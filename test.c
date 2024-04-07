#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
    int m, n, i, j, k=0;
    int a[10][10];
    printf("Introduceti dimensiunile matricii ");
    scanf("%d %d", &m, &n);
    if(m > 10 || n > 10)
    {
        printf("Ati introdus numere mai mari decat 10.");
        exit(1);
    }
    for(i = 0; i < m; i++)
    {
        for(j=0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] < 0)
                k++;
        }
    }
    if(k == 0)
    {
        printf("Matricea are toate elementele pozitive");
    }
    else
    {
        printf("Matricea nu are toate elementele pozitive");
    }
    return 0;
}