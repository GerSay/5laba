#include "5dTasks_tests.h"

//---------------------------------------1-----------------------------------

void test_swapRowsSquareMatrixWithMaxMinElement_maxAndMinInSameRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 7, 1,
                    3, 6, 0,
                    4, 5, 9
            },              3, 3);

    swapRowsSquareMatrixWithMaxMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, 7, 1,
                    3, 6, 0,
                    4, 5, 9
            },              3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_swapRowsSquareMatrixWithMaxMinElement_maxAndMinInDifferentRows() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },              3, 3);

    swapRowsSquareMatrixWithMaxMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 8, 9,
                    4, 5, 6,
                    1, 2, 3
            },              3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_swapRowsSquareMatrixWithMaxMinElement_oneElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1
            }, 1, 1);

    swapRowsSquareMatrixWithMaxMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1
            }, 1, 1);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_swapRowsSquareMatrixWithMaxMinElement() {
    test_swapRowsSquareMatrixWithMaxMinElement_maxAndMinInSameRow();
    test_swapRowsSquareMatrixWithMaxMinElement_maxAndMinInDifferentRows();
    test_swapRowsSquareMatrixWithMaxMinElement_oneElement();
}

//---------------------------------------2-----------------------------------

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, _getMax);
}

void test_sortRowsByMinElement_SquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3
            },              3, 3);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 2, 3,
                    7, 1, 2,
                    1, 8, 1
            },              3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortRowsByMinElement_rectangleHorizontalMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2, 3,
                    1, 8, 1, 6,
                    3, 2, 3, 8
            },                  3, 4);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2, 3,
                    1, 8, 1, 6,
                    3, 2, 3, 8
            },                  3, 4);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortRowsByMinElement_rectangleVerticalMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3,
                    6, 2, 1
            },              4, 3);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 2, 3,
                    6, 2, 1,
                    7, 1, 2,
                    1, 8, 1
            },              4, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortRowsByMinElement_oneElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7
            },        1, 1);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7
            },        1, 1);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortRowsByMinElement_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 2, 4, 6
            },                  1, 4);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 2, 4, 6
            },                  1, 4);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortRowsByMinElement_oneCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7,
                    2,
                    4,
                    6
            },        4, 1);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2,
                    4,
                    6,
                    7
            },        4, 1);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortRowsByMinElement() {
    test_sortRowsByMinElement_rectangleVerticalMatrix();
    test_sortRowsByMinElement_rectangleHorizontalMatrix();
    test_sortRowsByMinElement_SquareMatrix();
    test_sortRowsByMinElement_oneElement();
    test_sortRowsByMinElement_oneRow();
    test_sortRowsByMinElement_oneCol();
}

//---------------------------------------3-----------------------------------

void test_sortColsByMinElement_SquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3
            },              3, 3);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3
            },              3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortColsByMinElement_rectangleHorizontalMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3
            },                       3, 6);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    5, 2, 3, 3, 3, 4,
                    5, 1, 2, 2, 7, 8,
                    1, 4, 6, 8, 3, 4
            },                       3, 6);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortColsByMinElement_rectangleVerticalMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    4, 8, 1,
                    3, 2, 3,
                    6, 2, 1
            },              4, 3);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 7,
                    8, 1, 4,
                    2, 3, 3,
                    2, 1, 6
            },              4, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortColsByMinElement_oneElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7
            },        1, 1);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7
            },        1, 1);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortColsByMinElement_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 2, 4, 6
            },                 1, 4);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, 4, 6, 7
            },                 1, 4);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortColsByMinElement_oneCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7,
                    2,
                    4,
                    6
            },        4, 1);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7,
                    2,
                    4,
                    6
            },        4, 1);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortColsByMinElement() {
    test_sortColsByMinElement_SquareMatrix();
    test_sortColsByMinElement_rectangleHorizontalMatrix();
    test_sortColsByMinElement_rectangleVerticalMatrix();
    test_sortColsByMinElement_oneElement();
    test_sortColsByMinElement_oneRow();
    test_sortColsByMinElement_oneCol();
}

//---------------------------------------4-----------------------------------

