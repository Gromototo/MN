#include <stdlib.h>
#include <assert.h>

#include "abr.h"
#include "pile.h"

int main(int argc, char *argv[]) {

  ppile_t pile = creer_pile();
  
  assert(pile_vide(pile));
  assert(!pile_pleine(pile));

  for (int i = 0; i < MAX_PILE_SIZE; i++) {
    empiler(pile, (pnoeud_t) i);
  }

  assert(!pile_vide(pile));
  assert(pile_pleine(pile));

  for (int i = 0; i < MAX_PILE_SIZE; i++) {
    assert((int) depiler(pile) == MAX_PILE_SIZE - 1 - i);
  }

  assert(depiler(pile) == NULL);

  assert(pile_vide(pile));
  assert(!pile_pleine(pile));  

  detruire_pile(pile);

  return 0;
}
