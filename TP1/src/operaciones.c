/*
 * operaciones.c
 *
 *  Created on: Apr 14, 2021
 *      Author: camilatavera
 */

#include "validar.h"
#include "operaciones.h"

int sumar(float A, float B, float *resSuma){
	int ret=-1;
	if(resSuma!=NULL){
		*resSuma=A+B;
		ret=0;
	}
	return ret;
}
int restar(float A, float B, float *resResta){
	int ret=-1;
	if(resResta!=NULL){
		*resResta=A-B;
		ret=0;
	}
	return ret;
}
int multiplicar(float A, float B, float *resMultiplicar){
	int ret=-1;
	if(resMultiplicar){
		*resMultiplicar=A*B;
		ret=0;
	}
	return ret;
}



int factorial(float numero, long int *resFactorial){
	int ret=-1;
	if(resFactorial!=NULL){

		if (numero>0 && esEntero(numero)==0){
			ret=0;
			int fac=1;
			for(int i=1; i<=numero; i++){
				fac*=i;
			}
			*resFactorial=fac;
		}
	}
		return ret;
}

int dividir(float A, float B, float *resDivision){
	int ret=-1;
	if(resDivision!=NULL){
		if(B>0){
			*resDivision=A/B;
			ret=0;
		}
	}//cierrro validacion de punteros
	return ret;
}

