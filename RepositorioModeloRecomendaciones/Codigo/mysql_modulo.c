//
//  mysql_modulo.c
//
//
//  Created by Equipo 2 - 5/nov/2020
//



#include <stdlib.h>
#include "mysql_modulo.h"

char ** mysql_readquery(char query[], MYSQL* con, int *filas)
{
    int fila;
    int totalfilas=0;
    char **resultados=NULL;
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {
        finish_with_error(con);
    }
    MYSQL_ROW row;
    // Cuento el total de filas.
    while ((row = mysql_fetch_row(result)))
    {
        totalfilas=totalfilas+1;
        /*for(int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }*/
    }
    mysql_free_result(result);

    resultados=malloc(sizeof(char*)*totalfilas);
    int i;
    for(i=0; i<totalfilas;i++)
    {
        resultados[i]=malloc(sizeof(char)*100);
    }

    //Ahora obtengo resultados bien.
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
    MYSQL_RES *result2 = mysql_store_result(con);
    if (result2 == NULL)
    {
        finish_with_error(con);
    }
    num_fields=mysql_num_fields(result2);
    MYSQL_ROW row2;
    // Cuento el total de filas.
    i=0;
    while ((row2 = mysql_fetch_row(result2)))
    {
        char string[100];
        string[0]=0;
        for(int j = 0; j < num_fields; j++)
        {
            if(j==0)
            {
                strcat(string, row[j]);
            }
            else
            {
                strcat(string, ",");
                strcat(string, row[j]);
            }
        }
        strcpy(resultados[i], string);
        i+=1;
    }
    mysql_free_result(result2);
    mysql_close(con);
    *filas=totalfilas;
    return resultados;
}
MYSQL * mysql_startconnection(){
  MYSQL *mysql=NULL;;
  mysql_init(mysql);
  if(!mysql_real_connect(mysql, "localhost", "root", "", "tda", 0, NULL, 0))
    {
      printf("Error al conectarse a la base de datos %s\n", mysql_error(mysql));
      exit(1);
    }
    return mysql;
}
