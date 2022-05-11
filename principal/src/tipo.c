/*
 * tipo.c
 *
 *  Created on: 11 may. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"

void listarTipo(eTipo tipos){
	printf("%4d %15s\n",tipos.id, tipos.descripcion);
}
int listarTipos(eTipo tipos[], int tamHCodeTD){
	int todoOk=-1;
	if(tipos!=NULL && tamHCodeTD>0){
		system("cls");
		printf(".......................\n");
		printf("  ID      DESCRIPCION\n");
		printf(".......................\n");
		for(int i=0; i<tamHCodeTD;i++){
			listarTipo(tipos[i]);
		}
		printf(".......................\n");
		todoOk=0;
	}
	return todoOk;
}
int buscarIndexPorIdTipo(eTipo tipos[], int tamTD, int id){

	int todoOk=-1;
	if(tipos!=NULL && tamTD>0){
		for(int i=0; i<tamTD; i++){
			if(tipos[i].id== id){
				todoOk=i;
				break;
			}
		}
	}
	return todoOk;
}
