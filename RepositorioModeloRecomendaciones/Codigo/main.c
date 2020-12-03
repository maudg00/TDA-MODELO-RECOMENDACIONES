
#include <stdlib.h>
#include "modelo.h"

#include <stdio.h>
//#include "datashell.h"
#include "vista.h"
#include "usuarios.h"

/* Constants declarations. */
#define TRUE 1
#define FALSE 0
int main()
{
    //char **ResultadosQuery;
    int filas=0;
    MYSQL *con;
    con = modeloIniciarConexion();
    //char queryABT[]="SELECT u.id_usuario, u.edad, p.id_pelicula, p.titulo, u.genero, p.drama, p.accion, p.animacion, p.terror, p.comedia, p.G, p.PG13, p.R, p.actor_principal, p.casa_productora, p.duracion, p.anio_publicacion,  c.calificacion FROM usuarios u LEFT JOIN calificacion_peliculas c USING (id_usuario) LEFT JOIN peliculas p ON (p.id_peliculas=c.id_pelicula)";
    char usuario[27];
    int validar=FALSE;
    int idUsuario;
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
                vistaLogin(usuario);
                validar = modeloQueryNumeroFilas();
                usuariosLoginUsuario(con, &idUsuario, usuario);
            } while (validar == FALSE);
            
            validar=TRUE;
        break;
        case '2':
            do
            {
                validar = modeloIsQueryEmpty();

            } while (validar == TRUE);
            usuariosRegistrarUsuario(con);
            rewind(stdin);
        default:
            printf("ERROR: opcion invalida.\n");
        break;
        }
        vistaContinuar();
    }
    rewind(stdin);
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
    mysql_close(con);
    
    /*ResultadosQuery=mysql_readquery(query, con, &filas);
    datashell_getData(ResultadosQuery, filas);*/
}

