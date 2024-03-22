<h1 align="center">Trabalho de Aquecimento AEDS 1</h1>
<h2  align="center">JOGO DA VIDA</h2>
<ul>
  <li >📌 OBJETIVOS</li>
  <p>O objetivo deste trabalho é revisar os conceitos de manipulação de matrizes, controle de fluxo e lógica de jogo para reforçar e exercitar conceitos de lógica de programação.</p>
    <li>✒️ DESCRICAO</li>
  <p>O Jogo da Vida é um autômato celular que evolui de acordo com regras simples, mas
gera padrões complexos. Ele é representado por uma matriz 2D de células, cada uma
podendo estar viva ou morta.</p>
  <li>📄 IMPLEMENTAÇÃO E REGRAS</li>
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
  <li>💻 CONDIÇÕES</li>
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
   <li>🔨 ORGANIZAÇÃO E FLUXO DE CÓDIGO</li>
   <ul>
     <li style="display:inline;">    <img style="height:25px;" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/822c4da5-2aff-4013-b26f-a3aea03cff0a"></li>
      <p>Dentro da pasta "datasets", no arquivo "input.mps", está disposta a dimensão da matriz de entrada do programa, assim como os caracteres que a compõem. A organização do arquivo se dá da seguinte forma. </p>
      <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/8a83331a-df50-474a-8a1b-c791f2673197" style="height:200px">
     <li><img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/e5d96fed-1227-4aa9-8a12-28e29b1bba2e" style="height:25px;" ></li>
     <p>O arquivo "geracoes.mps" é responsável por armazenar os resultados de cada iteração do código e registrar a evolução da matriz seguindo as regras do jogo. Um exemplo de uma execução onde ocorreram 3 iterações.</p>
     <li></li>
     <div>
       <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/c24e6e4d-23b5-4d9b-b7fe-b3abf630c2b0" style="height:400px">
       <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/6836a49d-b379-4e24-b33b-ce5407990273" style="height:400px">
        
</div>
      <li><img style="height:25px;" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/523ce255-ec5a-43a9-a2fa-945cffddb7e7"></li>
      <p>A pasta "src" é onde está toda a estruturação e organização do programa, dividindo-se da seguinte forma.</p>
    <img style="height:50px;" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/d01eaee6-a613-4492-9d03-e9ea280f0871">
    <p>Os arquivos "file_manager.hpp" e "file_manager.cpp" são onde está escrito todo o processo referente ao gerenciamento da leitura e escrita de dados nos arquivos, ficando responsáveis exclusivamente por lidar com o arquivo e, dessa forma, construir uma boa relação de desacoplamento de função onde cada classe tem suas funções específicas.</p>
    <img style="height:50px;" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/54627e62-b039-4344-98e7-c6adb2e0b0de">
    <p>Os arquivos "table_manager.cpp" e "table_manager.hpp" são responsáveis por lidar com a parte lógica do problema e realizar as manipulações na matriz, e depois enviá-las para a classe que é responsável por escrever no arquivo.</p>

  <li>Fluxo de codigo</li>
  <p>Para construir uma boa organização de código, onde cada classe tem suas respectivas funções, a estrutura seguida foi a seguinte: uma classe responsável por lidar com o processo de leitura e escrita no arquivo, outra responsável por lidar com a parte lógica de manipulação de matrizes e regras de jogo, e por fim o arquivo main, que tem a função apenas de chamar as funções das classes que compõem o programa.</p>
  <ul>
    <li><img style="width:400px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/db8fe5bd-4b91-4cd6-b157-307b87ae330b" ><p>Primeiramente, instancia-se um objeto do tipo table_manager, passando o caminho do arquivo de entrada e a quantidade de execuções.</p></li>
    <li><img style="width:150px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/b3a82dda-34bd-48f6-b01b-84ffb59c47ff"> <p>Logo após, chama-se a função initializer da classe table_manager. </p></li>
    
   <li> <img style="height:150px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/5dbf727a-f10f-4cb4-993d-8198c139d0a4">
     <p>A função initializer executa uma série de códigos a quantidade de vezes que foi passada na instanciação do objeto.</p></li>
     <li><img style="width:300px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/417ff647-7586-4226-8109-d8f53d32aad3"> <p>O primeiro passo do bloco de código é chamar a função write_table da classe file_manager, que foi instanciada na construção do objeto, passando a matriz, o caminho do arquivo onde será escrita e qual é a iteração. Na primeira iteração, será escrita a matriz da forma como está no arquivo de entrada. </p> </li>
     <li><img style="width:150px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/3e68ab2d-1ac4-43d0-8573-c66f2f5157ee"> <p>A função next_table realiza os cálculos e altera a matriz "this->table" para que ela possa ser escrita no arquivo de saída com as alterações feitas na próxima iteração. Este processo é repetido a quantidade de vezes fornecida pelo usuário.</p></li>
     <li><img style="width:150px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/9bcfc58b-3cca-4ed4-8830-7eec757b7490"><p>E por fim, quando o ciclo da iteração é concluído, toda a memória que foi alocada durante a execução do código é liberada para evitar vazamento de memória.</p></li>
     <li>Após a realização de todos esses passos, o programa retorna para a função main e retorna 0 se tudo tiver ocorrido corretamente.</li>
  </ul>
   
      
</ul>
<li>👾 COMPILAÇÃO E EXECUÇÃO</li>
    <table border="1" align="center">
      <tr>
        <td>Comando</td>
        <td>Função</td>
      </tr>
      <tr>
        <td>make clean</td>
        <td>Apaga a última compilação realizada contida na pasta build</td>
      </tr>
      <tr>
        <td>make</td>
        <td>Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build</td>  
      </tr>
      <tr>
        <td>make run</td>
        <td>Executa o programa da pasta build após a realização da compilação</td>
      </tr>  
    </table>
   <li>🎯 RESOLUÇÕES FINAIS</li>
   <p>Para a construção de um programa que realize de maneira eficiente o exercício proposto, foram necessários conhecimentos precisos da linguagem de programação utilizada, uma boa compreensão lógica do problema exposto, abstração e manipulação de estruturas de dados bidimensionais, previsão de erros e uma boa organização de código para facilitar a escrita do programa.</p>
   <p>PErgunta: o numero de uns se mantem o msm a partir de uma geracao qualquer? Eles se mantem em um quadrante fixo ou se locomovem na matriz? Se o numero se estabiliza em relacao a entrada esta quantidade eh maior ou menor?</p>
</ul>
