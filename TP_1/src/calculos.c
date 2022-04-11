/*
 * calculos.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Dana
 */

#include <stdio.h>
#include <stdlib.h>

float descuentoDebitoA(float precioA)
{
	float debitoA;

	debitoA = precioA - (precioA * 0.1);

	return debitoA;
}

float descuentoDebitoL(float precioL)
{
	float debitoL;

	debitoL = precioL - (precioL * 0.1);

	return debitoL;
}

float interesCreditoA(float precioA)
{
	float creditoA;

	creditoA = precioA + (precioA * 0.25);

	return creditoA;
}

float interesCreditoL(float precioL)
{
	float creditoL;

	creditoL = precioL + (precioL * 0.25);

	return creditoL;
}

float bitcoinA(float precioA)
{
	float btcA;

	btcA = (precioA / 4606954.55);

	return btcA;
}

float bitcoinL(float precioL)
{
	float btcL;

	btcL = (precioL / 4723110.47);

	return btcL;
}

float precioUnitarioA(float precioA, float km)
{
	float precioPorKmA;

	precioPorKmA = (precioA / km);

	return precioPorKmA;
}

float precioUnitarioL(float precioL, float km)
{
	float precioPorKmL;

	precioPorKmL = (precioL / km);

	return precioPorKmL;
}

float diferenciaAerolineas(float precioA, float precioL)
{
	float diferencia;
	if (precioA == 0 || precioL == 0)
	{
		diferencia = 0;
	}
	else
	{
		diferencia = (precioL - precioA);
	}

	return diferencia;
}
