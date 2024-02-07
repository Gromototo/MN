#include <stdio.h>
#include <stdlib.h>

#include "abr.h"
#include "pile.h"
#include "file.h"
#include <stdbool.h>
#include <math.h>

#define max(a,b) ((a)>(b)?(a):(b))


int feuille (Arbre_t a)
{
  if (a == NULL)
    return 0 ;
  else
    {
      if ((a->fgauche == NULL) && (a->fdroite == NULL))
	return 1 ;
      else
	return 0 ;
    }
}

Arbre_t ajouter_noeud (Arbre_t a, Arbre_t n)
{
  /* ajouter le noeud n dans l'arbre a */
  
  if (a == NULL)
    return n ;
  else if (n->cle < a->cle)
	a->fgauche = ajouter_noeud (a->fgauche, n) ;
  else
	a->fdroite = ajouter_noeud (a->fdroite, n) ;
  return a ;
  
}  

Arbre_t rechercher_cle_arbre (Arbre_t a, int valeur)
{
  if (a == NULL)
    return NULL ;
  else
    {
      if (a->cle == valeur)
	return a ;
      else
	{
	  if (a->cle < valeur)
	    return rechercher_cle_arbre (a->fdroite, valeur) ;
	  else
	    return rechercher_cle_arbre (a->fgauche, valeur) ;
	}
    }
}

Arbre_t ajouter_cle (Arbre_t a, int cle)
{
  Arbre_t n ;
  Arbre_t ptrouve ;
  
  /* 
     ajout de la clé. Creation du noeud n qu'on insere 
    dans l'arbre a
  */

  ptrouve = rechercher_cle_arbre (a, cle) ;

  if (ptrouve == NULL)
    {
      n = (Arbre_t) malloc (sizeof(noeud_t)) ;
      n->cle = cle;
      n->fgauche = NULL ;
      n->fdroite = NULL ;

      a = ajouter_noeud (a, n) ;
      return a ;
    }
  else
    return a ;
}


Arbre_t lire_arbre (char *nom_fichier)
{
  FILE *f ;
  int cle;
  Arbre_t a = NULL;
  
  f = fopen (nom_fichier, "r") ;

  while (fscanf (f, "%d", &cle) != EOF)
    {
      a = ajouter_cle (a, cle) ;
    }
    
  fclose (f) ;

  return a ;
}

void afficher_arbre (Arbre_t a, int niveau)
{
  /*
    affichage de l'arbre a
    on l'affiche en le penchant sur sa gauche
    la partie droite (haute) se retrouve en l'air
  */
  
  int i ;
  
  if (a != NULL)
      {
	afficher_arbre (a->fdroite,niveau+1) ;
	
	for (i = 0; i < niveau; i++)
	  printf ("\t") ;
	printf (" %d (%d)\n\n", a->cle, niveau) ;

	afficher_arbre (a->fgauche, niveau+1) ;
      }
  return ;
}


int hauteur_arbre_r (Arbre_t a)
{
  if (feuille(a)) {
    return 0;
  }
  
  int lcounter = 0;
  if (a->fgauche != NULL) {
    lcounter = hauteur_arbre_r(a->fgauche);
  }

  int rcounter = 0;
  if (a->fdroite!= NULL) {
    rcounter = hauteur_arbre_r(a->fdroite);
  } 
  return 1 + max(lcounter, rcounter);
}

int hauteur_arbre_nr (Arbre_t a)
{

  int hauteur=-1;
  
  pfile_t file = creer_file();

  if (a == NULL) {
    return -1;
  }
  
  enfiler(file, a);
  
  while (!file_vide(file)) {
    pfile_t n_file = creer_file();

    hauteur++;

    while(!file_vide(file)) {

      pnoeud_t noeud  = defiler(file);
      if (noeud->fgauche != NULL) {
        enfiler(n_file, noeud->fgauche);
      }

      if (noeud->fdroite != NULL) {
        enfiler(n_file, noeud->fdroite);
      }


    }
    file = n_file;
  }
  
  return hauteur;
}


void parcourir_arbre_largeur (Arbre_t a)
{
  pfile_t file = creer_file();
  

  if (a == NULL) {
    return ;
  }
  
  enfiler(file, a);
  
  while (!file_vide(file)) {
    pfile_t n_file = creer_file();

    while(!file_vide(file)) {
    
      pnoeud_t noeud  = defiler(file);

      if (noeud->fgauche != NULL) {
        enfiler(n_file, noeud->fgauche);
      }

      if (noeud->fdroite != NULL) {
        enfiler(n_file, noeud->fdroite);
      }


      printf("%d \n", (int) noeud->cle);
    }
    file = n_file;
  }
  
  return ;
}

void afficher_nombre_noeuds_par_niveau (Arbre_t a)
{

  int nb_noeud = 0;
  int num_niveau = 0;
  pfile_t file = creer_file();
  


  if (a == NULL) {
    printf("Arbre null dans afficher_nombre_noeuds_par_niveau !\n");
    return ;
  }
  
  enfiler(file, a);
  
  while (!file_vide(file)) {
    pfile_t n_file = creer_file();

    while(!file_vide(file)) {
    
      pnoeud_t noeud  = defiler(file);
      nb_noeud++;

      if (noeud->fgauche != NULL) {
        enfiler(n_file, noeud->fgauche);
      }

      if (noeud->fdroite != NULL) {
        enfiler(n_file, noeud->fdroite);
      }
    }
    printf("Au niveau %d, il y a %d noeuds\n",num_niveau,nb_noeud);
    nb_noeud=0;
    num_niveau++;
    file = n_file;
  }
  
  return ;
}


