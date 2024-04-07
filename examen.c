#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    FILE *f, *f1;
    f = fopen("TP.txt", "w");
    f1 = fopen("EX.dat", "wb");
    int n = 21;
    if(f==NULL)
    {
        printf("Eroare la deschiderea fisierului.\n");
        exit(1);
    }
    if(f1 == NULL)
    {
        printf("Eroare la deschiderea fisierului.\n");
        exit(1);
    }
    fprintf(f, "Hello\n");
    fputs("Acesta este un fisier text\n", f);
    char sir[10] = "Briana\n";
    fputs(sir, f);
    char c = 'B';
    fputc(c, f);
    fwrite(&n, sizeof(int), 1, f1);
    fclose(f);
    fclose(f1);
    return 0;
}