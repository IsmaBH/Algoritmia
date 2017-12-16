#include "funciones.h"

struct contacto//creo la funcion de estruc 
{
  char nombre[80];
  float promedio;
  int boleta;
  int eliminado;
};

int mostrar_menu(void)//solo printfs que muestran el menu y ya
    {
    	int opcion =0;
    	printf("1) Capturar registro \n");
    	printf("2) Eliminar registro \n");
    	printf("3) Ver registro \n");
    	printf("4) Salir \n");
    	scanf("%d",&opcion);//escaneo la opcion que eligio el usuario
    	return opcion;//regreso la opcion
    }

int rellenar (struct contacto *agenda)//esta funcion llena la agenda a partir de un archivo txt
    {
      FILE *fp=0;
      fp = fopen ("datos.csv","r");//abro la direccion del archivo en modo "r"  que es reading
      int i=0;
      int coma;
      int numero_contactos=0;
      while(!feof(fp))//mientras el archivo tena algo, sigo revisandolo
      	    {
             fscanf(fp,"%f, ",&(agenda+i)->promedio);
             fscanf(fp,"%s, ",(agenda+i)->nombre);//La coma la incluye a la cadena
             coma = strlen((agenda+i)->nombre);
             coma = coma-1;
             *((agenda+i)->nombre+coma) = '\0'; 
             fscanf(fp,"%d\n",&(agenda+i)->boleta);
             (agenda+i)->eliminado = 0;
             i++;
      	    }
      i=i-1;
      numero_contactos = (i);
      fclose(fp);
      return numero_contactos;//regreso el total contado, que en este caso se llama numero_contactos
    }

void mostrar_agenda(struct contacto *agenda, int numero_contactos)// una funcion que muestra los contactos 
{
 int i=0;
 for(i=0; i <= numero_contactos; i++)
    {
     printf("%f ",(agenda+i)->promedio);
     printf("%s ",(agenda+i)->nombre);
     printf("%d \n",(agenda+i)->boleta);
    }
}

int agregar_contacto (struct contacto *agenda, int numero_contactos)//Funcion para nuevos contactos
{
    int i=0;
    i = numero_contactos;
    FILE *fp=0;
    fp = fopen("datos.csv","a");// Ojo al dato, abro el archivo en modo "a", que es para escribir hasta la parte inferior del mismo
	char nombre[80];
	float promedio=0.0;
        int boleta;
        int boleta2;
        int x=0;
	printf("Dame nombre \n");
	scanf("%s",nombre);
	printf("Dame boleta \n");
	scanf("%d",&boleta);
	while(x < numero_contactos)
      	{
       	boleta2 = (agenda+x)->boleta;
       	x++;
       	if(boleta == boleta2)
       	 {
      	  printf("Ingresa otro numero de boleta \n");
 	  scanf("%d",&boleta);
 	 }
 	}
	
	printf("Dame promedio \n");
	scanf("%f",&promedio);
	while(promedio < 0.0 || promedio > 10.0)
	{
	 printf("Dame promedio \n");
         scanf("%f",&promedio);
        }
       
        strcpy( (agenda+i)->nombre, nombre);
        
        (agenda+i)->promedio = promedio;
        (agenda+i)->boleta = boleta;
        (agenda+i)->eliminado = 0;
        fprintf(fp,"%f",promedio);
	fprintf(fp,", ");
	fprintf(fp,"%s",nombre);
	fprintf(fp,", ");
        fprintf(fp,"%d",boleta);
        fprintf(fp," \n");
        
	fclose(fp);
	numero_contactos++;
	return numero_contactos;
}

int ordenar_agenda (struct contacto *agenda, int numero_contactos)
{
int x=0;
int f=1;
int buffer=0;
float promedio1=0.0f;
float promedio2=0.0f;
 while(x < numero_contactos)
 {
  promedio1 = (agenda+x)->promedio;  
  promedio2 = (agenda+f)->promedio;
  if(promedio1 <= promedio2)
    {
     ordenar_contacto(agenda, f, x);
    }
  x++;
  f++;
 }
 buffer = sobreescribir_agenda(agenda, numero_contactos);//Mando a llamar la funcion que "guarda" los cambios realizados en el documento
}

int sobreescribir_agenda (struct contacto *agenda, int numero_contactos)//Funcion que "guarda" los cambios
{
 int i=0;
 FILE *fp = fopen("datos.csv", "w");//Mando a abrir el erchivo en modo "w" que es write, para escribir desde el inicio
 fclose(fp);
 remove("davos.csv");//Borro el archivo
 fp = fopen("datos.csv","w");//vuelvo a crear el archivo y comienzo a llenarlo con los datos ya en orden
 numero_contactos++;
 while(i < numero_contactos)// mientras "i", sea menor que el numero de contactos, sigo aumentando
          {
          if((agenda+i)->eliminado != 1)
 	  {
 	  	fprintf(fp,"%f, ",(agenda+i)->promedio);//Hago lo mismo que en la funcion agregar nuevo contacto
 	  	//fprintf(fp,", ");
 	        fprintf(fp,"%s, ",(agenda+i)->nombre);
      		//fprintf(fp,", ");
 	    	fprintf(fp,"%d\n",(agenda+i)->boleta);
      		//fprintf(fp,"\n");
        	}
      		i++;
 	  }
 fclose(fp);
 return 0;
}

int ordenar_contacto (struct contacto *agenda, int f, int x)//mando a llamar la funcion que hace el swap
{
 char cadena_temporal[200];
 int temporal=0;
 float temp=0.0f;
 int i=0;
 i=x;
 //struct contacto temporal;//Declaro un temporal de tipo struct  
 
  strcpy(cadena_temporal, (agenda+i)->nombre);
  strcpy((agenda+i)->nombre, (agenda+f)->nombre);
  strcpy((agenda+f)->nombre, cadena_temporal);
  
  temporal = (agenda+i)->boleta;
  (agenda+i)->boleta = (agenda+f)->boleta;
  (agenda+f)->boleta = temporal;
  
  temp = (agenda+i)->promedio;
  (agenda+i)->promedio = (agenda+f)->promedio;
  (agenda+f)->promedio = temp;
  
return 0;
}

int eliminar_registro(struct contacto *agenda, int numero_contactos)
{
 int boleta=0;
 int boleta2=0;
 int x=0;
 int buffer=0;
 int encontrado = 0;
 printf("Ingresa el numero de boleta \n");
 scanf("%d",&boleta);
 while(x < numero_contactos)
      {
       boleta2 = (agenda+x)->boleta;
       if(boleta == boleta2)
         {
          (agenda+x)->eliminado = 1;
          encontrado = 1;
         }
       x++;
      }
 if(encontrado==1)
   {
    printf("Registro eliminado \n");
   }
 else
   {
    printf("Registro no encontrado \n");
   }
 buffer = sobreescribir_agenda(agenda, numero_contactos);
 numero_contactos--;
 buffer = rellenar(agenda);
 return numero_contactos;
}


