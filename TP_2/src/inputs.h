/*
 * inputs.h
 *
 *  Created on: 12 may. 2022
 *      Author: Dana
 */

#ifndef INPUTS_H_
#define INPUTS_H_

int menu(int opcion);
int menuModificar(int opcion);
void getInt(int* variableRecibida, char textoAMostrar []);
void getFloat(float* variableRecibida, char textoAMostrar[]);
void getArray(char arrayRecibido[], char textoAMostrar []);
/*********************************VALIDACIONES***********************************/
int validarInt(char numeroIngresado[]);
int validarChar(char arrayIngresado[]);

#endif /* INPUTS_H_ */
