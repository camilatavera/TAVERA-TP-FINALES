
#include "Employee.h"




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


int employee_setId(Employee* this,int id){

	int ret=-1;
	if(this!=NULL && id>0){
		this->id=id;
		ret=0;
	}
	return ret;
}

int employee_setIdTxt(Employee* this,char* id){

	int ret=-1;
	if(this!=NULL && id!=NULL){
		if(esNumero(id, 10)){
			this->id=atoi(id);
			ret=0;
		}
	}
	return ret;


}

int employee_setNombre(Employee* this,char* nombre){
	int ret=-1;
	if(this!=NULL && nombre!=NULL){

		if(isValidNombre(nombre, LEN_STR)){
			strncpy(this->nombre, nombre, LEN_STR);
			ret=0;
		}
	}
		return ret;
}



int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

	int ret=-1;
		if(this!=NULL && horasTrabajadas>0){
				this->horasTrabajadas=horasTrabajadas;
				ret=0;
		}
		return ret;
}



int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas){

	int ret=-1;
	if(this!=NULL && horasTrabajadas!=NULL){

		if(esNumero(horasTrabajadas, 100)){   //validar positivo
			this->horasTrabajadas=atoi(horasTrabajadas);
			ret=0;
		}
	}
		return ret;
}

int employee_setSueldo(Employee* this,int sueldo){

	int ret=-1;
	if(this!=NULL && sueldo>0){
		this->sueldo=sueldo;
		ret=0;
	}
	return ret;
}

int employee_setSueldoTxt(Employee* this,char* sueldo){

	int ret=-1;
	if(this!=NULL && sueldo!=NULL){

		if(esNumero(sueldo, 1000000)){
			this->sueldo=atoi(sueldo);
			ret=0;

		}
	}
	return ret;
}


Employee* employee_new(){
	Employee* nuevoEmpleado=NULL;
	nuevoEmpleado=(Employee*)malloc(sizeof(Employee));
	return nuevoEmpleado;
}

Employee* employee_newParametros(int id, char* nombre, int horas, int sueldo){
	Employee* pEmpleado=NULL;

	if(id>0 && nombre!=NULL && horas>0 && sueldo>0){

		pEmpleado=employee_new();
		if(pEmpleado!=NULL){

			if(employee_setHorasTrabajadas(pEmpleado, horas)==-1 ||
					employee_setId(pEmpleado, id)==-1 ||
				employee_setNombre(pEmpleado, nombre)==-1 ||
				employee_setSueldo(pEmpleado, sueldo)==-1){

						employee_delete(pEmpleado);
						pEmpleado=NULL;
			}
		}
	}
	return pEmpleado;
}



Employee* employee_newParametrosTxt(char* id,char* nombre,char* horas, char* sueldo){

	Employee* pEmpleado=NULL;

	if(id!=NULL && nombre!=NULL && horas!=NULL && sueldo!=NULL ){

		pEmpleado=employee_new();
		if(pEmpleado!=NULL){


			if(employee_setIdTxt(pEmpleado, id)==-1 ||
				employee_setNombre(pEmpleado, nombre)==-1 ||
				employee_setHorasTrabajadasTxt(pEmpleado, horas)==-1 ||
				employee_setSueldoTxt(pEmpleado, sueldo)==-1){

					employee_delete(pEmpleado);
					pEmpleado=NULL;
				}

		}
	}
	return pEmpleado;
}

int addValores(int *horas, int* sueldo, char *nombre){
	int ret=-1;
	int aHoras, aSueldo;
	char aNombre[LEN_STR];

	if(horas!=NULL && sueldo!=NULL && nombre!=NULL){
		ret=0;

		if(utn_getString(aNombre, LEN_STR, "Ingrese su nombre \n", "Error. ", 25)==0){
			strncpy(nombre, aNombre, LEN_STR);
		}

		if(getNumero(&aHoras, "Ingrese horas trabajadas \n", "Error", 1, 1000, 25)==0){
			*horas=aHoras;
		}
		if(getNumero(&aSueldo, "Ingrese el sueldo \n", "Error", 1000, 100000, 25)==0){
			*sueldo=aSueldo;
		}
	}
	return ret;
	}

int employee_setValores(Employee* this, int id, int sueldo, int horas, char* nombre){

	int ret=-1;
	if(this!=NULL && sueldo>0 && horas>0 && nombre!=NULL){
		employee_setSueldo(this, sueldo);
		employee_setHorasTrabajadas(this, horas);
		employee_setId(this, id);
		employee_setNombre(this, nombre);
		ret=0;
	}
	return ret;
}

int addValoresAModificar(int *opcion, char *ingresoChar, int *ingresoInt){

	int ret=-1;
	int option;
	char auxChar[LEN_STR];
	int auxInt;

	if(opcion!=NULL && ingresoChar!=NULL && ingresoInt!=NULL){
		ret=0;
		printModificaciones();
		if(getNumero(&option, "Ingrese el numero de lo que quiere modificar\n", "Error. ",
				1, 3, 20)==0){

			*opcion=option;
			switch(option){
				case 1:
					utn_getString(auxChar, LEN_STR, "Ingrese el nuevo nombre \n", "Error. ", 25);
					strncpy(ingresoChar, auxChar, LEN_STR);
					break;
				case 2:
					getNumero(&auxInt, "Ingrese horas trabajadas \n", "Error", 1, 1000, 25);
					*ingresoInt=auxInt;
					break;
				case 3:
					getNumero(&auxInt, "Ingrese el sueldo \n", "Error", 1000, 100000, 25);
					*ingresoInt=auxInt;
					break;
			}
		}
	}
	return ret;
}


