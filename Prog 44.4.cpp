/* Autor: Xavier Romero Hernández, Realizado: 13/05/2022 
	Utilizando Archivos Binarios
	Programa que almacena las calificaciones de un alumno y su faltas para un grupo de 10 alumnos
	El programa tendra las siguientes opciones:
		0. Salir
		1. Agregar alumnos
		2. Imprimir
		3. Alumnos Aprobados
		4. Alumnos Reprobados
		5. Promedio del grupo
		6. Porcentaje de alumnos Aprobados
		7. Guardar datos
		8. Cargar datos
		9. Ordenar por nombre
		10. Ordenar por promedio de mayor a menor
		//Para hacer operaciones con las calificaciones de los alumnos se siguen las siguientes reglas
			Si el numero de faltas es <=6, la calificación es la que esta almacenada en el dato promedio de la estructura
            	Pero si no, la calificación que se toma es 5
	*/
	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "milibreria.h"
#define MAX 10


int menu();
void agregar(struct alumno x[]);
void imprimir(struct alumno x[],int tipo, char *a);
void promedio(struct alumno x[]);
void porcentajeaprobados(struct alumno x[]);
void guardar(struct alumno x[]);
void cargar(struct alumno x[]);
void ordenarNombre(struct alumno x[]);
void ordenarPromedio(struct alumno x[]);

struct alumno{
	char nombre[30];
	float promedio;
	int faltas;
};

int n=0;

