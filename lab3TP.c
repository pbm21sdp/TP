#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

/*Aplicatia 3.2 Implementati pe calculator structura de date coada, asa cum este descrisa in
laborator.*/

#define QUEUE_EMPTY INT_MIN

void throwError(const char *msg)
{
    fprintf(stderr, "%s:%s\n", msg, strerror(errno));
    exit(errno);
}

void *allocateMemory(unsigned const long long size) 
{

    void *tmp = malloc(size);
    if (NULL == tmp) 
    {
        throwError("Eroare la alocarea memoriei");
    }

    return tmp;
}

typedef unsigned Element_t;
typedef struct Coada *Coada_t;

struct Coada {
    Element_t data;
    Coada_t next;
};

Coada_t initializare_Coada() {
    Coada_t coada = (Coada_t) allocateMemory(sizeof(struct Coada));
    coada->next = NULL;

    return coada;
}

Coada_t adaugare_element(Coada_t q, Element_t e) {

    if (NULL == q) {
        throwError("Coada nu este initializata.");
    }
    Coada_t newElement = initializare_Coada();
    newElement->data = e;
    newElement->next = NULL;

    if (NULL == q->next) {
        q->next = newElement;
    } else {
        Coada_t tmp = q->next;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newElement;
    }
    return q;
}

Element_t peek(Coada_t q) {
    if (NULL == q || NULL == q->next) {
        return QUEUE_EMPTY;
    }
    return q->next->data;
}

int main() 
{
    Coada_t q = initializare_Coada();
    q = adaugare_element(q, 25);
    q = adaugare_element(q, 45);
    q = adaugare_element(q, 78);
    q = adaugare_element(q, 34);
    q = adaugare_element(q, 89);
    q = adaugare_element(q, 40);
    Element_t el = peek(q);
    printf("Primul element este %u\n", el);
    return 0;
}