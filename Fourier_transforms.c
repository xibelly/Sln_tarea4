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

struct SALIDA
{
  double salida[2];
};

struct SALIDA *OUT; 

//Parametros globales//

int N;
double *x;
fftw_complex *in1=NULL, *in2=NULL, *in3=NULL;


FILE *input = NULL;
FILE *output = NULL;


//Funciones//

void fourier(int N, fftw_complex *in)
{
  int i;
  fftw_complex *out=NULL;
  fftw_plan my_plan;

  in  = (fftw_complex *) malloc((size_t) N*sizeof(fftw_complex));
  out  = (fftw_complex *) malloc((size_t) N*sizeof(fftw_complex));
  
  my_plan = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_MEASURE);

  fftw_execute(my_plan);

   for(i=0; i<N; i++)
    {
      OUT[i].salida[0] = out [i][0];
	
      OUT[i].salida[1] = out [i][1];

    }
   
   fftw_destroy_plan(my_plan);

   fftw_free(out);
   
   
   printf("THE STATE OF DFT IS: SUCESS\n");
   
}



//Programa Principal


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

  
  OUT = (struct SALIDA *) malloc((size_t) N *sizeof(struct SALIDA));

  //Se crea la funcion f(x) = x*sin(x)//

  //CASO a)

  dx = 2.0 * M_PI/ (1.0 * N);

  input=fopen("fdex_fourier1.dat","w");
  
  for (i = 0; i < N; i++)
    {
      x[i] = dx * i;

      in1[i][0] = x[i] *sin (x[i]);

      in1[i][1] = 0.0;

      fprintf(input,"%g %g %g\n", x[i], in1[i][0], in1[i][1]);

      
    }
  fclose(input);

  //Se calculan las respectiva transformada de Fourier//

  fourier(N, in1);

  output = fopen("fourier_transform_1.dat","w");
  
  for (i = 0; i < N; i++)
    {      
      fprintf(output,"%lf %lf\n", OUT[i].salida[0], OUT[i].salida[1]);
      
    }
  
  fclose(output);
   
  
  // CASO b)
  
  
  input=fopen("fdex_fourier0.5.dat","w");
  
  for (i = 0; i < N; i++)
    {
      x[i] = dx * (i+0.5);
      
      in2[i][0] = x[i] *sin (x[i]);
      
      in2[i][1] = 0.0;
      
      fprintf(input,"%g %g\n", x[i], in2[i][0]);
    }
  fclose(input);
  
  
  fourier(N, in2);
  
  output = fopen("fourier_transform_0.5.dat","w");
  
  for (i = 0; i < N; i++)
    {      
      fprintf(output,"%lf %lf\n", OUT[i].salida[0], OUT[i].salida[1]);
      
    }
  
  fclose(output);
  
  // CASO c)
  
  
  input=fopen("fdex_fourier0.1.dat","w");
  
  for (i = 0; i < N; i++)
    {
      x[i] = dx * (i+0.1);

      in3[i][0] = x[i] *sin (x[i]);
      
      in3[i][1] = 0.0;
      
      fprintf(input,"%g %g\n", x[i], in3[i][0]);
    }
  fclose(input);

  fourier(N, in3);
  
  output = fopen("fourier_transform_0.1.dat","w");
  
  for (i = 0; i < N; i++)
    {      
      fprintf(output,"%lf %lf\n", OUT[i].salida[0], OUT[i].salida[1]);
      
    }
  
  fclose(output);
   
  
  //Se libera memoria usada
  
  free(x);
  
  fftw_free(in1);
  fftw_free(in2);
  fftw_free(in3);

  return 0;
}

