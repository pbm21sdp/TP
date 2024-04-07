#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*Aplicația 7.1: Să se scrie o funcție care primește două liste și returnează 1 dacă ele sunt identice, altfel 0. */

typedef struct elem{
    int n; 
    struct elem *urm; 
}elem;

elem *nou(int n,elem *urm)
{
    elem *e=(elem*)malloc(sizeof(elem));
    if(!e){
    printf("memorie insuficienta");
    exit(EXIT_FAILURE);
}
    e->n=n;
    e->urm=urm;
    return e;
}

typedef struct{
    elem *prim;
    elem *ultim; 
}Lista;

void init(Lista *lista)
{
    lista->prim=NULL;
    lista->ultim=NULL;
}

void adaugaSfarsit(Lista *lista,int n)
{
    elem *e=nou(n,NULL);
    if(lista->ultim)
    { 
        lista->ultim->urm=e;
    }
    else
    { 
        lista->prim=e;
    }
    lista->ultim=e;
}

void afisare(Lista *lista)
{
    elem *crt;
    for(crt=lista->prim;crt;crt=crt->urm)
    {
    printf("%d ",crt->n);
    }
putchar('\n');
}

void eliberare(Lista *lista)
{
    elem *p,*crt=lista->prim;
    while(crt)
    {
    p=crt->urm;
    free(crt);
    crt=p;
    }
}

int comparare(Lista *lista1, Lista *lista2)
{
    int k = 0;
    elem *crt1;
    elem *crt2;
    for(crt1=lista1->prim; crt1; crt1=crt1->urm)
    {
        for(crt2 = lista2->prim; crt2; crt2 = crt2->urm)
        {
            if(crt1->n == crt2->n)
            {
                k = 1;
            }
        }
    }
    return k;
}

int main()
{
    Lista lista1, lista2, lista3;
    init(&lista1);
    init(&lista2);
    init(&lista3);
    adaugaSfarsit(&lista1,108);
    adaugaSfarsit(&lista1,-1);
    adaugaSfarsit(&lista1,49);
    adaugaSfarsit(&lista2, 32);
    adaugaSfarsit(&lista2, 43);
    adaugaSfarsit(&lista2, 76);
    adaugaSfarsit(&lista3,108);
    adaugaSfarsit(&lista3,-1);
    adaugaSfarsit(&lista3,49);
    afisare(&lista1);
    afisare(&lista2);
    if(comparare(&lista1, &lista2) == 1)
    {
        printf("Listele sunt identice.\n");
    }
    else
    {
        printf("Listele nu sunt identice.\n");
    }
    if(comparare(&lista1, &lista3) == 1)
    {
        printf("Listele sunt identice.\n");
    }
    else
    {
        printf("Listele nu sunt identice.\n");
    }
    eliberare(&lista1);
    eliberare(&lista2);
    eliberare(&lista3);
    return 0;
}

/*Să se scrie o funcție care primește o listă și returnează lista respectivă cu elementele inversate.
Funcția va acționa doar asupra listei originare, fără a folosi vectori sau alocare de noi elemente.*/
