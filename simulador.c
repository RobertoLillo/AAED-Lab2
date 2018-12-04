#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "simulador.h"

/********** Main **********/
int main() {

    return 0;
}


/********** Otras funciones **********/
lista insertarLista(lista rodillo, char elemento) {

	nodo *nuevo = (nodo *)malloc(sizeof(nodo));
	nuevo->valor = elemento;
	nuevo->sgte = NULL;

	if (rodillo.size == 0) {
		rodillo.inicio = nuevo;
        rodillo.fin = nuevo;
		rodillo.size = 1;
	}
	else {
		nodo *aux = rodillo.inicio;
		int i;
		for (i = 0; i < (rodillo.size - 1); i++){
			aux = aux->sgte;
		}
		aux->sgte = nuevo;
        rodillo.fin = nuevo;
        nuevo->sgte = rodillo.inicio;
		rodillo.size++;
	}

	return rodillo;
}

lista borrarLista(lista rodillo) {

    int i;
    nodo *aux = rodillo.inicio;

    for (i = 0; i < (rodillo.size - 1); i++) {
        aux = aux->sgte;
    }
    aux->sgte = NULL;   // Dejar de ser lista enlazada circular.

    aux = rodillo.inicio;
    while (aux->sgte != NULL) {
        rodillo.inicio = aux->sgte;
        free(aux);
        rodillo.size--;
        aux = rodillo.inicio;
    }
    free(aux);

    return rodillo;
}

void imprimirLista(nodo *lista, int tamano) {

    int i;
	nodo *aux = lista;
	for (i = 0; i < (tamano - 1); i++){
		printf("%c", aux->valor);
		aux = aux->sgte;
	}
	printf("%c", aux->valor);
	printf("\n");

    return;
}