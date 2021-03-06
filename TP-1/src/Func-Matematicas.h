#ifndef FUNC_MATEMATICAS_H_
#define FUNC_MATEMATICAS_H_
#include <stdio.h>
#include <stdlib.h>
#include "Func-Menu.h"
/**
 *	Se declaran las funciones matematicas que van a ser utilizadas
 *	en el trabajo.
 * @param Son de tipo "float" en todos los casos para contemplar que
 * @param el/los usuarios ingresen numeros decimales.
 * @return Para respetar los parametros retornamos un flotante
 * resultante de los calculos hechos
 */
float Sumar (float,float);
float Restar (float,float);
float Dividir (float,float);
float Multiplicar (float,float);
float FactorizarA (float);
float FactorizarB (float);


#endif /* FUNC_MATEMATICAS_H_ */
