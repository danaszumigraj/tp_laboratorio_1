/*
 ============================================================================
 Name        : TP_2.c
 Author      : Dana Szumigraj
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "inputs.h"

#define MAXPASAJEROS 2000



int main(void) {

	setbuf(stdout, NULL);

	int opcionIngresada;

	int idAux;
	char nameAux[51];
	char lastNameAux[51];
	float priceAux;
	char flycodeAux[10];
	int typePassengerAux;

	Passenger pasajeros[MAXPASAJEROS];

	initPassengers(pasajeros, maxPasajeros);

	do{
	opcionIngresada = menu(opcionIngresada);
	fflush(stdin);

	switch(opcionIngresada)
	{
	case 1:
		idAux++;

		getArray(nameAux, "Ingrese el nombre del pasajero");
		getArray(lastNameAux, "Ingrese el apellido del pasajero");
		getFloat(priceAux, "Ingrese el precio del vuelo");
		getArray(flycodeAux, "Ingrese el codigo de vuelo");
		getInt(typePassengerAux, "Ingrese el tipo de pasajero");

		addPassenger(pasajeros, maxPasajeros, idAux, nameAux, lastNameAux, priceAux, typePassengerAux, flycodeAux);

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
