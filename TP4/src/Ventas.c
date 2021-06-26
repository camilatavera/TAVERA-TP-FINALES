#include "Ventas.h"

#include <stdio.h>
#include "getsDatos.h"


static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i]==' '){
				continue;
			}
			if(cadena[i]=='-'){
				continue;
			}
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


static int esNumero(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}


int ventas_setId(Ventas* pVentas,int Aid){

	int ret=-1;
	if(pVentas!=NULL && Aid>0){
		pVentas->id=Aid;
		ret=0;
	}
	return ret;
}

int ventas_setIdTxt(Ventas* pVentas,char* Aid){

	int ret=-1;
	if(pVentas!=NULL && Aid!=NULL){
		if(esNumero(Aid, 10)){
			pVentas->id=atoi(Aid);
			ret=0;
		}
	}
	return ret;
}

int ventas_setNombre(Ventas* pVentas,char* nombre){
	int ret=-1;
	if(pVentas!=NULL && nombre!=NULL){

			strncpy(pVentas->nombre, nombre, LEN_STR);
			ret=0;

	}
		return ret;
}



int ventas_setDia(Ventas* pVentas,int dia){

	int ret=-1;
		if(pVentas!=NULL && dia>=0 && dia<=6){
			pVentas->dia=dia;
				ret=0;
		}
		return ret;
}



int ventas_setTipoTxt(Ventas* pVentas, char* Adia){

	int ret=-1;
	if(pVentas!=NULL && Adia!=NULL){

		if(esNumero(Adia, 3)){   //validar positivo
			pVentas->dia=atoi(Adia);
			ret=0;
		}
	}
		return ret;
}

int ventas_setHorario(Ventas* pVentas,char* Ahorario){
	int ret=-1;
	if(pVentas!=NULL && Ahorario!=NULL){


			strncpy(pVentas->horario, Ahorario, LEN_STR);
			ret=0;
	}
	return ret;
}

int ventas_setSala(Ventas* pVentas,int Asala){

	int ret=-1;
	if(pVentas!=NULL && Asala>=1 && Asala<=5){
		pVentas->sala=Asala;
		ret=0;
	}
	return ret;
}

int ventas_setSalaTxt(Ventas* pVentas,char* Asala){

	int ret=-1;
	if(pVentas!=NULL && Asala!=NULL){

		if(esNumero(Asala, 3)){
			pVentas->sala=atoi(Asala);
			ret=0;

		}
	}
	return ret;
}

int ventas_setCantEntradas(Ventas* pVentas,int AcantEntradas){

	int ret=-1;
	if(pVentas!=NULL && AcantEntradas>0){
		pVentas->cantEntradas=AcantEntradas;
		ret=0;
	}
	return ret;
}

int ventas_setcantEntradasTxt(Ventas* pVentas,char* AcantEntradas){

	int ret=-1;
	if(pVentas!=NULL && AcantEntradas!=NULL){

		if(esNumero(AcantEntradas, 3)){
			pVentas->cantEntradas=atoi(AcantEntradas);
			ret=0;
		}
	}
	return ret;
}

int ventas_setMonto(Ventas* pVentas, int monto){
	int ret=-1;

	if(pVentas!=NULL && monto>0){
		pVentas->monto=monto;
		ret=0;
	}
	return ret;
}


Ventas* ventas_new(){
	Ventas* nuevaVenta=NULL;
	nuevaVenta=(Ventas*)malloc(sizeof(Ventas));
	return nuevaVenta;
}

Ventas* ventas_newParametros(int id, char* nombre, int dia, char* horario, int sala, int cantEntradas){
	Ventas* pVentas=NULL;

	//mas validaciones
	if(id>0 && nombre!=NULL && dia>0 && horario!=NULL ){

		pVentas=ventas_new();
		if(pVentas!=NULL){

			if(ventas_setId(pVentas, id)==-1 ||
					ventas_setNombre(pVentas, nombre)==-1 ||
					ventas_setDia(pVentas, dia)==-1 ||
					ventas_setHorario(pVentas, horario)==-1 ||
					ventas_setSala(pVentas, sala)==-1 ||
					ventas_setCantEntradas(pVentas, cantEntradas)==-1){

						ventas_delete(pVentas);
						pVentas=NULL;
			}
		}
	}
	return pVentas;
}



