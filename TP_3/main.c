#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Extras.h"

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
	setbuf(stdout,NULL);

    int opcionMenuPrincipal = 0;

    int flagPasajeros = 0;
    int flagAltaPasajeros = 0;
    int contadorPasajeros = 0;
    int flagGuardado = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	opcionMenuPrincipal = menuPrincipal(opcionMenuPrincipal);
        switch(opcionMenuPrincipal)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                if(flagAltaPasajeros == 1)
                {
                	controller_corregirId(listaPasajeros, contadorPasajeros);
                	controller_sortPassengerById(listaPasajeros);
                }
                flagPasajeros = 1;
            break;
            case 2:
            	controller_loadFromBinary("data.bin",listaPasajeros);
                if(flagAltaPasajeros == 1)
                {
                	controller_corregirId(listaPasajeros, contadorPasajeros);
                	controller_sortPassengerById(listaPasajeros);
                }
                flagPasajeros = 1;
            break;
            case 3:
            	if(controller_addPassenger(listaPasajeros)==-1)
            	{
            		printf("\nHubo un error al intentar agregar al pasajero\n");
            	}
            	else
            	{
            		contadorPasajeros = contadorPasajeros + 1;
            		flagAltaPasajeros = 1;
            		flagPasajeros = 1;
            	}
            break;
            case 4:
            	if(flagPasajeros==1)
            	{
					if(controller_editPassenger(listaPasajeros)==-1)
					{
						printf("\nNingun pasajero fue modificado\n");
					}
            	}
            	else
            	{
            		printf("\nPor favor ingrese un pasajero antes de hacer modificaciones");
            	}
            break;
            case 5:
            	if(flagPasajeros==1)
            	{
					if(controller_removePassenger(listaPasajeros)==-1)
					{
						printf("\nNingun pasajero fue eliminado\n");
					}
            	}
            	else
            	{
            		printf("\nPor favor ingrese un pasajero antes de hacer modificaciones");
            	}
            break;
            case 6:
            	if(flagPasajeros == 1)
            	{
            	controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nPor favor ingrese un pasajero antes de listar");
            	}
            break;
            case 7:
            	if(flagPasajeros==1)
            	{
            		if(controller_sortPassenger(listaPasajeros)==0)
            		{
            			printf("\nLista ordenada con exito\n");
            		}
            		else
            		{
            			printf("\nHubo un error al intentar ordenar la lista\n");
            		}
            	}
            	else
            	{
            		printf("\nPor favor ingrese un pasajero antes de ordenar\n");
            	}
            break;
            case 8:
            	if(flagPasajeros ==1)
            	{
            		if(controller_saveAsText("data.csv",listaPasajeros)==0)
            		{
            			printf("\nLista guardada con exito\n");
            			flagGuardado = 1;
            		}
            		else
            		{
            			printf("\nHubo un error al intentar guardar la lista\n");
            		}
            	}
            	else
            	{
            		printf("\nPor favor ingrese un pasajero o cargue la lista antes de guardar");
            	}
            break;
            case 9:
            	if(flagPasajeros ==1)
            	{
            		if(controller_saveAsBinary("data.bin",listaPasajeros)==0)
            		{
            			printf("\nLista guardada de forma binaria con exito\n");
            			flagGuardado = 1;
            		}
            		else
            		{
            			printf("\nHubo un error al intentar guardar la lista\n");
            		}
            	}
            	else
            	{
            		printf("\nPor favor ingrese un pasajero o cargue la lista antes de guardar");
            	}
            break;
            case 10:
            	if(flagGuardado == 0)
            	{
            		printf("\nPor favor guarde los datos antes de salir\n");
            	}
            	else
            	{
            		printf("\nVuelva pronto!!!\n");
            	}
            break;
            default:
            	printf("\nOpcion no valida, intente nuevamente\n");
            break;

        }
    }while(opcionMenuPrincipal != 10);
    return 0;
}
