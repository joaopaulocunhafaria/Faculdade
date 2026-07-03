"""
Implementação da formulação MILP para o SEQUENCIAMENTO DE RECUPERADORAS EM
PÁTIOS DE MINÉRIO visando à minimização do atraso total ponderado.

Artigo reproduzido:
    Florinda, E. M.; Souza, M. J. F.; Cota, L. P. (2024).
    "Uma formulação de programação linear inteira mista para o sequenciamento
     de recuperadoras em pátios de minério visando à minimização do atraso total."
    LVI Simpósio Brasileiro de Pesquisa Operacional (SBPO), Fortaleza/CE.
    DOI: 10.59254/sbpo-2024-193585

O problema é uma variante de sequenciamento em MÁQUINAS PARALELAS NÃO-RELACIONADAS
(as recuperadoras têm taxas de recuperação diferentes), com:
  - tempos de preparação (setup) dependentes da sequência;
  - datas de entrega (due dates) e penalidade por atraso;
  - elegibilidade de máquinas.

Toda a formulação (conjuntos, parâmetros, variáveis, função objetivo e restrições)
segue a Seção 4 do artigo. Os comentários referenciam diretamente as equações (1)-(12)
e a caracterização do problema (Seção 3, itens a-j).

Uso:
    source venv/bin/activate
    python solver.py            # resolve TODAS as 30 instâncias de data/instances.csv
    python solver.py --gantt 8  # resolve a instância 8 e gera o gráfico de Gantt
                                # (salvo em output/gantt_instancia_8.png)
"""

import json
import time

import pandas as pd
import gurobipy as gp
from gurobipy import GRB

# ---------------------------------------------------------------------------
# Parâmetros do resolvedor, idênticos aos usados no artigo (Seção 5).
# ---------------------------------------------------------------------------
# "O parâmetro de tempo limite do resolvedor foi estabelecido como 3600 segundos."
TIME_LIMIT = 3600
# "O parâmetro de foco na integralidade (integrality focus) foi definido com valor
#  igual a 1 para garantir que as variáveis binárias não sejam influenciadas por
#  problemas de arredondamento durante a resolução do problema."
INTEGRALITY_FOCUS = 1

INSTANCES_CSV = "data/instances.csv"


