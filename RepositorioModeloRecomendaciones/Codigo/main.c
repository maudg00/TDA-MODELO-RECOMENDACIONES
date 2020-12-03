#include <stdlib.h>
#include "modelo.h"

#include <stdio.h>
//#include "datashell.h"
#include "vista.h"
#include "usuarios.h"

/* Constants declarations. */
#define TRUE 1
#define FALSE 0

void loginYRegistro(MYSQL *con, int *idUsuario, char usuario[27]);
void menuPrincipal(MYSQL *con, int idUsuario, char usuario[27]);

int main()
{
    MYSQL *con;
    con = modeloIniciarConexion();
    int idUsuario = 0;
    char usuario[27];
    //char queryABT[]="SELECT u.id_usuario, u.edad, p.id_pelicula, p.titulo, u.genero, p.drama, p.accion, p.animacion, p.terror, p.comedia, p.G, p.PG13, p.R, p.actor_principal, p.casa_productora, p.duracion, p.anio_publicacion,  c.calificacion FROM usuarios u LEFT JOIN calificacion_peliculas c USING (id_usuario) LEFT JOIN peliculas p ON (p.id_peliculas=c.id_pelicula)";

   loginYRegistro(con, &idUsuario, usuario);
   menuPrincipal(con, &idUsuario, usuario);
   
    //while
    
    
    mysql_close(con);
    
    /*ResultadosQuery=mysql_readquery(query, con, &filas);
    datashell_getData(ResultadosQuery, filas);*/
}

void loginYRegistro(MYSQL *con, int *idUsuario, char usuario[27]){
	char contasena[27], nombre[50], genero;
	int validar, edad;
	char opcionMenu;
	
	while(validar==FALSE)
    {
        opcionMenu=vistaMenuLoginRegistro();
        system("cls");
        switch (opcionMenu)
        {
        case '1':
            do
            {
                vistaLogin(usuario, contrasena);
                idUsuario = usuariosLoginUsuario(con, usuario, contrasena);
            } while (idUsuario == FALSE);
            
            validar=TRUE;
        break;
        case '2':
            do
            {
            	vistaRegistro(usuario, contrasena, nombre, &genero, &edad);
                validar = usuariosRegistrarUsuario(usuario, contrasena, nombre, &genero, &edad);
            } while (validar == FALSE);
        break;
        default:
            printf("ERROR: opcion invalida.\n");
        break;
        }
        vistaContinuar();
    }	
}

void menuPrincipal(MYSQL *con, int idUsuario, char usuario[27]){
	char opcionMenu;
	
	do
    {
        system("cls");
        opcionMenu=vistaMenu(usuario);
        switch(opcionMenu)
        {
            case '1':
                printf("%d\n", idUsuario);
                printf("Agregar pelicula.\n");
                usuariosAgregarPelicula(idUsuario);
            break;
            case '2':
                printf("Calificar Pelicula.\n");
            break;
            case '3':
                printf("Ver Recomendaciones P.\n");
            break;
            case '4':
                printf("Ver Recomendaciones A.\n");
            break;
            case '5':
                printf("Salir.\n");
            break;
            default:
                printf("ERROR: opcion equivocada.\n"); 
            break;
        }
        vistaContinuar();
    } while (opcionMenu!='5');
}

