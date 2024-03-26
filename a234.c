#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "a234.h"

#define max(a,b) ((a)>(b)?(a):(b))


int hauteur (Arbre234 a)
{
  int h0, h1, h2, h3 ;
  
  if (a == NULL)
    return 0 ;

  if (a->t == 0)
    return 0 ;

  h0 = hauteur (a->fils [0]) ;
  h1 = hauteur (a->fils [1]) ;
  h2 = hauteur (a->fils [2]) ;
  h3 = hauteur (a->fils [3]) ;

  return 1 + max (max (h0,h1),max (h2,h3)) ;
} 

int NombreCles (Arbre234 a)
{
  int counter = 0;

  if (a->t==0 || a == NULL){
    return 0;
  }
  else{
    counter += a->t -1;
  }

  if (a->t == 0){
  }
  else if (a->t == 2){
    counter += NombreCles(a->fils[1]);
    counter += NombreCles(a->fils[2]);
    

  }
  else if (a->t == 3){

    counter += NombreCles(a->fils[0]);
    counter += NombreCles(a->fils[1]);
    counter += NombreCles(a->fils[2]);


  }
  else if (a->t == 4){

    counter += NombreCles(a->fils[0]);
    counter += NombreCles(a->fils[1]);
    counter += NombreCles(a->fils[2]);
    counter += NombreCles(a->fils[3]);


  }

  
  return counter;
}

int LastFilsIndex(int nodetype) {
  switch (nodetype) {
      case 2:
          return 2;
      default :
        return nodetype-1;
  };
};

Arbre234 noeud_max (Arbre234 a)
{
  Arbre234 node_parcours = a;  

  if (a==NULL){
    return a;
  }

  while (node_parcours->fils[LastFilsIndex(node_parcours->t)]->t != 0){
        node_parcours = node_parcours->fils[LastFilsIndex(node_parcours->t)];
  }


  return node_parcours;
}



int CleMax (Arbre234 a)
{
  int max;
  Arbre234 node_parcours = noeud_max(a);




  switch ( node_parcours->t )
  {
      case 2:
        max = node_parcours->cles[1];
        break;
      case 3:
        max = node_parcours->cles[1];
        break;
      case 4:
        max = node_parcours->cles[2];
        break;
  }


  return max;
}

int FirstFilsIndex(int nodetype) {
  switch (nodetype) {
      case 2:
          return 1;
      default :
        return 0;
  };
};

int CleMin (Arbre234 a)
{
   Arbre234 node_parcours = a;  

  if (a==NULL){
    return -1;
  }

  int min =-1;

  if (node_parcours->t==0){
    printf("l'arbre est seulement une feuille !\n");
    exit(-1);
  }
  else{
    min = node_parcours->cles[node_parcours->t-1];
  }

  while (node_parcours->fils[FirstFilsIndex(node_parcours->t)]->t != 0){
      node_parcours = node_parcours->fils[FirstFilsIndex(node_parcours->t)];
  }


  if (node_parcours->t == 2){
    min = node_parcours->cles[1];
  }
  else {
    min = node_parcours->cles[0];

  }

  return min;
}

Arbre234 RechercherCle (Arbre234 a, int cle)
{
  noeud234 node_parcours = *a;  

  if (a==NULL){
    return NULL;
  }
  if (node_parcours.t==0){
    printf("l'arbre est seulement une feuille !\n");
    exit(-1);
  }
  while(node_parcours.t!=0){
    for (int i=0; i<node_parcours.t-1; i++){
      if(node_parcours.cles[i]==cle){
        return &node_parcours;
      }
      if (cle<node_parcours.cles[i]){
        node_parcours=*node_parcours.fils[i];
        break;
      }
    }
    node_parcours=*node_parcours.fils[node_parcours.t-1];
  }
  return NULL;
}

void AnalyseStructureArbre (Arbre234 a, int *feuilles, int *noeud2, int *noeud3, int *noeud4)
{
  switch (a->t) {
    case 0 :
      *feuilles += 1;

      break;
    case 2 :
      *noeud2 += 1;

      AnalyseStructureArbre(a->fils[1], feuilles, noeud2, noeud3, noeud4);
      AnalyseStructureArbre(a->fils[2], feuilles, noeud2, noeud3, noeud4);

      break;
    case 3 :
      *noeud3 += 1;

      AnalyseStructureArbre(a->fils[0], feuilles, noeud2, noeud3, noeud4);
      AnalyseStructureArbre(a->fils[1], feuilles, noeud2, noeud3, noeud4);
      AnalyseStructureArbre(a->fils[2], feuilles, noeud2, noeud3, noeud4);

      break;
    case 4 :
      *noeud4 += 1;

      AnalyseStructureArbre(a->fils[0], feuilles, noeud2, noeud3, noeud4);
      AnalyseStructureArbre(a->fils[1], feuilles, noeud2, noeud3, noeud4);
      AnalyseStructureArbre(a->fils[2], feuilles, noeud2, noeud3, noeud4);
      AnalyseStructureArbre(a->fils[3], feuilles, noeud2, noeud3, noeud4);


      break;
  }
}




