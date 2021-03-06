#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "otros.h"
#include "menus.h"

#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "destino.h"
#include "vuelo.h"

#define TAM_HCODE_A 5
#define TAM_HCODE_TD 4
#define TAM_AVION 1000
#define TAM_VUELO 2000



int main(void) {
	setbuf(stdout,NULL);
	eAerolinea aerolineas[TAM_HCODE_A]={
			{1000,"Lan"},
			{1001,"Iberia"},
			{1002,"Norwegian"},
			{1003,"American"},
			{1004,"Austral"}
	};
	eTipo tipos[TAM_HCODE_TD]={
			{5000,"Jet"},
			{5001,"Helice"},
			{5002,"Planeador"},
			{5003,"Carga"},
	};
	eDestino destinos[TAM_HCODE_TD]={
			{20000,"Calafate",100000},
			{20001,"Miami",100000},
			{20002,"Madrid",100000},
			{20003,"Amsterdam",100000},
	};

	eAvion aviones[TAM_AVION];
	int idIncrem=4000;
	inicializarArray(aviones, TAM_AVION);


	eVuelo vuelos[TAM_VUELO];
	int idInVuelo=40000;
	int indexVuelo=0;

	char salir='n';
	do{
			switch(menu()){
			case 1:

				if(altaAvion(aviones, aerolineas, tipos, TAM_AVION, TAM_HCODE_TD, TAM_HCODE_A, &idIncrem)==-1){
					printf("Error al validar punteros o tam menor a cero.\n");
				}else{
					printf("Se cargaron los datos con exito.\n");
				}
				break;
			case 2:
				if(existeRegistro(aviones, TAM_AVION)==0){
					if(modificarAvion(aviones, aerolineas, tipos, TAM_AVION, TAM_HCODE_A, TAM_HCODE_TD)==-1){
						printf("Error al validar punteros o tam menor a cero.\n");
					}else{
						printf("Se modifico con exito.\n");
					}
				}else{
					printf("Primero debe registrar un avion.\n");
				}
				break;
			case 3:
				if(existeRegistro(aviones, TAM_AVION)==0){
					if(bajaAvion(aviones, aerolineas, tipos, TAM_AVION, TAM_HCODE_A, TAM_HCODE_TD)==-1){
						printf("Error al validar punteros o tam menor a cero.\n");
					}
				}else{
					printf("Primero debe registrar un avion.\n");
				}
				break;
			case 4:
				ordenarPorAEyCapacidad(aviones, aerolineas,TAM_HCODE_A,TAM_AVION);
				if(listarAviones(aviones, aerolineas, tipos,TAM_AVION, TAM_HCODE_A, TAM_HCODE_TD)==-1){
					printf("HUbo un error al validar punteros.\n");
				}
				break;
			case 5:

				if(listarAerolineas(aerolineas, TAM_HCODE_A)==-1){
					printf("HUbo un error al validar punteros.\n");
				}
				break;
			case 6:
				if(listarTipos(tipos, TAM_HCODE_TD)==-1){
					printf("HUbo un error al validar punteros.\n");
				}
				break;
			case 7:
				if(listarDestinos(destinos, TAM_HCODE_TD)==-1){
					printf("HUbo un error al validar punteros.\n");
				}
				break;
			case 8:
				if(existeRegistro(aviones, TAM_AVION)==0){
					if(altaVuelo(vuelos, aviones,destinos, aerolineas, tipos, TAM_VUELO,TAM_AVION, TAM_HCODE_TD,TAM_HCODE_A,&idInVuelo, &indexVuelo)==-1){
						printf("Error al validar punteros o tam menor a cero.\n");
					}
				}else{
					printf("Primero debe registrar un avion.\n");
				}
				break;
			case 9:
				if(listarVuelos(vuelos, destinos,TAM_VUELO, TAM_HCODE_TD, indexVuelo)==-1){
					printf("HUbo un error al validar punteros.\n");
				}
				break;
			case 10:
				hardCodearAviones(aviones,TAM_AVION, &idIncrem);
				hardCodearVuelos(vuelos,aviones,TAM_AVION, TAM_VUELO,&indexVuelo, &idInVuelo);
				break;
			case 11:
				listarAvionesPorAerolineaSeleccionado(aviones, aerolineas, tipos,TAM_AVION, TAM_HCODE_A, TAM_HCODE_TD);
				break;
			case 12:
				listarAvionesPorTipoSeleccionado(aviones, aerolineas, tipos,TAM_AVION, TAM_HCODE_A, TAM_HCODE_TD);
				break;
			case 13:
				ListarSeparadoPorAerolinea(aviones, aerolineas, tipos,TAM_AVION, TAM_HCODE_A, TAM_HCODE_TD);
				break;
			case 14:
				MostrarAeroLineaMayorCarga(aviones, aerolineas, tipos,TAM_AVION, TAM_HCODE_A, TAM_HCODE_TD);
				  break;
			case 15:
				listarAerolineaConMenorAviones(aviones, aerolineas, tipos,TAM_AVION, TAM_HCODE_A, TAM_HCODE_TD);
				break;
			case 16:
				listarVuelosConAvionSeleccionado(vuelos, destinos, aviones, aerolineas, tipos,TAM_VUELO, TAM_HCODE_TD, TAM_AVION,TAM_HCODE_A, indexVuelo);

				break;
			case 17:
				listarPrecioTotalViajeUnAvion(vuelos, destinos, aviones, aerolineas, tipos,TAM_VUELO, TAM_HCODE_TD, TAM_AVION,TAM_HCODE_A);
				break;
			case 18:
				listarViajesSeleccionandoUnDestino(vuelos, destinos, aviones, aerolineas, tipos,TAM_VUELO, TAM_HCODE_TD, TAM_AVION,TAM_HCODE_A, indexVuelo);

				 break;
			case 19:
				listarViajesSeleccionandoUnaFecha(vuelos, destinos, aviones, aerolineas, tipos,TAM_VUELO, TAM_HCODE_TD, TAM_AVION,TAM_HCODE_A);

				  break;
			case 20:
				if(!cerrar(&salir)){
					printf("Hubo un problema con la validacion.\n");
				}
				break;
			}
			system("pause");
			system("cls");
		}while(salir!='s');
	return EXIT_SUCCESS;
}
