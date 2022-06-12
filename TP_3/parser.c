#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(pFile!=NULL)
	{
		if(pArrayListPassenger!=NULL)
		{
			int id;
			char nombre;
			char apellido;
			float precio;
			int tipoPasajero;
			char codigoVuelo;
			char estadoVuelo;
			Passenger* unPasajero;
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo)==7)
			{
				unPasajero = Passenger_newParametros(id, nombre, apellido, precio, tipoPasajero, codigoVuelo);
				if(unPasajero!=NULL)
				{
					ll_add(pArrayListPassenger, unPasajero);
					retorno = 0;
				}
			}
		}
	}

    return retorno;
}

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
