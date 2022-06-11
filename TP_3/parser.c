#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "Passenger.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		char id[TAM_DATO];
		char nombre[TAM_NOMBRE];
		char apellido[TAM_NOMBRE];
		char precio[TAM_DATO];
		char tipoPasajero[TAM_DATO];
		char codigoVuelo[TAM_DATO];
		char estadoVuelo[TAM_DATO];
		Passenger* unPasajero;

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);

		while(!feof(pFile))
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo)==7)
			{
				unPasajero = Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
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
	Passenger* unPasajero;
	unPasajero = Passenger_new();

	int retorno = -1;
	int cantidad;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			cantidad = fread(unPasajero, sizeof(Passenger), 1, pFile);
			printf("Leido: %d\n", cantidad);

			if(cantidad == 7)
			{
				ll_add(pArrayListPassenger, unPasajero);
				retorno = 0;
			}

		}
	}

    return retorno;
}
