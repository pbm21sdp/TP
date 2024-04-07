#include <stdio.h>
#include <math.h>
typedef struct{
  int id, salariu;
  char *nume, *ocupatie;
}angajat;

typedef enum{
	     tip_A,
	     tip_B
}Tip_restaurant;

typedef struct{
  char *nume_restaurant;
  angajat *angajati;
  Tip_restaurant tr;
  union{
    struct{
      int *Nr_telefon;
      int indice_piata;
      float rating;
    }Tip_A;
    struct{
      char *adresa_geografica;
      float analiza_marketing;
      float coeficient_de_reputatie;
    }Tip_B;
  }Tip;
}Restaurant;

typedef struct{
Restaurant *restaurante;
}Corporatie;
  
int Restaurant_indice_performanta(Corporatie *A, int Nr_restaurante)
{
  int Ind_P = 0, max = -1;
  for(int i = 0; i < Nr_restaurante ; i++)
    {
      Ind_P = 0;
      switch(A->restaurante[0].tr)
	{
           case tip_A:
		     {
		       Ind_P = A->restaurante[0].Tip.Tip_A.indice_piata * A->restaurante[0].Tip.Tip_A.rating;
		       break;
		     }
	case tip_B:
	  {
	      Ind_P = (A->restaurante[0].Tip.Tip_B.analiza_marketing * A->restaurante[0].Tip.Tip_B.coeficient_de_reputatie);  //Eroare cand pun sqrt ?
	      break;
	  }
}
      if ( Ind_P > max)
	max = Ind_P;
    }
  return max;		    
}
  

int main()
{
  return 0;
}