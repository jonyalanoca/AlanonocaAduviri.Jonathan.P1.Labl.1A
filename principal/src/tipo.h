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
void listarTipo(eTipo tipos);
int listarTipos(eTipo tipos[], int tamHCodeTD);
int buscarIndexPorIdTipo(eTipo tipos[], int tamTD, int id);
