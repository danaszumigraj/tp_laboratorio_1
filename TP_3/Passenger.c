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
		unPasajero->tipoPasajero = 0;
		strcpy(unPasajero->codigoVuelo, " ");
		unPasajero->estadoVuelo = 0;
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
						if(Passenger_setTipoPasajero(unPasajero, atoi(tipoPasajero))==0)
						{
							if(Passenger_setCodigoVuelo(unPasajero, codigoVuelo)==0)
							{
								if(Passenger_setEstadoVuelo(unPasajero, atoi(estadoVuelo))==0)
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
	int len = 0;
	int id;

	len = ll_len(pArrayListPassenger);
	id = len + 1;

	return id;
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

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;
	if(this!=NULL)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;
	if(this!=NULL)
	{
		*tipoPasajero = this->tipoPasajero;
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

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo)
{
	int retorno = -1;
	if(this!=NULL)
	{
		this->estadoVuelo = estadoVuelo;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo)
{
	int retorno = -1;
	if(this!=NULL && estadoVuelo!=NULL)
	{
		*estadoVuelo = this->estadoVuelo;
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
	int tipoPasajero;
	char codigoVuelo [TAM_DATO];
	int estadoVuelo;

	char tipoPasajeroAux[TAM_DATO];
	char estadoVueloAux[TAM_DATO];


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
							if(Passenger_getTipoPasajero(this, &tipoPasajero)==0)
							{
								if (tipoPasajero == 1)
												{
													strcpy(tipoPasajeroAux, "EconomyClass");
												}
												else if(this->tipoPasajero == 2)
												{
													strcpy(tipoPasajeroAux, "FirstClass");
												}
													else
													{
														strcpy(tipoPasajeroAux, "ExecutiveClass");
													}
								if(Passenger_getCodigoVuelo(this, codigoVuelo)==0)
								{
									if(Passenger_getEstadoVuelo(this, &estadoVuelo)==0)
									{
										if(estadoVuelo == 1)
										{
											strcpy(estadoVueloAux, "En Vuelo");
										}
										else if(estadoVuelo == 2)
											{
												strcpy(estadoVueloAux, "Demorado");
											}
											else if(estadoVuelo == 3)
												{
													strcpy(estadoVueloAux, "En Horario");
												}
												else
												{
													strcpy(estadoVueloAux, "Aterrizado");
												}
										printf("%d %13s %17s %15d %15s %18s %15s\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajeroAux, estadoVueloAux);
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


