#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{   int m, n, a[10][10], i, j;
    printf("Introduceti dimensiunile matricei: ");
    scanf("%d %d", &m, &n);
    if(m > 10 || n > 10)
    {
        printf("Ati introdus numere prea mari");
        exit(1);
    }
    for(i = 0; i < m ; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i > j)
            {
                a[i][j] = i;
            }
            else
            {
                a[i][j] = j;
            }
        }
    }
    for(i = 0; i < m ; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}