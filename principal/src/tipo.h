/*
 * tipo.h
 *
 *  Created on: 11 may. 2022
 *      Author: Jony
 */

#ifndef TIPO_H_
#define TIPO_H_
typedef struct{
	int id;
	char descripcion[20];
}eTipo;


#endif /* TIPO_H_ */
/// @brief muestra en forma encolumnada una estructura eTipo
///
/// @param tipos
void listarTipo(eTipo tipos);
/// @brief muestra en forma enculumnada un array de estructura eTipo
///
/// @param tipos
/// @param tamHCodeTD
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int listarTipos(eTipo tipos[], int tamHCodeTD);
/// @brief busca el index correspondiente el ID pasado por parametro, dentro del array de estructura eTipo
///
/// @param tipos
/// @param tamTD
/// @param id
/// @return retorna -1: no existe el id. retorna numero: el index correspondiente el id.
int buscarIndexPorIdTipo(eTipo tipos[], int tamTD, int id);