void Afficher_Cles_Largeur (Arbre234 a)
{
  /* 
     Afficher les cles en ordre croissant
     Cette fonction sera recursive
  */

  if (a == NULL){
    return;
  }

  switch (a->t) {

    case 2 :
      printf("%d, ", a->cles[1]);
      Affichage_Cles_Triees_Recursive(a->fils[1]);
      Affichage_Cles_Triees_Recursive(a->fils[2]);
      break;

    case 3 :

      Affichage_Cles_Triees_Recursive(a->fils[0]);
      printf("%d, ", a->cles[0]);
      Affichage_Cles_Triees_Recursive(a->fils[1]);
      printf("%d, ", a->cles[1]);
      Affichage_Cles_Triees_Recursive(a->fils[2]);
      break;

    case 4 :
      Affichage_Cles_Triees_Recursive(a->fils[0]);
      printf("%d, ", a->cles[0]);
      Affichage_Cles_Triees_Recursive(a->fils[1]);
      printf("%d, ", a->cles[1]);
      Affichage_Cles_Triees_Recursive(a->fils[2]);
      printf("%d, ", a->cles[2]);
      Affichage_Cles_Triees_Recursive(a->fils[3]);
      break;

  }

  return;



  return ;
}

void Affichage_Cles_Triees_Recursive (Arbre234 a)
{
  /* 
     Afficher les cles en ordre croissant
     Cette fonction sera recursive
  */

  if (a == NULL){
    return;
  }

  switch (a->t) {

    case 2 :
      Affichage_Cles_Triees_Recursive(a->fils[1]);
      printf("%d, ", a->cles[1]);
      Affichage_Cles_Triees_Recursive(a->fils[2]);
      break;

    case 3 :

      Affichage_Cles_Triees_Recursive(a->fils[0]);
      printf("%d, ", a->cles[0]);
      Affichage_Cles_Triees_Recursive(a->fils[1]);
      printf("%d, ", a->cles[1]);
      Affichage_Cles_Triees_Recursive(a->fils[2]);
      break;

    case 4 :
      Affichage_Cles_Triees_Recursive(a->fils[0]);
      printf("%d, ", a->cles[0]);
      Affichage_Cles_Triees_Recursive(a->fils[1]);
      printf("%d, ", a->cles[1]);
      Affichage_Cles_Triees_Recursive(a->fils[2]);
      printf("%d, ", a->cles[2]);
      Affichage_Cles_Triees_Recursive(a->fils[3]);
      break;

  }

  return;
     
}

void Affichage_Cles_Triees_NonRecursive (Arbre234 a)
{
    /* 
     Afficher les cles en ordre croissant
     Cette fonction ne sera pas recursive
     Utiliser une pile
  */

}


void Detruire_Cle (Arbre234 *a, int cle)
{
  /*
    retirer la cle de l'arbre a
  */

  return ;
}




int main (int argc, char **argv)
{
  Arbre234 a ;

  if (argc != 2)
    {
      fprintf (stderr, "il manque le parametre nom de fichier\n") ;
      exit (-1) ;
    }

  a = lire_arbre (argv [1]) ;

  printf ("==== Afficher arbre ====\n") ;
  
  afficher_arbre (a, 0) ;

  printf ("==== Nombre Cles ====\n") ;

  printf("%d \n", NombreCles(a));

  printf ("==== Cles MAX MIN ====\n") ;

  printf("Cle max : %d\n", CleMax(a));

  printf("Cle min : %d\n", CleMin(a));

  
  printf ("==== Noeud Max ====\n") ;

  printf("Noeud max : \n");
  Arbre234 nm = noeud_max(a);
  for (int cle = 0; cle<3; cle++){
    printf("      %d\n", nm->cles[cle]);
  }

  printf ("==== Afficahge Clefs Triées ====\n") ;

  Affichage_Cles_Triees_Recursive(a);
  printf("\n");

  printf ("==== Afficahge Analyse Arbre ====\n") ;

  int feuilles = 0;
  int noeud2 = 0;
  int noeud3 = 0;
  int noeud4 = 0;
  AnalyseStructureArbre(a, &feuilles, &noeud2,  &noeud3,  &noeud4);
  printf("Feuilles : %d\n", feuilles);
  printf("Noeud 2 : %d\n", noeud2);
  printf("Noeud 3 : %d\n", noeud3);
  printf("Noeud 4 : %d\n", noeud4);

  printf ("==== Recherche Cle ====\n") ;

  int CLEF = 30;
  printf("Noeud trouvé : \n");
  printf("      %d\n", RechercherCle(a, CLEF)->cles[0]);
  printf("      %d\n", RechercherCle(a, CLEF)->cles[1]);
  printf("      %d\n", RechercherCle(a, CLEF)->cles[2]);



}