# ===========================================================================
# 1. CARREGAMENTO DOS DADOS DE ENTRADA (data/instances.csv)
# ===========================================================================
class Instance:
    """
    Representa uma instância do problema, expondo os parâmetros de entrada do
    artigo (Seção 4 - "Parâmetros de entrada").

    Convenção de indexação adotada para manter o código alinhado ao artigo:
      - Recuperadoras (conjunto RC): numeradas 1..|RC|          (índice i).
      - Tarefas reais (conjunto N):  numeradas 1..|N|           (índices j, k).
      - Tarefa fictícia 0:           conjunto N0 = {0} ∪ N      (Seção 3, item f).
    As listas lidas do CSV são 0-based, portanto o acesso é sempre deslocado de -1.
    """

    def __init__(self, row):
        self.id = int(row["Instance_ID"])
        self.RC = int(row["RC"])                 # |RC| - número de recuperadoras
        self.Nn = int(row["N"])                  # |N|  - número de tarefas

        # Listas 0-based lidas do CSV (colunas armazenadas como strings JSON).
        self._q = json.loads(row["q"])           # q_j : quantidade de minério da tarefa j
        self._v = json.loads(row["v"])           # v_i : taxa de recuperação da recuperadora i
        self._d = json.loads(row["d"])           # d_j : data de entrega planejada da tarefa j
        self._w = json.loads(row["w"])           # w_j : penalidade por atraso da tarefa j
        # Elegibilidade e_ij (Seção 3, item j). No CSV está no formato e[j][i]
        # (linha = tarefa, coluna = recuperadora); o artigo usa e_{ij}.
        self._e = json.loads(row["e"])
        # Setup S_ijk (Seção 3, item e). No CSV está no formato S[i][prev][next],
        # com prev ∈ {0..|N|} (0 = tarefa fictícia) e next ∈ {0..|N|-1}.
        self._S = json.loads(row["S"])

        # Conjuntos de índices no estilo do artigo.
        self.N = list(range(1, self.Nn + 1))     # N  = {1, ..., |N|}
        self.N0 = [0] + self.N                    # N0 = {0} ∪ N
        self.RCs = list(range(1, self.RC + 1))    # RC = {1, ..., |RC|}

    # --- Parâmetros de entrada (acesso no estilo do artigo, 1-based) --------
    def q(self, j):
        return self._q[j - 1]

    def v(self, i):
        return self._v[i - 1]

    def d(self, j):
        return self._d[j - 1]

    def w(self, j):
        return self._w[j - 1]

    def p(self, i, j):
        """p_ij = q_j / v_i : tempo de processamento (Seção 3, item d; parâmetro p_ij)."""
        return self.q(j) / self.v(i)

    def eligible(self, i, j):
        """
        e_ij : True se a recuperadora i é elegível para a tarefa j.
        A tarefa fictícia 0 é elegível em TODAS as recuperadoras (item f: ela é
        sempre a primeira a ser executada em qualquer recuperadora).
        """
        if j == 0:
            return True
        return self._e[j - 1][i - 1] == 1

    def S(self, i, j, k):
        """
        S_ijk : tempo de setup para a recuperadora i executar a tarefa k
        imediatamente após a tarefa j (j = anterior, k = próxima).

        Mapeamento CSV S[i][prev][next]:
          - i    -> índice i-1
          - prev -> j diretamente (0 = fictícia; tarefas reais ocupam 1..|N|)
          - next -> k-1 (dimensão "next" é 0-based sobre as tarefas reais)
        """
        return self._S[i - 1][j][k - 1]

    def big_B(self):
        """
        B : constante suficientemente grande (parâmetro B, usado na restrição (6)).
        Usa-se um limitante superior seguro para os tempos de conclusão: a soma,
        sobre todas as tarefas, do maior tempo de processamento possível, acrescida
        de |N| vezes o maior tempo de setup (todas as tarefas + setups numa mesma máquina).
        """
        max_S = max(
            self.S(i, j, k)
            for i in self.RCs
            for j in self.N0
            for k in self.N
            if j != k
        )
        sum_max_p = sum(max(self.p(i, j) for i in self.RCs) for j in self.N)
        return sum_max_p + self.Nn * max_S


def load_instances(path=INSTANCES_CSV):
    """Lê o CSV e devolve a lista de instâncias (uma por linha)."""
    df = pd.read_csv(path)
    return [Instance(row) for _, row in df.iterrows()]


