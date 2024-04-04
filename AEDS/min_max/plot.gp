# Define o terminal de saída e o arquivo de saída
set terminal png
set output 'graphs/minmax1_random.png'


# Configurações do gráfico
set xlabel 'Tempo de execucao(em segundos)'
set ylabel 'Tamanho da entrada de dados'
set title 'minmax1 random'
set yrange [0:550000]
set ytics add (1000, 10000, 100000, 500000)
set ytics font ",8"
# Plotagem dos dados
plot 'data.txt' with linespoint pointtype 7
