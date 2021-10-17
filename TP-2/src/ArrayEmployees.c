#include "ArrayEmployees.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void initEmployees(Employee* list, int len)
{
	if(list != NULL && len>0)
	{
		for(int i=0; i<len;i++)
		{
			list[i].isEmpty = TRUE;
		}
	}
}
/** \brief Sirve para generar ID de forma automatica
 * \param Recibe Id del main, que luego se modificara
 * \return Retorna nuevo ID
 *
 */
int IdAutomatico(int id)
{
	id++;
	return id;
}

/** \brief Sirve para ingresar datos de empleados que luego se pasan por parametros a "AddEmployee"
 * \param La estructura
 * \param int tamaño
 * \param int ID
 * \return Retorna -1 en caso de error, 0 si se realizo correctamente, este retorno lo obtiene de la funcion "AddEmployee"
 *
 */
int ingresarEmpleado(Employee* list, int len, int id)
{
	int rtn;
	char name[51];
	char lastName[51];
	float salary;
	int sector;

	GetString("Ingrese nombre: ", name);
	GetString("Ingrese apellido: ",lastName);
	salary=PedirFlotante("Ingrese salario: ");
	sector=PedirEntero("Ingrese N° de sector: ");

	rtn = addEmployee(list, len, id, name,lastName,salary,sector);
	return rtn;
}
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector)
{
	int rtn;
	rtn=-1;

	if(list !=NULL && len>0 && len <1001)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				list[i].id=id;
				strcpy(list[i].name,name);
				strcpy(list[i].lastName,lastName);
				list[i].salary=salary;
				list[i].sector=sector;
				list[i].isEmpty=FALSE;
				rtn=0;
				break;
			}
		}
	}

 return rtn;
}



/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id)
{
	int rtn;
	rtn=-1;
	if(list != NULL && len>0 && id>0)
	{
		for(int i=0; i<len;i++)
		{
			if(list[i].isEmpty==FALSE && list[i].id == id)
			{
				rtn=i;
				break;
			}
		}
	}
	return rtn;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
	int rtn;
	rtn=-1;
	if(list!=NULL && len>0 && id>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].id == id && list[i].isEmpty == FALSE)
			{
				list[i].isEmpty = TRUE;
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
	int rtn;
	rtn=-1;
	int i;
	int j;
	Employee auxiliar;
	if(list!=NULL && len>0)
	{
	switch(order)
	{
	case 1:
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(strcmp(list[i].lastName,list[j].lastName)>=0)
			{
				auxiliar = list[i];
				list[i] = list[j];
				list[j] = auxiliar;
				rtn = 0;
			}
		}
	}
		break;
	case 2:
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(list[i].sector > list[j].sector)
			{
				auxiliar = list[i];
				list[i] = list[j];
				list[j] = auxiliar;
				rtn = 0;
			}
		}
	}
	break;
	}
	}
	return rtn;
}

/** \brief Sirve para mostrar un empleado de la estructura
 * \param La estructura
 * \return No retorna nada, sirve para mostrar el empleado
 *
 */
void MostrarUnEmpleado(Employee Empleado)
{
	printf("%6d %12s %16s %14.2f %11d\n", Empleado.id,Empleado.name,Empleado.lastName,Empleado.salary,Empleado.sector);
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length)
{
	int rtn;
	rtn=-1;
	printf("    ID       Nombre          Apellido       Salario      Sector\n");
	for(int i=0; i<length; i++)
	{
		if(list[i].isEmpty == FALSE)
		{
			MostrarUnEmpleado(list[i]);
			rtn=0;
		}
	}
	return rtn;
}

/** \brief Sirve como funcion que engloba distintos funciones de calculos sobre la estructura
 * \param La estructura
 * \param int tamaño
 * \param puntero float para guardar el valor en main
 * \param puntero int para guardar el valor en main
 * \return Retorna -1 en caso de error, 0 si se realizo correctamente
 *
 */
int CalculosConSalarios(Employee* list, int len, float *salarioTotal, int *totalEmpleados)
{
	int rtn;
	rtn=-1;
	float totalSalario;
	int cantEmpleados;

	if(list!=NULL && len>0)
	{
		cantEmpleados=ContadorEmpleados(list, len);
		totalSalario=AcumuladorSueldos(list,len);
		rtn=0;
	}
	*salarioTotal=totalSalario;
	*totalEmpleados=cantEmpleados;
	return rtn;

}
/** \brief Cuenta los empleados activos(FALSE)
 * \param La estructura
 * \param int tamaño
 * \return Retorna la cantidad de empleados que encontro
 *
 */
int ContadorEmpleados(Employee* list, int len)
{
	int contEmpleados;
	contEmpleados=0;
	if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				contEmpleados++;
			}
		}
	}
	return contEmpleados;
}
/** \brief Acumula los salarios de los empleados activos(FALSE)
 * \param La estructura
 * \param int tamaño
 * \return Retorna la suma de todos los salarios
 *
 */
float AcumuladorSueldos(Employee* list, int len)
{
	float acumSueldos;
	acumSueldos=0;
	if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				acumSueldos=acumSueldos+list[i].salary;
			}
		}
	}
	return acumSueldos;
}
/** \brief Modifica los empleados con un menu interno ya que la consigna pedia modificar alguno de los valores y no todos a la vez.
 * \param La estructura
 * \param int tamaño
 * \return Retorna -1 en caso de error, 0 si se realizo correctamente
 *
 */
int ModificarEmpleadoPorId (Employee* list, int len)
{
	int rtn=-1;
	int idEmpleado;
	int opcion;
	printEmployees(list,len);
	idEmpleado = PedirEnteroFull("Ingrese ID de empleado a modificar: ", len);
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty==FALSE && list[i].id==idEmpleado)
		{
			MostrarTercerMenu();
			opcion = PedirEnteroFull("\nIngrese opcion: ",5);
			switch(opcion)
			{
			case 1:
				GetString("Ingrese nuevo nombre: ", list[i].name);
				rtn=0;
				break;
			case 2:
				GetString("Ingrese nuevo apellido: ", list[i].lastName);
				rtn=0;
				break;
			case 3:
				list[i].salary=PedirEntero("Ingrese nuevo salario: ");
				rtn=0;
				break;
			case 4:
				list[i].sector=PedirEntero("Ingrese nuevo sector: ");
				rtn=0;
				break;
			case 5:
				GetString("Ingrese nuevo nombre: ", list[i].name);
				GetString("Ingrese nuevo apellido: ", list[i].lastName);
				list[i].salary=PedirEntero("Ingrese nuevo salario: ");
				list[i].sector=PedirEntero("Ingrese nuevo sector: ");
				rtn=0;
				break;

			}
			//break;
			//rtn = 0;
		}
	}
	return rtn;
}
/** \brief Compara un empleado de la estructura con el promedio para encontrar a quienes lo superen.
 * \param La estructura
 * \param int tamaño
 * \param float promedio desde el main
 * \return int Retorna la cantidad de empleados activos(FALSE) que se encontraron con mayor salario que el promedio
 *
 */
int EmpleadosConMayorSalario(Employee* list,int len, float promedio)
{
	int empleadosArribaDelPromedio=0;
	if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].salary > promedio)
			{
				empleadosArribaDelPromedio++;
				MostrarUnEmpleado(list[i]);

			}
		}
	}
	return empleadosArribaDelPromedio;
}
