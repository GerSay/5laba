#include "vectorVoid.h"

void errorV() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid v;
    v.size = 0;
    v.capacity = n;
    v.baseTypeSize = baseTypeSize;
    if (n) {
        v.data = malloc(sizeof(int) * v.capacity);
        if (v.data == NULL)
            errorV();
    } else
        v.data = NULL;

    return v;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (!newCapacity) {
        free(v->data);
        v->data = NULL;
        return;
    }

    v->data = realloc(v->data, newCapacity * v->baseTypeSize);
    if (v->data == NULL)
        errorV();

    v->capacity = newCapacity;
    if (v->size > newCapacity)
        v->size = newCapacity;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
    v->baseTypeSize = 0;
}