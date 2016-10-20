/*Xibelly Eliseth Mosquera Escobar
 * 
 * programa: input.c
 * 
 * 
 * Se encarga de leer los datos de
 * un archivo dado le longitud arbitraria
 * usando malloc.
 * 
 * 
 * La funcion "read_file" recibe como entradas
 * la longitud del archivo y el nombre del archivo
 * a leer. Ambas entradas se hacen usando 
 * la variable ARGS en el makefile incluido con
 * el programa.
 *
 * 
 
 */



int read_file1(char *filename, int N)
{
  int i, nread;
  double X, Y;

  FILE *pf = NULL;
  
  pf = fopen(filename,"r"); 
  
  datos = (struct data*) malloc(N *sizeof(struct data));

  printf(" ->In read_file:\n");
    
  for(i=0; i<N; i++)
    {
      nread = fscanf(pf,"%lf %lf",&X, &Y);

      datos[i].x1 = X ; 

      datos[i].f1 = Y ;
      
    }

  

  printf("READ FILE STATE: SUCESSFUL\n");
  
  return 0;
}
