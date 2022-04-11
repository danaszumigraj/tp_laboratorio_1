/*
 * calculos.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Dana
 */

#include <stdio.h>
#include <stdlib.h>

int descuentoDebitoA(float precioA)
{
	int debitoA;

	debitoA = precioA - (precioA * 0.1);

	return debitoA;
}

int descuentoDebitoL(float precioL)
{
	int debitoL;

	debitoL = precioL - (precioL * 0.1);

	return debitoL;
}

int interesCreditoA(float precioA)
{
	int creditoA;

	creditoA = precioA + (precioA * 0.25);

	return creditoA;
}

int interesCreditoL(float precioL)
{
	int creditoL;

	creditoL = precioL + (precioL * 0.25);

	return creditoL;
}

int bitcoinA(float precioA)
{
	int btcA;

	btcA = (precioA / 4606954.55);

	return btcA;
}

int bitcoinL(float precioL)
{
	int btcL;

	btcL = (precioL / 4606954.55);

	return btcL;
}

int precioUnitarioA(float precioA, float km)
{
	int precioPorKmA;

	precioPorKmA = (precioA / km);

	return precioPorKmA;
}

int precioUnitarioL(float precioL, float km)
{
	int precioPorKmL;

	precioPorKmL = (precioL / km);

	return precioPorKmL;
}

int diferenciaAerolineas(float precioA, float precioL)
{
	float diferencia;

	diferencia = (precioL - precioA);

	return diferencia;
}
