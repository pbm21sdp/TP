#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <math.h>

/*Aplicația 6.3: Să se scrie o funcție absN(int n,...) care primește un număr n de adrese de tip float și setează la
fiecare dintre aceste adrese valoarea absolută de la acea locație.
Exemplu: absN(2,&x,&y); // echivalent cu x=fabs(x); y=fabs(y); */


void absN(int n, ...) 
{
    va_list va;
    va_start(va, n);
    for (int i = 0; i < n; i++) 
    {
        double *a = va_arg(va, double*);
        if(*a <= 0)
        {
            *a = fabs(*a);
        }
    }
    va_end(va);
}

int main()
{
    float a = 1.234;
    float b = -5.7688;
    float c = -3.42;
    float d = 98.5784;
    printf("Valorile initiale introduse sunt:\n");
    printf("a = %.2f, b = %.2f, c = %.2f, d = %.2f\n", a, b, c, d);
    absN(4, &a, &b, &c, &d);
    printf("a = %.2f, b = %.2f, c = %.2f, d = %.2f\n", a, b, c, d);

    return 0;
}
