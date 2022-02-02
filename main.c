#include "libs/data_structures/vector_tests//vector_tests.h"

void _tests() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    }

int main() {
    _tests();

    return 0;
}