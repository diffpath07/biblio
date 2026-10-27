#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct Vector vec_t;


vec_t *vec_new(size_t element_size); 

void vec_free(vec_t *v );  

int vec_push(vec_t *v , const void *element); 

int vec_pop(vec_t *v , void *out_element); 

void *vec_get( const vec_t *v , size_t i);  

int vec_set(vec_t *v , size_t i, const void *element);   

size_t vec_size(const vec_t *v );   



#endif   
