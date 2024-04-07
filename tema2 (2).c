#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/*Se introduce un număr întreg n<10 și apoi n numere de tip float. Să se folosească funcția qsort
pentru a sorta aceste numere în mod crescător. Se va introduce apoi un număr x de tip float. Folosind funcția
bsearch, să se determine dacă x există în vectorul sortat. Se pot consulta paginile de manual pentru funcțiile qsort
și bsearch.*/

int comparinatorul(const void *element1, const void *element2)
{
    const float *a = (const float*)element1;
    const float *b = (const float*)element2;
    if(*a < *b)
    {
        return -1; //ordinea este corecta, crescatoare => nu se fac schimbari
    }
    else if(*a > *b)
    {
        return 1; //ordinea este gresita, elementele se interschimba
    }
    return 0;
}

int main()
{
    int n, i;
    float vector[10];
    float x;
    printf("Introduceti numarul de elemente: ");
    scanf("%d", &n);
    if(n >= 10)
    {
        printf("Numarul introdus este prea mare!");
        exit(1);
    }
    printf("Introduceti elementele: \n");
    for(i = 0; i < n; i++)
    {
        scanf("%f", &vector[i]);
    }
    qsort(vector, n, sizeof(float), comparinatorul);
    printf("Vectorul sortat este: \n");
    for(i = 0; i < n; i++)
    {
        printf("%.2f ", vector[i]);
    }
    printf("\n");
    printf("Introduceti numarul pe care doriti sa il cautati: \n");
    scanf("%f", &x);
    float *cautarinatorul = bsearch(&x, vector, n, sizeof(float), comparinatorul);
    if (cautarinatorul == NULL) 
    {
        printf("Numarul cautat nu exista in vector.\n");
    } 
    else 
    {
        printf("Numarul cautat exista in vector.\n");
    }
    return 0;
}