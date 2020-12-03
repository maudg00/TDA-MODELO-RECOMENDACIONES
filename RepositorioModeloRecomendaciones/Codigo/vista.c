//
//  vista.c
//
//
//  Created by Equipo 2 - 01/dic/2020
//
/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/
#include "vista.h"
/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/


char vistaMenuLoginRegistro()
{
    char op;
    printf("Bienvenido a PelisChidas.c om!\n");
    printf("\t1.-Login.\n");
    printf("\t2.-Registrar.\n");
    printf("Selecciona tu opcion:\n");
    scanf("%c", &op);
    fflush(stdin);
    return op;
}

void vistaLogin(char * usuario, char * contrasena)
{
    printf("Inicia sesion en PelisChidas.c om!\n");
    printf("\tDame tu usuario: ");
    fgets(usuario, 25, stdin);
    usuario[(strlen(usuario)-1)]=0;
    fflush(stdin);
    printf("\n\tDame tu contrasena: ");
    fgets(contrasena, 25, stdin);
    contrasena[(strlen(contrasena)-1)]=0;
    fflush(stdin);
}
void vistaRegistro(char * usuario, char * contrasena, char *nombre, char *genero, int *edad)
{
    printf("Registrate a PelisChidas.c om!\n");
    printf("\tDame tu usuario: ");
    fgets(usuario, 25, stdin);
    usuario[(strlen(usuario)-1)]=0;
    fflush(stdin);
    printf("\n\tDame tu contrasena: ");
    fgets(contrasena, 25, stdin);
    contrasena[(strlen(contrasena)-1)]=0;
    fflush(stdin);
    printf("\n\tDame tu nombre: ");
    fgets(nombre, 50, stdin);
    nombre[(strlen(nombre)-1)]=0;
    fflush(stdin);
    *genero='y';
    while(*genero!='M' || *genero!='F' || *genero!='O')
    {
        printf("\n\tDame tu genero (M, F, O): ");
        scanf("%c", genero);
        fflush(stdin);
    }
    printf("\n\tDame tu edad: ");
    scanf("%d", edad);
    fflush(stdin);
}
char vistaMenu(char * usuario)
{
    char op;
    printf("Bienvenido %s !.\n", usuario);
    printf("\n\nMenu:\n");
    printf("\t1.- Agregar pelicula.\n");
    printf("\t2.- Calificar pelicula.\n");
    printf("\t3.- Ver recomendaciones pelicula.\n");
    printf("\t4.- Ver recomendaciones amigos.\n");
    printf("\t5.- Salir.\n");
    printf("Dame tu opcion: ");
    scanf("%c", &op);
    fflush(stdin);
}

