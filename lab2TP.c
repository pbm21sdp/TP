#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Se cere un număr n și apoi un vector de n rezultate ale studenților la un examen. Fiecare rezultat
este definit prin (nume,nota). Se cere să se sorteze folosind qsort vectorul în ordinea notelor, notele cele mai mari
fiind primele. Dacă două note sunt identice, rezultatele respective se vor sorta în ordinea alfabetică a numelor.*/

/*
typedef struct {
    char nume[30];
    int nota;
} student;

void umplere(student *b, int size)
{
    int i;
    for(i = 0; i < size; i ++)
    {
        printf("Introduceti numele studentului: ");
        scanf("%s", b[i].nume);
        printf("Introduceti nota studentului: ");
        scanf("%d",&b[i].nota);
    }
}
int comparinatorul(student *std1, student *std2)
    {   
        if(std1->nota > std2->nota) //nota studentului 1 este mai mare decat a studentului 2, deci ordinea este corecta, returneaza un intreg negativ
        {
            return -1;
        }
        else if(std1->nota < std2->nota) //ordinea este gresita, returneaza un intreg pozitiv
        {
            return 1;
        }
        else if(strcmp(std1->nume,std2->nume)>0)
        {
            return 1;
        }
        return -1;
    }

int main()
{
    int n, i;
    student elev[21];
    printf("Introduceti numarul de studenti: ");
    scanf("%d", &n);
    umplere(elev, n);
    typedef int (*comp_t)(const void*, const void*);
    qsort(elev,n,sizeof(student),(comp_t)comparinatorul);
    for(i = 0; i < n; i++)
    {
        printf("%s %d", elev[i].nume, elev[i].nota);
        printf("\n");
    }
    return 0;
}
*/

/*Să se implementeze o funcție care primește ca parametri un vector de întregi, numărul elementelor
din vector transmis prin adresă și un predicat care testează dacă un întreg îndeplinește o anumită condiție. Funcția
va sterge din vector toate elementele care nu îndeplinesc condiția dată și va actualiza numărul elementelor cu
numărul de elemente rămas în vector. Să se testeze funcția cu un predicat care testează dacă un număr este
negativ și să se afișeze vectorul rezultat.*/

int conditie(int a)
{
    if(a % 2 == 0)
    {
        return 1;
    }
    return 0;
}

void stergere(int *v, int *n)
{
    int i;
    for(i = 1; i < *n; i++)
    {
        v[i-1] = v[i];
    }
}

void citire(int *v, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        scanf("%d", &v[i]);
    }
}
int main()
{
    int n, i, v[100];
    printf("Introduceti numarul de elemente ale vectorului: ");
    scanf("%d", &n);
    citire(v, n);
    return 0;
}