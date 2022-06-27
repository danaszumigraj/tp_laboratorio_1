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
    int flagGuardado = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    LinkedList* listaCargaManual = ll_newLinkedList();
    LinkedList* listaPasajerosEliminados = ll_newLinkedList();

    do{
    	opcionMenuPrincipal = menuPrincipal(opcionMenuPrincipal);
    	fflush(stdin);
        switch(opcionMenuPrincipal)
        {
        	//CARGAR ARCHIVO TEXTO
            case 1:
            	if(flagPasajeros==0)
            	{
					if(controller_loadFromText("data.csv",listaPasajeros)==0)
					{
						printf("\nLista cargada con exito");
						flagPasajeros = 1;
						if(flagAltaPasajeros == 1)
						{
							controller_corregirId(listaPasajeros, listaCargaManual);
							controller_sortPassengerById(listaPasajeros);

						}
					}
					else
					{
						printf("\nHubo un error al intentar cargar la lista");
					}
            	}
            	else
            	{
            		printf("\nNo puede cargar la lista dos veces");
            	}
            break;
            //CARGAR ARCHIVO BINARIO
            case 2:
            	if(flagPasajeros==0)
				{
					if(controller_loadFromBinary("data.bin",listaPasajeros)==0)
					{
						printf("\nLista binaria cargada con exito");
						flagPasajeros = 1;
						if(flagAltaPasajeros == 1)
						{
							controller_corregirId(listaPasajeros, listaCargaManual);
							controller_sortPassengerById(listaPasajeros);
						}
					}
					else
					{
						printf("\nHubo un error al intentar cargar la lista");
					}
				}
            	else
            	{
            		printf("\nNo puede cargar la lista dos veces");
            	}
            break;
            //AGREGAR PASAJERO
            case 3:
            	if(controller_addPassenger(listaPasajeros, listaCargaManual, listaPasajerosEliminados)==0)
            	{
            		flagAltaPasajeros = 1;
            		flagPasajeros = 1;
            	}
            	else
            	{
            		printf("\nHubo un error al intentar agregar al pasajero\n");
            	}
            break;
            //MODIFICAR PASAJERO
            case 4:
            	if(flagPasajeros==1)
            	{
					if(controller_editPassenger(listaPasajeros, listaCargaManual)!=0)
					{
						printf("\nNingun pasajero fue modificado\n");
					}
            	}
            	else
            	{
            		printf("\nPor favor ingrese un pasajero antes de hacer modificaciones");
            	}
            break;
            //BORRAR PASAJERO
            case 5:
            	if(flagPasajeros==1)
            	{
					if(controller_removePassenger(listaPasajeros, listaPasajerosEliminados, listaCargaManual)!=0)
					{
						printf("\nNingun pasajero fue eliminado\n");
					}
            	}
            	else
            	{
            		printf("\nPor favor ingrese un pasajero antes de hacer modificaciones");
            	}
            break;
            //LISTAR PASAJEROS
            case 6:
            	if(flagPasajeros == 1)
            	{
            	controller_ListPassenger(listaPasajeros, listaCargaManual);
            	}
            	else
            	{
            		printf("\nPor favor ingrese un pasajero antes de listar");
            	}
            break;
            //ORDENAR PASAJEROS
            case 7:
            	if(flagPasajeros==1)
            	{
            		if(controller_sortPassenger(listaPasajeros, listaCargaManual)==0)
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
            //GUARDAR TEXTO
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
            //GUARDAR BINARIO
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
            //SALIR
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
