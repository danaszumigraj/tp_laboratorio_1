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
			opcionIngresada = mostrarMenu(opcionIngresada, km, precioA, precioL);
			switch(opcionIngresada)
			{
			case 1:
				do{
					km = pedirKm(km);
				  }while (km < 1);
			break;
			case 2:
					seleccionAerolinea = pedirAerolinea(seleccionAerolinea);
					do{
						switch(seleccionAerolinea)
						{
							case 'a':
								precioA = pedirPrecio(precioA);
							break;
							case 'l':
								precioL = pedirPrecio(precioL);
							break;
						}
					}while(precioA < 0 || precioL<0);
		break;
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
		case 4:
			printf("KMs ingresados: %.2f\n", km);
			mostrarResultados(precioA, precioL, debitoA, debitoL, creditoA, creditoL, btcA, btcL, precioPorKmA, precioPorKmL);
			mostrarDiferencia(diferencia);
		break;
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
			mostrarResultados(precioA, precioL, debitoA, debitoL, creditoA, creditoL, btcA, btcL, precioPorKmA, precioPorKmL);
			mostrarDiferencia(diferencia);
		break;
			}
		}while(opcionIngresada!=6 || opcionIngresada > 6 || opcionIngresada < 1);
	printf("Vuelva pronto!!!");
	return 0;
}






