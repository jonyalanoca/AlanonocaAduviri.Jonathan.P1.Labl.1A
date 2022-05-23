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
/// @brief  muestra en forma encoumanda los valores de una estructura eVuelo
///
/// @param vuelos
/// @param destinos
/// @param tamTD
void listarVuelo(eVuelo vuelos, eDestino destinos[],int tamTD);
/// @brief muestra en forma encoumnada los valores de un array de estructura eVuelo
///
/// @param vuelos
/// @param destinos
/// @param tamVuelo
/// @param tamTD
/// @param lenVuelos
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int listarVuelos(eVuelo vuelos[], eDestino destinos[],int tamVuelo,int tamTD,int lenVuelos );
/// @brief pide datos, valida y carga de forma segura en un array estructura eVuelo
///
/// @param vuelos
/// @param aviones
/// @param destinos
/// @param aerolineas
/// @param tipos
/// @param tamVuelos
/// @param tamAviones
/// @param tamTD
/// @param tamA
/// @param idVuelo
/// @param indexVuelo
/// @return  retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int altaVuelo(eVuelo vuelos[], eAvion aviones[], eDestino destinos[],eAerolinea aerolineas[], eTipo tipos[],  int tamVuelos,int tamAviones, int tamTD, int tamA, int* idVuelo, int* indexVuelo);
/// @brief  cargalos datos a la estructura eVuelos de forma segura
///
/// @param vuelos
/// @param tamVuelos
/// @param indexVuelo
/// @param idVuelo
/// @param idAvion
/// @param idDestino
/// @param dia
/// @param mes
/// @param anio
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int cargarVuelos(eVuelo vuelos[], int tamVuelos,int* indexVuelo, int* idVuelo,int idAvion, int idDestino, int dia, int mes, int anio);
/// @brief hardCodea 10 registros de forma aleatoria y los caraga en el array estructura eVuelos
///
/// @param vuelos
/// @param aviones
/// @param tamAviones
/// @param tamVuelos
/// @param indexVuelo
/// @param idVuelo
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int hardCodearVuelos(eVuelo vuelos[],eAvion aviones[], int tamAviones, int tamVuelos, int* indexVuelo, int* idVuelo);

/// @fn int listarVuelosConAvionSeleccionado(eVuelo[], eDestino[], eAvion[], eAerolinea[], eTipo[], int, int, int, int)
/// @brief  se selecciona un avion y se muetra el array estructura eVuelo que cumplen la condicion
/// @param vuelos
/// @param destinos
/// @param aviones
/// @param aerolineas
/// @param tipos
/// @param tamVuelos
/// @param tamTD
/// @param tamAviones
/// @param tamA
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int listarVuelosConAvionSeleccionado(eVuelo vuelos[], eDestino destinos[],eAvion aviones[], eAerolinea aerolineas[], eTipo tipos[], int tamVuelos,int tamTD,int tamAviones , int tamA,int lenVuelos);
/// @fn int listarPrecioTotalViajeUnAvion(eVuelo[], eDestino[], eAvion[], eAerolinea[], eTipo[], int, int, int, int)
/// @brief  se elije un avion y se suma los precios. se muestra en forma encolumnada el array eVeulo que cumplan la condicion tambien el precio total.
/// @param vuelos
/// @param destinos
/// @param aviones
/// @param aerolineas
/// @param tipos
/// @param tamVuelos
/// @param tamTD
/// @param tamAviones
/// @param tamA
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int listarPrecioTotalViajeUnAvion(eVuelo vuelos[], eDestino destinos[],eAvion aviones[], eAerolinea aerolineas[], eTipo tipos[], int tamVuelos,int tamTD,int tamAviones , int tamA);
/// @brief  pide un destino y muetra la lista con el destino seleccionado
///
/// @param vuelos
/// @param destinos
/// @param aviones
/// @param aerolineas
/// @param tipos
/// @param tamVuelos
/// @param tamTD
/// @param tamAviones
/// @param tamA
/// @param lenVuelos
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int listarViajesSeleccionandoUnDestino(eVuelo vuelos[], eDestino destinos[],eAvion aviones[], eAerolinea aerolineas[], eTipo tipos[], int tamVuelos,int tamTD,int tamAviones , int tamA,int lenVuelos);
/// @brief selecciona una fecha y filtra la lista con la fecha seleccionada
///
/// @param vuelos
/// @param destinos
/// @param aviones
/// @param aerolineas
/// @param tipos
/// @param tamVuelos
/// @param tamTD
/// @param tamAviones
/// @param tamA
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int listarViajesSeleccionandoUnaFecha(eVuelo vuelos[], eDestino destinos[],eAvion aviones[], eAerolinea aerolineas[], eTipo tipos[], int tamVuelos,int tamTD,int tamAviones , int tamA);
