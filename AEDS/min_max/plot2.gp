# Define o terminal de saída e o arquivo de saída
set terminal png
set output 'todas_as_funcoes.png'

# Configurações do gráfico
set xlabel 'Tempo de execução (em segundos)'
set ylabel 'Tamanho da entrada de dados'
set title 'Resultados'
set yrange [0:550000]
set ytics add (1000, 10000, 100000, 500000)
set ytics font ",8"

# Plotagem dos dados
plot 'test.txt' using 1:2 with linespoint pointtype 7 title 'minmax3', \
     '' using 1:3 with linespoint pointtype 7 title 'minmax2', \
     '' using 1:4 with linespoint pointtype 7 title 'minmax1'
