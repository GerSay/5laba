#ifndef WORKPROJECT_VECTORVOID_H
#define WORKPROJECT_VECTORVOID_H

#include <stdio.h>
#include <malloc.h>

typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;

vectorVoid createVectorV(size_t n, size_t baseTypeSize);

void reserveV(vectorVoid *v, size_t newCapacity);

void shrinkToFitV(vectorVoid *v);

void clearV(vectorVoid *v);

// Очищает память из-под v.data,
// обнуляет v.size, v.capacity и v.baseTypeSize
void deleteVectorV(vectorVoid *v);




#endif //WORKPROJECT_VECTORVOID_H
