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
	mysql_readquery(query, con, &filas)
	return filas;
}

