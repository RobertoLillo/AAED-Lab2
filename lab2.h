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
    int largo;
    lista matrix;
} matriz;