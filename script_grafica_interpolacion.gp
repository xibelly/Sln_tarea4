plot "fdex_sample.dat" title  "fdex_sample.dat" 
set terminal png
set output "grafica_inter_akima_per.png" 
set pointsize 1.5
set xlabe 'x'
set ylabe 'f(x)'
set key top right
replot "inter_akima_per.dat" title "inter_akima_per.dat" 
