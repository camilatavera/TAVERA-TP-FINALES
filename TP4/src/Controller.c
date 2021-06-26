/*
 * Controller.c
 *
 *  Created on: Jun 23, 2021
 *      Author: caami
 */

#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArray)
{
	int ret=-1;
	FILE* fp=NULL;

	if(path!=NULL && pArray!=NULL ){

		fp=fopen(path, "r");

		if(fp!=NULL){
			parser_EmployeeFromText(fp, pArray);
			fclose(fp);
			ret=0;
		}
	}
    return  ret;;
}


int controller_ListVentas(LinkedList* pArray)
{
	int ret=-1;
	Ventas* pVentas;
	int i;

	int id;
	char nombre[LEN_STR];
	int ndia;
	char dia[LEN_STR];
	char horario[LEN_STR];
	int sala;
	int cantEntradas;

	if(pArray!=NULL){

		if(ll_len(pArray)==0){
			printf("No hay empleados ingresados al sistema \n");
		}
		else{
			ret=0;
			printf("Id    Nombre                              Dia      Horario  Sala    Cant Entradas \n");

			for(i=0; i<ll_len(pArray); i++){
				pVentas=ll_get(pArray, i);

				if(ventas_getId(pVentas, &id)==0 && ventas_getNombre(pVentas, nombre)==0 && ventas_getDia(pVentas, &ndia)==0 &&
						getDiaStr(ndia, dia)==0 && ventas_getHorario(pVentas, horario)==0 &&
						ventas_getSala(pVentas, &sala)==0 && ventas_getCantEntradas(pVentas, &cantEntradas)==0){


					printf("%-5d %-35s %-8s %-8s %-8d %d  \n", id, nombre, dia, horario, sala, cantEntradas);
				}

			}//cierro for


		}
	}
	return ret;

}

int controller_saveAsText(char* path , LinkedList* pArray){
	int ret=-1;
	FILE* fp;
	Ventas* pVentas;

	if(path!=NULL && pArray!=NULL){

		if(ll_len(pArray)==0){
			printf("No hay datos cargados \n");
		}
		else{
			ll_map(pArray, calculaMonto);
			fp=fopen(path, "w");
			if(fp!=NULL){
				fprintf(fp, "id_venta,nombre_pelicula,dia,horario,sala,cantidad_entradas,monto\n");

				for(int i=0; i<ll_len(pArray); i++){
					pVentas=ll_get(pArray, i);
					if(pVentas!=NULL){
						printTxt(fp, pVentas);
					}
				}
				fclose(fp);
				ret=0;
			}
		}
	}
    return ret;
}

int controller_Informes(LinkedList* pArray){

	int ret=-1;
	int opSala;


	int totalEntradas=0;
	int totalMonto=0;
	LinkedList* ll_filtrada=NULL;
	Ventas* auxVenta=NULL;


	if(pArray!=NULL && getNumero(&opSala, "Ingrese sale de 1 a 5 \n", "Error. ", 1, 5, 20)==0){

		ret=0;

		switch(opSala){
		case 1:
			totalEntradas=ll_count(pArray, entradasSala1);
			totalMonto=ll_count(pArray, montoSala1);
			ll_filtrada=ll_filter(pArray, nombreSala1);
			break;
		case 2:
			totalEntradas=ll_count(pArray, entradasSala2);
						totalMonto=ll_count(pArray, montoSala2);
						ll_filtrada=ll_filter(pArray, nombreSala2);
			break;
		case 3:
			totalEntradas=ll_count(pArray, entradasSala3);
						totalMonto=ll_count(pArray, montoSala3);
						ll_filtrada=ll_filter(pArray, nombreSala3);
			break;
		case 4:
			totalEntradas=ll_count(pArray, entradasSala4);
						totalMonto=ll_count(pArray, montoSala4);
						ll_filtrada=ll_filter(pArray, nombreSala4);
			break;
		case 5:
			totalEntradas=ll_count(pArray, entradasSala5);
						totalMonto=ll_count(pArray, montoSala5);
						ll_filtrada=ll_filter(pArray, nombreSala5);
			break;
		}


		printf("SALA %d  \n", opSala);
		printf("Cantidad de entradas vendidas: %d \n", totalEntradas);
		printf("Monto total facturado:  %d \n", totalMonto);
		printf("LISTADO DE PELICULAS:  \n");

		for(int i=0; i<ll_len(ll_filtrada); i++){

			auxVenta=ll_get(ll_filtrada, i);
			if(auxVenta!=NULL){
				list_nombresFiltrados(auxVenta);
			}

		}



	}
	return ret;
}

