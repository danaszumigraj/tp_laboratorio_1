/*
 * funciones.h
 *
 *  Created on: 8 abr. 2022
 *      Author: Dana
 */

#ifndef MENU_H_
#define MENU_H_


/// @brief
///
/// @pre
/// @post
/// @param opcion
/// @param km
/// @param precioA
/// @param precioL
/// @return
int mostrarMenu(int opcion, float km, float precioA, float precioL);
/// @brief
///
/// @pre
/// @post
/// @param km
/// @return
int pedirKm(float km);
/// @brief
///
/// @pre
/// @post
/// @param opcionAerolinea
int pedirAerolinea(float opcionAerolinea);
/// @brief
///
/// @pre
/// @post
/// @param precioIngresado
int pedirPrecio(float precioIngresado);
/// @brief
///
/// @pre
/// @post
/// @param precioA
/// @param precioL
/// @param debitoA
/// @param debitoL
/// @param creditoA
/// @param creditoL
/// @param btcA
/// @param btcL
/// @param precioPorKmA
/// @param precioPorKmL
/// @return
int mostrarResultados(float precioA, float precioL, float debitoA, float debitoL, float creditoA, float creditoL, float btcA, float btcL, float precioPorKmA, float precioPorKmL);
/// @brief
///
/// @pre
/// @post
/// @param diferencia
/// @return
int mostrarDiferencia(float diferencia);

#endif /* MENU_H_ */
