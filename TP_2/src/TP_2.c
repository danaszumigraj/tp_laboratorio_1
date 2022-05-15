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


	int idAux = 100;
	char name[51];
	char lastname[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;


	int tipoDeBusqueda;
	int criterioDeOrden;
	int bandera = 0;

	float total;
	float promedio;
	int contadorMasPromedio;
	int validacionSort;

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
		utn_getName(name, "Ingrese el nombre del pasajero\n", "El nombre ingresado no es valido\n");
		utn_getName(lastname, "Ingrese el apellido del pasajero\n", "El apellido ingresado no es valido\n");
		utn_getFloat(&price, "Ingrese el precio del vuelo\n", "El precio ingresado no es valido\n", 1000, 9999999);
		getString(flyCode, "Ingrese el codigo de vuelo\n");
		utn_getNumber(&typePassenger, "Ingrese el tipo de pasajero (1- TURISTA 2- EJECUTIVO 3- VIP)\n", "El dato ingresado no es valido\n", 1, 3);
		utn_getNumber(&statusFlight, "Ingrese el estado del vuelo (1- ACTIVO 2- CANCELADO)\n", "El estado de vuelo ingresado no es valido\n",  1, 2);

		if(addPassenger(pasajeros, MAXPASAJEROS, idAux, name, lastname, price, typePassenger, statusFlight, flyCode) == 0)
		{
			printf("\nEl pasajero fue ingresado correctamente\n");
			bandera = 1;
		}
		else
		{
			printf("\nError, intente nuevamente\n");
		}

	break;
	//MODIFICAR PASAJEROS
	case 2:
		if (bandera == 0)
		{
			printf("\nDebe ingresar algun pasajero primero\n");
		}
		else
		{
			modifyPassenger(pasajeros, MAXPASAJEROS, idAux, name, lastname, price, typePassenger, statusFlight, flyCode);
		}
	break;
	//ELIMINAR PASAJERO
	case 3:
		if (bandera == 0)
		{
			printf("\nDebe ingresar algun pasajero primero\n");
		}
		else
		{
			removePassenger(pasajeros, MAXPASAJEROS, idAux);
		}
	break;



	//ORDENAMIENTO DE PASAJEROS
	case 4:
					if(bandera == 1)
					{
						utn_getNumber(&tipoDeBusqueda, "\n1-Ordenar por apellido y pasajero. \n2-Ordenar por codigo de vuelo.\n", "El dato ingresado no es valido\n", 1, 2);
						utn_getNumber(&criterioDeOrden, "\n1-Ordenar de manera ascendente. \n2-Ordenar de manera descendente.\n", "El dato ingresado no es valido\n", 1, 2);
						total =  totalArrays(pasajeros, MAXPASAJEROS);
						promedio = promedioArrays(pasajeros, MAXPASAJEROS, total);
						contadorMasPromedio = contadorPromedioMayor(pasajeros, MAXPASAJEROS, promedio);
						if(tipoDeBusqueda == 1)
						{
							validacionSort=sortPassengers(pasajeros, MAXPASAJEROS, criterioDeOrden);
						}
						else
						{
							validacionSort=sortPassengersByCode(pasajeros, MAXPASAJEROS, criterioDeOrden);
						}
						if(validacionSort == -1)
						{
							printf("Error, vuelva a ingresar");
						}

						printPassenger(pasajeros, MAXPASAJEROS);
						printf("La suma de todos los precios da %f \n y el promedio es %f \n, %d pasajeros que superan ese promedio: \n", total, promedio, contadorMasPromedio);
					}
					else
					{
						printf("\nDebe ingresar algun pasajero primero\n");
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
		statusFlight = 3;
		strcpy(flyCode, "KJW-862");
		addPassenger(pasajeros, MAXPASAJEROS, idAux, name, lastname, price, typePassenger, statusFlight, flyCode);

		idAux ++;
		strcpy(name, "Moni");
		strcpy(lastname, "Argento");
		price = 40000;
		typePassenger = 2;
		statusFlight = 3;
		strcpy(flyCode, "KLM-583");
		addPassenger(pasajeros, MAXPASAJEROS, idAux, name, lastname, price, typePassenger, statusFlight, flyCode);

		idAux ++;
		strcpy(name, "Juan");
		strcpy(lastname, "Perez");
		price = 20000;
		typePassenger = 1;
		statusFlight = 2;
		strcpy(flyCode, "MNE-601");
		addPassenger(pasajeros, MAXPASAJEROS, idAux, name, lastname, price, typePassenger, statusFlight, flyCode);

		bandera = 1;
	break;

	case 6:
		printf("Vuelva pronto!!!");
	break;



	default:
		printf("\nOpcion no valida.\n");
	break;

	}
	}while(opcionIngresada!=6);


	return 0;
}
