#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"
#include "Extras.h"


int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE *pFile;
	int retorno = -1;

	if(pArrayListPassenger!=NULL && path!=NULL)
	{
		pFile = fopen(path, "r");

		if(pFile!=NULL)
		{
			parser_PassengerFromText(pFile , pArrayListPassenger);
			printf("\nLa lista fue cargada con exito\n");
			retorno = 0;
		}
		else
		{
			printf("\nHubo un error al cargar la lista\n");
		}
		fclose(pFile);
	}
	return retorno;
}
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE *pFile;
	int retorno = -1;

	if(pArrayListPassenger!=NULL && path!=NULL)
	{
		pFile = fopen(path, "rb");

		if(pFile!=NULL)
		{
			parser_PassengerFromBinary(pFile,pArrayListPassenger);
			printf("\nLa lista fue cargada con exito\n");
			retorno = 0;
		}
		else
		{
			printf("\nHubo un error al cargar la lista\n");
		}
		fclose(pFile);
	}
	return retorno;
}
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(pArrayListPassenger!=NULL)
	{
		Passenger* unPasajero;

		int id;
		char nombreStr[TAM_NOMBRE];
		char apellidoStr[TAM_NOMBRE];
		int precio;
		int tipoPasajero;
		char codigoVueloStr[TAM_DATO];
		int estadoVuelo;

		char idStr[TAM_DATO];
		char precioStr[TAM_DATO];
		char tipoPasajeroStr[TAM_DATO];
		char estadoVueloStr[TAM_DATO];

		id = Passenger_newId(pArrayListPassenger);
		itoa(id, idStr, TAM_DECIMAL);

		if(utn_getName(nombreStr, "Ingrese el nombre del pasajero\n", "El nombre ingresado no es valido\n")==0)
		{
			if(utn_getName(apellidoStr, "Ingrese el apellido del pasajero\n", "El apellido ingresado no es valido\n")==0)
			{
				if(utn_getNumber(&precio, "Ingrese el precio\n", "El dato ingresado no es valido\n", 10000, 999999)==0)
				{
					itoa(precio, precioStr, TAM_DECIMAL);

					if(getString(codigoVueloStr, TAM_DATO, "\nIngrese el codigo de vuelo\n", "\nEl dato ingresado no es valido\n")==0)
					{
						if(utn_getNumber(&tipoPasajero, "Ingrese el tipo de pasajero (1- EconomyClass 2- FirstClass 3- ExecutiveClass)\n", "El dato ingresado no es valido\n", 1, 3)==0)
						{
							itoa(tipoPasajero, tipoPasajeroStr, TAM_DECIMAL);
							fflush(stdin);
							switch(tipoPasajero)
							{
							case 1:
								strcpy(tipoPasajeroStr, "EconomyClass");
							break;
							case 2:
								strcpy(tipoPasajeroStr, "FirstClass");
							break;
							case 3:
								strcpy(tipoPasajeroStr, "ExecutiveClass");
							break;
							}
							if(utn_getNumber(&estadoVuelo, "Ingrese el estado del vuelo (1- En Vuelo 2- Demorado 3- En Horario 4- Aterrizado)\n", "El estado de vuelo ingresado no es valido\n",  1, 4)==0)
							{
								itoa(estadoVuelo, estadoVueloStr, TAM_DECIMAL);
								switch(estadoVuelo)
								{
								case 1:
									strcpy(estadoVueloStr, "En Vuelo");
								break;
								case 2:
									strcpy(estadoVueloStr, "Demorado");
								break;
								case 3:
									strcpy(estadoVueloStr, "En Horario");
								break;
								case 4:
									strcpy(estadoVueloStr, "Aterrizado");
								break;
								}
								unPasajero = Passenger_newParametros(idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
								if(unPasajero!=NULL)
								{
									ll_add(pArrayListPassenger, unPasajero);
									printf("\nEl Pasajero fue agregado correctamente\n"
											"\nID generado: %s\n", idStr);
									retorno = 0;
								}
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;

	char nombre[TAM_NOMBRE];
	char apellido[TAM_NOMBRE];
	int precio;
	int tipoPasajero;
	char codigoVuelo [TAM_DATO];
	int estadoVuelo;

	char precioAux[TAM_DATO];
	char tipoPasajeroAux[TAM_DATO];
	char estadoVueloAux[TAM_DATO];

	int retorno = 0;
	int opcionMenuModificar = 0;
	int idABuscar;
	int i;

	if(pArrayListPassenger!=NULL)
	{
		utn_getNumber(&idABuscar, "Ingrese el ID del pasajero\n", "El dato ingresado no es valido\n", 1, ll_len(pArrayListPassenger) + 1);
		//i = ll_indexOf(pArrayListPassenger, &idABuscar);
		i = Passenger_get(pArrayListPassenger, idABuscar);
		if(i == -1)
		{
			printf("\nEl ID no coincide con ningun pasajero");
			retorno = -1;
		}
		else
		{
			unPasajero = ll_get(pArrayListPassenger, i);

			while(opcionMenuModificar!=7)
			{
				Passenger_printOnePassenger(unPasajero);
				opcionMenuModificar = menuModificar(opcionMenuModificar);
				switch(opcionMenuModificar)
				{
				case 1:
					if(utn_getName(nombre, "Ingrese el nombre del pasajero\n", "El nombre ingresado no es valido\n")==0)
					{
						if(Passenger_setNombre(unPasajero, nombre)==0)
						{
						printf("\nEl nombre fue modificado con exito\n");
						}
						else
						{
							printf("\nHubo un error al intentar modificar el nombre");
						}
					}
				break;
				case 2:
					if(utn_getName(apellido, "Ingrese el apellido del pasajero\n", "El apellido ingresado no es valido\n")==0)
					{
						if(Passenger_setApellido(unPasajero,apellido)==0)
						{
							printf("\nEl apellido fue modificado con exito\n");
						}
						else
						{
							printf("\nHubo un error al intentar modificar el apellido");
						}
					}
				break;
				case 3:
					if(utn_getNumber(&precio, "Ingrese el precio\n", "El dato ingresado no es valido\n", 10000, 999999)==0)
					{
						itoa(precio, precioAux, TAM_DECIMAL);
						if(Passenger_setPrecio(unPasajero, precio)==0)
						{
							printf("\nEl precio fue modificado con exito\n");
						}
						else
						{
							printf("\nHubo un error al intentar modificar el precio");
						}
					}
				break;
				case 4:
					if(getString(codigoVuelo, TAM_DATO, "\nIngrese el codigo de vuelo\n", "\nEl dato ingresado no es valido\n")==0)
					{
						utn_caracteresAMayus(codigoVuelo);
						if(Passenger_setCodigoVuelo(unPasajero, codigoVuelo)==0)
						{
						printf("\nEl codigo de vuelo fue modificado con exito\n");
						}
						else
						{
							printf("\nHubo un error al intentar modificar el codigo de vuelo");
						}
					}
				break;
				case 5:
					if(utn_getNumber(&tipoPasajero, "Ingrese el tipo de pasajero (1- EconomyClass 2- FirstClass 3- ExecutiveClass)\n", "El dato ingresado no es valido\n", 1, 3)==0)
					{
						itoa(tipoPasajero, tipoPasajeroAux, TAM_DECIMAL);
						fflush(stdin);
						switch(tipoPasajero)
						{
						case 1:
							strcpy(tipoPasajeroAux, "EconomyClass");
						break;
						case 2:
							strcpy(tipoPasajeroAux, "FirstClass");
						break;
						case 3:
							strcpy(tipoPasajeroAux, "ExecutiveClass");
						break;
						}
						if(Passenger_setTipoPasajero(unPasajero, tipoPasajero)==0)
						{
							printf("\nEl tipo de pasajero fue modificado con exito\n");
						}
						else
						{
							printf("\nHubo un error al intentar modificar el tipo de pasajero");
						}
					}
				break;
				case 6:
					if(utn_getNumber(&estadoVuelo, "Ingrese el estado del vuelo (1- En Vuelo 2- Demorado 3- En Horario 4- Aterrizado)\n", "El estado de vuelo ingresado no es valido\n",  1, 4)==0)
					{
						itoa(estadoVuelo, estadoVueloAux, TAM_DECIMAL);
						switch(estadoVuelo)
						{
						case 1:
							strcpy(estadoVueloAux, "En Vuelo");
						break;
						case 2:
							strcpy(estadoVueloAux, "Demorado");
						break;
						case 3:
							strcpy(estadoVueloAux, "En Horario");
						break;
						case 4:
							strcpy(estadoVueloAux, "Aterrizado");
						break;
						}
						if(Passenger_setEstadoVuelo(unPasajero, estadoVuelo)==0)
						{
							printf("\nEl estado de vuelo fue modificado con exito\n");
						}
						else
						{
							printf("\nHubo un error al intentar modificar el estado de vuelo");
						}
					}
				break;
				case 7:
					printf("\nVolviendo al menu principal...\n");
				break;
				default:
					printf("\nOpcion no valida\n");
				break;

				}
			}
		}
	}
	return retorno;
}
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;

	int retorno = -1;
	char respuesta;
	int idABuscar;
	int i;

		if(pArrayListPassenger!=NULL)
		{
			utn_getNumber(&idABuscar, "Ingrese el ID del pasajero\n", "El dato ingresado no es valido\n", 1, ll_len(pArrayListPassenger) + 1);
			//i = ll_indexOf(pArrayListPassenger, &idABuscar);
			i = Passenger_get(pArrayListPassenger, idABuscar);
			if(i == -1)
			{
				printf("\nEl ID no coincide con ningun pasajero");
			}
			else
			{
				unPasajero = ll_get(pArrayListPassenger, i);
				Passenger_printOnePassenger(unPasajero);

				printf("\nEsta seguro de que quiere borrar a este pasajero? Ingrese s/n\n");
				fflush(stdin);
				scanf("%c", &respuesta);
				respuesta = toupper(respuesta);
				while(respuesta!='S' && respuesta!='N')
				{
					printf("Error, por favor ingrese s/n");
					fflush(stdin);
					scanf("%c", &respuesta);
					respuesta = toupper(respuesta);
				}

				if(respuesta == 'S')
				{
					if(ll_remove(pArrayListPassenger, i)==0)
					{
						printf("\nEl pasajero fue eliminado con exito\n");
						retorno = 0;
					}
					else
					{
						printf("\nVolviendo al menu principal\n");
					}
				}
				else
				{
					printf("\nVolviendo al menu principal\n");
				}
			}
		}

	return retorno;
}
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* unPasajero;

	for(int i = 0; i < ll_len(pArrayListPassenger); i++)
	{
		unPasajero = (Passenger*) ll_get(pArrayListPassenger,i);
		Passenger_printOnePassenger(unPasajero);
		retorno = 0;
	}

	return retorno;
}
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	return 0;
}
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	return 0;
}
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	return 0;
}
