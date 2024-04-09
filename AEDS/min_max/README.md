<h1 align="center">ANÁLISE ASSINTÓTICA E CUSTO COMPUTACIONAL</h1>
<div align="center"> <img height="50px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/e23053b2-63e7-486c-aaf0-11bb4a30fd3c">
 </div>
<h3>Sumário</h3>
<ul>
 <li><strong>Introdução</strong></li>
 <li><strong>Descrição da resolução</strong></li>
 <li><strong>Exposição dos algoritmos de teste</strong></li>
 <li><strong>Exposição dos dados de entradas</strong></li>
 <li><strong>Condições de análise</strong></li>
 <li><strong>Resultados e conclusoes</strong></li>
 <li><strong>Ferramentas usadas</strong></li>
 <li><strong>Referencias</strong></li>
</ul>

 <hr>
<h2 align="center">Introdução</h2>
<p align="center">"A análise de desempenho é uma etapa fundamental na concepção de um algoritmo. Diante de um problema computacional, diversas soluções podem ser propostas. Por exemplo, para ordenar uma sequência de números, o desenvolvedor pode utilizar algoritmos como o BubbleSort, MergeSort, QuickSort, entre outros. Entender como esses algoritmos se comportam à medida que aumentamos o tamanho da entrada a ser ordenada é primordial para decidirmos qual solução adotar em um determinado contexto.</p>

<p align="center">
 
 Analisar um algoritmo significa prever a quantidade de recursos que tal algoritmo consome ao ser executado. Diversas variáveis podem ser objetos de estudo da análise de um algoritmo, por exemplo, consumo de memória, largura de banda de comunicação, entre outros."
(Brunet, 2019)[^1]

</p>



 
<p align="center">Contudo, com frequência, desejamos medir o tempo de execução de um programa em um ambiente controlado e a isso damos o nome de abordagem empírica. Neste contexto, este projeto tem o objetivo de calcular e realizar comparações a respeito de algoritmos que descobrem valores máximos e mínimos em uma base de dados de tamanhos e com ordenações diversas, fazendo uso de três algoritmos formulados de maneiras diferentes, afim de chegar à conclusão de qual deles tem a melhor performance e em quais situações eles se encaixam melhor.</p>
<hr>
<h2 align="center">Descrição da resolucao</h2>
<p align="center">Para bem tratar e chegar as conclusoes necessarias quanto a eficiencia comparada dos tres algoritimos que serao apresentados a abordagem tomada sera a seguinte, serao usadas diferentes entradas de dados de diferentes tamanhos e ordenacoes para que se tenha nocao se acasso algum algoritimo performa melhor em alguma condicao especifica, se a eficiencia dos algoritimos independem da ordenacao e ainda se existe outras condicoes que podem interferir no dessempenho dos mesmos; para que se tenha uma justa medida do tempo gasto por cada algoritimo em cada situacao que sera abordada fazer-se-a o calculo do tempo gasto em todas as  execucoes em conjunto, ou seja, sem distincao de ordenacao de dados,mas ainda distiguindo-se o tamanho da entrada, e logo apos o tempo gasto em cada condicao especifica de ordenacao e tamanho da entrada de dados. </p>
<p align="center">A forma com que sera calculada o tempo gasto por  cada algoritimo durante sua execucao sera fazendo-se uso da biblioteca padrao da linguagem <strong>C++</strong> <strong>CHRONO</strong> que eh amplamente usada para medicao de tempo em programas escritos em C ou C++.</p>
<p align="center"> Segue um pseudo codigo de como sera feita a medicao de tempo</p>
<div align="center"> <img align="center" height="160px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/794be396-1b00-454d-9ce4-cda8efcfbf0d">

</div><p align="center">Dessa forma, obtendo o tempo de execução de cada algoritmo individualmente, poderemos chegar às conclusões necessárias quanto ao custo computacional e análise assintótica dos algoritmos de estudo.</p>

<hr>
<h2 align="center">Exposição dos algoritmos de teste</h2>

<p align="center">
    Como dito anteriormente, os algoritmos a serem analisados executam a tarefa de encontrar um menor e um maior valor dentro de uma base de dados de <strong>n</strong> posições.
    As bases de dados serão vetores preenchidos com números de 1 a 1000.
    Adiante, será esclarecido como serão dispostos tais vetores.
    Faremos uso de três algoritmos que, embora realizem a mesma operação, o fazem de maneiras diferentes.
</p>

<h3 align="center">ALGORITMO 1 - MINMAX 1</h3>

<p align="center">
    O primeiro algoritmo, chamado <strong>minmax1</strong>, realiza sua função de maneira bem simples,
    fazendo com que, dentre os três algoritmos com os quais trabalharemos, ele seja o de menor complexidade
    e também, logicamente, o de implementação mais simples.
    A implementação deste algoritmo em C++ pode ser encontrada na linha 7 do arquivo 
    <a href="https://github.com/joaopaulocunhafaria/Faculdade/blob/7c8fc1f23c02af0dcf4a43c28427759ad79c92e7/AEDS/min_max/src/minMax.cpp#L7">
        <strong>minMax.cpp</strong>
    </a> 
    dentro da pasta <strong>src</strong>.