void test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_1() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    2, 1, 3
            },              3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    54, 17, 21,
                    17, 66, 13,
                    21, 13, 14
            },                 3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    0, 11, 7,
                    11, 0, 4,
                    7, 4, 22
            },               3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    170, 28, 198,
                    28, 137, 165,
                    198, 165, 549
            },                    3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_3() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },              3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },              3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_getSquareOfMatrixIfSymmetric_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7
            },        1, 1);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    49
            },         1, 1);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_getSquareOfMatrixIfSymmetric_NotSymmetricSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 1, 3
            },              3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 1, 3
            },              3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix() {
    test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_1();
    test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_2();
    test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_3();
}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix();
    test_getSquareOfMatrixIfSymmetric_NotSymmetricSquareMatrix();
    test_getSquareOfMatrixIfSymmetric_oneElem();
}

//---------------------------------------5-----------------------------------

void test_transposeIfMatrixHasEqualSumOfRows_oneElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2
            },        1, 1);

    transposeIfMatrixHasEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2
            },        1, 1);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_transposeIfMatrixHasEqualSumOfRows_hasEqualSum() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 1, 3
            },              3, 3);

    transposeIfMatrixHasEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 1, 3
            },              3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_transposeIfMatrixHasEqualSumOfRows_hasNotEqualSum() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 1,
                    1, 8, 1,
                    3, 1, 3
            },              3, 3);

    transposeIfMatrixHasEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 1, 3,
                    1, 8, 1,
                    1, 1, 3
            },              3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_transposeIfMatrixHasEqualSumOfRows_lastsSumIsEqual() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 1, 3,
                    1, 8, 1,
                    7, 1, 2
            },              3, 3);

    transposeIfMatrixHasEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 1, 3,
                    1, 8, 1,
                    7, 1, 2
            },              3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_transposeIfMatrixHasEqualSumOfRows() {
    test_transposeIfMatrixHasEqualSumOfRows_oneElement();
    test_transposeIfMatrixHasEqualSumOfRows_hasEqualSum();
    test_transposeIfMatrixHasEqualSumOfRows_hasNotEqualSum();
    test_transposeIfMatrixHasEqualSumOfRows_lastsSumIsEqual();
}

//---------------------------------------6-----------------------------------

//---------------------------------------7-----------------------------------

void test_findSumOfMaxesOfPseudoDiagonal_positiveHorizontalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            },                 3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 20);

    {
        freeMemMatrix(m1);
    }
}

void test_findSumOfMaxesOfPseudoDiagonal_negativeHorizontalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, -2, -5, -4,
                    -1, -3, -6, -3,
                    -3, -2, -1, -2
            },                     3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -3 + -1 + -2 + -3 + -4);

    {
        freeMemMatrix(m1);
    }
}

void test_findSumOfMaxesOfPseudoDiagonal_positiveVerticalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 1, 3,
                    1, 8, 1,
                    7, 1, 2,
                    4, 5, 3,
                    1, 5, 7,
                    6, 4, 3
            },              6, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 6 + 4 + 5 + 7 + 3 + 1 + 3);

    {
        freeMemMatrix(m1);
    }
}

void test_findSumOfMaxesOfPseudoDiagonal_negativeVerticalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, -1, -3,
                    -1, -8, -1,
                    -7, -1, -2,
                    -4, -5, -3,
                    -1, -5, -7,
                    -6, -4, -3
            },                 6, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -6 + -1 + -3 + -5 + -1 + -1 + -3);

    {
        freeMemMatrix(m1);
    }
}

void test_findSumOfMaxesOfPseudoDiagonal_positiveSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 1, 3,
                    1, 8, 1,
                    7, 1, 2
            },              3, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 7 + 1 + 1 + 3);

    {
        freeMemMatrix(m1);
    }
}

void test_findSumOfMaxesOfPseudoDiagonal_negativeSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, -1, -3,
                    -1, -8, -1,
                    -7, -1, -2
            },                 3, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -7 + -1 + -1 + -3);

    {
        freeMemMatrix(m1);
    }
}

void test_findSumOfMaxesOfPseudoDiagonal_oneCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3,
                    1,
                    -7,
                    4,
                    -1,
                    6
            },        6, 1);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 1 + -7 + 4 + -1 + 6);

    {
        freeMemMatrix(m1);
    }
}

void test_findSumOfMaxesOfPseudoDiagonal_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, 1, -7, 4, -1, 6
            },                          1, 6);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 1 + -7 + 4 + -1 + 6);

    {
        freeMemMatrix(m1);
    }
}

