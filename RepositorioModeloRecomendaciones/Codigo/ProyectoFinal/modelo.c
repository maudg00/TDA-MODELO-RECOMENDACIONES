//
//  modelo.c
//
//
//  Created by Equipo 2 - 01/dic/2020
//



/*
* System headers required by the following declarations
* (the implementation will import its specific dependencies):
*/

#include "modelo.h"
/*
* Application specific headers required by the following declarations
* (the implementation will import its specific dependencies):
*/



/* Global variables declarations. */
//
//

MYSQL* modeloIniciarConexion()
{
	return mysql_startconnection();
}


int modeloQueryNumeroFilas(char query[], MYSQL* con)
{
	int filas = 0;
	mysql_readquery(query, con, &filas);
	return filas;
}
void modeloAgregarPelicula( Peliculas pelicula, MYSQL* con)
{
	int filas = 0;
	char queryInsertar[500];
	sprintf(queryInsertar, "SELECT id_peliculas FROM peliculas WHERE titulo='%s'", pelicula.titulo);
	mysql_readquery(queryInsertar, con, &filas);
	if (filas != 0)
	{
		printf("ERROR: ya existe esta pelicula.\n");
		return;
	}
	printf("%d\n", pelicula.duracion);
	sprintf(queryInsertar, "INSERT INTO peliculas VALUES(NULL, '%s', %d, %d, %d, %d, %d, %d, %d, %d, '%s', '%s', '%s', %d, %d)", pelicula.titulo, pelicula.drama, pelicula.accion, pelicula.animacion, pelicula.terror, pelicula.comedia, pelicula.G, pelicula.PG13, pelicula.R, pelicula.director, pelicula.actor_principal, pelicula.casa_productora, pelicula.duracion, pelicula.anio_publicacion);
	int validacion = mysql_doquery(queryInsertar, con);
	if (validacion == 0)
	{
		printf("ERROR: No se pudo subir la pelicula.\n");
	}
	else printf("La pelicula se subio exitosamente.\n");
}
void modeloVerPeliculas(MYSQL* con)
{
	int filas = 0;
	char queryPeliculas[] = "SELECT * FROM peliculas";
	char** resultados;
	int columnas;
	resultados = mysql_readquery(queryPeliculas, con, &filas);
	if (filas == 0)
	{
		printf("No hay peliculas.\n");
	}
	if (resultados == NULL)
	{
		printf("ERROR OBTENIENDO PELICULAS.\n");
	}
	else
	{
		printf("");
		for (int i = 0; i < filas; i++)
		{
			columnas = (int)strlen(*(resultados + i));
			for (int j = 0; j < columnas;j++)
			{
				 printf("%c", *(*(resultados + i) + j));
			}
			printf("\n");
		}
		
	}
	
}