/*
 ============================================================================
 Name        : TP02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployee.h"
#include "utn.h"
#define QTY_EMPLOYEE 1000

int main(void)
{
	setbuf(stdout,NULL);

	Employee arrayEmployee[QTY_EMPLOYEE];
	initEmployees(arrayEmployee,QTY_EMPLOYEE);

	int option;
	int idEmployee = 0;
	int buscarId;

	while(option != 5)
		{
			utn_getInt("\n **** MENU ****\n"
					"1- Alta empleado \n"
					"2- Modificar empleado \n"
					"3- Baja empleado \n"
					"4- Informes \n"
					"5- Salir \n"
					" Elija una opción (primero, elige la primera): ","\nError\n",1,sizeof(int),1,5,3,&option);

			switch(option)
			{
			case 1:
				addEmployees(arrayEmployee,QTY_EMPLOYEE,&idEmployee);
				break;
			case 2:
				if(existEmployees(arrayEmployee,QTY_EMPLOYEE) == 0)
				{
					printEmployees(arrayEmployee,QTY_EMPLOYEE);
					modifyEmployees(arrayEmployee,QTY_EMPLOYEE);
				}
				else
					printf("\n Antes de elegir esta opción, elige la primera \n");
				break;
			case 3:
				if(existEmployees(arrayEmployee,QTY_EMPLOYEE) == 0)
				{
					utn_getInt("\n Escriba el ID del empleado que quiere eliminar: ","\nError",1,sizeof(int),1,QTY_EMPLOYEE,3,&findEmployeeById);
					removeEmployee(arrayEmployee,QTY_EMPLOYEE,findEmployeeById);
				}
				else
					printf("\n Antes de elegir esta opción, elige la primera \n");
				break;
			case 4:
				if(existEmployees(arrayEmployee,QTY_EMPLOYEE) == 0)
				   informe(arrayEmployee,QTY_EMPLOYEE);
				else
				printf("\n Antes de elegir esta opción, elige la primera\n");
				break;
			case 5:
				break;
			}
		}

	return 0;
}

