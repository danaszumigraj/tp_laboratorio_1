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
#include "ArrayPassenger.h"
#include "inputs.h"

#define MAXPASAJEROS 2000



int main(void) {

	setbuf(stdout, NULL);

	int opcionIngresada;
	int opcionSubMenu;

	int idAux = 100;
	char nameAux[51];
	char lastNameAux[51];
	float priceAux;
	char flycodeAux[10];
	int typePassengerAux;

	int buscarId;
	int posicionRecibida;





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

		getArray(nameAux, "Ingrese el nombre del pasajero\n");
		getArray(lastNameAux, "Ingrese el apellido del pasajero\n");
		getFloat(&priceAux, "Ingrese el precio del vuelo\n");
		getArray(flycodeAux, "Ingrese el codigo de vuelo\n");
		getInt(&typePassengerAux, "Ingrese el tipo de pasajero\n");

		addPassenger(pasajeros, MAXPASAJEROS, idAux, nameAux, lastNameAux, priceAux, typePassengerAux, flycodeAux);

	break;
	//MODIFICAR PASAJEROS
	case 2:
		getInt(&buscarId, "Ingrese el ID del pasajero\n");

		posicionRecibida = findPassengerById(pasajeros, MAXPASAJEROS,buscarId);
		//BUCLE SUBMENU
		do{
			menuModificar(opcionSubMenu);
			scanf("%d", &opcionSubMenu);
			fflush(stdin);

			switch(opcionSubMenu)
			{
			case 1:
				getArray(nameAux, "Ingrese el nuevo nombre del pasajero\n");
			break;
			case 2:
				getArray(lastNameAux, "Ingrese el nuevo apellido del pasajero\n");
			break;
			case 3:
				getFloat(&priceAux, "Ingrese el nuevo precio del vuelo\n");
			break;
			case 4:
				getArray(flycodeAux, "Ingrese el nuevo codigo de vuelo\n");
			break;
			case 5:
				getInt(&typePassengerAux, "Ingrese el nuevo tipo de pasajero\n");
			break;
			case 6:
				printf("Volviendo al menu principal...\n");
			break;
			default:
				printf("\nOpcion no valida.\n");
			break;
			}
		}while(opcionSubMenu!=6);
		//SE AGREGAN LOS DATOS MODIFICADOS
		addPassenger(pasajeros, MAXPASAJEROS, posicionRecibida, nameAux, lastNameAux, priceAux, typePassengerAux, flycodeAux);

	break;
	//ELIMINAR PASAJERO
	case 3:
		getInt(&buscarId, "Ingrese el ID del pasajero\n");

		removePassenger(pasajeros, MAXPASAJEROS, buscarId);
	break;
	//ORDENAMIENTO DE PASAJEROS
	case 4:

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