int employee_print(Employee* this){
	int ret=-1;
	int id;
	int horas;
	int sueldo;
	char nombre[LEN_STR];

	if(this!=NULL){
		if(employee_getId(this, &id)==0 && employee_getSueldo(this, &sueldo)==0 &&
			employee_getHorasTrabajadas(this, &horas)==0 && employee_getNombre(this, nombre)==0){

			printf("id: %d    nombre: %s    horas: %d    sueldo: %d \n",
			id, nombre, horas, sueldo);
			ret=0;
		}
	}
	return ret;
}


void printModificaciones(void){
	printf("1. Nombre   2. Horas trabajadas  3. Sueldo  \n");
}




int employee_getId(Employee* this,int* id){

	int ret=-1;
	if(this!=NULL && id!=NULL){
		*id=this->id;
		ret=0;
	}
	return ret;
}

int employee_getNombre(Employee* this,char* nombre){
	int ret=-1;
		if(this!=NULL && nombre!=NULL){
			strncpy(nombre, (*this).nombre, LEN_STR);
			ret=0;
		}

		return ret;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int ret=-1;
	if(this!=NULL && horasTrabajadas!=NULL){
		*horasTrabajadas=(*this).horasTrabajadas;
		ret=0;
	}
	return ret;
}

int employee_getSueldo(Employee* this,int* sueldo){
	int ret=-1;
	if(this!=NULL && sueldo!=NULL){
		*sueldo=this->sueldo;
		ret=0;
	}

	return ret;
}

int employee_delete(Employee* this){
	int ret=-1;
	if(this!=NULL){
		free(this);
		ret=0;
	}
	return ret;
}


int employee_setModificaciones(Employee* this){
	int ret=-1;
	int option;
	char auxChar[LEN_STR];
	int auxInt;

	if(this!=NULL){

		if(addValoresAModificar(&option, auxChar, &auxInt)==0){

			switch(option){
			case 1:
				if(employee_setNombre(this, auxChar)==0){
					ret=0;
				}
				break;
			case 2:
				if(employee_setHorasTrabajadas(this, auxInt)==0){
					ret=0;
				}
				break;
			case 3:
				if(employee_setSueldo(this, auxInt)==0){
					ret=0;
				}
				break;
			}
		}
	}
	return ret;
}


int employee_criterioSueldo( void* item1, void* item2){
	int ret=0;

	Employee* e1;
	Employee* e2;

	int sueldo1;
	int sueldo2;
	int id1;
	int id2;

	if(item1!=NULL && item2!=NULL){

		e1=(Employee*)item1;
		e2=(Employee*)item2;

		if(employee_getSueldo(e1, &sueldo1)==0 && employee_getSueldo(e2, &sueldo2)==0){
			if(sueldo1>sueldo2){
				ret=1;
			}
			else if(sueldo2>sueldo1){
				ret=-1;
			}
			else{
				if(employee_getId(e1, &id1)==0 && employee_getId(e2, &id2)==0){
					if(id1>id2){
						ret=1;
					}
					else{
						ret=-1;
					}
				}
			}
		}

	}
	return ret;
}


int employee_criterioId( void* item1, void* item2){
	int ret=0;

	Employee* e1;
	Employee* e2;

	int id1;
	int id2;

	if(item1!=NULL && item2!=NULL){

		e1=(Employee*)item1;
		e2=(Employee*)item2;

		if(employee_getId(e1, &id1)==0 && employee_getId(e2, &id2)==0){
			if(id1>id2){
				ret=1;
			}
			else if(id2>id1){
				ret=-1;
			}

		}
	}

	return ret;
}


int employee_criterioNombre(void* item1, void* item2){
	int ret=0;
	Employee* e1;
	Employee* e2;

	char nombre1[LEN_STR];
	char nombre2[LEN_STR];
	int id1;
	int id2;

	if(item1!=NULL && item2!=NULL){

		e1=(Employee*)item1;
		e2=(Employee*)item2;

		if(employee_getNombre(e1, nombre1)==0 && employee_getNombre(e2, nombre2)==0){
				if(strcmp(nombre1, nombre2)>0){
					ret=1;
				}
				else if(strcmp(nombre1, nombre2)<0){
					ret=-1;
				}
				else{
					if(employee_getId(e1, &id1)==0 && employee_getId(e2, &id2)==0){
						if(id1>id2){
							ret=1;
						}
						else{
							ret=-1;
						}
					}
				}

		}
	}
	return ret;
}

int employee_criterioHoras( void* item1, void* item2){
	int ret=0;

	Employee* e1;
	Employee* e2;

	int horas1;
	int horas2;
	int id1;
	int id2;

	if(item1!=NULL && item2!=NULL){

		e1=(Employee*)item1;
		e2=(Employee*)item2;

		if(employee_getHorasTrabajadas(e1, &horas1)==0 && employee_getHorasTrabajadas(e2, &horas2)==0){
			if(horas1>horas2){
				ret=1;
			}
			else if(horas2>horas1){
				ret=-1;
			}
			else{
				if(employee_getId(e1, &id1)==0 && employee_getId(e2, &id2)==0){
					if(id1>id2){
						ret=1;
					}
					else{
						ret=-1;
					}
				}
			}
		}

	}
	return ret;
}
















