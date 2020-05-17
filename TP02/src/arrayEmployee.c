/*
 * arrayEmployee.c
 *
 *  Created on: 16 may. 2020
 *      Author: JUNMI
 */


#include "ArrayEmployee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int initEmployees(Employee* list, int len)
{
	int retorno=-1;
	    if(list!= NULL && len>0)
	    {
	        for(;len>0;len--)
	        {
	        	list[len-1].isEmpty=1;
	        }
	        retorno=0;
	    }
	    return retorno;
}

int existEmployees(Employee *list, int len)
{
	int retorno = -1;
    int i;

    for( i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            retorno = 0;
        }
    }
    return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int retorno = -1;

	if(list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL && salary>0 && sector>0)
	{
		list[id].id = id;
	    strcpy(list[id].name, name);
	    strcpy(list[id].lastName, lastName);
	    list[id].salary = salary;
	    list[id].sector = sector;
	    list[id].isEmpty = 0;
	    retorno = 0;
	}
 return retorno;
}


int printEmployees(Employee* list, int length)
{
  int retorno=-1;
  int i;

	    if(list!=NULL && length>=0)
	    {
	    	printf("***   ID   //    Last Name  //   Name   //    Salary   //    Sector \n ***");
	        for(i=0;i<length;i++)
	        {
	            if(list[i].isEmpty==1)
	                continue;
	            else
	            	printf("*** %d   //    %s   //    %s   //    %.2f   //    %d",list[i].id,list[i].lastName,list[i].name,list[i].salary,list[i].sector);
	        }
	        retorno=0;
	    }
	    return retorno;

}

int modifyEmployee(Employee* list, int len)
{
	    int retorno=-1;
	    int posicion;
	    int id;
	    char opcion;

	    if(list!=NULL && len>0)
	    {
	        utn_getInt("\n Escriba el ID del empleado que quiere modificar: ","\nError",1,sizeof(int),1,len,3,&id);
	        if(findEmployeeById(list,len,id,&posicion)==-1)
	        {
	            printf("\n ID no registrada");
	        }
	        else
	        {
	            do
	            {
	                utn_getChar("\nModify: \nA-Name\nB-Last Name\nC-Salary\nD-Sector \nE-Exit","\nError",'A','Z',1,&opcion);
	                switch(opcion)
	                {
	                    case 'A':
	                    	utn_getTexto("\n Ingrese el nombre: ","\nError",1,51,3,list[posicion].name);
	                        break;
	                    case 'B':
	                    	utn_getTexto("\n Ingrese el apellido: ","\nError",1,51,3,list[posicion].lastName);
	                        break;
	                    case 'C':
	                    	utn_getFloat("\n Ingrese el salario: ","\nError",1,30000,1,30000,3,&list[posicion].salary);
	                        break;
	                    case 'D':
	                    	utn_getInt("\n Ingrese el sector: ","\nError",1,sizeof(int),1,10,3,&list[posicion].sector);
	                        break;
	                    case 'E':
	                        break;
	                    default:
	                        printf("\n Opcion inválida");
	                }
	            }while(opcion!='E');
	            retorno=0;
	        }
	    }
	    return retorno;

}


int removeEmployee(Employee* list, int len, int id)
{
	int retorno=-1;
    int posicion;
	    if(list!=NULL && len>0 && id>0)
	    {

	        if(findEmployeeById(list,len,id,&posicion)==-1)
	        {
	            printf("\n ID no registrada");
	        }
	        else
	        {
	        	list[posicion].isEmpty=1;
	        	list[posicion].id=0;
	        	strcpy(list[posicion].name,"");
	        	strcpy(list[posicion].lastName,"");
	        	list[posicion].salary=0;
	        	list[posicion].sector=0;
	            retorno=0;
	        }
	    }
	    return retorno;
}

int findEmployeeById(Employee* list, int len,int id,int* position)
{
		int retorno = -1;
	    int i;
	    if(list!= NULL && len>=0 && id>0)
	    {
	        for(i=0;i<len;i++)
	        {
	            if(list[i].isEmpty==1)
	                continue;
	            else if(list[i].id==id)
	            {
	                retorno=0;
	                *position=i;
	                break;
	            }
	        }
	    }
	    return retorno;
}


int informe(Employee* list, int len)
{
	int retorno = -1;
	int option = 0;
	int order;

	if (list != NULL && len >0)
	{
		while (option != 3)
		{
			utn_getInt("\n\n 1- Lista de empleados alfabeticamente por apellido y sector \n 2- Salarios totales y promedio, y cuantos empleados superan el salario promedio\n 3- Salir\n Elegir opcion: ",
				"\nError\n",1,sizeof(int),1,5,3,&option);
			switch(option)
			{
			case 1:
				utn_getInt("\n Ordenar por apellido:\n1- Ascendente \n2- Descendente \n Elegir opción: ","\nError\n",1,sizeof(int),1,2,3,&order);
				sortEmployees(list,len,order);
				printEmployees(list,len);
				break;
			case 2:
				salaryReport(list,len);
				break;
			case 3:
				printf("\n Hecho \n");
				break;
			default:
				printf("\n Ingresa una opción de la 1 a la 3 \n");
			}
		}
		retorno = 0;
	}
	return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	Employee aux;

	if(list!= NULL && len>0 && order>0)
	{
		switch(order)
		{

		case 1:
			for(int i=0; i<len - 1; i++)
			{
				for(int j=i+1; j<len; j++)
				{
					if(strcmp(list[j].lastName, list[i].lastName) < 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
			retorno = 0;
			break;

			case 2:
			for(int i = 0; i < len - 1; i++)
			{
				for(int j = i + 1; j < len; j++)
				{
					if(strcmp(list[j].lastName, list[i].lastName) > 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
			retorno = 0;
			break;
		}

	}

 return retorno;
}
