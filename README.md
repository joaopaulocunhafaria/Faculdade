# Faculdade — Engenharia de Computação CEFET-MG

Repositório com os projetos, atividades e trabalhos desenvolvidos nas disciplinas do curso de Engenharia de Computação do CEFET-MG. Cada diretório na raiz corresponde a uma disciplina e é independente dos demais.

## Disciplinas

| Diretório | Disciplina | Principais tecnologias | Conteúdo |
| --- | --- | --- | --- |
| `IPC/` | Introdução à Programação de Computadores | C | Laboratórios, trabalho 1 e trabalho final |
| `AEDS I/` | Algoritmos e Estruturas de Dados I | C++ | Análise assintótica, Jogo da Vida e práticas |
| `AEDS II/` | Algoritmos e Estruturas de Dados II | C++ | Árvores binárias e TF-IDF |
| `AOC/` | Arquitetura e Organização de Computadores | Quartus (diagramas de blocos) | Cronômetro com seletor de clock e primeiro projeto |
| `POO/` | Programação Orientada a Objetos | Java, C++ | Laboratórios e trabalhos 1 e 2 |
| `LP/` | Linguagens de Programação | Java, Python | Exemplos de tratamento de exceções |
| `BD/` | Banco de Dados | SQL, Docker | Atividades 1 a 10, notas de aula e consultas |
| `CD/` | CD | Python, Node.js, LaTeX | NumPy, regex, web scraping e trabalho final |
| `CG/` | Computação Gráfica | Python (matplotlib, numpy, Pillow) | Scripts das aulas, slides e jogo de corrida (trabalho final) |
| `GO/` | GO | Excel | Organograma e Planejamento Estratégico Pessoal (PEP) |
| `IA/` | Inteligência Artificial | Python | Trabalhos 1 e 2 e KNN |
| `IC/` | IC | Python (pandas, scikit-learn) | Pré-processamento, clusterização, trabalho intermediário e final |
| `PO/` | Pesquisa Operacional | Python | Dualidade e trabalho final (gerador de instâncias e solver) |
| `RMPR/` | RMPR | OpenSCAD | Modelo 3D de chassi e rodas de um carrinho |
| `SD/` | Sistemas Distribuídos | Java (Maven, Swing) | Sockets TCP/UDP, urna digital e chat com middleware |
| `SO/` | Sistemas Operacionais | C++ | Simulador da arquitetura de Von Neumann |
| `LFA/` | Linguagens Formais e Autômatos | Python, Pascal | Conversão e teste de autômatos |
| `COMPILADORES/` | Compiladores | Python | Compilador para o "Mineirês" |
| `MHM/` | MHM | Python | Otimização multiobjetivo em máquinas paralelas (makespan e energia) |
| `TCC/` | Trabalho de Conclusão de Curso | Python | Instâncias de teste da literatura (TB1 a TB4) |

## Repositórios externos

Alguns trabalhos foram feitos em grupo e têm repositório próprio no GitHub. Eles ficam nos diretórios abaixo, mas são ignorados por este repositório (`.gitignore`):

| Diretório | Repositório |
| --- | --- |
| `COMPILADORES/Compilador-MG/` | [0livas/Compilador-MG](https://github.com/0livas/Compilador-MG) |
| `IA/ia-trabalho-2025-2/` | [alvaroajs/ia-trabalho-2025-2](https://github.com/alvaroajs/ia-trabalho-2025-2) |
| `IC/IC-atividade3/` | [joaopaulocunhafaria/ic-atividade3](https://github.com/joaopaulocunhafaria/ic-atividade3) |
| `IC/TrabalhoFinal/` | [joaopaulocunhafaria/IC-TrabalhoFinal](https://github.com/joaopaulocunhafaria/IC-TrabalhoFinal) |
| `LFA/LFA-Automato/` | [Jottynha/LFA-Automato](https://github.com/Jottynha/LFA-Automato) |
| `LFA/Mateus/` | [Matheus-Emanue123/Conversor-E-Testeador-De-Automatos](https://github.com/Matheus-Emanue123/Conversor-E-Testeador-De-Automatos) |
| `LFA/Trabalho-Pratico-AFs/` | [ByBrun0/Trabalho-Pratico-AFs](https://github.com/ByBrun0/Trabalho-Pratico-AFs) |
| `MHM/MHM_Trabalho_Final/` | [0livas/MHM_Trabalho_Final](https://github.com/0livas/MHM_Trabalho_Final) |
| `SO/SO-SimuladorVonNeumann/` | [samuelsilvg/SO-SimuladorVonNeumann](https://github.com/samuelsilvg/SO-SimuladorVonNeumann) |
| `SO/Trabalho-Final/SO-SimuladorVonNeumann/` | [alvarengazv/SO-SimuladorVonNeumann](https://github.com/alvarengazv/SO-SimuladorVonNeumann) |

## Ambientes Python

Os projetos em Python usam ambientes virtuais locais (`venv/`, `.venv/`, `sklearn-env/`), que não são versionados por causa do tamanho. Para recriar um ambiente, entre no diretório do projeto e instale as dependências:

```bash
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
```
