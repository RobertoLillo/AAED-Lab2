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
void obtenerDimensiones(int *arreglo);
lista crearMaquina(int alto, int ancho);
lista insertarHeader(lista listaPrincipal, lista listaGuardar);


lista insertarLista(lista actual, char elemento);
lista borrarLista(lista rodillo);
void imprimirLista(nodo *lista, int tamano);