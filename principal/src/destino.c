/*
 * destino.c
 *
 *  Created on: 11 may. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include "destino.h"

void listarDestino(eDestino destinos){
	printf("%4d %15s %10.2f\n",destinos.id,destinos.descripcion, destinos.precio);
}
int listarDestinos(eDestino destinos[], int tamHCodeTD){
	int todoOk=-1;
	if(destinos!=NULL && tamHCodeTD>0){
		system("cls");
		printf(".......................\n");
		printf("  ID      DESCRIPCION     PRECIO\n");
		printf(".......................\n");
		for(int i=0; i<tamHCodeTD;i++){
			listarDestino(destinos[i]);
		}
		printf(".......................\n");
		todoOk=0;
	}
	return todoOk;
}
int buscarIndexPorIdDestino(eDestino destinos[], int tamTD, int id){

	int todoOk=-1;
	if(destinos!=NULL && tamTD>0){
		for(int i=0; i<tamTD; i++){
			if(destinos[i].id== id){
				todoOk=i;
				break;
			}
		}
	}
	return todoOk;
}
