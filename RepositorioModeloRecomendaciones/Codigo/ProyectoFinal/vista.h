
//
//  vista.h
//
//
//  Created by Equipo 2 - 01/dic/2020
//

#ifndef vista_h
#define vista_h

/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include <stdio.h>
#include "structs.h"
#include <string.h>
/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/



/* Set EXTERN macro: */

#ifndef vista_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif


/* Global variables declarations. */
//
//
/*Prototipos de funciones*/
EXTERN char vistaMenuLoginRegistro();
/*
    La función vistaMenuLoginRegistro te lleva a un menu donde tienes dos opciones -> Hacer login con una cuenta
    ya registrada en la base de datos o registrar una nueva cuenta a la misma
    @params
    @return
*/
EXTERN void vistaLogin(char * usuario, char * contrasena);
/*
    La función vistaLogin te lleva a un menú donde te pide tu usuario y contraseña para posteriormente
    verificarlos en la base de datos
    @params char * usuario, char * contrasena
    @return
*/
EXTERN void vistaRegistro(char* usuario, char* contrasena, char* nombre, char* genero, int* edad);
/*
    La función vistRegistro te lleva a un menú interactivo para poder obtener la información del nuevo usuario
    (y posteriormente agregarla a la base de datos, por lo que la información tiene que estar limpia)
    @params char* usuario, char* contrasena, char* nombre, char* genero, int* edad
    @return
*/
EXTERN char vistaMenu(char *usuario);
/*
    La función vistMenu despliega el menu principal de la plataforma
    @params char *usuario
    @return
*/
EXTERN void vistaContinuar();
/*
    La función vistaContinuar sirve para que el usuario tenga que presionas la tecla enter para continuar
    @params
    @return
*/
EXTERN void vistaAgregarPelicula(Peliculas *peliNueva);
/*
    La función vistaAgregarPelicula te lleva a un menu donde te pide una película nueva con todos sus parámetros
    correspondientes (dados por la estructura de Películas)
    @params Peliculas *peliNueva
    @return
*/
EXTERN void vistaAgregarCalificacion(char *nombrePelicula, int *calificacion);
/*
    La función vistAgregarCalificacion te lleva a un menú en donde te pide el nombre de la película y su calificación
    @params char *nombrePelicula, int *calificacion
    @return
*/
EXTERN void vistaGraficarError();
/*
    La función vistaGraficaError manda a llamar a funciones de pipes para que se grafique a través de GNUPlot
    @params
    @return
*/
#undef vista_IMPORT
#undef EXTERN
#endif
