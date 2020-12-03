#include "usuarios.h"
int usuariosloginUsuario(MYSQL* con, int *idUsuario, char * usuario)
{
    char queryLogin[150];
    int validarLogin=FALSE;
    char contrasena[27];
    char ** resultados;
    int filas=0;
    while(validarLogin==FALSE)
    {
        vistaLogin(usuario, contrasena);
        sprintf(queryLogin, "SELECT id_usuario FROM usuarios WHERE (username= '%s' AND password= '%s')", usuario, contrasena);
        resultados= mysql_readquery(queryLogin, con, &filas);
        if(filas!=0)
        {
            validarLogin=TRUE;
        }
        else
        {
            printf("ERROR: esta combinacion de usuario/contrasena no existe.\n");

        }
    }
    sscanf(resultados[0],"%d", idUsuario);
    fflush(stdin);
}
int usuariosRegistrarUsuario(MYSQL* con)
{
    char usuario[27],contrasena[27], genero, nombre[50];
    int edad;
    char queryRegistro[150];
    int validarRegistro=FALSE;
    int filas;
    char **resultados;
    while(validarRegistro==FALSE)
    {
        filas=0;
        vistaRegistro(usuario, contrasena, nombre, &genero, &edad);
        //Validar que no exista el usuario.
        sprintf(queryRegistro, "SELECT id_usuario FROM usuarios WHERE (username= '%s')", usuario);
        resultados= mysql_readquery(queryRegistro, con, &filas);
        if(filas!=0)
        {
            validarRegistro=FALSE;
            printf("ERROR: este usuario ya existe.\n");
        }
        else
        {
            sprintf(queryRegistro, "INSERT INTO usuarios (username, password, nombre, edad, genero) VALUES ('%s', '%s', '%s', %d, '%c')", usuario, contrasena, nombre, edad, genero);
            validarRegistro=mysql_doquery(queryRegistro, con);
            if(validarRegistro==FALSE)
            {
                printf("ERROR: no se pudo registrar el usuario.\n");
            }
        }
    }
}
void usuariosAgregarPelicula(char * usuario, char * contrasena)
{

}
void usuariosAgregarRecomendacion()
{

}