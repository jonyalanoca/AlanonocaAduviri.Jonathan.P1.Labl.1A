/*
 * avion.c
 *
 *  Created on: 11 may. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include "avion.h"
#include "validaciones.h"
#include "menus.h"

int inicializarArray(eAvion aviones[], int tamAvion){
	int todoOk=-1;
	if(aviones!=NULL && tamAvion>0){
		for(int i=0;i<tamAvion;i++){
			aviones[i].isEmpty=1;
		}
		todoOk=0;
	}
	return todoOk;
}

int buscarIndexLibre(eAvion aviones[], int tamAvion){
	int todoOk=-1;
	if(aviones!=NULL && tamAvion>0){
		for(int i=0;i<tamAvion;i++){
			if(aviones[i].isEmpty==1){
				todoOk=i;
				break;
			}
		}
	}
	return todoOk;
}

int existeRegistro(eAvion aviones[], int tamAvion){/// 0: si hay algun registro, -1 esta vacio
	int todoOk=-1;
	if(aviones!=NULL && tamAvion>0){
		for(int i=0;i<tamAvion;i++){
			if(aviones[i].isEmpty==0){
				todoOk=0;
				break;
			}
		}
	}
	return todoOk;
}
void listarAvion(eAvion aviones,eAerolinea aerolineas[], eTipo  tipos[], int tamA, int tamTD){
	printf("%4d %15s %15s %10d\n",aviones.id, aerolineas[buscarIndexPorIdAerolinea(aerolineas,tamA, aviones.idAeroLinea)].descripcion, tipos[buscarIndexPorIdTipo(tipos, tamTD, aviones.idTipo)].descripcion,aviones.capacidad);
}
int listarAviones(eAvion aviones[],eAerolinea aerolineas[], eTipo  tipos[], int tamAviones, int tamA, int tamTD){
	int todoOk=-1;
	if(aviones!=NULL && tamAviones>0){
		system("cls");
		printf(".......................\n");
		printf("  ID      AEROLINEA     TIPO  CAPACIDAD\n");
		printf(".......................\n");
		for(int i=0; i<tamAviones;i++){
			if(aviones[i].isEmpty==0){
				listarAvion(aviones[i], aerolineas, tipos, tamA, tamTD);
			}
		}
		printf(".......................\n");
		todoOk=0;
	}
	return todoOk;
}
int modificarAvion(eAvion aviones[],eAerolinea aerolineas[],eTipo tipos[], int tamAvion, int tamA, int tamTD){
	int todoOk=-1;
	int id;
	int index;

	int aux;
	int idAerolinea;
	int idTipo;
	int capacidad;
	if(aviones!=NULL && aerolineas!=NULL && tipos!=NULL &&  tamAvion>0 && tamA>0 && tamTD>0){
		do{

			listarAviones(aviones, aerolineas, tipos,tamAvion, tamA, tamTD);
			cargarValidarEntero("Ingrese el id del Avion a modificar",&id);
			index=buscarIndexPorIdAvion(aviones, tamAvion, id);
			if(index==-1){
				printf("No se encontro el id seleccionado.\n");
				system("pause");
			}else{
				switch(menuModificar()){
				case 1:
					listarAerolineas(aerolineas,tamA);
					do{
						cargarValidarEnteroPositivo("Ingrese el id de la Aerolinea del Vuelo",&idAerolinea);
						aux= buscarIndexPorIdAerolinea(aerolineas, tamA, idAerolinea);
						if(aux==-1){
							printf("No se encontro el id. Vuelva a intentear.\n");
						}
					}while(aux==-1);
					aviones[index].idAeroLinea=idAerolinea;
					break;
				case 2:
					listarTipos(tipos, tamTD);
					do{
						cargarValidarEnteroPositivo("Ingrese el id del Tipo  del avion",&idTipo);
						aux= buscarIndexPorIdTipo(tipos, tamTD, idTipo);
						if(aux==-1){
							printf("No se encontro el id. Vuelva a intentear.\n");
						}
					}while(aux==-1);
					aviones[index].idTipo=idTipo;
					break;
				case 3:
					enteroEnRango("Ingrese la capacidad el avion (10-300)", &capacidad,10,300);
					aviones[index].capacidad=capacidad;
					break;
				}
			}
		}while(index==-1);
		todoOk=0;
	}
	return todoOk;
}

int bajaAvion(eAvion aviones[],eAerolinea aerolineas[],eTipo tipos[], int tamAvion, int tamA, int tamTD){
	int todoOk=-1;
	int index;
	int id;

	char confir;
	if(aviones!=NULL && aerolineas!=NULL && tipos!=NULL &&  tamAvion>0 && tamA>0 && tamTD>0){
		do{
			listarAviones(aviones, aerolineas, tipos,tamAvion, tamA, tamTD);
			cargarValidarEntero("Ingrese el id del Avion a dar de baja",&id);
			index=buscarIndexPorIdAvion(aviones, tamAvion, id);
			if(index==-1){
				printf("No se encontro el id seleccionado.\n");
				system("pause");

			}else{
				system("cls");
				printf("ATENCION:Por favor confirme si desea borrar el siguiente registro:\n\n");
				listarAvion(aviones[index], aerolineas, tipos, tamA, tamTD);
				cargarValidarCharEntreDos("Confirme (s/n)",&confir,'s','n');
				if(confir=='s'){
					aviones[index].isEmpty=1;
					printf("Se borro el resgistro\n");
				}else{
					printf("No se realizaron cambios.\n");
				}
			}
		}while(index==-1);
		todoOk=0;
	}
	return todoOk;
}
int altaAvion(eAvion aviones[], eAerolinea aerolineas[], eTipo tipos[],int  tamAviones, int tamTD, int tamA, int* idAviones){
	int todoOk=-1;
	int auxIndex;
	int idAerolinea;
	int idTipo;
	int capacidad;
	if(aviones!=NULL && aerolineas!=NULL && tipos!=NULL && idAviones!=NULL && tamAviones>0 && tamTD>0){

		auxIndex=buscarIndexLibre(aviones, tamAviones);
		if(auxIndex!=-1){
			if(validarDatos(aerolineas, tipos, tamTD,tamA, &idAerolinea, &idTipo, &capacidad)==0){


				aviones[auxIndex].id=*idAviones;
				aviones[auxIndex].idAeroLinea=idAerolinea;
				aviones[auxIndex].idTipo=idTipo;
				aviones[auxIndex].capacidad=capacidad;
				aviones[auxIndex].isEmpty=0;
				(*idAviones)++;

				todoOk=0;
			}else{
				printf("Error al validar punteros o tam menor a cero.\n");
			}
		}else{
			printf("No hay mas espacio.\n");
		}
	}
	return todoOk;
}
int validarDatos(eAerolinea aerolineas[], eTipo tipos[], int tamTD,int tamA, int* idAerolinea, int* idTipo, int* capacidad ){
	int todoOk=-1;
	int aux;
	if(aerolineas!=NULL && tipos!=NULL && idAerolinea!=NULL && idTipo!=NULL && capacidad!=NULL  && tamTD>0){
		listarAerolineas(aerolineas, tamA);
		do{
			cargarValidarEnteroPositivo("Ingrese el id la Aerolinea",idAerolinea);
			aux= buscarIndexPorIdAerolinea(aerolineas, tamA, *idAerolinea);
			if(aux==-1){
				printf("No se encontro el id. Vuelva a intentear.\n");
			}
		}while(aux==-1);

		listarTipos(tipos,tamTD);
		do{
			cargarValidarEnteroPositivo("Ingrese el id del tipo",idTipo);
			aux= buscarIndexPorIdTipo(tipos, tamTD, *idTipo);
			if(aux==-1){
				printf("No se encontro el id. Vuelva a intentear.\n");
			}
		}while(aux==-1);
		enteroEnRango("Ingrese la capacidad el avion (10-300)", capacidad,10,300);
		todoOk=0;
	}
	return todoOk;
}
int buscarIndexPorIdAvion(eAvion aviones[], int tamAvion, int id){

	int todoOk=-1;
	if(aviones!=NULL && tamAvion>0){
		for(int i=0; i<tamAvion; i++){
			if(aviones[i].id== id && aviones[i].isEmpty==0){
				todoOk=i;
				break;
			}
		}
	}
	return todoOk;
}
