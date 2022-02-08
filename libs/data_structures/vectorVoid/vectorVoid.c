#include "vectorVoid.h"

void errorV() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

void indexErrorV(size_t index) {
    fprintf(stderr, "IndexError: a[%d] is not exists", index);
    exit(2);
}

void ifCorrectIndex(vectorVoid *v, size_t index) {
    if (index > v->size)
        indexErrorV(index);
}

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid v;
    v.size = 0;
    v.capacity = n;
    v.baseTypeSize = baseTypeSize;
    if (n) {
        v.data = malloc(v.baseTypeSize * v.capacity);
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

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index,
                     void *destination) {
    ifCorrectIndex(v, index);
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    ifCorrectIndex(v, index);
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v))
        errorV();
    v->size = v->size - 1;
}

void pushBackV(vectorVoid *v, void *source) {
    if (v->size >= v->capacity && v->capacity)
        reserveV(v, v->capacity * 2);
    else if (!v->capacity)
        reserveV(v, v->capacity + 1);

    setVectorValueV(v, v->size++, source);
}