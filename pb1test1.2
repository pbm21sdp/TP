#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Film {
    char nume[36];
    unsigned int an:11; //11 biți pentru a reprezenta anul apariției
    unsigned int premii:1; //1 bit pentru a reprezenta dacă a primit premii sau nu
};

int cmp(const void *a, const void *b) {
    struct Film *f1 = (struct Film *)a;
    struct Film *f2 = (struct Film *)b;
    if(f1->premii > f2->premii) {
        return -1;
    } else if(f1->premii < f2->premii) {
        return 1;
    } else {
        return strcmp(f1->nume, f2->nume);
    }
}

int main() {
    int n, i;
    printf("Introduceti numarul de filme: ");
    scanf("%d", &n);
    struct Film *filme = (struct Film*)malloc(n * sizeof(struct Film));
    printf("Introduceti informatiile despre filme:\n");
    for(i = 0; i < n; i++) {
        printf("Filmul %d:\n", i+1);
        printf("Numele filmului: ");
        scanf("%35s", filme[i].nume);
        printf("Anul aparitiei (maxim 2023): ");
        scanf("%d", &filme[i].an);
        if(filme[i].an > 2023) {
            printf("Anul aparitiei este prea mare. Introduceti un an mai mic sau egal cu 2023.\n");
            i--;
            continue;
        }
        printf("A primit premii? (da/nu): ");
        char str[3];
        scanf("%s", str);
        if(strcmp(str, "da") == 0) {
            filme[i].premii = 1;
        } else {
            filme[i].premii = 0;
        }
    }
    printf("\nInformatiile despre filme sunt:\n");
    for(i = 0; i < n; i++) {
        printf("%d. %s (%d)", i+1, filme[i].nume, filme[i].an);
        if(filme[i].premii == 1) {
            printf(" - a primit premii");
        }
        printf("\n");
    }
    printf("\nVectorul sortat este:\n");
    qsort(filme, n, sizeof(struct Film), cmp);
    for(i = 0; i < n; i++) {
        printf("%d. %s (%d)", i+1, filme[i].nume, filme[i].an);
        if(filme[i].premii == 1) {
            printf(" - a primit premii");
        }
        printf("\n");
    }
    free(filme);
    return 0;
}
``
