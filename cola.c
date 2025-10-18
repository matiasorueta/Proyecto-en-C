#include <stdio.h>
#include <stdlib.h>

#include "cola.h"
#include <string.h>

struct Cola{

    NodoPtr primero;
    NodoPtr ultimo;

};

NodoPtr getPrimer(ColaPtr cola){
return cola->primero;};
void setPrimer(ColaPtr cola, NodoPtr nuevoPrimero){
cola->primero=nuevoPrimero;};

NodoPtr getUltimo(ColaPtr cola){
return cola->ultimo;
}
void setUltimo(ColaPtr cola, NodoPtr nuevoUltimo){
cola->ultimo=nuevoUltimo;
};

ColaPtr crearCola(){

    ColaPtr cola = malloc(sizeof(struct Cola));

    cola->primero = NULL;
    cola->ultimo=NULL;

    return cola;
};



void encolar(ColaPtr cola, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato,NULL);
    if ((cola->ultimo)==NULL && (cola->primero)==NULL){
    cola->primero=nuevoNodo;
    cola->ultimo = nuevoNodo;

    }else{
            setSiguiente(cola->ultimo,nuevoNodo);
            setUltimo(cola,nuevoNodo);
    }
};


DatoPtr desencolar(ColaPtr cola){
    NodoPtr nodoAux=cola->primero;
    DatoPtr dato= getDato(nodoAux);
    cola->primero=getSiguiente(nodoAux);
    liberarNodo(nodoAux);
    return dato;
    };
ColaPtr duplicarCola(ColaPtr cola) {
    ColaPtr colaAux = crearCola();
    ColaPtr colaDuplicada = crearCola();

    NodoPtr actual = cola->primero;
    while (actual != NULL) {
        DatoPtr dato1 = desencolar(cola);
        encolar(colaAux, dato1);
        encolar(colaDuplicada,dato1);
       actual = getSiguiente(actual);
    }

     actual = colaAux->primero;
    while (actual!= NULL) {
        DatoPtr dato = desencolar(colaAux);
        encolar(cola,dato);
        actual = getSiguiente(actual);
    }
     printf("a ver");
     liberarCola(colaAux);

    return colaDuplicada;}

void liberarCola(ColaPtr cola) {

    //NodoPtr actual = cola->primero;
    //NodoPtr aux;

    while (cola->primero!=NULL){
        desencolar(cola);
        //setSiguiente(actual,cola->primero);
        //actual = getSiguiente(actual);
    };
}
