/*
 * ArrayPassenger.h
 *
 *  Created on: 11 may. 2022
 *      Author: Dana
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define VACIO -1

struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger; // 1 2 3 turista //
int isEmpty;
}typedef Passenger;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok

*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);


#endif /* ARRAYPASSENGER_H_ */