</p>

<div align="center">
    <img height="150px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/9777f4f1-0753-4a7e-8d3a-00dccceeb351">
    <p>
    
Implementação em COBOL do <strong>minmax1</strong>. (Loureiro A.A.F, 2010)[^2] 
     
</p>
</div>

</div><h3 align="center">ALGORITMO 2 - MINMAX 2</h3>

<p align="center">
    Seguindo um caminho lógico bem semelhante ao primeiro algoritmo, a segunda versão apresenta uma solução um pouco mais elaborada.
    Diferenciando-se apenas na condição de que, ao invés de em cada iteração serem realizadas duas comparações, ele envolve o código com uma condicional <em>if</em> e uma segunda condição <em>else if</em>.
    Dessa forma, em alguns casos, principalmente devido à ordenação dos vetores, será feita durante cada iteração apenas uma única comparação ao invés das duas que sempre são feitas no primeiro caso. Isso consequentemente economiza processamento, visto que o número de instruções realizadas pela máquina é menor. Tal diferença pode causar grandes impactos, principalmente em quantidades massivas de dados.
</p>
<p align="center">A implementacao em C++ da segunda versao do algoritimo pode ser encontrada na linha 34, tambem no arquivo <a href="https://github.com/joaopaulocunhafaria/Faculdade/blob/7c8fc1f23c02af0dcf4a43c28427759ad79c92e7/AEDS/min_max/src/minMax.cpp#L34"><strong>minMax.cpp</strong></a></p>
<div align="center" >
    <img height="150px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/f6590068-4822-4945-901a-58cfd9a33649">
   <p>
    
   Implementação em COBOL do <strong>minmax2</strong>. (Loureiro A.A.F, 2010)[^2] 
    </p>
</div>
</div><h3 align="center">ALGORITMO 3 - MINMAX 3</h3>

<p align="center">
   Seguindo uma abordagem um pouco diferente dos dois primeiros algoritimos a terceira versao opta por uma abordagem com maior complexidade logica e de implementacao mas que pode trazer algumas vantagens, novamente em decorrencia da organizacao da massa de dados de entrada. Nesta implementacao o algoritimo utiliza-se de duas comparacoes consecutivas das posicoes <em>i</em> e <em>i+1</em> em cada iteracao, reduzindo como que pela metade a quantidade final de interacoes realizadas pelo algoritimo.
</p>
<p align="center">A implementacao em C++ da terceira versao do algoritimo pode ser encontrada na linha  62,   no arquivo <a href="https://github.com/joaopaulocunhafaria/Faculdade/blob/7ba8c27063c41bf034e8e99e1f3fd7f01ef862fd/AEDS/min_max/src/minMax.cpp#L62"><strong>minMax.cpp</strong></a></p>
<div align="center" >
    <img height="300px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/b3e6e628-471a-4d05-a0b3-58de38b7a659">
 <img height="290px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/447a3360-4955-400a-898b-ac76d7bd4db0">
 
 <p>
 
  Implementação em COBOL do <strong>minmax3</strong>. (Loureiro A.A.F, 2010)[^2] 
 </p>
</div>
<hr>
<h2 align="center">Exposição dos dados de entradas</h2>
<p align="center">Com o intuito de melhor testar cada algoritmo de modo a expor cada um deles em uma gama de testes mais diversa, as entradas de dados serão distribuídas da seguinte forma:</p>
 <table border="1" align="center">
      <tr>
        <td>Tamanho da entrada <strong>n</strong></td>
        <td>Ordenações</td>
      </tr>
      <tr>
        <td>1000</td>
        <td>Aleatório, crescente, decrescente</td>
      </tr>
      <tr>
        <td>10000</td>
        <td>Aleatório, crescente, decrescente</td>
      </tr>
      <tr>
        <td>100000</td>
        <td>Aleatório, crescente, decrescente</td>
      </tr>
        <tr>
        <td>500000</td>
        <td>Aleatório, crescente, decrescente</td>
      </tr>
     
 </table>

 <p align="center">Com os números que compõem cada entrada variando de 0 a 1000, as mesmas serão construídas primeiramente inicializando um vetor com números aleatórios de 0 a 1000 e depois ordenando cada um conforme mostrado acima, de modo crescente e decrescente, exceto, é claro, aquela entrada de dados que será aleatória, ou seja, sem ordenação.</p>
