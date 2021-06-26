#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	if(pFile!=NULL && pArrayListEmployee!=NULL){
		ret=0;
		char id[LEN_STR], nombre[LEN_STR], horas[LEN_STR], sueldo[LEN_STR];
		int flag=0; //lectura fantasma


		do{

			if(fscanf(pFile, "%[^,], %[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo)==4 && flag){


				Employee* pEmpleado=NULL;
				pEmpleado=employee_newParametrosTxt(id, nombre, horas, sueldo);


				ll_add(pArrayListEmployee, pEmpleado);
			}
			flag=1;
		}while(feof(pFile)==0);

	}

    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	int validacion;
	Employee aux;


	if(pFile!=NULL && pArrayListEmployee!=NULL){

		ret=0;
		while(!feof(pFile)){
			Employee* newEmployee=employee_new();


			if(newEmployee!=NULL){
				validacion=fread(&aux, sizeof(Employee), 1, pFile);

				if(validacion==1){
					employee_setId(newEmployee, aux.id);
					employee_setNombre(newEmployee, aux.nombre);
					employee_setHorasTrabajadas(newEmployee, aux.horasTrabajadas);
					employee_setSueldo(newEmployee, aux.sueldo);
					ll_add(pArrayListEmployee, newEmployee);
				}
			}

		}
	}
    return ret;
}
