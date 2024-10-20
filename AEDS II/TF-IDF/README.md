## OBJETIVOS

O trabalho consiste na implementação de um sistema de ranqueamento de documentos utilizando o algoritmo TF/IDF (Term Frequency-Inverse Document Frequency). O objetivo principal é classificar um conjunto de documentos de acordo com a relevância de cada um em relação a frases de pesquisa específicas, utilizando a métrica TF/IDF para calcular essa relevância.

### Algoritmo TF/IDF

O TF/IDF é uma técnica amplamente utilizada em recuperação de informações e mineração de texto. Ele combina duas medidas:

- **TF (Term Frequency)**: Mede a frequência de um termo em um documento, indicando a importância do termo dentro daquele documento específico.
- **IDF (Inverse Document Frequency)**: Avalia a importância de um termo em relação a todo o conjunto de documentos, penalizando termos que aparecem em muitos documentos, pois eles tendem a ser menos informativos.

### Objetivo do Trabalho

1. Ler e processar documentos de texto.
2. Calcular a relevância de cada documento em relação a uma lista de frases de pesquisa, utilizando a métrica TF/IDF.
3. Classificar os documentos de acordo com essa relevância, utilizando métodos de ordenação eficientes.

### Tipo de Entrada

O sistema receberá como entrada:

1. Um conjunto de arquivos de texto contendo documentos aleatórios.
2. Uma lista de frases de pesquisa, onde cada frase será comparada aos documentos para determinar a relevância de cada um.

## Estruturas de Dados

Para bem modelar o trabalho em questão, de forma a obter a melhor performance possível, usaram-se diversas estruturas de dados que foram abordadas durante a matéria de Algoritmos e Estruturas de Dados I. Foram usadas, em sua grande maioria, estruturas de dados complexas ou de segunda ordem, ou seja, estruturas diferentes das primárias. Em cada etapa da implementação, foram usadas estruturas que melhor modelassem o problema a ser resolvido, de forma que, em diferentes etapas, usaram-se estruturas semelhantes para resolver problemas diferentes. Sendo assim, para cada etapa da resolução do trabalho, será apresentada as estruturas que foram empregadas, de forma a exemplificar da melhor maneira possível a solução apresentada.

## Contagem de Palavras

Para bem abordar o problema apresentado, primeiramente é necessário realizar a normalização dentro dos textos presentes em cada documento. Para tal, faz-se necessário a eliminação de todas as palavras que usualmente não geram alterações no sentido de cada texto. Essas palavras são as chamadas "stop words", dentre elas podemos citar palavras genéricas como: a, as, que, da, de, entre inúmeras outras. Após realizado tal procedimento, necessita-se fazer a contagem de palavras relevantes dentro de cada documento. Para cada documento, foi usada uma estrutura do tipo **Hash Table**, ou **unordered_map** em C++, para auxiliar na contagem. Como as **Hash Tables** possuem custo de acesso com valor constante, elas são uma ótima opção para atribuir a um determinado índice um certo valor, que, nesse caso, será a quantidade de vezes que a palavra aparece no documento em questão. Ao iterar sobre as palavras presentes no documento, cada uma delas é alocada dentro da tabela. Sempre que seu valor se repete, seu índice é acessado e o valor presente nele incrementado. Dessa forma, ao percorrer todo o documento, as palavras presentes nele foram todas contadas e estão alocadas dentro da tabela, assim como a quantidade de vezes que cada uma se repete no documento.

Contudo, tal abordagem oferece a solução para apenas um único documento, sendo necessário ampliar essa solução para quantos documentos forem necessários processar. Sendo assim, a estrutura final para realizar tal procedimento foi um array, **vector** na linguagem C++, de tabelas hash, onde cada posição do array representa as palavras processadas em cada documento. Como resultado final, para termos acesso a todas essas informações, a estrutura final ficou implementada da seguinte maneira:


<img src="https://github.com/user-attachments/assets/d933efc9-0b88-429a-bb72-4a6d3ffa3a23" height="80px" alt="Vector de Hash">

## COMPILAÇÃO E EXECUÇÃO

| Comando     | Função                                                                 |
| ----------- | ---------------------------------------------------------------------- |
| make clean  | Apaga a última compilação realizada contida na pasta build              |
| make        | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build |
| make run    | Executa o programa da pasta build após a realização da compilação       |
