/*
 ============================================================================
 Name        : TP_2.c
 Author      : Dana Szumigraj

El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
número de Id. El resto de los campos se le pedirá al usuario.

2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o Código de vuelo

3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.

4. INFORMAR:
1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’

1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún pasajero.
2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "ArrayPassenger.h"
#include "inputs.h"
#include "Herramientas.h"


#define MAXPASAJEROS 2000



int main(void) {

	setbuf(stdout, NULL);

	int opcionIngresada;
	int opcionMostrar;

	int idAux = 100;
	char name[51];
	char lastname[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;

	int orden;
	int flagPasajeros = 0;

	float totalPasajes;
	float promedioPasajes;
	int contadorPromedio;

	Passenger pasajeros[MAXPASAJEROS];
	initPassengers(pasajeros, MAXPASAJEROS);

	//BUCLE MENU PRINCIPAL
	do{
	opcionIngresada = menu(opcionIngresada);
	fflush(stdin);
	//SWITCH OPCION MENU PPAL
	switch(opcionIngresada)
	{
	//ALTAS DE PASAJEROS
	case 1:
		idAux++;
		if(utn_getName(name, "\nIngrese el nombre del pasajero", "\nEl nombre ingresado no es valido")==0)
		{
			if(utn_getName(lastname, "\nIngrese el apellido del pasajero", "\nEl apellido ingresado no es valido")==0)
			{
				getString(flyCode, "\nIngrese el codigo de vuelo");
				utn_caracteresAMayus(flyCode);
				if(utn_getFloat(&price, "\nIngrese el precio del vuelo", "\nEl precio ingresado no es valido", 1000, 9999999)==0)
				{
					if(utn_getNumber(&typePassenger, "\nIngrese el tipo de pasajero (1- TURISTA 2- EJECUTIVO 3- VIP)", "\nEl dato ingresado no es valido", 1, 3)==0)
					{
						if(utn_getNumber(&statusFlight, "\nIngrese el estado del vuelo (1- ACTIVO 2- CANCELADO)", "\nEl estado de vuelo ingresado no es valido",  1, 2)==0)
						{
							if(addPassenger(pasajeros, MAXPASAJEROS, idAux, name, lastname, price, typePassenger, statusFlight, flyCode) == 0)
								{
									printf("\nEl pasajero fue ingresado correctamente");
									flagPasajeros = 1;
								}
							else
							{
								printf("\nError, intente nuevamente");
							}
						}
					}

				}
			}
		}
	break;
	//MODIFICAR PASAJEROS
	case 2:
		if (flagPasajeros == 0)
		{
			printf("\nDebe ingresar algun pasajero primero");
		}
		else
		{
			modifyPassenger(pasajeros, MAXPASAJEROS, idAux, name, lastname, price, typePassenger, statusFlight, flyCode);
		}
	break;
	//ELIMINAR PASAJERO
	case 3:
		if (flagPasajeros == 0)
		{
			printf("\nDebe ingresar algun pasajero primero");
		}
		else
		{
			removePassenger(pasajeros, MAXPASAJEROS, idAux);
		}
	break;



	//ORDENAMIENTO DE PASAJEROS
	case 4:
					if(flagPasajeros == 1)
					{
						opcionMostrar = menuInformar(opcionMostrar);
						switch(opcionMostrar)
						{
						case 1:
							if(utn_getNumber(&orden, "\n1-Ordenar de manera ascendente. \n2-Ordenar de manera descendente.", "\nEl dato ingresado no es valido", 1, 2)==0)
							{
								if(sortPassengers(pasajeros, MAXPASAJEROS, orden)==0)
								{
									printPassenger(pasajeros, MAXPASAJEROS);
								}
								else
								{
									printf("\nError, intente nuevamente");
								}
							}
						break;
						case 2:
							totalPasajes =  calcularTotal(pasajeros, MAXPASAJEROS);
							promedioPasajes = calcularPromedio(pasajeros, MAXPASAJEROS, totalPasajes);
							contadorPromedio = contadorSuperaPromedio(pasajeros, MAXPASAJEROS, promedioPasajes);
							printf("\nTotal de los pasajes: %2.f"
									"\nPromedio de los pasajes: %2.f"
									"\nPasajeros que superan el promedio: %d \n", totalPasajes, promedioPasajes, contadorPromedio);
						break;
						case 3:
							if(utn_getNumber(&orden, "\n1-Ordenar de manera ascendente. \n2-Ordenar de manera descendente.", "\nEl dato ingresado no es valido", 1, 2)==0)
							{
								if(sortPassengersByCode(pasajeros, MAXPASAJEROS, orden)==0)
								{
									printPassenger(pasajeros, MAXPASAJEROS);
								}
								else
								{
									printf("\nError, intente nuevamente");
								}
							}
						break;
						}
					}
					else
					{
						printf("\nDebe ingresar algun pasajero primero");
					}
	break;

	case 5:
		idAux ++;
		strcpy(name, "Dana");
		strcpy(lastname, "Szumigraj");
		price = 10000;
		typePassenger = 1;
		statusFlight = 1;
		strcpy(flyCode, "ABM-408");
		addPassenger(pasajeros, MAXPASAJEROS, idAux, name, lastname, price, typePassenger, statusFlight, flyCode);

		idAux ++;
		strcpy(name, "Pepe");
		strcpy(lastname, "Argento");
		price = 60000;
		typePassenger = 3;
		statusFlight = 2;
		strcpy(flyCode, "KJW-862");
		addPassenger(pasajeros, MAXPASAJEROS, idAux, name, lastname, price, typePassenger, statusFlight, flyCode);

		idAux ++;
		strcpy(name, "Moni");
		strcpy(lastname, "Argento");
		price = 40000;
		typePassenger = 2;
		statusFlight = 2;
		strcpy(flyCode, "KLM-583");
		addPassenger(pasajeros, MAXPASAJEROS, idAux, name, lastname, price, typePassenger, statusFlight, flyCode);

		idAux ++;
		strcpy(name, "Juan");
		strcpy(lastname, "Perez");
		price = 20000;
		typePassenger = 1;
		statusFlight = 1;
		strcpy(flyCode, "MNE-601");
		addPassenger(pasajeros, MAXPASAJEROS, idAux, name, lastname, price, typePassenger, statusFlight, flyCode);

		flagPasajeros = 1;
	break;

	case 6:
		printf("\nVuelva pronto!!!");
	break;



	default:
		printf("\nOpcion no valida");
	break;

	}
	}while(opcionIngresada!=6);


	return 0;
}
