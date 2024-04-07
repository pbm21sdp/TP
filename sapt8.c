#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

/*Aplicația 8.1: Să se modifice exemplul 1 astfel încât el să numere de câte ori apare fiecare cuvânt în propoziție.
Pentru aceasta, cuvintele vor fi adăugate doar cu litere mici și fiecare cuvânt va avea asociat un contor. Dacă un
cuvânt nou nu există în propoziție, el va fi adăugat. Altfel, dacă el există deja, doar se va incrementa contorul
cuvântului existent. La afișare, pentru fiecare cuvânt se va afișa și contorul său.*/

typedef struct Cuvant{
    char text[16]; 
    int contor;
    struct Cuvant *pred; 
    struct Cuvant *urm; 
}Cuvant;

Cuvant *Cuvant_nou(const char *text)
{
    Cuvant *c=(Cuvant*)malloc(sizeof(Cuvant));
    if(!c)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    strcpy(c->text,text);
    c->contor = 1;
    return c;
}
typedef struct{
     Cuvant *prim; 
     Cuvant *ultim; 
 }Propozitie;

void Propozitie_init(Propozitie *p)
{
     p->prim=p->ultim=NULL;
}

void Propozitie_adauga(Propozitie* p, const char* text) {
    char cuvant[16];
    int i = 0;
    for (const char* ptr = text; *ptr; ptr++) {
        if (isalpha(*ptr)) {
            cuvant[i++] = tolower(*ptr);
        }
    }
    cuvant[i] = '\0';

    Cuvant* c;
    for (c = p->prim; c; c = c->urm) {
        if (strcmp(c->text, cuvant) == 0) {
            c->contor++;
            return;
        }
    }
    c = Cuvant_nou(cuvant);
    c->pred = p->ultim;
    if (p->ultim) {
        p->ultim->urm = c;
    }
    else {
        p->prim = c;
    }
    p->ultim = c;
    c->urm = NULL;
}

Cuvant *Propozitie_cauta(Propozitie *p,const char *text)
{
    Cuvant *c;
    for(c=p->prim;c;c=c->urm)
    {
        if(!strcmp(c->text,text)) return c;
    }
    return NULL;
}

void Propozitie_sterge(Propozitie *p,Cuvant *c)
{
    if(c->pred)
    { 
        c->pred->urm=c->urm; 
    }
    else
    {
        p->prim=c->urm; 
    }
    if(c->urm)
    { 
        c->urm->pred=c->pred; 
    }
    else
    { 
        p->ultim=c->pred; 
    }
    free(c);
}

void Propozitie_elibereaza(Propozitie *p)
{
    Cuvant *c,*urm;
    for(c=p->prim;c;c=urm)
    {
        urm=c->urm;
        free(c);
    }
    Propozitie_init(p);
}

void Propozitie_afisare(Propozitie* p) 
{
    Cuvant* c;
    for (c = p->prim; c; c = c->urm) {
        printf("%s (%d) ", c->text, c->contor);
    }
    putchar('\n');
}


int main()
{
    Propozitie p;
    int op; 
    char text[16];
    Cuvant *c;
    Propozitie_init(&p); 
    do{
        printf("1 - propozitie noua\n");
         printf("2 - afisare\n");
        printf("3 - stergere cuvant\n");
        printf("4 - iesire\n");
        printf("optiune: ");scanf("%d",&op);
        switch(op){
         case 1:
            Propozitie_elibereaza(&p); 
            printf("Introduceti propozitia: ");
            getchar(); 
            fgets(text, sizeof(text), stdin); 
            char* token = strtok(text, " ");
            while (token != NULL) {
                Propozitie_adauga(&p, token);
                token = strtok(NULL, " ");
            }
        break;
         case 2:
            Propozitie_afisare(&p);
        break;
         case 3:
            printf("cuvant de sters:");
            scanf("%s",text);
            c=Propozitie_cauta(&p,text);
            if(c)
            {
            Propozitie_sterge(&p,c);
            }
            else
            {
            printf("cuvantul \"%s\" nu se gaseste in propozitie\n",text);
            }
        break;
         case 4:break;
         default:printf("optiune invalida");
        }
 }while(op!=4);
 return 0;
}