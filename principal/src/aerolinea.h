/*
 * aerolinea.h
 *
 *  Created on: 11 may. 2022
 *      Author: Jony
 */

#ifndef AEROLINEA_H_
#define AEROLINEA_H_

typedef struct{
	int id;
	char descripcion[20];
}eAerolinea;

#endif /* AEROLINEA_H_ */
void listarAerolinea(eAerolinea aerolinea);
int listarAerolineas(eAerolinea aerolineas[], int tamHCodeA);
int buscarIndexPorIdAerolinea(eAerolinea aerolineas[], int tamA, int id);
