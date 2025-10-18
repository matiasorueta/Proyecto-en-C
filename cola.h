#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "nodo.h"


struct Cola;

typedef struct Cola * ColaPtr;


NodoPtr getPrimer(ColaPtr cola);
void setPrimer(ColaPtr cola, NodoPtr nuevoPrimero);
NodoPtr getUltimo (ColaPtr cola);
void setUltimo (ColaPtr cola, NodoPtr nuevoUltimo);

ColaPtr crearCola();

void encolar(ColaPtr cola, DatoPtr dato);
void mostrarCola (ColaPtr cola);

DatoPtr desencolar(ColaPtr cola);

ColaPtr duplicarCola(ColaPtr cola);

void liberarCola(ColaPtr cola);


#endif // LISTA_H_INCLUDED
