/*
 * menus.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "validaciones.h"
int menu(void){
	int opcion;
	printf("----------------------------------------\n");
	printf(" \t..........[MENU PRINCIPAL]...........\n");
	printf("========================================\n\n");
	printf("  [1]  ALTA AVION.\n");
	printf("  [2]  MODIFICAR AVION.\n");
	printf("  [3]  BAJA AVION.\n");
	printf("  [4]  LISTAR AVION.\n");
	printf("  [5]  LISTAR AEROLINEA.\n");
	printf("  [6]  LISTAR TIPOS.\n");
	printf("  [7]  LISTAR DESTINOS.\n");
	printf("  [8]  ALTA VUELO.\n");
	printf("  [9]  LISTAR AVIONES.\n");
	printf("  [10]  [BONUS] HARDCODEAR AVIONES Y VUELOS!!!.\n");
	printf("  [11]  LISTAR AVIONES DE AEROLINEA SELECCIONADO.\n");
	printf("  [12]  LISTAR AVIONES DE TIPO SELECCIONADO.\n");
	printf("  [13]  LISTAR AVIONES SEPARADOS POR AEROLINEAS.\n");
	printf("  [14]  INFORMAR LA AEROLINEA QUE PUEDE TRANSPORTAR MAS PASAJEROS.\n");
	printf("  [15]  MOSTRAR LA AEROLINEA CON MENOR CANTIDAD DE AVIONES.\n");
	printf("  [16]  LISTAR VUELOS CON AVION SELECCIONADO.\n");
	printf("  [17]  Pedir un avion e informar la suma de los precios (costo) de todos los vuelos que realizo..\n");
	printf("  [18]  Pedir un destino y mostrar los aviones que volaron a ese destino y en qué fecha..\n");
	printf("  [19]  Pedir una fecha y mostrar todos los vuelos realizados en la misma..\n");


	printf("  [20]  Salir.\n");
	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,20)){
		printf("Algo ha salido mal.\n");
	}
	return opcion;
}
int menuModificar(void){
	int opcion;
	system("cls");
	printf("----------------------------------------\n");
	printf(" \t...........[MENU MODIFICAR]..........\n");
	printf("========================================\n\n");
	printf("  [1]MODIFICAR LA AEROLINE DEL AVION .\n");
	printf("  [2]MODIFICAR EL TIPO DEL AVION .\n");
	printf("  [3]MODIFICAR LA CAPACIDAD DEL AVION.\n");

	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,3)){
		printf("Algo ha salido mal.\n");
	}
	return opcion;
}
int menuInformes(void){
	int opcion;
	system("cls");
	printf("----------------------------------------\n");
	printf(" \t............[MENU DE INFORMES].......\n");
	printf("========================================\n\n");
	printf("  [1]  Litas pasajeros.\n");
	printf("  [2]  Listar por apellido y tipo de pasajero.\n");
	printf("  [3]  Listar por codigo de vuelo y estado de vuelo (ACTIVO).\n");
	printf("  [4]  Listar pasajeros superando el precio promedio.\n");
	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,4)){
		printf("Algo ha salido mal.\n");
	}
	return opcion;
}
int ascendenteDescendente(void){
	int opcion;
	system("cls");
	printf("----------------------------------------\n");
	printf(" \t..[TIPO DE ORDENAMIENTO]..\n");
	printf("========================================\n\n");
	printf("  [1]  Ordenar ascendente.\n");
	printf("  [2]  Ordenar descendente\n");

	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,2)){
		printf("Algo ha salido mal.\n");
	}
	return opcion;
}
