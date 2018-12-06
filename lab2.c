#include "lab2.h"

void leerArchivo(const char *nombreArchivo){

    FILE *pArchivo = fopen(nombreArchivo, "r");
    int alto, ancho, i, j;
    char simbolo;

    if (pArchivo) {

        fscanf(pArchivo, "%i %i\n", &alto, &ancho);
        for (i = 0; i < alto; i++) {
            for (j = 0; j < (ancho * 2); j++) {
                fscanf(pArchivo, "%c", &simbolo);
                if (simbolo != ' ' && simbolo != '\n') {
                
                }
            }
            printf("\n");
        }

    }
    else {
        printf("No se pudo leer el archivo\n");
    }

    fclose(pArchivo);
    return;
}

lista insertarEnLista(lista actual, char elemento) {

    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));
    nuevoNodo->simbolo = elemento;
    nuevoNodo->sgte = NULL;

    if (actual.largo == 0) {
        actual.inicio = nuevoNodo;
        actual.largo = 1;
    }
    else {
        int i;
        nodo *aux = actual.inicio;
        for (i = 0; i < (actual.largo - 1); i++) {
            aux = aux->sgte;
        }
        aux->sgte = nuevoNodo;
        actual.largo++;
    }

    return actual;
} 

matriz insertarEnMatriz(matriz actual, lista elemento) {

    

}



int main(int argc, char const *argv[])
{
    if (argc > 1) {
        leerArchivo(argv[1]);
    }
    else {
        printf("Ingrese archivo a leer\n");
        lista listaqla;
        listaqla = insertarEnLista(listaqla, 'a');
        printf("%c\n", listaqla.inicio->simbolo);
        listaqla = insertarEnLista(listaqla, 'b');
        printf("%c\n", listaqla.inicio->sgte->simbolo);
    }   
    return 0;
}
