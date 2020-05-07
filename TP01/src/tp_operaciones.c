/*
 * utn.c
 *
 *  Created on: 11 abr. 2020
 *      Author: Gil Miguel Ángel
 */

#include <stdio.h>
#include <stdlib.h>
#include "tp_operaciones.h"

float sumar(float a, float b)
{
	float resultado;
	resultado=a+b;
	return resultado;
}

float restar(float a,float b)
{
	float resultado;
	resultado=a-b;
	return resultado;
}

float multiplicar(float a,float b)
{
	float resultado;
	resultado=a*b;
	return resultado;
}

float dividir(float a,float b)
{
	float resultado;
	if(a==0||b==0)
	{
		printf("No se puede dividir por 0");
		exit(0);
	}
	resultado=a/b;
	return resultado;
}

int factorizar(int a)
{
	int entero;
	int resultado;
	int i;

	resultado=1;

	entero=(int)a;
	for(i=1; i<entero+1; i++){
			resultado=resultado*i;
	}
	return resultado;
}


