#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Marchandise_a_vendre{
  char nom[8];
  int nombre;
  int prix;
};

struct Inventaire{
  char nom;
  int nombre;
};
typedef struct Inventaire inventaire;
typedef struct Marchandise_a_vendre marchandise_a_vendre;
marchandise_a_vendre viande = {"viande", 0,5};
marchandise_a_vendre epee = {"epee", 0,10};
marchandise_a_vendre fleches = {"fleches",0,2};
marchandise_a_vendre poison = {"poison",10,30};


int demande;
int nombre;
int argent = 500;

void random(){
  srand(time(NULL));
  viande.nombre =rand()%10+1;
  srand(time(NULL));
  epee.nombre =rand()%5+1;
  srand(time(NULL));
  fleches.nombre =rand()%50+1;
}


int main(){
  random();
  printf("Que veux tu acheter au marchands ? Il lui reste %d %s au prix de %d pieces , %d %s au prix de %d pieces, %d %s au prix de %d pieces, %d %s au prix de %d pieces. \n", viande.nombre, viande.nom,viande.prix, epee.nombre, epee.nom,epee.prix, fleches.nombre, fleches.nom, fleches.prix, poison.nombre, poison.nom,poison.prix );
  scanf("%d\n", demande);
  if (demande == 1) {
    scanf("%d\n", nombre);
    viande.nombre = viande.nombre - nombre;
    printf("Tu achetes %d morceau de viande\n", nombre);
    argent = argent - viande.prix;
    printf("Il te reste que %d pieces\n", argent);
  }
  if (demande == 2) {
    scanf("%d\n", nombre);
    epee.nombre = epee.nombre - nombre;
    printf("Tu achetes %d epees\n", nombre);
    argent = argent - epee.prix;
    printf("Il te reste que %d pieces\n", argent);
  }
  if (demande == 3) {
    scanf("%d\n", nombre );
    fleches.nombre = fleches.nombre - nombre;
    printf("Tu achete %d fleches\n", nombre);
    argent = argent - fleches.prix;
    printf("Il te reste que %d pieces\n", argent);
  }
  return 0;
}
