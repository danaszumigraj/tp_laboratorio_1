#ifndef PARSER_H_
#define PARSER_H_

#define TAM_NOMBRE 50
#define TAM_DATO 20

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* ubicacion del archivo
 * \param pArrayListPassenger LinkedList* lista de pasajeros
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char* ubicacion del archivo
 * \param pArrayListPassenger LinkedList* lista de pasajeros
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

#endif /* PARSER_H_ */
