#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    float a[10][10];
    int m, n, i, j;
    printf("Introduceti dimensiunile matricei: ");
    scanf("%d %d", &m, &n);
    if(m > 10 || n > 10)
    {
        printf("Ati introdus numere prea mari.");
        exit(1);
    }
    for(i = 0; i < m ; i++)
    {
        for(j = 0; j < n; j++)
        {
            a[i][j] =(i+j)/2.0;
        }
    }
    for(i = 0; i < m ; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%5.2g ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}