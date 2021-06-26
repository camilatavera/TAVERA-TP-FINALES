#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"

#include "parser.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	FILE* fp;


		FILE* fpAux;
		char validar;
		Employee* pEmpleado;
		int i;
		int id;
		char nombre[LEN_STR];
		int horas;
		int sueldo;

	if(path!=NULL && pArrayListEmployee!=NULL ){

			if(ll_len(pArrayListEmployee)>0){
				printf("Ya tiene cargados empleados. Quiere guardarlos en un archivo.csv para no perderlos?");
				validarChar(&validar, "presione 's'=si o 'n'=no \n", "Error. ", 's', 'n', 20);

				switch(validar){
				case 's':
					fpAux=fopen("backup.csv", "w");

					if(fpAux!=NULL){
						fprintf(fpAux, "id,nombre,horasTrabajadas,sueldo \n");

						for(i=0; i<ll_len(pArrayListEmployee); i++){

							pEmpleado=ll_get(pArrayListEmployee, i);

							if(employee_getId(pEmpleado, &id)==0 &&
								employee_getNombre(pEmpleado, nombre)==0 &&
								employee_getHorasTrabajadas(pEmpleado, &horas)==0 &&
								employee_getSueldo(pEmpleado, &sueldo)==0){

									fprintf(fpAux,"%d,%s,%d,%d\n", id, nombre, horas, sueldo);
								}

								}//cierro for
								fclose(fpAux);
								ll_clear(pArrayListEmployee);
							}
						break;
				case 'n':
					ll_clear(pArrayListEmployee);
					break;
				}

			} //cierro switch


		fp=fopen(path, "r");
		if(fp!=NULL){
			parser_EmployeeFromText(fp, pArrayListEmployee);
			fclose(fp);
			ret=0;
		}
	}
    return  ret;;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	FILE* fp;

	if(path!=NULL && pArrayListEmployee!=NULL ){

		fp=fopen(path, "rb");
		if(fp!=NULL){
			parser_EmployeeFromBinary(fp, pArrayListEmployee);
			fclose(fp);
			ret=0;
		}
		else{
			printf("No se puede abrir archivo binario. Asegurese de que este cargado. \n");
		}
	}

	   return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	int aId, aHoras, aSueldo;
	char aNombre[LEN_STR];
	int lastIndex;
	int lastId;

	Employee* pEmpleado=NULL;
	Employee* pEmpleadoAux=NULL;
    if(pArrayListEmployee!=NULL){

    		if(addValores(&aHoras, &aSueldo, aNombre)==0){

    			if(ll_len(pArrayListEmployee)==0){
    				aId=1;
    			}
    			else{
					//busco el ultimo id y le agrego +1 para el nuevo empleado
					ll_sort(pArrayListEmployee, employee_criterioId, 1);
					lastIndex=ll_len(pArrayListEmployee)-1;

					pEmpleadoAux=ll_get(pArrayListEmployee, lastIndex);
					employee_getId(pEmpleadoAux, &lastId);
					aId=lastId+1;
    			}

    			pEmpleado=employee_newParametros(aId, aNombre, aHoras, aSueldo);

    			if(pEmpleado!=NULL){
    				if(ll_add(pArrayListEmployee, pEmpleado)==0){
						printf("Empleado cargado con exito  \n");
						employee_print(pEmpleado);
						ret=0;
    				}
    			}
    		}
    }
    return ret;
}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	int idIngresado;
	int i;
	int idAux;
	Employee* pEmpleado;
	int flag=1;


	if(pArrayListEmployee!=NULL){

		if(ll_len(pArrayListEmployee)==0){
			printf("No hay empleados ingresados al sistema \n");
		}
		else{

			getNumero(&idIngresado, "Ingrese el id \n", "Error. ", 1, 10000, 20);

			for(i=0; i<ll_len(pArrayListEmployee); i++){

				pEmpleado=ll_get(pArrayListEmployee, i);
				employee_getId(pEmpleado, &idAux);

				if(idAux==idIngresado){
					flag=0;
					break;
				}
			}

			if(flag==0){
				if(employee_setModificaciones(pEmpleado)==0){
					printf("Modificacion exitosa \n");
					ret=0;
				}
			}
			else{
				printf("No se encontro el id ingresado  \n");
			}
		}

	}
	return ret;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

	int ret=-1;
	int i;
	int idIngresado;
	int idAux;
	int flag=1;
	Employee* pEmpleado;
	char validar;


	if(pArrayListEmployee!=NULL){

		getNumero(&idIngresado, "Ingrese el id \n", "Error. ", 1, 10000, 20);

				for(i=0; i<ll_len(pArrayListEmployee); i++){

					pEmpleado=ll_get(pArrayListEmployee, i);
					employee_getId(pEmpleado, &idAux);

					if(idAux==idIngresado){
						flag=0;
						break;
					}
				}

				if(flag==0){
					employee_print(pEmpleado);
					validarChar(&validar, "Quiere eliminar este empleado? presione 's'=si o 'n'=no \n",
							"Error. ", 's', 'n', 25);

					if(validar=='s'){
						if(ll_remove(pArrayListEmployee, i)==0){
							printf("Se elimino exitosamente \n");
							ret=0;
						}
					}
					else{
						printf("No se realizaron cambios en la lista de empleados \n");
					}
				}
				else{
					printf("No se encontro el id ingresado  \n");
				}
		}
		return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	Employee* pEmpleado;
	int i;

	int id;
	char nombre[LEN_STR];
	int horas;
	int sueldo;


	if(pArrayListEmployee!=NULL){

		if(ll_len(pArrayListEmployee)==0){
			printf("No hay empleados ingresados al sistema \n");
		}
		else{
			ret=0;
			printf("Id      Nombre       Horas trabajadas    Sueldo \n");

			for(i=0; i<ll_len(pArrayListEmployee); i++){
				pEmpleado=ll_get(pArrayListEmployee, i);

				if(employee_getId(pEmpleado, &id)==0 && employee_getNombre(pEmpleado, nombre)==0 &&
				   employee_getHorasTrabajadas(pEmpleado, &horas)==0 && employee_getSueldo(pEmpleado, &sueldo)==0){

					printf("%-7d %-12s %-19d %d  \n", id, nombre, horas, sueldo);
				}

			}//cierro for
		}
	}
	return ret;

}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee){

	int ret=-1;
	int criterio;
	int orden;

	if(pArrayListEmployee!=NULL){

		getNumero(&criterio, "Criterio de ordenamiento: \n1. Id   2.Nombre   3.Horas   4.Sueldo \n", "Error. ",
						1, 4, 25);
		getNumero(&orden, "1.Ascendente   2.Descendente \n", "Error. ", 1, 2, 25);

		printf("Aguarde unos segundos... \n");

		switch(criterio){
		case 1:
			if(orden==1){
				ret=ll_sort(pArrayListEmployee, employee_criterioId, 1);
			}
			else{
				ret=ll_sort(pArrayListEmployee, employee_criterioId, 0);
			}
			break;

		case 2:
			if(orden==1){
				ret=ll_sort(pArrayListEmployee, employee_criterioNombre, 1);
			}
			else{
				ret=ll_sort(pArrayListEmployee, employee_criterioNombre, 0);
			}
			break;

		case 3:
			if(orden==1){
				ret=ll_sort(pArrayListEmployee, employee_criterioHoras, 1);
			}
			else{
				ret=ll_sort(pArrayListEmployee, employee_criterioHoras, 0);
			}
			break;
		case 4:
			if(orden==1){
				ret=ll_sort(pArrayListEmployee, employee_criterioSueldo, 1);
			}
			else{
				ret=ll_sort(pArrayListEmployee, employee_criterioSueldo, 0);
			}
			break;
		}
	}

	return ret;
}




