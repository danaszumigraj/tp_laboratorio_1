/*
 * ArrayPassenger.c
 *
 *  Created on: 11 may. 2022
 *      Author: Dana
 */

#include "ArrayPassenger.h"
#include <string.h>

int initPassengers(Passenger* list, int len)
{
	int i = 0;

	//Hacemos un for con un indice (i), en la que, para cada posicion
	//de la estructura, dejando todas las flags isEmpty en VACIO (en el .h hay un
	// define que lo iguala a -1
	for(; i < len; i++)
	{
		list[i].isEmpty = VACIO;
	}

	return 0;
}

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
