#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "getsDatos.h"


typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

#define LEN_STR 128




Employee* employee_new();
Employee* employee_newParametros(int id, char* nombre, int horas, int sueldo);
Employee* employee_newParametrosTxt(char* id,char* nombre,char* horas, char* sueldo);


int addValores(int *horas, int* sueldo, char *nombre);
int employee_setValores(Employee* this, int id, int sueldo, int horas, char* nombre);

int employee_setId(Employee* this,int id);
int employee_setIdTxt(Employee* this,char* id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_setSueldoTxt(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_print(Employee* this);

void printModificaciones(void);

int addValoresAModificar(int *opcion, char *ingresoChar, int *ingresoInt);


int employee_delete(Employee* this);
int employee_setModificaciones(Employee* this);


int employee_criterioSueldo( void* item1, void* item2);
int employee_criterioId( void* item1, void* item2);
int employee_criterioNombre(void* item1, void* item2);
int employee_criterioHoras( void* item1, void* item2);

#endif // employee_H_INCLUDED
