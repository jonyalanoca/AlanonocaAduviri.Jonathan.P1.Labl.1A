#include "tipo.h"
#include "aerolinea.h"
#ifndef AVION_H_
#define AVION_H_



typedef struct{
	int id;
	int idAeroLinea;
	int idTipo;
	int capacidad;
	int isEmpty;
}eAvion;
#endif /* AVION_H_ */
/// @brief pone isEmpty=1 en todos los elementos del array idicando que estan libres
///
/// @param aviones
/// @param tamAvion
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int inicializarArray(eAvion aviones[], int tamAvion);
/// @brief busca el primer isEmpty =1 informando que esta disponible para usarlo.
///
/// @param aviones
/// @param tamAvion
/// @return retorna -1: error con punteros o tam menor a 0 o la lista esta llena.
/// 		retorna numero: el numero de index libre
int buscarIndexLibre(eAvion aviones[], int tamAvion);
/// @brief indica si nuestra lista tiene algun elemento guardado
///
/// @param aviones
/// @param tamAvion
/// @return  retorma 0: si hay algun elemento, retorna 1: si la lista esta vacia.
int existeRegistro(eAvion aviones[], int tamAvion);
/// @brief  muestra una estructura en foma encolumnada.
///
/// @param aviones
/// @param aerolineas
/// @param tipos
/// @param tamA
/// @param tamTD
void listarAvion(eAvion aviones,eAerolinea aerolineas[], eTipo  tipos[], int tamA, int tamTD);
/// @brief mustra en array de estructura en forma enculumnada. llamando a la funcion listarAvion
///
/// @param aviones
/// @param aerolienas
/// @param tipos
/// @param tamAviones
/// @param tamA
/// @param tamTD
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int listarAviones(eAvion aviones[],eAerolinea aerolienas[], eTipo  tipos[], int tamAviones, int tamA, int tamTD);
/// @brief  permite modificar un registro preiamente cargado, cuenta con un menu y validaciones
///
/// @param aviones
/// @param aerolineas
/// @param tipos
/// @param tamAvion
/// @param tamA
/// @param tamTD
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int modificarAvion(eAvion aviones[],eAerolinea aerolineas[],eTipo tipos[], int tamAvion, int tamA, int tamTD);
/// @brief permite dar de baja logica  a un regitro previamente cargado.
///
/// @param aviones
/// @param aerolineas
/// @param tipos
/// @param tamAvion
/// @param tamA
/// @param tamTD
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int bajaAvion(eAvion aviones[],eAerolinea aerolineas[],eTipo tipos[], int tamAvion, int tamA, int tamTD);
/// @brief permite dar de alta un avion, cuenta con validaciones y carga de forma segura al array de estructura.
///
/// @param aviones
/// @param aerolineas
/// @param tipos
/// @param tamAviones
/// @param tamTD
/// @param tamA
/// @param idAviones
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int altaAvion(eAvion aviones[], eAerolinea aerolineas[], eTipo tipos[],int  tamAviones, int tamTD, int tamA, int* idAviones);
/// @brief pide y valida los datos que van a ser ingresados posteriormente en el array de estructura.
///
/// @param aerolineas
/// @param tipos
/// @param tamTD
/// @param tamA
/// @param idAerolinea
/// @param idTipo
/// @param capacidad
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int validarDatos(eAerolinea aerolineas[], eTipo tipos[], int tamTD,int tamA, int* idAerolinea, int* idTipo, int* capacidad );
/// @brief busca el index del ID pasado por parametro, dentro del array de estructura, y lo devuelve
///
/// @param aviones
/// @param tamAvion
/// @param id
/// @return retorna -1: si el ID no existe, retorma Numero:  el numero de index correspondiente al id.
int buscarIndexPorIdAvion(eAvion aviones[], int tamAvion, int id);
/// @brief carga de forma segura a los datos al array de esctructura
///
/// @param aviones
/// @param tamAviones
/// @param idAviones
/// @param idAerolinea
/// @param idTipo
/// @param capacidad
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int cargarDatos(eAvion aviones[], int tamAviones, int* idAviones, int idAerolinea, int idTipo, int capacidad);
/// @brief ordena el array de estructura eAviones primeramente por Aerolineas, en caso de conicidencia: por capacidad en
///
/// @param aviones
/// @param aerolineas
/// @param tamA
/// @param tamAviones
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int ordenarPorAEyCapacidad(eAvion* aviones,eAerolinea aerolineas[],int tamA,int tamAviones);
/* Nuevas funciones   */
/// @brief carga de forma automatica valores al array estructura eAviones.
///
/// @param aviones
/// @param tamAviones
/// @param idAviones
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int hardCodearAviones(eAvion aviones[],int tamAviones, int* idAviones);
/// @fn int listarAvionesPorAerolineaSeleccionado(eAvion[], eAerolinea[], eTipo[], int, int, int)
/// @brief  se selecciona una aerolinea y se muestra en forma ecolumnada el array de estructura eAviones que complan la condicion
/// @param aviones
/// @param aerolineas
/// @param tipos
/// @param tamAviones
/// @param tamA
/// @param tamTD
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int listarAvionesPorAerolineaSeleccionado(eAvion aviones[],eAerolinea aerolineas[], eTipo  tipos[], int tamAviones, int tamA, int tamTD);
/// @fn int listarAvionesPorColorSeleccionado(eAvion[], eAerolinea[], eTipo[], int, int, int)
/// @brief Se selecciona un color luego se muestra en forma encolumnada los el array estructura eAvion que cumplan la condicion.
/// @param aviones
/// @param aerolineas
/// @param tipos
/// @param tamAviones
/// @param tamA
/// @param tamTD
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int listarAvionesPorTipoSeleccionado(eAvion aviones[],eAerolinea aerolineas[], eTipo  tipos[], int tamAviones, int tamA, int tamTD);
/// @fn int ListarSeparadoPorAerolinea(eAvion*, eAerolinea[], eTipo[], int, int, int)
/// @brief lista  las aero lineas de forma saparada
/// @param aviones
/// @param aerolineas
/// @param tipos
/// @param tamA
/// @param tamAviones
/// @param tamTD
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int ListarSeparadoPorAerolinea(eAvion* aviones,eAerolinea aerolineas[], eTipo tipos[],int tamA,int tamAviones, int tamTD);

/// @fn int MostrarAeroLineaMayorCarga(eAvion[], eAerolinea[], eTipo[], int, int, int)
/// @brief muestra en forma encolumnada los aviones con la aerolinea con mayor cantidad de capacidades
/// @param aviones
/// @param aerolineas
/// @param tipos
/// @param tamAviones
/// @param tamA
/// @param tamTD
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int MostrarAeroLineaMayorCarga(eAvion aviones[],eAerolinea aerolineas[], eTipo  tipos[], int tamAviones, int tamA, int tamTD);
/// @brief muestra la aerolineas menos usada
///
/// @param aviones
/// @param aerolineas
/// @param tipos
/// @param tamAviones
/// @param tamA
/// @param tamTD
/// @return retorna -1: error con punteros o tam menor a 0. retorna 0: si todo salio bien.
int listarAerolineaConMenorAviones(eAvion aviones[],eAerolinea aerolineas[], eTipo  tipos[], int tamAviones, int tamA, int tamTD);
