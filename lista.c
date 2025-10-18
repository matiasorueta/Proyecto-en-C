#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include <string.h>

struct Lista{

    NodoPtr primero;

};

NodoPtr getPrimero(ListaPtr lista){
return lista->primero;};
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero){
lista->primero=nuevoPrimero;};


ListaPtr crearLista(){

    ListaPtr lista = malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;
};


void insertarPrimero(ListaPtr lista, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);

    lista->primero = nuevoNodo;


};


void insertarUltimo(ListaPtr lista, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, NULL);

    NodoPtr actual = lista->primero;
    if(actual == NULL){
        lista->primero = nuevoNodo;
    }else{
        while(getSiguiente(actual)!=NULL){

            actual = getSiguiente(actual);
        }

       setSiguiente(actual, nuevoNodo);
        }

}; //tarea


void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion){
 int tam = obtenerTamanio(lista);

    /// 1 2 3 ///TAM 3
    if(posicion > tam+1){

        printf("\n\nERROR, no se puede insertar en pos que no existen!!!");

    }else{

        if(posicion<0){

            printf("\n\nERROR, no se puede insertar en pos negativas!!!");
        }else{  ///0 _ _ _ _  tam

            if(posicion == 0){

                insertarPrimero(lista, dato);
            }else{
                if(posicion==tam){

                    insertarUltimo(lista, dato);
                }else{

                    if(posicion>0 && posicion<tam){ ///ALGORITMO
                        /// 12  23  33  XX  34  55     POS 3  ///TAM 5
                        NodoPtr actual = lista->primero;

                        for ( int i = 0 ; i<posicion-1; i++){
                            actual= getSiguiente(actual);
                        }
                        setSiguiente(actual,crearNodo(dato, getSiguiente(actual)));

                }}}
        }    }



}; //tarea


DatoPtr obtenerPrimero(ListaPtr lista){
 NodoPtr nodo=lista->primero;
 return getDato(nodo);};


DatoPtr obtenerUltimo(ListaPtr lista){
  NodoPtr nodoAux=lista->primero;
  DatoPtr dato = getDato (nodoAux);
    while (getSiguiente(nodoAux)!=NULL){

        nodoAux = getSiguiente(nodoAux);
        dato=getDato(nodoAux);
    }
return dato;
}; //tarea
DatoPtr obtenerPosicion(ListaPtr lista, int posicion){
     NodoPtr nodoAux=lista->primero;
     DatoPtr dato=getDato(nodoAux);
    if ((posicion>=obtenerTamanio(lista))||(posicion<0)){
        printf("\nEsta posicion no existe\n");
    }
    else{

        if(posicion==0){
            nodoAux=lista->primero;
        }else{
        int contador=0;

        while (contador!=posicion){

           nodoAux = getSiguiente(nodoAux);
           dato=getDato(nodoAux);
           contador++;
        }
    }
    }

return dato;}; //tarea


DatoPtr eliminarPrimero(ListaPtr lista){
    NodoPtr nodoAux=lista->primero;
    DatoPtr dato= getDato(nodoAux);
    lista->primero=getSiguiente(nodoAux);
    liberarNodo(nodoAux);
    return dato;
    };

DatoPtr eliminarUltimo(ListaPtr lista){
 NodoPtr nodoAux=lista->primero;

    DatoPtr aux=getDato(nodoAux);
    if (getSiguiente(nodoAux)==NULL){
             lista->primero=getSiguiente(nodoAux);
             liberarNodo(nodoAux);

            //return aux;

     }
    else{
        nodoAux = getSiguiente(nodoAux);
        aux=getDato(nodoAux);

     while (getSiguiente(getSiguiente(nodoAux))!=NULL){
             nodoAux = getSiguiente(nodoAux);}
              aux=getDato(getSiguiente(nodoAux));
              setSiguiente(nodoAux,NULL);
              liberarNodo(getSiguiente(nodoAux));
     }

return aux;}

DatoPtr eliminarPosicion(ListaPtr lista, int posicion){
NodoPtr nodoAux=lista->primero;
  DatoPtr aux=getDato(nodoAux);
    if ((posicion>=obtenerTamanio(lista))||(posicion<0)){
        printf("\nEsta posicion no existe\n");

    }
    else{
            if (posicion==0){
                eliminarPrimero(lista);
                return aux;
            }
            setSiguiente(nodoAux,getSiguiente(nodoAux));

            for (int i=0;i<posicion;i++){
                if (i==posicion-1){

                aux=getDato(getSiguiente(nodoAux));
                NodoPtr borrar = getSiguiente(nodoAux);
                setSiguiente(nodoAux,getSiguiente(getSiguiente(nodoAux))) ;
                liberarNodo(borrar);

            }
            nodoAux = getSiguiente(nodoAux);
            }

    }

return aux;}; //tarea

int obtenerTamanio(ListaPtr lista){

    int tam = 0 ;
    NodoPtr actual = lista->primero;
    while (actual != NULL){

            tam = tam + 1;
            actual = getSiguiente(actual);

    }

    return tam;
}; //tarea

