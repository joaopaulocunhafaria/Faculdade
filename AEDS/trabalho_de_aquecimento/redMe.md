<h1>Trabalho de Aquecimento AEDS 1</h1>
<h2>Jogo da Vida</h2>
<ul>
  <li>Objetivos</li>
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
   </ul>
</ul>
