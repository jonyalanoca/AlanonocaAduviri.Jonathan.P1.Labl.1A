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
/// @brief mestra una estructura en forma encolumnada.
///
/// @param aerolinea
void listarAerolinea(eAerolinea aerolinea);
/// @brief muestra una  array de estructura en forma encolumnada
///
/// @param aerolineas
/// @param tamHCodeA
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int listarAerolineas(eAerolinea aerolineas[], int tamHCodeA);
/// @brief Busca la posicion del index del ID pasado por parametro, dentro del  array estructura.
///
/// @param aerolineas
/// @param tamA
/// @param id
/// @return retorna -1: error con punteros o tam menor  o no se encontro el id a 0. retorna en numero de index
int buscarIndexPorIdAerolinea(eAerolinea aerolineas[], int tamA, int id);
