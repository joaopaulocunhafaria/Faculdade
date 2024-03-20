# Define o terminal de saída e o arquivo de saída
set terminal png
set output 'results.png'


# Configurações do gráfico
set xlabel 'Tempo de execucao'
set ylabel 'Tamanho da entrada'
set title 'results'
set yrange [0:550000]

# Plotagem dos dados
plot 'data.txt' with linespoint pointtype 7
