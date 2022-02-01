#include "vector.h"

void error() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

vector createVector(size_t n) {
    vector v;
    v.data = malloc(sizeof(int) * n);
    if (v.data != NULL)
        return v;

    error();
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    if (newCapacity < v->size)
        v->size = newCapacity;
    v->data = realloc(v->data, sizeof(int) * newCapacity);
}

