#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void sume(int *matrice, int n, int *suma_linie, int *suma_coloana)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        suma_linie[i] = 0;
        for (j = 0; j < n; j++) 
        {
            suma_linie[i] = suma_linie[i]  *(matrice + i*n + j);
        }
    }
    for(j = 0; j < n; j++)
    {
        suma_coloana[j] = 0;
        for(i = 0; i < n; i ++)
        {
            suma_coloana[j] = suma_coloana[j] + *(matrice + i*n + j);
        }
    }
}
int main()
{
    int matrice[20][20], suma_linie[20], suma_coloana[20];
    int n, i, j;

    printf("Introduceti numarul de linii si coloane ale matricei: ");
    scanf("%d", &n);
    if(n > 20)
    {
        printf("Numarul introdus este prea mare. Introduceti unul mai mic sau egal cu 20.");
        exit(1);
    }
    printf("Introduceti elementele: ");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrice[i][j]);
        }
    }
    sume(&matrice[0][0], n, suma_linie, suma_coloana);
    for(i = 0; i < n; i++)
    {
        printf("%d ", suma_linie[i]);
    }
    printf("\n");
    for(j = 0; j < n; j++)
    {
        printf("%d ", suma_coloana[j]);
    }
    return 0;
}
