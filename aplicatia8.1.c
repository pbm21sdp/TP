#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
    int n, a[10][10], i, j, k = 0;
    printf("Introduceti dimensiunile matricei patratice: ");
    scanf("%d", &n);
    if(n >= 11)
    {
        printf("Ati introdus un numar prea mare.");
        exit(1);
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("a[%d][%d]= ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0; i < n; i++)
    { 
        for(j = 0; j < n; j++)
        {
            if (i == j)
            {
                if(a[i][j] == 1)
                {
                    k++;
                }
            }
            else
            {
                if(a[i][j] == 0)
                {
                    k++;
                }
            }
        }
    }
    if(k == n * n)
    {
        printf("Aceasta este o matrice unitate. ");
    }
    else
    {
        printf("Aceasta nu este o matrice unitate.");
    }
    return 0;
}