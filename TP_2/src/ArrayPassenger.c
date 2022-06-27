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
#include "Herramientas.h"

//INICIAR PASAJEROS
int initPassengers(Passenger* list, int len)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = -1;
		}
		retorno = 0;
	}

	return retorno;
}
//AGREGAR PASAJEROS
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, int statusFlight, char flycode[])
{
	setbuf(stdout, NULL);
	int i = 0;
	int retorno = -1;

	if(list != NULL && len > 0)
	{

		for (; i < len; i++)
		{
			if (list[i].isEmpty == -1)
			{
				list[i].isEmpty = 0;
				list[i].id = id;
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				list[i].statusFlight = statusFlight;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				strcpy(list[i].flycode, flycode);

				printf("\nEl id generado es: %d\n", id);
				i = len + 1;
				retorno = 0;
			}
		}
	}
	return retorno;
}
//MODIFICAR PASAJEROS
int modifyPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, int statusFlight, char flycode[])
{
	int retorno = -1;
	int i;
	int respuesta;

	utn_getNumber(&id, "\nIngrese el ID del pasajero\n", "\nEl ID ingresado es un numero no valido\n" , 1, len);
	i = findPassengerById(list, len,id);

	if(i == -1)
	{
		printf("\nEl ID ingresado no es valido, intente nuevamente\n");
	}
	else
	{
		do{
			printOnePassenger(list, len, i);
			respuesta = menuModificar(respuesta);
			fflush(stdin);

			switch(respuesta)
			{
			case 1:
				if(utn_getName(name, "\nIngrese el nombre a modificar\n", "\nEl nombre ingresado no es valido\n") == 0)
				{
					strcpy(list[i].name, name);
					printf("\nEl nombre fue modificado correctamente\n");
				}
				else
				{
					printf("\nError, intente nuevamente\n");
				}
			break;
			case 2:
				if(utn_getName(lastName, "\nIngrese el apellido del pasajero\n", "\nEl apellido ingresado no es valido\n") == 0)
				{
					strcpy(list[i].lastName, lastName);
					printf("\nEl apellido fue modificado correctamente\n");
				}
				else
				{
					printf("\nError, intente nuevamente\n");
				}
			break;
			case 3:
				getString(flycode, "\nIngrese el codigo de vuelo", "\nEl codigo de vuelo no es valido");
				utn_caracteresAMayus(flycode);
				strcpy(list[i].flycode, flycode);
				printf("\nEl codigo de vuelo fue modificado correctamente\n");
			break;
			case 4:
				if(utn_getFloat(&price, "\nIngrese el precio del vuelo\n", "\nEl precio ingresado no es valido\n", 1000, 9999999)==0)
				{
					list[i].price = price;
					printf("\nEl precio fue modificado correctamente\n");
				}
				else
				{
					printf("\nError, intente nuevamente\n");
				}
			break;
			case 5:
				if(utn_getNumber(&typePassenger, "\nIngrese el tipo de pasajero (1- TURISTA 2- EJECUTIVO 3- VIP)\n", "\nEl dato ingresado no es valido\n", 1, 3)==0)
				{
					list[i].typePassenger = typePassenger;
					printf("\nEl tipo de pasajero fue modificado correctamente\n");
				}
			break;
			case 6:
				if(utn_getNumber(&statusFlight, "\nIngrese el estado del vuelo (1- ACTIVO 2- CANCELADO)\n", "\nEl estado de vuelo ingresado no es valido\n",  1, 2)==0)
				{
					list[i].statusFlight = statusFlight;
					printf("\nEl estado del vuelo fue modificado correctamente\n");
				}
			break;
			default:
				printf("\nOpcion no valida.\n");
			break;
			case 7:
				printf("\nVolviendo al menu principal...\n");
			}
		}while(respuesta!=7);
	}

	return retorno;
}
//ENCONTRAR PASAJEROS
int findPassengerById(Passenger *list, int len, int id)
{
	int i;
	int posicionADevolver = -1;

	if(list != NULL && len>0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].id == id)
			{
				posicionADevolver = i;
			}
		}
	}
	return posicionADevolver;
}
//BORRAR PASAJEROS
int removePassenger(Passenger* list, int len, int id)
{
	int i;
	char respuesta = 'n';
	int retorno = -1;


	if(list != NULL && len > 0)
	{
		utn_getNumber(&id, "\nIngrese el ID del pasajero\n", "\nEl ID ingresado es un numero no valido\n" , 1, len);
			i = findPassengerById(list, len,id);

			if(i == -1)
			{
				printf("\nEl ID ingresado no es valido, intente nuevamente\n");
			}
			else
			{
				printOnePassenger(list, len, i);
				printf("\nEsta seguro de que quiere eliminar al pasajero correspondiente al ID %d (ingrese s/n)?\n", id);
				scanf("%c", &respuesta);

				if(respuesta == 's')
				{
					list[i].isEmpty = -1;
					list[i].id = -1;
					printf("\nEl pasajero fue eliminado correctamente\n");
					retorno = 0;
				}
				else
				{
					printf("\nVolviendo al menu principal...\n");
				}
			}
	}
	return retorno;
}

