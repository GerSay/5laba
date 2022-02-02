#ifndef WORKPROJECT_VECTOR_TESTS_H
#define WORKPROJECT_VECTOR_TESTS_H

#include "../../data_structures/vector/vector.h"
#include <assert.h>

void test_pushBack_emptyVector();

void test_pushBack_fullVector();

void test_popBack_notEmptyVector();

void test_atVector_notEmptyVector();

void test_atVectorRequestToLastElement();

void test_back_oneElementInVector();

void test_front_oneElementInVector();

void _tests() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVectorRequestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

#endif //WORKPROJECT_VECTOR_TESTS_H