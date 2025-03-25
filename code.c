#include "code.h"
#include <stdlib.h>
#include <stdio.h>

code_t *alloue_code() {
      
  code_t *v = (code_t *)malloc(sizeof(code_t));
  if(v == NULL){
      return NULL; // Echec d'allocation
    }
  v->taille=0;

    return v;
}
void libere_code(code_t *c) {
  //free(c->table);
  if(c == NULL){return;}
  free(c);
}

int taille_code(code_t *c) { 
  if(c == NULL){return 0;}
  return c->taille;
}

char code_element(code_t *c, int p) {
  if(c == NULL){return ' ';}
  if(p >= taille_code(c)){ 

    return ' '; 
    // Si la position donnée est égale à la fin du code, la valeur à renvoyer est ' '
  }
  else if(p < 0){
    return c->sequence[0]; 
    // La position 0 si position est négatif
  }
  else{
    return c->sequence[p]; 
    // La position qui précède le caractère de numéro position si position appartient à [0;taille_code(c)-1]
  }
}

void code_ajoute(code_t *c, char e) {
  if(c == NULL){return;}
  if(e == 'A' || e == 'C' || e == 'G' || e == 'T'){
    if(c->taille < MAX && c->taille >= 0){
      c->sequence[c->taille]=e;
      c->taille++;
    }
  }
}

int sous_code(code_t *a, code_t *b) {

  if(a == NULL || b == NULL){return -1;}
  int position = -1;  
  int k = 0;
    
  for (int i = 0; i < taille_code(a); i++) {
      if (code_element(a, i) == code_element(b, k)) {
          if (k == 0) {
              position = i;  
          }
          k++;
          if (k == taille_code(b)) {
              return position;  
          }
      } else {
          
          if (k > 0) {
              i = position;  
          }
          k = 0;
          position = -1;
      }
  }
  return -1; 
}
void coupe_code(code_t *a, int position, code_t **b, code_t **c) {

  if (a == NULL || b == NULL || c == NULL) {
    return;
  }

  *b = alloue_code();
  *c = alloue_code();
  if (*b == NULL || *c == NULL) {
        return;
  }
  
  if (position > taille_code(a)) {
        position = taille_code(a);
  }
  if(position < 0){
      position = 0;
  }
  
  
  for (int i = 0; i < taille_code(a); i++) {
        if (i < position) {
            code_ajoute(*b, code_element(a, i));
        } else {
            code_ajoute(*c, code_element(a, i));
        }
    }
}
code_t *combine_codes(code_t *a, code_t *b) {
  code_t *c=alloue_code();

  if(c==NULL || a == NULL || b == NULL){return NULL;}

  int new_taille=taille_code(a)+taille_code(b);
  if(new_taille > MAX){
    new_taille = MAX;
  }
  for (int i = 0; i < taille_code(a) && i < new_taille; i++) {
    code_ajoute(c, code_element(a, i));
  }
  
  for (int j = 0; j < taille_code(b) && c->taille < new_taille; j++) {
    code_ajoute(c, code_element(b, j));
  }  

  return c;
}
