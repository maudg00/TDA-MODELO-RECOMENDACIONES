//
//  modelo.h
//
//
//  Created by Equipo 2 - 03/dic/2020
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
#include "structs.h"
#include "cesarin.h"
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

/*
 *
 * Funcion puente entre el contenedor y el modulo SQL
 *
 * @params
 *      void
 
 * @returns
        MYSQL * conexion
*/
EXTERN void modeloIniciarConexion(MYSQL * con);

/*
 *
 * Funcion que realiza el query indicado y regresa el numero de filas
 * resultante
 *
 * @params
 *      query (char *)
        	Query SQL a realizar
        	
 		con (MYSQL *):
            Conexion a la base de datos

 * @returns
        int filas
*/
EXTERN int modeloQueryNumeroFilas(char query[], MYSQL* con);

/*
 *
 * Funcion que realiza el query indicado y regresa el numero de filas
 * resultante
 *
 * @params
 *      peliculas (Peliculas)
        	Instancia de la estructura Pelicula para guardar la informacion de esta
        	
 		con (MYSQL *):
            Conexion a la base de datos

 * @returns
        void
*/
EXTERN void modeloAgregarPelicula(Peliculas pelicula, MYSQL* con);

/*
 *
 * Funcion que nos muestra la informacion de todas las peliculas 
 * registradas
 *
 * @params
 *      con (MYSQL *):
            Conexion a la base de datos

 * @returns
        void
*/
EXTERN void modeloVerPeliculas(MYSQL* con);
/*
 *
 * Funcion que se encarga de obtener toda la información necesaria para obtener las aficiones de un usuario respectivamente
 * Se llama a función de cesarin.h con los datos listos para ser procesados. Para más info de la función de ecuaciones, revisar
 * su header.
 *
 * @params
 *      MYSQL *con, int idUsuario, float *aficiones, int to_file

 * @returns
        void
*/
EXTERN void modeloObtenerVectorAficiones(MYSQL *con, int idUsuario, float *aficiones, int to_file);
/*
 *
 * Funcion que se encarga de obtener toda la información necesaria para obtener las películas que le gusten a un usuario respectivamente
 * Se llama a funciónd e cesarin.h con los datos listos para ser procesados. Para más info de la función de ecuaciones, revisar
 * su header.
 *
 * @params
 *      MYSQL *con, int idUsuario,float *aficiones

 * @returns
        void
*/
EXTERN float * modeloObtenerPeliculasRecomendadas(MYSQL *con, int idUsuario,float *aficiones);
/*
 *
 * Funcion que se encarga de obtener toda la información necesaria para obtener los amigos que le gusten a un usuario respectivamente
 * Se llama a función de cesarin.h en un ciclo (de tantos amigos que hay) con los datos listos para ser procesados. Para más info de la función de ecuaciones, revisar
 * su header.
 * A parte de llamar a eGD, se tiene que considerar que se generar una nueva tabla con las afinidades de los usuarios diferentes a idUsuario para que
 * se pueda generar el PP entre ambos
 *
 * @params
 *      MYSQL *con, int idUsuario,float *user_aficiones

 * @returns
        void
*/
EXTERN void modeloRecomendarAmigos(MYSQL *con, int idUsuario,float *user_aficiones);


#undef modelo_IMPORT
#undef EXTERN
#endif /* modelo_h */
