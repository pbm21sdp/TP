#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


/*Aplicația 4.1: Să se codifice cu ajutorul structurilor cu câmpuri pe biți informațiile despre un fișier: nume (șir de
maxim 15 caractere), dimensiunea acestuia (int - număr de octeți, maxim 1024 octeți), tipul acestuia (.txt - 0, .doc
- 1, .xls – 2), tipul fisierului (normal – 0, read-only – 1). Să se citească informația despre un fișier, și să se afișeze
pe ecran. */

typedef struct fisier{
    char nume[16];
    int dimensiune : 10; 
    int tip : 2; 
    int tipFisier : 1; 
}fisier;

int main()
{
    struct fisier Fisier;
    int aux_dimensiune;
    int aux_tip;
    int aux_tipFisier;
    printf("Introduceti numele fisierului: ");
    scanf("%15s", Fisier.nume);
    printf("Introduceti dimensiunea fisierului in octeti: ");
    scanf("%d", &aux_dimensiune);
    Fisier.dimensiune = aux_dimensiune;
    printf("Introduceti tipul fisierului (0 - .txt, 1 - .doc, 2 - .xls): ");
    scanf("%d", &aux_tip);
    Fisier.tip = aux_tip;
    printf("Introduceti tipul fisierului (0 - normal, 1 - read-only): ");
    scanf("%d", &aux_tipFisier);
    Fisier.tipFisier = aux_tipFisier;
    printf("Nume: %s\n", Fisier.nume);
    printf("Dimensiune: %d octeti\n", Fisier.dimensiune);
    if(Fisier.tip == 0)
    {
        printf("Tip: %s\n", ".txt");
    }
    else if(Fisier.tip == 1)
    {
        printf("Tip: %s\n", ".doc");
    }
    else
    {
        printf("Tip: %s\n", ".xls");
    }
    if(Fisier.tipFisier == 0)
    {
        printf("Tip fisier: %s\n", "normal");
    }
    else
    {
        printf("Tip fisier: %s\n", "read-only");
    }
    return 0;
}
