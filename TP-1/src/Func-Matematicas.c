#include "Func-Matematicas.h"
#include "Func-Menu.h"



float Sumar (float numeroA,float numeroB)
{
	float suma;
	suma = numeroA+numeroB;
	return suma;
	/**
	 * Esta funcion toma 2 parametros flotantes los suma,
	 * los guarda en la variable "suma" y lo retorna.
	 */
}
float Restar (float numeroA,float numeroB)
{
	float resta;
	resta = numeroA-numeroB;
	return resta;
	/**
	* Esta funcion toma 2 parametros flotantes los resta,
	* los guarda en la variable "resta" y lo retorna.
	*/
}
float Dividir (float numeroA,float numeroB)
{
	float division;
	division = numeroA/numeroB;
	return division;
	/**
	* Esta funcion toma 2 parametros flotantes los divide,
	* los guarda en la variable "division" y lo retorna.
	*/
}
float Multiplicar (float numeroA,float numeroB)
{
	float multiplicacion;
	multiplicacion = numeroA*numeroB;
	return multiplicacion;
	/**
	* Esta funcion toma 2 parametros flotantes los multiplica,
	* los guarda en la variable "multiplicacion" y lo retorna.
	*/
}
float FactorizarA (float numeroA)
{

	float factorial = 1;
	for(;numeroA>0 ;numeroA --)
	{
		factorial = factorial*numeroA;
	}
	return factorial;

}
float FactorizarB (float numeroB)
{

	float factorial = 1;
	for(;numeroB>0 ;numeroB --)
	{
		factorial = factorial*numeroB;
	}
	return factorial;

}
/**
	* Estas ultimas 2 funciones toman un flotante como parametro a factorizar,
	* el resultado se guarda en la variable "factorial" y lo retornan.
	* Si bien no se puede factorizar un decimal, se retorna uno para respetar el
	* numero ingresado ya que mientras los numeros despues de la coma sean 0
	* la factorizacion deberia realizarse sin problemas.
	*
	*/
