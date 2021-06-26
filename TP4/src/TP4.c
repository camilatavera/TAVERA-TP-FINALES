/*
 ============================================================================
 Name        : parcial2p.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "controller.h"
#include "menu.h"

int main(void) {

	setbuf(stdout, NULL);

	    int option;
	    char nombreArchivo[LEN_STR];
	    int flag=1;

	    LinkedList* listaVentas = ll_newLinkedList();




	    do{
	    	printMenu();
	    	getNumero(&option, "Ingrese opcion de menu\n", "Error. ", 1, 5, 25);


	        switch(option)
	        {
	            case 1:
	            	if(validarString(nombreArchivo, LEN_STR, "Ingrese el nombre del archivo (hola.csv) \n",
	            			"Error. ", "hola.csv", 25)==0 && controller_loadFromText("hola.csv", listaVentas)==0){

	                	printf("Operacion realizada con exito \n");
	                }
	                break;
	            case 2:
	            	if(controller_ListVentas(listaVentas)!=0){
	            		printf("Error \n");
	            	}
	            	break;

	            case 3:
	            	if(controller_saveAsText("monto.csv", listaVentas)==0){
	            		flag=0;
	            		printf("Operacion realizada con exito \n");
	            	}
	            	break;
	            case 4:
	            	if(flag==0){
	            		controller_Informes(listaVentas);
	            	}
	            	else{
	            		printf("Primero debes generar el monto \n");
	            	}
	            	break;
	        }
	    }while(option!=5);
	    return 0;
}