void test_findSumOfMaxesOfPseudoDiagonal_oneElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3
            },         1, 1);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 0);

    {
        freeMemMatrix(m1);
    }
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonal_positiveHorizontalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_negativeHorizontalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_positiveVerticalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_negativeVerticalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_negativeSquareMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_positiveSquareMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_oneElement();
    test_findSumOfMaxesOfPseudoDiagonal_oneRow();
    test_findSumOfMaxesOfPseudoDiagonal_oneCol();
}

//---------------------------------------8----------------------------------

void test_getMinInArea_rectangleMatrixMinInBot() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2
            },                  3, 4);

    assert(getMinInArea(m) == 5);

    {
        freeMemMatrix(m);
    }
}

void test_getMinInArea_rectangleMatrixMinInMiddle() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    7, 12, 3, 4,
                    10, 11, 5, 1
            },                   3, 4);

    assert(getMinInArea(m) == 6);

    {
        freeMemMatrix(m);
    }
}

void test_getMinInArea_rectangleVerticalMatrix_1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 4,
                    7, 12, 3, 6,
                    10, 11, 5, 15,
                    11, 14, 13, 1,
                    16, 17, 18, 19
            },                     5, 4);

    assert(getMinInArea(m) == 1);

    {
        freeMemMatrix(m);
    }
}

void test_getMinInArea_rectangleVerticalMatrix_2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 4,
                    7, 12, 3, 6,
                    10, 14, 5, 11,
                    11, 1, 13, 15,
                    16, 17, 18, 20
            },                     5, 4);

    assert(getMinInArea(m) == 3);

    {
        freeMemMatrix(m);
    }
}

void test_getMinInArea_oneElem() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6
            },        1, 1);

    assert(getMinInArea(m) == 6);

    {
        freeMemMatrix(m);
    }
}

void test_getMinInArea_oneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6,
                    2,
                    8,
                    1,
                    7
            },        5, 1);

    assert(getMinInArea(m) == 2);

    {
        freeMemMatrix(m);
    }
}

void test_getMinInArea_oneCol() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6, 2, 8, 1, 7
            },                    1, 5);

    assert(getMinInArea(m) == 8);

    {
        freeMemMatrix(m);
    }
}

void test_getMinInArea() {
    test_getMinInArea_rectangleMatrixMinInMiddle();
    test_getMinInArea_rectangleVerticalMatrix_1();
    test_getMinInArea_rectangleVerticalMatrix_2();
    test_getMinInArea_rectangleMatrixMinInBot();
    test_getMinInArea_oneElem();
    test_getMinInArea_oneRow();
    test_getMinInArea_oneCol();
}

//---------------------------------------9-----------------------------------

void test_sortByDistances_somePoints() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    10, 11, 5, 1,
                    7, 12, 3, 4
            },                  3, 4);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    7, 12, 3, 4,
                    10, 11, 5, 1
            },                   3, 4);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortByDistances_somePoints2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    8, 9, 10, 11,
                    0, 1, 2, 3,
                    4, 5, 6, 7
            },                  3, 4);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    0, 1, 2, 3,
                    4, 5, 6, 7,
                    8, 9, 10, 11
            },                   3, 4);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortByDistances_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    8, 9, 10, 11
            },                   1, 4);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    8, 9, 10, 11
            },                   1, 4);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortByDistances_oneCols() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    11,
                    9,
                    10,
                    2
            },        4, 1);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2,
                    9,
                    10,
                    11
            },         4, 1);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortByDistances_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2
            },        1, 1);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2
            },        1, 1);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_sortByDistances() {
    test_sortByDistances_somePoints2();
    test_sortByDistances_somePoints();
    test_sortByDistances_oneCols();
    test_sortByDistances_oneElem();
    test_sortByDistances_oneRow();
}

//--------------------------------------10-----------------------------------

void test_countEqClassesByRowsSum_verticalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1,
                    2, 7,
                    5, 4,
                    4, 3,
                    1, 6,
                    8, 0
            },           6, 2);

    assert(countEqClassesByRowsSum(m1) == 3);

    {
        freeMemMatrix(m1);
    }
}

void test_countEqClassesByRowsSum_horizontalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2, 7,
                    5, 4, 4, 4,
                    1, 6, 8, 2
            },                 3, 4);

    assert(countEqClassesByRowsSum(m1) == 1);

    {
        freeMemMatrix(m1);
    }
}

