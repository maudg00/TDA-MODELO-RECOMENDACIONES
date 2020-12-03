#include "mysql_modulo.h"
#include <string.h>
char ** mysql_readquery(char query[], MYSQL* con, int *filas)
{
    int totalfilas=0;
    char **resultados=NULL;
    if (mysql_query(con, query))
    {
        printf("ERROR QUERY: %s", query);
        return NULL;
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {
        *filas=0;
        printf("QUERY VACIO.\n");
        return NULL;
    }
    MYSQL_ROW row;
    int num_fields;
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
        printf("ERROR QUERY");
        return NULL;
    }
    MYSQL_RES *result2 = mysql_store_result(con);
    if (result2 == NULL)
    {
        *filas=0;
        printf("QUERY VACIO.\n");
        return NULL;
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
                strcat(string, row2[j]);
            }
            else
            {
                strcat(string, ",");
                strcat(string, row2[j]);
            }
        }
        strcpy(resultados[i], string);
        i+=1;
    }
    mysql_free_result(result2);
    *filas=totalfilas;
    return resultados;
}
MYSQL * mysql_startconnection(){
   MYSQL mysql;
  mysql_init(&mysql);
  mysql_real_connect(&mysql, "localhost", "root", "", "tda", 3306, NULL, 0);

  return &mysql;
}
int mysql_doquery(char query[], MYSQL *con){
if (mysql_query(con, query))
    {
    printf("ERROR QUERY");
        return 0;
    }
	
	return 1;		
}