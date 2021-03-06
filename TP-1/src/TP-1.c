/*
 ============================================================================
	Estrada Meza Brajan
	TP-1 Laboratorio y programacion 1
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "Func-Matematicas.h"
#include "Func-Menu.h"

int main(void) {
	setbuf(stdout,NULL);

	float numeroA;
	float numeroB;
	float suma;
	float resta;
	float division;
	float multiplicacion;
	float factorialA;
	float factorialB;
	int opcion;
	opcion = 0;

	int flag1 =0;
	int flag2 =0;
	int flag3 =0;

	do
	{
	opcion = MostrarMenu(opcion, numeroA,numeroB);

	switch(opcion)
	{
	case 1:
		numeroA = PedirFlotante();
		flag1=1;
		break;
	case 2:
		numeroB = PedirFlotante();
		flag2=1;
		break;
	case 3:
		if (flag1 == 1 && flag2 == 1)
		{
		suma = Sumar(numeroA,numeroB);
		resta = Restar(numeroA,numeroB);
		division = Dividir(numeroA,numeroB);
		multiplicacion = Multiplicar(numeroA,numeroB);
		factorialA = FactorizarA(numeroA);
		factorialB = FactorizarB(numeroB);
		flag3=1;
		printf("\nNumeros cargados y calculados.\n \n");
		} else
		{
			MensajeControl();
		}
		break;
	case 4:
		if (flag1 == 1 && flag2 == 1 && flag3 == 1)
		{
			printf("\n");
			MostrarSuma(numeroA,numeroB,suma);
			MostrarResta(numeroA,numeroB,resta);
			MostrarDivision(numeroA,numeroB,division);
			MostrarMultiplicacion(numeroA,numeroB,multiplicacion);
			MostrarFactorialA(numeroA, factorialA);
			MostrarFactorialB(numeroB,factorialB);
			printf("\nCalculos realizados. Si desea continuar ingrese una opcion.\n \n");
		} else
		{
			MensajeControl();
		}
		break;
	case 5:
		printf("¡Gracias por usar esta calculadora!\n");
		break;
	}

	}while (opcion !=5);

	return EXIT_SUCCESS;
}




