#include <stdio.h>
#include <string.h>

struct contacto;
int mostrar_menu(void);
int rellenar (struct contacto *agenda);
void mostrar_agenda(struct contacto *agenda, int numero_contactos);
int agregar_contacto (struct contacto *agenda, int numero_contactos);
int ordenar_agenda (struct contacto *agenda, int numero_contactos);
int sobreescribir_agenda (struct contacto *agenda, int numero_contactos);
int ordenar_contacto (struct contacto *agenda, int f, int i);
int eliminar_registro(struct contacto *agenda, int numero_contactos);
