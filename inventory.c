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

maFonction(inventaire monItem){
  monItem.nombre;
}

int demande;
int nombre;
int argent = 500;
int achat=1;

void random(){
  srand(time(NULL));
  viande.nombre =rand()%100+1;
  srand(time(NULL));
  epee.nombre =rand()%30+1;
  srand(time(NULL));
  fleches.nombre =rand()%50+1;
}


int main(){
  random();
  while (achat ==1) {
  printf("Que veux tu acheter au marchands ? Il lui reste %d %s au prix de %d pieces , %d %s au prix de %d pieces, %d %s au prix de %d pieces, %d %s au prix de %d pieces. \n", viande.nombre, viande.nom,viande.prix, epee.nombre, epee.nom,epee.prix, fleches.nombre, fleches.nom, fleches.prix, poison.nombre, poison.nom,poison.prix );
  scanf("%d", &demande);
  if (demande == 1) {
    printf("Tu veux en acheter combien ?\n");
    scanf("%d", &nombre);
    if (nombre > viande.nombre) {
      printf("Le marchand n'en a pas autant\n");
    }
    else{
    viande.nombre = viande.nombre - nombre;
    printf("Tu achetes %d morceau de viande\n", nombre);
    argent = argent - (viande.prix*nombre);
    printf("Il te reste que %d pieces\n", argent);
  }
}
  if (demande == 2) {
    printf("Tu veux en acheter combien ?\n");
    scanf("%d", &nombre);
    if (nombre > epee.nombre) {
      printf("Tu ne peux pas il n'en a pas assez !\n", );
    }
    else{
    epee.nombre = epee.nombre - nombre;
    printf("Tu achetes %d epees\n", nombre);
    argent = argent - (epee.prix*nombre);
    printf("Il te reste que %d pieces\n", argent);
    }
  }
  if (demande == 3) {
    printf("Tu veux en acheter combien ?\n");
    scanf("%d", &nombre );
    if (nombre > fleches.nombre) {
      printf("Tu ne peux pas il n'en a pas assé\n");
    }
    else{
    fleches.nombre = fleches.nombre - nombre;
    printf("Tu achete %d fleches\n", nombre);
    argent = argent - (fleches.prix*nombre);
    printf("Il te reste que %d pieces\n", argent);
  }
  }
  if (demande == 4) {
    printf("Tu veux en acheter combien ?\n");
    scanf("%d", nombre);
    poison.nombre = poison.nombre - nombre;
    printf("Tu as donc acheter %d poisons\n",nombre );
    argent = argent - (poison.prix*nombre);
  }
  if (argent <=0) {
    achat = 0;
  }
}
  return 0;
}