Ventas* ventas_newParametrosTxt(char* id, char* nombre, char* dia, char* horario, char* sala, char* cantEntradas){

	Ventas* pVentas=ventas_new();



	if(id!=NULL && nombre!=NULL && dia!=NULL && horario!=NULL &&
			 sala!=NULL && cantEntradas!=NULL && pVentas!=NULL){



			if(ventas_setIdTxt(pVentas, id)==-1 ||
					ventas_setNombre(pVentas, nombre)==-1 ||
					ventas_setTipoTxt(pVentas, dia)==-1 ||
					ventas_setHorario(pVentas, horario)==-1 ||
					ventas_setSalaTxt(pVentas, sala)==-1 ||
					ventas_setcantEntradasTxt(pVentas, cantEntradas)==-1){

					ventas_delete(pVentas);
				}


	}

	return pVentas;
}


int ventas_print(Ventas* pVentas){
	int ret=-1;
	int id;
	char nombre[128];
	int dia;
	char horario[128];
	int sala;
	int cantEntradas;

	if(pVentas!=NULL){
		ventas_getId(pVentas, &id) ;
				ventas_getNombre(pVentas, nombre);
				ventas_getDia(pVentas, &dia);
				ventas_getHorario(pVentas, horario);

				ventas_getSala(pVentas, &sala);
				ventas_getCantEntradas(pVentas, &cantEntradas);


			ret=0;
		}

	return ret;
}


int ventas_getId(Ventas* pVentas,int* id){

	int ret=-1;

	if(pVentas!=NULL && id!=NULL){
		*id=pVentas->id;
		ret=0;
	}
	return ret;
}

int ventas_getNombre(Ventas* pVentas,char* nombre){
	int ret=-1;
		if(pVentas!=NULL && nombre!=NULL){
			strcpy(nombre, pVentas->nombre);
			ret=0;
		}

		return ret;
}


int ventas_getDia(Ventas* pVentas,int* dia){
	int ret=-1;
	if(pVentas!=NULL && dia!=NULL){
		*dia=pVentas->dia;
		ret=0;
	}
	return ret;
}

int getDiaStr(int ndia, char* dia){
	int ret=-1;
	if(ndia>=1 && ndia<=7 && dia!=NULL){
		ret=0;
		switch(ndia){
		case 0:
			strcpy(dia, "Domingo");
			break;
		case 1:
			strcpy(dia, "Lunes");
			break;
		case 2:
			strcpy(dia, "Martes");
			break;
		case 3:
			strcpy(dia, "Miercoles");
			break;
		case 4:
			strcpy(dia, "Jueves");
			break;
		case 5:
			strcpy(dia, "Viernes");
			break;
		case 6:
			strcpy(dia, "Sabado");
			break;
		}
	}
	return ret;
}


int ventas_getHorario(Ventas* pVentas,char* horario){
	int ret=-1;
		if(pVentas!=NULL && horario!=NULL){
			strncpy(horario, pVentas->horario, LEN_STR);
			ret=0;
		}

		return ret;
}

int ventas_getSala(Ventas* pVentas,int* sala){
	int ret=-1;
	if(pVentas!=NULL && sala!=NULL){
		*sala=pVentas->sala;
		ret=0;
	}

	return ret;
}

int ventas_getCantEntradas(Ventas* pVentas,int* cantEntradas){
	int ret=-1;
	if(pVentas!=NULL && cantEntradas!=NULL){
		*cantEntradas=pVentas->cantEntradas;
		ret=0;
	}

	return ret;
}

int ventas_getMonto(Ventas* pVentas,int* monto){
	int ret=-1;
	if(pVentas!=NULL && monto!=NULL){
		*monto=pVentas->monto;
		ret=0;
	}

	return ret;
}

int ventas_delete(Ventas* pVentas){
	int ret=-1;
	if(pVentas!=NULL){
		free(pVentas);
		pVentas=NULL;
		ret=0;
	}
	return ret;
}



void calculaMonto(void* pElement){

	int dia;
	int entradas;
	int monto;

		ventas_getDia(pElement, &dia);
		ventas_getCantEntradas(pElement, &entradas);

		if(dia>=1 && dia<=3){
			monto=240*entradas;
		}
		else{
			monto=350*entradas;
		}
		if(entradas>3){
			monto=0.9*monto;
		}

		ventas_setMonto(pElement, monto);
	}




int printTxt(FILE* fp, Ventas* this){
	int ret=-1;


	int id;
	char nombre[LEN_STR];
	int dia;
	char horario[LEN_STR];
	int sala;
	int entradas;
	int monto;

	if(fp!=NULL && this!=NULL){
		ret=0;


			if(ventas_getId(this, &id)==0 && ventas_getNombre(this, nombre)==0 && ventas_getDia(this, &dia)==0 &&
					ventas_getHorario(this, horario)==0 && ventas_getSala(this, &sala)==0 &&
					ventas_getCantEntradas(this, &entradas)==0 && ventas_getMonto(this, &monto)==0){

				fprintf(fp,"%d,%s,%d,%s,%d,%d,%d\n", id, nombre, dia, horario, sala, entradas, monto);
			}
	}
	return ret;
}


