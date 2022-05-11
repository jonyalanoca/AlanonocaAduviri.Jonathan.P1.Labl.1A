/*
 * validaciones.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Jony
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"


static int stringSoloNumeros(int inicio, char nums[], int* validado){
	int todoOk=0;
	if(inicio>=0 && nums!=NULL && validado!=NULL){
		for(int i=inicio; i<strlen(nums);i++){
			if(!isdigit(nums[i])){
				printf("Ingrese solo numeros. ");
				*validado=0;
				break;
			}
			*validado=1;
		}
		todoOk=1;
	}
	return todoOk;
}
int cargarValidarEnteroPositivo(char mensaje[],int* pNumero){
	int todoOk=0;
	char numero[50];
	int validado=0;
	if(mensaje !=NULL && pNumero!=NULL){
		do{
			printf("%s: ",mensaje);
			fflush(stdin);
			gets(numero);
			if(strlen(numero)==0){
				printf("No ingreso nada aun. ");
			}else{
				stringSoloNumeros(0, numero, &validado);
			}
		}while(!validado);
		*pNumero=atoi(numero);
		todoOk=0;
	}
	return todoOk;
}
int enteroEnRango(char mensaje[], int* pNumero,int numero1, int numero2){
	int todoOk=0;
	if(mensaje!=NULL && pNumero!=NULL){
		cargarValidarEntero(mensaje, pNumero);
		while(*pNumero<numero1 || *pNumero>numero2){
			printf("El numero esta fuera de rango. ");
			cargarValidarEntero(mensaje, pNumero);
		}
		todoOk=1;
	}
	return todoOk;
}
int cargarValidarEntero(char mensaje[],int* pNumero){
	int todoOk=0;
	char numero[50];
	int validado=0;
	if(mensaje !=NULL && pNumero!=NULL){
		do{
			printf("%s: ",mensaje);
			fflush(stdin);
			gets(numero);
			switch(strlen(numero)){
			case 0:
				printf("No ingreso nada aun. ");
				break;
			case 1:
				if(numero[0]=='-'){
					printf("No ingreso nada aun. ");
				}else{
					if(isdigit(numero[0])){
						validado=1;
					}else{
						printf("Ingrese solo numeros. ");
					}
				}
				break;
			default:
				if(numero[0]=='-'){
					stringSoloNumeros(1, numero, &validado);
				}else{
					stringSoloNumeros(0, numero, &validado);
				}
				break;
			}
		}while(!validado);
		*pNumero=atoi(numero);
	}
	return todoOk;
}
int cargarValidarDecimalPositivo(char mensaje[], float* varNumero){
	int todoOk=0;
	if(mensaje!= NULL && varNumero!=NULL){
		cargarValidarDecimal(mensaje, varNumero);
		while(*varNumero<0){
			printf("No se admiten numeros negativos. ");
			cargarValidarDecimal(mensaje, varNumero);
		}
		todoOk=1;
	}
	return todoOk;
}
int cargarValidarDecimal(char mensaje[], float* varNumero){
	int todoOk=0;
		int i;
		char auxString[50];
		if(mensaje!= NULL && varNumero!=NULL){
			todoOk=1;
			do{
				todoOk=1;
				printf("%s: ", mensaje);
				fflush(stdin);
				gets(auxString);
				if(auxString[0]=='\0'){
					printf("No ingreso nada aun. ");
					todoOk=0;
				}
				else{
					i=0;
					if(auxString[0]=='-'){
						i=1;
						if(auxString[1]=='\0'){
							printf("No ingreso nada aun. ");
							todoOk=0;
						}
					}
					while(auxString[i]!='\0' && todoOk==1){
						if(auxString[i]=='.'){
							i++;
							continue;

						}
						if(auxString[i]<'0' || auxString[i]>'9'){
							printf("Caracteres no validos. ");
							todoOk=0;
							break;
						}
						i++;
					}
				}
			}while(!todoOk);
			*varNumero=atof(auxString);
		}
		return todoOk;
}
int cargarValidarCadena(char mensaje[], int tam, char string[]){
	int todoOk=0;
	char texto[50];
	int validado=0;
	if(mensaje !=NULL && string!=NULL && tam>0){
		do{
			printf("%s: ",mensaje);
			fflush(stdin);
			fgets(texto,tam,stdin);
			borrarBarraN(texto);
			if(strlen(texto)==0){
				printf("No ingreso nada aun. ");
			}else{
				for(int i=0;i<strlen(texto);i++){
					if(!isalpha(texto[i])){
						printf("Caracteres no validos. ");
						validado=0;
						break;
					}
					validado=1;
				}
			}
		}while(!validado);
		todoOk=1;
		strncpy(string, texto, tam);
	}
	return todoOk;
}
int cargarValidarAlfaNumerico(char mensaje[], int tam, char string[]){
	int todoOk=0;
	char texto[50];
	int validado=0;
	if(mensaje !=NULL && string!=NULL && tam>0){
		do{
			printf("%s: ",mensaje);
			fflush(stdin);
			fgets(texto,tam,stdin);
			borrarBarraN(texto);
			if(strlen(texto)==0){
				printf("No ingreso nada aun. ");
			}else{
				for(int i=0;i<strlen(texto);i++){
					if(!isalpha(texto[i]) && !isdigit(texto[i])){
						printf("Caracteres no validos. ");
						validado=0;
						break;
					}
					validado=1;
				}
			}
		}while(!validado);
		todoOk=1;
		strncpy(string, texto, tam);
	}
	return todoOk;
}
int borrarBarraN(char string[]){
	int todoOk=0;
	int tam=strlen(string);
	if(string!=NULL){

		for(int i=0;i<tam;i++){
			if(string[i]=='\n'){
				string[i]='\0';
				break;
			}
		}
		todoOk=1;
	}
	return todoOk;
}
int capitalizar(char varString[]){
	int todoOk=0;
	if (varString!=NULL){
		strlwr(varString);
		varString[0]=varString[0]-32;
		todoOk=1;
	}
	return todoOk;
}
int cargarValidarCharEntreDos(char mensaje[],char* varChar, char letra1, char letra2){
	int todoOk=0;
	if(mensaje!=NULL&&varChar!=NULL){
		char aux;
		printf("%s: ", mensaje);
		fflush(stdin);
		scanf("%c", &aux);
		aux=tolower(aux);
		while(aux!=letra1 && aux!=letra2){
			 printf("Caracter no valido. %s: ",mensaje);
			 fflush(stdin);
			 scanf("%c", &aux);
			 aux=tolower(aux);
		}
		*varChar=aux;
		todoOk=1;
	}
	return todoOk;
}

int cargarValidarChar(char mensaje[], char* letra){
	int todoOk=0;
	char aux='-';
	int validado=0;
	if(mensaje !=NULL && letra!=NULL){
		do{
			printf("%s: ",mensaje);
			fflush(stdin);
			scanf("%c", &aux);
			if(aux=='\n' || aux =='\0'){
				printf("No ingreso nada aun. ");
			}else if(!isalpha(aux)){
				printf("Caracteres no validos. ");
				validado=0;
			}else{
				validado=1;

			}
		}while(!validado);
		todoOk=1;
		*letra=aux;
	}
	return todoOk;
}
int cargarValidarFecha(int* dia,int* mes,int* anio){
	int todoOk=-1;
	if(dia!=NULL && mes!=NULL && anio!=NULL){
		enteroEnRango("Ingrese el dia(1-31)", dia,1,31);
		enteroEnRango("Ingrese el mes(1-12)", mes,1,12);
		enteroEnRango("Ingrese el anio(2000-2050)", anio,2000,2050);
		todoOk=0;
	}
	return todoOk;
}
