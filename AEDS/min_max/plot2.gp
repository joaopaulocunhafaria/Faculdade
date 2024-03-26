set terminal png
set output 'plot.png'

set xlabel 'Tempo'
set ylabel 'Valor'

set title 'Dados Ordenados'

set key top left

plot 'test.txt' using 1:2 with lines title '1000', \
     '' using 1:3 with lines title '10000', \
     '' using 1:4 with lines title '100000', \
     '' using 1:5 with lines title '500000'
