/*
 * aerolinea.c
 *
 *  Created on: 11 may. 2022
 *      Author: Jony
 */

#include <stdio.h>
#include <stdlib.h>
#include "aerolinea.h"
void listarAerolinea(eAerolinea aerolinea){
	printf("%4d %15s\n",aerolinea.id, aerolinea.descripcion);
}
int listarAerolineas(eAerolinea aerolineas[], int tamHCodeA){
	int todoOk=-1;
	if(aerolineas!=NULL && tamHCodeA>0){
		system("cls");
		printf(".......................\n");
		printf("  ID      DESCRIPCION\n");
		printf(".......................\n");
		for(int i=0; i<tamHCodeA;i++){
			listarAerolinea(aerolineas[i]);
		}
		printf(".......................\n");
		todoOk=0;
	}
	return todoOk;
}
int buscarIndexPorIdAerolinea(eAerolinea aerolineas[], int tamA, int id){

	int todoOk=-1;
	if(aerolineas!=NULL && tamA>0){
		for(int i=0; i<tamA; i++){
			if(aerolineas[i].id== id){
				todoOk=i;
				break;
			}
		}
	}
	return todoOk;
}