void test_countEqClassesByRowsSum_onRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2, 7
            },                 1, 4);

    assert(countEqClassesByRowsSum(m1) == 1);

    {
        freeMemMatrix(m1);
    }
}

void test_countEqClassesByRowsSum_onCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2, 7
            },                 1, 4);

    assert(countEqClassesByRowsSum(m1) == 1);

    {
        freeMemMatrix(m1);
    }
}

void test_countEqClassesByRowsSum_onElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7
            },        1, 1);

    assert(countEqClassesByRowsSum(m1) == 1);

    {
        freeMemMatrix(m1);
    }
}

void test_countEqClassesByRowsSum() {
    test_countEqClassesByRowsSum_horizontalRectangleMatrix();
    test_countEqClassesByRowsSum_verticalRectangleMatrix();
    test_countEqClassesByRowsSum_onElement();
    test_countEqClassesByRowsSum_onRow();
    test_countEqClassesByRowsSum_onCol();
}

//--------------------------------------11-----------------------------------

void test_getNSpecialElement_rectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2
            },                  3, 4);

    assert(getNSpecialElement(m1) == 2);

    {
        freeMemMatrix(m1);
    }
}

void test_getNSpecialElement_rectangleMatrixHasNotSpecial() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 4,
                    1, 2, 1, 2
            },                 3, 4);

    assert(getNSpecialElement(m1) == 0);

    {
        freeMemMatrix(m1);
    }
}

void test_getNSpecialElement_rectangleVerticalMatrixHasNotSpecial() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 5,
                    4, 2, 3,
                    6, 4, 1,
                    2, 1, 2
            },              4, 3);

    assert(getNSpecialElement(m1) == 0);

    {
        freeMemMatrix(m1);
    }
}

void test_getNSpecialElement_allElementsEqual() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    5, 5, 5,
                    5, 5, 5,
                    5, 5, 5,
                    5, 5, 5
            },              4, 3);

    assert(getNSpecialElement(m1) == 0);

    {
        freeMemMatrix(m1);
    }
}

void test_getNSpecialElement_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1,
                    2,
                    3,
                    7
            },        4, 1);

    assert(getNSpecialElement(m1) == 1);

    {
        freeMemMatrix(m1);
    }
}

void test_getNSpecialElement_oneCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 7
            },                 1, 4);

    assert(getNSpecialElement(m1) == 4);

    {
        freeMemMatrix(m1);
    }
}

void test_getNSpecialElement() {
    test_getNSpecialElement_rectangleVerticalMatrixHasNotSpecial();
    test_getNSpecialElement_rectangleMatrixHasNotSpecial();
    test_getNSpecialElement_allElementsEqual();
    test_getNSpecialElement_rectangleMatrix();
    test_getNSpecialElement_oneRow();
    test_getNSpecialElement_oneCol();
}

//--------------------------------------12-----------------------------------

void test_swapPenultimateRow_squareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1
            },              3, 3);

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 4, 7,
                    7, 8, 1
            },              3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_swapPenultimateRow_twoRows() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    4, 5
            },           2, 2);

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 4,
                    4, 5
            },           2, 2);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_swapPenultimateRow_someMinimums() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    4, 2, 1,
                    4, 5, 4,
                    1, 6, 7
            },              3, 3);

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 2, 1,
                    4, 4, 1,
                    1, 6, 7
            },              3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_swapPenultimateRow_EMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },              3, 3);

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    1, 0, 0,
                    0, 0, 1
            },              3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    {
        freeMemMatrix(m1);
        freeMemMatrix(m2);
    }
}

void test_swapPenultimateRow() {
    test_swapPenultimateRow_squareMatrix();
    test_swapPenultimateRow_someMinimums();
    test_swapPenultimateRow_twoRows();
    test_swapPenultimateRow_EMatrix();
}

//--------------------------------------13-----------------------------------

void test_countNonDescendingRowsMatrices_SquareMatrixHasSuitableMatrix() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9
            },           4, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);

    {
        freeMemMatrices(ms, 4);
    }
}

void test_countNonDescendingRowsMatrices_RectangleMatrixHasSuitableMatrix() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 0, 1,
                    1, 3, 2,

                    1, 6, 7,
                    2, 2, 2,

                    -1, 0, 1,
                    2, 1, 2,

                    1, 2, 3,
                    1, 2, 3
            },              4, 2, 3);

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);

    {
        freeMemMatrices(ms, 4);
    }
}

