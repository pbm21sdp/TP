#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

int main()
{
    int a[10][10];
    int m, n, i, j, count = 1;
    printf("Introduceti numarul de linii m:\n");
    scanf("%d", &m);
    printf("Introduceti numarul de coloane n:\n");
    scanf("%d", &n);
    if(m >= 10 || n >= 10)
    {
        printf("Ati introdus numere prea mari.\n");
        exit(1);
    }
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] < 0)
            {
                count = -1;
            }
        }
    }
    if(count == 1)
    {
        printf("Matricea are toate elementele pozitive.\n");
    }
    else 
    {
        printf("Matricea nu are toate elementele pozitive.\n");
    }
    return 0;
}