<hr> 
<h2 align="center">Condições de análise</h2>
<p align="center">Visando sempre os melhores resultados possíveis e, novamente, com o intuito de testar bem cada algoritmo, as condições de análise serão impostas para que os resultados não sejam afetados por condições que não as presentes nos próprios algoritmos.</p>
<p align="center">Dessa forma, o tempo considerado para análise de cada algoritmo será a média calculada entre dez execuções. Assim, cada algoritmo com cada ordenação e tamanho de dados será testado dez vezes e terá suas médias calculadas para que se obtenha um resultado final.</p>
<p align="center">Somado a isso, as condições da máquina de teste são outra característica que pode interferir de maneira considerável no tempo de execução de cada algoritmo. Embora, de modo geral, as condições e o desempenho de cada um possam ser tomados de maneira comum a todos, fazendo com que mesmo tendo diferenças de tempo devido ao hardware, as devidas proposições sempre são guardadas, fazendo com que nenhum sobreponha outro por estar em um ambiente diferente.</p>
 <p align="center">Este projeto foi testado no seguinte ambiente:</p>

     
     
     
 <table border="1" align="center">
      <tr>
        <td>Sistema Operacional </td>
        <td>Debian 12 - "Bookworm"</td>
      </tr>
      <tr>
        <td>Compilador </td>
        <td>G++ 12.2.0</td>
      </tr>
      <tr>
        <td>Hardware </td>
        <td>11th Gen Intel(R) Core(TM) i5-11400H @ 2.70GHz, 8GB RAM, 512GB SSD</td>
      </tr>   
 </table>
<hr>
<h2 align="center">Resultados e conclusoes</h2>
<p align="center">Tomando a literatura como base para termos nocao do que esperar da analize pratica, utilizaremos das conclusoes teoricas presente, tambem, no material de aula do professor Loureiro A.A.F como ja citado acima. De acordo com os resultados apresentados pelo professor o custo assintotico de cada um dos tres algoritimos,ja apresentados, nos tres casos possiveis que sao o melhor caso, pior caso e caso medio, sao os seguintes.</p>
<div align="center"><img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/07a16d2c-eb19-4a19-8d4d-fc9e8550f73f" height="100px">
<p  align="center">
 
Loureiro A.A.F, 2010[^2] 
</p>
</div>

<p align="center">A partir desses resultados, podemos supor que cada algoritmo pode apresentar um desempenho melhor ou pior, dependendo de qual caso ele está executando. Os "casos" neste trabalho serão as formas com as quais as massas de dados estão organizadas. Analisando os resultados do custo assintótico de cada algoritmo, percebemos que o <strong>minmax1</strong> e o <strong>minmax3</strong> possuem um custo linear, ou seja, não se alteram em relação aos casos, e também que o <strong>minmax3</strong> apresenta um resultado ligeiramente melhor que o <strong>minmax1</strong>. O <strong>minmax2</strong>, por sua vez, possui um custo que pode variar conforme o caso em que ele está executando. Tal variação pode fazer com que ele tenha uma performance melhor ou pior que os demais, dependendo do caso.</p>
<p align="center">Tendo agora um aparato teórico com o qual podemos nos basear e saber o que esperar, vamos agora para os resultados práticos. Para melhor analissarmos a eficiecia e o custo de cada algoritimo iremos dividir os os teste segundo a ordenacao de dados, primeiramente iremos analisar os resultados para os testes feitos com os a massa de dados ordenadas crescentemente.</p>
<h4 align="center">Crescente</h4>
<div align="center">
 <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/be20488a-a255-4712-be30-e2df32fbc0ba" height="200px">
 <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/561e1556-e954-4208-86a3-eb8b1e72df46" height="200px">
 <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/e0169ba6-b573-4283-a8db-52e8e93e6011" height="200px">
</div>
<div align="center">
<img height="250px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/03cdc72f-f8a0-4622-aa08-15a661a1eddf">
 
</div>
<h4 align="center">Decrescente</h4>
<div align="center">
 <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/8d2508e3-e6a0-42ef-8495-aeab0a3eda93" height="200px">
 <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/47eed561-a5b1-4532-8cf2-4f479fc148aa" height="200px">
 <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/637444bb-38c7-44d8-aff1-40cb7392155f" height="200px">
</div>
<div align="center">
 <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/d3531e42-7a38-4de1-b0e3-e98c030f803a" height="250px">
</div>

<h4 align="center">Aleatorio</h4>
<div align="center">
 <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/d71ade5a-481e-49c6-8c43-90f1bbdf00d8" height="200px">
 <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/11250291-9bfe-4fb4-9d50-a684bd64092e" height="200px">
 <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/de3458ad-9c23-4a2e-903b-5f057c9b1161" height="200px">
</div>
<div align="center">
 <img src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/f4d245be-bf15-4fae-a490-2df1c71c49cd" height="250px">
</div>



<hr>


<h2>Contato</h2>
<div><a href="https://www.linkedin.com/public-profile/settings?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_self_edit_contact-info%3BObdM58vxRxmAhVnA76lGBQ%3D%3D"><img  height="25px" src="https://github.com/joaopaulocunhafaria/Faculdade/assets/138056835/03a2e495-7b32-4f8e-93d6-c90963460432"></a></div>
<h2 align="center">Referências</h2>

[^1]:Rerefencia do site de introducao a analise assintotica https://joaoarthurbm.github.io/eda/posts/introducao-a-analise/
[^2]: LOURERO, A. F. nome do material. Disponivel em:  https://homepages.dcc.ufmg.br/~loureiro/alg/091/paa_Analise.pdf. Acesso em 10/04/200
