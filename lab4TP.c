
#include <stdio.h>
#include <stdint.h>
#include <string.h>


/*Aplicația 4.0: Să se creeze o structură care reține următoarele informații despre un student: nume (maxim 20 de
caractere), nota. Să se citească un element din structură și să se afișeze pe ecran.

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
        scanf("%20s", studenti[i].nume);
        getchar();
        printf("Introduceti nota studentului %d:\n", i);
        scanf("%f", &studenti[i].nota);
        getchar();
    }
    printf("Introduceti numarul studentului pe care doriti sa il vizualizati:\n");
    scanf("%d", &a);
    getchar();
    printf("Numele studentului %d este:\n", a);
    printf("%s", studenti[a].nume);
    printf("\n");
    printf("Nota studentului %d este:\n", a);
    printf("%f", studenti[a].nota);
    printf("\n");
    return 0;
}

*/

// Use malloc and realloc 
// FootballTeam *addPlayer(FootballTeam *team, FootballPlayer *player)
// FootballChampionship *addTeam(FootballChampionship *footballChampionship, FootballTeam *footballTeam)
/*
typedef struct FootballPlayer
{
    char *name;
    double salary;
} FootballPlayer;

typedef struct FootballTeam
{
    FootballPlayer **footbaballPlayers;
    char *name;
    int currentNumberOfPlayers;
    int currentAllocatedMemory;
} FootbaballTeam;

typedef struct FootballChampionship
{
    FootbaballTeam **footballTeams;
    char *name;
    int currentNumbersOfTeams;
    int currentAllocatedMemory;
} FootballChampionship;

FootballPlayer *searchFootballPlayerInFootballTeamByName(char *name, FootbaballTeam *footbalTeam)
{
    for (int i = 0; i < footbalTeam->currentNumberOfPlayers; ++i)
    {
        if (strcmp(footbalTeam->footbaballPlayers[i]->name, name) == 0)
        {
            return footbalTeam->footbaballPlayers[i];
        }
    }

    return NULL;
}

FootballPlayer *searchFootballPlayerInFootballChampionship(char *name, FootballChampionship *footballChampionship)
{
    for (int i = 0; i < footballChampionship->currentNumbersOfTeams; ++i)
    {
        FootbaballTeam *footballTeam = footballChampionship->footballTeams[i];

        FootballPlayer *footballPlayer = searchFootballPlayerInFootballTeamByName(name, footballTeam);
        if (footballPlayer != NULL)
        {
            return footballPlayer;
        }
    }

    return NULL;
}

int main()
{

    return 0;
}
*/

/*Subiectul 1: Să se imlementeze un program care gestionează un parc de automobile. Informaţiile relative la un
automobil sunt: codul mașinii (număr între 1 si 9000), numărul de locuri (între 1 și 9), puterea (în cai putere între 1
și 500), marca, culoarea, anul fabricaţiei maşinii (între 1800 și 2017). Parcul conține n automobile, datele sunt citite
de la tastatură. Să se scrie următoarele funcții de gestiune a mașinilor:
a) Introducerea unui automobil nou;
b) Ștergerea unui anumit automobil, al cărui cod e citit de la tastatură;
c) Afișarea întregii liste de automobile;
d) Afișarea pe ecran doar a automobilelor cu un anumit număr de locuri, citit de la tastatură;
e) Ordonarea listei în funcție de anul fabricației, folosind qsort.
Să se definească structura pentru o mașină cu ajutorul structurilor cu câmpuri pe biți astfel încât spațiul ocupat să
fie minim.*/

typedef struct Automobil{
    int cod_masina;
    int nr_locuri;
    int putere;
    char marca[100];
    char culoare[20];
    int an_fabricatie;
}Automobil;

void introducere_automobil(Automobil *a1)
{
    printf("Introduceti codul masinii: \n");
    scanf("%d" &a1.cod_masina);
    printf("Introduceti numarul de locuri: \n");
    scanf("%d", &a1.nr_locuri)
}
int main()
{
    Automobil automobile[50];
    int n;
    printf("Introduceti numarul de automobile: ");
    scanf("%d", &n);

}