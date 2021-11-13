#include "General.h"

/**
 * Muestra el menu principal
 */
void ShowMainMenu()
{
	printf("Menu:\n"
     "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
     "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
     "3. Alta de empleado\n"
     "4. Modificar datos de empleado\n"
     "5. Baja de empleado\n"
     "6. Listar empleados\n"
     "7. Ordenar empleados\n"
     "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
     "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
    "10. Salir\n");
}

/**
 * Pide un numero entero, validadndo que no sea letra
 * @param mensaje
 * @return
 */
int PedirEntero(char mensaje[])
{
	int numeroIngresado;
	char term;
	printf("%s",mensaje);
	while((scanf("%d%c", &numeroIngresado, &term) != 2 || term != '\n'))
	{
		printf("Digito invalido. %s",mensaje);
		fflush(stdin);
	}
	return numeroIngresado;
}

/**
 * Pide un numero entero, validando que no sea letra y que este dentro de un rango maximo
 * @param mensaje
 * @param maximo
 * @return
 */
int PedirEnteroFull(char mensaje[],int maximo)
{
	int numeroIngresado;
	char term;
	printf("%s",mensaje);
	while((scanf("%d%c", &numeroIngresado, &term) != 2 || term != '\n')||(numeroIngresado<1 || numeroIngresado>maximo))
	{
		printf("Digito invalido. %s",mensaje);
		fflush(stdin);
	}
	return numeroIngresado;
}

/* Tal vez no se use
float PedirFlotante(char mensaje[])
{
	float numeroIngresado;
	char term;
	printf("%s",mensaje);
	while(scanf("%f%c", &numeroIngresado, &term) != 2 || term != '\n')
	{
		printf("Digito invalido. %s",mensaje);
		fflush(stdin);
	}
	return numeroIngresado;
}
*/
/**
 * Toma un id que aumentara segun la cantidad de ciclos que se realice
 * @param id
 * @return
 */
int IdAutomatico(int id)
{
	id++;

	return id;
}
/**
 * Funcion que toma los return de funciones para alertar si hubo un error o no
 * @param corroboracion
 * @param mensajeOk
 * @param mensajeError
 */
void MensajeDeCorroboracion(int corroboracion, char mensajeOk[], char mensajeError[])
{
	if(corroboracion>=0)
	{
		printf("%s",mensajeOk);
	}else {
		printf("%s",mensajeError);
	}
}

/**
 * Funcion que se usa en GetString principalmente para que el string se mantenga ordenado con la primera letra en amyuscula y las demas en minuscula
 * @param array
 */
void CorreccionDeCadenas(char array[])
{
	char auxiliar[51];
	strcpy(auxiliar,array);
	strlwr(auxiliar);
	for(int i=0; i<strlen(auxiliar);i++)
	{
		auxiliar[0] = toupper(auxiliar[0]);
		break;
	}
	strcpy(array,auxiliar);
}

/**
 * Valida que el array ingresado no sea numero
 * @param array
 * @return
 */
int ValidacionDeStrings(char array[])
{
	int rtn=0;
	for(int i=0;i<strlen(array);i++)
	{
		if(!(array[i]>=65 && array[i]<=90) && !(array[i]>=97 && array[i]<=122))
		{
			if(array[i]!=' ' || array[i-1]==' ')
			{
				rtn=-1;
				break;
			}
		}
	}
	return rtn;
}

/**
 * Pide una cadena de caracteres, validadndo que no sean numeros
 * @param mensaje
 * @param stringIngresado
 */
void GetString(char mensaje[], char stringIngresado[])
{
	int corroboracion;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",stringIngresado);
	corroboracion=ValidacionDeStrings(stringIngresado);
	CorreccionDeCadenas(stringIngresado);
	while(corroboracion ==-1)
	{
		printf("Digito invalido. Ingrese letras: ");
		fflush(stdin);
		scanf("%[^\n]",stringIngresado);
		corroboracion=ValidacionDeStrings(stringIngresado);
		CorreccionDeCadenas(stringIngresado);
	}
}

/**
 * Menu de modificar empleado punto 4
 */
void ShowModificationMenu()
{
	printf(	"\t1- Modificar Nombre\n"
			"\t2- Modificar Hs Trabajadas\n"
			"\t3- Modificar Sueldo\n"
			"\t4- Volver al menu principal\n");
}

/**
 * Menu para Punto 4 y 5, de manera que no se muestre el listado de los 1000 empleados si no es necesario
 */
void ShowOrNot()
{
	printf("\n\t1- Ver listado de Empleados\n"
			"\t2- Ingresar ID\n"
			"\t3- Volver al menu anterior\n");
}

/**
 * muestra el menu para ordenar Punto 7
 */
void ShowSortMenus()
{
	printf("\t1- Ordenar por ID\n"
			"\t2- Ordenar por Nombre\n"
			"\t3- Ordenar por Hs Trabajadas\n"
			"\t4- Ordenar por Sueldo\n"
			"\t5- Volver al menu principal\n");
}

/**
 * Muestra el orden a ordenar dentro del menu punto 7
 */
void ShowSortMenuOrden()
{
	printf("\tPresione 1: Orden descendente\n"
			"\tPresione 2: Orden ascendente\n");
}
