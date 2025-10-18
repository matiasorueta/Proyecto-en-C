#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include<string.h>


struct Nodo {

    DatoPtr dato;
    struct Nodo * siguiente;

};


DatoPtr getDato(NodoPtr nodo){

    return nodo->dato;
};

NodoPtr getSiguiente(NodoPtr nodo){

    return nodo->siguiente;
};

void setDato(NodoPtr nodo, DatoPtr nuevoDato){

    nodo->dato = nuevoDato;
};

void setSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente){

    nodo->siguiente = nuevoSiguiente;

};

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente){


    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;

};

void mostrarNodo(NodoPtr nodo){

    printf("{ %d }", *(int*)(nodo->dato));

};

void mostrarNodoChar(NodoPtr nodo){

    printf("{ %s }", (char*)(nodo->dato));

};

void mostrarNodoFloat(NodoPtr nodo){

    printf("{ %.2f }", *(float*)(nodo->dato));

};
int compararEnteros (DatoPtr d1,DatoPtr d2){
int dato1 = *(int*)d1;
int dato2 = *(int*)d2;
return (dato1>dato2);};

int compararFloats (DatoPtr d1,DatoPtr d2){
float dato1 =*(float*) d1;
float dato2 =*(float*) d2;
return (dato1>dato2);};

int compararChars (DatoPtr d1,DatoPtr d2){
char dato1 = *(char*)(d1);
char dato2 = *(char*)(d2);

return (strcmp(&dato1,&dato2));

};

void liberarNodo(NodoPtr nodo){

    free(nodo);


};
