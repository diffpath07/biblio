#include <stdlib.h>
#include <string.h>
#include "vector.h"


struct Vector {
    void *data;      // Pointer to the array of elements
    size_t size;      // Current number of elements in the vector
    size_t capacity;  // Current allocated capacity of the vector
    size_t element_size; // Size of each element in the vector
};

vec_t *vec_new(size_t element_size){
    vec_t *v = calloc(1,sizeof(struct Vector));
    if (v == NULL) {
        return NULL; // Allocation failed
    }
    if (element_size == 0) {
        free(v);
        return NULL; // Invalid element size
    }
    v->element_size = element_size;     
    return v;
}
void vec_free(vec_t *v){
    if (v != NULL) {
        free(v->data); // Free the data array
        free(v);       // Free the vector structure
    }
}
int vec_push(vec_t *v , const void *element){
    if (v == NULL || element == NULL) {
        return -1; // Invalid input
    }

    // Check if we need to resize the vector
    if (v->size >= v->capacity) {
        size_t new_capacity = (v->capacity == 0) ? 1 : v->capacity * 2;
        void *new_data = realloc(v->data, new_capacity * v->element_size);
        if (new_data == NULL) {
            return -1; // Allocation failed
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }

    // Copy the new element into the vector
    memcpy((char *)v->data + v->size * v->element_size, element, v->element_size);
    v->size++;
    return 0; // Success
}
int vec_pop(vec_t *v , void *out_element){
    if (v == NULL || v->size == 0) {
        return -1; // Invalid input or empty vector
    }

    if (out_element != NULL) {
        memcpy(out_element, (char *)v->data + (v->size - 1) * v->element_size, v->element_size);
    }
    v->size--;
    return 0; // Success
}
void *vec_get(const vec_t *v , size_t i){
    if (v == NULL || i >= v->size) {
        return NULL; // Invalid input or index out of bounds
    }
    return (char *)v->data + i * v->element_size; // Return pointer to the element
}

int vec_set(vec_t *v , size_t i, const void *element){
    if (v == NULL || element == NULL || i >= v->size) {
        return -1; // Invalid input or index out of bounds
    }
    memcpy((char *)v->data + i * v->element_size, element, v->element_size);
    return 0; // Success
}

size_t vec_size(const vec_t *v){
    if (v == NULL) {
        return 0; // Invalid input
    }
    return v->size; // Return the current size of the vector
}