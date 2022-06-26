#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "Passenger.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int r = 0;

	char id[TAM_DATO];
	char nombre[TAM_NOMBRE];
	char apellido[TAM_NOMBRE];
	char precio[TAM_DATO];
	char tipoPasajero[TAM_DATO];
	char codigoVuelo[TAM_DATO];
	char estadoVuelo[TAM_DATO];
	Passenger* unPasajero;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);

		while(!feof(pFile))
		{
			r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
			if(r==7)
			{
				unPasajero = Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
				if(unPasajero!=NULL)
				{
					if(ll_add(pArrayListPassenger, unPasajero)==0)
					{
						retorno = 0;
					}
				}
			}
		}
	}

    return retorno;
}

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;

	int retorno = -1;
	int cantidad;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			unPasajero = Passenger_new();
			cantidad = fread(unPasajero, sizeof(Passenger), 1, pFile);
			if(cantidad==1)
			{
				ll_add(pArrayListPassenger, unPasajero);
				retorno = 0;
			}

		}while(!feof(pFile));
	}
    return retorno;
}
