/* Autor: Xavier Romero Hernández, Realizado: 18/04/2022
	Libreria para funciones comunes de programas en C 
	para las funciones es_entero y es_decimmal se usa el codigo de la pagina:
	http://www.programacionenc.net/index.php?option=com_content&view=article&id=125:verificar-si-el-ingreso-de-teclado-es-un-entero-o-decimal&catid=31:general&Itemid=41#:~:text=Lo%20que%20se%20hace%20es,float%20usando%20la%20funci%C3%B3n%20atof.&text=Las%20funciones%20atoi%2C%20atof%20est%C3%A1n%20definidas%20en%20stdlib.
	*/
	
#ifndef _MILIBRERIA
#define _MILIBRERIA
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//prototipos
float leerf(char *mensaje, float inferior, float superior);
int leerd(char *mensaje, int inferior, int superior);
void leers(char *mensaje,char s[],int n);
int es_entero(char *cadena);
int es_decimal(char *cadena);

#include "milibreria.cpp"
#endif

