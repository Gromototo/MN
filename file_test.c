#include <stdlib.h>

#include <stdio.h>


#include <assert.h>


#include "file.c"

int main(int argc, char *argv[]){

  pfile_t file = creer_file();
  
  assert(file_vide(file));
  assert(!file_pleine(file));

  for (int i = 0; i < MAX_FILE_SIZE -1; i++) {
    enfiler(file, i);
  }

  assert(!file_vide(file));
  assert(file_pleine(file));


  for (int i = 0; i < MAX_FILE_SIZE -1; i++) {
    assert((int)defiler(file) == i);
  }

  assert(defiler(file) == NULL);

  assert(file_vide(file));
  assert(!file_pleine(file));  

  detruire_file(file);

  return 0;
    
}