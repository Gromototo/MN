/*
  Structures de type graphe
  Structures de donnees de type liste
  (Pas de contrainte sur le nombre de noeuds des  graphes)
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "file.h"
#include "pile.h"

#include <stdbool.h>



bool deja_visite(int s_label, int* visites, int last_label_index) {

  for (int i = 0; i <= last_label_index; i++){

    int label = visites[i];

    if(s_label == label){
      return true;
    }
  }
  
  return false;
}

int visiter(int label, int* visites, int last_label_index) {
    
  if (!deja_visite(label, visites, last_label_index)){
    visites[last_label_index+1] = label;
    last_label_index ++;
  }

  return last_label_index;
}


psommet_t chercher_sommet (pgraphe_t g, int label)
{
  psommet_t s ;

  s = g ;

  while ((s!= NULL) && (s->label != label))
    {
      s = s->sommet_suivant ;
    }
  return s ;
}

parc_t existence_arc (parc_t l, psommet_t s)
{
  parc_t p = l ;

  while (p != NULL)
    {
      if (p->dest == s)
	return p ;
      p = p->arc_suivant ;
    }
  return p ;
  
}


void ajouter_arc (psommet_t o, psommet_t d, int distance)
{
  parc_t parc ;

  parc = (parc_t) malloc (sizeof(arc_t)) ;

  if (existence_arc (o->liste_arcs, d) != NULL)
    {
      fprintf(stderr, "ajout d'un arc deja existant\n") ;
      exit (-1) ;
    }
  
  parc->poids = distance ;
  parc->dest = d ;
  parc->arc_suivant = o->liste_arcs ;
  o->liste_arcs = parc ;
  return ;
}



// ===================================================================

int nombre_sommets (pgraphe_t g)
{
  psommet_t p = g ;
  int nb = 0 ;

  while (p != NULL)
    {
      nb = nb + 1 ;
      p = p->sommet_suivant ;
    }

  return nb ;
}

int nombre_arcs (pgraphe_t g)
{

  psommet_t p = g ;
  int nb_arcs = 0 ;

  while (p != NULL)
    {
      parc_t l = p->liste_arcs ;

      while (l != NULL)
	{
          nb_arcs = nb_arcs + 1 ;
	  l = l->arc_suivant ;
	}
      
      p = p->sommet_suivant ;
    }
  return nb_arcs ;
}

void init_couleur_sommet (pgraphe_t g)
{
  psommet_t p = g ;

  while (p != NULL)
    {
      p->couleur = 0 ; // couleur indefinie
      p = p->sommet_suivant ; // passer au sommet suivant dans le graphe
    }
  
  return ;
}

int colorier_graphe (pgraphe_t g)
{
  /*
    coloriage du graphe g
    
    datasets
    graphe data/gr_planning
    graphe data/gr_sched1
    graphe data/gr_sched2
  */

  psommet_t p = g ;
  parc_t a ;
  int couleur ;
  int max_couleur = INT_MIN ; // -INFINI
  
  int change ;

  init_couleur_sommet (g) ;
  
  while (p != NULL)
    {
      couleur = 1 ; // 1 est la premiere couleur

      // Pour chaque sommet, on essaie de lui affecter la plus petite couleur

      // Choix de la couleur pour le sommet p
      
      do
	{
	  a = p->liste_arcs ;
	  change = 0 ;
      
	  while (a != NULL)
	    {
	      if (a->dest->couleur == couleur)
          {
            couleur = couleur + 1 ;
            change = 1 ;
          } 
	      a = a->arc_suivant ; 
	    }

	} while (change == 1) ;

      // couleur du sommet est differente des couleurs de tous les voisins
      
  p->couleur = couleur ;
  if (couleur > max_couleur)
	    max_couleur = couleur ;

      p = p->sommet_suivant ;
    }
  
  return max_couleur ;
}

void afficher_graphe_largeur (pgraphe_t g, int r)
{
  /*
    afficher les sommets du graphe avec un parcours en largeur
  */

  int visites[nombre_sommets(g)];
  int last_label_index = -1;
  
  pfile_t q = creer_file();
  enfiler(q, chercher_sommet(g, r));

  while (!file_vide(q)){
    psommet_t s = defiler(q);


    if (!deja_visite(s->label, visites, last_label_index)){
      
      last_label_index = visiter(s->label, visites, last_label_index);
      
      parc_t a = s->liste_arcs;

      while (a != NULL){

        if (!deja_visite(a->dest->label, visites, last_label_index)){
          enfiler(q, a->dest);
        }
        a = a->arc_suivant;
      }
      printf("SOMMET %d \n", s->label);

    }
  }
  
  return ;
}



