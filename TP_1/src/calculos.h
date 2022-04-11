/*
 * calculos.h
 *
 *  Created on: 9 abr. 2022
 *      Author: Dana
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

float descuentoDebitoA(float precioA);
float descuentoDebitoL(float precioL);

float interesCreditoA(float precioA);
float interesCreditoL(float precioL);

float bitcoinA(float precioA);
float bitcoinL(float precioL);

float precioUnitarioA(float precioA, float km);
float precioUnitarioL(float precioL, float km);

float diferenciaAerolineas(float precioA, float precioL);

#endif /* CALCULOS_H_ */
