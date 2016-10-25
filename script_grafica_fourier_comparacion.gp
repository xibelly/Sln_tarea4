plot "fdex_fourier0.5.dat" title  "fdex_fourier0.5.dat" 
set terminal png
set output "grafica_fourier0.5_comparacion.png" 
set pointsize 1.5
set xlabe 'x'
set ylabe 'f(x)'
set key top right
replot "IFT_0.5.dat" u 2:1 title "IFT_0.5.dat" 
