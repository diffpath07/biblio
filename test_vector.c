#include <stdio.h>
#include <assert.h>
#include "vector.h"

int main(void)
{
    vec_t *v = vec_new(sizeof(int));
    assert(v != NULL);

    for (int i = 0; i < 100; i++)
        vec_push(v, &i);

    assert(vec_size(v) == 100);
    assert(*(int *)vec_get(v, 42) == 42);
    assert(vec_get(v, 100) == NULL);

    int x = 7;
    vec_set(v, 0, &x);
    assert(*(int *)vec_get(v, 0) == 7);

    int out;
    vec_pop(v, &out);
    assert(out == 99);
    assert(vec_size(v) == 99);

    vec_free(v);
    assert(vec_new(0) == NULL);               

    vec_t *e = vec_new(sizeof(int));          
    assert(vec_size(e) == 0);
    assert(vec_pop(e, NULL) == -1);           
    assert(vec_get(e, 0) == NULL);            
    int y = 5;
    assert(vec_set(e, 0, &y) == -1);          

    vec_push(e, &y);
    assert(vec_pop(e, NULL) == 0);          
    assert(vec_size(e) == 0);
    vec_free(e);

    vec_free(NULL);  
    puts("OK");
    return 0;
}
 