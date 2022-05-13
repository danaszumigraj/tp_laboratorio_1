/*
 * ArrayPassenger.c
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

//INICIAR PASAJEROS
int initPassengers(Passenger* list, int len)
{
	int i = 0;

	for(; i < len; i++)
	{
		list[i].isEmpty = VACIO;
	}

	return 0;
}
//AGREGAR PASAJEROS
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	int i = 0;
	for(; i < len; i++)
	{
		if(list[i].isEmpty == VACIO)
		{
			list[i].id = id;
			list[i].price = price;
			list[i].typePassenger = typePassenger;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			strcpy(list[i].flycode, flycode);
			i = len + 1;
		}
	}
	return 0;
}
//ENCONTRAR PASAJEROS, FALTA VALIDAR SI NO HAY INGRESADOS Y SI EL ID ES INCORRECTO
int findPassengerById(Passenger* list, int len,int id)
{
	int i;
	int posicion;

	for(i=0; i<len; i++)
	{
		if(list[i].id ==id)
		{
			posicion = i;
			i = len + 1;
		}
		else
		{
			printf("El ID ingresado no es valido");
		}
	}

	return posicion;
}
//BORRAR PASAJEROS
int removePassenger(Passenger* list, int len, int id)
{
	int posicion;
	char respuesta = 'n';
	//BUSCO AL PASAJERO
	posicion = findPassengerById(list, len, id);
	//CONSULTO SI QUIERE ELIMINARLO
	printf("Esta seguro de que quiere eliminar al pasajero correspondiente al ID %d (ingrese s/n)?", id);
	scanf("%c", &respuesta);
	//ACA IRIA LA VALIDACION DE Q INGRESO SI O NO

	//ELIMINO O VUELVO AL MENU PPAL
	if(respuesta == 's')
	{
		list[posicion].isEmpty = -1;
		printf("El pasajero fue eliminado correctamente");
	}
	else
	{
		printf("Volviendo al menu principal...");
	}
	return 0;
}
//ORDENAR PASAJEROS
int sortPassengers(Passenger* list, int len, int order)
{

	return 0;
}
//IMPRIMIR INFO
int printPassenger(Passenger* list, int length)
{

	return 0;
}
