#include "../../algorithms/algorithms.h"
#include "vector_tests.h"


//--89-
void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 5);
    assert(v.size == 1);
    assert(v.data[0] == 5);
}

//--90-
void test_pushBack_fullVector() {
    vector v = createVector(5);
    v.size = v.capacity;
    pushBack(&v, 5);
    assert(v.size == 6);
    assert(v.data[v.size - 1] == 5);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}
