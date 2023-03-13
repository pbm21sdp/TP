#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*Aplicația 4.0: Să se creeze o structură care reține următoarele informații despre un student: nume (maxim 20 de
caractere), nota. Să se citească un element din structură și să se afișeze pe ecran.*/

typedef struct Student{
    char nume[20];
    float nota;
}Student;

int main()
{
    int i;
    Student studenti[30];
    int n, a;
    printf("Introduceti numarul de studenti: \n");
    scanf("%d", &n);
    getchar();
    for(i=1; i<=n; i++)
    {
        printf("Introduceti numele studentului %d:\n", i);
        scanf("%20s", studenti[n].nume);
        getchar();
        printf("Introduceti nota studentului %d:\n", i);
        scanf("%f", &studenti[n].nota);
        getchar();
    }
    printf("Introduceti numarul studentului pe care doriti sa il vizualizati:\n");
    scanf("%d", &a);
    getchar();
    printf("Numele studentului %d este:\n", a);
    printf("%s", studenti[a].nume);
    printf("Nota studentului %d este:\n", a);
    printf("%f", studenti[a].nota);
    return 0;
}
