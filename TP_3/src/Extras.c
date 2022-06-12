/*
 * Extras.c
 *
 *  Created on: 8 jun. 2022
 *      Author: Dana
 */

int menuPrincipal(int opcionIngresada)
{
	printf("\nMenu:\n"
     "\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
     "\n2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
     "\n3. Alta de pasajero\n"
     "\n4. Modificar datos de pasajero\n"
     "\n5. Baja de pasajero\n"
     "\n6. Listar pasajeros\n"
     "\n7. Ordenar pasajeros\n"
     "\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
    "\n9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
    "\n10. Salir"
	"\nIngrese una opcion\n");
	scanf("%d", opcionIngresada);

	return opcionIngresada;
}
