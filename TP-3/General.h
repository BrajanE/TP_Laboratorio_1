#ifndef GENERAL_H_
#define GENERAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

void ShowMainMenu();
int PedirEntero(char mensaje[]);
int PedirEnteroFull(char mensaje[],int maximo);
//float PedirFlotante(char mensaje[]);
int IdAutomatico(int id);
void MensajeDeCorroboracion(int corroboracion, char mensajeOk[], char mensajeError[]);
void CorreccionDeCadenas(char array[]);
int ValidacionDeStrings(char array[]);
void GetString(char mensaje[], char stringIngresado[]);
void ShowModificationMenu();
void ShowOrNot();
void ShowSortMenus();
void ShowSortMenuOrden();



#endif /* GENERAL_H_ */
