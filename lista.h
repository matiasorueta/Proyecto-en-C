#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"


struct Lista;

typedef struct Lista * ListaPtr;


NodoPtr getPrimero(ListaPtr lista);
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero);

ListaPtr crearLista();

void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato);
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion);


DatoPtr obtenerPrimero(ListaPtr lista);
DatoPtr obtenerUltimo(ListaPtr lista);
DatoPtr obtenerPosicion(ListaPtr lista, int posicion);
DatoPtr eliminarPrimero(ListaPtr lista);
DatoPtr eliminarUltimo(ListaPtr lista);
DatoPtr eliminarPosicion(ListaPtr lista, int posicion);

int obtenerTamanio(ListaPtr lista);

void ordenarLista(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr));
//ListaPtr ordenarListaCopia(ListaPtr lista,lista,int(*resultadoComparacion)(DatoPtr, DatoPtr));//tarea
ListaPtr duplicarLista(ListaPtr lista);

int buscarElemento(ListaPtr lista, DatoPtr datoBuscado);
int buscarElementoFloat(ListaPtr lista, DatoPtr datoBuscado);
int buscarElementoChar(ListaPtr lista, DatoPtr datoBuscado);

void insertarEnOrden(ListaPtr lista, DatoPtr dato,int(*resultadoComparacion)(DatoPtr, DatoPtr));//tarea, si la lista está ordenada cada vez que
//se inserta se inserta en la posición que corresponda


void mostrarLista(ListaPtr lista);
void mostrarListaChar(ListaPtr lista);
void mostrarListaFloat(ListaPtr lista);
void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr));

void liberarLista(ListaPtr lista);


#endif // LISTA_H_INCLUDED
