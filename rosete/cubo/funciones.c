#include "funciones.h"

struct color
{
	char *colores;
};

void colorear (struct color *cara1, struct color *cara2, struct color *cara3, struct color *cara4, struct color *cara5, struct color *cara6)
{
	int x=0;
	for(x=0; x < 9; x++)
	  {
       (cara1+x)->colores = "\033[1;30;35m";//morado
	  }
	for (x=0; x < 9; x++)
	{
	   (cara2+x)->colores = "\033[0;30;32m";//verde
	}
	for (x=0; x < 9; x++)
	{
	   (cara3+x)->colores = "\033[0;30;34m";//azul
	}
	for (x=0; x < 9; x++)
	{
	   (cara4+x)->colores = "\033[0;30;31m";//rojo
	}
	for (x=0; x < 9; x++)
	{
	   (cara5+x)->colores = "\033[0;30;37m";//blanco
	}
	for (x=0; x < 9; x++)
	{
	   (cara6+x)->colores = "\033[0;30;33m";//amarillo
	}
}

void dibujar_cubo (struct color *cara1, struct color *cara2, struct color *cara3, struct color *cara4, struct color *cara5, struct color *cara6)
{
const char *const n = "\033[0m";
printf("       %s______%s______%s______%s\n", (cara5+0)->colores, (cara5+3)->colores , (cara5+6)->colores, n);
printf("      %s/*****%s/*****%s/*****/%s|%s\n", (cara5+0)->colores, (cara5+3)->colores, (cara5+6)->colores, (cara2+6)->colores, n);
printf("     %s/_____%s/_____%s/_____/%s*|%s\n", (cara5+0)->colores, (cara5+3)->colores, (cara5+6)->colores, (cara2+6)->colores, n); 
printf("    %s/*****%s/*****%s/*****/%s|%s*|%s\n", (cara5+1)->colores, (cara5+4)->colores, (cara5+7)->colores, (cara2+3)->colores, (cara2+6)->colores, n);
printf("   %s/_____%s/_____%s/_____/%s*|%s*|%s\n", (cara5+1)->colores, (cara5+4)->colores, (cara5+7)->colores, (cara2+3)->colores, (cara2+6)->colores, n);
printf("  %s/*****%s/*****%s/*****/%s|%s*|%s/%s|%s\n", (cara5+2)->colores, (cara5+5)->colores, (cara5+8)->colores, (cara2+0)->colores, (cara2+3)->colores, (cara2+6)->colores, (cara2+7)->colores, n);
printf(" %s/_____%s/_____%s/_____/%s*|%s*/%s*|%s\n", (cara5+2)->colores, (cara5+5)->colores, (cara5+8)->colores, (cara2+0)->colores, (cara2+3)->colores, (cara2+7)->colores, n);
printf(" %s|*****%s|*****%s|*****|%s*|%s/%s|%s*|%s\n", (cara1+0)->colores, (cara1+3)->colores, (cara1+6)->colores, (cara2+0)->colores, (cara2+3)->colores, (cara2+7)->colores, (cara2+7)->colores, n);
printf(" %s|*****%s|*****%s|*****|%s*/%s*|%s/%s|%s\n", (cara1+0)->colores, (cara1+3)->colores, (cara1+6)->colores, (cara2+0)->colores, (cara2+4)->colores, (cara2+7)->colores, (cara2+8)->colores, n);
printf(" %s|_____%s|_____%s|_____|%s/%s|%s*/%s*|%s\n", (cara1+0)->colores, (cara1+3)->colores, (cara1+6)->colores, (cara2+0)->colores, (cara2+4)->colores, (cara2+4)->colores, (cara2+8)->colores, n);
printf(" %s|*****%s|*****%s|*****|%s*|%s/%s|%s*|%s\n", (cara1+1)->colores, (cara1+4)->colores, (cara1+7)->colores, (cara2+1)->colores, (cara2+4)->colores, (cara2+5)->colores, (cara2+8)->colores, n);
printf(" %s|*****%s|*****%s|*****|%s*/%s*|%s/%s\n", (cara1+1)->colores, (cara1+4)->colores, (cara1+7)->colores, (cara2+1)->colores, (cara2+5)->colores, (cara2+8)->colores, n);
printf(" %s|_____%s|_____%s|_____|%s/%s|%s*/%s\n", (cara1+1)->colores, (cara1+4)->colores, (cara1+7)->colores, (cara2+1)->colores, (cara2+2)->colores, (cara2+5)->colores, n);
printf(" %s|*****%s|*****%s|*****|%s*|%s/%s\n", (cara1+2)->colores, (cara1+5)->colores, (cara1+8)->colores, (cara2+2)->colores, (cara2+5)->colores, n);
printf(" %s|*****%s|*****%s|*****|%s*/%s\n", (cara1+2)->colores, (cara1+5)->colores, (cara1+8)->colores, (cara2+2)->colores, n);
printf(" %s|_____%s|_____%s|_____|%s/%s\n", (cara1+2)->colores, (cara1+5)->colores, (cara1+8)->colores, (cara2+2)->colores, n);
}

