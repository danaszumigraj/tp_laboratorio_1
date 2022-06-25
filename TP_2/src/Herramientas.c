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

//MENU PPAL
int menu(int opcion)
{
	printf("\n-------MENU PRINCIPAL-------"
			"\n1. ALTAS"
			"\n2. MODIFICAR"
			"\n3. BAJA"
			"\n4. INFORMAR"
			"\n5. CARGA FORZADA"
			"\n6. SALIR"
			"\n----------------------------"
			"\nIngrese una opción:");
	scanf("%d", &opcion);
	fflush(stdin);

	return (opcion);
}
//SUBMENU MODIFICAR
int menuModificar(int opcion)
{
	printf("\n---------------MODIFICAR---------------"
			"\n1. Modificar nombre del pasajero"
			"\n2. Modificar apellido del pasajero"
			"\n3. Modificar codigo de vuelo"
			"\n4. Modificar precio del vuelo"
			"\n5. Modificar tipo de pasajero"
			"\n6. Modificar el estado de vuelo"
			"\n7. SALIR\n"
			"\n---------------------------------------"
			"\nIngrese una opción:");
	scanf("%d", &opcion);
	fflush(stdin);

	return (opcion);
}

int menuInformar(int opcion)
{
	printf("\n-----------------------------------------------MOSTRAR-----------------------------------------------"
			"\n1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero."
			"\n2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio"
			"\n3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’"
			"\n4. SALIR\n"
			"\n-----------------------------------------------------------------------------------------------------"
			"\nIngrese una opción:");
	scanf("%d", &opcion);
	fflush(stdin);

return (opcion);
}

float calcularTotal(Passenger* list, int len)
{
	float acumulador = 0;

	for(int i=0; i < len; i++)
	{
		if(list[i].isEmpty != -1)
		{
			acumulador = acumulador + list[i].price;
		}
	}
	return acumulador;
}
float calcularPromedio(Passenger* list, int len, float total)
{
	float promedio = 0;
	int contador = 0;
	for(int i=0; i < len; i++)
	{
		if(list[i].isEmpty != -1)
		{
			contador++;
		}
	}
	promedio = total/contador;

	return promedio;
}
int contadorSuperaPromedio(Passenger* list, int len, float promedio)
{
	int contador = 0;
	for(int i=0; i < len; i++)
	{
		if(list[i].isEmpty != -1)
		{
			if(list[i].price > promedio)
			{
				contador++;
			}
		}
	}
	return contador;
}



