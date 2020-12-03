#include "mysql_modulo.h"
#include <mysqlx/xapi.h>
//#include "datashell.h"
#include "vista.h"
/* Constants declarations. */
#define TRUE 1
#define FALSE 0
int registrarUsuario(MYSQL* con);
int loginUsuario(MYSQL* con, int *idUsuario, char * usuario);
int main()
{
    char **ResultadosQuery;
    int filas=0;
    MYSQL *con;
    con=mysql_startconnection();
    //char queryABT[]="SELECT u.id_usuario, u.edad, p.id_pelicula, p.titulo, u.genero, p.drama, p.accion, p.animacion, p.terror, p.comedia, p.G, p.PG13, p.R, p.actor_principal, p.casa_productora, p.duracion, p.anio_publicacion,  c.calificacion FROM usuarios u LEFT JOIN calificacion_peliculas c USING (id_usuario) LEFT JOIN peliculas p ON (p.id_peliculas=c.id_pelicula)";
    char usuario[27];
    int validar=FALSE;
    int idUsuario;
    char opcionMenu;
    while(validar==FALSE)
    {
        opcionMenu=vistaMenuLoginRegistro();
        switch (opcionMenu)
        {
        case '1':
            loginUsuario(con, &idUsuario, usuario);
            validar=TRUE;
        break;
        case '2':
            registrarUsuario(con);
        default:
            printf("ERROR: opcion invalida.\n");
        break;
        }
    }
    /*ResultadosQuery=mysql_readquery(query, con, &filas);
    datashell_getData(ResultadosQuery, filas);*/
}
int registrarUsuario(MYSQL* con)
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
        sprintf(queryLogin, "SELECT id_usuario FROM usuarios WHERE (username= '%s')", usuario);
        resultados= mysql_readquery(queryLogin, con, &filas);
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
int loginUsuario(MYSQL* con, int *idUsuario, char * usuario)
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