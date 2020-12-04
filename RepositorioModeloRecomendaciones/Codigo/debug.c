#include "debug.h"

void debugImprimir(int largo, int ancho, float *matriz[ancho]){
  for(int i=0; i<largo; i++){
    for (int j=0; j<ancho; j++){
      printf("%.1f ", matriz[i][j]);
    }
    printf("\n");
  }
}
