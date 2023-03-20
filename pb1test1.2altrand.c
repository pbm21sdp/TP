#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct angajat {
    char nume[46];  // 45 caractere + terminatorul de sir '\0'
    unsigned int an_nastere: 12;  // 2^12 = 4096, deci putem stoca ani de la 0 la 4095
    unsigned int bonus: 1;
};
int main() {
    int n;
    printf("Introduceti numarul de angajati: ");
    scanf("%d", &n);

    struct angajat *angajati = (struct angajat*)malloc(n * sizeof(struct angajat));

    for (int i = 0; i < n; i++) {
        printf("Introduceti numele angajatului %d: ", i + 1);
        scanf("%45s", angajati[i].nume);

        printf("Introduceti anul nasterii angajatului %d: ", i + 1);
        scanf("%u", &angajati[i].an_nastere);

        printf("Are angajatul %d bonus? (1 = da, 0 = nu): ", i + 1);
        scanf("%u", &angajati[i].bonus);
    }

    // afisare vector de angajati
    for (int i = 0; i < n; i++) {
        printf("%s %u %u\n", angajati[i].nume, angajati[i].an_nastere, angajati[i].bonus);
    }

    // sortare vector de angajati dupa nume
    qsort(angajati, n, sizeof(struct angajat), comparare_nume);

    // afisare vector de angajati sortat
    for (int i = 0; i < n; i++) {
        printf("%s %u %u\n", angajati[i].nume, angajati[i].an_nastere, angajati[i].bonus);
    }

    free(angajati);
    return 0;
}
