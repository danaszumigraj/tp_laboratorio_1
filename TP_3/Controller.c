#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"


int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(pArrayListPassenger!=NULL)
	{
		if(path!=NULL)
		{
			FILE *pArchivo;
			pArchivo = fopen(path, "r");

			if(pArchivo!=NULL)
			{
				if(parser_PassengerFromText(pArchivo , pArrayListPassenger)==0)
				{
					retorno = 0;
				}
			}
			fclose(pArchivo);
		}
	}
	return retorno;
}
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	return 0;
}
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	return 0;
}
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	return 0;
}
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	return 0;
}
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	return 0;
}
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	return 0;
}
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	return 0;
}
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	return 0;
}
