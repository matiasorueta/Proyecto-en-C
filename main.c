#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "cola.h"
#include "pila.h"
int main()
{
        ///algo no esta funcionando de las colas, en especial el liberar o el duplicar
        ColaPtr cola = crearCola();
        int n=23,n2=5,n4=6;
        encolar(cola,&n);
        encolar(cola,&n2);
        encolar(cola,&n4);
        ColaPtr cola2 =duplicarCola(cola);
        printf("DATO DESENCOLADO:%d\n",*(int*)desencolar(cola2));
        //printf("DATO DESENCOLADO:%d\n",*(int*)desencolar(cola2));
        liberarCola(cola);
        liberarCola(cola2);



        PilaPtr pila =crearPila();
        int p=3,p2=5,p4=6;
        apilar(pila,&p);
        apilar(pila,&p2);
        apilar(pila,&p4);

       /* printf("%d",*(int*)desapilar(pila));
          printf("%d",*(int*)desapilar(pila));
            printf("%d",*(int*)desapilar(pila));
        */
        //
        apilar(pila,&p);
        printf("DATO DESAPILADO:%d\n",*(int*)desapilar(pila));
        PilaPtr pilaDupli = duplicarPila (pila);
        printf("DATO DESAPILADO:%d\n",*(int*)desapilar(pilaDupli));
        printf("DATO DESAPILADO:%d\n",*(int*)desapilar(pilaDupli));
        liberarPila(pila);
        liberarPila(pilaDupli);


    return 0;
}
