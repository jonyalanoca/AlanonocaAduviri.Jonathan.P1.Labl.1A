/*
 * validaciones.h
 *
 *  Created on: 25 abr. 2022
 *      Author: Jony
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */
/// @fn int cargarValidarCharEntreDos(char[], char*, char, char)
/// @brief  pide y valida que sea un char igual al parametro 3y4 y lo guarda en el puntero char. Informa si se ingresa un valor erroneo
///
/// @param mensaje
/// @param varChar
/// @param letra1
/// @param letra2
/// @return retorna 0 para puntero nulo , 1 si todo salio bien.
///
int cargarValidarCharEntreDos(char mensaje[],char* varChar, char letra1, char letra2);
/// @fn int cargarValidarChar(char[], char*)
/// @brief pide y valida que sea un char y lo guarda en el puntero letra. Informa si se ingresa un valor erroneo
///
/// @param mensaje
/// @param letra
/// @return retorna 0 para puntero nulo , 1 si todo salio bien.
int cargarValidarChar(char mensaje[], char* letra);
/// @fn int cargarValidarCadena(char[], int, char[])
/// @brief pide y valida que sea un string y lo guarda en el puntero string. Informa si se ingresa un valor erroneo
///
/// @param mensaje
/// @param tam
/// @param string
/// @return retorna 0 para puntero nulo o len invalido, 1 si todo salio bien.
int cargarValidarCadena(char mensaje[], int tam, char string[]);
/// @fn int cargarValidarAlfaNumerico(char[], int, char[])
/// @brief pide y valida que solo contenga valores alfanumericos y lo guarda en el puntero string. Informa si se ingresa un valor erroneo
///
/// @param mensaje
/// @param tam
/// @param string
/// @return retorna 0 para puntero nulo o len invalido, 1 si todo salio bien.
int cargarValidarAlfaNumerico(char mensaje[], int tam, char string[]);
/// @fn int cargarValidarEntero(char[], int*)
/// @brief pide y valida que sea un numero entero y lo guarda en el puntero pNumero. Informa si se ingresa un valor erroneo
///
/// @param mensaje
/// @param pNumero
/// @return retorna 0 para puntero nulo, 1 si todo salio bien.
int cargarValidarEntero(char mensaje[],int* pNumero);
/// @fn int cargarValidarEnteroPositivo(char[], int*)
/// @brief pide y valida que sea un numero entero positivo y lo guarda en el puntero pNumero. Informa si se ingresa un valor erroneo
///
/// @param mensaje
/// @param pNumero
/// @return retorna 0 para puntero nulo, 1 si todo salio bien.
int cargarValidarEnteroPositivo(char mensaje[],int* pNumero);
/// @fn int cargarValidarDecimal(char[], float*)
/// @brief pide y valida que sea un numero decimal y lo guarda en el puntero varNumero. Informa si se ingresa un valor erroneo
///
/// @param mensaje
/// @param varNumero
/// @return retorna 0 para puntero nulo, 1 si todo salio bien.
int cargarValidarDecimal(char mensaje[], float* varNumero);
/// @fn int cargarValidarDecimalPositivo(char[], float*)
/// @brief pide y valida que sea un numero decimal positivo y lo guarda en el puntero varNumero. Informa si se ingresa un valor erroneo
///
/// @param mensaje
/// @param varNumero
/// @return retorna 0 para puntero nulo, 1 si todo salio bien.
int cargarValidarDecimalPositivo(char mensaje[], float* varNumero);
/// @fn int borrarBarraN(char[])
/// @brief  cumple la funcion de borrar el '\n' que queda guardado en el string al cagar una cadena con la funcion fgets
///
/// @param string
/// @return retorna 0 para puntero nulo, 1 si todo salio bien.
int borrarBarraN(char string[]);
/// @fn int capitalizar(char[])
/// @brief primero transforma la cadena en minuscula luego tranforma el primer caracter en mayuscula
///
/// @param varString
/// @return retorna 0 para puntero nulo, 1 si todo salio bien.
int capitalizar(char varString[]);
/// @fn int enteroEnRango(char[], int*, int, int)
/// @brief	pide y valida que sea un numero entero luego valida que este entre el rango comprendidos en los paramentros 3y4,
/// 		Lo guarda en el puntero pNumero.
/// 		Informa si se ingresa un valor erroneo
///
/// @param mensaje
/// @param pNumero
/// @param numero1
/// @param numero2
/// @return retorna 0 para puntero nulo, 1 si todo salio bien.
int enteroEnRango(char mensaje[], int* pNumero,int numero1, int numero2);
int cargarValidarFecha(int* dia,int* mes,int* anio);