# ===========================================================================
# 2. CONSTRUÇÃO DO MODELO MILP (Seção 4, equações 1–12)
# ===========================================================================
def build_model(inst):
    """
    Constrói o modelo Gurobi correspondente à formulação MILP do artigo para a
    instância `inst`. Retorna (model, x, C_ij, C_j, T).
    """
    m = gp.Model(f"reclaimer_scheduling_inst_{inst.id}")

    RC, N, N0 = inst.RCs, inst.N, inst.N0

    # -----------------------------------------------------------------------
    # VARIÁVEIS DE DECISÃO E AUXILIARES (Seção 4)
    # -----------------------------------------------------------------------
    # x_ijk ∈ {0,1} : 1 se a tarefa k será executada imediatamente após a tarefa j
    #                 na recuperadora i (equação (12): domínio binário).
    # Só são criadas as variáveis para pares elegíveis (e_ij = 1 e e_ik = 1) e j != k,
    # exatamente o domínio restrito indicado nas equações (2)–(6) e (12).
    x = {}
    for i in RC:
        for j in N0:
            for k in N:
                if j != k and inst.eligible(i, j) and inst.eligible(i, k):
                    x[i, j, k] = m.addVar(vtype=GRB.BINARY, name=f"x_{i}_{j}_{k}")

    # C_ij : tempo de conclusão da tarefa j na recuperadora i (equação (11): C_ij >= 0).
    # Criada para j ∈ N0 elegível; C_i0 será fixada em 0 pela restrição (7).
    C_ij = {}
    for i in RC:
        for j in N0:
            if inst.eligible(i, j):
                C_ij[i, j] = m.addVar(lb=0.0, vtype=GRB.CONTINUOUS, name=f"C_{i}_{j}")

    # C_j : tempo de conclusão da tarefa j (independente da máquina).
    C_j = {j: m.addVar(lb=0.0, vtype=GRB.CONTINUOUS, name=f"C_{j}") for j in N}

    # T_j : tempo de atraso da tarefa j, T_j = max{C_j - d_j, 0}
    #       (equação (10): T_j >= 0; a linearização vem da equação (9)).
    T = {j: m.addVar(lb=0.0, vtype=GRB.CONTINUOUS, name=f"T_{j}") for j in N}

    # -----------------------------------------------------------------------
    # FUNÇÃO OBJETIVO (1): min z = Σ_{j∈N} w_j · T_j  (atraso total ponderado)
    # -----------------------------------------------------------------------
    m.setObjective(gp.quicksum(inst.w(j) * T[j] for j in N), GRB.MINIMIZE)

    B = inst.big_B()  # parâmetro B da restrição (6)

    # -----------------------------------------------------------------------
    # RESTRIÇÕES
    # -----------------------------------------------------------------------

    # Restrição (2): cada tarefa k é designada a exatamente uma recuperadora
    # elegível e possui exatamente uma tarefa predecessora j (real ou fictícia)
    # também elegível nessa recuperadora.
    #   Σ_{i∈RC} Σ_{j∈N0, j≠k, e_ij=1, e_ik=1} x_ijk = 1   ∀k∈N
    for k in N:
        m.addConstr(
            gp.quicksum(
                x[i, j, k]
                for i in RC
                for j in N0
                if j != k and (i, j, k) in x
            ) == 1,
            name=f"eq2_atribuicao_k{k}",
        )

    # Restrição (3): cada tarefa j tem no máximo uma tarefa sucessora (limite
    # máximo de um sucessor por tarefa), desde que ambas sejam elegíveis em i.
    #   Σ_{i∈RC} Σ_{k∈N, k≠j, e_ij=1, e_ik=1} x_ijk ≤ 1   ∀j∈N
    for j in N:
        m.addConstr(
            gp.quicksum(
                x[i, j, k]
                for i in RC
                for k in N
                if k != j and (i, j, k) in x
            ) <= 1,
            name=f"eq3_sucessor_j{j}",
        )

    # Restrição (4): a tarefa fictícia 0 tem no máximo uma tarefa sucessora em
    # cada recuperadora (isto é, cada recuperadora inicia no máximo uma sequência).
    #   Σ_{k∈N, e_ik=1} x_i0k ≤ 1   ∀i∈RC
    for i in RC:
        m.addConstr(
            gp.quicksum(x[i, 0, k] for k in N if (i, 0, k) in x) <= 1,
            name=f"eq4_ficticia_i{i}",
        )

    # Restrição (5): conservação de fluxo. Se a tarefa j é predecessora imediata
    # de k na recuperadora i, então j necessariamente possui uma predecessora
    # imediata h também elegível na mesma recuperadora i.
    #   Σ_{h∈N0, h≠j, h≠k, e_ih=1} x_ihj ≥ x_ijk
    #   ∀j,k∈N, j≠k, ∀i∈RC, e_ij=1, e_ik=1
    for i in RC:
        for j in N:
            for k in N:
                if j != k and (i, j, k) in x:
                    m.addConstr(
                        gp.quicksum(
                            x[i, h, j]
                            for h in N0
                            if h != j and h != k and (i, h, j) in x
                        ) >= x[i, j, k],
                        name=f"eq5_fluxo_i{i}_j{j}_k{k}",
                    )

    # Restrição (6): sequenciamento dos tempos de conclusão (big-B). Se a tarefa k
    # é executada imediatamente após j na recuperadora i (x_ijk = 1), então o tempo
    # de conclusão de k deve ser ≥ conclusão de j + setup S_ijk + processamento p_ik.
    # Quando x_ijk = 0, a constante B torna a restrição redundante.
    #   C_ik + B(1 - x_ijk) ≥ C_ij + S_ijk + p_ik
    #   ∀j∈N0, ∀k∈N, j≠k, ∀i∈RC, e_ij=1, e_ik=1
    for i in RC:
        for j in N0:
            for k in N:
                if j != k and (i, j, k) in x:
                    m.addConstr(
                        C_ij[i, k] + B * (1 - x[i, j, k])
                        >= C_ij[i, j] + inst.S(i, j, k) + inst.p(i, k),
                        name=f"eq6_conclusao_i{i}_j{j}_k{k}",
                    )

    # Restrição (7): tempo de conclusão nulo para a tarefa fictícia em cada recuperadora.
    #   C_i0 = 0   ∀i∈RC
    for i in RC:
        m.addConstr(C_ij[i, 0] == 0.0, name=f"eq7_ficticia_i{i}")

    # Restrição (8): o tempo de conclusão da tarefa j (C_j) é ao menos o seu tempo
    # de conclusão em qualquer recuperadora elegível. Como a tarefa é executada em
    # exatamente uma recuperadora, C_j assume esse valor.
    #   C_j ≥ C_ij   ∀j∈N, ∀i∈RC, e_ij=1
    for j in N:
        for i in RC:
            if inst.eligible(i, j):
                m.addConstr(C_j[j] >= C_ij[i, j], name=f"eq8_conclusao_j{j}_i{i}")

    # Restrição (9): definição (linearizada) do atraso de cada tarefa.
    #   T_j ≥ C_j - d_j   ∀j∈N     (combinada com (10): T_j ≥ 0 → T_j = max{C_j-d_j,0})
    for j in N:
        m.addConstr(T[j] >= C_j[j] - inst.d(j), name=f"eq9_atraso_j{j}")

    # Restrições (10), (11) e (12) — domínios das variáveis — já foram impostas na
    # criação das variáveis (lb=0 para T_j e C_ij; vtype=BINARY para x_ijk).

    return m, x, C_ij, C_j, T


