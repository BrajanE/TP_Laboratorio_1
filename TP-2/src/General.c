#include "General.h"

/** \brief Sirve para pedir un entero al usuario, validando que no sea una letra (sinceramente encontre la validacion por internet)
 * \param Mensaje desde el main
 * \return Retorna numero ingresado por el usuario
 *
 */
int PedirEntero(char mensaje[])
{
	/*int numeroIngresado;
	printf("%s", mensaje);
	scanf("%d",&numeroIngresado);
	return numeroIngresado;*/
	int numeroIngresado;
	char term;
	printf("%s",mensaje);
	//scanf(" %d",&numeroIngresado);
	//fflush(stdin);
	while(scanf("%d%c", &numeroIngresado, &term) != 2 || term != '\n')
	{
		printf("Digito invalido. %s",mensaje);
		//scanf("%d",&numeroIngresado);
		fflush(stdin);
	}
	return numeroIngresado;
}
/** \brief Funcion mas especializada que la anterior ya que permite manejarse dentro de una cantidad especifica de valores
 * \param Mensaje desde el main
 * \param numero maximo
 * \return Retorna numero ingresado por el usuario
 */
int PedirEnteroFull(char mensaje[], int maximo)
{
	int numeroIngresado;
	char term;
	printf("%s",mensaje);
	//scanf(" %d",&numeroIngresado);
	//fflush(stdin);
	while((scanf("%d%c", &numeroIngresado, &term) != 2 || term != '\n')||(numeroIngresado<1 || numeroIngresado>maximo))
	{
		printf("Digito invalido. %s",mensaje);
		//scanf("%d",&numeroIngresado);
		fflush(stdin);
	}
	return numeroIngresado;
}
/** \brief Sirve para pedir un flotante al usuario, validando que no sea una letra
 * \param Mensaje desde el main
 * \return Retorna numero flotante ingresado por el usuario
 *
 */
float PedirFlotante(char mensaje[])
{
	/*int numeroIngresado;
		printf("%s", mensaje);
		scanf("%d",&numeroIngresado);
		return numeroIngresado;*/
		float numeroIngresado;
		char term;
		printf("%s",mensaje);
		//scanf(" %d",&numeroIngresado);
		//fflush(stdin);
		while(scanf("%f%c", &numeroIngresado, &term) != 2 || term != '\n')
		{
			printf("Digito invalido. %s",mensaje);
			//scanf("%d",&numeroIngresado);
			fflush(stdin);
		}
		return numeroIngresado;
}

/** \brief Sirve para corroborar los resultados de las funciones necesarias
 * La use una sola vez aproposito para ver el funcionamiento pero me habian dicho que no estaba permitido usarla
 *
 * \param Int es el valor de las funciones los cuales siempre seran <0 en caso de error y >0 en caso de exito
 * \param Mensaje de exito desde el main
 * \param Mensaje de error desde el main
 * \return Void no retorna valores ya que es para enviar un mensaje
 *
 */
void MensajeDeAlerta(int rtn, char mensaje[], char mensajeError[])
{
	char teclaIngresada;
	if(rtn>=0)
	{
		printf("%s\n",mensaje);
	}else {
		printf("%s\n",mensajeError);
	}
	printf("Presione una tecla para continuar.");
	fflush(stdin);
	scanf("%c",&teclaIngresada);
	printf("\n");
}

/** \brief Sirve para obtener una letra o una cadena, validando que no se ingresen numeros
 * \param Mensaje desde el main
 * \param variable de cadena para que se guarde lo ingresado por el usuario
 * \return no retorna nada ya que lo que retorna es mediante el segundo parametro
 *
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

/** \brief Funcion que encontre por ahí para validar que no se ingresen numeros cuando necesite letras o cadenas
 * \param Mensaje desde el main
 * \return Retorna numero ingresado por el usuario
 *
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
				//printf("Digito invalido. Ingrese letras");
				rtn=-1;
				break;
			}
		}
	}
	return rtn;
}

/** \brief Muestra el menu principal
 *
 */
void MostrarMenu(void)
{
	printf("Bienvenido, ¿que desea realizar?: \n"
			"1- ALTA.\n"
			"2- MODIFICAR.\n"
			"3- BAJA.\n"
			"4- INFORMAR.\n"
			"5- SALIR.\n");
}

/** \brief Muestra un segundo menu para la opcion 4 del main
*/
void MostrarSegundoMenu(void)
{
	printf("1- Listado de empleados ordenados por apellido y sector.\n"
			"2- Total y Promedio de los salarios, y cuantos empleados superan el promedio.\n");
}
/** \brief Muestra un tercer menu para la opcion 2 del main
*/
void MostrarTercerMenu(void)
{
	printf("1- Modificar nombre.\n"
			"2- Modificar apellido.\n"
			"3- Modificar salario.\n"
			"4- Modificar sector.\n"
			"5- Todo");
}

/** \brief Permite corregir las cadenas enc aso de que el usuario ingrese muchas mayusculas
 * \param Recibe la cadena que se ingrese desde el "GetString"
 *
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
