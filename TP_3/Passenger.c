/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* unPasajero;

	if(unPasajero!=NULL)
	{
		unPasajero = (Passenger*) malloc(sizeof(Passenger));
	}

	return unPasajero;
}

Passenger* Passenger_newParametros(char* id, char* nombre,char* apellido, char* precio, char* tipoPasajero, char* codigoVuelo, char* estadoVuelo)
{
	Passenger* unPasajero;
	unPasajero = Passenger_new();
	if(unPasajero != NULL)
	{
		if(Passenger_setId(unPasajero, atoi(id))==0)
		{
			if(Passenger_setNombre(unPasajero, nombre) == 0)
			{
				if(Passenger_setApellido(unPasajero, apellido)==0)
				{
					if(Passenger_setPrecio(unPasajero, atof(precio))==0)
					{
						if(Passenger_setTipoPasajero(unPasajero, atoi(tipoPasajero))==0)
						{
							if(Passenger_setCodigoVuelo(unPasajero, codigoVuelo)==0)
							{
								if(Passenger_setEstadoVuelo(unPasajero, estadoVuelo)==0)
								{
									return unPasajero;
								}
							}
						}
					}
				}
			}
		}

	}
	return NULL;
}

void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,int id)
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

int Passenger_setPrecio(Passenger* this, float precio)
{
	int retorno = -1;
	if(this!=NULL && precio!=NULL)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getPrecio(Passenger* this, float* precio)
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
	if(this!=NULL && estadoVuelo!=NULL)
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
int Passenger_printOnePassenger(Passenger* this)
{
	char tipoPasajero[20];
	char estadoVuelo[20];
	int retorno = -1;

	if(this != NULL)
	{
		if()
	}


	/*if (this->tipoPasajero == 1)
				{
					strcpy(tipoPasajero, "EconomyClass");
				}
				else if(this->tipoPasajero == 2)
				{
					strcpy(tipoPasajero, "FirstClass");
				}
				else
				{
					strcpy(tipoPasajero, "ExecutiveClass");
				}
*/




				printf("\n/**********************************************************************************************************************************************/\n"
						"\n%4d || %20s || %20s || $%.2f ||  $%.2f ||  %20s  ||  %20s  ||  %20s  \n"
						"\n/**********************************************************************************************************************************************/\n"
						);
				retorno = 0;



	return retorno;
}


