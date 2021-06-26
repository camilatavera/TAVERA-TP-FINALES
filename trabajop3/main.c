

#include "Controller.h"

#include "menu.h"



int main()
{

	setbuf(stdout, NULL);

    int option;


    LinkedList* listaEmpleados = ll_newLinkedList();



    do{
    	printMenu();
    	getNumero(&option, "Ingrese opcion de menu\n", "Error. ", 1, 10, 25);


        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)==0){
                	printf("Operacion realizada con exito \n");
                }
                break;
            case 2:
            	if(controller_loadFromBinary("data.bin", listaEmpleados)==0){
            		printf("Operacion realizada con exito \n");
            	}
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7:
            	if(controller_sortEmployee(listaEmpleados)==0){
            		printf("Ordenamiento exitoso \n");
            	}
            	break;
            case 8:
            	if(controller_saveAsText("data.csv", listaEmpleados)==0){
            		printf("Se guardaron los datos en modo texto exitosamente  \n");
            	}
            	break;
            case 9:
            	if(controller_saveAsBinary("data.bin", listaEmpleados)==0){
            		printf("Se guardaron los datos en modo binario exitosamente  \n");
            	}
            	break;
        }
    }while(option != 10);
    return 0;
}

