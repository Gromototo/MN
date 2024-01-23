#include <stdlib.h>
#include "abr.h"
#include "pile.h"

ppile_t creer_pile ()
{
  ppile_t pile = (ppile_t) malloc(sizeof(pile_t));
  if (pile == NULL) {
    // Handle memory allocation failure
    exit(EXIT_FAILURE);
  }

  pile->sommet = -1;
  return pile;
}


int detruire_pile (ppile_t p)
{
  free(p);
 
  return 1;
}  

int pile_vide (ppile_t p)
{
  if (p->sommet == -1) {
    return 1;
  }
  return 0 ;
}

int pile_pleine (ppile_t p)
 {
  if (p->sommet == MAX_PILE_SIZE-1) {
    return 1;
  }
  return 0 ;
} 

pnoeud_t depiler (ppile_t p)
{
  
  if (pile_vide(p)) {
    return NULL;
  }
 
  pnoeud_t elem = p->Tab[p->sommet];
  p->sommet--;
  return elem ;
  
}

int empiler (ppile_t p, pnoeud_t pn)
{
  if (pile_pleine(p)){
    return -1;
  }

  p->Tab[p->sommet+1]=pn;
  p->sommet++;
  return p->sommet;  
}
