#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "simulador.h"

/********** Main **********/
int main() {

    srand(2018);
    int dimensiones[2];
    obtenerDimensiones(dimensiones);
    printf("%d %d\n", dimensiones[0], dimensiones[1]);

    lista maquina;
    maquina = crearMaquina(dimensiones[0], dimensiones[1]);


    return 0;
}

/********** Funciones pertenecientes al programa **********/
void obtenerDimensiones(int *arreglo) {

    char linea[10];

    FILE *pArchivo;
    pArchivo = fopen("maquina.in", "r");
    if (pArchivo == NULL) {
        printf("No se pudo leer el archivo.");
    }
    else{
        fscanf(pArchivo, "%d", &arreglo[0]);
        fscanf(pArchivo, "%d", &arreglo[1]);
    }

    fclose(pArchivo);

    return; 
}

lista crearMaquina(int alto, int ancho) {
    int i, j, k;
    char simbolo;
    char noUsar[20];
    nodo *aux1;
    lista listaFinal, listaAuxiliar;

    FILE *pArchivo;
    pArchivo = fopen("maquina.in", "r");
    fgets(noUsar, 20, pArchivo);

    for (i = 0; i < alto; i++) {
        for (j = 0; j < (2 * ancho); j++) {
            fscanf(pArchivo, "%c", &simbolo);
            if (simbolo != ' ' && simbolo != '\n') {
                listaAuxiliar = insertarLista(listaAuxiliar, simbolo);
            }
        }
        aux1 = listaAuxiliar.fin;
        aux1->sgte = NULL;  // Para que deje de ser circular.
        imprimirLista(listaAuxiliar.inicio, listaAuxiliar.size);

        printf("\n");
    }

    return listaAuxiliar;
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

lista insertarHeader(lista listaPrincipal, lista listaGuardar) {
    
    nodo *inicioListaGuardar;
    inicioListaGuardar = listaGuardar.inicio;

    if (listaPrincipal.size == 0) {
        listaPrincipal.inicio = inicioListaGuardar;
        listaPrincipal.fin = inicioListaGuardar;
        listaPrincipal.size = 1;
    }
    else {
        int i;
        nodo *aux = listaPrincipal.inicio;
        for (i = 0; i < (listaPrincipal.size - 1); i++) {
            aux = aux->sgte;
        }
        aux->sgte = inicioListaGuardar;
        listaPrincipal.fin = inicioListaGuardar;
        listaPrincipal.size++;
    }
    return listaPrincipal;
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