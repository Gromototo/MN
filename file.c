#include <stdlib.h>

#include "abr.h"
#include "file.h"

pfile_t creer_file ()
{
  pfile_t file = (pfile_t)malloc(sizeof(file_t));
  if (file == NULL) {
    // Handle memory allocation failure
    exit(EXIT_FAILURE);
  }

  file->tete = -1;
  file->queue = -1;
  return file;
}

int detruire_file (pfile_t f)
{
  free(f);
  return 1;
}



int file_vide (pfile_t f)
{
 if (f->queue == f->tete-1){
  return 1;
 }
  return 0 ;
}

int file_pleine (pfile_t f)
  {
  if (f->queue == f->tete+1){
    return 1;
  }
  return 0 ;
}

pnoeud_t defiler (pfile_t f)
{
  if(file_vide(f)){
    return NULL;
  }
  if(f->tete==MAX_FILE_SIZE-1){
    pnoeud_t elem = f->Tab[f->tete];
    f->tete=0;
    return elem;
  }
  pnoeud_t elem = f->Tab[f->tete];
  f->tete++;  
  return elem;
}

int enfiler (pfile_t f, pnoeud_t p)
{
  if (file_pleine(f)){
    return -1;
  }
  if(f->queue!=MAX_FILE_SIZE-1){
    f->queue++;
    f->Tab[f->queue]=p;
    return f->queue;
  }
  else{
    f->queue=0;
    f->Tab[f->queue]=p;
    return f->queue;
  }
}
