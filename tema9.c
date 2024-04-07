#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*Aplicația 9.9: Sa se construiasca o lista liniara simplu inlantuita cu elemente numere intregi. Sa se stearga din
lista elementele pare*/

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

void stergePare(Lista* lista) {
    elem* crt = lista->prim;
    elem* ant = NULL;

    while (crt) {
        if (crt->n % 2 == 0) {
            if (ant) {
                ant->urm = crt->urm;
            }
            else {
                lista->prim = crt->urm;
            }

            if (crt == lista->ultim) {
                lista->ultim = ant;
            }

            elem* temp = crt;
            crt = crt->urm;
            free(temp);
        }
        else {
            ant = crt;
            crt = crt->urm;
        }
    }
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

int main() {
    Lista lista;
    init(&lista);

    adaugaSfarsit(&lista, 1);
    adaugaSfarsit(&lista, 2);
    adaugaSfarsit(&lista, 3);
    adaugaSfarsit(&lista, 4);
    adaugaSfarsit(&lista, 5);
    adaugaSfarsit(&lista, 6);

    printf("Lista initiala: ");
    afisare(&lista);

    stergePare(&lista);

    printf("Lista dupa stergere: ");
    afisare(&lista);

    eliberare(&lista);

    return 0;
}
