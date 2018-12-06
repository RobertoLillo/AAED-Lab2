#include <stdio.h>
#include <stdlib.h> //malloc

#define TRUE 1
#define FALSE 0

typedef struct Nodo {
    char simbolo;
    struct Nodo *sgte;
} nodo;

typedef struct Lista {
    int largo;
    nodo *inicio;
    struct Lista *sgte;
    struct Lista *ant;
} lista;

typedef struct {
    int alto;
    int ancho;
    int cantidadDeListas;
    lista *matrix;
} matriz;

void leerArchivo();
void insertarEnLista(lista *actual, char elemento);
void imprimirLista(nodo *lista);
matriz insertarListaEnMatriz(matriz actual, lista *ingresar);
