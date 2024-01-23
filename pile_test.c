#include <stdlib.h>
#include <assert.h>
#include "pile.c"

int main(int argc, char *argv[]) {

  ppile_t pile = creer_pile();
  
  assert(pile_vide(pile));
  assert(!pile_pleine(pile));

  for (int i = 0; i < MAX_PILE_SIZE; i++) {
    empiler(pile, i);
  }

  assert(!pile_vide(pile));
  assert(pile_pleine(pile));

  for (int i = 0; i < MAX_PILE_SIZE; i++) {
    assert(depiler(pile) == MAX_PILE_SIZE - 1);
  }

  assert(depiler(pile) == NULL);

  assert(pile_vide(pile));
  assert(!pile_pleine(pile));  

  detruire_pile(pile);

  return 0;
}
