/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void); //crea la lista en memoria

int ll_len(LinkedList* this); //saca el largo de la lista

Node* test_getNode(LinkedList* this, int nodeIndex); // no la usamos

int test_addNode(LinkedList* this, int nodeIndex,void* pElement); //no la usamos

int ll_add(LinkedList* this, void* pElement); //agrega a la lista, puede agregar cualquier cosa

void* ll_get(LinkedList* this, int index); //devuelve un pasajero

int ll_set(LinkedList* this, int index,void* pElement); //reemplaza un elemento

int ll_remove(LinkedList* this,int index); //borra el elemento del indice especificado

int ll_clear(LinkedList* this); //borra todos los elementos de la lista

int ll_deleteLinkedList(LinkedList* this); //borra la lista

int ll_indexOf(LinkedList* this, void* pElement); //devuelve el indice especifico de un elemento q pase por parametro

int ll_isEmpty(LinkedList* this); //indica si la lista esta vacia o no

int ll_push(LinkedList* this, int index, void* pElement); //cuela o mete en el medio a partir del indice que se especifica

void* ll_pop(LinkedList* this,int index); //saca al elemento de la lista y lo devuelve(para mostrarlo, agregarlo a otra lista, etc)

int ll_contains(LinkedList* this, void* pElement); //indica si un elemento especifico esta dentro de la lista

int ll_containsAll(LinkedList* this,LinkedList* this2); //indica si todos los elementos q estan en la lista 2 se encuentran en la 1

LinkedList* ll_subList(LinkedList* this,int from,int to); //te devuelve un pedacito de la lista(desde hasta)

LinkedList* ll_clone(LinkedList* this); //devuelve una nueva lista clonada

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); //ordena la lista
