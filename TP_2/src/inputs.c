/*
 * mostrar.c
 *
 *  Created on: 11 may. 2022
 *      Author: Dana
 */
#include <stdio.h>
#include <stdlib.h>

int menu(int opcion)
{
		printf("1) ALTAS\n");
		printf("2) MODIFICAR\n");
		printf("3) BAJA\n");
		printf("4) INFORMAR\n");
		printf("5) CARGA FORZADA\n");
		printf("6) SALIR\n");

	printf("\nIngrese una opción: \n");
	scanf("%d", &opcion);


	return (opcion);
}

void obtenerInt(int* variableRecibida)
{
	scanf("%d", variableRecibida);
	fflush(stdin);
}

void obtenerFloar(float* variableRecibida)
{
	scanf("%f", variableRecibida);
	fflush(stdin);
}

