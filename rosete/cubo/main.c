#include "funciones.h"

struct color
{
	char *colores;
};

int main (void)
{
	struct color cara1[9];
	struct color cara2[9];
    struct color cara3[9];
	struct color cara4[9];
	struct color cara5[9];
	struct color cara6[9];
	colorear(cara1,cara2,cara3,cara4,cara5,cara6);
    dibujar_cubo(cara1,cara2,cara3,cara4,cara5,cara6);
    int opcion=0;
    int opcion2=0;

    while (opcion != 7)
    	  {
    	  	printf("Bienvenido al menu elige una opcion \n");
    	  	printf("1) giar columna izquierda  \n");
    	  	printf("2) giar columna central  \n");
    	  	printf("3) giar columna derecha  \n");
    	  	printf("4) giar fila superior  \n");
    	  	printf("5) giar fila central \n");
    	  	printf("6) giar fila inferior \n");
    	  	printf("7) Salir \n");
    	  	scanf("%d",&opcion);
    	    if(opcion != 7)
    	    {
    	    printf("1) Giro horario\n");
    	    printf("2) Giro antihorario\n");
    	    scanf("%d",&opcion2);
    	    if(opcion2 == 1)
    	    {
    	  	girar_horario(opcion,cara1,cara2,cara3,cara4,cara5,cara6);
    	  	}
    	  	if(opcion2 == 2)
    	  	{
    	  	girar_horario(opcion,cara1,cara2,cara3,cara4,cara5,cara6);
    	  	girar_horario(opcion,cara1,cara2,cara3,cara4,cara5,cara6);
    	  	girar_horario(opcion,cara1,cara2,cara3,cara4,cara5,cara6);
    	  	}
    	    }
    	  	dibujar_cubo(cara1,cara2,cara3,cara4,cara5,cara6);
       	  }
 return 0;
}