# ===========================================================================
# 3. RESOLUÇÃO E RELATÓRIO DE RESULTADOS
# ===========================================================================
def solve_instance(inst, return_model=False):
    """
    Constrói, resolve e coleta os resultados de uma instância.

    Se `return_model=True`, retorna também o modelo e as variáveis resolvidas
    (x_ijk e C_ij), necessárias para reconstruir a sequência e gerar o Gantt.
    """
    m, x, C_ij, C_j, T = build_model(inst)

    # Parâmetros do resolvedor conforme o artigo (Seção 5).
    m.Params.TimeLimit = TIME_LIMIT
    m.Params.IntegralityFocus = INTEGRALITY_FOCUS
    m.Params.OutputFlag = 0  # silencia o log do Gurobi; imprimimos nosso próprio resumo

    start = time.time()
    m.optimize()
    runtime = time.time() - start

    # z = valor da função objetivo (atraso total ponderado);
    # best bound = melhor limite inferior encontrado; gap = distância relativa.
    result = {
        "id": inst.id,
        "RC": inst.RC,
        "N": inst.Nn,
        "z": m.ObjVal if m.SolCount > 0 else float("nan"),
        "bound": m.ObjBound,
        "gap": m.MIPGap * 100 if m.SolCount > 0 else float("nan"),
        "time": runtime,
        "status": "ótimo" if m.Status == GRB.OPTIMAL else "limite de tempo"
        if m.Status == GRB.TIME_LIMIT else str(m.Status),
    }
    if return_model:
        return result, m, x, C_ij
    return result


