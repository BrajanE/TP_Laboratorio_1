/**
 * Esta biblioteca Tiene todas las funciones que no traian las bibliotecas por defecto
 * o que se usaran en funciones de las demas bibliotecas, por ejemplo mostrar los empleados, ordenar, buscar empleado, etc
 *
 */
#include "FuncEspecificas.h"

/**
 * Esta funcion muestra/imprime el empleado de una posicion
 * @param pArrayListEmployee
 * @param index
 */
void PrintAnEmployee(LinkedList* pArrayListEmployee, int index)
{
	Employee* pEmployeeAuxiliar;
	int id;
	char nombre[100];
	int horasTrabajadas;
	int sueldo;

	pEmployeeAuxiliar = ll_get(pArrayListEmployee,index);
	employee_getId(pEmployeeAuxiliar,&id);
	employee_getNombre(pEmployeeAuxiliar,nombre);
	employee_getHorasTrabajadas(pEmployeeAuxiliar,&horasTrabajadas);
	employee_getSueldo(pEmployeeAuxiliar,&sueldo);
	printf("%d\t%s\t\t%d\t\t%d\n", id,nombre,horasTrabajadas,sueldo);

}

/**
 * Esta funcion pide ingresar un ID, luego compara y busca la coincidencia retornando la posicion en la que se encontro
 * @param pArrayListEmployee
 * @param mensaje
 * @return posicionId
 */
int FindEmployeeById(LinkedList* pArrayListEmployee, char mensaje[])
{
	int idBuscado;
	int idDeLista;
	int posicionId=-1;
	int lenArray;
	Employee* pEmployeeAuxiliar;

	if(pArrayListEmployee!=NULL)
	{
		idBuscado=PedirEntero(mensaje);
		lenArray=ll_len(pArrayListEmployee);

		for(int i=0;i<lenArray;i++)
		{
			pEmployeeAuxiliar=ll_get(pArrayListEmployee,i);
			employee_getId(pEmployeeAuxiliar,&idDeLista);

			if(idDeLista==idBuscado)
			{
				posicionId=i;
				break;
			}
		}
	}


	return posicionId;
}

/**
 * Funcion que toma el listado y la direccion del archivo para escribir en el los datos en formato Texto
 * ese usa en controller
 * @param pArrayListEmployee
 * @param path
 * @return rtn
 */
