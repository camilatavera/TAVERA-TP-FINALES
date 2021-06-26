/*
 * biblotp1.c
 *
 *  Created on: Apr 5, 2021
 *      Author: caami
 */
#include "menu.h"
#include "operaciones.h"
#include "validar.h"

int mostrarMenu(float A, float B){
	printf("1.Ingresar primer operando (A=%f)\n2. Ingresar segundo operando (B=%f)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n", A, B);
	return 0;
}


int operaciones(float A, float B, float *suma, float *resta, float *division, float *multiplicacion, long int *factorialA, long int *factorialB){
	int ret=-1;

	if(suma!=NULL && resta!=NULL && division!=NULL && multiplicacion!=NULL && factorialA!=NULL && factorialB!=NULL){
		//*suma=A+B;
		float resSuma;
		sumar(A, B, &resSuma);
		*suma=resSuma;

		//*resta=A-B;
		float resResta;
		restar(A, B, &resResta);
		*resta=resResta;

		//*multiplicacion=A*B;
		float resMultiplicar;
		multiplicar(A, B, &resMultiplicar);
		*multiplicacion=resMultiplicar;

		long int resFactorialA;
		long int resFactorialB;
		factorial(A, &resFactorialA);
		factorial(B, &resFactorialB);
		*factorialA=resFactorialA;
		*factorialB=resFactorialB;

		float resDiv;
		dividir(A, B, &resDiv);
		*division=resDiv;

		ret=0;
	}
	return ret;
}

int informarResultados(float A, float B, float suma, float resta, float division, float multiplicacion, int factorialA, int factorialB){
	printf("a)El resultado de %f + %f es: %f\n", A, B, suma);
	printf("b) El resultado de %f - %f  es: %f \n", A, B, resta);

	float validarDiv;
	if(dividir(A, B, &validarDiv)==0){
		printf("c) El resultado de %f / %f es: %f \n", A, B, division);
	}
	else{
		printf("c) No es posible realizar la division\n");
	}

	printf("El resultado de %f * %f es: %f \n", A, B, multiplicacion);

	long int validarFac;
	if(factorial(A, &validarFac)==0){
		printf("El factorial del primer operando es %d\n", factorialA);
	}
	else{
		printf("No es posible calcular el factorial del primer operando\n");
				//hago lo mismo con B
	}
	if(factorial(B, &validarFac)==0){
			printf("El factorial del segundo operando es %d\n", factorialB);
	}
	else{
		printf("No es posible calcular el factorial del segundo operando\n");
	}

	return 0;
}





