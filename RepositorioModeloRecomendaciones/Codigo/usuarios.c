#include "usuarios.h"
#include "vista.h"
#include "mysql_modulo.h"
#define TRUE 1
#define FALSE 0

//Regresa el  Id del Usuario
int usuariosLoginUsuario(MYSQL* con, char * usuario, char contrasena[])
{
    char queryLogin[150];
    int validarLogin=FALSE;
    char cont;
    int filas=0, idUsuario = 0;
    
    sprintf(queryLogin, "SELECT id_usuario FROM usuarios WHERE (username= '%s' AND password= '%s')", usuario, contrasena);
    mysql_readquery(queryLogin, con, &filas);
    
	if(filas==0)
    {
    	printf("ERROR: esta combinacion de usuario/contrasena no existe.\n");
        rewind(stdin);
        return FALSE;
    }
    
    sscanf(resultados[0],"%d", &idUsuario);
    rewind(stdin);
    return idUsuario;

}

int usuariosRegistrarUsuario(MYSQL* con, char usuario[], char contrasena[], char nombre[], char genero, int edad)
{
    char queryRegistro[150];
    int validarRegistro=FALSE;
    int filas = 0;
    
    //Validar que no exista el usuario.
    sprintf(queryRegistro, "SELECT id_usuario FROM usuarios WHERE (username= '%s')", usuario);
    mysql_readquery(queryRegistro, con, &filas);
    
    if(filas!=0)
    {
    	printf("ERROR: este usuario ya existe.\n");
        return FALSE;
    }
    
    sprintf(queryRegistro, "INSERT INTO usuarios VALUES (NULL, '%s', '%s', '%s', %d, '%c')", usuario, contrasena, nombre, edad, genero);

    if(!mysql_doquery(queryRegistro, con))
    {
        printf("ERROR: no se pudo registrar el usuario.\n");
        return FALSE;
    }
    
    return TRUE;
}

void usuariosAgregarPelicula(int idUsuario)
{
    char nombrePelicula[50], queryInsertar[150];

}
void usuariosAgregarRecomendacion()
{
	printf("Agregar Recomendacion\n");
}
