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
	printf("%5d %10d %11s  %02d/%02d/%4d\n", vuelos.id, vuelos.idAvion, destinos[buscarIndexPorIdDestino(destinos, tamTD, vuelos.idDestino)].descripcion,vuelos.fecha.dia ,vuelos.fecha.mes,vuelos.fecha.anio);
}
int listarVuelos(eVuelo vuelos[], eDestino destinos[],int tamVuelo,int tamTD,int lenVuelos ){
	int todoOk=-1;
	if(vuelos!=NULL && destinos!=NULL && tamVuelo>0 && tamTD>0){
		system("cls");
		printf("........................................\n");
		printf("   ID  COD-AVION     DESTINO       FECHA\n");
		printf("........................................\n");
		for(int i=0; i<lenVuelos;i++){
				listarVuelo(vuelos[i], destinos, tamTD);
		}
		printf("........................................\n");
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
		cargarVuelos(vuelos,tamVuelos, indexVuelo, idVuelo, idAvion, idDestino, dia, mes, anio);

		printf("Se guardaron los datos con exito.\n");

		todoOk=0;
	}
	return todoOk;
}
int cargarVuelos(eVuelo vuelos[], int tamVuelos,int* indexVuelo, int* idVuelo,int idAvion, int idDestino, int dia, int mes, int anio){
	int todoOk=0;
	if(vuelos!=NULL && tamVuelos>0){
		vuelos[*indexVuelo].id=*idVuelo;
		vuelos[*indexVuelo].idAvion=idAvion;
		vuelos[*indexVuelo].idDestino=idDestino;
		vuelos[*indexVuelo].fecha.dia=dia;
		vuelos[*indexVuelo].fecha.mes=mes;
		vuelos[*indexVuelo].fecha.anio=anio;
		(*idVuelo)++;
		(*indexVuelo)++;

		todoOk=0;
	}
	return todoOk;

}

int hardCodearVuelos(eVuelo vuelos[],eAvion aviones[], int tamAviones, int tamVuelos, int* indexVuelo, int* idVuelo){
	int todoOk=0;
	if(vuelos!=NULL && tamVuelos>0){
		if(existeRegistro(aviones, tamAviones)==0){
			int idDestino[10]={20000,20001,20002,20003,20000,20001,20002,20003,20000,20001};
			int dia[10]={12,10,23,9,20,20,8,30,7,19};
			int mes[10]={1,2,4,4,10,6,7,9,9,10};
			int anio[10]={2000,2001,2002,2003,2005,2000,2001,2002,2003,2005};
			int idAvion[10];
			int contador=0;
			while(contador<=10){
				for(int i=0;i<tamAviones;i++){
					if(aviones[i].isEmpty==0){
						idAvion[contador]=aviones[i].id;
						contador++;
					}
				}
			}
			for(int i=0;i<10;i++){
				cargarVuelos(vuelos, tamVuelos, indexVuelo,idVuelo, idAvion[i], idDestino[i],dia[i], mes[i],  anio[i]);
			}
		}else{
			printf("No se puede hardCodear por que no hay aviones cargados.\n");
		}

		todoOk=0;
	}
	return todoOk;
}


///


int listarVuelosConAvionSeleccionado(eVuelo vuelos[], eDestino destinos[],eAvion aviones[], eAerolinea aerolineas[], eTipo tipos[], int tamVuelos,int tamTD,int tamAviones , int tamA, int lenVuelos){
	int todoOk=-1;
	int idAvion;
	int aux;
	int aux2;
	if(vuelos!=NULL && destinos!=NULL && tamVuelos>0 && tamTD>0){
		listarAviones(aviones, aerolineas, tipos, tamAviones, tamA, tamTD);
		do{
			cargarValidarEnteroPositivo("Ingrese el id del tipo",&idAvion);
			aux= buscarIndexPorIdAvion(aviones, tamAviones, idAvion);
			if(aux==-1){
				printf("No se encontro el id. Vuelva a intentear.\n");
			}
		}while(aux==-1);

		system("cls");
		printf("........................................\n");
		printf("   ID  COD-AVION     DESTINO       FECHA\n");
		printf("........................................\n");
		for(int i=0; i<lenVuelos;i++){
			aux2=vuelos[i].idAvion;
			if(aux2==idAvion){
				listarVuelo(vuelos[i], destinos, tamTD);
			}


		}
		printf("........................................\n");
		todoOk=0;



	}
	return todoOk;
}

