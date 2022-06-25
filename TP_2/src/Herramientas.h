/*
 * Herramientas.h
 *
 *  Created on: 14 may. 2022
 *      Author: Dana
 */

#ifndef HERRAMIENTAS_H_
#define HERRAMIENTAS_H_
/**
 * @brief Muestra el menu principal
 *
 * @param opcion Es la respuesta que ingresa el usuario
 * @return Retorna la respuesta del usuario
 */
int menu(int opcion);
/**
 * @brief Muestra el submenu para hacer modificaciones
 * @param opcion Es la respuesta que ingresa el usuario
 * @return Retorna la respuesta del usuario
 */
int menuModificar(int opcion);
/**
 * @brief Muestra el submenu para informar
 * @param opcion Es la respuesta que ingresa el usuario
 * @return Retorna la respuesta del usuario
 */
int menuInformar(int opcion);
/**
 * @brief acumula los precios de vuelo de los pasajeros ingresados
 * @param valor refiere a la estructura de los pasajeros
 * @param longitud es el largo del array
 * @return retorna el acumulador
 */
float calcularTotal(Passenger* list, int len);
/**
 * @brief calcula el promedio de precios entre los pasajeros ingresados
 * @param valor refiere a la estructura de los pasajeros
 * @param len largo del array
 * @param total acumulador de precios de la funcion totalArrays
 * @return retorna el promedio
 */
float calcularPromedio(Passenger* list, int len, float total);
/**
 * @brief calcula la cantidad de pasajeros que superan el promedio de precio calculado previamente
 * @param valor refiere a la estructura de los pasajeros
 * @param len largo del array
 * @param promedio dato previamente obtenido en la funcion totalArrays
 * @return retorna el contador de las personas que superaron el promedio
 */
int contadorSuperaPromedio(Passenger* list, int len, float promedio);

#endif /* HERRAMIENTAS_H_ */
