#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{	//cargamos cada empleado de la lista
	int ultimoIdCargado;
	char idStr[100];
	char nombreStr[100];
	char horasTrabajadasStr[100];
	char sueldoStr[100];
	Employee* pEmployee;
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreStr,horasTrabajadasStr,sueldoStr);
	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreStr,horasTrabajadasStr,sueldoStr);
		pEmployee = employee_newParametros(idStr,nombreStr,horasTrabajadasStr,sueldoStr);
		ll_add(pArrayListEmployee, pEmployee);
		employee_getId(pEmployee,&ultimoIdCargado);
	}
    return ultimoIdCargado;
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
	int ultimoIdCargado=-1;
	int i=0;
	Employee* pEmployee;
	while(!feof(pFile))
	{
		pEmployee=employee_new();
		fread(pEmployee,sizeof(pEmployee),1,pFile);
		if (pEmployee!=NULL)
		{
			i++;
			pEmployee=ll_get(pArrayListEmployee, i);
			employee_getId(pEmployee,&ultimoIdCargado);
		}
	}
    return ultimoIdCargado;
}
