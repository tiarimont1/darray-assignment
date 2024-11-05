#include "darray.h"
#include <stdio.h>
#include <assert.h>

void test_da_create() {
    darray *arr = da_create();
    assert(arr != NULL);
    assert(arr->size == 0);
    assert(arr->capacity == 10);
    printf("da_create passed\n");
}

void test_da_append() {
    darray *arr = da_create();
    da_append(arr, 1);
    assert(arr->size == 1);
    assert(arr->data[0] == 1);
    printf("da_append passed\n");
}

int main() {
    test_da_create();
    test_da_append();
    return 0;
}
