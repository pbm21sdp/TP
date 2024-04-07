#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*Să se scrie o funcție care primește o listă și returnează lista respectivă cu elementele inversate.
Funcția va acționa doar asupra listei originare, fără a folosi vectori sau alocare de noi elemente.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
    int n;
    struct elem* urm;
} elem;

elem* nou(int n, elem* urm) {
    elem* e = (elem*)malloc(sizeof(elem));
    if (!e) {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    e->n = n;
    e->urm = urm;
    return e;
}

typedef struct {
    elem* prim;
    elem* ultim;
} Lista;

void init(Lista* lista) {
    lista->prim = NULL;
    lista->ultim = NULL;
}

void adaugaSfarsit(Lista* lista, int n) {
    elem* e = nou(n, NULL);
    if (lista->ultim) {
        lista->ultim->urm = e;
    }
    else {
        lista->prim = e;
    }
    lista->ultim = e;
}

void inversareLista(Lista* lista) {
    elem* pred = NULL;
    elem* crt = lista->prim;
    elem* urm = NULL;
    while (crt != NULL) {
        urm = crt->urm;
        crt->urm = pred;
        pred = crt;
        crt = urm;
    }
    lista->prim = pred;
}

void afisare(Lista* lista) {
    elem* crt;
    for (crt = lista->prim; crt; crt = crt->urm) {
        printf("%d ", crt->n);
    }
    putchar('\n');
}

void eliberare(Lista* lista) {
    elem* p, * crt = lista->prim;
    while (crt) {
        p = crt->urm;
        free(crt);
        crt = p;
    }
}

Lista inversare(Lista* lista) {
    inversareLista(lista);
    return *lista;
}

int main() {
    Lista lista;
    init(&lista);
    adaugaSfarsit(&lista, 1);
    adaugaSfarsit(&lista, 2);
    adaugaSfarsit(&lista, 3);
    adaugaSfarsit(&lista, 4);
    adaugaSfarsit(&lista, 5);

    printf("Lista initiala: ");
    afisare(&lista);

    Lista listaInversata = inversare(&lista);

    printf("Lista inversata: ");
    afisare(&listaInversata);

    eliberare(&lista);
    return 0;
}





