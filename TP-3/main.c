#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "General.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
	setbuf(stdout,NULL);
	int opcion;
	int ultimoId=1000; //teoricamente se tiene que pisar al cargar los archivos
	int corroboracion;
	int flagOpcion=-1;
	LinkedList* pArrayListEmployee = NULL;
	pArrayListEmployee = ll_newLinkedList();
	do{
		ShowMainMenu();
		opcion = PedirEnteroFull("Ingrese Opcion: ",10);
		switch(opcion)
		{
		case 1:
			ultimoId=controller_loadFromText("data.csv",pArrayListEmployee);
			MensajeDeCorroboracion(ultimoId,"Carga completa.\n","Error en la carga.\n");
			flagOpcion = 1;
			break;
		case 2:
			ultimoId=controller_loadFromBinary("data.csv",pArrayListEmployee);
			MensajeDeCorroboracion(ultimoId,"Carga completa.\n","Error en la carga.\n");
			flagOpcion = 1;
			break;
		case 3:
			ultimoId=IdAutomatico(ultimoId);
			corroboracion= controller_addEmployee(pArrayListEmployee,ultimoId);
			MensajeDeCorroboracion(corroboracion,"Alta exitosa.\n","Error al dar de Alta.\n");
			flagOpcion = 1;
			break;
		case 4:
			if(flagOpcion == 1)
			{
				do{
					ShowOrNot();
					opcion=PedirEnteroFull("Ingrese opcion: ",3);
					switch(opcion)
					{
						case 1:
							controller_ListEmployee(pArrayListEmployee);
							break;
						case 2:
							corroboracion=controller_editEmployee(pArrayListEmployee);
							MensajeDeCorroboracion(corroboracion,"Modificacion exitosa.\n","Error al modificar.\n");
							break;
					}
				}while(opcion!=3);

			}
			break;
		case 5:
			if(flagOpcion == 1)
			{
				do{
					ShowOrNot();
					opcion=PedirEnteroFull("Ingrese opcion: ",3);
					switch(opcion)
					{
					case 1:
						controller_ListEmployee(pArrayListEmployee);
						break;
					case 2:
						corroboracion=controller_removeEmployee(pArrayListEmployee);
						MensajeDeCorroboracion(corroboracion,"Baja de empleado exitosa.\n","No se pudo dar de baja.\n");
						break;
					}
				}while(opcion!=3);
			}
			break;
		case 6:
			if(flagOpcion == 1)
			{
				controller_ListEmployee(pArrayListEmployee);
			}
			break;
		case 7:
			if(flagOpcion == 1)
			{
				corroboracion=controller_sortEmployee(pArrayListEmployee);
				MensajeDeCorroboracion(corroboracion,"Ordenado exitosamente.\n","Error al ordenar los datos.\n");
			}
			break;
		case 8:
			if(flagOpcion == 1)
			{
				corroboracion=controller_saveAsText("data.csv",pArrayListEmployee);
				MensajeDeCorroboracion(corroboracion,"Se guardaron los datos exitosamente.\n","Error al guardar los datos.\n");
			}
			break;
		case 9:
			if(flagOpcion == 1)
			{
				corroboracion=controller_saveAsBinary("data.bin",pArrayListEmployee);
				MensajeDeCorroboracion(corroboracion,"Se guardaron los datos exitosamente.\n","Error al guardar los datos.\n");
			}
			break;
		if(flagOpcion == -1)

			{
				printf("\nPrimero debe dar de alta al menos un empleado.\n");
			}
		}
	}while(opcion != 10);
	ll_deleteLinkedList(pArrayListEmployee);
    return 0;
}
