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

#include <string.h>
#include "mysql_modulo.h"
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


/* Global variables declarations. */
//
//
EXTERN int usuariosLoginUsuario(MYSQL* con, char * usuario, char contrasena[]);
EXTERN int usuariosRegistrarUsuario(MYSQL* con, char usuario[], char contrasena[], char nombre[], char genero, int edad);
<<<<<<< HEAD:RepositorioModeloRecomendaciones/Codigo/ProyectoFinal/usuarios.h
EXTERN void usuariosAgregarCalificacion(MYSQL* con, int idUsuario, char nombrepelicula[100], int calificacion);

#undef usuarios_IMPORT
#undef EXTERN
#endif 
=======
EXTERN void usuariosAgregarPelicula(int idUsuario);
EXTERN void usuariosAgregarRecomendacion();

#undef usuarios_IMPORT
#undef EXTERN
#endif /* vista_h */
>>>>>>> 7f7056e9fdf306f689e84f5f7d1a7d218904119a:RepositorioModeloRecomendaciones/Codigo/usuarios.h
