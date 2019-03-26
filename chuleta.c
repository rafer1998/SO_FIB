PIPE CON NOMBRE:

	if ((mknod("MIPIPE", S_IFIFO|0666, 0) < 0) && (errno != EEXIST)){
		perror("Error en mknod");
		return;
	}
	
	if ((npd = open("MIPIPE", O_WRONLY)) < 0){
		perror("Error en open pipe");
		return -1;
	}

	if ((fd = open("MIPIPE", O_RDONLY)) < 0){
		perror("Error en open file");
		return -1;
	}
	close(npd);
	close(fd);

CREAR UN PROCESO HIJO

int pid = fork();
if (pid < 0) {
	perror("Error en la creacion del hijo")
}

	

PIPE SIN NOMBRE:
	int pf[2]; //crear la pipe
	if(pipe(pf) == -1) error_y_exit("a fallado la creacion del pipe\n",1); //crear la pipe
	write(pf[1],buf,strlen(buf)); //escribir en la pipe
	close(pf[1]); //cerrar canal 1 de la pipe
	
EJEMPLO DE MUTACION
	void muta_cat() {
		execlp("cat","cat",NULL);
		error_y_exit("a fallado la mutacion\n",1);
	}
	
EJEMPLO DE ESCRITURA
	char c, buf[256];
	int op1, op2;
	sprintf(buf, "%d %c %d\n", op1, c, op2);
	write(1, buf, len);

ATOI:

	int ---- = atoi("nuestro char");
	
ASIGNAR CANALES //DUP Y DUP2
	newfd = dup2(fd, newfd);  //FD CANAL ORIGINAL || NEW FD: CANAL NUEVO
	close(fd); //CIERRA CANAL FD
	newfd = dup(fd); //LO ASIGNA AL PRIMER CANAL DISPONIBLE
	
read:
	fd = open (canal que abro, O_RDONLY);
	if (fd < 0) {
		error_y_exit("Abriendo fichero");	
	}
	ret = read(canal, &queleo, sizeof(loqueleo))
	
write:
	write(canal, &queescribo, sizeof(loqueescribo))
	
LSEEK:
La posició de l/e es modifica manualment per l’usuari. 
Permet fer accessos directes a posicions concretes de fitxers de dades 
(o fitxers de dispositius que ofereixin accés seqüencial)
	● S’inicialitza a 0 a l’ open
	● S’ incrementa automàticament al fer read/write
	● El podem moure manualment amb la crida lseek
		■ nova_posicio=lseek(fd, desplaçament, relatiu_a)
			● SEEK_SET : posicio_l/e=desplaçament
			● SEEK_CUR: posicio_l/e=posicio_l/e+desplaçament
			● SEEK_END: posicio_l/e=file_size+desplaçament
			● “desplaçament” pot ser negatiu

MALLOC 

Ejemplo de uso de malloc, free y sizeof


#include <stdlib.h>

int* ptr;	/* puntero a enteros */
int* ptr2;	/* otro puntero */

...

/* reserva hueco para 300 enteros */
ptr = (int*)malloc ( 300*sizeof(int) );
...
  ptr[33] = 15;		/* trabaja con el área de memoria */

  ptr2 = ptr + 15;		/* asignación a otro puntero */

/* finalmente, libera la zona de memoria */
free(ptr);	


HARDLINK

Un enlace físico no es más que una etiqueta o un nuevo nombre asociado a un archivo. 
Es una forma de identificar el mismo contenido con diferentes nombres. 
Éste enlace no es una copia separada del archivo anterior sino un nombre diferente para exactamente el mismo contenido.

Para crear un enlace físico en Linux del archivo archivo.txt a nuevo_nombre.txt, ejecutamos:

$ ln archivo.txt nuevo_nombre.txt

El enlace aparecerá como otro archivo más en el directorio y apuntará al mismo contenido de archivo.txt. 
Cualquier cambio que se haga se reflejará de la misma manera tanto para archivo.txt como para nuevo_nombre.txt.

Un enlace se puede borrar usando el comando rm de la misma manera en que se borra un archivo, 
sin embargo el contenido del inodo no se eliminará mientras haya un enlace físico que le haga referencia. 
Esto puede tener varias ventajas, pero también puede complicar la tarea de seguimiento de los archivos. 
Un enlace físico tampoco puede usarse para hacer referencia a directorios o a archivos en otros equipos.


SOFTLINK

Un enlace simbólico también puede definirse como una etiqueta o un nuevo nombre asociado a un archivo pero a diferencia de los enlaces físicos, 
el enlace simbólico no contiene los datos del archivo, simplemente apunta al registro del sistema de archivos donde se encuentran los datos. 
Tiene mucha similitud a un acceso directo en Windows o un alias en OS X.

Para crear un enlace simbólico del archivo archivo.txt a nuevo_nombre.txt, ejecutamos:

$ ln -s archivo.txt nuevo_nombre.txt


Éste enlace también aparecerá como otro archivo más en el directorio y apuntará al mismo contenido de archivo.txt, 
reflejando todos los cambios que se hagan tanto para archivo.txt como para nuevo_nombre.txt.

Sobre un enlace simbólico también se pueden usar todos los comandos básicos de archivos (rm, mv, cp, etc). 
sin embargo cuando el archivo original es borrado o movido a una ubicación diferente el enlace dejará de funcionar y se dice que el enlace está roto.
