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
#include "menu.h"


int opcionIngresada;
float km;
char seleccionAerolinea;

float precioA;
float precioL;
float debitoA;
float debitoL;
float creditoA;
float creditoL;
float btcA;
float btcL;
float precioPorKmA;
float precioPorKmL;
float diferencia;


int main(void)
{

	setbuf(stdout, NULL);
		do{
			//MENU
			opcionIngresada = mostrarMenu(opcionIngresada, km, precioA, precioL);

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

					//VALIDO QUE INGRESE Y O Z

					printf("Seleccione 'a' para Aerolineas o 'l' para Latam, una a la vez");
					fflush(stdin);
					scanf("%c", &seleccionAerolinea);
					while(seleccionAerolinea!='a' && seleccionAerolinea!='l')
					{
						printf("Error, seleccione 'a' para Aerolineas o 'l' para Latam, una a la vez");
						fflush(stdin);
						scanf("%c", &seleccionAerolinea);
					}


					//ANALIZO AERO O LATAM
					do{
						switch(seleccionAerolinea)
						{
							case 'a':
								printf("Ingrese el precio de vuelo: ");
								fflush(stdin);
								scanf("%f", &precioA);
							break;
							case 'l':
								printf("Ingrese el precio de vuelo: ");
								fflush(stdin);
								scanf("%f", &precioL);
							break;
						}
					}while(precioA < 0 || precioL<0);//VALIDO QUE PONGA UN PRECIO REAL

		break;
		//CALCULOS
		case 3:
			debitoA = descuentoDebitoA(precioA);
			debitoL = descuentoDebitoL(precioL);
			creditoA = interesCreditoA(precioA);
			creditoL = interesCreditoL(precioL);
			btcA = bitcoinA(precioA);
			btcL = bitcoinL(precioL);
			precioPorKmA = precioUnitarioA(precioA, km);
			precioPorKmL = precioUnitarioL(precioL, km);
			diferencia = diferenciaAerolineas(precioA, precioL);

		break;
		//MUESTRO RESULTADOS
		case 4:
			printf("KMs ingresados: %.2f\n", km);
			//VALIDO QUE HAYAN INGRESADO DATOS DE AERO
			if (precioA > 0)
			{
			printf("\nAerolineas: \n");
			mostrarDebitoA (debitoA);
			mostrarCreditoA (creditoA);
			mostrarBitcoinA (btcA);
			mostrarPrecioUnitarioA (precioPorKmA);
			}
			else
			{
				printf("\nNo se ingresó ningun valor para Aerolineas\n");
			}
			//VALIDO QUE HAYAN INGRESADO DATOS DE LATAM
			if(precioL > 0)
			{
			printf("\nLatam: \n");
			mostrarDebitoL (debitoL);
			mostrarCreditoL (creditoL);
			mostrarBitcoinL (btcL);
			mostrarPrecioUnitarioL (precioPorKmL);
			}
			else
			{
				printf("\nNo se ingresó ningun valor para Latam\n");
			}
			mostrarDiferencia(diferencia);

		break;
		//CARGA FORZADA, HACE TODO SOLO
		case 5:
			km = 7090;
			precioA = 162965;
			precioL = 159339;

			debitoA = descuentoDebitoA(precioA);
			debitoL = descuentoDebitoL(precioL);
			creditoA = interesCreditoA(precioA);
			creditoL = interesCreditoL(precioL);
			btcA = bitcoinA(precioA);
			btcL = bitcoinL(precioL);
			precioPorKmA = precioUnitarioA(precioA, km);
			precioPorKmL = precioUnitarioL(precioL, km);
			diferencia = diferenciaAerolineas(precioA, precioL);

			printf("KMs ingresados: %f\n", km);

			printf("\nAerolineas: \n");
			mostrarDebitoA (debitoA);
			mostrarCreditoA (creditoA);
			mostrarBitcoinA (btcA);
			mostrarPrecioUnitarioA (precioPorKmA);
			printf("\nLatam: \n");
			mostrarDebitoL (debitoL);
			mostrarCreditoL (creditoL);
			mostrarBitcoinL (btcL);
			mostrarPrecioUnitarioL (precioPorKmL);
			mostrarDiferencia(diferencia);


		break;
			}

		}while(opcionIngresada!=6 || opcionIngresada > 6);//SI PRESIONA 6 TERMINA EL PROGRAMA

	printf("Vuelva pronto!!!");


	return 0;
}






