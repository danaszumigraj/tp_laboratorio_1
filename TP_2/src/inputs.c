/*
 * mostrar.c
 *
 *  Created on: 11 may. 2022
 *      Author: Dana
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

void getInt(int* variableRecibida, char textoAMostrar [])
{
	char numeroIngresado[256];
	printf(textoAMostrar);
	scanf("%s", numeroIngresado);

	fflush(stdin);
	while(validarInt(numeroIngresado)==-1)
	{
		printf(textoAMostrar);
		scanf("%s", numeroIngresado);
		validarInt(numeroIngresado);
		fflush(stdin);
	}

	variableRecibida = atoi(numeroIngresado);
}

void getFloat(float* variableRecibida, char textoAMostrar[])
{
	printf(textoAMostrar);
	scanf("%f", variableRecibida);
	fflush(stdin);
}

void getArray(char arrayRecibido[], char textoAMostrar [])
{
	printf(textoAMostrar);
	gets(arrayRecibido);
	fflush(stdin);
}

/***********************************VALIDACIONES***********************************/

void validarInt()
{
	int retorno = 0;

    for (int i = 0; i < strlen(variableRecibida); i++)
    {
        if(!isdigit(variableRecibida[i]) ) {
            printf("Ingrese un numero valido");
            retorno = -1;
        }

    }
    return retorno;
}
