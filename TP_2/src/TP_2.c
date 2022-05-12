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



int main(void) {

	setbuf(stdout, NULL);

	int opcionIngresada;

	int idAux;
	char nameAux[51];
	char lastNameAux[51];
	float priceAux;
	char flycodeAux[10];
	int typePassengerAux;

	int maxPasajeros = 2000;
	Passenger pasajeros[maxPasajeros];
	initPassengers(pasajeros, maxPasajeros);

	do{
	opcionIngresada = menu(opcionIngresada);
	fflush(stdin);

	switch(opcionIngresada)
	{
	case 1:
		idAux++;
		printf("Ingrese el nombre del pasajero");
		gets(nameAux);
		printf("Ingrese el apellido del pasajero");
		gets(lastNameAux);
		printf("Ingrese el precio del vuelo");
		obtenerFloar(&priceAux);
		printf("Ingrese el codigo de vuelo");
		gets(flycodeAux);
		printf("Ingrese el tipo de pasajero");
		obtenerInt(&typePassengerAux);

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
