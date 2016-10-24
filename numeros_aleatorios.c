#include <stdio.h>
/*
Xibelly Eliseth Mosquera Escobar

Solucion punto 2 Tarea 4 COMPUTACION CIENTIFICA AVANZADA

1) Vamos a leer los datos que correponden a la interpolacion con la menor diferencia cuadratica media -> akima_periodico

2) tomamos el valos min y max

3) con estos datos vamos a generar 1000 numeros aleatorios uniformamente distribuidos
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<gsl/gsl_rng.h>
#include <gsl/gsl_sort_int.h>
#include <gsl/gsl_sort_double.h>


//Variables globales//

int N;
char *file;

FILE *out1 = NULL;
FILE *out2 = NULL;
FILE *out3 = NULL;
FILE *out4 = NULL;
FILE *out5 = NULL;
FILE *out6 = NULL;
FILE *out7 = NULL;
FILE *out8 = NULL;
FILE *out9 = NULL;
FILE *out10 = NULL;

//Estructuras//

struct data   
{
  double x, f;
  
}; 
struct data *datos;

struct data_result   
{
  double *value;
  
}; 
struct data_result RESULT; 

 
//Llamados a subrutinas//

#include "input.c"

//Funciones//

int random_gfsr4(int N)
{
  
  int i;
  long seed;
  gsl_rng *rng;  //generador de # aleatorios

   
  rng = gsl_rng_alloc (gsl_rng_gfsr4);     
  seed = time(NULL)*getpid();    //semilla que cambia con el tiempo
  gsl_rng_set (rng, seed);       //se establce la semilla
  
  for(i=0; i<1000; i++)
    {
      RESULT.value[i] = gsl_rng_uniform (rng);

    }
 
  gsl_rng_free (rng);                           
 
  return 0;
  
}

int random_taus(int N)
{
  int i;
  long seed;
  gsl_rng *rng;  //generador de # aleatorios

  
  rng = gsl_rng_alloc (gsl_rng_taus);     
  seed = time(NULL)*getpid();    //semilla que cambia con el tiempo
  gsl_rng_set (rng, seed);       //se establce la semilla
  
  for(i=0; i<1000; i++)
    {
      RESULT.value[i] = gsl_rng_uniform (rng);

    }
 
  gsl_rng_free (rng);                           
 
  return 0;
  
}

int random_rand48(int N)
{
  int i;
  long seed;
  gsl_rng *rng;  //generador de # aleatorios

  
  rng = gsl_rng_alloc (gsl_rng_rand48);     
  seed = time(NULL)*getpid();    //semilla que cambia con el tiempo
  gsl_rng_set (rng, seed);       //se establce la semilla
  
  for(i=0; i<1000; i++)
    {
      RESULT.value[i] = gsl_rng_uniform (rng);

    }
 
  gsl_rng_free (rng);                           
 
  return 0;
  
}

int random_mt19937(int N)
{
  int i;
  long seed;
  gsl_rng *rng;  //generador de # aleatorios

  
  rng = gsl_rng_alloc (gsl_rng_mt19937);     
  seed = time(NULL)*getpid();    //semilla que cambia con el tiempo
  gsl_rng_set (rng, seed);       //se establce la semilla
  
  for(i=0; i<1000; i++)
    {
      RESULT.value[i] = gsl_rng_uniform (rng);

    }
 
  gsl_rng_free (rng);                           
 
  return 0;
  
}

int random_ranlxs0(int N)
{
  int i;
  long seed;
  gsl_rng *rng;  //generador de # aleatorios

  
  rng = gsl_rng_alloc (gsl_rng_ranlxs0);     
  seed = time(NULL)*getpid();    //semilla que cambia con el tiempo
  gsl_rng_set (rng, seed);       //se establce la semilla
  
  for(i=0; i<1000; i++)
    {
      RESULT.value[i] = gsl_rng_uniform (rng);

    }
 
  gsl_rng_free (rng);                           
 
  return 0;
  
}

int random_ranlxs1(int N)
{
  int i;
  long seed;
  gsl_rng *rng;  //generador de # aleatorios

  
  rng = gsl_rng_alloc (gsl_rng_ranlxs1);     
  seed = time(NULL)*getpid();    //semilla que cambia con el tiempo
  gsl_rng_set (rng, seed);       //se establce la semilla
  
  for(i=0; i<1000; i++)
    {
      RESULT.value[i] = gsl_rng_uniform (rng);

    }
 
  gsl_rng_free (rng);                           
 
  return 0;
  
}

int random_mrg(int N)
{
  int i;
  long seed;
  gsl_rng *rng;  //generador de # aleatorios

  
  rng = gsl_rng_alloc (gsl_rng_mrg);     
  seed = time(NULL)*getpid();    //semilla que cambia con el tiempo
  gsl_rng_set (rng, seed);       //se establce la semilla
  
  for(i=0; i<1000; i++)
    {
      RESULT.value[i] = gsl_rng_uniform (rng);

    }
 
  gsl_rng_free (rng);                           
 
  return 0;
  
}

int random_ranlux(int N)
{
  int i;
  long seed;
  gsl_rng *rng;  //generador de # aleatorios

  
  rng = gsl_rng_alloc (gsl_rng_ranlux);     
  seed = time(NULL)*getpid();    //semilla que cambia con el tiempo
  gsl_rng_set (rng, seed);       //se establce la semilla
  
  for(i=0; i<1000; i++)
    {
      RESULT.value[i] = gsl_rng_uniform (rng);

    }
 
  gsl_rng_free (rng);                           
 
  return 0;
  
}

int random_ranlxd1(int N)
{
  int i;
  long seed;
  gsl_rng *rng;  //generador de # aleatorios

  
  rng = gsl_rng_alloc (gsl_rng_ranlxd1);     
  seed = time(NULL)*getpid();    //semilla que cambia con el tiempo
  gsl_rng_set (rng, seed);       //se establce la semilla
  
  for(i=0; i<1000; i++)
    {
      RESULT.value[i] = gsl_rng_uniform (rng);

    }
 
  gsl_rng_free (rng);                           
 
  return 0;
  
}

int random_cmrg(int N)
{
  int i;
  long seed;
  gsl_rng *rng;  //generador de # aleatorios

  
  rng = gsl_rng_alloc (gsl_rng_cmrg);     
  seed = time(NULL)*getpid();    //semilla que cambia con el tiempo
  gsl_rng_set (rng, seed);       //se establce la semilla
  
  for(i=0; i<1000; i++)
    {
      RESULT.value[i] = gsl_rng_uniform (rng);

    }
 
  gsl_rng_free (rng);                           
 
  return 0;
  
}

//Programa Principal//

int main (int argc, char *argv[]) 
{
  int i;
  double xmin, xmax;
  double *value;
  double *X;

  printf("%d\n",argc);
  
  if(argc != 3)
    {
      printf("ERROR--> use as:\n");
      printf("%s Nline file\n",argv[0]);
      exit(0);  
    }

  //Carga de parametros//

  N = atoi(argv[1]);

  file = argv[2];

  printf("%s %d %s\n",argv[0], N, file);

  datos  = (struct data *) malloc(N *sizeof(struct data));

  RESULT.value  = (double *) malloc(N *sizeof(double));

  X = (double *) malloc(N *sizeof(double));

  size_t p[N];

  int k = N;


  //Lectura archivos -carga de datos-//
  
  read_file(file,N);

  for(i=0; i<N; i++)
    {
      X[i] = datos[i].x;
    }

  gsl_sort_smallest_index (p, k, X, 1, N);//Se ordenan los datos de forma creciente

  xmin = X[p[0]];

  xmax = X[p[N-1]];
  
  
  //Generacion de numeros aleatorios//

  //GSFR4

  random_gfsr4(N);
  
  out1 = fopen("random_gfsr4.dat","w");

  for(i=0; i<1000; i++)
    {
      
      if((RESULT.value[i] < xmax) && (RESULT.value[i] > xmin))
	{
	  fprintf(out1,"%lf\n", RESULT.value[i]);
     	}
    } 
  
  fclose(out1);

  
  //TAUS

  random_taus(N);

  out2 = fopen("random_taus.dat","w");

  for(i=0; i<1000; i++)
    {
       
    if((RESULT.value[i] < xmax) && (RESULT.value[i] > xmin))
      {
	  fprintf(out2,"%lf\n", RESULT.value[i]);
     	}
    } 
  
  fclose(out2);
  
  
  //RAND48

  random_rand48(N);

  out3 = fopen("random_rand48.dat","w");

  for(i=0; i<1000; i++)
    {
           
      if((RESULT.value[i] < xmax) && (RESULT.value[i] > xmin))
	{
	  fprintf(out3,"%lf\n", RESULT.value[i]);
     	}
    } 
  
  fclose(out3);
 
  //MT19937

  random_mt19937(N);
  
  out4 = fopen("random_mt19937.dat","w");

  for(i=0; i<1000; i++)
    {
     
      
      if((RESULT.value[i] < xmax) && (RESULT.value[i] > xmin))
	{
	  fprintf(out4,"%lf\n", RESULT.value[i]);
     	}
    } 
  
  fclose(out4);
 
  //RANLXS0

  random_ranlxs0(N);
  
  out5 = fopen("random_ranlxs0.dat","w");

  for(i=0; i<1000; i++)
    {
      
      
      if((RESULT.value[i] < xmax) && (RESULT.value[i] > xmin))
	{
	  fprintf(out5,"%lf\n", RESULT.value[i]);
     	}
    } 
  
  fclose(out5);

  //RANLXS1
  
  random_ranlxs1(N);
  
  out6 = fopen("random_ranlxs1.dat","w");

  for(i=0; i<1000; i++)
    {
      
      
      if((RESULT.value[i] < xmax) && (RESULT.value[i] > xmin))
	{
	  fprintf(out6,"%lf\n", RESULT.value[i]);
     	}
    } 
  
  fclose(out6);

  //MRG

  random_mrg(N);
  
  out7 = fopen("random_mrg.dat","w");

  for(i=0; i<1000; i++)
    {
      
      
      if((RESULT.value[i] < xmax) && (RESULT.value[i] > xmin))
	{
	  fprintf(out7,"%lf\n", RESULT.value[i]);
     	}
    } 
  
  fclose(out7);

  //RANLUX
  
  random_ranlux(N);
  
  out8 = fopen("random_ranlux.dat","w");

  for(i=0; i<1000; i++)
    {
      
      
      if((RESULT.value[i] < xmax) && (RESULT.value[i] > xmin))
	{
	  fprintf(out8,"%lf\n", RESULT.value[i]);
     	}
    } 
  
  fclose(out8);

  //RANLXD1

  random_ranlxd1(N);
  
  out9 = fopen("random_ranlxd1.dat","w");

  for(i=0; i<1000; i++)
    {
      
      
      if((RESULT.value[i] < xmax) && (RESULT.value[i] > xmin))
	{
	  fprintf(out9,"%lf\n", RESULT.value[i]);
     	}
    } 
  
  fclose(out9);

  //CMRG

  random_cmrg(N);
  
  out10 = fopen("random_cmrg.dat","w");

  for(i=0; i<1000; i++)
    {
      
      
      if((RESULT.value[i] < xmax) && (RESULT.value[i] > xmin))
	{
	  fprintf(out10,"%lf\n", RESULT.value[i]);
     	}
    } 
  
  fclose(out10);


 
  
  return 0;
}