void test_countNonDescendingRowsMatrices_oneRow() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 0, 1,

                    1, 6, 7,

                    -1, 0, 1,

                    1, 2, 3
            },              4, 1, 3);

    assert(countNonDescendingRowsMatrices(ms, 4) == 4);

    {
        freeMemMatrices(ms, 4);
    }
}

void test_countNonDescendingRowsMatrices_oneCol() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0,
                    0,
                    1,

                    1,
                    6,
                    7,

                    -1,
                    0,
                    1,

                    1,
                    2,
                    3
            },        4, 3, 1);

    assert(countNonDescendingRowsMatrices(ms, 4) == 4);

    {
        freeMemMatrices(ms, 4);
    }
}

void test_countNonDescendingRowsMatrices_oneElement() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0,

                    1,

                    -1,

                    1
            },        4, 1, 1);

    assert(countNonDescendingRowsMatrices(ms, 4) == 4);

    {
        freeMemMatrices(ms, 4);
    }
}

void test_countNonDescendingRowsMatrices() {
    test_countNonDescendingRowsMatrices_RectangleMatrixHasSuitableMatrix();
    test_countNonDescendingRowsMatrices_SquareMatrixHasSuitableMatrix();
    test_countNonDescendingRowsMatrices_oneElement();
    test_countNonDescendingRowsMatrices_oneRow();
    test_countNonDescendingRowsMatrices_oneCol();
}


//--------------------------------------14-----------------------------------

void test_countZeroRows_rectangleMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    4, 0, 1,
                    7, 0, 0,
                    0, 0, 0
            },              4, 3);

    assert(countZeroRows(m) == 2);

    {
        freeMemMatrix(m);
    }
}

void test_countZeroRows_squareZeroMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0
            },              3, 3);

    assert(countZeroRows(m) == 3);

    {
        freeMemMatrix(m);
    }
}

void test_countZeroRows_oneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0,
                    0,
                    1
            },        3, 1);

    assert(countZeroRows(m) == 2);

    {
        freeMemMatrix(m);
    }
}

void test_countZeroRows_oneCol() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 1
            },              1, 3);

    assert(countZeroRows(m) == 0);

    {
        freeMemMatrix(m);
    }
}

void test_countZeroRows_oneColZero() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0
            },              1, 3);

    assert(countZeroRows(m) == 1);

    {
        freeMemMatrix(m);
    }
}

void test_countZeroRows_oneElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0
            },        1, 1);

    assert(countZeroRows(m) == 1);

    {
        freeMemMatrix(m);
    }
}

void test_countZeroRows() {
    test_countZeroRows_squareZeroMatrix();
    test_countZeroRows_rectangleMatrix();
    test_countZeroRows_oneColZero();
    test_countZeroRows_oneElement();
    test_countZeroRows_oneRow();
    test_countZeroRows_oneCol();
}

//--------------------------------------15-----------------------------------

void test_getMatrixNormal_rectangleMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, -7, 11,
                    4, 13, 10,
                    7, -17, 16,
                    12, 1, -56
            },                 4, 3);

    assert(getMatrixNormal(m) == 56);

    {
        freeMemMatrix(m);
    }
}

void test_getMatrixNormal_squareZeroMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0
            },              3, 3);

    assert(getMatrixNormal(m) == 0);

    {
        freeMemMatrix(m);
    }
}

void test_getMatrixNormal_oneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2,
                    0,
                    1
            },        3, 1);

    assert(getMatrixNormal(m) == 2);

    {
        freeMemMatrix(m);
    }
}

void test_getMatrixNormal_oneCol() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 1
            },              1, 3);

    assert(getMatrixNormal(m) == 1);

    {
        freeMemMatrix(m);
    }
}

void test_getMatrixNormal_oneColZero() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 1, -12
            },                1, 3);

    assert(getMatrixNormal(m) == 12);

    {
        freeMemMatrix(m);
    }
}

void test_getMatrixNormal_oneElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -12
            },          1, 1);

    assert(getMatrixNormal(m) == 12);

    {
        freeMemMatrix(m);
    }
}

void test_getMatrixNorm() {
    test_getMatrixNormal_squareZeroMatrix();
    test_getMatrixNormal_rectangleMatrix();
    test_getMatrixNormal_oneElement();
    test_getMatrixNormal_oneColZero();
    test_getMatrixNormal_oneRow();
    test_getMatrixNormal_oneCol();
}
