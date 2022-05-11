/*
 * otros.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Jony
 */

#include <stdio.h>
#include <stdlib.h>
#include "otros.h"
#include <ctype.h>
#include <time.h>

int cerrar(char* pSalir){
	int todoOk=0;
	if(pSalir!=NULL){
		system("cls");
		printf("ATENCION.\nEsta por salir del programa.\nPara confirmar presione (s): ");
		fflush(stdin);
		scanf("%c", pSalir);

		*pSalir=tolower(*pSalir);
		todoOk=1;
	}
	return todoOk;
}
int numeroRandom(int numero1, int numero2){
	srand(time(NULL));
	return rand() %(numero2 - numero1 +1)+numero1;
}
