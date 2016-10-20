/*
Xibelly Eliseth Mosquera Escobar

Solucion punto 1 Tarea 4 COMPUTACION CIENTIFICA AVANZADA

1) Generar una tabla de datos con 20 puntos entre x=0 y x=2*M_PI

2) Interpolar -> vamos a generar una funcion para cada tipo de interpolador
   evluar la funcion en puntos igualmente espaciados, con frecuencia de 0.01

   vamos a imprimir en disco cada tipo de interpolacion

3) Graficar los resultados de todos los tipos de interpolador

4) Evaluar la diferencia cuadratica media entre los diferentes metodos de interpolacion usados. Para ello vamos a crear una funcion que recibe las interpolaciones que van a ser comparadas y vamos imprimir en pantalla cada resultado talque el usuario decida cual es el metodo que presenta menos error.

 */

/*
  NOTA: ESTE PROGRAMA SE ENCARGA DEL PUMTO 4)

 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_sort_float.h>


//Parametros globales//

int N;

FILE *in1;
FILE *in2;


//Estructuras//

struct data   
{
  double x1, f1;
  double x2, f2;
  
}; 
struct data *datos; 

//Llamados a subrutinas//

#include "input.c"

//Funciones//




int main (int argc, char *argv[])
{
  
  int i;
  double xo, yo;
  double dx;

  printf("%d\n",argc);
  
  if(argc != 4)
    {
      printf("ERROR--> use as:\n");
      printf("%s Nline file1 file2\n",argv[0]);
      exit(0);  
    }

  N = atoi(argv[1]);

  file1 = argv[2];

  file2 = argv[3];

  //Lectura archivos -carga de datos-//

  
  read_file1(file1,N);

  read_file2(file2,N);

  
  return 0;
}

