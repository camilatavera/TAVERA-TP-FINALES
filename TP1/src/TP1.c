/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "menu.h"
#include "validar.h"

int main(void) {
	setbuf(stdout,NULL);
	float x=0;
	float y=0;

	int opcionIngresada;

	float resSuma;
	float resResta;
	float resDivision;
	float resMultiplicacion;
	long int resFacx;
	long int resFacy;

	int flagOpcion1=1;
	int flagOpcion2=1;
	int flagOpcion3=1;

	do{
		mostrarMenu(x, y);
		ingresarOpcion(&opcionIngresada, "Ingrese la opcion deseada: ", "ERROR\n", 1, 5);
		switch(opcionIngresada){
					case 1:
						utn_getNumero(&x, "Ingrese el primer operando: ", "ERROR\n");
						flagOpcion1=0;
						break;
					case 2:
						utn_getNumero(&y, "Ingrese el segundo operando: ", "ERROR\n");
						flagOpcion2=0;
						break;
					case 3:
						if(flagOpcion1==0 && flagOpcion2==0){
							operaciones(x, y, &resSuma, &resResta, &resDivision, &resMultiplicacion, &resFacx, &resFacy);
							flagOpcion3=0;
						}
						else{
							printf("Primero debe ingresar los operandos\n");
						}
						break;
					case 4:
						if(flagOpcion3==0){
							informarResultados(x, y, resSuma, resResta, resDivision, resMultiplicacion, resFacx, resFacy);
						}
						else{
							printf("Primero debe realizar las operaciones\n");
						}
						break;
		}
	}while(opcionIngresada!=5);

		printf("Saliste del programa\n");

	}









