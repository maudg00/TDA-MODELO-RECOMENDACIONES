//
//  modelo.h
//
//
//  Created by Equipo 2 - 01/dic/2020
//

#ifndef modelo_h
#define modelo_h

/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include <stdio.h>
#include <mysql.h>
#include "mysql_modulo.h"
#include <string.h>
/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/



/* Set EXTERN macro: */

#ifndef modelo_IMPORT
#define EXTERN
#else
#define EXTERN extern
#endif


/* Global variables declarations. */
//
//
EXTERN MYSQL * modeloIniciarConexion();
EXTERN int modeloQueryNumeroFilas();
#undef modelo_IMPORT
#undef EXTERN
#endif /* modelo_h */