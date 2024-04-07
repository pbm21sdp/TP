#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/*Aplicația 6.9: Scrieți un program care calculează suma parametrilor primiți din linia de comandă (numere reale).
Exemplu: execuția fără parametri va fișa 0, iar execuția cu parametrii 1.1 6.57 99.122 va afișa 106.792
int main(int argc, char *argv[])
{
    int i;
    float n, s = 0;
    if(argc == 0)
    {
        printf("0");
    }
    else for (i = 1; i < argc; i++) 
    {
        n = atof(argv[i]);
        s = s + n;
    }
    printf("%.3f\n", s);
    return 0;
}
*/

/*Aplicația 6.4: Să se scrie o funcție crescator(int n,char tip,...) care primește un număr n de valori și returnează 1
dacă ele sunt în ordine strict crescătoare, altfel 0. Caracterul tip indică tipul valorilor și poate fi ‘d’ - int, ‘f’ - double.
Exemplu: printf(“%d”,crescator(3,’d’,-1,7,9))*/

/*
int crescator(int n, char tip, ...)
{
    va_list va; 
    va_start(va,tip); //primul nr din lista de argumente variabile
    int crescator = 1;
    int i;
    if(n == 1)
    {
        printf("Nu se poate stabili ordinea elementelor pentru ca exista unul singur\n");
    }
    else if(tip == 'd')
    {
        int nr2 = va_arg(va, int); //al doilea nr din lista de argumente variabile
        for(i = 2; i<=n; i++)
        {
            int nr_urm = va_arg(va, int);
            if(nr_urm < nr2)
            {
                crescator = 0;
                break;
            }
            nr2 = nr_urm;
        }
    }
    else if(tip == 'f')
    {
        double nr2 = va_arg(va, double);
        for(i = 2; i <=n; i++)
        {
            double nr_urm =  va_arg(va, double);
            if(nr_urm < nr2)
            {
                crescator = 0;
                break;
            }
            nr2 = nr_urm;
        }
    }
    else 
    {
        crescator = 0;
    }
    va_end(va);
    return crescator;
}


int main()
{
    printf("%d\n",crescator(3,'d',-1,7,9));
    printf("%d\n",crescator(3,'d',-1,10,9));
    printf("%d\n", crescator(4, 'f', 6.78, 4.32, 1.23, 5.87));
    printf("%d\n", crescator(3, 'f', 2.23, 4.65, 7.54));
    printf("%d\n", crescator(5, 'd', 3, 4, 8, 1, 6));
    printf("%d\n", crescator(1, 'd', 2));
    printf("%d\n", crescator(3, 'f', 2.21, 3.32, 5.43));
    printf("%d\n", crescator(3, 'd', 1, 2, 3));
    return 0;
}
*/

