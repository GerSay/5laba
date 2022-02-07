#include "vector.h"

void error() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

void indexError(size_t index) {
    fprintf(stderr, "IndexError: a[%d] is not exists", index);
    exit(2);
}

vector createVector(size_t n) {
    vector v;
    v.size = 0;
    v.capacity = n;
    if (n) {
        v.data = malloc(sizeof(int) * v.capacity);
        if (v.data == NULL)
            error();
    } else
        v.data = NULL;

    return v;
}

void reserve(vector *v, size_t newCapacity) {
    if (!newCapacity) {
        free(v->data);
        v->data = NULL;
        return;
    }

    v->data = realloc(v->data, newCapacity * sizeof(int));
    if (v->data == NULL)
        error();

    v->capacity = newCapacity;
    if (v->size > newCapacity)
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

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->size >= v->capacity && v->capacity)
        reserve(v, v->capacity * 2);
    else if (!v->capacity)
        reserve(v, 1);
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (isEmpty(v))
        error();
    v->size = v->size - 1;
}

int *atVector(vector *v, size_t index) {
    if (index < v->size)// size на 1 больше индекса последнего элемента
        return v->data + index;
    indexError(index);
}

int *back(vector *v) {
    if (v->data != NULL && v->size)
        return v->data + v->size - 1;
    error();
}

int *front(vector *v) {
    if (v->data != NULL && v->size)
        return v->data;
    error();
}


// ---------------------------------------------------------------------

