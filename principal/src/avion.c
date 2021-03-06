/*
 * avion.c
 *
 *  Created on: 11 may. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	printf("%4d %14s %10s %10d\n",aviones.id, aerolineas[buscarIndexPorIdAerolinea(aerolineas,tamA, aviones.idAeroLinea)].descripcion, tipos[buscarIndexPorIdTipo(tipos, tamTD, aviones.idTipo)].descripcion,aviones.capacidad);
}
int listarAviones(eAvion aviones[],eAerolinea aerolineas[], eTipo  tipos[], int tamAviones, int tamA, int tamTD){
	int todoOk=-1;
	if(aviones!=NULL && tamAviones>0){

		system("cls");
		printf("........................................\n");
		printf("  ID      AEROLINEA       TIPO  CAPACIDAD\n");
		printf(".........................................\n");
		for(int i=0; i<tamAviones;i++){
			if(aviones[i].isEmpty==0){
				listarAvion(aviones[i], aerolineas, tipos, tamA, tamTD);
			}
		}
		printf(".........................................\n");
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
	int idAerolinea;
	int idTipo;
	int capacidad;
	if(aviones!=NULL && aerolineas!=NULL && tipos!=NULL && idAviones!=NULL && tamAviones>0 && tamTD>0){
		if(buscarIndexLibre(aviones, tamAviones)!=-1){
			if(validarDatos(aerolineas, tipos, tamTD,tamA, &idAerolinea, &idTipo, &capacidad)==0){
				cargarDatos(aviones, tamAviones,idAviones,idAerolinea, idTipo, capacidad);
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
int cargarDatos(eAvion aviones[], int tamAviones, int* idAviones, int idAerolinea, int idTipo, int capacidad){
	int todoOk=-1;
	int auxIndex;
	if(aviones!=NULL && idAviones!=NULL && tamAviones>0){
		auxIndex=buscarIndexLibre(aviones, tamAviones);
		if(auxIndex!=-1){
			aviones[auxIndex].id=*idAviones;
			aviones[auxIndex].idAeroLinea=idAerolinea;
			aviones[auxIndex].idTipo=idTipo;
			aviones[auxIndex].capacidad=capacidad;
			aviones[auxIndex].isEmpty=0;
			(*idAviones)++;
			todoOk=0;
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
int ordenarPorAEyCapacidad(eAvion* aviones,eAerolinea aerolineas[],int tamA,int tamAviones){
	int todoOk=-1;
	eAvion aux;
	if(aviones!=NULL && tamAviones>0){
		for(int i=0;i<tamAviones-1;i++){
			for(int j=i+1;j<tamAviones;j++){
				if(strcmp(aerolineas[buscarIndexPorIdAerolinea(aerolineas,tamA,aviones[i].idAeroLinea)].descripcion,aerolineas[buscarIndexPorIdAerolinea(aerolineas,tamA,aviones[j].idAeroLinea)].descripcion)>0){
					aux=aviones[i];
					aviones[i]=aviones[j];
					aviones[j]=aux;
				}else if(strcmp(aerolineas[buscarIndexPorIdAerolinea(aerolineas,tamA,aviones[i].idAeroLinea)].descripcion,aerolineas[buscarIndexPorIdAerolinea(aerolineas,tamA,aviones[j].idAeroLinea)].descripcion)==0 && aviones[i].capacidad > aviones[j].capacidad){
					aux=aviones[i];
					aviones[i]=aviones[j];
					aviones[j]=aux;
				}

			}
		}
		todoOk=0;
	}
	return todoOk;
}



int hardCodearAviones(eAvion aviones[],int tamAviones, int* idAviones){
	 int todoOk=-1;
	 if(aviones!=NULL && idAviones!=NULL && tamAviones>0){
		 int idAE[10]={1000,1002,1003,1004,1000,1002,1003,1004,1002,1001};
		 int idTP[10]={5000,5001,5002,5003,5000,5001,5002,5003,5000,5001};
		 int idCP[10]={10,100,200,300,200,150,80,280,300,180};
		 for(int i=0;i<10;i++){
			cargarDatos(aviones,tamAviones, idAviones,idAE[i],idTP[i],idCP[i]);
		 }
		 todoOk=0;
	 }
	 return todoOk;
}
int listarAvionesPorAerolineaSeleccionado(eAvion aviones[],eAerolinea aerolineas[], eTipo  tipos[], int tamAviones, int tamA, int tamTD){
	int todoOk=-1;
	int aux;
	int idAerolinea;
	if(aviones!=NULL && tamAviones>0){
		listarAerolineas(aerolineas, tamA);
		do{
			cargarValidarEnteroPositivo("Ingrese el id la Aerolinea",&idAerolinea);
			aux= buscarIndexPorIdAerolinea(aerolineas, tamA, idAerolinea);
			if(aux==-1){
				printf("No se encontro el id. Vuelva a intentear.\n");
			}
		}while(aux==-1);

		system("cls");
		printf("........................................\n");
		printf("  ID      AEROLINEA       TIPO  CAPACIDAD\n");
		printf(".........................................\n");
		for(int i=0; i<tamAviones;i++){
			if(aviones[i].isEmpty==0 && aviones[i].idAeroLinea==idAerolinea){
				listarAvion(aviones[i], aerolineas, tipos, tamA, tamTD);
			}
		}
		printf(".........................................\n");
		todoOk=0;
	}
	return todoOk;
}
int listarAvionesPorTipoSeleccionado(eAvion aviones[],eAerolinea aerolineas[], eTipo  tipos[], int tamAviones, int tamA, int tamTD){
	int todoOk=-1;
	int aux;
	int idTipo;
	if(aviones!=NULL && tamAviones>0){
		listarTipos(tipos,tamTD);
		do{
			cargarValidarEnteroPositivo("Ingrese el id del tipo",&idTipo);
			aux= buscarIndexPorIdTipo(tipos, tamTD, idTipo);
			if(aux==-1){
				printf("No se encontro el id. Vuelva a intentear.\n");
			}
		}while(aux==-1);

		system("cls");
		printf("........................................\n");
		printf("  ID      AEROLINEA       TIPO  CAPACIDAD\n");
		printf(".........................................\n");
		for(int i=0; i<tamAviones;i++){
			if(aviones[i].isEmpty==0 && aviones[i].idTipo==idTipo){
				listarAvion(aviones[i], aerolineas, tipos, tamA, tamTD);
			}
		}
		printf(".........................................\n");
		todoOk=0;
	}
	return todoOk;
}
////////
///
///
int ListarSeparadoPorAerolinea(eAvion aviones[],eAerolinea aerolineas[], eTipo  tipos[], int tamAviones, int tamA, int tamTD){
	int todoOk=-1;
	int aux;
	if(aviones!=NULL && tamAviones>0){

		for(int i=0; i<tamA; i++){
			aux=aerolineas[i].id;
			printf("........................................\n");
			printf("  ID      AEROLINEA       TIPO  CAPACIDAD\n");
			printf(".........................................\n");
			for(int i=0; i<tamAviones;i++){
				if(aviones[i].isEmpty==0 && aviones[i].idAeroLinea==aux){
					listarAvion(aviones[i], aerolineas, tipos, tamA, tamTD);
				}
			}
			printf(".........................................\n");
		}


		todoOk=0;
	}
	return todoOk;
}

int MostrarAeroLineaMayorCarga(eAvion aviones[],eAerolinea aerolineas[], eTipo  tipos[], int tamAviones, int tamA, int tamTD){
	int todoOk=-1;


	int acum;
	int aux;
	int mayor;
	int mayorIndex;
	int flag=0;
	if(aviones!=NULL && tamAviones>0){
		for(int j=0; j<tamA;j++){
			aux=aerolineas[j].id;
			acum=0;
			for(int i=0;i<tamAviones; i++){
				if(aux==aviones[i].idAeroLinea){
					acum+=aviones[i].capacidad;
				}

			}

			if(flag==0){
				mayor=acum;
				mayorIndex=j;
				flag=1;
			}else if(mayor<acum){
				mayor=acum;
				mayorIndex=j;
			}
		}

		system("cls");
		printf("El mayor es %s con una suma total: %d\n", aerolineas[mayorIndex].descripcion, mayor);
		printf("........................................\n");
		printf("  ID      AEROLINEA       TIPO  CAPACIDAD\n");
		printf(".........................................\n");
		for(int i=0; i<tamAviones;i++){
			if(aviones[i].isEmpty==0 && aviones[i].idAeroLinea==aerolineas[mayorIndex].id){
				listarAvion(aviones[i], aerolineas, tipos, tamA, tamTD);
			}
		}
		printf(".........................................\n");
		todoOk=0;
	}
	return todoOk;
}
int listarAerolineaConMenorAviones(eAvion aviones[],eAerolinea aerolineas[], eTipo  tipos[], int tamAviones, int tamA, int tamTD){
	int todoOk=-1;

	int tot1000=0;
	int tot1001=0;
	int tot1002=0;
	int tot1003=0;
	int tot1004=0;
	int menor;
	if(aviones!=NULL && tamAviones>0){
		for(int i=0;i<tamAviones; i++){
			switch(aviones[i].idAeroLinea){
			case 1000:
				tot1000++;
				break;
			case 1002:
				tot1002++;
				break;
			case 1003:
				tot1003++;
				break;
			case 1004:
				tot1004++;
				break;
			case 1001:
				tot1001++;
				break;
			}
		}
		if(tot1000<tot1001 &&tot1000<tot1002 &&tot1000<tot1003 &&tot1000<tot1004){
			printf("El la aerolinea menos usada es: %s\n", aerolineas[buscarIndexPorIdAerolinea(aerolineas, tamA, 1000)].descripcion);
			menor=1000;
		}else if(tot1001<tot1002 &&tot1001<tot1003 &&tot1001<tot1004){
			printf("El la aerolinea menos usada es: %s\n", aerolineas[buscarIndexPorIdAerolinea(aerolineas, tamA, 1001)].descripcion);
			menor=1001;
		}else if(tot1002>tot1003 &&tot1002>tot1004){
			printf("El la aerolinea menos usada es: %s\n", aerolineas[buscarIndexPorIdAerolinea(aerolineas, tamA, 1002)].descripcion);
			menor=1002;
		}else if(tot1003<tot1004){
			printf("El la aerolinea menos usada es: %s\n", aerolineas[buscarIndexPorIdAerolinea(aerolineas, tamA, 1003)].descripcion);
			menor=1003;
		}else{
			printf("El la aerolinea menos usada es: %s\n", aerolineas[buscarIndexPorIdAerolinea(aerolineas, tamA, 1004)].descripcion);
			menor=1004;
		}

		system("cls");
		printf("........................................\n");
		printf("  ID      AEROLINEA       TIPO  CAPACIDAD\n");
		printf(".........................................\n");
		for(int i=0; i<tamAviones;i++){
			if(aviones[i].isEmpty==0 && aviones[i].idAeroLinea==menor){
				listarAvion(aviones[i], aerolineas, tipos, tamA, tamTD);
			}
		}
		printf(".........................................\n");
		todoOk=0;
	}
	return todoOk;
}
