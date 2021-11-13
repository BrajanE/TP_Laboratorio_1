#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "General.h"
#include "LinkedList.h"
#include "Employee.h"
#include "FuncEspecificas.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

