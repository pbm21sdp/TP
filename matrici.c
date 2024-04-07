#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#define M 10

void afisare(int a[][M], int m, int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m, n, a[10][10], i, j;
    printf("Introduceti numarul de linii m:\n");
    scanf("%d", &m);
    printf("Introduceti numarul de coloane n:\n");
    scanf("%d", &n);
    if(m >= 10 || n >= 10)
    {
        printf("Numerele introduse sunt prea mari.");
        exit(1);
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i > j)
            {
                a[i][j]= i;
            }
            else 
            {
                a[i][j] = j;
            }
        }
    }
    afisare(a, m, n);
    return 0;
}