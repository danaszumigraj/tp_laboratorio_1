/*
 * Extras.c
 *
 *  Created on: 8 jun. 2022
 *      Author: Dana
 */
#include <stdio.h>
#include <stdlib.h>
#include "Extras.h"

int menuPrincipal(int opcionIngresada)
{
	printf("\n-----------------Menu-----------------\n"
     "\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)."
     "\n2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario)."
     "\n3. Alta de pasajero"
     "\n4. Modificar datos de pasajero"
     "\n5. Baja de pasajero"
     "\n6. Listar pasajeros"
     "\n7. Ordenar pasajeros"
     "\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)."
    "\n9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario)."
    "\n10. Salir"
	"\nIngrese una opcion\n");
	fflush(stdin);
	scanf("%d", &opcionIngresada);
	return opcionIngresada;
}

int menuModificar(int opcionIngresada)
{
	printf("\n-----------------Modificar Pasajero-----------------\n"
		     "\n1. Modificar NOMBRE"
		     "\n2. Modificar APELLIDO"
		     "\n3. Modificar PRECIO DE VUELO"
		     "\n4. Modificar CODIGO DE VUELO"
		     "\n5. Modificar TIPO DE PASAJERO"
		     "\n6. Modificar ESTADO DE VUELO"
		     "\n7. SALIR"
			"\nIngrese una opcion\n");
	fflush(stdin);
	scanf("%d", &opcionIngresada);
	return opcionIngresada;
}
