/*
 * destino.h
 *
 *  Created on: 11 may. 2022
 *      Author: Jony
 */

#ifndef DESTINO_H_
#define DESTINO_H_

typedef struct{
	 int id;
	 char descripcion[25];
	 float precio;

}eDestino;

#endif /* DESTINO_H_ */
void listarDestino(eDestino destinos);
int listarDestinos(eDestino destinos[], int tamHCodeTD);
int buscarIndexPorIdDestino(eDestino destinos[], int tamTD, int id);
