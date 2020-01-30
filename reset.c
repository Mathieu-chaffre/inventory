#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int compteur = 2;
int loop=1;
int demande = 0;
int loop_demande = 0;


struct Objet{
  int classement;
  char nom[20];
  int nombre;
  int prix;
  int inventaire;
};

typedef struct Objet objet;




void alphabet(int * ){
  
}



int main(){


  objet tableau[109];
  tableau[0].classement = 1;
  strcpy(tableau[0].nom, "fleches");
  srand(time(NULL));
  tableau[0].nombre =rand()%80+1;
  tableau[0].prix = 10;
  tableau[0].inventaire = 0;

  tableau[1].classement = 1;
  strcpy(tableau[1].nom, "epee");
  srand(time(NULL));
  tableau[1].nombre =rand()%10+1;
  tableau[1].prix = 10;
  tableau[1].inventaire = 0;

  while (fin == 1) {
    printf("Que veux tu faire /1 inventaire /2 magasin /3 création ?\n");
    scanf("%d", &demande );
    switch (demande) {
      case 1:
        printf("Tu rentre dans l'inventaire\n");
      break;
      case 2:
        printf("Tu rentre dans le magasin de Chelsea.\n");
          while (loop_demande == 0) {
            for (i = 0; i <= compteur; i++) {
              alphabet(&tableau[i], &tableau[i+1]);
            }
          }
      break;
      case 3:
        printf("tu va créer un objet chez le shop Chelsea\n");
      break;
    }
  }

printf("test : %s \n", tableau[0].nom );
  return 0;
}
