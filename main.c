#include "libs/data_structures/vector_tests/vector_tests.h"
#include "libs/govnocode/DiscMath/DiscMath.h"
#include "libs/algorithms/array/array.h"


int main() {
    size_t sizeA = 3, sizeB = 3;
    int a[sizeA], b[sizeB];
    inputArray_(a, sizeA);
    inputArray_(b, sizeB);
    size_t sizeC = sizeA + sizeB;
    int c[sizeC];
    varEight(a, sizeA, b, sizeB, c, &sizeC);
    outputArray_(c, sizeC);

    return 0;
}