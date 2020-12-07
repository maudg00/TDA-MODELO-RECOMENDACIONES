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
/* Prototipos de funciones*/
EXTERN int usuariosLoginUsuario(MYSQL* con, char * usuario, char contrasena[]);
/*
    La función de usuariosLoginUsuario regresa el id del usuario correspondiente de la Base de Datos
    @params MYSQL* con, char * usuario, char contrasena[]
    @return
*/
EXTERN int usuariosRegistrarUsuario(MYSQL* con, char usuario[], char contrasena[], char nombre[], char genero, int edad);
/*
    La función de usuariosRegistrarUsuario permite ingresar un usuario a la base de datos MySQL con
    los datos recibidos.
    @params MYSQL* con, char usuario[], char contrasena[], char nombre[], char genero, int edad
    @return
*/
EXTERN void usuariosAgregarCalificacion(MYSQL* con, int idUsuario, char nombrepelicula[100], int calificacion);
/*
    La función de usuariosAgregarCalificacion permite agregar calificaciones a las películas dentro de la base de datos.
    
    @params MYSQL* con, int idUsuario, char nombrepelicula[100], int calificacion
    @return
*/

EXTERN void usuariosAgregarPelicula(int idUsuario);
/*
    La función de usuariosAgregarPelicula permite agregar películas dentro de la base de datos.
    
    @params int idUsuario
    @return
*/
EXTERN void usuariosAgregarRecomendacion();
/*
    La función de usuariosAgregarRecomendacion permite agregar recomendaciones.
    
    @params
    @return
*/

#undef usuarios_IMPORT
#undef EXTERN
#endif /* vista_h */
