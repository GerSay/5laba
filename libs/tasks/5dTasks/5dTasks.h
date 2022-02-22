#ifndef WORKPROJECT_5DTASKS_H
#define WORKPROJECT_5DTASKS_H

#include "../../data_structures/matrix/matrix.h"

//1
void swapRowsSquareMatrixWithMaxMinElement(matrix m);

//2
void sortRowsByMaxElement(matrix m);

//3
void sortColsByMinElement(matrix m);

//4
void getSquareOfMatrixIfSymmetric(matrix *m);

//5
void transposeIfMatrixHasEqualSumOfRows(matrix m);

//6
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

//7
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

//8
int getMinInArea(matrix m);

//9
void sortByDistances(matrix m);

//10
int countEqClassesByRowsSum(matrix m);

//11
int getNSpecialElement(matrix m);

//12
void swapPenultimateRow(matrix m);

//13
int countNonDescendingRowsMatrices(matrix *ms, size_t nMatrix);

//14
int countZeroRows(matrix m);

void printMatrixWithMaxZeroRows(matrix *ms, size_t nMatrix);

//15
int getMatrixNormal(matrix m);

void printMatrixWithNormal(matrix *ms, size_t nMatrix);


#endif //WORKPROJECT_5DTASKS_H
