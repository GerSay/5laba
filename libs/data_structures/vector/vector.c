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
    v->data = realloc(v->data, sizeof(int) * newCapacity);
    if (v->data == NULL)
        error();
    if (newCapacity == 0 && v->capacity != 0)
        v->data = NULL;
    if (newCapacity < v->size)
        v->size = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve (v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

int main() {


    return 0;
}



