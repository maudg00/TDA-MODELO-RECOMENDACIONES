recomendaciones.exe: main.o mysql_modulo.o vista.o datashell.o ecuaciones.o usuarios.o
	gcc -o recomendaciones.exe main.o mysql_modulo.o vista.o datashell.o ecuaciones.o usuarios.o -lm
	
main.o: main.c
	gcc -c main.c 

mysql_modulo.o: mysql_modulo.c
	gcc -c mysql_modulo.c

vista.o: vista.c
	gcc -c vista.c
 
datashell.o: datashell.c
	gcc -c datashell.c

ecuaciones.o: ecuaciones.c
	gcc -c ecuaciones.c
	
usuarios.o: usuarios.c
	gcc -c usuarios.c
limpia:
	rm *.o