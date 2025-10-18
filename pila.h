#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "nodo.h"


struct Pila;

typedef struct Pila * PilaPtr;


NodoPtr getPrimeroP(PilaPtr pila);
void setPrimeroP(PilaPtr pila, NodoPtr nuevoPrimero);
NodoPtr getUltimoP (PilaPtr pila);
void setUltimoP(PilaPtr pila, NodoPtr nuevoUltimo);

PilaPtr crearPila();

void apilar(PilaPtr pila, DatoPtr dato);
void mostrarPila (PilaPtr pila);

DatoPtr desapilar(PilaPtr pila);

PilaPtr duplicarPila(PilaPtr pila);

void liberarPila(PilaPtr pila);


#endif // LISTA_H_INCLUDED
