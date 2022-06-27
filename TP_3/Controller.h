#define TAM_NOMBRE 50
#define TAM_DATO 20
#define TAM_DECIMAL 10

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 * \param path char* ubicacion del archivo
 * \param pArrayListPassenger LinkedList* lista de pasajeros
 * \return int 0 si esta ok y -1 si hay problema
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 * \param path char* ubicacion del archivo
 * \param pArrayListPassenger LinkedList* lista de pasajeros
 * \return int 0 si esta ok y -1 si hay problema
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
/** \brief Alta de pasajero
 * \param pArrayListPassenger LinkedList* lista de pasajeros
 * \return int 0 si esta ok y -1 si hay problema
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayManualPassenger, LinkedList* pArrayRemovedPassenger);
/** \brief Modificar datos de pasajero
 * \param pArrayListPassenger LinkedList* lista de pasajeros
 * \return int 0 si esta ok y -1 si hay problema
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayManualPassenger);
/** \brief Baja de pasajero
 * \param pArrayListPassenger LinkedList* lista de pasajeros
 * \return int 0 si esta ok y -1 si hay problema
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayRemovedPassenger, LinkedList* pArrayManualPassenger);
/** \brief Listar pasajeros
 * \param pArrayListPassenger LinkedList* lista de pasajeros
 * \return int 0 si esta ok y -1 si hay problema
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayManualPassenger);
/** \brief Ordenar pasajeros por apellido y si son iguales por nombre
 * \param pArrayListPassenger LinkedList* lista de pasajeros
 * \return retorna 0 si esta ok y -1 si hay problema
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayManualPassenger);
/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char* ubicacion del archivo
 * \param pArrayListPassenger LinkedList* lista de pasajeros
 * \return retorna 0 si esta ok y -1 si hay problema
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
/**
 * @brief Ordena los pasajeros por ID
 * @param pArrayListPassenger Lista de pasajeros
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int controller_sortPassengerById(LinkedList* pArrayListPassenger);
/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 * \param path char* ubicacion del archivo
 * \param pArrayListPassenger LinkedList* lista de pasajeros
 * \return int retorna 0 si esta ok y -1 si hay problema
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
/**
 * @brief corrige los ID en caso de ingresar un pasajero y luego cargar la lista desde el archivo
 * @param pArrayListPassenger lista de pasajeros
 * @param contadorPasajeros contador de pasajeros cargados manualmente
 * @return retorna 0 si esta ok y -1 si hay problema
 */
int controller_corregirId(LinkedList* pArrayListPassenger, LinkedList* pArrayManualPassenger);
