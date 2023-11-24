#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct
{
    int dato;
    struct nodo* siguiente;
}nodo;


 typedef struct
 {
     nodo* lista;
 }Pila;

 nodo* inicLista()
 {
     return NULL;
 }
 nodo* crearNodo(nodo* nuevo)
 {
     nodo* lista=malloc(sizeof(nodo));
     lista->dato=nuevo;
     lista->siguiente=NULL;
     return lista;
 }

 nodo* agregarPcio(nodo* lista, nodo* nuevo)
 {
     nodo* seguidora=NULL;
     if(!lista)
     {
         lista=nuevo;
     }
     else
     {
         nuevo->siguiente=lista;
         lista=nuevo;
     }
     return lista;
 }
 nodo* buscarUltimo(nodo* lista)
 {
     nodo* seguidora=lista;
     while(seguidora->siguiente!=NULL)
     {
         seguidora=seguidora->siguiente;
     }
     return seguidora;
 }
 nodo* agregarAlFinal(nodo* lista,nodo* nuevo)
 {
     nodo* seguidora=lista;
     if(lista==NULL)
     {
         lista=nuevo;
     }
     else
     {
         seguidora=buscarUltimo(lista);
         seguidora->siguiente=nuevo;
     }
    return lista;
 }
 void mostrarNodo(nodo* lista)
 {
    printf("El valor es : %d\n",lista->dato);

 }
 void mostrarLista(nodo*lista)
 {
     while(lista)
     {
         mostrarNodo(lista);
         lista=lista->siguiente;
     }
 }

 ///============================================================================
void inicPila(Pila *p)
{
    p->lista=NULL;
}
void apilar(Pila *p, int dato)
{
    p->lista=agregarPcio(p->lista,crearNodo(dato));
}
int desapilar(Pila *p)
{
    int aux;
    nodo* borrado=p->lista;

    aux=(p->lista)->dato;
    p->lista=p->lista->siguiente;
    free(borrado);

    return aux;
}
int posTope(Pila *p)
{
  return (p->lista)->dato;
}

int pilaVacia(Pila *p)          ///MOUDULARIZAR CON UNA FUNCION DE LISTAVACIA()
{
    int flag=0;
    if(p->lista ==NULL)
    {
        flag=1;
    }
    else
    {
        flag=0;
    }
    return flag;
    /* listaVcia()
    int flag=0;
    if(lista==NULL)
    {flag=1);
    */
}

void mostrarPila(Pila *p)
{
    if(p->lista)
    {
        mostrarLista(p->lista);
    }
}
void leer(Pila *p)
{
    int dato;
    printf("Ingrese un dato : ");
    scanf("%d",&dato);
    apilar(p,dato);
}
///======================================================================
void cargarPila(Pila *p)
{
    char continuar='s';
    while(continuar=='s')
    {
        leer(p);
        printf("Desea continuar? (s/n)");
        fflush(stdin);
        scanf("%c",&continuar);
    }
}
nodo* cargarListaPar(Pila *p, nodo* lista)
{
    Pila aux;
    inicPila(&aux);
    while(!pilaVacia(p))
    {
        if(posTope(p)%2==0)
        {
            lista=agregarAlFinal(lista,crearNodo(desapilar(p)));
        }
        else
        {
            apilar(&aux,desapilar(p));
        }
    }
    return lista;
}
 nodo* eliminarPrimerNodo(nodo* lista)
 {
     nodo* seguidora=NULL;
     if(lista)
     {
         seguidora=lista;
         lista=lista->siguiente;
         free(seguidora);
     }
     return lista;
 }
nodo* eliminarValorEspecifico(nodo* lista)
{
    int numero=10;
    nodo* seguidora=lista;
    nodo*anterior=NULL;
    nodo* borrado=NULL;

        while(seguidora!=NULL)
        {
            if(seguidora->dato<=numero)
            {
                borrado=seguidora;
                seguidora=seguidora->siguiente;

                free(borrado);
                if(anterior!=NULL)
                {
                    anterior->siguiente=seguidora;
                }
                else
                {
                    lista=seguidora;
                }
            }
            else
            {
                anterior=seguidora;
                seguidora=seguidora->siguiente;
            }
        }
        return lista;

}
int main()
{

    Pila dada;
    inicPila(&dada);
    nodo* lista=inicLista();
    /*apilar(&dada,10);
    apilar(&dada,20);
    apilar(&dada,30);
    apilar(&dada,40);
    mostrarPila(&dada);
    leer(&dada);
    mostrarPila(&dada);
    */
    cargarPila(&dada);
    mostrarPila(&dada);
    printf("Llamo a funcion \n");
    lista=cargarListaPar(&dada,lista);
    mostrarLista(lista);
    printf("LLamo a funcion de eliminar menores de 10 \n");
    lista=eliminarValorEspecifico(lista);
    mostrarLista(lista);
}
