#include "milibreria.h"

float leerf(char *mensaje, float inferior, float superior){
	float valor=superior+1;
	char s[10];
	do{
		printf(mensaje);
		fflush(stdin);
		fgets(s,10,stdin);
		fflush(stdin);
		if(s[strlen(s)-1]=='\n'){
		s[strlen(s)-1]=0;
		}
		if(es_decimal(s)){
			valor=atof(s);
			if(valor<inferior || valor>superior){
				printf("Dato invalido !!!, Debe estar entre(%.2f-%.2f). Vuelva a introducirlo\n",inferior,superior);
			}
		}
		else{
			printf("Dato invalido !!!, Debe ser un numero decimal\n");
		}
	}while(valor<inferior || valor>superior);
	return valor;
}

int leerd(char *mensaje, int inferior, int superior){
	int valor=superior+1;
	char s[10];
	do{
		printf(mensaje);
		fflush(stdin);
		fgets(s,10,stdin);
		fflush(stdin);
		if(s[strlen(s)-1]=='\n'){
		s[strlen(s)-1]=0;
		}
		if(es_entero(s)){
			valor=atoi(s);
			if(valor<inferior || valor>superior){
				printf("Dato invalido !!!, Debe estar entre(%d-%d). Vuelva a introducirlo\n",inferior,superior);
			}
		}
		else{
			printf("Dato invalido !!!, Debe ser un numero entero\n");
		}
		
	}while(valor<inferior || valor>superior);
	return valor;
}

void leers(char *mensaje,char s[],int n){
	//char text[20];
	printf(mensaje);
	fflush(stdin);
	fgets(s,n,stdin);
	fflush(stdin);
	if(s[strlen(s)-1]=='\n'){
		s[strlen(s)-1]=0;
	}
}

//funcion de validacion de enteros y flotantes
//tomados de http://www.programacionenc.net/index.php?option=com_content&view=article&id=125:verificar-si-el-ingreso-de-teclado-es-un-entero-o-decimal&catid=31:general&Itemid=41#:~:text=Lo%20que%20se%20hace%20es,float%20usando%20la%20funci%C3%B3n%20atof.&text=Las%20funciones%20atoi%2C%20atof%20est%C3%A1n%20definidas%20en%20stdlib.
int es_entero(char *cadena){
   int i, valor;
   for(i=0; i < strlen(cadena); i++){
      valor = cadena[ i ] - '0';
      if(valor < 0 || valor > 9){
          if(i==0 && valor==-3) continue;
          return 0;
      }
   }
   return 1;
}

int es_decimal(char *cadena){
   int i, valor;
   int tiene_punto = 0;
   for(i=0; i < strlen(cadena); i++){
      valor = cadena[ i ] - '0';
      if(valor < 0 || valor > 9){
          /* El primer caracter es: - */
         if(i==0 && valor==-3) continue;

         /* Verifica que solo tenga un: . */
         if(valor==-2 && !tiene_punto){ 
            tiene_punto=1;
            continue;
         }
         return 0;
      }
   }
   return 1;
}


