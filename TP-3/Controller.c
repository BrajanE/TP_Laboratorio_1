#include "Controller.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int ultimoIdCargado=-1;
	FILE* pFile;
	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		pFile = fopen(path, "r");// path es el archivo "data.csv"
		if(pFile!=NULL)
		{	//abrimos el archivo y lo pasamos para que el parser lo analice y cargue
			ultimoIdCargado=parser_EmployeeFromText(pFile,pArrayListEmployee);
		}
	fclose(pFile);
	}
    return ultimoIdCargado;
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
	int ultimoIdCargado=-1;
	FILE* pFile;
	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		pFile = fopen(path, "rb");
		if(pFile!=NULL)
		{
			ultimoIdCargado=parser_EmployeeFromBinary(pFile ,pArrayListEmployee);
		}
	fclose(pFile);
	}
	return ultimoIdCargado;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int id)
{
	int rtn=-1;
	char nombre[100];
	int horasTrabajadas;
	int sueldo;
	Employee* pEmployee;
	pEmployee = employee_new();

	GetString("Ingrese nombre: ", nombre);
	horasTrabajadas=PedirEntero("Ingrese horas trabajadas: ");
	sueldo=PedirEntero("Ingrese sueldo: ");

	employee_setId(pEmployee,id);
	employee_setNombre(pEmployee,nombre);
	employee_setHorasTrabajadas(pEmployee,horasTrabajadas);
	employee_setSueldo(pEmployee,sueldo);

	if(pArrayListEmployee!=NULL && pEmployee!=NULL)
	{
		rtn=ll_add(pArrayListEmployee, pEmployee);
	}


    return rtn;
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
	int rtn=-1;
	int opcion;
	int posicionEmpleado;
	Employee* pEmployee;
	posicionEmpleado = FindEmployeeById(pArrayListEmployee, "Ingrese ID de empleado a modificar:\n");
	if(posicionEmpleado!=-1)
		{
			char nombre[100];
			int horasTrabajadas;
			int sueldo;
			pEmployee = ll_get(pArrayListEmployee,posicionEmpleado);
				do{
					ShowModificationMenu();
					opcion = PedirEnteroFull("Ingrese opcion: ",4);
					switch(opcion)
					{
					case 1:
						GetString("Ingrese nombre: ", nombre);
						employee_setNombre(pEmployee,nombre);
						break;
					case 2:
						horasTrabajadas=PedirEntero("Ingrese horas trabajadas: ");
						employee_setHorasTrabajadas(pEmployee,horasTrabajadas);
						break;
					case 3:
						sueldo=PedirEntero("Ingrese sueldo: ");
						employee_setSueldo(pEmployee,sueldo);
						break;
					}
				}while(opcion != 4);
			rtn=1;
		}

    return rtn;
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
	int rtn=-1;
	int opcion;
	int posicionEmpleado;
	Employee* pEmployee;
	posicionEmpleado = FindEmployeeById(pArrayListEmployee, "Ingrese ID de empleado a modificar:\n");
	if(posicionEmpleado!=-1)
	{
		printf("Seleccion 1 para remover al empleado, 2 para cancelar: ");
		opcion=PedirEnteroFull("Ingrese opcion: ",2);
		if(opcion==1 && pArrayListEmployee!=NULL)
		{
			pEmployee = ll_get(pArrayListEmployee,posicionEmpleado);
			employee_delete(pEmployee);
			rtn=ll_remove(pArrayListEmployee,posicionEmpleado);
		}
	}
    return rtn;
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
	int rtn=-1;
	int lenList;
    lenList=ll_len(pArrayListEmployee);
    if(pArrayListEmployee!=NULL)
    {
    	printf("ID\tNombre\tHs trabajadas\tSueldo\n");
    	for(int i=0;i<lenList;i++)
    	{
    		PrintAnEmployee(pArrayListEmployee,i);
    		rtn=1;
    	}
    }
	return rtn;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	rtn=SortAllInOne(pArrayListEmployee);
    return rtn;
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
	int rtn=-1;
	FILE* pFile;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile=fopen(path,"w");
		if(pFile!=NULL)
		{
			rtn=SaveEmployeesAsText(pArrayListEmployee,pFile);
		}
		fclose(pFile);
	}
    return rtn;
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
	int rtn=-1;
	FILE* pFile;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile=fopen(path,"wb");
		if(pFile!=NULL)
		{
			rtn=SaveEmployeesAsText(pArrayListEmployee,pFile);
		}
		fclose(pFile);
	}
	return rtn;
}

