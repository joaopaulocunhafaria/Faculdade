
Para garantir que você cumpra todos os requisitos da atividade de Inteligência Computacional e apresente um trabalho metodologicamente correto, organizei um pipeline dividido em quatro fases principais.

Este roteiro segue a sequência lógica exigida pelo Prof. Alisson.

🚀 Pipeline de Trabalho: Adult Census Income
Fase 1: Análise e Compreensão (O "Olhar" sobre os Dados)

Nesta fase, você cumpre os requisitos de caracterização e análise exploratória.

    Carregamento: Importe a base tratando os valores "?" como NaN.

Estatística Descritiva: Gere tabelas com média, mediana e desvio padrão para atributos numéricos.

Visualização: * Crie histogramas para age e hours-per-week.

    Gere um gráfico de barras para a variável alvo (income) para evidenciar o desbalanceamento.

Use boxplots para identificar outliers em capital-gain.

Diagnóstico: Liste formalmente os problemas encontrados (dados faltantes, redundâncias e desbalanceamento).

Fase 2: Preparação (Limpando a Casa)

Aplique as transformações necessárias para que os algoritmos consigam "ler" os dados.

    Limpeza: Trate os valores ausentes (imputação pela moda ou remoção estratégica).

Codificação: Aplique One-Hot Encoding em variáveis nominais (ex: race, sex) e Ordinal Encoding se houver hierarquia.

Escalonamento: Utilize StandardScaler ou MinMaxScaler nos atributos numéricos.

Engenharia de Atributos: Escolha entre seleção (ex: remover fnlwgt se julgar irrelevante) ou redução (PCA), justificando sua escolha no relatório.

Fase 3: Metodologia Experimental (O Coração do Trabalho)

Aqui você define como o teste será justo e reprodutível.

    Divisão de Dados: Utilize a estratégia de Hold-out (Treino/Teste) ou Validação Cruzada (K-Fold).

Seleção de Algoritmos: Escolha pelo menos três modelos (ex: Árvore de Decisão, SVM e KNN).

Métricas de Avaliação: Como a base é desbalanceada, não use apenas a Acurácia. Inclua F1-Score, Precisão e Recall.

Fase 4: Consolidação e Entrega

Organize os resultados para a apresentação de 15 minutos.

    Comparação: Monte tabelas comparando o desempenho dos três algoritmos.

Discussão: Analise qual modelo foi melhor e por que (ex: "O modelo X lidou melhor com os outliers de capital-gain").

Checklist de Código: Garanta que seu Notebook esteja comentado, organizado e que qualquer pessoa consiga rodá-lo do início ao fim sem erros.
