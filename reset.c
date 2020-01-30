#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int compteur = 2;
int loop=1;
int demande = 0;
int  tableau= 0;
int test_alphabet;


struct Objet{
  int classement;
  char nom[50];
  int nombre;
  int prix;
  int inventaire;
};

typedef struct Objet objet;




void alphabet(objet * marchandise_1 , objet * marchandise_2 ){
  int save;
  char save_nom[40];
  test_alphabet = strncmp( &marchandise_1.nom, &marchandise_2.nom, 20);
  if (test_alphabet > 0) {
    save = &marchandise_2.nombre;
    &marchandise_2->nombre = marchandise_1.nombre;
    &marchandise_1->nombre = save;
    strcpy(save_nom, &marchandise_2.nom);
    strcpy(&marchandise_2.nom, &marchandise_1.nom);
    strcpy(&marchandise_1,save_nom);
    save = &marchandise_2.inventaire;
    &marchandise_2.inventaire = &marchandise_1.inventaire;
    &marchandise_1.inventaire = save;
    save = marchandise_2.prix;
    &marchandise_2.prix = &marchandise_1.prix;
    &marchandise_1.prix = save;


    tableau = 0;

  }
  else{
    tableau =1;
  }

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
          while (tableau == 0) {
            for (i = 1; i <= compteur; i++) {
              alphabet(&tableau[i], &tableau[i+1]);

              printf("%s : \n %d\n %d $", tableau[i].nom, tableau[i].nombre , tableau[i].prix );
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
