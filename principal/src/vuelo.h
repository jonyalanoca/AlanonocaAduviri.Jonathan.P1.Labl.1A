#include "destino.h"
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#ifndef VUELO_H_
#define VUELO_H_

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int id;
	int idAvion;
	int idDestino;
	eFecha fecha;
}eVuelo;

#endif /* VUELO_H_ */
void listarVuelo(eVuelo vuelos, eDestino destinos[],int tamTD);
int listarVuelos(eVuelo vuelos[], eDestino destinos[],int tamVuelo,int tamTD,int lenVuelos );





int altaVuelo(eVuelo vuelos[], eAvion aviones[], eDestino destinos[],eAerolinea aerolineas[], eTipo tipos[],  int tamVuelos,int tamAviones, int tamTD, int tamA, int* idVuelo, int* indexVuelo);
