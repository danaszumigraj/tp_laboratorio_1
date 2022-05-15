/*
 * Herramientas.h
 *
 *  Created on: 14 may. 2022
 *      Author: Dana
 */

#ifndef HERRAMIENTAS_H_
#define HERRAMIENTAS_H_
/**
 * @brief Busca un pasajero por su ID y lo muestra en pantalla
 * @param list es la estructura de los pasajeros
 * @param len largo del array
 * @param id es el id del pasajero
 */
void mostrarPasajero(Passenger *list, int len, int id);
/**
 * @brief acumula los precios de vuelo de los pasajeros ingresados
 * @param valor refiere a la estructura de los pasajeros
 * @param longitud es el largo del array
 * @return retorna el acumulador
 */
float totalArrays(Passenger* valor, int len);
/**
 * @brief calcula el promedio de precios entre los pasajeros ingresados
 * @param valor refiere a la estructura de los pasajeros
 * @param len largo del array
 * @param total acumulador de precios de la funcion totalArrays
 * @return retorna el promedio
 */
float promedioArrays(Passenger* valor, int len, float total);
/**
 * @brief calcula la cantidad de pasajeros que superan el promedio de precio calculado previamente
 * @param valor refiere a la estructura de los pasajeros
 * @param len largo del array
 * @param promedio dato previamente obtenido en la funcion totalArrays
 * @return retorna el contador de las personas que superaron el promedio
 */
int contadorPromedioMayor(Passenger* valor, int len, float promedio);

#endif /* HERRAMIENTAS_H_ */
