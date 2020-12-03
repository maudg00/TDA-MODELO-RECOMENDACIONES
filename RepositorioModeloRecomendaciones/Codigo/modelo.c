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
	MYSQL* con;
	con=mysql_startconnection();
	return con;
}
int modeloQueryNumeroFilas()
{
	int filas = 0;

	return filas;
}

