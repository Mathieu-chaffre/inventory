#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Marchandise_a_vendre{
  char nom[8];
  int nombre;
  int prix;
  int inventaire;
};

typedef struct Marchandise_a_vendre marchandise_a_vendre;
marchandise_a_vendre viande = {"viande", 0,5,0};
marchandise_a_vendre epee = {"epee", 0,10,0};
marchandise_a_vendre fleches = {"fleches",0,2,0};
marchandise_a_vendre poison = {"poison",10,30,0};
marchandise_a_vendre produit = {"",0,0,0};


int demande;
int nombre;
int piece = 500;
int choix_joueur = 1;
int ajout=1;
int fin =1;

void random(){
  srand(time(NULL));
  viande.nombre =rand()%10+1;
  srand(time(NULL));
  epee.nombre =rand()%5+1;
  srand(time(NULL));
  fleches.nombre =rand()%50+1;
};



void achat( marchandise_a_vendre* marchandise, marchandise_a_vendre test) {
  if (test.nombre < nombre) {
    printf("Le marchands n'a pas assez de %s!\n", test.nom);
  }
  if (piece <= (test.prix*nombre)) {
    printf("Tu n'as pas assez d'argent\n");
  }
  if(test.nombre >= nombre && piece >= (test.prix*nombre)){
    printf("tu as achete %d %s\n", nombre, test.nom);
    marchandise->nombre = marchandise->nombre - nombre;
    printf("%d\n", test.nombre);
    marchandise->inventaire = marchandise->inventaire + nombre;
    piece = piece - (marchandise->prix*nombre);
  }
};


int main(){
  random();
  while (fin == 1) {
    if (ajout == 1) {
      printf("Que veux tu acheter au marchands ? Il lui reste %d %s au prix de %d pieces , %d %s au prix de %d pieces, %d %s au prix de %d pieces, %d %s au prix de %d pieces.\n", viande.nombre, viande.nom,viande.prix, epee.nombre, epee.nom,epee.prix, fleches.nombre, fleches.nom, fleches.prix, poison.nombre, poison.nom,poison.prix  );
    }
    else if(ajout == 2){
      printf("Que veux tu acheter au marchands ? Il lui reste %d %s au prix de %d pieces , %d %s au prix de %d pieces, %d %s au prix de %d pieces, %d %s au prix de %d pieces, %d %s au prix de %d pieces.\n", viande.nombre, viande.nom,viande.prix, epee.nombre, epee.nom,epee.prix, fleches.nombre, fleches.nom, fleches.prix, poison.nombre, poison.nom,poison.prix, produit.nombre, produit.nom, produit.prix );
    }
    scanf("%d", &demande);
    if (demande == 1) {
      printf("tu prends de la viande tu en veux combien ?\n");
      scanf("%d", &nombre );
      achat(&viande, viande);
      printf("Tu veux continuer d'acheter ? 1 oui et 2 non\n");
      scanf("%d", &choix_joueur );
    }
    if (demande == 2) {
      printf("tu prends des epees tu en veux combien ?\n");
      scanf("%d", &nombre );
      achat(&epee, epee);
      printf("Tu veux continuer d'acheter ? 1 oui et 2 non\n");
      scanf("%d", &choix_joueur );
    }
    if (demande == 3) {
      printf("tu prends des fleches tu en veux combien ?\n");
      scanf("%d", &nombre );
      achat(&fleches, fleches);
      printf("Tu veux continuer d'acheter ? 1 oui et 2 non\n");
      scanf("%d", &choix_joueur );
    }
    if (demande == 4) {
      printf("tu prends du poison tu en veux combien ?\n");
      scanf("%d", &nombre );
      achat(&poison, poison);
      printf("Tu veux continuer d'acheter ? 1 oui et 2 non\n");
      scanf("%d",&choix_joueur );
    }
    if (choix_joueur == 2) {
      printf("Tu possede: \n - %d %s \n -%d %s \n -%d %s \n - %d %s \n ",viande.inventaire, viande.nom, fleches.inventaire, fleches.nom, poison.inventaire, poison.nom, epee.inventaire, epee.nom );
      scanf("%d",&choix_joueur );

    }
    if (choix_joueur == 3) {
      ajout = 2;
      printf("Tu peux creer un objet\n");
      char nom_objet[40] = "";
      printf("donne le nom de l'objet ?\n");
      scanf("%s", nom_objet);
      strcpy(produit.nom, nom_objet);
      printf("Tu veux quel nombre que possedera le vendeur ?\n");
      scanf("%d", &nombre);
      produit.nombre = nombre;
      printf("Le prix ?\n");
      scanf("%d", &nombre );
      produit.prix = nombre;
      scanf("%d", &choix_joueur );
    }
    if (viande.nombre == 0 && epee.nombre == 0 && fleches.nombre==0 && poison.nombre == 0 && produit.nombre ==0) {
      fin == 0;
    }
  }





  return 0;
}
