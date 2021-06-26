/*
 * tp1.h
 *
 *  Created on: Apr 5, 2021
 *      Author: camilatavera
 *      PROTOTIPOS
 *
 *
 */



#ifndef BIBLOTP1_H_
#define BIBLOTP1_H_

int mostrarMenu(float A, float B);
/*
 * Muestra el menu principal con los valores que recibe como parametro.
 * Devuelve 0
 */


int operaciones(float A, float B, float *suma, float *resta, float *division, float *multiplicacion, long int *factorialA, long int *factorialB);
/*
 * Llama a otras funciones que realizan las operaciones.
 * Si se ejecuta correctamente devuelve 0
 */

int informarResultados(float A, float B, float suma, float resta, float division, float multiplicacion, int factorialA, int factorialB);
/*
 * Muestra los valores de los operando que recibio como parametro, y los resultados
 * de las operaciones.
 * Si se ejecuta correctamente devuelve 0.
 */




#endif /* BIBLOTP1_H_ */