void afficher_graphe_profondeur (pgraphe_t g, int r)
{
  /*
    afficher les sommets du graphe avec un parcours en profondeur
  */
  
  psommet_t s = chercher_sommet(g,r);
  ppile_t avisiter = creer_pile();

  int visites[nombre_sommets(g)];
  int last_label_index = 0;

  empiler(avisiter, s);
  while (!pile_vide(avisiter))
      {
          psommet_t t = depiler(avisiter);

          if (last_label_index != visiter(t->label, visites, last_label_index)){
            last_label_index++;
            printf("%i \n", t->label);
          }

          parc_t arc_courant = t->liste_arcs;
          while (arc_courant != NULL) {
            
            if (!deja_visite(arc_courant->dest->label, visites, last_label_index))
            {
              empiler(avisiter, arc_courant->dest);
            }

            arc_courant = arc_courant->arc_suivant;
          }
      }
  return;
}
 



void algo_dijkstra (pgraphe_t g, int r)
{
  /*
    algorithme de dijkstra
    des variables ou des chanmps doivent etre ajoutees dans les structures.
  */

  return ;
}





// ======================================================================




int degre_sortant_sommet (pgraphe_t g, psommet_t s)
{
  /*
    Cette fonction retourne le nombre d'arcs sortants 
    du sommet n dans le graphe g
  */ 

  parc_t arc = chercher_sommet(g, s->label)->liste_arcs;


  int compteur = 0;

  while (arc != NULL){
    compteur++;
    arc = arc->arc_suivant;
  }

  return compteur ;
}

int degre_entrant_sommet (pgraphe_t g, psommet_t s)
{
  /*
    Cette fonction retourne le nombre d'arcs entrants 
    dans le noeud n dans le graphe g

    Effet de bord, initialise la variable nb_arcs_entrants de chaque sommet
  */ 

  int nb_arcs_entrants = 0;
  psommet_t s_courant = g;
  while (s_courant != NULL){

    parc_t arc_courant = s_courant->liste_arcs;

    while (arc_courant != NULL) {

      if (arc_courant->dest->label == s->label){
        nb_arcs_entrants++;
      }
      
      arc_courant = arc_courant->arc_suivant; 
    }

    s_courant = s_courant->sommet_suivant;
  }


  return nb_arcs_entrants;
}

int degre_maximal_graphe (pgraphe_t g)
{
  /*
    Max des degres des sommets du graphe g
  */

  psommet_t s_courant = g;

  degre_entrant_sommet(g, s_courant);
  int max = degre_entrant_sommet(g, g);

  while (s_courant != NULL){

    int nb_arcs_entrants = degre_entrant_sommet(g, s_courant);

    if (nb_arcs_entrants > max){
      max = nb_arcs_entrants;
    }
    
    s_courant = s_courant->sommet_suivant;
  }

  return max ;
}


int degre_minimal_graphe (pgraphe_t g)
{
  /*
    Min des degres des sommets du graphe g
  */
  psommet_t s_courant = g;

  int min = degre_entrant_sommet(g, g);
  while (s_courant != NULL){

    int nb_arcs_entrants = degre_entrant_sommet(g, s_courant);

    if (nb_arcs_entrants < min){
      min = nb_arcs_entrants;
    }
    
    s_courant = s_courant->sommet_suivant;
  }

  return min ;
}


int independant (pgraphe_t g)
{
  /* Les aretes du graphe n'ont pas de sommet en commun */


  return (degre_maximal_graphe(g) <=1) ;
}



int complet (pgraphe_t g)
{
  /* Toutes les paires de sommet du graphe sont jointes par un arc */

  return (degre_minimal_graphe(g) >=1) ;
}

int regulier (pgraphe_t g)
{
  /* 
     graphe regulier: tous les sommets ont le meme degre
     g est le ponteur vers le premier sommet du graphe
     renvoie 1 si le graphe est régulier, 0 sinon
  */
  psommet_t s = g->sommet_suivant;
  int degre = degre_entrant_sommet(g,s);

  while (s != NULL) {

   int s_degre =  degre_entrant_sommet(g,s);

   if (s_degre != degre){
      return 0;
    }

    s  = s->sommet_suivant;
  }
    
  return 1 ;
}




/*
  placer les fonctions de l'examen 2017 juste apres
*/


