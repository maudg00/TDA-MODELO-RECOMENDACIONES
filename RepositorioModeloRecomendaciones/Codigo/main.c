#include "mysql_modulo.h"
#include <mysql/mysql.h>
#include "datashell.h"

int main()
{
    char **ResultadosQuery;
    int filas=0;
    MYSQL *con;
    con=mysql_startconnection();
    char query[]="SELECT u.id_usuario, u.edad, p.id_pelicula, p.titulo, u.genero, p.drama, p.accion, p.animacion, p.terror, p.comedia, p.G, p.PG13, p.R, p.actor_principal, p.casa_productora, p.duracion, p.anio_publicacion,  c.calificacion FROM usuarios u LEFT JOIN calificacion_peliculas c USING (id_usuario) LEFT JOIN peliculas p ON (p.id_peliculas=c.id_pelicula)";
    ResultadosQuery=mysql_readquery(query, con, &filas);
    datashell_getData(ResultadosQuery, filas);
}
