/********** Estructuras **********/
typedef struct Nodo {
	char valor;
	struct Nodo *sgte;
} nodo;

typedef struct ListaEnlazada {
	nodo *inicio;
	nodo *fin;
	int size;
} lista;

/********** Prototipos **********/


lista insertarLista(lista actual, char elemento);
lista borrarLista(lista rodillo);
void imprimirLista(nodo *lista, int tamano);