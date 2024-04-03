<h1 align="center">ANÁLISE ASSINTÓTICA E CUSTO COMPUTACIONAL</h1>
<div align="center"> <img height="50px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/e23053b2-63e7-486c-aaf0-11bb4a30fd3c">
 </div>
<h3>Sumario</h3>
<ul>
 <li><strong>Introdução</strong></li>
 <li><strong>Descrição da resolucao</strong></li>
 <li><strong>Exposicao dos algoritimos de teste</strong></li>
 <li><strong>Exposicao das entradas de dados</strong></li>
 <li><strong>Condicoes de analise</strong></li>
 <li></li>
</ul>
<hr>
<h2 align="center">Introdução</h2>
<p align="center">"A análise de desempenho é uma etapa fundamental na concepção de um algoritmo. Diante de um problema computacional, diversas soluções podem ser propostas. Por exemplo, para ordenar uma sequência de números, o desenvolvedor pode utilizar algoritmos como o BubbleSort, MergeSort, QuickSort, entre outros. Entender como esses algoritmos se comportam à medida que aumentamos o tamanho da entrada a ser ordenada é primordial para decidirmos qual solução adotar em um determinado contexto.</p>
<p align="center">Analisar um algoritmo significa prever a quantidade de recursos que tal algoritmo consome ao ser executado. Diversas variáveis podem ser objetos de estudo da análise de um algoritmo, por exemplo, consumo de memória, largura de banda de comunicação, entre outros."
(Brunet, João Arthur. "Introdução à Análise de Algoritmos." <a href="https://joaoarthurbm.github.io/eda/posts/introducao-a-analise/">Link para o artigo.</a>).
</p>

 
<p align="center">Contudo, com frequência, desejamos medir o tempo de execução de um programa em um ambiente controlado e a isso damos o nome de abordagem empírica. Neste contexto, este projeto tem o objetivo de calcular e realizar comparações a respeito de algoritmos que descobrem valores máximos e mínimos em uma base de dados de tamanhos e com ordenações diversas, fazendo uso de três algoritmos formulados de maneiras diferentes, afim de chegar à conclusão de qual deles tem a melhor performance e em quais situações eles se encaixam melhor.</p>
<hr>
<h2 align="center">Descrição da resolucao</h2>
<p align="center">Para bem tratar e chegar as conclusoes necessarias quanto a eficiencia comparada dos tres algoritimos que serao apresentados a abordagem tomada sera a seguinte, serao usadas diferentes entradas de dados de diferentes tamanhos e ordenacoes para que se tenha nocao se acasso algum algoritimo performa melhor em alguma condicao especifica, se a eficiencia dos algoritimos independem da ordenacao e ainda se existe outras condicoes que podem interferir no dessempenho dos mesmos; para que se tenha uma justa medida do tempo gasto por cada algoritimo em cada situacao que sera abordada fazer-se-a o calculo do tempo gasto em todas as  execucoes em conjunto, ou seja, sem distincao de ordenacao de dados,mas ainda distiguindo-se o tamanho da entrada, e logo apos o tempo gasto em cada condicao especifica de ordenacao e tamanho da entrada de dados. </p>
<p align="center">A forma com que sera calculada o tempo gasto por  cada algoritimo durante sua execucao sera fazendo-se uso da biblioteca padrao da linguagem <strong>C++</strong> <strong>CHRONO</strong> que eh amplamente usada para medicao de tempo em programas escritos em C ou C++.</p>
<p align="center"> Segue um pseudo codigo de como sera feita a medicao de tempo</p>
<div align="center"> <img align="center" height="160px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/794be396-1b00-454d-9ce4-cda8efcfbf0d">
</div>
<hr>
<h2 align="center">Exposicao dos algoritimos de teste</h2>
<p align="center">Como dito anteriormente os algoritimos a serem analissado executam a tarefa de encontrar um menor e maior valor dentro de uma base de dados de <strong>n</strong> posicoes, as bases de dados serao vetores preenchido com numeros 1-1000, adiante sera esclarecido como serao dispostos tais vetores. Faremos uso de tres algoritimos que embora realizem a mesma operacao o fazem de maneira diferente. </p>
<h3 align="center">ALGORITIMO 1 - MINMAX 1</h3>
<p align="center">O primeiro algoritimo chamado de <strong>minmax1</strong> realiaza sua funcao de maneira bem simples, fazendo com que dentre os tres algoritimos com os quais trabalharemos ele seja o de menor complexidade e tambem, logicamente, o de implementacao mais simples. A implementacao deste algoritimo em C++ pode ser encontrada na linha 7 do arquivo <strong>minMax.cpp</strong> dentro da pasta <strong>src</strong></p>
<div align="center">
<img height="150px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/9777f4f1-0753-4a7e-8d3a-00dccceeb351">
 <p>Implementacao em cobol do <strong>minmax1</strong>. (Loureiro A.A.F, 2010</p>
</div>
