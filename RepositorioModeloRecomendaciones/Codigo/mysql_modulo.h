//
//  mysql_modulo.h
//
//
//  Created by Equipo 2 - 5/nov/2020
//

#ifndef mysql_modulo_h
#define mysql_modulo_h

/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include <stdio.h>
#include <mysql.h>

/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/


/* Constants declarations. */

/* Set EXTERN macro: */

#ifndef mysql_modulo_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif


/* Global variables declarations. */
//
//

EXTERN char ** mysql_readquery(char query[], MYSQL con, int* filas);
EXTERN MYSQL *con mysql_startconnection();
EXTERN int  mysql_doquery(char query[], MYSQL con);





#undef mysql_modulo_IMPORT
#undef EXTERN
#endif /* mysql_modulo_h */
