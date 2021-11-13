#ifndef FUNCESPECIFICAS_H_
#define FUNCESPECIFICAS_H_
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "General.h"

void PrintAnEmployee(LinkedList* pArrayListEmployee, int index);
int FindEmployeeById(LinkedList* pArrayListEmployee, char mensaje[]);
int SaveEmployeesAsText(LinkedList* pArrayListEmployee, FILE* path);
int SaveEmployeesAsBinary(LinkedList* pArrayListEmployee, FILE* path);
int SortByNombre(void* primerDato, void* segundoDato);
int SortByHsTrabajadas(void* primerDato, void* segundoDato);
int SortBySueldo(void* primerDato, void* segundoDato);
int SortAllInOne(LinkedList* pArrayListEmployee);


#endif /* FUNCESPECIFICAS_H_ */
