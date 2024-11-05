#include "darray.h"
#include <stdlib.h>
#include <string.h>

// Create a dynamic array with an initial capacity
darray *da_create() {
    darray *array = malloc(sizeof(darray));
    if (array == NULL) {
        return NULL; // Memory allocation failure
    }
    array->capacity = 10;  // Start with a capacity of 10 elements
    array->size = 0;
    array->data = malloc(array->capacity * sizeof(int)); // Assuming the array holds integers
    if (array->data == NULL) {
        free(array); // Clean up if allocation fails
        return NULL;
    }
    return array;
}

// Destroy the dynamic array and free all associated memory
void da_delete(darray *array) {
    if (array) {
        free(array->data); // Free the allocated data
        free(array); // Free the array struct itself
    }
}

// Add an element to the dynamic array
int da_append(darray *array, int value) {
    if (array == NULL) {
        return 0; // If the array is NULL, return 0 (failure)
    }
    
    // If the array is full, resize it
    if (array->size >= array->capacity) {
        size_t new_capacity = array->capacity * 2; // Double the capacity
        int *new_data = realloc(array->data, new_capacity * sizeof(int)); // Reallocate memory
        if (new_data == NULL) {
            return 0; // Memory allocation failure
        }
        array->data = new_data;
        array->capacity = new_capacity;
    }
    
    // Append the value and increase size
    array->data[array->size++] = value;
    return 1; // Success
}

// Get an element from the dynamic array at a specific index
int *da_get(darray *array, size_t idx) {
    if (array == NULL || idx >= array->size) {
        return NULL; // Return NULL if out of bounds or array is NULL
    }
    return &array->data[idx]; // Return a pointer to the element
}

// Get the size of the dynamic array (number of elements)
size_t da_size(darray *array) {
    if (array == NULL) {
        return 0; // If the array is NULL, return size 0
    }
    return array->size;
}