/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	FILE* fp;
	Employee* pEmpleado;
	int i;
	int len;

	int id;
	char nombre[LEN_STR];
	int horas;
	int sueldo;

	int cont=0;

	if(path!=NULL && pArrayListEmployee!=NULL){
		len=ll_len(pArrayListEmployee);

		if(len==0){
			printf("No hay datos cargados para guardar \n");
		}
		else{
			fp=fopen(path, "w");

			if(fp!=NULL){

				fprintf(fp, "id,nombre,horasTrabajadas,sueldo \n");

				for(i=0; i<len; i++){
					pEmpleado=ll_get(pArrayListEmployee, i);

					if(employee_getId(pEmpleado, &id)==0 &&
						employee_getNombre(pEmpleado, nombre)==0 &&
						employee_getHorasTrabajadas(pEmpleado, &horas)==0 &&
						employee_getSueldo(pEmpleado, &sueldo)==0){

						fprintf(fp,"%d,%s,%d,%d\n", id, nombre, horas, sueldo);
						cont++;
					}

				}//cierro for
				fclose(fp);

				if(cont==len){
					ret=0;
				}
			}
		}//cierro else
	}//ciero validacion
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	FILE* fp;
	Employee *aEmployee;

	int len=ll_len(pArrayListEmployee);
	int validacion;
	int cont=0;

	if(path!=NULL && pArrayListEmployee!=NULL){

		if(len==0){
			printf("No hay nada para guardar \n");
		}

		else{
			fp=fopen(path, "wb");
			if(fp!=NULL){

				for(int i=0; i<len; i++){
					aEmployee=ll_get(pArrayListEmployee, i);

					if(aEmployee!=NULL){
						validacion=fwrite(aEmployee, sizeof(Employee), 1, fp);

						if(validacion==1){
							cont++;
						}
						else{
							printf("No entro en %d", i);
						}
					}
				}//cierro for
				fclose(fp);

				if(cont==len){
					ret=0;
				}
			}
		}
	}
    return ret;
}


