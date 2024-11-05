#ifndef H_DARRAY
#define H_DARRAY

#include <stdlib.h>

// Full definition of the darray struct
typedef struct {
    int *data;         // Pointer to array of integers
    size_t size;       // Current number of elements in the array
    size_t capacity;   // Capacity of the array
} darray;

/* Function prototypes */
darray *da_create();
int *da_get(darray *array, size_t idx);
int da_append(darray *array, int value);
size_t da_size(darray *array);
void da_delete(darray *array);

#endif
