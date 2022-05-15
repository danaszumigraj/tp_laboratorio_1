/*
 * Herramientas.c
 *
 *  Created on: 14 may. 2022
 *      Author: Dana
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "ArrayPassenger.h"
#include "inputs.h"
#include "Herramientas.h"

void mostrarPasajero(Passenger *list, int len, int id)
{
	char tipoPasajero[20];
	char estadoVuelo [20];
	int i;
		for(i = 0; i<len; i++)
		{
			if(list[i].id == id)
			{
			{

				if (list[i].typePassenger == 1)
				{
					strcpy(tipoPasajero, "Turista");
				}
				else if(list[i].typePassenger == 2)
				{
					strcpy(tipoPasajero, "Ejecutivo");
				}
				else
				{
					strcpy(tipoPasajero, "VIP");
				}

				if(list[i].statusFlight == 1)
				{
					strcpy(estadoVuelo, "Activo");
				}
				else if(list[i].statusFlight == 2)
				{
					strcpy(estadoVuelo, "Inactivo");
				}

				printf("\n/**********************************************************************************************************************************************/\n"
						"\nID: %d || Nombre: %s || Apellido: %s || Cod. Vuelo: %s ||   Precio Vuelo: $%.2f ||  Clase: %s  || Estado del Vuelo: %s  \n"
						"\n/**********************************************************************************************************************************************/\n",
						list[i].id, list[i].name, list[i].lastName, list[i].flycode,
						list[i].price, tipoPasajero, estadoVuelo);
			}
		}
	}
}

float totalArrays(Passenger* valor, int len)
{
	int i;
	float acumulador = 0;
	for(i=0; i < len; i++)
	{
		if(valor[i].isEmpty != -1)
		{
			acumulador = acumulador + valor[i].price;
		}
	}
	return acumulador;
}
float promedioArrays(Passenger* valor, int len, float total)
{
	float promedio = 0;
	int i;
	int contador = 0;
	for(i=0; i < len; i++)
	{
		if(valor[i].isEmpty != -1)
		{
			contador++;
		}
		promedio = total/contador;
	}
	return promedio;
}
int contadorPromedioMayor(Passenger* valor, int len, float promedio)
{
		int i;
		int contador = 0;
		for(i=0; i < len; i++)
		{
			if(valor[i].isEmpty != -1)
			{
				if(valor[i].price > promedio)
				{
					contador++;
				}
			}
		}
	return contador;
}



