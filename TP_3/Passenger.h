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
/**
 * @brief genera un nuevo pasajero en memoria
 * @return retorna el pasajero
 */
Passenger* Passenger_new(void);
/**
 * @brief guarda al nuevo pasajero con todos sus datos
 * @param id
 * @param nombre
 * @param apellido
 * @param precio
 * @param codigoVuelo
 * @param tipoPasajero
 * @param estadoVuelo
 * @return
 */
Passenger* Passenger_newParametros(char* id, char* nombre,char* apellido, char* precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo);
/**
 * @brief borra al pasajero
 * @param this pasajero a borrar
 */
void Passenger_delete(Passenger* this);
/**
 * @brief Busca el ID mas alto dentro de los ya ingresados y devuelve el siguiente
 * @param pArrayListPassenger lista de pasajeros
 * @return retorna el ID generado
 */
int Passenger_newId(LinkedList* pArrayListPassenger);
/**
 * @brief guarda el ID dentro del pasajero
 * @param this el pasajero
 * @param id ID a guardar
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_setId(Passenger* this,int id);
/**
 * @brief devuelve un ID a partir de un pasajero
 * @param this el pasajero
 * @param id variable en la que se guarda el id obtenido
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_getId(Passenger* this,int* id);
/**
 * @brief guarda el nombre dentro del pasajero
 * @param this el pasajero
 * @param nombre nombre a guardar
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_setNombre(Passenger* this,char* nombre);
/**
 * @brief devuelve un nombre a partir de un pasajero
 * @param this el pasajero
 * @param nombre variable en la que se guarda el nombre a devolver
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_getNombre(Passenger* this,char* nombre);
/**
 * @brief guarda un apellido en un pasajero
 * @param this el pasajero
 * @param apellido apellido a guardar
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_setApellido(Passenger* this,char* apellido);
/**
 * @brief obtiene un apellido a partir de un pasajero
 * @param this el pasajero
 * @param apellido variable en la que se guarda el apellido a devolver
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_getApellido(Passenger* this,char* apellido);
/**
 * @brief guarda un codigo de vuelo en un pasajero
 * @param this el pasajero
 * @param codigoVuelo codigo a guardar
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
/**
 * @brief obtiene un codigo de vuelo a partir de un pasajero
 * @param this el pasajero
 * @param codigoVuelo variable en la que se guarda el codigo a devolver
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
/**
 * @brief guarda un tipo de pasajero en un pasajero
 * @param this el pasajero
 * @param tipoPasajero tipo a guardar
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
/**
 * @brief obtiene un tipo a partir de un pasajero
 * @param this el pasajero
 * @param tipoPasajero variable donde se almacena el tipo a devolver
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);
/**
 * @brief guarda un precio dentro de un pasajero
 * @param this el pasajero
 * @param precio precio a guardar
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_setPrecio(Passenger* this,int precio);
/**
 * @brief obtiene un precio a partir de un pasajero
 * @param this el pasajero
 * @param precio variable donde se almacena el precio a devolver
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_getPrecio(Passenger* this,int* precio);
/**
 * @brief guarda un estado de vuelo en un pasajero
 * @param this el pasajero
 * @param estadoVuelo estado a guardar
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);
/**
 * @brief obtiene un estado de vuelo a partir de un pasajero
 * @param this el pasajero
 * @param estadoVuelo variable donde se almacena el estado de vuelo obtenido
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);
/**
 * @brief imprime un pasajero
 * @param this el pasajero
 */
void Passenger_printOnePassenger(Passenger* this);
/**
 * @brief obtiene un pasajero a partir de su id
 * @param this el pasajero
 * @param id id del pasajero
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_get(LinkedList* this, int id);
/**
 * @brief ordena el array por apellido y si son iguales por nombre
 * @param primerPasajero pasajero a comparar
 * @param segundoPasajero pasajero a comparar
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_sortByApellido(void* primerPasajero, void* segundoPasajero);
/**
 * @brief ordena a los pasajeros por ID
 * @param primerPasajero pasajero a comparar
 * @param segundoPasajero pasajero a comparar
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int Passenger_sortById(void* primerPasajero, void* segundoPasajero);



#endif /* PASSENGER_H_ */
