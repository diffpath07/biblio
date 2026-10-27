#include <stdlib.h>
#include <string.h>
#include "vector.h"


struct Vector {
    void *data;      
    size_t size;     
    size_t capacity;  
    size_t element_size; 
};

vec_t *vec_new(size_t element_size){
    vec_t *v = calloc(1,sizeof(struct Vector));
    if (v == NULL) {
        return NULL; 
    }
    if (element_size == 0) {
        free(v);
        return NULL; 
    }
    v->element_size = element_size;     
    return v;
}
void vec_free(vec_t *v){
    if (v != NULL) {
        free(v->data); 
        free(v);       
    }
}
int vec_push(vec_t *v , const void *element){
    if (v == NULL || element == NULL) {
        return -1; 
    }

  
    if (v->size >= v->capacity) {
        size_t new_capacity = (v->capacity == 0) ? 1 : v->capacity * 2;
        void *new_data = realloc(v->data, new_capacity * v->element_size);
        if (new_data == NULL) {
            return -1; 
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }

   
    memcpy((char *)v->data + v->size * v->element_size, element, v->element_size);
    v->size++;
    return 0; 
}
int vec_pop(vec_t *v , void *out_element){
    if (v == NULL || v->size == 0) {
        return -1; 
    }

    if (out_element != NULL) {
        memcpy(out_element, (char *)v->data + (v->size - 1) * v->element_size, v->element_size);
    }
    v->size--;
    return 0; 
}
void *vec_get(const vec_t *v , size_t i){
    if (v == NULL || i >= v->size) {
        return NULL; 
    }
    return (char *)v->data + i * v->element_size; 
}

int vec_set(vec_t *v , size_t i, const void *element){
    if (v == NULL || element == NULL || i >= v->size) {
        return -1; 
    }
    memcpy((char *)v->data + i * v->element_size, element, v->element_size);
    return 0; 

size_t vec_size(const vec_t *v){
    if (v == NULL) {
        return 0; 
    }
    return v->size; 
}