int entradasSala1(void* pElement){

	int ret=0;
	int sala;
	int cantEntradas;
	if(pElement!=NULL && ventas_getSala(pElement, &sala)==0 && sala==1 &&
			ventas_getCantEntradas(pElement, &cantEntradas)==0 ){

		ret=cantEntradas;
	}
	return ret;
}

int entradasSala2(void* pElement){

	int ret=0;
	int sala;
	int cantEntradas;
	if(pElement!=NULL && ventas_getSala(pElement, &sala)==0 && sala==2 &&
			ventas_getCantEntradas(pElement, &cantEntradas)==0 ){

		ret=cantEntradas;
	}
	return ret;
}

int entradasSala3(void* pElement){

	int ret=0;
	int sala;
	int cantEntradas;
	if(pElement!=NULL && ventas_getSala(pElement, &sala)==0 && sala==3 &&
			ventas_getCantEntradas(pElement, &cantEntradas)==0 ){

		ret=cantEntradas;
	}
	return ret;
}

int entradasSala4(void* pElement){

	int ret=0;
	int sala;
	int cantEntradas;
	if(pElement!=NULL && ventas_getSala(pElement, &sala)==0 && sala==4 &&
			ventas_getCantEntradas(pElement, &cantEntradas)==0 ){

		ret=cantEntradas;
	}
	return ret;
}

int entradasSala5(void* pElement){

	int ret=0;
	int sala;
	int cantEntradas;
	if(pElement!=NULL && ventas_getSala(pElement, &sala)==0 && sala==5 &&
			ventas_getCantEntradas(pElement, &cantEntradas)==0 ){

		ret=cantEntradas;
	}
	return ret;
}


int montoSala1(void* pElement){
	int ret=0;
	int sala;
	int monto;
	if(pElement!=NULL && ventas_getSala(pElement, &sala)==0 && sala==1 &&
			ventas_getMonto(pElement, &monto)==0 ){
		ret=monto;
	}
	return ret;
}

int montoSala2(void* pElement){
	int ret=0;
	int sala;
	int monto;
	if(pElement!=NULL && ventas_getSala(pElement, &sala)==0 && sala==2 &&
			ventas_getMonto(pElement, &monto)==0 ){
		ret=monto;
	}
	return ret;
}

int montoSala3(void* pElement){
	int ret=0;
	int sala;
	int monto;
	if(pElement!=NULL && ventas_getSala(pElement, &sala)==0 && sala==3 &&
			ventas_getMonto(pElement, &monto)==0 ){
		ret=monto;
	}
	return ret;
}

int montoSala4(void* pElement){
	int ret=0;
	int sala;
	int monto;
	if(pElement!=NULL && ventas_getSala(pElement, &sala)==0 && sala==4 &&
			ventas_getMonto(pElement, &monto)==0 ){
		ret=monto;
	}
	return ret;
}

int montoSala5(void* pElement){
	int ret=0;
	int sala;
	int monto;
	if(pElement!=NULL && ventas_getSala(pElement, &sala)==0 && sala==5 &&
			ventas_getMonto(pElement, &monto)==0 ){
		ret=monto;
	}
	return ret;
}

int nombreSala1(void* pElement){
	int ret=-1;
	int sala;

	if(pElement!=NULL && ventas_getSala(pElement, &sala)==0 && sala==1){
		ret=0;
	}
	return ret;
}


int nombreSala2(void* pElement){
	int ret=-1;
	int sala;

	if(pElement!=NULL && ventas_getSala(pElement, &sala)==0 && sala==2){
		ret=0;
	}
	return ret;
}

int nombreSala3(void* pElement){
	int ret=-1;
	int sala;

	if(pElement!=NULL && ventas_getSala(pElement, &sala)==0 && sala==3){
		ret=0;
	}
	return ret;
}


int nombreSala4(void* pElement){
	int ret=-1;
	int sala;

	if(pElement!=NULL && ventas_getSala(pElement, &sala)==0 && sala==4){
		ret=0;
	}
	return ret;
}


int nombreSala5(void* pElement){
	int ret=-1;
	int sala;

	if(pElement!=NULL && ventas_getSala(pElement, &sala)==0 && sala==5){
		ret=0;
	}
	return ret;
}

int list_nombresFiltrados(Ventas *pElement){
	int ret=-1;
	char nombre[LEN_STR];

	if(pElement!=NULL && ventas_getNombre(pElement, nombre)==0){
		printf("%s  \n", nombre);
		ret=0;
	}
	return ret;
}
