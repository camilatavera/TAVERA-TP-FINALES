/*
 * validar.c
 *
 *  Created on: Apr 15, 2021
 *      Author: caami
 */
#include "validar.h"

int ingresarOpcion(int* numero, char* mensaje, char* mensajeError, int minimo, int maximo){
	//
	 int ret;
	 int num;
	 int reintentar=-1;

	 if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL){
	 while(reintentar) {
		 printf("%s", mensaje);
		 if(scanf("%d",&num)==1 && (num<=maximo && num>=minimo))
		 {
		 	 *numero = num;
		 	 ret=0;
			 reintentar=0;
			 break;
		 }
		 else{
			 fflush(stdin);
			 printf("%s", mensajeError);
		 }
	 }//cierro while.
	 }//cierro la validacion de los punteros.

	 return ret;
}


int utn_getNumero(float* numero, char* mensaje, char* mensajeError){

	 int ret=-1;
	 float num;
	 int reintentar=1;

	 if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL){
	 while(reintentar){
		 printf("%s", mensaje);
		 if(scanf("%f",&num)==1)
		 {
			 reintentar=0;
			 *numero=num;
			 ret=0;
		 }
		 else
		 {
			 fflush(stdin);
			 printf("%s", mensajeError);
		 }
	 }//cierro while
	 }//cierro la validacion de los punteros.

	return ret;
}

int esEntero(float numero){

	int ret=1;
	float parteDecimal;
	parteDecimal=numero-(int)numero;

	if(parteDecimal==0){
		ret=0;
	}
	return ret;
}