void columnas (int opcion, struct color *cara1, struct color *cara2, struct color *cara3, struct color *cara4, struct color *cara5, struct color *cara6)
{
  struct color temporal;
  switch(opcion)
  {
  case 1:
  temporal = *(cara1+0);
  *(cara1+0) = *(cara6+0);
  *(cara6+0) = *(cara3+0);
  *(cara3+0) = *(cara5+0);
  *(cara5+0) = temporal;

  temporal = *(cara1+1);
  *(cara1+1) = *(cara6+1);
  *(cara6+1) = *(cara3+1);
  *(cara3+1) = *(cara5+1);
  *(cara5+1) = temporal; 
 
  temporal = *(cara1+2);
  *(cara1+2) = *(cara6+2);
  *(cara6+2) = *(cara3+2);
  *(cara3+2) = *(cara5+2);
  *(cara5+2) = temporal; 
  break;
  case 2:
  temporal = *(cara1+3);
  *(cara1+3) = *(cara6+3);
  *(cara6+3) = *(cara3+3);
  *(cara3+3) = *(cara5+3);
  *(cara5+3) = temporal;

  temporal = *(cara1+4);
  *(cara1+4) = *(cara6+4);
  *(cara6+4) = *(cara3+4);
  *(cara3+4) = *(cara5+4);
  *(cara5+4) = temporal; 
 
  temporal = *(cara1+5);
  *(cara1+5) = *(cara6+5);
  *(cara6+5) = *(cara3+5);
  *(cara3+5) = *(cara5+5);
  *(cara5+5) = temporal; 
  break;
  case 3:
   temporal = *(cara1+6);
  *(cara1+6) = *(cara6+6);
  *(cara6+6) = *(cara3+6);
  *(cara3+6) = *(cara5+6);
  *(cara5+6) = temporal;

  temporal = *(cara1+7);
  *(cara1+7) = *(cara6+7);
  *(cara6+7) = *(cara3+7);
  *(cara3+7) = *(cara5+7);
  *(cara5+7) = temporal; 
 
  temporal = *(cara1+8);
  *(cara1+8) = *(cara6+8);
  *(cara6+8) = *(cara3+8);
  *(cara3+8) = *(cara5+8);
  *(cara5+8) = temporal; 
  break;
  default:printf("Nada\n");
  break;
  }
}


void filas (int opcion, struct color *cara1, struct color *cara2, struct color *cara3, struct color *cara4, struct color *cara5, struct color *cara6)
{
  struct color temporal;
  switch(opcion)
  {
  case 4:
  temporal = *(cara1+0);
  *(cara1+0) = *(cara2+0);
  *(cara2+0) = *(cara3+0);
  *(cara3+0) = *(cara4+0);
  *(cara4+0) = temporal;
  
  temporal = *(cara1+3);
  *(cara1+3) = *(cara2+3);
  *(cara2+3) = *(cara3+3);
  *(cara3+3) = *(cara4+3);
  *(cara4+3) = temporal;

  temporal = *(cara1+6);
  *(cara1+6) = *(cara2+6);
  *(cara2+6) = *(cara3+6);
  *(cara3+6) = *(cara4+6);
  *(cara4+6) = temporal;

  break;
  case 5:
  temporal = *(cara1+1);
  *(cara1+1) = *(cara2+1);
  *(cara2+1) = *(cara3+1);
  *(cara3+1) = *(cara4+1);
  *(cara4+1) = temporal;
  
  temporal = *(cara1+4);
  *(cara1+4) = *(cara2+4);
  *(cara2+4) = *(cara3+4);
  *(cara3+4) = *(cara4+4);
  *(cara4+4) = temporal;

  temporal = *(cara1+7);
  *(cara1+7) = *(cara2+7);
  *(cara2+7) = *(cara3+7);
  *(cara3+7) = *(cara4+7);
  *(cara4+7) = temporal;
  break;
  case 6:
  temporal = *(cara1+2);
  *(cara1+2) = *(cara2+2);
  *(cara2+2) = *(cara3+2);
  *(cara3+2) = *(cara4+2);
  *(cara4+2) = temporal;
  
  temporal = *(cara1+5);
  *(cara1+5) = *(cara2+5);
  *(cara2+5) = *(cara3+5);
  *(cara3+5) = *(cara4+5);
  *(cara4+5) = temporal;

  temporal = *(cara1+8);
  *(cara1+8) = *(cara2+8);
  *(cara2+8) = *(cara3+8);
  *(cara3+8) = *(cara4+8);
  *(cara4+8) = temporal;
  break;
  default: printf("Nada\n");
  break;
 }
}

void girar_horario (int opcion, struct color *cara1, struct color *cara2, struct color *cara3, struct color *cara4, struct color *cara5, struct color *cara6)
{
  if(opcion == 1 || opcion == 2 || opcion == 3)
  {
   columnas(opcion,cara1,cara2,cara3,cara4,cara5,cara6);   
  }
  if(opcion == 4 || opcion == 5 || opcion == 6)
  {
   filas(opcion,cara1,cara2,cara3,cara4,cara5,cara6);   
  }
}