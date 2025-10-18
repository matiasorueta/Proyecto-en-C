#include <stdio.h>
#include <stdlib.h>

#include "pila.h"
#include <string.h>

struct Pila{

    NodoPtr ultimo;

};


NodoPtr getUltimoP(PilaPtr pila){
return pila->ultimo;
}
void setUltimoP(PilaPtr pila, NodoPtr nuevoUltimo){
pila->ultimo=nuevoUltimo;
};

PilaPtr crearPila(){

    PilaPtr pila = malloc(sizeof(struct Pila));

    pila->ultimo=NULL;

    return pila;
};



void apilar(PilaPtr pila, DatoPtr dato){
    //el nuevo dato apunta al ultimo
    NodoPtr nuevoNodo = crearNodo(dato,pila->ultimo);
    if ((pila->ultimo)==NULL ){
    pila->ultimo = nuevoNodo;

    }else{
            // el ultimo pasa a ser nuevoNodo
            setUltimoP(pila,nuevoNodo);
    }
};


DatoPtr desapilar(PilaPtr pila){
    NodoPtr nodoAux=pila->ultimo;
    DatoPtr dato= getDato(nodoAux);
    pila->ultimo=getSiguiente(nodoAux);
    liberarNodo(nodoAux);


    return dato;
    };

PilaPtr duplicarPila(PilaPtr pila) {
    PilaPtr pilaAux1 = crearPila();
    PilaPtr pilaAux2 = crearPila();

    while (pila->ultimo!= NULL) {
        apilar(pilaAux1, desapilar(pila));
    }

     while (pilaAux1->ultimo != NULL) {
        DatoPtr dato = desapilar(pilaAux1);
        apilar(pilaAux2, dato);
        apilar(pila,dato);
    }
    return pilaAux2;
}

    void mostrarPila (PilaPtr pila){
NodoPtr actual = pila->ultimo;

    while (actual!=NULL){
        desapilar(pila);
    }
    printf("\n\n");}

void liberarPila(PilaPtr pila) {

    NodoPtr actual =pila->ultimo;
    //NodoPtr aux;

    while (actual!=NULL){
     desapilar(pila);
     actual = getUltimoP(pila);
    };
}

