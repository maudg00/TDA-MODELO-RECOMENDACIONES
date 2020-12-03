//
//  usuarios.h
//
//
//  Created by Equipo 2 - 01/dic/2020
//

#ifndef usuarios_h
#define usuarios_h

/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include <stdio.h>
#include <strings.h>
#include <string.h>
/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/



/* Set EXTERN macro: */

#ifndef usuarios_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif
#include <mysql.h>

/* Global variables declarations. */
//
//
EXTERN int usuariosloginUsuario(MYSQL* con, int *idUsuario, char * usuario);
EXTERN int usuariosRegistrarUsuario(MYSQL* con);
EXTERN void usuariosAgregarPelicula(char * usuario, char * contrasena);
EXTERN void usuariosAgregarRecomendacion();
#undef usuarios_IMPORT
#undef EXTERN
#endif /* vista_h */