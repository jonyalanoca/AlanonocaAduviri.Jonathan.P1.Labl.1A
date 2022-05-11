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
	printf("  [9]  LISTAR VUELOS.\n");

	printf("  [10]  Salir.\n");
	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,10)){
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
