//
//  ecuaciones.h
//  TDA
//
//  Created by Equipo 2 on 29/11/20.
//

#ifndef ecuaciones_h
#define ecuaciones_h

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

extern void ecuacionesRandom(int largo, int ancho, float *matriz[ancho]);
/*
    Asigna valores aleatorios entre 0 y 1 a toda la matriz.

    @params int largo, int ancho, float **matrix
    @return

 */

extern void ecuacionesPP(int largo, int ancho, int features, float *matriz1[features],
  float *matriz2[features], float *matrizFinal[ancho]);
/*
    Hace el producto punto entre matriz1 y matriz2 y asigna los valores a la matrizFinal

    @params int largo, int ancho, float **matriz1, float **matriz2, float **matrizFinal
    @return

 */

extern void ecuacionesCero(int largo, int ancho, float *matriz[ancho]);
/*
    Hace 0 todos los valores dentro de la matriz

    @params float **matriz
    @return

 */

extern float ecuacionesError(int largo, int ancho, float *matrizEntrenamiento[ancho], float *matrizRandom[ancho]);
/*
    Asigna a la matrizRandom el error entre las otras 2 matrices

    @params int largo, int ancho, float **matrizEntrenamiento, float **matrizRandom
    @return error

 */

extern void ecuacionesCorregir(int largo, int ancho, int features,
  float *matriz1[features], float *matriz2[features],
  float *matrizError[ancho], float n);
/*
    Actualizar matriz1 con stochastic gradient descent

    @params int largo, int ancho, float **matriz1, float **matriz2, float **matrizError
    @return

 */

#endif /* ecuaciones_h */
