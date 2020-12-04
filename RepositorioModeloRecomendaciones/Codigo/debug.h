//
//  debug.h
//  TDA
//
//  Created by Equipo 2 on 29/11/20.
//

#ifndef debug_h
#define debug_h

#include <stdio.h>
#include <stdlib.h>

/* Set EXTERN macro: */

#ifndef memoria_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif

EXTERN void debugImprimir(int largo, int ancho, float *matriz[ancho]);
#endif /* debug_h */
