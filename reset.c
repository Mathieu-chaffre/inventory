#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int compteur = 2;
int loop=1;
int demande = 0;
int  loop_2= 0;
int fin =1;
int piece = 5000;
int choix_joueur;
int nombre;
int demande_2;
char nom_objet[40];



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
  int test_alphabet;
  test_alphabet = strncmp( (*marchandise_1).nom, (*marchandise_2).nom, 20);
  if (test_alphabet > 0) {
    save = (*marchandise_2).nombre;
    (*marchandise_2).nombre = (*marchandise_1).nombre;
    (*marchandise_1).nombre = save;


    strcpy(save_nom, (*marchandise_2).nom);
    strcpy((*marchandise_2).nom, (*marchandise_1).nom);
    strcpy((*marchandise_1).nom,save_nom);

    save = (*marchandise_2).inventaire;
    (*marchandise_2).inventaire = (*marchandise_1).inventaire;
    (*marchandise_1).inventaire = save;

    save = (*marchandise_2).prix;
    (*marchandise_2).prix = (*marchandise_1).prix;
    (*marchandise_1).prix = save;




    loop_2 = 0;

  }
  else{
    loop_2 = 1;
  }

}



int main(){


  objet tableau[109];
  tableau[0].classement = 1;
  strcpy(tableau[0].nom, "fleches");
  tableau[0].nombre = 10;
  tableau[0].prix = 10;
  tableau[0].inventaire = 0;

  tableau[1].classement = 2;
  strcpy(tableau[1].nom, "epee");
  tableau[1].nombre =20;
  tableau[1].prix = 40;
  tableau[1].inventaire = 0;


  while (fin == 1) {
    printf("Que veux tu faire /1 inventaire /2 magasin /3 creation ?\n");
    scanf("%d", &demande );
    switch (demande) {
      case 1:
        printf("Tu rentre dans l'inventaire\n");
        while (loop_2 == 0) {
            for ( int i = 0; i < compteur-1; i++) {
              alphabet(&tableau[i], &tableau[i+1]);
            }
          }
          for(int i = 0; i < compteur; i++){
            printf("[%d] %s :  tu en as %d\n",tableau[i].classement, tableau[i].nom, tableau[i].inventaire );
          }
      break;
      case 2:
        printf("Tu rentre dans le magasin de Chelsea.\n");
          while (loop_2 == 0) {
            for ( int i = 0; i < compteur-1; i++) {
              alphabet(&tableau[i], &tableau[i+1]);
            }
          }
          for(int i = 0; i < compteur; i++){
            printf("[%d] %s :  il en a %d  a %d $\n",tableau[i].classement, tableau[i].nom, tableau[i].nombre , tableau[i].prix );
          }

            printf("Tu veux quoi ?\n");
            scanf("%d", &demande_2);
            demande_2 -=1;
            printf("Tu en veux combien ?\n");
            scanf("%d", &nombre);
            if(nombre <= tableau[demande_2].nombre && piece > (tableau[demande_2].prix*nombre)){
              printf("tu choisi %s\n", tableau[demande_2].nom);
            tableau[demande_2].inventaire += nombre;
            tableau[demande_2].nombre -= nombre;
            piece -= tableau[demande_2].prix*nombre;
            printf("Tu as achete %d %s au prix de %d\n", nombre, tableau[demande_2].nom, (tableau[demande_2].prix*nombre) );
            }
            else if(piece < (tableau[demande_2].prix*nombre) ){
              printf("Tu n'as pas assez d'argent\n");
            }
            else if(nombre > tableau[demande_2].nombre){
              printf("Le vendeur n'a pas tout ça !\n");
            }



      break;
      case 3:
        printf("tu va creer un objet chez le shop Chelsea\n");

        compteur +=1;
        int compteur_2 = compteur-1;
        tableau[compteur_2].classement = compteur_2+1;
        printf("Donne un nom au nouvel objet.\n");
        scanf("%s", &nom_objet[40]);
        printf("%s", nom_objet);
        strcpy(tableau[compteur_2].nom, nom_objet);
        printf("Combien d'exemplaire ?\n");
        scanf("%d", &nombre);
        tableau[compteur_2].nombre = nombre;
        printf("Quel prix ?\n");
        scanf("%d", &nombre);
        tableau[compteur_2].prix = nombre;

      break;
      case 4:
      fin = 0;
      break;
    }
  }

printf("test : %s \n", tableau[0].nom );
  return 0;
}
