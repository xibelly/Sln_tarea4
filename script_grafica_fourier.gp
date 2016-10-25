set terminal png
set output "grafica_fourier0.5_complex.png" 
set pointsize 1.5
set xlabe 'frecuncies'
set ylabe 'Complex FT'
set key top right
plot "FT_0.5.dat" u 2 w lp title "FT_0.5.dat" 
