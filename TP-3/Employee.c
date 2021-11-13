#include "Employee.h"

/**
 * Inicia el Array
 * @return
 */
Employee* employee_new() //Inicializar el array "initArray"
{
	Employee* pEmployee;
	pEmployee = (Employee*) malloc(sizeof(Employee));

	return pEmployee;
}

/**
 * funcion alberga las demas funciones del set, toma cada dato y los guarda en la variable correspondiente
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @param sueldoStr
 * @return
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pEmployee;
	//Usamos el espacio que iniciamos con "employee_new" para agregar los parametros del empleado
	pEmployee = employee_new();
	if(pEmployee!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		employee_setId(pEmployee, atoi(idStr));
		employee_setNombre(pEmployee,nombreStr); // no hace falta convertir a entero por que tiene que ser char obviamente
		employee_setHorasTrabajadas(pEmployee, atoi(horasTrabajadasStr));
		employee_setSueldo(pEmployee, atoi(sueldoStr));
	}
	return pEmployee;
}

/**
 * Elimina un elemento
 * @param this
 */
void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

/**
 * Toma un dato ID y lo guarda en el listado
 * @param this
 * @param id
 * @return rtn
 */
int employee_setId(Employee* this,int id)
{
	int rtn = -1;
	if(this!=NULL)
	{
		this->id=id;
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un Id del listado y lo guarda en la variable id que luego se enviara por puntero
 * @param this
 * @param id
 * @return
 */
int employee_getId(Employee* this,int* id)
{
	int rtn = -1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un dato Nombre y lo guarda en el listado
 * @param this
 * @param nombre
 * @return
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int rtn = -1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un Nombre del listado y lo guarda en la variable nombre que luego se enviara por puntero
 * @param this
 * @param nombre
 * @return
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int rtn = -1;
	if(this!=NULL && nombre !=NULL)
	{
		strcpy(nombre,this->nombre);
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un dato nuevo "horas trabajadas" y lo guarda en el listado
 * @param this
 * @param horasTrabajadas
 * @return
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int rtn = -1;
	if(this!=NULL)
	{
		this->horasTrabajadas=horasTrabajadas;
		rtn = 1;
	}

	return rtn;
}
/**
 * Toma un dato de Horas trabajadas del listado y lo guarda en la variable "horas trabajadas" que luego se enviara por puntero
 * @param this
 * @param horasTrabajadas
 * @return
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int rtn = -1;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un dato "sueldo" y lo guarda en el listado
 * @param this
 * @param sueldo
 * @return
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int rtn = -1;
	if(this!=NULL)
	{
		this->sueldo=sueldo;
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un dato de "sueldo" del listado y lo guarda en la variable "sueldo" que luego se enviara por puntero
 * @param this
 * @param sueldo
 * @return
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int rtn = -1;
	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		rtn = 1;
	}

	return rtn;
}

