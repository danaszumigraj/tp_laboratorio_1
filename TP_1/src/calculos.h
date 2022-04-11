/*
 * calculos.h
 *
 *  Created on: 9 abr. 2022
 *      Author: Dana
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

int descuentoDebitoA(float precioA);
int descuentoDebitoL(float precioL);

int interesCreditoA(float precioA);
int interesCreditoL(float precioL);

int bitcoinA(float precioA);
int bitcoinL(float precioL);

int precioUnitarioA(float precioA, float km);
int precioUnitarioL(float precioL, float km);

int diferenciaAerolineas(float precioA, float precioL);

#endif /* CALCULOS_H_ */
