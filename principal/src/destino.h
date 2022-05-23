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
/// @brief muestra en forma encolumnada una estructura eDestino.
///
/// @param destinos
void listarDestino(eDestino destinos);
/// @brief muestra en forma encolumnada un array de estructura eDestino.
///
/// @param destinos
/// @param tamHCodeTD
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int listarDestinos(eDestino destinos[], int tamHCodeTD);
/// @brief  busca el index que corresponde al ID paasdo por parametro, dentro del array estructura eDestino
///
/// @param destinos
/// @param tamTD
/// @param id
/// @return retorna -1: no existe el id. retorna Numero: el index correspondiente el ID
int buscarIndexPorIdDestino(eDestino destinos[], int tamTD, int id);
