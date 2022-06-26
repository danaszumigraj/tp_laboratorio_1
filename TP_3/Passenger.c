/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "Passenger.h"

Passenger* Passenger_new(void)
{
	Passenger* unPasajero = NULL;
	unPasajero = (Passenger*) malloc (sizeof(Passenger));

	if(unPasajero!=NULL)
	{
		unPasajero->id = 0;
		strcpy(unPasajero->nombre, " ");
		strcpy(unPasajero->apellido, " ");
		unPasajero->precio = 0;
		strcpy(unPasajero->tipoPasajero, " ");
		strcpy(unPasajero->codigoVuelo, " ");
		strcpy(unPasajero->estadoVuelo, " ");
	}

	return unPasajero;
}

Passenger* Passenger_newParametros(char* id, char* nombre,char* apellido, char* precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo)
{
	Passenger* unPasajero;
	unPasajero = Passenger_new();

	int retorno = -1;

	if(unPasajero != NULL)
	{
		if(Passenger_setId(unPasajero, atoi(id))==0)
		{
			if(Passenger_setNombre(unPasajero, nombre) == 0)
			{
				if(Passenger_setApellido(unPasajero, apellido)==0)
				{
					if(Passenger_setPrecio(unPasajero, atoi(precio))==0)
					{
						if(Passenger_setTipoPasajero(unPasajero, tipoPasajero)==0)
						{
							if(Passenger_setCodigoVuelo(unPasajero, codigoVuelo)==0)
							{
								if(Passenger_setEstadoVuelo(unPasajero, estadoVuelo)==0)
								{
									retorno = 0;
								}
							}
						}
					}
				}
			}
		}

	}
	if(retorno == -1)
	{
		unPasajero = NULL;
	}
	return unPasajero;
}

void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

int Passenger_newId(LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;

	int id;
	int idMasAlto = 0;

	if(pArrayListPassenger!=NULL)
	{
		for(int i = 0; i< ll_len(pArrayListPassenger); i++)
		{
			unPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			if(unPasajero!=NULL)
			{
				id = unPasajero->id;
				if(idMasAlto<id)
				{
					idMasAlto = id;
				}
			}
		}
	}

	return idMasAlto;
}


int Passenger_setId(Passenger* this, int id)
{
	int retorno = -1;

	if(this!=NULL && id>0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;
	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL && nombre!= NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getApellido(Passenger* this, char* apellido)
{
	int retorno = -1;
	if(this!=NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this!=NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = -1;
	if(this!=NULL)
	{
		strcpy(this->tipoPasajero, tipoPasajero);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = -1;
	if(this!=NULL)
	{
		strcpy(tipoPasajero, this->tipoPasajero);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setPrecio(Passenger* this, int precio)
{
	int retorno = -1;
	if(this!=NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getPrecio(Passenger* this, int* precio)
{
	int retorno = -1;
	if(this!=NULL && precio!=NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	int retorno = -1;
	if(this!=NULL)
	{
		strcpy(this->estadoVuelo, estadoVuelo);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	int retorno = -1;
	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(estadoVuelo, this->estadoVuelo);
		retorno = 0;
	}

	return retorno;
}
void Passenger_printOnePassenger(Passenger* this)
{
	int id;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_NOMBRE];
	int precio;
	char tipoPasajero[TAM_DATO];
	char codigoVuelo [TAM_DATO];
	char estadoVuelo[TAM_DATO];


	if(this != NULL)
	{
			if(Passenger_getId(this, &id)==0)
			{
				if(Passenger_getNombre(this, nombre) == 0)
				{
					if(Passenger_getApellido(this, apellido)==0)
					{
						if(Passenger_getPrecio(this, &precio)==0)
						{
							if(Passenger_getTipoPasajero(this, tipoPasajero)==0)
							{
								if(Passenger_getCodigoVuelo(this, codigoVuelo)==0)
								{
									if(Passenger_getEstadoVuelo(this, estadoVuelo)==0)
									{
										printf("||%-4d | %13s | %17s | %15d | %15s | %18s | %15s||\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
									}
								}
							}
						}
					}
				}
			}

		}
}

int Passenger_get(LinkedList* this, int id)
{
	Passenger* unPasajero;
	int retorno = -1;

	if(this!=NULL && id>0)
	{
		for(int i = 0; i < ll_len(this); i++)
		{
			unPasajero = (Passenger*) ll_get(this, i);
			if(unPasajero->id == id)
			{
				retorno = i;
			}
		}
	}
	return retorno;
}
int Passenger_sortByApellido(void* primerPasajero, void* segundoPasajero)
{
	int retorno = -1;

	Passenger* pPrimerPasajero;
	Passenger* pSegundoPasajero;

	char apellidoUno[TAM_NOMBRE];
	char nombreUno[TAM_NOMBRE];
	char apellidoDos[TAM_NOMBRE];
	char nombreDos[TAM_NOMBRE];

	if(primerPasajero != NULL && segundoPasajero!= NULL)
	{
		pPrimerPasajero = (Passenger*) primerPasajero;
		pSegundoPasajero = (Passenger*) segundoPasajero;

		if(Passenger_getApellido(pPrimerPasajero, apellidoUno)==0)
		{
			if(Passenger_getApellido(pSegundoPasajero, apellidoDos)==0)
			{
				retorno = strcmp(apellidoUno, apellidoDos);
				if(retorno == 0)
				{
					if(Passenger_getNombre(pPrimerPasajero, nombreUno)==0)
					{
						if(Passenger_getNombre(pSegundoPasajero, nombreDos)==0)
						{
							retorno = strcmp(nombreUno, nombreDos);
						}
					}
				}

			}
		}
	}

	return retorno;
}

int Passenger_sortById(void* primerPasajero, void* segundoPasajero)
{
	int retorno = -1;

	Passenger* pPrimerPasajero;
	Passenger* pSegundoPasajero;

	int idPrimerPasajero;
	int idSegundoPasajero;

	if(primerPasajero != NULL && segundoPasajero!= NULL)
	{
		pPrimerPasajero = (Passenger*) primerPasajero;
		pSegundoPasajero = (Passenger*) segundoPasajero;

		if(Passenger_getId(pPrimerPasajero, &idPrimerPasajero)==0)
		{
			if(Passenger_getId(pSegundoPasajero, &idSegundoPasajero)==0)
			{
				if(idPrimerPasajero > idSegundoPasajero)
				{
					retorno = 1;
				}
				else
				{
					retorno = 0;
				}


			}
		}
	}

	return retorno;
}

