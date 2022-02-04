#ifndef WORKPROJECT_VECTOR_TESTS_H
#define WORKPROJECT_VECTOR_TESTS_H

#include "../../algorithms/algorithms.h"
#include "../../data_structures/vector/vector.h"
#include <assert.h>
#include <stdint.h>

void test_createVector();

void test_createVectorError();

void test_reserve();

void test_reserve_error();

void test_clear();

void test_shrinkToFit();

void test_pushBack_emptyVector();

void test_pushBack_fullVector();

void test_popBack_notEmptyVector();

void test_atVector_notEmptyVector();

void test_atVectorRequestToLastElement();

void test_back_oneElementInVector();

void test_front_oneElementInVector();

void test_vector();

#endif //WORKPROJECT_VECTOR_TESTS_H