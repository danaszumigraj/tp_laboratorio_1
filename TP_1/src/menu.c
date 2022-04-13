/*
 * menu.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Dana
 */
#include <stdio.h>

int mostrarMenu(int opcion, float km, float precioA, float precioL)
{
	printf("\n1. Ingresar Kil�metros: (km= %.2f)\n", km);
	printf("\n2. Ingresar Precio de Vuelos: (Aerol�neas=%.2f, Latam=%.2f)\n", precioA, precioL);
	printf("\n3. Calcular todos los costos:\n"
			"\n4. Informar Resultados\n"
			"\n5. Carga forzada de datos\n"
			"\n6. Salir\n");

	printf("\nIngrese una opcion: \n");
	scanf("%d", &opcion);

return(opcion);

}

int mostrarResultados(float precioA, float precioL, float debitoA, float debitoL, float creditoA, float creditoL, float btcA, float btcL, float precioPorKmA, float precioPorKmL)
{
	if (precioA > 0)
	{
		printf("\nAerolineas: \n");
		printf("a) Precio con tarjeta de d�bito: %.2f", debitoA);
		printf("\nb) Precio con tarjeta de cr�dito: %.2f", creditoA);
		printf("\nc) Precio pagando con bitcoin : %f", btcA);
		printf("\nd) Precio unitario: %.2f", precioPorKmA);
	}
	else
	{
		printf("\nNo se ingres� ningun valor para Aerolineas\n");
	}
	if(precioL > 0)
	{
		printf("\nLatam: \n");
		printf("a) Precio con tarjeta de d�bito: %.2f", debitoL);
		printf("\nb) Precio con tarjeta de cr�dito: %.2f", creditoL);
		printf("\nc) Precio pagando con bitcoin : %f", btcL);
		printf("\nd) Precio unitario: %.2f", precioPorKmL);
	}
	else
	{
		printf("\nNo se ingres� ningun valor para Latam\n");
	}

	return 0;
}

int mostrarDiferencia(float diferencia)
{
	printf("\nLa diferencia de precio es: %.2f\n", diferencia);

	return 0;
}

