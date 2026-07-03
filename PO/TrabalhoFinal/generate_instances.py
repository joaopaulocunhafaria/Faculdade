import os
import random
import pandas as pd
import json

def generate_instances():
    # Grupos definidos no artigo (Recuperadoras, Tarefas)
    groups = [(2, 8), (2, 10), (2, 12), (4, 8), (4, 10), (4, 12)]
    num_instances_per_group = 5
    
    data = []
    instance_id = 1
    
    for rc, n in groups:
        for _ in range(num_instances_per_group):
            # 1. Quantidade de minério na pilha q_j: uniforme [7000, 100000], múltiplos de 10
            q = [random.randrange(7000, 100010, 10) for _ in range(n)]
            
            # 2. Taxa de recuperação v_i: uniforme entre {5000, 6000, 7000} em t/h
            v = [random.choice([5000, 6000, 7000]) for _ in range(rc)]
            
            # 3. Data de entrega d_j (em horas)
            # Limite inferior: menor tempo de processamento de uma tarefa
            min_p = min(q_j / v_i for q_j in q for v_i in v)
            
            # Limite superior: soma dos maiores tempos de processamento dividida pelo número de máquinas
            sum_max_p = sum(max(q_j / v_i for v_i in v) for q_j in q)
            upper_bound = sum_max_p / rc
            
            d = [round(random.uniform(min_p, max(min_p, upper_bound)), 2) for _ in range(n)]
            
            # 4. Elegibilidade e_ij
            # 10% de chance, garantindo ao menos 1 recuperadora por tarefa
            e = []
            for j in range(n):
                row = [1 if random.random() < 0.10 else 0 for _ in range(rc)]
                if sum(row) == 0:
                    row[random.randint(0, rc - 1)] = 1
                e.append(row)
                
            # 5. Tempos de preparação S_ijk (em minutos)
            # Escolhidos de {10, 20, 30, 40, 50, 60}
            # S[i][k][j] onde i = recuperadora, k = tarefa anterior (0 = fictícia), j = próxima tarefa
            S = []
            for i in range(rc):
                S_i = []
                for k in range(n + 1):
                    S_ik = [random.choice([10, 20, 30, 40, 50, 60]) for _ in range(n)]
                    S_i.append(S_ik)
                S.append(S_i)
                
            # 6. Penalidade w_j
            # O artigo menciona valores {0%, 10%, 20%, 30%}
            # Transformando nos multiplicadores da tabela: 1.0, 1.1, 1.2, 1.3
            w = [random.choice([1.0, 1.1, 1.2, 1.3]) for _ in range(n)]
            
            row_dict = {
                'Instance_ID': instance_id,
                'RC': rc,
                'N': n,
                'q': json.dumps(q),
                'v': json.dumps(v),
                'd': json.dumps(d),
                'e': json.dumps(e),
                'S': json.dumps(S),
                'w': json.dumps(w)
            }
            data.append(row_dict)
            instance_id += 1
            
    df = pd.DataFrame(data)
    
    # Cria o diretório /data se não existir
    os.makedirs('data', exist_ok=True)
    
    # Salva o arquivo CSV
    csv_path = os.path.join('data', 'instances.csv')
    df.to_csv(csv_path, index=False)
    print(f"Geradas {len(data)} instâncias com sucesso no arquivo '{csv_path}'.")

if __name__ == '__main__':
    generate_instances()