int main(){
	struct alumno grupo[MAX];
	int opcion, centi=0;
	do{
		opcion=menu();
		switch(opcion) {
			case 0: printf("Adios.....\n");
					break;
			case 1: agregar(grupo);
					centi=1;
					break;
			case 2:	if(centi==1){
						imprimir(grupo,0,"Totales");
					}
					else{
						printf("Primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break;
			case 3: if(centi==1){
						imprimir(grupo,1,"Aprobados");
					}
					else{
						printf("Primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break;
			case 4: if(centi==1){
						imprimir(grupo,2,"Reprobados");
					}
					else{
						printf("Primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break;
			case 5: if(centi==1){
						promedio(grupo);
					}
					else{
						printf("Primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break;
			case 6: if(centi==1){
						porcentajeaprobados(grupo);
					}
					else{
						printf("Primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break;
			case 7: if(centi==1){
						guardar(grupo);
					}
					else{
						printf("No se han registrado nuevos alumnos\n");
					}
					system("PAUSE");
					break;
			case 8: cargar(grupo);
					centi=1;
					system("PAUSE");
					break;	
			case 9:	if(centi==1){
						ordenarNombre(grupo);
					}
					else{
						printf("Primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break;
			case 10:if(centi==1){
						ordenarPromedio(grupo);
					}
					else{
						printf("Primero debes llenar los datos.\n");
					}
					system("PAUSE");
					break;							
			default:printf("Opcion no valida, ingresa otra opcion\n\n");
					break;
					
		}
	}while(opcion!=0);
	
	return 0;
}

//funciones
//Funcion que muestra el menu, pide una opcion, la valida y la regresa
int menu(){
	int opcion;
	printf("----------Menu Principal----------\n");
	printf("0. Salir\n");
	printf("1. Agregar alumnos\n");
	printf("2. Imprimir\n");
	printf("3. Alumnos Aprobados\n");
	printf("4. Alumnos Reprobados\n");
	printf("5. Promedio del grupo\n");
	printf("6. Porcentaje de aprobados\n");
	printf("7. Guardar datos\n");
	printf("8. Cargar datos\n");
	printf("9. Ordenar por nombre\n");
	printf("10. Ordenar por promedio (mayor a menor)\n");
	printf("----------------------------------\n");
	printf("Selecciona una opcion: ");
	scanf("%d",&opcion);
	return opcion;
}

//guardar daros del arreglo de estructuras en un archivo binario
void guardar(struct alumno x[]){
	FILE *f;
	f=fopen("alumnos.dat","w");
	if(f==NULL){
		printf("Error al intentar guardar los datos!!!\n");
	}
	else{
		for(int i=0;i<n;i++){
			fwrite(&x[i],sizeof(x[i]),1,f);
		}
		fclose(f);
		printf("--> Se guardaron %d registros\n",n);
	}
}

//leer el archivo binario y cargarlo al arreglo de estructuras
void cargar(struct alumno x[]){
	FILE *f;
	f=fopen("alumnos.dat","r");
	n=0;
	if(f==NULL){
		printf("Error al intentar guardar los datos!!!\n");
	}
	else{
		printf("Leyendo.......\n");
		printf("No.\tNombre\t\t\t\tFaltas\tPromedio\n");
		while(fread(&x[n],sizeof(x[n]),1,f)==1){
			n++;
			printf("%3d\t%-30s\t%2d\t%4.1f\n",n,x[n-1].nombre,x[n-1].faltas,x[n-1].promedio);
		}
		fclose(f);
		printf("--> %d registros leidos\n",n);
	}
}

void agregar(struct alumno x[]){
	int pregunta;
	while(n<MAX){
		leers("Nombre: ",x[n].nombre,30);
		x[n].promedio=leerf("Promedio: ",0,10);
		x[n].faltas=leerd("Faltas: ",0,32);
		n++;
		pregunta=leerd("Agregar otro alumno? (1-Si, 0-No) ",0,1);
		if(pregunta==0){
			break;
		}
	}
	if(n==MAX){
		printf("Arreglo lleno!!\n");
		system("PAUSE");
	}
}

void imprimir(struct alumno x[],int tipo, char *a){
	printf("----------------------Alumnos %s------------------\n",a);
	printf("No.\tNombre\t\t\t\tFaltas\tPromedio\n");
	printf("-------------------------------------------------------\n");
	for(int i=0;i<n;i++){
		switch(tipo){
			case 0: printf("%2d\t%-30s\t%-2d\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);
					break;
			case 1: if(x[i].promedio>=7 && x[i].faltas<=6){
						printf("%2d\t%-30s\t%-2d\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);
					}
					break;
			case 2: if(x[i].promedio<7 || x[i].faltas>6){
						printf("%2d\t%-30s\t%-2d\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);
					}
					break;
		}
	}
	printf("-------------------------------------------------------\n");
}

void promedio(struct alumno x[]){
	float suma=0, prom;
	for(int i=0;i<n;i++){
		if(x[i].faltas<=6){
			suma=suma+x[i].promedio;	
		}
		else{
			suma=suma+5;
		}
	}
	prom=suma/n;
	printf("PROMEDIO DEL GRUPO\n");
	printf("------------------------------\n");
	printf("El promedio es de %.1f\n",prom);
	printf("------------------------------\n");
}

void porcentajeaprobados(struct alumno x[]){
	int apro=0;
	float porcentaje;
	for(int i=0;i<n;i++){
		if(x[i].promedio>=7 && x[i].faltas<=6){
			apro++;
		}
	}
	porcentaje=(float)(apro*100)/n;
	printf("PORCENTAJE DE APROBADOS DEL GRUPO\n");
	printf("------------------------------\n");
	printf("Aprobados %.2f%%\n",porcentaje);
	printf("------------------------------\n");
}

void ordenarNombre(struct alumno x[]){
	//ordenamiento del arreglo por el metodo de la burbuja
	//usando el codigo de https://es.wikipedia.org/wiki/Ordenamiento_de_burbuja#:~:text=El%20ordenamiento%20de%20burbuja%20(Bubble,est%C3%A1n%20en%20el%20orden%20equivocado.	
	for(int z = 1; z < n; ++z) {
		struct alumno aux;
      	for(int v = 0; v < (n - z); v++) {
      	//edades[v] > edades[v+1]
         if(strcmp(x[v].nombre,x[v+1].nombre)>0){
            aux = x[v];
            x[v] = x[v + 1];
            x[v + 1] = aux;
         	}
      	}
    }
    imprimir(x,0,"Totales");
}

void ordenarPromedio(struct alumno x[]){
	//ordenamiento del arreglo por el metodo de la burbuja
	//usando el codigo de https://es.wikipedia.org/wiki/Ordenamiento_de_burbuja#:~:text=El%20ordenamiento%20de%20burbuja%20(Bubble,est%C3%A1n%20en%20el%20orden%20equivocado.	
	for(int z = 1; z < n; ++z) {
		struct alumno aux;
      	for(int v = 0; v < (n - z); v++) {
      	//edades[v] > edades[v+1]
         if(x[v].promedio < x[v+1].promedio){
            aux = x[v + 1];
            x[v + 1] = x[v];
            x[v] = aux;
         	}
      	}
    }
    imprimir(x,0,"Totales");
}
