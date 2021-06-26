/*
 * validar.h
 *
 *  Created on: Apr 15, 2021
 *      Author: caami
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef VALIDAR_H_
#define VALIDAR_H_



int ingresarOpcion(int* numero, char* mensaje, char* mensajeError, int minimo, int maximo);
/*
 * Permite al usuario ingresar la opcion de menu y valida que sea un int y que este
 * en el rango de opciones.
 * Si se ejecuta correctamente devuelve 0.
 *
 */

int utn_getNumero(float* numero, char* mensaje, char* mensajeError);
/*
 * Permite al usuario ingresar un numero (los operandos) y valida que sean numeros.
 * Si se ejecuta correctamente devuelve 0
 */

int esEntero(float numero)	;
/*
 * Recibe un numero flotante como parametro. Evalua si tiene parte decimal.
 * Si no tiene parte decimal me devuelve 0.
 * Si tiene parte decimal me devuelve 1
 */






#endif /* VALIDAR_H_ */
