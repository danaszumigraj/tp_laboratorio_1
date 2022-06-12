#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int opcionMenuPrincipal = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    opcionMenuPrincipal = menuPrincipal(opcionMenuPrincipal);
    do{
        switch(opcionMenuPrincipal)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
            break;
            default:
            	printf("\nOpcion no valida, intente nuevamente\n");
            break;
        }
    }while(opcionMenuPrincipal != 10);
    return 0;
}

