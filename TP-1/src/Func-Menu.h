#ifndef FUNC_MENU_H_
#define FUNC_MENU_H_
#include <stdio.h>
#include <stdlib.h>
#include "Func-Matematicas.h"
// Punto 1 y 2
float PedirFlotante(void); /// Esta funcion la utilizo para ingresar un valor
/// por ese motivo no tiene parametros, lo realiza automaticamente.
/// Si retorna el numero ingresado, que es float debido a que el usuario
/// puede ingresar un flotante.
int MostrarMenu(int,float, float);
/// @param	Esta funcion muestra el menu en sus diferentes formas.
/// @param 	Retorna un entero por que dentro agrege una "scanf" para obtener
/// @param 	el numero entero correspondiente al menu (1,2,3,4,5) que sera usado posteriormente.
void MostrarOpciones(int opcion, float numeroA,float numeroB);
// Punto 4
void MostrarSuma(float,float,float);
void MostrarResta(float,float,float);
void MostrarDivision(float,float,float);
void MostrarMultiplicacion(float,float,float);
void MostrarFactorialA(float,float);
void MostrarFactorialB(float,float);
/**
 * En estas funciones no retornamos valores, son unicamente para
 * mostrar en pantalla los resultados de la opcion 4, los parametros
 * son los valores que debe mostrar.
 */
// Extras
void MensajeControl(void);

#endif /* FUNC_MENU_H_ */
