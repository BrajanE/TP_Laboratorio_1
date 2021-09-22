#include "Func-Menu.h"

// Punto 1 y 2

float PedirFlotante(void)
{
	float unFlotante;
	printf("Ingrese numero: ");
	scanf("%f",&unFlotante);
	printf("\n");
	return unFlotante;
	/***
	 * Funcion que permite ingresar un flotante,
	 * no necesita parametro y devuelve el N° ingresado.
	 */

}
int MostrarMenu(int opcionMenu, float numeroA, float numeroB)
{
	/***
	 * Funcion que muestra el menu base sin carga de N° en primer opcion
	 * luego al ingresar un N° correspondiente con  la opcion despliega la
	 * version del menu cargada con los N° correspondientes.
	 */
	int opcion;
	if(opcionMenu == 0)
	{
		printf("1- Ingresar 1° operando (A=X).\n");
		printf("2- Ingresar 2° operando (B=Y).\n");
		printf("3- Calcular todas las operaciones:\n");
			 printf("	a) Calcular la suma (A+B).\n");
			 printf("	b) Calcular la resta (A-B).\n");
			 printf("	c) Calcular la division (A/B).\n");
			 printf("	d) Calcular la multiplicacion (A*B).\n");
		 	 printf("	e) Calcular la factorial (A!).\n");
		 	 printf("4- Informar resultados.\n");
		printf("5- Salir.\n");
		printf("Elija opcion para continuar: \n");
		scanf("%d",&opcion);
	}
	else if(opcionMenu >0 && opcionMenu<5)
	{

	 printf("1- Ingresar 1° operando (A=%.2f).\n",numeroA);
	 printf("2- Ingresar 2° operando (B=%.2f).\n",numeroB);
	 printf("3- Calcular todas las operaciones:\n");
	 	 printf("	a) Calcular la suma (%.2f+%.2f).\n",numeroA,numeroB);
	 	 printf("	b) Calcular la resta (%.2f-%.2f).\n",numeroA,numeroB);
	 	 printf("	c) Calcular la division (%.2f/%.2f).\n",numeroA,numeroB);
	 	 printf("	d) Calcular la multiplicacion (%.2f*%.2f).\n",numeroA,numeroB);
	 	 printf("	e) Calcular la factorial (%.2f!).\n",numeroA);
	 printf("4- Informar resultados.\n");
	 printf("5- Salir.\n");
	 printf("Elija opcion para continuar: \n");
	 scanf("%d",&opcion);

	}
	while (opcion <0 || opcion>5)
		{
			MensajeControl();
			scanf("%d",&opcion);
			/***
			 * En este while ingrese un mensaje de advertencia si el usuario
			 * ingresa un numero que no este contemplado en el menu y pide que se ingrese uno.
			 * no va a salir del bucle hasta que ingrese uno correcto.
			 */
		}
	return opcion;
}

// Punto 4
/***
 * 	Se muestran todos los calculos realizados si se realizaron las opciones anteriores.
 * 	No tienen return debido a que muestran directamente en pantalla, los resultados obtenidos.
 *
 * @param numeroA El numero ingresado en la primera opcion
 * @param numeroB Numero ingresado en la segunda opcion
 * @param El ultimo parametro es el resultado, especializado segun calculo.
 * Los muestra con 2 numeros despues de la coma, para evitar numeros largos y confusos.
 *
 * En el caso de la division y factorizacion tienen un mensaje en caso de que ingrese un numero invalido
 * por ejemplo que ingrese 0 como divisor; o numero no natural en caso de factorizacion.
 */
void MostrarSuma(float numeroA,float numeroB,float suma)
{
	printf("El resultado de %.2f + %.2f es: %.2f\n", numeroA,numeroB,suma);
}
void MostrarResta(float numeroA,float numeroB,float resta)
{
	printf("El resultado de %.2f - %.2f es: %.2f\n", numeroA,numeroB,resta);
}
void MostrarDivision(float numeroA,float numeroB,float division)
{
	if(numeroB != 0)
	{
		printf("El resultado de %.2f / %.2f es: %.2f\n", numeroA,numeroB,division);
	}
	else if(numeroB == 0)
	{
		printf("No se puede dividir por 0 (divisor = 0).\n");
	}
}
void MostrarMultiplicacion(float numeroA,float numeroB,float multiplicacion)
{
	printf("El resultado de %.2f * %.2f es: %.2f\n", numeroA,numeroB,multiplicacion);
}
void MostrarFactorialA(float numeroA, float factorialA)
{
	/***
	 * La variable entera "numControl" (A o B) la utiliza para verificar que el numero ingresado
	 * sea Natural mayor o igual a 0 haciendo una resta, ya que si el resto da 0 significa que es entero
	 * péro si da un numero despues de la coma es decimal y mostrara el mensaje de error.
	 */
	int numControl;
	numControl = numeroA;
	if(numeroA>=0 && (numControl-numeroA == 0))
	{
		printf("El resultado de %.2f ! es: %.2f\n", numeroA,factorialA);
	}
	else if (numeroA<0 || numControl-numeroA !=0)
	{
		printf("Para poder factorizar el numero A: %.2f debe ser N° Natural, mayor o igual a 0.\n",numeroA);
	}
}
void MostrarFactorialB(float numeroB, float factorialB)
{
	/***
	 * La variable entera "numControl" (A o B) la utiliza para verificar que el numero ingresado
	 * sea Natural mayor o igual a 0 haciendo una resta, ya que si el resto da 0 significa que es entero
	 * péro si da un numero despues de la coma es decimal y mostrara el mensaje de error.
	 */

	int numControl;
	numControl = numeroB;
		if(numeroB>=0 && (numControl-numeroB == 0))
		{
			printf("El resultado de %.2f ! es: %.2f\n", numeroB,factorialB);

		}
		else if (numeroB<0 || numControl-numeroB !=0)
		{
			printf("Para poder factorizar el numero B: %.2f debe ser N° Natural, mayor o igual a 0.\n \n", numeroB);
		}
}

// Extras
void MensajeControl(void)
{
	/***
	 * Funcion utilizada para mostrar un mensaje lo mas generica posible en caso de que el usuario
	 * ingrese un valor incorrecto.
	 */
	printf("Error. Podria probar las opciones 1 y 2 para ingresar numeros a calcular; 5 para salir!\n \n");
}

