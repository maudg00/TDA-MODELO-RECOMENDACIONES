typedef struct _data{
	int id_usuario;
	short int edad;
	int id_pelicula;
	char titulo[60];
	short int drama;
	short int accion;
	short int animacion;
	short int terror;
	short int comedia;
	short int G;
	short int PG13;
	short int R;
	
	char actor_principal[60];
	char casa_productora[60];
	short int duracion;
	short int anio_publicacion;
	
	short int calificacion;

}DATA;

//Checar que Mau si haya puesto el id de la pelicula y el titulo en el indice correcto

DATA * dataShell(char **data, int SIZE){
	DATA *d;
	d = malloc(sizeof(DATA) * SIZE);
	for(i=0; i<SIZE; i++){
		sscanf(data[i], "%i,%hi,%i,%[^,],%hi,%hi,%hi,%hi,%hi,%hi,%hi,%hi,%[^,],%[^,],%hi,%hi,%[^,]", 
			&d[i].id_usuario,
			&d[i].edad,
			&d[i].id_pelicula,
			 d[i].titulo,
			&d[i].drama,
			&d[i].accion,
			&d[i].animacion,
			&d[i].terror,
			&d[i].comedia,
			&d[i].G,
			&d[i].PG13,
			&d[i].R,
			 d[i].actor_principal,
			 d[i].casa_productora,
			&d[i].duracion,
			&d[i].anio_publicacion,
			&d[i].calificacion);
	}
	
	return d;
}
