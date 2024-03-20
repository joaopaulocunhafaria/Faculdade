<h1>Trabalho de Aquecimento AEDS 1</h1>
<h2>Jogo da Vida</h2>
<ul>
  <li >Objetivos</li>
  <p>O objetivo deste trabalho é revisar os conceitos de manipulação de matrizes, controle
   de fluxo e lógica de jogo para reforcar e exercitar conceitos de logica de programacao.</p>
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
     <li style="display:inline;">    <img style="height:25px;" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/822c4da5-2aff-4013-b26f-a3aea03cff0a"></li>
      <p>Dentro da pasta datasets, no arquivo input.mps, esta disposta a dimensao da matriz de entrada do programa assim como os caracterer que a compoe. A organizacao do arquivo se da da seguinte forma. </p>
      <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/8a83331a-df50-474a-8a1b-c791f2673197" style="height:200px">
     <li><img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/e5d96fed-1227-4aa9-8a12-28e29b1bba2e" style="height:25px;" ></li>
     <p>O arquivo geracoes.mps eh o responsavel por armazenar os resultados de cada iteracao do codigo e registrar a evolucao da matriz seguindo as regras do jogo. Um exemplo de uma execucao onde ocorreram 3 interacoes.</p>
     <li></li>
     <div>
       <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/c24e6e4d-23b5-4d9b-b7fe-b3abf630c2b0" style="height:400px">
       <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/6836a49d-b379-4e24-b33b-ce5407990273" style="height:400px">
        
</div>
      <li><img style="height:25px;" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/523ce255-ec5a-43a9-a2fa-945cffddb7e7"></li>
      <p>A pasta src eh onde esta toda a estruturacao e a organizacao do programa. Dividindo-se da seguinte forma</p>
    <img style="height:50px;" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/d01eaee6-a613-4492-9d03-e9ea280f0871">
    <p>Os arquivos file_manager.hpp e file_manager.cpp sao onde estao escrito todo os processos referente ao gerenciamento da leitura e escrita de dados nos arquivos, ficando responsaveis exclusivamente por lidar com o arquivo e, dessa forma, construir uma boa relacao de desaclopamento de funcao onde cada classe tem suas funcoes especificas.</p>
    <img style="height:50px;" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/54627e62-b039-4344-98e7-c6adb2e0b0de">
    <p>Os arquivos table_manager.cpp e table_manager.hpp sao responsaveis por lidar com a parte logica do problema e realizar as manipulacoes na matriz,e depois envia-las para a classe que eh responsavel por escrever no arquivo</p>

  <li>Fluxo de codigo</li>
  <p>Para construir uma boa organizacao de codigo onde cada classe tem suas respectivas funcoes a estrutura seguida foi a seguinte: Uma classe responsavel por lidar com o processo de leitura e escrita no arquivo, outra responsavel por lidar com a parte logica de manipulacao de matrizes e regras de jogo e por fim o arquivo main que tem a funcao apenas de chamar as funcoes das classes que compoe o programa</p>
  <ul>
    <li><img style="width:400px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/db8fe5bd-4b91-4cd6-b157-307b87ae330b" ><p>Primeiramente instancia um objeto do tipo table_manager passando o caminho do arquivo de entrada e a quantidade de execucoes</p></li>
    <li><img style="width:150px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/b3a82dda-34bd-48f6-b01b-84ffb59c47ff"> <p>Logo apos chama a funcao initializer da classe table_manager </p></li>
    
   <li> <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/5dbf727a-f10f-4cb4-993d-8198c139d0a4">
     <p>A funcao initializer roda uma serie de codigo a quantidade de vezes que foram passadas na instanciacao do objeto</p></li>
     <li><img src=""> </li>
  </ul>
      
</ul>
   <li>Resolucoes finais</li>
   <p>Para a construcao de um programa que realize de maneira eficiente o exercicio proposto foram necessarios conhecimentos precissos da linguagem de programacao utilizada, uma boa compreensao logica do problema exposto, abstracao e manipulacao de estruturas de dados bidimensionais, previsao de erros  e uma boa organizacao de codigo para facilitar a escrita do programa.</p>
</ul>
