#include "lab2.h"

int main() {
    
    leerArchivo();

    return 0;
}

void leerArchivo() {

    FILE *pArchivo = fopen("maquina.in", "r");
    int alto, ancho, i, j;
    char simbolo;
    matriz maquina;
    lista lineaSimbolos;
    lista *aux;

    if (pArchivo) {

        fscanf(pArchivo, "%i %i\n", &alto, &ancho);

        maquina.alto = alto;
        maquina.ancho = ancho;
        maquina.cantidadDeListas = 0;

        for (i = 0; i < alto; i++) {
            lista *nuevaLista = (lista *)malloc(sizeof(lista));
            nuevaLista->ant =NULL;
            nuevaLista->sgte=NULL;
            nuevaLista->inicio=NULL;
            nuevaLista->largo = 0;
            
            for (j = 0; j < (ancho * 2); j++) {
                fscanf(pArchivo, "%c", &simbolo);
                if (simbolo != ' ' && simbolo != '\n') {
                
                    insertarEnLista(nuevaLista, simbolo);

                }
            }
            // LINEA LEIDA
            imprimirLista(nuevaLista->inicio);
            
            maquina = insertarListaEnMatriz(maquina, nuevaLista);
            
            printf("\n");
        }
    }
    else {
        printf("No se pudo leer el archivo\n");
    }

    fclose(pArchivo);
    return;
}

void insertarEnLista(lista *actual, char elemento) {

    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));
    nuevoNodo->simbolo = elemento;
    nuevoNodo->sgte = NULL;

    if (actual->largo == 0) {
        actual->inicio = nuevoNodo;
        actual->largo = 1;
    }
    else {
        int i;
        nodo *aux = actual->inicio;
        for (i = 0; i < (actual->largo - 1); i++) {
            aux = aux->sgte;
        }
        aux->sgte = nuevoNodo;
        actual->largo++;
    }
} 

lista borrarLista(lista actual) {

    int i;
    nodo *aux = actual.inicio;
    while (aux->sgte != NULL) {
        actual.inicio = aux->sgte;
        free(aux);
        actual.largo--;
        aux = actual.inicio;
    }
    free(aux);

    return actual;
}

void imprimirLista(nodo *lista) {

	nodo *aux;
	aux = lista;
	while(aux->sgte != NULL){
		printf("%c, ", aux->simbolo);
		aux = aux->sgte;
	}
	printf("%c, ", aux->simbolo);
	printf("\n");

    return;
}

matriz insertarListaEnMatriz(matriz actual, lista *ingresar) {

    if (actual.cantidadDeListas == 0) {
        actual.alto = 1;
        actual.ancho = ingresar->largo;
        actual.cantidadDeListas = 1;
        actual.matrix = ingresar;
    }
    else {
        int i;
        lista *aux1 = actual.matrix;
        lista *aux2 = actual.matrix;

        for (i = 0; i < (actual.cantidadDeListas - 1); i++) {
            aux1 = aux1->sgte;
            aux2 = aux2->sgte;
        }
        aux1->sgte = ingresar;
        aux1 = aux1->sgte;
        aux1->ant = aux2;
        actual.alto++;
        actual.cantidadDeListas++;
    }

    return actual;
}