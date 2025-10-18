#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;


typedef struct Nodo * NodoPtr;

typedef void * DatoPtr; ///Dato del tipo puntero a cualquier cosa

DatoPtr getDato(NodoPtr nodo);
NodoPtr getSiguiente(NodoPtr nodo);

void setDato(NodoPtr nodo, DatoPtr nuevoDato);
void setSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente);

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);

void mostrarNodo(NodoPtr nodo);
void mostrarNodoChar(NodoPtr nodo);
void mostrarNodoFloat(NodoPtr nodo);

int compararEnteros (DatoPtr d1,DatoPtr d2);
int compararFloats (DatoPtr d1,DatoPtr d2);
int compararChars (DatoPtr d1,DatoPtr d2);

void liberarNodo(NodoPtr nodo);





#endif // NODO_H_INCLUDED