void ordenarLista(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr)){

    int permutacion;
    NodoPtr nodo;
    //NodoPtr ultimo = NULL;

    if(obtenerTamanio(lista)< 2){
        //ya esta ordenada, no hago nada
    } else {

        do{
            permutacion = 0 ;
            nodo = lista->primero;


            while (getSiguiente(nodo) !=NULL){

                if((resultadoComparacion(getDato(nodo),getDato(getSiguiente(nodo))))==1){


                    DatoPtr aux = getDato(nodo);
                    setDato(nodo, getDato(getSiguiente(nodo)));
                    setDato(getSiguiente(nodo), aux);
                    permutacion = 1;

                }
                nodo = getSiguiente(nodo);

            }
           // ultimo = nodo; //opcional!!!

            }while (permutacion!=0);


    }
};

/*ListaPtr ordenarListaCopia(ListaPtr lista,int(*resultadoComparacion)(DatoPtr, DatoPtr)){
    ListaPtr listaAux=duplicarLista(lista);
    ordenarLista(listaAux,resultadoComparacion);
    return listaAux;

};//tarea*/
ListaPtr duplicarLista(ListaPtr lista){
ListaPtr listaAux=crearLista();
    NodoPtr nodoAux =lista->primero;
    while (nodoAux!=NULL){
        insertarUltimo(listaAux,getDato(nodoAux));
        nodoAux = getSiguiente(nodoAux);
    }

return listaAux;};//tarea

int buscarElemento(ListaPtr lista, DatoPtr datoBuscado){
NodoPtr nodoAux=lista->primero;


int contador=0;
    while (nodoAux!=NULL){
        if ((*(int*)(getDato(nodoAux)))==*(int*)datoBuscado){
            contador =1;
        }
        nodoAux = getSiguiente(nodoAux);
    }
    if (contador ==0){
    printf("\nNO ENCONTRADO\n");}
    else{
        printf("\nENCONTRADO\n");
    }
return contador;
};//tarea
int buscarElementoFloat(ListaPtr lista, DatoPtr datoBuscado){
NodoPtr nodoAux=lista->primero;
int contador=0;
    while (nodoAux!=NULL){
        if ((*(float*)(getDato(nodoAux)))==*(float*)datoBuscado){
            contador =1;
        }
        //setSiguiente(nodoAux,getSiguiente(nodoAux));
        nodoAux = getSiguiente(nodoAux);
    }
    if (contador ==0){
    printf("\nNO ENCONTRADO\n");}
    else{
        printf("\nENCONTRADO\n");
    }
return contador;


};
int buscarElementoChar(ListaPtr lista, DatoPtr datoBuscado){
    NodoPtr nodoAux=lista->primero;
    int contador=0;
    while (nodoAux!=NULL){
        if ((strcmp((char*)getDato(nodoAux),(char*)datoBuscado))==1){
            contador =1;
        }
        nodoAux = getSiguiente(nodoAux);
    }
    if (contador ==0){
    printf("\nNO ENCONTRADO\n");}
    else{
        printf("\nENCONTRADO\n");
    }
return contador;


};
void insertarEnOrden(ListaPtr lista, DatoPtr dato,int(*resultadoComparacion)(DatoPtr, DatoPtr)){
    ordenarLista(lista,resultadoComparacion);
    NodoPtr nodoAux = lista->primero;
    int contador =0;

    if (resultadoComparacion(dato,getDato(nodoAux))<=0){
        insertarPrimero(lista,dato);
        contador=1;
    }

    while ((contador!=1) || (getSiguiente(nodoAux)==NULL) ){
        if((resultadoComparacion(dato,getDato(getSiguiente(nodoAux))))!=1){

            NodoPtr reemplazo =crearNodo(dato,getSiguiente(nodoAux));
            setSiguiente(nodoAux,reemplazo);

            contador =1;
        }

        nodoAux=getSiguiente(nodoAux);
    }

    if (contador==0){
        insertarUltimo(lista,dato);
    }



};//tarea, si la lista está ordenada cada vez que
//se inserta se inserta en la posición que corresponda

void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr)){

    printf("\n<LISTA> TAM:%d \n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        //mostrarFloat(actual);
        mostrar(getDato(actual));
        actual = getSiguiente(actual);
    }
    printf("\n\n");



};
void mostrarLista(ListaPtr lista){

    printf("\n<LISTA> TAM:%d \n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        mostrarNodo(actual);
        actual = getSiguiente(actual);
    }
    printf("\n\n");



};

void mostrarListaChar(ListaPtr lista){

    printf("\n<LISTA> TAM:%d \n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        mostrarNodoChar(actual);
        actual = getSiguiente(actual);
    }
    printf("\n\n");



};


void mostrarListaFloat(ListaPtr lista){

    printf("\n<LISTA> TAM:%d \n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        mostrarNodoFloat(actual);
        actual = getSiguiente(actual);
    }
    printf("\n\n");



};






void liberarLista(ListaPtr lista) {

    NodoPtr actual = lista->primero;
    NodoPtr aux;

    while (actual!=NULL){
        aux = actual;
        actual = getSiguiente(actual);
        free(aux);
    };
}
