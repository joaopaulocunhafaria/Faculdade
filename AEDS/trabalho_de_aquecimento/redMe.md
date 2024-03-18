<h1>Trabalho de Aquecimento AEDS 1</h1>
<h2>Jogo da Vida</h2>
<ul>
  <li >Objetivos</li>
  <p>O objetivo deste trabalho é revisar os conceitos de manipulação de matrizes, controle
   de fluxo e lógica de jogo para reforcar e exercitar, tambem, conceitos de logica de programacao.</p>
  <li>Descricao</li>
  <p>O Jogo da Vida é um autômato celular que evolui de acordo com regras simples, mas
gera padrões complexos. Ele é representado por uma matriz 2D de células, cada uma
podendo estar viva ou morta.</p>
  <li>Implementacao e regras</li>
   <ul>
     <li>1. Crie uma matriz N x N para representar o tabuleiro do Jogo da Vida.</li>
     <li>2. Inicialize o tabuleiro com células vivas (1) e mortas (0) aleatoriamente.</li>
     <li>3. Implemente uma função para exibir o estado atual do tabuleiro.</li>
     <li>4. Implemente uma função para produzir um relatório de execução, guardando o
histórico da evolução do jogo em arquivo.</li>
     <li>5. Implemente uma função para calcular a próxima geração do Jogo da Vida com base
nas seguintes regras:</li>
     <ul>
       <li>- Uma célula viva com menos de dois vizinhos vivos morre (solidão).</li>
        <li>- Uma célula viva com mais de três vizinhos vivos morre (superpopulação).</li>
        <li>- Uma célula viva com dois ou três vizinhos vivos sobrevive.</li>
        <li>- Uma célula morta com exatamente três vizinhos vivos se torna viva (reprodução).</li>
     </ul>
     <li>6. Execute várias gerações do jogo e mostre o estado do tabuleiro após cada geração.</li>
     <li><img style="height:200px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/78afcedc-c5ca-4b7b-82e8-dc6739d56029"> 
</li>
   </ul>
  <li>Condicoes</li>
  <ul>
    <li> Ler a matriz de entrada de um arquivo, considerando um tamanho mínimo de
5x5.</li>
    <li> Considere uma fração de 2 para 1 para compor os valores 0s e 1s, sendo o
número de 1s em menor quantidade para produzir um melhor espalhamento.</li>
    <li>  A cada interação, faça as avaliações utilizando a matriz atual e produza os
resultados da avaliação em uma nova matriz. Feito isso, salve a matriz avaliada
como parte de seus resultados em um arquivo chamado geracoes.mps.</li>
    <li>O arquivo geracoes.mps deve ser organizado para mostrar todas as evoluções,
contando inclusive com a matriz de origem da execução.</li>
    <li>Na tela, basta apresentar as mensagens de algoritmo executando e processo
de gerações finalizado.</li>
    <li>Como entradas, pedir ao usuário para digitar apenas o número de gerações a
ser avaliado.</li>
    <li>Para a matriz de entrada, crie uma pasta chamada datasets dentro do seu projeto
e fora da pasta src, armazenando ela como input.mps.</li>
   
    
  </ul>
   <li>Organizacao e fluxo de Codigo</li>
   <ul>
     <li> <p>Na pasta input.mps esta disposta a matriz de entrada com a qual o codigo ira trabalhar e acima desta esta sua dimensao. No codigo como esta disposto o tamanho da matriz e de 10x10. </p></li>
     <li>Apos a primeira execucao o programa escreve a matriz de entrada no arquivo geracoes.mps, assim como as demais geracaoes.</li>
     <li>Apos fazer o calculo da proxima geracao o programa a imprimi tambem no arquivo geracoes.mps, e assim a quantidade de vezes desejada pelo usuario.</li>
   </ul>

   <li>Resolucoes finais</li>
   <p>Para a construcao de um programa que realize de maneira eficiente o exercicio proposto foram necessarios conhecimentos precissos da linguagem de programacao utilizada, uma boa compreensao logica do problema exposto, abstracao e manipulacao de estruturas de dados bidimensionais, previsao de erros  e uma boa organizacao de codigo para facilitar a escrita do programa.</p>
</ul>