int nombre_cles_arbre_r (Arbre_t a)
{

  if (a==NULL){
    return 0;
  }

  if (feuille(a)){
    return 1;
  }

  return ( 1 + nombre_cles_arbre_r(a->fdroite) + nombre_cles_arbre_r (a->fgauche));
}

int nombre_cles_arbre_nr (Arbre_t a)
{
  int nb_cle=0;
  
  pfile_t file = creer_file();
  pfile_t n_file = creer_file();
  
  enfiler(file, a);
  
  while (!file_vide(file)) {
    while(!file_vide(file)) {
      nb_cle++;
      pnoeud_t noeud  = defiler(file);

      if (noeud->fgauche != NULL) {
        enfiler(n_file, noeud->fgauche);
      }

      if (noeud->fdroite != NULL) {
        enfiler(n_file, noeud->fdroite);
      }

    }
    file = n_file;
  }
  
  return nb_cle;
}

int trouver_cle_min (Arbre_t a)
{
  int min = 0;
  if (a == NULL){
    return min;
  }
  while (a-> fgauche != NULL){
    a = a->fgauche;
  }
  min = a->cle;
  return min ;
}

 

void imprimer_liste_cle_triee_r (Arbre_t a)
{
  
  if (feuille(a)) {
    printf("%d\n", a->cle);
    return;}
  
  if (a->fgauche != NULL) {
    imprimer_liste_cle_triee_r(a->fgauche);
  }

  printf("%d\n", a->cle);
  
  if (a->fdroite!= NULL) {
    imprimer_liste_cle_triee_r(a->fdroite);
  } 

  return;
}

void imprimer_liste_cle_triee_nr (Arbre_t a)
{

  
  pfile_t file = creer_file();

  enfiler(file, a);

  while(!file_vide(file)) {
    pfile_t n_file = creer_file();
    bool found_arbre = false;

    while(!file_vide(file)){
      
      noeud_t* noeud  = defiler(file);

      if(feuille(noeud) && !found_arbre){
        printf("%d\n", noeud->cle);
      }
      else {

        if(noeud->fgauche != NULL){
          enfiler(n_file, noeud->fgauche);
        }
        
        pnoeud_t feuille_noeud;
        feuille_noeud->cle = noeud->cle;
        enfiler(n_file, feuille_noeud);


        if(noeud->fdroite != NULL){
          enfiler(n_file, noeud->fdroite);
        }

        found_arbre = true;
      }

    }

    file = n_file;
  }


}


int arbre_plein (Arbre_t a)
{
  if (a == NULL){
    return 0;
  }

  int h = hauteur_arbre_r(a);
  int nb_noeud = nombre_cles_arbre_r(a);

  return nb_noeud == (pow(2,h+1)-1);
}

int check_parfait(pfile_t file,pfile_t n_file, pnoeud_t noeud){
  while(!file_vide(file)){
    pnoeud_t n_noeud  = defiler(file);
    if (n_noeud->fgauche==NULL || n_noeud->fdroite==NULL){
      return 0;
    }
  }
  file = n_file;
  while(!file_vide(file)){
    pnoeud_t n_noeud  = defiler(file);
    if (!feuille(n_noeud)){
      return 0;
    }
  }
  return 1;
}

int arbre_parfait (Arbre_t a)
{
  pfile_t file = creer_file();
  

  if (a == NULL) {
    return 0;
  }
  
  enfiler(file, a);
  
  while (!file_vide(file)) {
    pfile_t n_file = creer_file();

    while(!file_vide(file)) {
    
      pnoeud_t noeud  = defiler(file);
      if (noeud->fgauche==NULL || noeud->fdroite==NULL){
        if (noeud->fgauche==NULL && noeud->fdroite!=NULL){
          return 0;
        }
        return check_parfait(file,n_file,noeud);
      }

      if (noeud->fgauche != NULL) {
        enfiler(n_file, noeud->fgauche);
      }

      if (noeud->fdroite != NULL) {
        enfiler(n_file, noeud->fdroite);
      }


      printf("%d \n", (int) noeud->cle);
    }
    /*fin de niveau*/
    file = n_file;
  }
  
  printf("Ce cas n'est pas censé arriver !\n");
  return 0;
}




Arbre_t rechercher_cle_sup_arbre (Arbre_t a, int valeur)
{
  /*
    a completer
  */

  return NULL ;
  
}

Arbre_t rechercher_cle_inf_arbre (Arbre_t a, int valeur)
{
  /*
    a completer
  */

  return NULL ;
  
}


Arbre_t detruire_cle_arbre (Arbre_t a, int cle)
{
  /*
    a completer
  */

  return NULL ;
}



Arbre_t intersection_deux_arbres (Arbre_t a1, Arbre_t a2)
{
  /*
    a completer
  */

  return NULL ;
  
}

Arbre_t union_deux_arbres (Arbre_t a1, Arbre_t a2)
{
  /*
    a completer
  */

  return NULL ;
}

