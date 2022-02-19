#ifndef WORKPROJECT_MATRIX_H
#decfine WORKPROJECT_MATRIX_H

#include "../../algorithms/array/array.h"
#include "../../algorithms/base/base.h"

#include <stdbool.h>
#include <malloc.h>
#include <string.h>

typedef struct matrix {
    int **values;
    size_t nRows;
    size_t nCols;
} matrix;

typedef struct position {
    size_t rowIndex;
    size_t colIndex;
} position;

matrix getMemMatrix(size_t nRows, size_t nCols);

matrix *getMemArrayOfMatrices(size_t nMatrices, size_t nRows, size_t nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, size_t nMatrices);

void inputMatrix(matrix m);

void outputMatrix(matrix m);

void inputMatrices(matrix *ms, size_t nMatrices);

void outputMatrices(matrix *ms, size_t nMatrices);

void inputAndCreateMatrix(matrix *m);

void swapRows(matrix m, size_t i1, size_t i2);

void swapColumns(matrix m, size_t j1, size_t j2);

void insertionSortRowsMatrixByRowCriteria(matrix m, int (* criteria) (int *, size_t));

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, size_t));

bool isSquareMatrix(matrix m);

bool twoMatricesEqual(matrix m1, matrix m2);

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

void transposeSquareMatrix(matrix m);

void transposeMatrix(matrix *m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols);

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);

void swapRowsSquareMatrixWithMaxMinElement(matrix m);

int getMax(int *a, size_t n);

void sortRowsByMaxElement(matrix m);

int getMin(int *a, size_t n);

void sortColsByMinElement(matrix m);

matrix mulMatrices(matrix m1, matrix m2);

void getSquareOfMatrixIfSymmetric(matrix *m);

size_t find(long long *arr, size_t size, int el);

bool isUnique(long long *arr, size_t size);

long long getSum(int *a, size_t n);

void transposeIfMatrixHasEqualSumOfRows(matrix m, size_t nRows, size_t nCols);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

int max(int a, int b);

int findDiagonalMax(matrix m, size_t i, size_t k);

long long findSumOfMaxesOfPseudoDiagonal(matrix m);

int min(int x, int y);

int getMinInArea(matrix m);

#endif //WORKPROJECT_MATRIX_H
