/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#define TAM_NOMBRE 50
#define TAM_DATO 20

typedef struct
{
	int id;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_NOMBRE];
	int precio;
	int tipoPasajero;
	char codigoVuelo[TAM_DATO];
	int estadoVuelo;

}Passenger;

Passenger* Passenger_new(void);
Passenger* Passenger_newParametros(char* id, char* nombre,char* apellido, char* precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo);
void Passenger_delete(Passenger* this);

int Passenger_newId(LinkedList* pArrayListPassenger);
int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,int precio);
int Passenger_getPrecio(Passenger* this,int* precio);

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);

void Passenger_printOnePassenger(Passenger* this);
int Passenger_get(LinkedList* this, int id);



#endif /* PASSENGER_H_ */
