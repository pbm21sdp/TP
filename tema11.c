#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define G 6.674e-11

/*Aplicația 11.2: Se cere un n strict pozitiv și patru valori reale: ma, mb, m, d. ma și mb reprezintă masele a două
corpuri situate la distanța d unul de celălalt. m este masa unui corp care pornește din a și ajunge în b, din n pași
egali. Să se calculeze în fiecare punct al traseului lui m forța F de atracție gravitațională care acționează asupra
lui. F va fi cu semn: negativ înseamnă că m este atras către ma, iar pozitiv către mb. Formula atracției gravitaționale
dintre două corpuri m1 și m2, situate la distanța d unul de celălalt este: F=G*m1*m2/d2
, unde G=6.674e-11. Masele
sunt exprimate în kilograme, distanțele în metri, iar forțele în newtoni.*/

int main()
{
    int n, i;
    double ma, mb, m, d, F, MasaExtraPerPas, DistantaPerPas;
    printf("Introduceti numarul de pasi n.\n");
    scanf("%d", &n);
    if(n <= 0)
    {
        printf("n trebuie sa fie un numar strict pozitiv.\n");
        exit(1);
    }
    printf("Introduceti masa primului corp ma:\n");
    scanf("%lf", &ma);
    printf("Introduceti masa celui de-al doilea corp mb:\n");
    scanf("%lf", &mb);
    printf("Introduceti masa corpului care porneste din a, m:\n");
    scanf("%lf", &m);
    printf("Introduceti distanta d:\n");
    scanf("%lf", &d);
    MasaExtraPerPas = (ma + mb)/n;
    DistantaPerPas = d/n;
    for(i = 0; i < n; i++)
    {
        F = (G * m * mb)/(d * d);
        printf("F = %lf\n", F);
        m = m + MasaExtraPerPas;
        d = d - DistantaPerPas;
    }

    return 0;
}