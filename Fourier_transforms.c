/*
Xibelly Eliseth Mosquera Escobar

Solucion punto 5 Tarea 4 COMPUTACION CIENTIFICA AVANZADA

1) Muestrear la funcion f(x) = x*sin(x) entre (0,2*M_PI)
con una frecuencia de

a) 1

b) 0.5

c) 0.1

2) Calcular la DFT 1D en cada caso -> usamos librerias de FFTW3
   e imprimos en disco 

3) Comparar resultado numerico y analitico
 */


/*
  NOTA: ESTE PROGRAMA SE ENCARGA DE LOS PUNTOS 1), 2)

 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<fftw3.h>


//Parametros globales//

int N;
double *x;
fftw_complex *in1=NULL, *in2=NULL, *in3=NULL;

FILE *input = NULL;
FILE *output1 = NULL;


fourier1(int N, fftw_complex *in1)
{
  int i;
  fftw_complex *out=NULL;
  fftw_plan my_plan;

 
  out  = (fftw_complex *) malloc((size_t) N*sizeof(fftw_complex));
  
  my_plan = fftw_plan_dft_1d(N, in1, out, FFTW_FORWARD, FFTW_ESTIMATE);

  fftw_execute(my_plan);

  output1 = fopen("fourier_1.dat","w");

   for (i = 0.0; i < N; i++)
    {
      fprintf(output1,"%lf %lf\n", out[i][0], out[i][1]);

    }

   fftw_destroy_plan(my_plan);

   fftw_free(out);

   printf("THE STATE OF DFT WITH FRECUENCY 1 IS: SUCESS\n");


}


fourier2(int N, fftw_complex *in2)
{
  int i;
  fftw_complex *out=NULL;
  fftw_plan my_plan;
  
  
  out  = (fftw_complex *) malloc((size_t) N*sizeof(fftw_complex));

  my_plan = fftw_plan_dft_1d(N, in2, out, FFTW_FORWARD, FFTW_ESTIMATE);

  fftw_execute(my_plan);

  output1 = fopen("fourier_0.5.dat","w");

   for (i = 0; i < N; i++)
    {
      fprintf(output1,"%lf %lf\n", out[i][0], out[i][1]);

    }

   fftw_destroy_plan(my_plan);


   fftw_free(out);

   printf("THE STATE OF DFT WITH FRECUENCY 0.5 IS: SUCESS\n");


}

fourier3(int N, fftw_complex *in3)
{
  int i;
  fftw_complex *out=NULL;
  fftw_plan my_plan;
  
  out  = (fftw_complex *) malloc((size_t) N*sizeof(fftw_complex));

  my_plan = fftw_plan_dft_1d(N, in2, out, FFTW_FORWARD, FFTW_ESTIMATE);

  fftw_execute(my_plan);

  output1 = fopen("fourier_0.5.dat","w");

   for (i = 0; i < N; i++)
    {
      fprintf(output1,"%lf %lf\n", out[i][0], out[i][1]);

    }

   fftw_destroy_plan(my_plan);

   fftw_free(out);
   
   printf("THE STATE OF DFT WITH FRECUENCY 0.1 IS: SUCESS\n");


}


int main (int argc, char *argv[])
{
  
  int i;
  double xo, yo;
  double dx;
  
  
  //Carga de parametros//
  
  N = 20;

  x = (double *) malloc(N *sizeof(double));

  in1   = (fftw_complex *) malloc((size_t) N*sizeof(fftw_complex));
  
  in2   = (fftw_complex *) malloc((size_t) N*sizeof(fftw_complex));

  in3   = (fftw_complex *) malloc((size_t) N*sizeof(fftw_complex));

  

  //Se crea la funcion f(x) = x*sin(x)//

  //CASO a)

  dx = 2 * M_PI/ N;

  input=fopen("fdex_fourier1.dat","w");
  
  for (i = 0; i < N; i++)
    {
      x[i] = dx * i;

      in1[i][0] = (x[i]) *sin (x[i]);

      in1[i][1] = 0.0;

      fprintf(input,"%g %g\n", x[i], in1[i][0]);
    }
  fclose(input);

  

  // CASO b)

  
  input=fopen("fdex_fourier0.5.dat","w");
  
  for (i = 0; i < N; i++)
    {
      x[i] = dx * (i+0.5);

      in2[i][0] = (x[i]) *sin (x[i]);

      in2[i][1] = 0.0;

      fprintf(input,"%g %g\n", x[i], in2[i][0]);
    }
  fclose(input);
  
  // CASO c)

  
  input=fopen("fdex_fourier0.1.dat","w");
  
  for (i = 0; i < N; i=i+0.1)
    {
      x[i] = dx * (i+0.1);

      in3[i][0] = (x[i]) *sin (x[i]);

      in3[i][1] = 0.0;

      fprintf(input,"%g %g\n", x[i], in3[i][0]);
    }
  fclose(input);
  

  //Se calculan las respectivas transformadas de Fourier//

  fourier1(N, in1);

  fourier2(N, in2);

  fourier3(N, in3);

  //Se libera memoria usada

  free(x);
 
  fftw_free(in1);
  fftw_free(in2);
  fftw_free(in3);

  return 0;
}