int elementaire ( pgraphe_t g , chemin_t c ){
  
  
  int visites[nombre_sommets(g)]; 
  int last_label_index = -1;

  parc_t arc_courant = c.arcs;

  int noeud_courant = c.debut;
  last_label_index = visiter(noeud_courant, visites, last_label_index);



  while (arc_courant != NULL){
    noeud_courant = arc_courant->dest->label;

    if (deja_visite(noeud_courant, visites, last_label_index)){
      return 0;
    }

    last_label_index = visiter(noeud_courant, visites, last_label_index);

    arc_courant = arc_courant->arc_suivant;

  }

  return 1;
}

int simple ( pgraphe_t g , chemin_t c ) {

  int visites[nombre_arcs(g)]; 
  int last_label_index = -1;


  int debut = c.debut;


  //Je dis que l'id d'un arc c'est le nombre debutfin ex : debut = 4, fin = 5, id = 45
  parc_t arc_courant = c.arcs;
  int fin = c.arcs->dest->label;
  while (arc_courant != NULL){

    fin = arc_courant->dest->label;

    if (deja_visite((debut*10 + fin), visites, last_label_index)){
      return 0;
    }

    last_label_index = visiter((debut*10 + fin), visites, last_label_index);

    arc_courant = arc_courant->arc_suivant;

    debut = fin;
  }

  return 1;

}

/*
Un chemin est dit Eulérien si tous les arcs du graphe sont utilisés dans le chemin.
*/
int eulerien ( pgraphe_t g , chemin_t c ) {
  int nb_arcs_differents = 0;

  int visites[nombre_arcs(g)]; 
  int last_label_index = -1;

  parc_t arc_courant = c.arcs;

  int debut = c.debut;

  while (arc_courant != NULL){

    int fin = arc_courant->dest->label;
    
    if (!deja_visite((debut*10 + fin), visites, last_label_index)){
       last_label_index = visiter((debut*10 + fin), visites, last_label_index);
       nb_arcs_differents++;
    }

    arc_courant = arc_courant->arc_suivant;
    debut = fin;
  }

  if (nb_arcs_differents == nombre_arcs(g)){
    return 1;
  }

  return 0;

}

/*
* Un graphe connexe admet un parcours eulérien si et seulement si ses sommets sont tous de degré pair sauf au plus deux.
*/

int graphe_eulerien ( pgraphe_t g) {

  /*if (connexe(g) == 0){
    return 0;
  }*/

  int sommets_impairs = 0;
  
  psommet_t s = g;
  while (s != NULL) {
    if (degre_entrant_sommet(g, s) % 2 != 0){
      sommets_impairs++;
    }
    s = s->sommet_suivant;
  }

  if (sommets_impairs <= 2){
    return 1;
  }

  return 0;
}

 /*Un chemin est dit Hamiltonien si tous les sommets du graphe sont utilisés dans le chemin.*/
int hamiltonien ( pgraphe_t g , chemin_t c ) {
  int nb_arcs_differents = 0;

  int visites[nombre_sommets(g)]; 
  int last_label_index = -1;

  parc_t arc_courant = c.arcs;

  int debut = c.debut;

  while (arc_courant != NULL){

    int fin = arc_courant->dest->label;
    
    if (!deja_visite(debut, visites, last_label_index)){
       last_label_index = visiter(debut, visites, last_label_index);
       nb_arcs_differents++;
    }

    arc_courant = arc_courant->arc_suivant;
    debut = fin;
  }

  if (nb_arcs_differents == nombre_sommets(g)){
    return 1;
  }

  return 0;

}


int graphe_hamiltonien( pgraphe_t g) {

}


int longueur(pgraphe_t g, chemin_t c) {
  int longueur = 0;

  parc_t arc_courant = c.arcs;

  while (arc_courant != NULL){
    longueur += arc_courant->poids;
    arc_courant = arc_courant->arc_suivant;
  }

  return longueur;
}

int distance (pgraphe_t g, int x, int y) {


  /*
  algo_dijkstra(g) va nous fournir un chemin et on calcule le poids de ses arcs ?
  */
}

/*
L’excentricitéd’unsommetestsadistancemaximaleaveclesautressommetsdugraphe.
*/
int excentricite (pgraphe_t g, int n){
  int max = 0;

  psommet_t s = g;
  while (s != NULL) {
    int dist = distance(g, n, s->label);
    if (dist > max){
      max = dist;
    }
    s = s->sommet_suivant;
  }

  return max;
}

int diametre( pgraphe_t g) {
  int max = 0;

  psommet_t s = g;
  while (s != NULL) {
    int excentricite_s = excentricite(g, s->label);
    if (excentricite_s > max){
      max = excentricite_s;
    }
    s = s->sommet_suivant;
  }

  return max;
}
