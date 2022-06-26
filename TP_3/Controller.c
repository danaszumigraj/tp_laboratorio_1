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
	int retorno = -1;
	FILE* pFile;

	if(pArrayListPassenger!=NULL)
	{
		if(path!=NULL)
		{
			if(ll_len(pArrayListPassenger) > 0)
			{
				ll_clear(pArrayListPassenger);
			}

			pFile = fopen(path, "r");

			if(pFile!=NULL)
			{
				if(parser_PassengerFromText(pFile , pArrayListPassenger)==0)
				{
					retorno = 0;
				}
			}
			fclose(pFile);
		}
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
			if(parser_PassengerFromBinary(pFile,pArrayListPassenger)==0)
			{
				retorno = 0;
			}
		}
		fclose(pFile);
	}
	return retorno;
}
int controller_addPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayManualPassenger, LinkedList* pArrayRemovedPassenger)
{
	int retorno = -1;
	if(pArrayManualPassenger!=NULL)
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

		int i;

		if(ll_isEmpty(pArrayListPassenger)==0)
		{
			id = Passenger_newId(pArrayListPassenger) + 1;
		}
		else
		{
			id = Passenger_newId(pArrayManualPassenger) + 1;
		}

		i = Passenger_get(pArrayRemovedPassenger, id);
		if(i != -1)
		{
			id = id+1;
		}
		itoa(id, idStr, TAM_DECIMAL);

		if(utn_getName(nombreStr, "\nIngrese el nombre del pasajero", "\nEl nombre ingresado no es valido")==0)
		{
			if(utn_getName(apellidoStr, "\nIngrese el apellido del pasajero\n", "\nEl apellido ingresado no es valido")==0)
			{
				if(utn_getNumber(&precio, "\nIngrese el precio", "\nEl dato ingresado no es valido", 10000, 999999)==0)
				{
					itoa(precio, precioStr, TAM_DECIMAL);

					if(getString(codigoVueloStr, TAM_DATO, "\nIngrese el codigo de vuelo", "\nEl dato ingresado no es valido")==0)
					{
						utn_caracteresAMayus(codigoVueloStr);
						if(utn_getNumber(&tipoPasajero, "\nIngrese el tipo de pasajero (1- EconomyClass 2- FirstClass 3- ExecutiveClass)", "\nEl dato ingresado no es valido", 1, 3)==0)
						{
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
							if(utn_getNumber(&estadoVuelo, "\nIngrese el estado del vuelo (1- En Vuelo 2- Demorado 3- En Horario 4- Aterrizado)", "\nEl estado de vuelo ingresado no es valido",  1, 4)==0)
							{
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
									if(ll_isEmpty(pArrayListPassenger)==0)
									{
										if(ll_add(pArrayListPassenger, unPasajero)==0)
										{
											printf("\nEl Pasajero fue agregado correctamente"
													"\nID generado: %s\n", idStr);
											retorno = 0;
										}
									}
									else
									{
										if(ll_add(pArrayManualPassenger, unPasajero)==0)
										{
											printf("\nEl Pasajero fue agregado correctamente"
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

	char tipoPasajeroStr[TAM_DATO];
	char estadoVueloStr[TAM_DATO];

	int retorno = 0;
	int opcionMenuModificar = 0;
	int idABuscar;
	int i;

	if(pArrayListPassenger!=NULL)
	{
		utn_getNumber(&idABuscar, "\nIngrese el ID del pasajero\n", "\nEl dato ingresado no es valido", 1, Passenger_newId(pArrayListPassenger));
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
					if(utn_getName(nombre, "\nIngrese el nombre del pasajero", "\nEl nombre ingresado no es valido")==0)
					{
						if(Passenger_setNombre(unPasajero, nombre)==0)
						{
						printf("\nEl nombre fue modificado con exito\n");
						}
						else
						{
							printf("\nHubo un error al intentar modificar el nombre\n");
						}
					}
				break;
				case 2:
					if(utn_getName(apellido, "\nIngrese el apellido del pasajero", "\nEl apellido ingresado no es valido")==0)
					{
						if(Passenger_setApellido(unPasajero,apellido)==0)
						{
							printf("\nEl apellido fue modificado con exito\n");
						}
						else
						{
							printf("\nHubo un error al intentar modificar el apellido\n");
						}
					}
				break;
				case 3:
					if(utn_getNumber(&precio, "\nIngrese el precio", "\nEl dato ingresado no es valido", 10000, 999999)==0)
					{
						if(Passenger_setPrecio(unPasajero, precio)==0)
						{
							printf("\nEl precio fue modificado con exito\n");
						}
						else
						{
							printf("\nHubo un error al intentar modificar el precio\n");
						}
					}
				break;
				case 4:
					if(getString(codigoVuelo, TAM_DATO, "\nIngrese el codigo de vuelo", "\nEl dato ingresado no es valido")==0)
					{
						utn_caracteresAMayus(codigoVuelo);
						if(Passenger_setCodigoVuelo(unPasajero, codigoVuelo)==0)
						{
						printf("\nEl codigo de vuelo fue modificado con exito\n");
						}
						else
						{
							printf("\nHubo un error al intentar modificar el codigo de vuelo\n");
						}
					}
				break;
				case 5:
					if(utn_getNumber(&tipoPasajero, "\nIngrese el tipo de pasajero (1- EconomyClass 2- FirstClass 3- ExecutiveClass)", "\nEl dato ingresado no es valido", 1, 3)==0)
					{
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
						if(Passenger_setTipoPasajero(unPasajero, tipoPasajeroStr)==0)
						{
							printf("\nEl tipo de pasajero fue modificado con exito\n");
						}
						else
						{
							printf("\nHubo un error al intentar modificar el tipo de pasajero\n");
						}
					}
				break;
				case 6:
					if(utn_getNumber(&estadoVuelo, "\nIngrese el estado del vuelo (1- En Vuelo 2- Demorado 3- En Horario 4- Aterrizado)", "\nEl estado de vuelo ingresado no es valido",  1, 4)==0)
					{
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
						if(Passenger_setEstadoVuelo(unPasajero, estadoVueloStr)==0)
						{
							printf("\nEl estado de vuelo fue modificado con exito\n");
						}
						else
						{
							printf("\nHubo un error al intentar modificar el estado de vuelo\n");
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
int controller_removePassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayRemovedPassenger)
{
	Passenger* unPasajero;

	int retorno = -1;
	char respuesta;
	int idABuscar;
	int i;

		if(pArrayListPassenger!=NULL)
		{
			utn_getNumber(&idABuscar, "\nIngrese el ID del pasajero\n", "\nEl dato ingresado no es valido", 1, Passenger_newId(pArrayListPassenger));
			i = Passenger_get(pArrayListPassenger, idABuscar);
			if(i == -1)
			{
				printf("\nEl ID no coincide con ningun pasajero");
			}
			else
			{
				unPasajero = ll_get(pArrayListPassenger, i);
				Passenger_printOnePassenger(unPasajero);

				printf("\nEsta seguro de que quiere borrar a este pasajero? Ingrese s/n");
				fflush(stdin);
				scanf("%c", &respuesta);
				respuesta = toupper(respuesta);
				while(respuesta!='S' && respuesta!='N')
				{
					printf("\nError, por favor ingrese s/n");
					fflush(stdin);
					scanf("%c", &respuesta);
					respuesta = toupper(respuesta);
				}

				if(respuesta == 'S')
				{
					unPasajero = ll_pop(pArrayListPassenger, i);
					if(unPasajero!=NULL)
					{
						if(ll_add(pArrayRemovedPassenger, unPasajero)==0)
						{
							printf("\nEl pasajero fue eliminado con exito\n");
							retorno = 0;
						}
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

	printf("||===================================================================================================================||\n");
	for(int i = 0; i < ll_len(pArrayListPassenger); i++)
	{
		unPasajero = (Passenger*) ll_get(pArrayListPassenger,i);
		Passenger_printOnePassenger(unPasajero);
		retorno = 0;
	}
	printf("||===================================================================================================================||\n");

	return retorno;
}
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int orden;

	if(pArrayListPassenger!=NULL)
	{
		if(utn_getNumber(&orden, "\nOrdenar por apellido y nombre de forma: 1-ASCENDENTE 0-DESCENDENTE\n", "\nEl orden ingresado no es valido\n", 0, 1)==0)
		{
			printf("\nAguarde un segundo por favor...\n");
			ll_sort(pArrayListPassenger, Passenger_sortByApellido, orden);
			retorno = 0;
		}

	}
	return retorno;
}

int controller_sortPassengerById(LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(pArrayListPassenger!=NULL)
	{
		printf("\nAguarde un segundo por favor...\n");
		ll_sort(pArrayListPassenger, Passenger_sortById, 1);
		retorno = 0;
	}
	return retorno;
}
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;
	FILE* pFile;

	int retorno = -1;

	int id;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_NOMBRE];
	int precio;
	char tipoPasajero[TAM_DATO];
	char codigoVuelo [TAM_DATO];
	char estadoVuelo[TAM_DATO];

	int len;

	if(pArrayListPassenger!=NULL && path!=NULL)
	{
		pFile = fopen(path, "w");
		if(pFile!=NULL)
		{
			len = ll_len(pArrayListPassenger);
			if(len>0)
			{
				fprintf(pFile, "id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo \n");
				for(int i = 0; i<len; i++)
				{
					unPasajero = (Passenger*) ll_get(pArrayListPassenger,i);
					if(unPasajero!=NULL)
					{
						if(Passenger_getId(unPasajero, &id)==0)
						{
							if(Passenger_getNombre(unPasajero, nombre) == 0)
							{
								if(Passenger_getApellido(unPasajero, apellido)==0)
								{
									if(Passenger_getPrecio(unPasajero, &precio)==0)
									{
										if(Passenger_getTipoPasajero(unPasajero, tipoPasajero)==0)
										{
											if(Passenger_getCodigoVuelo(unPasajero, codigoVuelo)==0)
											{
												if(Passenger_getEstadoVuelo(unPasajero, estadoVuelo)==0)
												{
													fprintf(pFile, "%d, %s, %s, %d, %s, %s, %s \n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
													retorno = 0;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	fclose(pFile);
	return retorno;
}
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* unPasajero;

	int retorno = -1;

	if(pArrayListPassenger!=NULL && path!=NULL)
	{
		pFile = fopen(path, "wb");
		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			fwrite(unPasajero, sizeof(Passenger), 1, pFile);
			retorno = 0;
		}
		fclose(pFile);
	}

	return retorno;
}

int controller_corregirId(LinkedList* pArrayListPassenger, LinkedList* pArrayManualPassenger)
{
	Passenger* unPasajero;
	int id;

	int retorno = -1;

	if(pArrayListPassenger!=NULL && pArrayManualPassenger!=NULL)
	{
		if(ll_len(pArrayListPassenger)>0 && ll_len(pArrayManualPassenger)>0)
		{
			for(int i = 0; i < ll_len(pArrayManualPassenger) ; i++)
			{
				unPasajero = ll_pop(pArrayManualPassenger, i);
				if(unPasajero!=NULL)
				{
					id = Passenger_newId(pArrayListPassenger) + 1;
					if(Passenger_setId(unPasajero, id)==0)
					{
						if(ll_add(pArrayListPassenger, unPasajero)==0)
						{
							retorno = 0;
						}
					}
				}
			}
		}
	}
	return retorno;
}
