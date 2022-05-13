/*
 * mostrar.c
 *
 *  Created on: 11 may. 2022
 *      Author: Dana
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "ArrayPassenger.h"
#include "inputs.h"

//MENU PPAL
int menu(int opcion)
{
		printf("1. ALTAS\n");
		printf("2. MODIFICAR\n");
		printf("3. BAJA\n");
		printf("4. INFORMAR\n");
		printf("5. CARGA FORZADA\n");
		printf("6. SALIR\n");

	printf("\nIngrese una opción: \n");
	scanf("%d", &opcion);


	return (opcion);
}
//SUBMENU MODIFICAR
int menuModificar(int opcion)
{
	printf("1. Modificar nombre del pasajero\n");
	printf("2. Modificar apellido del pasajero\n");
	printf("3. Modificar precio del vuelo\n");
	printf("4. Modificar codigo de vuelo\n");
	printf("5. Modificar tipo de pasajero\n");
	printf("6. SALIR\n");

		printf("\nIngrese una opción: \n");
		scanf("%d", &opcion);

	return (opcion);
}
//OBTENER INT, TIENE VALIDACION
void getInt(int* variableRecibida, char textoAMostrar [])
{
	char numeroIngresado[256];
	int N;
	do
	{
	printf(textoAMostrar);
	scanf("%s", numeroIngresado);
	N = validarInt(numeroIngresado);

	fflush(stdin);
	}while(N == -1);

	*variableRecibida = atoi(numeroIngresado);
}
//OBTENER FLOAT (FALTA VALIDAR)
void getFloat(float* variableRecibida, char textoAMostrar[])
{
	printf(textoAMostrar);
	scanf("%f", variableRecibida);
	fflush(stdin);
}
//OBTENER ARRAY, TIENE VALIDACION DE CARACTER
void getArray(char arrayRecibido[], char textoAMostrar [])
{
	int D;

	do
	{
	printf(textoAMostrar);
	gets(arrayRecibido);
	D = validarChar(arrayRecibido);

	}while(D == -1);

}

/***********************************VALIDACIONES***********************************/

int validarInt(char numeroIngresado[])
{
	int retorno = 0;

    for(int i= 0; i < strlen(numeroIngresado); i++)
    {
        if(!(isdigit(numeroIngresado[i]))) {
            printf("El numero ingresado no es valido\n");
            break;
            retorno = -1;
        }

    }
    return retorno;
}

int validarChar(char arrayIngresado[])
{
	int retorno = 0;

	for(int i= 0; i < strlen(arrayIngresado); i++)
	    {
	        if(!(isalpha(arrayIngresado[i])))
	        {
	            printf("El dato ingresado no es valido\n");
	            break;
	            retorno = -1;
	        }

	    }
	return retorno;
}