# ===========================================================================
# 4. EXTRAÇÃO DA SEQUÊNCIA E GRÁFICO DE GANTT
# ===========================================================================
def extract_schedule(inst, x, C_ij):
    """
    Reconstrói, a partir da solução ótima (variáveis x_ijk e C_ij), o
    sequenciamento de cada recuperadora.

    Para cada recuperadora i, segue-se a cadeia de precedências a partir da
    tarefa fictícia 0 (item f; restrição (4)): o sucessor imediato de j é a
    tarefa k tal que x_ijk = 1. Para cada tarefa da sequência calcula-se, a
    partir do tempo de conclusão C_ik (restrição (6)):
        - intervalo de PROCESSAMENTO: [C_ik - p_ik, C_ik];
        - intervalo de SETUP:         [C_ik - p_ik - S_ijk, C_ik - p_ik].
    Esses intervalos correspondem, respectivamente, à parte colorida e à parte
    hachurada das Figuras 2 e 3 do artigo.

    Retorna: dict {i: [segmentos]}, cada segmento com os tempos e o atraso da tarefa.
    """
    schedule = {}
    for i in inst.RCs:
        segments = []
        prev = 0  # inicia na tarefa fictícia 0
        while True:
            # sucessor imediato de `prev` na recuperadora i (x_i,prev,k = 1)
            nxt = None
            for k in inst.N:
                if (i, prev, k) in x and x[i, prev, k].X > 0.5:
                    nxt = k
                    break
            if nxt is None:
                break  # fim da sequência desta recuperadora

            comp = C_ij[i, nxt].X          # C_ik  : tempo de conclusão da tarefa k
            proc = inst.p(i, nxt)          # p_ik  : tempo de processamento
            setup = inst.S(i, prev, nxt)   # S_ijk : setup de `prev` para `nxt`
            proc_start = comp - proc
            setup_start = proc_start - setup
            tardiness = max(comp - inst.d(nxt), 0.0)

            segments.append({
                "task": nxt,
                "setup_start": setup_start,
                "setup_end": proc_start,
                "proc_start": proc_start,
                "proc_end": comp,
                "completion": comp,
                "due": inst.d(nxt),
                "tardiness": tardiness,
                "tardiness_weighted": inst.w(nxt) * tardiness,  # parcela w_j·T_j de z
                "setup": setup,
                "proc": proc,
            })
            prev = nxt
        schedule[i] = segments
    return schedule


def plot_gantt(inst, schedule, path):
    """
    Gera o gráfico de Gantt do sequenciamento (estilo das Figuras 2 e 3 do artigo):
    uma linha por recuperadora, com o setup hachurado e o processamento colorido
    (tarefas atrasadas destacadas em outra cor). Salva a figura em `path`.
    """
    import os
    import matplotlib
    matplotlib.use("Agg")  # backend sem interface gráfica (apenas salva o arquivo)
    import matplotlib.pyplot as plt
    from matplotlib.patches import Patch

    COR_NO_PRAZO = "#4C78A8"  # processamento sem atraso
    COR_ATRASO = "#E45756"    # processamento com atraso
    ALTURA = 0.6

    fig, ax = plt.subplots(figsize=(11, 1.2 * inst.RC + 1.5))
    yticks, ylabels = [], []
    for idx, i in enumerate(inst.RCs):
        y = idx
        yticks.append(y)
        ylabels.append(f"RC{i:02d}")
        for seg in schedule[i]:
            # Parte hachurada: tempo de setup (S_ijk).
            if seg["setup"] > 0:
                ax.barh(y, seg["setup_end"] - seg["setup_start"], left=seg["setup_start"],
                        height=ALTURA, color="white", edgecolor="black", hatch="////")
            # Parte colorida: tempo de processamento (p_ik).
            cor = COR_ATRASO if seg["tardiness"] > 1e-6 else COR_NO_PRAZO
            ax.barh(y, seg["proc_end"] - seg["proc_start"], left=seg["proc_start"],
                    height=ALTURA, color=cor, edgecolor="black")
            # Identificação da tarefa no centro do bloco de processamento.
            ax.text((seg["proc_start"] + seg["proc_end"]) / 2, y, str(seg["task"]),
                    ha="center", va="center", color="white", fontsize=9, fontweight="bold")

    ax.set_yticks(yticks)
    ax.set_yticklabels(ylabels)
    ax.invert_yaxis()  # RC01 no topo
    ax.set_xlabel("Tempo de conclusão")
    ax.set_xlim(left=0)
    # z = Σ_{j∈N} w_j·T_j reconstruído a partir da sequência (equação (1)).
    z = sum(seg["tardiness_weighted"] for segs in schedule.values() for seg in segs)
    ax.set_title(
        f"Sequenciamento ótimo — Instância {inst.id} "
        f"(|RC|={inst.RC}, |N|={inst.Nn}, z={z:.3f})"
    )
    legenda = [
        Patch(facecolor=COR_NO_PRAZO, edgecolor="black", label="Processamento (no prazo)"),
        Patch(facecolor=COR_ATRASO, edgecolor="black", label="Processamento (com atraso)"),
        Patch(facecolor="white", edgecolor="black", hatch="////", label="Setup"),
    ]
    ax.legend(handles=legenda, loc="lower right", fontsize=8)
    fig.tight_layout()

    os.makedirs(os.path.dirname(path) or ".", exist_ok=True)
    fig.savefig(path, dpi=150)
    plt.close(fig)


