#include "funciones.h"

struct contacto
{
  char nombre[80];
  float promedio;
  int boleta;
  int eliminado;
};

int main (void)
{
  int opcion=0;
  int numero_contactos=0;
  int x=0;
  struct contacto agenda[1000];
  FILE *fp=0;
      numero_contactos = rellenar(agenda);
      while(opcion!=4)
           {
            x=0;
            while(x <= numero_contactos)
            {  
             ordenar_agenda(agenda, numero_contactos);
             x++;
            }
            opcion=mostrar_menu();
            switch(opcion)
                   {
                     case 1: 
                     numero_contactos = agregar_contacto(agenda, numero_contactos);//mando a llamar la funcion que agrega contactos
                     break;
                     case 2: 
                     numero_contactos = eliminar_registro(agenda, numero_contactos);
                     break;
                     case 3:
                     mostrar_agenda(agenda, numero_contactos);//muestro la agenda 
                     break;
                     case 4:printf("Adios \n");
                     break;
                     default: printf("Ingresa un numero \n");//Por si no ingresa un numero el usuaro le mando que lo meta >:v
                     break;
                   }
 }
 return 0;
}
