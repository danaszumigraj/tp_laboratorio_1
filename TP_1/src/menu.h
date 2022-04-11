/*
 * funciones.h
 *
 *  Created on: 8 abr. 2022
 *      Author: Dana
 */

#ifndef MENU_H_
#define MENU_H_



int mostrarMenu(int opcion, float km, float precioA, float precioL);

int mostrarDebitoA (float debitoA);
int mostrarDebitoL (float debitoL);

int mostrarCreditoA (float creditoA);
int mostrarCreditoL (float creditoL);

int mostrarBitcoinA (float btcA);
int mostrarBitcoinL (float btcL);

int mostrarPrecioUnitarioA (float precioPorKmA);
int mostrarPrecioUnitarioL (float precioPorKmL);

int mostrarDiferencia(float diferencia);



#endif /* MENU_H_ */
