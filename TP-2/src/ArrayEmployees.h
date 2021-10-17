#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "General.h"
#define TAM_EMP 7
#define TRUE 1
#define FALSE 0

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
} Employee;

void initEmployees(Employee* list, int len);
int IdAutomatico(int id);
int ingresarEmpleado(Employee* list, int len, int id);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
void MostrarUnEmpleado(Employee Empleado);
int printEmployees(Employee* list, int length);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int BajarEmpleado(Employee* list, int len);
int sortEmployees(Employee* list, int len, int order);
int CalculosConSalarios(Employee* list, int len, float *salarioTotal, int *totalEmpleados);
int ContadorEmpleados(Employee* list, int len);
float AcumuladorSueldos(Employee* list, int len);
int ModificarEmpleadoPorId (Employee* list, int len);
int EmpleadosConMayorSalario(Employee* list,int len, float promedio);
#endif /* ARRAYEMPLOYEES_H_ */
