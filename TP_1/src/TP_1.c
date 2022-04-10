/*
 ============================================================================
 Name        : TP_1.c
 Author      : Dana Szumigraj
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "calculos.h"

int opcionIngresada;
char respuesta = 0;
float km;
char seleccionAerolinea = 'y';
float precioAerolineas = 0;
float precioLatam = 0;

int main(void)
{

	setbuf(stdout, NULL);
		do{
			//MENU
			printf("\n1. Ingresar Kilómetros: (km=x)\n"
					"\n2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)\n"
					"\n3. Calcular todos los costos:\n"
					"\n4. Informar Resultados\n"
					"\n5. Carga forzada de datos\n"
					"\n6. Salir\n"
					);
			printf("\nIngrese una opcion: \n");
			fflush(stdin);
			scanf("%d", &opcionIngresada);
/*****************************************************************************************************/
			//ANALIZO OPCION
			switch(opcionIngresada)
			{
			//KM
			case 1:
				do{//VALIDO QUE ES UN NRO VALIDO DE KM
					printf("Ingrese los kilometros recorridos: ");
					fflush(stdin);
					scanf("%f", &km);

				  }while (km < 1);
			break;

			//AEROLINEAS
			case 2:
				do{//VALIDO SI QUIERE SEGUIR INGRESANDO DATOS

					//VALIDO QUE INGRESE Y O Z

						printf("Seleccione 'y' para Aerolineas o 'z' para Latam, una a la vez");
						fflush(stdin);
						scanf("%c", &seleccionAerolinea);
						while(seleccionAerolinea!='y' && seleccionAerolinea!='z')
						{
							printf("Error, seleccione 'y' para Aerolineas o 'z' para Latam, una a la vez");
							fflush(stdin);
							scanf("%c", &seleccionAerolinea);
						}


						//ANALIZO Y O Z
						do{//VALIDO QUE ES UN PRECIO VALIDO
							switch(seleccionAerolinea)
							{
								case 'y':
									printf("Ingrese el precio de vuelo: ");
									fflush(stdin);
									scanf("%f", &precioAerolineas);
								break;

								case 'z':
									printf("Ingrese el precio de vuelo: ");
									fflush(stdin);
									scanf("%f", &precioLatam);
								break;
							}
						}while(precioAerolineas < 0 || precioLatam<0);



					//PREGUNTO SI QUIERE INGRESAR MAS DATOS
					printf("\nDesea ingresar mas datos?(s/n)");
					fflush(stdin);
					scanf("%c", &respuesta);
					while(!(respuesta =='s' || respuesta =='n'))
					{
						printf("\nError, desea ingresar mas datos?(s/n)");
						fflush(stdin);
						scanf("%c", &respuesta);

					}


				}while(respuesta !='n');
		break;
		//CALCULOS
		case 3:

		break;

		case 4:

		break;

		case 5:

		break;
			}

		}while(opcionIngresada!=6);

	printf("Vuelva pronto!!!");


	return 0;
}






