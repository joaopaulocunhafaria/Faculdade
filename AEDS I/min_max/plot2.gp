# Define o terminal de saída e o arquivo de saída
set terminal png
set output 'graphs/crescente.png'

# Configurações do gráfico
set xlabel 'Tempo de execucao (em segundos)'
set ylabel 'Tamanho da entrada de dados'
set title 'Crescente'
set yrange [0:600000]
set ytics add (1000, 10000, 100000, 500000)
set ytics font ",8"

# Plotagem dos dados
plot 'test.txt' using 1:4 with linespoints title 'minmax1', \
     'test.txt' using 2:4 with linespoints title 'minmax2', \
     'test.txt' using 3:4 with linespoints title 'minmax3'