int SaveEmployeesAsText(LinkedList* pArrayListEmployee, FILE* path)
{
	int rtn=-1;
	Employee* pEmployee;
	int id;
	char nombre[100];
	int horasTrabajadas;
	int sueldo;
	int len;
	len = ll_len(pArrayListEmployee);
	fprintf(path,"ID,NOMBRE,HORAS TRABAJADAS,SUELDO\n");
	for(int i=0;i<len;i++)
	{
		pEmployee=ll_get(pArrayListEmployee,i);
		employee_getId(pEmployee,&id);
		employee_getNombre(pEmployee,nombre);
		employee_getHorasTrabajadas(pEmployee,&horasTrabajadas);
		employee_getSueldo(pEmployee,&sueldo);
		fprintf(path,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
		rtn=1;
	}
	return rtn;
}

/**
 * Funcion que toma el listado y la direccion del archivo para escribir en el los datos en formato binario
 * ese usa en controller
 * @param pArrayListEmployee
 * @param path
 * @return
 */
int SaveEmployeesAsBinary(LinkedList* pArrayListEmployee, FILE* path)
{
	int rtn=-1;
	Employee* pEmployee;
	int len;
	len = ll_len(pArrayListEmployee);
	for(int i=0;i<len;i++)
	{
		pEmployee=ll_get(pArrayListEmployee,i);
		fwrite(pEmployee,sizeof(pEmployee),1,path);
		rtn=1;
	}
	return rtn;
}

/**
 *
 * @param primerDato
 * @param segundoDato
 * @return
 */
int SortByNombre(void* primerDato, void* segundoDato)
{
	Employee* unEmpleado;
	Employee* otroEmpleado;
	int comparacion =-1;
	unEmpleado=(Employee*) primerDato;
	otroEmpleado=(Employee*) segundoDato;
	if(unEmpleado!=NULL && otroEmpleado!=NULL)
	{
		comparacion = strcmp(unEmpleado->nombre, otroEmpleado->nombre);
	}
	return comparacion;
}

/**
 *
 * @param primerDato
 * @param segundoDato
 * @return
 */
int SortByHsTrabajadas(void* primerDato, void* segundoDato)
{
	Employee* unEmpleado;
	Employee* otroEmpleado;
	int comparacion=0;
	unEmpleado=(Employee*) primerDato;
	otroEmpleado=(Employee*) segundoDato;
	if(unEmpleado!=NULL && otroEmpleado!=NULL)
	{
		if(unEmpleado->horasTrabajadas>otroEmpleado->horasTrabajadas)
		{
			comparacion = 1;
		}else
		{
			if(unEmpleado->horasTrabajadas<otroEmpleado->horasTrabajadas)
			{
				comparacion = -1;
			}
		}
	}
	return comparacion;
}

/**
 *
 * @param primerDato
 * @param segundoDato
 * @return
 */
int SortBySueldo(void* primerDato, void* segundoDato)
{
	Employee* unEmpleado;
	Employee* otroEmpleado;
	int comparacion=0;
	unEmpleado=(Employee*) primerDato;
	otroEmpleado=(Employee*) segundoDato;
	if(unEmpleado!=NULL && otroEmpleado!=NULL)
	{
		if(unEmpleado->sueldo>otroEmpleado->sueldo)
		{
			comparacion = 1;
		}else
		{
			if(unEmpleado->sueldo<otroEmpleado->sueldo)
			{
				comparacion = -1;
			}
		}
	}
	return comparacion;
}

/**
 *
 * @param primerDato
 * @param segundoDato
 * @return
 */
int SortById(void* primerDato, void* segundoDato)
{
	Employee* unEmpleado;
	Employee* otroEmpleado;
	int comparacion=0;
	unEmpleado=(Employee*) primerDato;
	otroEmpleado=(Employee*) segundoDato;
	if(unEmpleado!=NULL && otroEmpleado!=NULL)
	{
		if(unEmpleado->id>otroEmpleado->id)
		{
			comparacion = 1;
		}else
		{
			if(unEmpleado->id<otroEmpleado->id)
			{
				comparacion = -1;
			}
		}
	}
	return comparacion;
}

/**
 *
 * @param pArrayListEmployee
 * @return
 */
int SortAllInOne(LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	int opcion;
	do{
		ShowSortMenus();
		opcion=PedirEnteroFull("Ingrese opcion: ",5);
		switch(opcion)
		{
		case 1:
			ShowSortMenuOrden();
			opcion=PedirEnteroFull("Ingrese opcion: ",2);
			rtn=ll_sort(pArrayListEmployee,SortById,opcion-1);
			break;
		case 2:
			ShowSortMenuOrden();
			opcion=PedirEnteroFull("Ingrese opcion: ",2);
			rtn=ll_sort(pArrayListEmployee,SortByNombre,opcion-1);
			break;
		case 3:
			ShowSortMenuOrden();
			opcion=PedirEnteroFull("Ingrese opcion: ",2);
			rtn=ll_sort(pArrayListEmployee,SortByHsTrabajadas,opcion-1);
			break;
		case 4:
			ShowSortMenuOrden();
			opcion=PedirEnteroFull("Ingrese opcion: ",2);
			rtn=ll_sort(pArrayListEmployee,SortBySueldo,opcion-1);
			break;
		}
		MensajeDeCorroboracion(rtn,"Ordenado exitosamente, para ver los cambios vaya a la opcion 6 del menu principal.\n","Error al ordenar los datos.\n");
	}while(opcion!=5);
	return rtn;
}
