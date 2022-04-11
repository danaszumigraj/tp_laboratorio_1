/*
 * menu.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Dana
 */
#include <stdio.h>

int mostrarMenu(int opcion, float km, float precioA, float precioL)
{
	printf("\n1. Ingresar Kilómetros: (km= %.2f)\n", km);
				printf("\n2. Ingresar Precio de Vuelos: (Aerolíneas=%.2f, Latam=%.2f)\n", precioA, precioL);
				printf("\n3. Calcular todos los costos:\n"
						"\n4. Informar Resultados\n"
						"\n5. Carga forzada de datos\n"
						"\n6. Salir\n");

				printf("\nIngrese una opcion: \n");
				scanf("%d", &opcion);

return(opcion);

}

int mostrarDebitoA (float debitoA)
{
	printf("a) Precio con tarjeta de débito: %.2f", debitoA);

	return 0;
}

int mostrarDebitoL (float debitoL)
{
	printf("a) Precio con tarjeta de débito: %.2f", debitoL);

	return 0;
}

int mostrarCreditoA (float creditoA)
{
	printf("\nb) Precio con tarjeta de crédito: %.2f", creditoA);

	return 0;
}

int mostrarCreditoL (float creditoL)
{
	printf("\nb) Precio con tarjeta de crédito: %.2f", creditoL);

	return 0;
}

int mostrarBitcoinA (float btcA)
{
	printf("\nc) Precio pagando con bitcoin : %.2f", btcA);

	return 0;
}

int mostrarBitcoinL (float btcL)
{
	printf("\nc) Precio pagando con bitcoin : %.2f", btcL);

	return 0;
}

int mostrarPrecioUnitarioA (float precioPorKmA)
{
	printf("\nd) Precio unitario: %.2f", precioPorKmA);

	return 0;
}

int mostrarPrecioUnitarioL (float precioPorKmL)
{
	printf("\nd) Precio unitario: %.2f", precioPorKmL);

	return 0;
}

int mostrarDiferencia(float diferencia)
{
	printf("\nLa diferencia de precio es: %.2f\n", diferencia);

	return 0;
}