def solve_all(instances):
    """Resolve todas as instâncias e imprime a tabela no formato da Tabela 6 do artigo."""
    print(f"Resolvendo {len(instances)} instâncias de '{INSTANCES_CSV}'")
    print(f"(TimeLimit={TIME_LIMIT}s, IntegralityFocus={INTEGRALITY_FOCUS} — conforme o artigo)\n")

    # Cabeçalho no formato da Tabela 6 do artigo (Seção 5.2 - Resultados).
    header = f"{'ID':>3} | {'|RC|':>4} | {'|N|':>4} | {'z':>12} | {'best bound':>12} | {'gap(%)':>7} | {'tempo(s)':>9} | status"
    print(header)
    print("-" * len(header))

    for inst in instances:
        r = solve_instance(inst)
        print(
            f"{r['id']:>3} | {r['RC']:>4} | {r['N']:>4} | "
            f"{r['z']:>12.3f} | {r['bound']:>12.3f} | {r['gap']:>7.2f} | "
            f"{r['time']:>9.2f} | {r['status']}"
        )


def solve_and_plot_gantt(inst):
    """Resolve uma única instância, imprime a sequência e gera o gráfico de Gantt."""
    result, m, x, C_ij = solve_instance(inst, return_model=True)
    print(
        f"Instância {result['id']} (|RC|={result['RC']}, |N|={result['N']}): "
        f"z={result['z']:.3f}, gap={result['gap']:.2f}%, "
        f"tempo={result['time']:.2f}s, status={result['status']}\n"
    )

    schedule = extract_schedule(inst, x, C_ij)
    print("Sequenciamento por recuperadora (tarefa: [conclusão, atraso]):")
    for i in inst.RCs:
        seq = " → ".join(
            f"{s['task']}[C={s['completion']:.2f}, T={s['tardiness']:.2f}]"
            for s in schedule[i]
        )
        print(f"  RC{i:02d}: {seq if seq else '(sem tarefas)'}")

    path = f"output/gantt_instancia_{inst.id}.png"
    plot_gantt(inst, schedule, path)
    print(f"\nGráfico de Gantt salvo em '{path}'.")


def main():
    import argparse

    parser = argparse.ArgumentParser(
        description="Resolve o problema de sequenciamento de recuperadoras (formulação MILP)."
    )
    parser.add_argument(
        "--gantt",
        type=int,
        metavar="ID",
        help="resolve apenas a instância de identificador ID e gera o gráfico de Gantt.",
    )
    args = parser.parse_args()

    instances = load_instances()

    if args.gantt is not None:
        inst = next((i for i in instances if i.id == args.gantt), None)
        if inst is None:
            parser.error(f"Instância {args.gantt} não encontrada em '{INSTANCES_CSV}'.")
        solve_and_plot_gantt(inst)
    else:
        solve_all(instances)


if __name__ == "__main__":
    main()