//ORDENAR PASAJEROS POR APELLIDO Y TIPO DE PASAJERO
int sortPassengers(Passenger *list, int len, int order)
{
	int retorno = -1;

	Passenger listAux;

	if(list != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			for (int j = i+1; j < len; j++)
			{
				if (list[j].isEmpty != -1)
				{
					if (order == 1)
					{
						if(list[i].typePassenger > list[j].typePassenger)
						{
							retorno = 1;
						}
						else
						{
							if(list[i].typePassenger == list[j].typePassenger)
							{
								retorno = strcmp(list[j].lastName, list[i].lastName);
							}
						}
					}

					else
					{
						if(list[i].typePassenger < list[j].typePassenger)
						{
							retorno = 1;
						}
						else
						{
							if(list[i].typePassenger == list[j].typePassenger)
							{
								retorno = strcmp(list[i].lastName, list[j].lastName);
							}
						}
					}


					if (retorno == 1)
					{
						retorno = 0;

						listAux = list[i];
						list[i] = list[j];
						list[j] = listAux;

						j = i+1;
					}
				}
			}
		}
	}
	return retorno;
}
//ORDENAR PASAJEROS POR CODIGO DE VUELO Y ESTADOS ACTIVOS
int sortPassengersByCode(Passenger *list, int len, int order)
{
	int retorno = -1;

	Passenger listAux;
	if(list != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			for (int j = i+1; j < len; j++)
			{
				if (list[j].isEmpty != -1)
				{

					if (order == 1)
					{
						if(list[i].statusFlight > list[j].statusFlight)
						{
							retorno = 1;
						}
						else
						{
							if(list[i].statusFlight == list[j].statusFlight)
							{
								retorno = strcmp(list[j].flycode, list[i].flycode);
							}
						}
					}

					else
					{
						if(list[i].statusFlight < list[j].statusFlight)
						{
							retorno = 1;
						}
						else
						{
							if(list[i].statusFlight == list[j].statusFlight)
							{
								retorno = strcmp(list[i].flycode, list[j].flycode);
							}
						}
					}


					if (retorno == 1)
					{
						retorno = 0;

						listAux = list[i];
						list[i] = list[j];
						list[j] = listAux;

						j = i+1;
					}
				}
			}
		}
	}
	return retorno;
}

//IMPRIMIR TODA LA LISTA
int printPassenger(Passenger* list, int len)
{
	printf("\n||==================================================================================================================================================================||\n");
	for(int i=0;i<len;i++)
	{
		printOnePassenger(list, len, i);
	}
	printf("\n||==================================================================================================================================================================||\n");

	return 0;
}
//IMPRIMIR UN PASAJERO SOLO
void printOnePassenger(Passenger *list, int len, int i)
{
	char tipoPasajero[20];
	char estadoVuelo [20];

	if(list[i].isEmpty != -1)
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
			strcpy(estadoVuelo, "ACTIVO");
		}
		else if(list[i].statusFlight == 2)
		{
			strcpy(estadoVuelo, "CANCELADO");
		}

		printf(	"\n||ID: %-4d || Nombre: %-7s || Apellido: %-10s || Cod. Vuelo: %-9s ||   Precio Vuelo: $%-10.2f ||  Clase: %-9s  || Estado del Vuelo: %-9s  ||\n",
				list[i].id, list[i].name, list[i].lastName, list[i].flycode,
				list[i].price, tipoPasajero, estadoVuelo);
	}
}

}









