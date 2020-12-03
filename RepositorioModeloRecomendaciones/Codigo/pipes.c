//
//  pipes.c
//
//
//  Created by Mauricio de Garay, Bernardo García and Fernando Tapia on 29/09/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>



/* Function prototypes. */


/*
* La función openFile  se encarga de retornar un filepointer con un nuevo archivo de tipo lectura.
*
*
* @params
*
* @returns
       *FILE fpointer
*/
FILE* pipesOpenFile(char *archivo)
{
    return (fopen(archivo, "rt"));
}

/* Function prototypes. */


/*
* La función openFile  se encarga de retornar un filepointer con un nuevo archivo de tipo lectura.
*
*
* @params
*
* @returns
       *FILE fpointer
*/
FILE* pipesWriteNewFile(char *archivo)
{
    return (fopen(archivo, "wt"));
}

void pipesWritePlot(FILE *especial, float *arreglo, int size){
  int contador=0;
  for(int i=0; i<size; i++){
    contador=contador+1;
    if(arreglo[i]!=arreglo[i+1]){
      fprintf(especial, "%d,%d\n",(int)arreglo[i], contador);
      contador=0;
    }
  }
}

void pipesWrite(FILE *archivo, float media, float moda, float mediana, float desviacion, float minimo, float maximo, float distancia){
  fprintf(archivo, "Media: %f\n", media);
  fprintf(archivo, "Moda: %f\n", moda);
  fprintf(archivo, "Mediana: %f\n", mediana);
  fprintf(archivo, "Desviacion: %f\n", desviacion);
  fprintf(archivo, "Minimo: %f\n", minimo);
  fprintf(archivo, "Maximo: %f\n", maximo);
  fprintf(archivo, "Rango: %f\n", maximo-minimo);
  fprintf(archivo, "Distancia: %f\n", distancia);
}

/*
* La función closeFile  se encarga de cerrar el filepointer del archivo.
*
*
* @params
    archivo
*
* @returns
       void
*/
void pipesCloseFile(FILE *data)
{
    fclose(data);
}

/*
* La función writeFile  se encarga de escribir un archivo CSV con los arreglos que recibe.
*
*
* @params
    int rows
    float[] RespuestaResorte
    float[] TiempoDiscreto
    FILE * fpointer
*
* @returns
*/

void pipesObtenerValores(float *arreglo, FILE *archivo){
  float Valor;
  int Basura;
  int i=0;
  while(fscanf(archivo, "%d,%f", &Basura, &Valor)==2){
    arreglo[i]=Valor;
    i=i+1;
  }
  //}
}

/*
void pipesWriteFile(int rows, float RespuestaResorte[], float TiempoDiscreto[], FILE * fpointer)
{
    int i;
	for(i=0; i<rows; i++)
    {
		fprintf(fpointer, "%.2f \t %.4f \n", TiempoDiscreto[i], RespuestaResorte[i]);
	}
}
* La función openGnuPlot  se encarga de retornar un pipepointer que tenga una conexión establecida con GNUPlot.
*
*
* @params
*
* @returns
       FILE * gnupointer
*/
FILE * pipesOpenGnuPlot()
{
    return (popen("gnuplot -persist", "w"));
}
/*
* La función pipesGraphGnuPlot se encarga de graficar en GNUPlot los datos que tenga en un archivo.
*
*
* @params
    gnupointer
    NombreArch
*
* @returns
*/
void pipesGraphGnuPlot(FILE * gnupointer, char NombreArch[])
{
    char cont;
    fprintf(gnupointer,"set xrange[0:6]\nset yrange[0:30]\nset datafile separator \",\"\nset style data histograms\nplot \"%s\" using 2:xtic(1)\n", NombreArch);
    //fflush(gnupointer);
    printf("Presiona enter para continuar...\n");
    scanf("%c", &cont);
    fflush(stdin);
}
/*

*/
void pipesObtenerMatriz(int ancho, float *matriz[ancho], FILE *archivo){
  float Valor;
  int Basura;
  int i=0;
  char cosas[15];
  fscanf(archivo, "%s %s %s %s %s\n", cosas, cosas, cosas, cosas, cosas);
  while(fscanf(archivo, "%s %f %f %f %f\n", cosas, &(matriz[i][0]), &(matriz[i])[1], &(matriz)[i][2], &matriz[i][3])==5){
    printf("%f %f %f %f\n", matriz[i][0], matriz[i][1], matriz[i][2], matriz[i][3]);
    i=i+1;
  }
}

void pipesObtenerRatings(int ancho, float *matriz[ancho], FILE *archivo){
  float Valor;
  int Basura;
  int i=0;
  char cosas[15];
  fscanf(archivo, "%s %s %s\n", cosas, cosas, cosas);
  while(fscanf(archivo, "%s %f %f\n", cosas, &matriz[i][0], &matriz[i][1])==3){
    i=i+1;
  }
}
