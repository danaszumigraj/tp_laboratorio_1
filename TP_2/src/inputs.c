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
	printf("6. Modificar el estado de vuelo\n");
	printf("7. SALIR\n");

		printf("\nIngrese una opción: \n");
		scanf("%d", &opcion);

	return (opcion);
}
//OBTENER ARRAY, TIENE VALIDACION DE CARACTER
void getString(char arrayRecibido[], char textoAMostrar [])
{
	printf(textoAMostrar);
	gets(arrayRecibido);
	fflush(stdin);
}
int myGets(char *cadena, int longitud)
{
	int retorno = -1;
	if (cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
	{
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n')
		{
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

int getInt(int* pResultado)
{
int retorno=-1;
char buffer[64];
if(pResultado != NULL)
{
	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
	{
		*pResultado = atoi(buffer);
		retorno = 0;
	}
}
return retorno;
}

int esNumerica(char* cadena)
{
int i=0;
int retorno = 1;
if(cadena != NULL && strlen(cadena) > 0)
{
	while(cadena[i] != '\0')
	{
		if(cadena[i] < '0' || cadena[i] > '9' )
		{
			retorno = 0;
			break;
		}
		i++;
	}
}
return retorno;
}



int utn_getNumber(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int bufferInt;
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0)
		{
			if (bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}



int getFloat(float *pResultado)
{
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
		{
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo)
{
	float bufferFloat;
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (getFloat(&bufferFloat) == 0)
		{
			if (bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int utn_getName(char* cadena, char* mensaje, char* mensajeError)
{
	int retorno = 1;

	while(retorno != 0)
	{
		printf(mensaje);
		fflush(stdin);
		gets(cadena);
		for (int i = 0; i < strlen(cadena); i++)
		{
			if(isalpha(cadena[i]) == 0 && isspace(cadena[i]) == 0 && cadena[i] != 'ñ')
			{
				retorno = 1;
				printf(mensajeError);
				break;
			}
			retorno = 0;
		}
	}

	utn_corregirMayus(cadena);

	return retorno;
}

void utn_corregirMayus(char* cadena)
{
	strlwr(cadena);

	cadena[0] = toupper(cadena[0]);

	for(int i = 0; i < strlen(cadena); i++)
	{
		if (cadena[i] == ' ')
		{
			cadena[i + 1] = toupper(cadena[i + 1]);
		}
	}
}



