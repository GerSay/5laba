//#include "libs/data_structures/matrix/matrix.h"
//
//int main() {
//    matrix m;
//    inputAndCreateMatrix(&m);
//
//    swapColumns(m, 0, 1);
//
//    outputMatrix(m);
//
//    freeMemMatrix(m);
//
//    return 0;
//}

// Вариант №8
#include "libs/algorithms/array/array.h"

void createSortedArray(const int *a, size_t sizeA,
                       const int *b, size_t sizeB,
                       int *c, size_t *sizeC) {
    *sizeC = 0;
    int i = 0;
    int j = 0;
    for (size_t k = 0; k < sizeA + sizeB; k++)
        if (a[i] < b[j]) {
            c[*sizeC] = a[i];
            (*sizeC)++;
            i++;
        } else if (a[i] > b[j]) {
            c[*sizeC] = b[j];
            (*sizeC)++;
            j++;
        } else {
            c[*sizeC] = a[i];
            c[*sizeC + 1] = b[j];
            (*sizeC) += 2;
            i++;
            j++;
        }
}

void _tests1() {
    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6};
    size_t sizeC = 6;
    int c[sizeC];
    createSortedArray(a, 3, b, 3, c, &sizeC);

    outputArray_(c, sizeC);
}

void _tests2() {
    int a[] = {1, 3, 5};
    int b[] = {1, 3, 6};
    size_t sizeC = 6;
    int c[sizeC];
    createSortedArray(a, 3, b, 3, c, &sizeC);

    outputArray_(c, sizeC);
}

void _tests3() {
    int a[] = {1};
    int b[] = {2};
    size_t sizeC = 2;
    int c[sizeC];
    createSortedArray(a, 1, b, 1, c, &sizeC);

    outputArray_(c, sizeC);
}

void _tests4() {
    int a[] = {1, 3, 5, 7, 7, 8};
    int b[] = {2, 4, 6, 9};
    size_t sizeC = 10;
    int c[sizeC];
    createSortedArray(a, 6, b, 4, c, &sizeC);

    outputArray_(c, sizeC);
}

void _tests() {
    _tests1();
    _tests2();
    _tests3();
    _tests4();
}

int main() {
    int a[100];
//    int b[100];
//    inputArray_(a, 100);
//    inputArray_(b, 100);
//
//    size_t sizeC = 200;
//    int c[sizeC];
//    createSortedArray(a, 100, b, 100, c, &sizeC);

    _tests();

    return 0;
}