/*
 ============================================================================
 Name        : TP1.c
 Author      : Gil Miguel Ángel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main()
{
	setbuf(stdout, NULL);

	char respuesta='s';
	int opcion;

	float primerNumero;
	float segundoNumero;

	primerNumero=0;
	segundoNumero=0;

	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	float resultadoFactorialA;
	float resultadoFactorialB;

	do
	{
		printf("1. Ingresar 1er operando (A=%.2f)\n",primerNumero);
		printf("2. Ingresar 2do operando (B=%.2f)\n",segundoNumero);

		printf("3. Calcular operaciones\n");
		printf("   1) Calcular la suma (A+B) \n");
		printf("   2) Calcular la resta (A-B) \n");
		printf("   3) Calcular la division (A/B) \n");
		printf("   4) Calcular la multiplicacion (A*B) \n");
		printf("   5) Calcular el factorial (A! y B!) \n");

		printf("4. Informar resultados\n");
		printf("   1) “El resultado de A+B es: r” \n");
		printf("   2) “El resultado de A-B es: r” \n");
		printf("   3) “El resultado de A/B es: r” \n");
		printf("   4) “El resultado de A*B es: r” \n");
		printf("   5) “El factorial de A es: r1 y El factorial de B es: r2” \n");

		printf("5. Salir\n");

		printf("Elija una de las 5 opciones\n");
		fflush(stdin);
		scanf("%d", &opcion);

		switch (opcion)
		{
			case 1:
				printf("Ingrese el 1er operando: \n");
				fflush(stdin);
				scanf("%f", &primerNumero);
				break;
			case 2:
				printf("Ingrese el 2do operando: \n");
				fflush(stdin);
				scanf("%f", &segundoNumero);
				break;
			case 3:
				resultadoSuma=sumar(primerNumero,segundoNumero);
				resultadoResta=restar(primerNumero,segundoNumero);
				resultadoDivision=dividir(primerNumero,segundoNumero);
				resultadoMultiplicacion=multiplicar(primerNumero,segundoNumero);
				resultadoFactorialA=factorizar(primerNumero);
				resultadoFactorialB=factorizar(segundoNumero);
				printf("Operaciones realizadas\n");
				break;
			case 4:
				printf("El resultado de %.2f+%0f es: %.0f\n",primerNumero,segundoNumero,resultadoSuma);
				printf("El resultado de %.2f-%.2f es: %.2f\n",primerNumero,segundoNumero,resultadoResta);
				printf("El resultado de %.2f/%.2f es: %.2f\n",primerNumero,segundoNumero,resultadoDivision);
				printf("El resultado de %.2f*%.2f es: %.2f\n",primerNumero,segundoNumero,resultadoMultiplicacion);
				printf("El factorial de %.2f es: %.0f y el factorial de %.2f es: %.0f\n",primerNumero,resultadoFactorialA,segundoNumero,resultadoFactorialB);
				break;
			case 5:
				break;
			default:
				printf("Opción inválida, debe ser entre 1 y 5\n");
		}
		printf("Ingrese 's' para seleccionar más opciones\n");
		fflush(stdin);
		scanf("%c", &respuesta);
	} while (respuesta=='s');
}
