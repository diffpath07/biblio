#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct Vector vec_t;

//Cree un nouveau vecteur dynamique capable de contenir des éléments de taille element_size returne un pointeur vers le vecteur créé ou NULL si la création a échoué. Le vecteur est initialement vide et a une capacité de 0.
vec_t *vec_new(size_t element_size); // retourne une adresse ; reçoit un nombre


// Libère la mémoire allouée pour le vecteur v et ses éléments. Après l'appel à cette fonction, le vecteur ne doit plus être utilisé.
void vec_free(vec_t *v );  // ne retourne rien ; modifie le vecteur


// Ajoute un nouvel élément à la fin du vecteur v. L'élément est copié à partir de l'adresse pointée par element. Si le vecteur n'a pas assez de capacité pour contenir le nouvel élément, sa capacité est doublée. Retourne 0 si l'ajout a réussi, ou -1 si une erreur s'est produite (par exemple, échec d'allocation mémoire).
int vec_push(vec_t *v , const void *element); // modifie v ; lit element 

int vec_pop(vec_t *v , void *out_element); // modifie v ; écrit dans out



// Retourne l'adresse de l'élément à l'index i dans le vecteur v. Si i est hors des limites du vecteur, retourne NULL.
void *vec_get( const vec_t *v , size_t i);  // retourne l'adresse de l'élément i


// Modifie l'élément à l'index i dans le vecteur v en le remplaçant par l'élément pointé par element. Si i est hors des limites du vecteur, retourne -1. Sinon, retourne 0 pour indiquer que la modification a réussi.
int vec_set(vec_t *v , size_t i, const void *element);   // modifie v ; lit elem


// Retourne le nombre d'éléments actuellement stockés dans le vecteur v.
size_t vec_size(const vec_t *v );   // lit seulement v



#endif   