/*
 * vuelo.c
 *
 *  Created on: 11 may. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include "vuelo.h"
#include "validaciones.h"

void listarVuelo(eVuelo vuelos, eDestino destinos[],int tamTD){
	printf("%4d %10d %15s %d/%d/%d\n", vuelos.id, vuelos.idAvion, destinos[buscarIndexPorIdDestino(destinos, tamTD, vuelos.idDestino)].descripcion,vuelos.fecha.dia ,vuelos.fecha.mes,vuelos.fecha.anio);
}
int listarVuelos(eVuelo vuelos[], eDestino destinos[],int tamVuelo,int tamTD,int lenVuelos ){
	int todoOk=-1;
	if(vuelos!=NULL && destinos!=NULL && tamVuelo>0 && tamTD>0){
		system("cls");
		printf(".......................\n");
		printf("  ID      COD-AVION     DESTINO  FECHA\n");
		printf(".......................\n");
		for(int i=0; i<lenVuelos;i++){
				listarVuelo(vuelos[i], destinos, tamTD);
		}
		printf(".......................\n");
		todoOk=0;
	}
	return todoOk;
}
int altaVuelo(eVuelo vuelos[], eAvion aviones[], eDestino destinos[],eAerolinea aerolineas[], eTipo tipos[],  int tamVuelos,int tamAviones, int tamTD, int tamA, int* idVuelo, int* indexVuelo){
	int todoOk=-1;
	int idAvion;
	int idDestino;
	int dia;
	int mes;
	int anio;

	int index;
	int idAux;
	if(vuelos!=NULL && aviones!=NULL && destinos!=NULL && idVuelo!=NULL && indexVuelo!=NULL && tamVuelos>0 && tamAviones>0 && tamTD>0){
		do{
			listarAviones(aviones,aerolineas, tipos, tamAviones,tamA, tamTD);
			cargarValidarEntero("Ingrese el id Avion",&idAux);
			index=buscarIndexPorIdAvion(aviones, tamAviones, idAux);
			if(index==-1){
				printf("No se encontro el id seleccionado.\n");
				system("pause");
			}else{
				idAvion=aviones[index].id;
			}
		}while(index==-1);


		do{
			listarDestinos(destinos, tamTD);
			cargarValidarEntero("Ingrese el id del destino",&idAux);
			index=buscarIndexPorIdDestino(destinos, tamTD, idAux);
			if(index==-1){
				printf("No se encontro el id seleccionado.\n");
				system("pause");
			}else{
				idDestino=destinos[index].id;
			}
		}while(index==-1);
		cargarValidarFecha(&dia,&mes,&anio);

		vuelos[*indexVuelo].id=*idVuelo;
		vuelos[*indexVuelo].idAvion=idAvion;
		vuelos[*indexVuelo].idDestino=idDestino;
		vuelos[*indexVuelo].fecha.dia=dia;
		vuelos[*indexVuelo].fecha.mes=mes;
		vuelos[*indexVuelo].fecha.anio=anio;
		(*idVuelo)++;
		(*indexVuelo)++;
		printf("Se guardaron los datos con exito.\n");
		system("pause");

		todoOk=0;
	}
	return todoOk;
}
