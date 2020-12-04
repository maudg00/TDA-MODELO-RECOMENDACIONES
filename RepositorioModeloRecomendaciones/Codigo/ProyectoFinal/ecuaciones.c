//
//  ecuaciones.c
//  TDA
//
//  Created by Equipo 2 on 29/11/20.
//

/*#include "ecuaciones.h"


void ecuacionesRandom(int largo, int ancho, float **matriz){
    srand (time(NULL));
    for(int i=0;i<largo;i++){
        for(int j=0; j<ancho; j++){
            matriz[i][j]=(rand()%100)/100;
        }

    }
}

void ecuacionesPP(int largo, int ancho, int features, float *matriz1[features],
  float *matriz2[features], float *matrizFinal[ancho]){
    for(int i=0; i<largo; i++){
        for(int j=0; j<ancho; j++){
            for(int z=0; z<features; z++){
                matrizFinal[i][j]=matrizFinal[i][j]+(matriz1[i][z]*matriz2[j][z]);
            }
        }
    }
}

void ecuacionesCero(int largo, int ancho, float *matriz[ancho]){
    for(int i=0; i<largo; i++){
        for(int j=0; j<ancho; j++){
            matriz[i][j]=0;
        }
    }
}

float ecuacionesError(int largo, int ancho, float *matrizEntrenamiento[ancho], float *matrizRandom[ancho]){
    float error=0;
    for(int i=0; i<largo; i++){
        for(int j=0; j<ancho; j++){
          if(matrizEntrenamiento[i][j]!=0){
            matrizRandom[i][j]=(matrizEntrenamiento[i][j]-matrizRandom[i][j]);
            error=error+matrizRandom[i][j];
          }
          else{
            matrizRandom[i][j]=0;
          }
        }
    }
    if(error<0)
      error=sqrt(error*error);
    return error/(largo*ancho);
}

void ecuacionesCorregir(int largo, int ancho, int features,
  float *matriz1[features], float *matriz2[features],
  float *matrizError[ancho], float n){
    for (int i=0; i<largo; i++){
        for(int j=0; j<ancho; j++){
          if(matrizError[i][j]!=0){
            for(int z=0; z<features; z++)
              matriz1[i][z]=matriz1[i][z]+(matrizError[i][j]*n*matriz2[j][z]);
            }
          }
    }
}

/*
  Función StochasticGradientDescent que usa lo de arriba
*//*
void ecuacionesStochasticGradientDescent(int largo, int ancho, int features,
int maxEpocs,float *errores, float *matriz1[features], float *matriz2[features],
float *matriz3[ancho], float *matriz4[ancho]){
float error=1000;
float errorMax=100;
float n=0.01;
//PASO 1: Generar de forma aleatoria el contenido de nuestra  matriz
  ecuacionesRandom(largo, features, matriz1);

//PASO 2: Inicializar en cero toda la matriz a usar en el producto punto
  ecuacionesCero(largo, ancho, matriz3);

//PASO 3: Generar el producto punto entre matriz1 y matriz2 y guardarlo en
// la matriz3
  for(int i=0; i<maxEpocs||error<errorMax; i++){
    ecuacionesPP(largo, ancho, features, matriz1, matriz2, matriz3);

  //PASO 4: Obtenemos el error absoluto entre matriz4 y matriz3 (entrenamiento)
    error=ecuacionesError(largo, ancho, matriz4, matriz3);
    errores[i]=error;

  //PASO 5: Hacemos la actualización de matriz1 y matriz2
    ecuacionesCorregir(largo, ancho, features, matriz1, matriz2, matriz3, n);
    ecuacionesCorregir(largo, ancho, features, matriz2, matriz1, matriz2, n/10);
  }


<<<<<<< HEAD:RepositorioModeloRecomendaciones/Codigo/ProyectoFinal/ecuaciones.c
}*/
=======
}

>>>>>>> 7f7056e9fdf306f689e84f5f7d1a7d218904119a:RepositorioModeloRecomendaciones/Codigo/ecuaciones.c
