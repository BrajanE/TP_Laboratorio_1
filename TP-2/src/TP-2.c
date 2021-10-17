/*
 ============================================================================

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "General.h"
#include "ArrayEmployees.h"



int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	int id;
	id=0;
	int flagMenu=0;
	int corroboracion;
	int idAuxiliar;
	float totalSalario=0;
	float promSalario=0;
	int cantEmpleados=0;
	int empleadosArribaDelPromedio=0;
	Employee listadoEmpleados[TAM_EMP];
	initEmployees(listadoEmpleados, TAM_EMP);
	do
	{
		MostrarMenu();
		opcion=PedirEnteroFull("Ingrese una opcion: \n",5);
		switch(opcion)
		{
		case 1:
			id=IdAutomatico(id);
			corroboracion=ingresarEmpleado(listadoEmpleados, TAM_EMP,id);
			MensajeDeAlerta(corroboracion, "Se dio de alta con exito.","Hubo un error al dar de alta.");
			flagMenu = 1;
			break;
		case 2:
			if(flagMenu ==0)
			{
				printf("Debe dar de alta 1 empleado.\n\n");
			} else if(flagMenu==1)
			{
			corroboracion= ModificarEmpleadoPorId (listadoEmpleados, TAM_EMP);
			if(corroboracion !=-1)
			{
				printf("Modificacion exitosa.\n\n");
			} else
			{
				printf("Error al modificar, es probable que no se encuentre el ID.\n\n");
			}
			}
			break;

		case 3:
			if(flagMenu ==0)
			{
				printf("Debe dar de alta 1 empleado.\n\n");
			} else if(flagMenu==1)
			{
				printEmployees(listadoEmpleados, TAM_EMP);
				idAuxiliar = PedirEnteroFull("Ingrese ID de empleado a remover: ", TAM_EMP);
				corroboracion = findEmployeeById(listadoEmpleados,TAM_EMP,idAuxiliar);
				if(corroboracion!= -1)
				{
					removeEmployee(listadoEmpleados,TAM_EMP,idAuxiliar);
					printf("Baja con exito.\n\n");
				} else{
				printf("No se encuentra el ID del empleado.\n\n");
				}
			}
			break;
		case 4:
			if(flagMenu ==0)
			{
				printf("Debe dar de alta 1 empleado.\n\n");
			} else if(flagMenu==1)
			{
				MostrarSegundoMenu();
				opcion=PedirEnteroFull("Ingrese opcion: \n",2);
				switch (opcion)
				{
				case 1:
					opcion=PedirEnteroFull("1- Ordenar por apellido.\n2- Ordenar por sector.\n", 2);
					corroboracion=sortEmployees(listadoEmpleados,TAM_EMP, opcion);
					if(corroboracion!=-1)
					{
						printf("Ordenado exitosamente:\n");
						printEmployees(listadoEmpleados, TAM_EMP);
					} else {
						printf("Error.");
					}
					break;
				case 2:
					corroboracion=CalculosConSalarios(listadoEmpleados,TAM_EMP,&totalSalario,&cantEmpleados);
					if(corroboracion!=-1 && cantEmpleados!=0)
					{
						promSalario=totalSalario/cantEmpleados;
						empleadosArribaDelPromedio=EmpleadosConMayorSalario(listadoEmpleados,TAM_EMP,promSalario);
						printf("El total de los sarios es: %.2f.\nLa cantidad de empleados son: %d.\nEl promedio es: %.2f.\nLa cantidad de empleados que superan el sueldo promedio son: %d\n\n",totalSalario,cantEmpleados,promSalario,empleadosArribaDelPromedio);

					} else{
						printf("No se pudieron realizar los calculos correspondientes.\n");
					}
					break;
				}
			}
			break;

		}

	}while(opcion!=5);

	return EXIT_SUCCESS;
}
