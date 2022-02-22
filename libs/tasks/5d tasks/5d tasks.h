#ifndef WORKPROJECT_5D_TASKS_H
#define WORKPROJECT_5D_TASKS_H

#include "../../data_structures/matrix/matrix.h"

void swapRowsSquareMatrixWithMaxMinElement(matrix m);

void sortRowsByMaxElement(matrix m);

void sortColsByMinElement(matrix m);

void getSquareOfMatrixIfSymmetric(matrix *m);

void transposeIfMatrixHasEqualSumOfRows(matrix m, size_t nRows, size_t nCols);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

long long findSumOfMaxesOfPseudoDiagonal(matrix m);

int getMinInArea(matrix m);

void sortByDistances(matrix m);

int countEqClassesByRowsSum(matrix m);

int getNSpecialElement(matrix m);

void swapPenultimateRow(matrix m, size_t n);

int countNonDescendingRowsMatrices(matrix *ms, size_t nMatrix);

void printMatrixWithMaxZeroRows(matrix *ms, size_t nMatrix);

void printMatrixWithNormal(matrix *ms, size_t nMatrix);



#endif //WORKPROJECT_5D_TASKS_H
