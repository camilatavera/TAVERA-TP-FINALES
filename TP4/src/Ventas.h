/*
 * Ventas.h
 *
 *  Created on: Jun 23, 2021
 *      Author: caami
 */

#ifndef VENTAS_H_
#define VENTAS_H_
#define LEN_STR 128

typedef struct
{
    int id;
    char nombre[128];
    int dia;
    char horario[128];
    int sala;
	int cantEntradas;
	int monto;
}Ventas;


#include "getsDatos.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


Ventas* ventas_new();
Ventas* ventas_newParametros(int id, char* nombre, int dia, char* horario, int sala, int cantEntradas);
Ventas* ventas_newParametrosTxt(char* id, char* nombre, char* dia, char* horario, char* sala, char* cantEntradas);

//int addValores(int *horas, int* sueldo, char *nombre);
int ventas_setValores(Ventas* pVentas, int id, int sueldo, int horas, char* nombre);

int ventas_setId(Ventas* pVentas,int Aid);
int ventas_setIdTxt(Ventas* pVentas,char* Aid);
int ventas_getId(Ventas* pVentas,int* id);

int ventas_setNombre(Ventas* pVentas,char* Anombre);
int ventas_getNombre(Ventas* pVentas,char* nombre);


int ventas_setDia(Ventas* pVentas,int Adia);
int ventas_setTipoTxt(Ventas* pVentas, char* Adia);
int ventas_getDia(Ventas* pVentas,int* dia);
int getDiaStr(int ndia, char* dia);

int ventas_setHorario(Ventas* pVentas,char* Ahorario);
int ventas_getHorario(Ventas* pVentas,char* horario);

int ventas_setSala(Ventas* pVentas,int Asala);
int ventas_setSalaTxt(Ventas* pVentas,char* sala);
int ventas_getSala(Ventas* pVentas,int* sala);

int ventas_setCantEntradas(Ventas* pVentas,int AcantEntradas);
int ventas_setcantEntradasTxt(Ventas* pVentas,char* AcantEntradas);
int ventas_getCantEntradas(Ventas* pVentas,int* cantEntradas);

int ventas_setMonto(Ventas* pVentas, int monto);
int ventas_getMonto(Ventas* pVentas,int* monto);

int ventas_print(Ventas* pVentas);

void printModificaciones(void);




int ventas_delete(Ventas* pVentas);
void calculaMonto(void* pElement);


int printTxt(FILE* fp, Ventas* this);

int entradasSala1(void* pElement);
int entradasSala2(void* pElement);
int entradasSala3(void* pElement);
int entradasSala4(void* pElement);
int entradasSala5(void* pElement);

int montoSala1(void* pElement);
int montoSala2(void* pElement);
int montoSala3(void* pElement);
int montoSala4(void* pElement);
int montoSala5(void* pElement);

int nombreSala1(void* pElement);
int nombreSala2(void* pElement);
int nombreSala3(void* pElement);
int nombreSala4(void* pElement);
int nombreSala5(void* pElement);



int list_nombresFiltrados(Ventas *pElement);







/*
 * int addValoresAModificar(int *opcion, char *ingresoChar, int *ingresoInt);
int ventas_setModificaciones(Ventas* this);
int ventas_criterioSueldo( void* item1, void* item2);
int ventas_criterioId( void* item1, void* item2);
int ventas_criterioNombre(void* item1, void* item2);
int ventas_criterioHoras( void* item1, void* item2);

*/

#endif /* VENTAS_H_ */
