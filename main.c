#include <stdio.h>
#include <stdlib.h>

typedef struct Lista Lista;

struct Lista
{
    int numero;
    Lista *siguiente;
};

void ListaAgrega(Lista **lista, int numero);
void ListaLlena(Lista **lista, int limite);
void ListaImprime(Lista **lista);
void ListaLibera(Lista **lista);

int main(void)
{
    Lista *lista;
    lista = NULL;
    ListaLlena(&lista, 10);
    ListaImprime(&lista);
    ListaLibera(&lista);
    return 0;
}

void ListaAgrega(Lista **lista, int numero)
{
    Lista *ix;
    ix = *lista;
    if (ix == NULL) {
        *lista = (Lista *) malloc(sizeof(Lista));
        (**lista).numero = numero;
        (**lista).siguiente = NULL;
        return;
    }
    if (ix->siguiente == NULL) {
        ix->siguiente = (Lista *) malloc(sizeof(Lista));
        ix = ix->siguiente;
        ix->numero = numero;
        ix->siguiente = NULL;
        return;
    }
    while (ix->siguiente != NULL) {
        ix = ix->siguiente;
    }
    ix->siguiente = (Lista *) malloc(sizeof(Lista));
    ix = ix->siguiente;
    ix->numero = numero;
    ix->siguiente = NULL;
}

void ListaLlena(Lista **lista, int limite)
{
    int ix;
    for (ix = 0; ix < limite; ++ix) {
        ListaAgrega(lista, ix);
    }
}

void ListaImprime(Lista **lista)
{
    Lista *ix;
    ix = *lista;
    while (ix != NULL) {
        printf("%d ", ix->numero);
        ix = ix->siguiente;
    }
}

void ListaLibera(Lista **lista)
{
    Lista *ix;
    Lista *ixAux;
    ix = *lista;
    while (ix != NULL) {
        ixAux = ix->siguiente;
        free(ix);
        ix = ixAux;
    }
}