int listarPrecioTotalViajeUnAvion(eVuelo vuelos[], eDestino destinos[],eAvion aviones[], eAerolinea aerolineas[], eTipo tipos[], int tamVuelos,int tamTD,int tamAviones , int tamA){
	int todoOk=-1;
	int idAvion;
	int aux;
	float precioTotal=0;
	if(vuelos!=NULL && destinos!=NULL && tamVuelos>0 && tamTD>0){
		listarAviones(aviones, aerolineas, tipos, tamAviones, tamA, tamTD);
		do{
			cargarValidarEnteroPositivo("Ingrese el id del tipo",&idAvion);
			aux= buscarIndexPorIdAvion(aviones, tamAviones, idAvion);
			if(aux==-1){
				printf("No se encontro el id. Vuelva a intentear.\n");
			}
		}while(aux==-1);

		system("cls");
		printf("........................................\n");
		printf("   ID  COD-AVION     DESTINO       FECHA\n");
		printf("........................................\n");
		for(int i=0; i<tamVuelos;i++){
			if(vuelos[i].idAvion==idAvion){
				precioTotal+=destinos[buscarIndexPorIdDestino(destinos, tamTD, vuelos[i].idDestino)].precio;
				listarVuelo(vuelos[i], destinos, tamTD);
			}
		}
		printf("........................................\n");
		printf("El precio total los servicios hechos al avion %d es:$ %.2f\n",idAvion, precioTotal);
		todoOk=0;
	}
	return todoOk;
}

int listarViajesSeleccionandoUnDestino(eVuelo vuelos[], eDestino destinos[],eAvion aviones[], eAerolinea aerolineas[], eTipo tipos[], int tamVuelos,int tamTD,int tamAviones , int tamA,int lenVuelos){
	int todoOk=-1;
	int idAux;
	int index;

	if(vuelos!=NULL && destinos!=NULL && tamVuelos>0 && tamTD>0){
		do{
			listarDestinos(destinos, tamTD);
			cargarValidarEntero("Ingrese el id del destino",&idAux);
			index=buscarIndexPorIdDestino(destinos, tamTD, idAux);
			if(index==-1){
				printf("No se encontro el id seleccionado.\n");
				system("pause");
			}
		}while(index==-1);

		system("cls");
		printf("........................................\n");
		printf("   ID  COD-AVION     DESTINO       FECHA\n");
		printf("........................................\n");
		for(int i=0; i<lenVuelos;i++){
			if(vuelos[i].idDestino==idAux){
				if(vuelos[i].idDestino==idAux){
				listarVuelo(vuelos[i], destinos, tamTD);
				}
			}
		}
		printf("........................................\n");

		todoOk=0;
	}
	return todoOk;
}

int listarViajesSeleccionandoUnaFecha(eVuelo vuelos[], eDestino destinos[],eAvion aviones[], eAerolinea aerolineas[], eTipo tipos[], int tamVuelos,int tamTD,int tamAviones , int tamA){
	int todoOk=-1;
	int dia;
	int mes;
	int anio;

	if(vuelos!=NULL && destinos!=NULL && tamVuelos>0 && tamTD>0){
		cargarValidarFecha(&dia,&mes,&anio);
		system("cls");
		printf("........................................\n");
		printf("   ID  COD-AVION     DESTINO       FECHA\n");
		printf("........................................\n");
		for(int i=0; i<tamVuelos;i++){
			if(vuelos[i].fecha.dia==dia && vuelos[i].fecha.mes==mes && vuelos[i].fecha.anio==anio){

				listarVuelo(vuelos[i], destinos, tamTD);
			}
		}
		printf("........................................\n");

		todoOk=0;
	}
	return todoOk;
}

