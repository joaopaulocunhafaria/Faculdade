# Define o terminal de saída e o arquivo de saída
set terminal png
set output 'min_max1_crescente.png'


# Configurações do gráfico
set xlabel 'Tempo de execucao'
set ylabel 'Tamanho da entrada'
set title 'results'
set yrange [0:550000]
set ytics add (1000, 10000, 100000, 500000)
set ytics font ",8"
# Plotagem dos dados
plot 'data.txt' with linespoint pointtype 7
