#ifndef GENERAL_H_
#define GENERAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int PedirEntero(char mensaje[]);
int PedirEnteroFull(char mensaje[], int maximo);
float PedirFlotante(char mensaje[]);
void MensajeDeAlerta(int rtn, char mensaje[], char mensajeError[]);
void GetString(char mensaje[], char stringIngresado[]);
void MostrarMenu(void);
void MostrarSegundoMenu(void);
void MostrarTercerMenu(void);
int ValidacionDeStrings(char array[]);
void CorreccionDeCadenas(char array[]);

#endif /* GENERAL_H_ */
