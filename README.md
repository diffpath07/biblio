# biblio

A small, dependency-free C library of generic data structures.

## Contents

- [Vector](#vector)
- [Build and test](#build-and-test)
- [Example](#example)
- [API reference](#api-reference)
- [Notes](#notes)

## Vector

A dynamic array that grows automatically. It hides `malloc`, `realloc`, and `free` behind a few simple functions, and works with any element type (`int`, `double`, structs, …).

## Build and test

```bash
make test
```

## Example

```c
#include <stdio.h>
#include "vector.h"

int main(void)
{
    vec_t *v = vec_new(sizeof(int));

    for (int i = 0; i < 5; i++)
        vec_push(v, &i);

    printf("%d\n", *(int *)vec_get(v, 2)); /* prints 2 */

    vec_free(v);
    return 0;
}
```

## API reference

| Function | Description | Returns |
|---|---|---|
| `vec_new(element_size)` | Creates an empty vector. | Pointer to the vector, or `NULL` on failure. |
| `vec_free(v)` | Frees the vector. Accepts `NULL`. | — |
| `vec_push(v, element)` | Appends a copy of `element`. | `0` on success, `-1` on failure. |
| `vec_pop(v, out)` | Removes the last element and copies it into `out` if `out` is not `NULL`. | `0` on success, `-1` if empty. |
| `vec_get(v, i)` | Returns the address of element `i`. | Pointer to the element, or `NULL` if out of bounds. |
| `vec_set(v, i, element)` | Replaces element `i` with a copy of `element`. | `0` on success, `-1` if out of bounds. |
| `vec_size(v)` | Returns the number of elements. | Element count. |

## Notes

- **Ownership:** elements are copied into the vector, so the vector owns its data.
- **Pointer invalidation:** the pointer returned by `vec_get` becomes invalid after a `vec_push`, because the underlying array may be reallocated.