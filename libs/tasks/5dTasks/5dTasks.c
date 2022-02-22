#include "5dTasks.h"

void errorSquareMatrixForTasks() {
    fprintf(stderr, "Matrix is not square");
    exit(4);
}

//---------------------------------------1-----------------------------------

void swapRowsSquareMatrixWithMaxMinElement(matrix m) {
    position min = getMinValuePos(m);
    position max = getMaxValuePos(m);
    swapRows(m, min.rowIndex, max.rowIndex);
}

//---------------------------------------2-----------------------------------

int getMax(int * const a, size_t n) {
    int max = a[0];
    for (size_t i = 0; i < n; i++)
        max = max < a[i] ? a[i] : max;

    return max;
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

//---------------------------------------3-----------------------------------

int getMin(int *a, size_t n) {
    int min = a[0];
    for (size_t i = 0; i < n; i++)
        min = min > a[i] ? a[i] : min;

    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

//---------------------------------------4-----------------------------------

matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows)
        errorSquareMatrixForTasks();

    matrix m = getMemMatrix(m1.nRows, m2.nCols);
    for (size_t iRow = 0; iRow < m1.nRows; iRow++)
        for (size_t iCol = 0; iCol < m2.nCols; iCol++) {
            m.values[iRow][iCol] = 0;
            for (size_t i = 0; i < m1.nCols; i++)
                m.values[iRow][iCol] += m1.values[iRow][i] * m2.values[i][iCol];
        }

    return m;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

//---------------------------------------5-----------------------------------

size_t find(long long *arr, size_t size, int element) {
    for (size_t i = 0; i < size; i++)
        if (arr[i] == element)
            return i;

    return size;
}

bool isUnique(long long *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        const size_t pos = find(arr, size, (int) arr[i]);
        if (pos != i && pos != size)
            return 0;
    }

    return 1;
}

long long getSum(int *a, size_t n) {
    long long sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

void transposeIfMatrixHasEqualSumOfRows(matrix m) {
    long long *rSum = malloc(m.nRows * sizeof(long long));
    for (size_t i = 0; i < m.nRows; i++)
        rSum[i] = getSum(m.values[i], m.nCols);

    if (isUnique(rSum, m.nRows))
        transposeSquareMatrix(m);
}

//---------------------------------------6-----------------------------------

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    return isSquareMatrix(m1) && isEMatrix(mulMatrices(m1, m2));
}

//---------------------------------------7-----------------------------------

int _max(int a, int b) {
    return a > b ? a : b;
}

int findDiagonalMax(matrix m, size_t i, size_t k) {
    size_t iRow = i;
    size_t iCol = k;
    int max = m.values[iRow][iCol];
    while (iCol < m.nCols && iRow < m.nRows) {
        if (m.values[iRow][iCol] > max)
            max = m.values[iRow][iCol];
        iRow++;
        iCol++;
    }

    return max;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long sum = 0;
    for (size_t iShift = m.nRows - 1; iShift > 0; iShift--)
        sum += findDiagonalMax(m, iShift, 0);

    for (size_t kShift = 1; kShift < m.nCols; kShift++)
        sum += findDiagonalMax(m, 0, kShift);

    return sum;
}

//---------------------------------------8-----------------------------------

int _min(int x, int y) {
    return x < y ? x : y;
}

int getMinInArea(matrix m) {
    position maxPos = getMaxValuePos(m);
    int minEl = m.values[maxPos.rowIndex][maxPos.colIndex];
    for (size_t iRow = maxPos.rowIndex; iRow != -1; iRow--) {
        const size_t dist = maxPos.rowIndex - iRow;
        const size_t start = _max(0, (int)(maxPos.colIndex - dist));
        const size_t end = _min((int)m.nCols - 1, (int)(maxPos.colIndex + dist));
        minEl = getMin(m.values[iRow] + start, end - start + 1);
    }

    return minEl;
}

//---------------------------------------9-----------------------------------

float getDistance(int *a, size_t n) {
    float distance = 0;
    for (size_t i = 0; i < n; i++)
        distance += (float) (a[i] * a[i]);

    return sqrtf(distance);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, size_t)) {
    float rowsCriteria[m.nRows];
    for (size_t i = 0; i < m.nRows; i++)
        rowsCriteria[i] = criteria(m.values[i], m.nCols);

    for (size_t i = 1; i < m.nRows; i++)
        for (size_t j = i; j > 0 && rowsCriteria[j - 1] > rowsCriteria[j]; j--) {
            swapU(&rowsCriteria[j - 1], &rowsCriteria[j], sizeof(float));
            swapRows(m, j, j - 1);
        }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

//---------------------------------------10----------------------------------

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2)
        return -1;
    return arg1 > arg2;
}

int countNUnique(long long *a, size_t n) {
    if (n == 1)
        return 1;

    qsort(a, n, sizeof(long long), cmp_long_long);

    int counterOfUnique = 1;
    size_t i = 1;
    while (i < n) {
        if (a[i] != a[i - 1])
            counterOfUnique++;
        i++;
    }

    return counterOfUnique;
}

int countEqClassesByRowsSum(matrix m) {
    long long rowSums[m.nRows];
    for (size_t i = 0; i < m.nRows; i++)
        rowSums[i] = getSum(m.values[i], m.nCols);

    return countNUnique(rowSums, m.nRows);
}

//---------------------------------------11----------------------------------

int getNSpecialElement(matrix m) {
    int countEl = 0;
    for (size_t j = 0; j < m.nCols; j++) {
        int specialEl = m.values[0][j];
        int sum = 0;
        for (size_t i = 1; i < m.nRows; i++)
            if (m.values[i][j] > specialEl) {
                sum += specialEl;
                specialEl = m.values[i][j];
            } else
                sum += m.values[i][j];

        if (specialEl > sum)
            countEl++;
    }

    return countEl;
}

//---------------------------------------12----------------------------------

position getLeftMin(matrix m) {
    int min = m.values[0][0];
    position minPos = {0, 0};

    for (size_t i = 0; i < m.nCols; i++)
        for (size_t j = 0; j < m.nRows; j++)
            if (m.values[j][i] < min) {
                min = m.values[j][i];
                minPos.colIndex = i;
                minPos.rowIndex = j;
            }

    return minPos;
}

void penultimateError() {
    fprintf(stderr, "Has not penultimate row.");
    exit(5);
}

void swapPenultimateRow(matrix m) {
    if (m.nRows < 2)
        penultimateError();

    int col[m.nRows];
    position min = getLeftMin(m);

    for (size_t i = 0; i < m.nRows; i++)
        col[i] = m.values[i][min.colIndex];

    memcpy(m.values[m.nRows - 2], col, sizeof(int) * m.nCols);
}

//---------------------------------------13----------------------------------

bool isNonDescendingSorted(int *a, size_t n) {
    for (size_t i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return 0;
    return 1;
}

bool hasAllNonDescendingRows(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return 0;
    return 1;
}

int countNonDescendingRowsMatrices(matrix *ms, size_t nMatrix) {
    int count = 0;
    for (size_t k = 0; k < nMatrix; k++)
        if (hasAllNonDescendingRows(ms[k]))
            count++;

    return count;
}

//---------------------------------------14----------------------------------

int countValues(const int *a, size_t n, size_t value) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
        if (a[i] == value)
            count++;

    return count;
}

int countZeroRows(matrix m) {
    int countZero = 0;
    for (size_t i = 0; i < m.nRows; i++)
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            countZero++;

    return countZero;
}

void printMatrixWithMaxZeroRows(matrix *ms, size_t nMatrix) {
    int zeroCount[nMatrix];
    for (size_t i = 0; i < nMatrix; i++)
        zeroCount[i] = countZeroRows(ms[i]);

    int max = getMax(zeroCount, nMatrix);

    for (size_t i = 0; i < nMatrix; i++)
        if (zeroCount[i] == max)
            outputMatrix(ms[i]);
}

//---------------------------------------15----------------------------------

int getMatrixNormal(matrix m) {
    int normal = abs(m.values[0][0]);
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j > m.nCols; j++) {
            int absNormal = abs(m.values[i][j]);
            normal = normal < absNormal ? absNormal : normal;
        }

    return normal;
}

void printMatrixWithNormal(matrix *ms, size_t nMatrix) {
    int normals[nMatrix];
    for (size_t i = 0; i < nMatrix; i++)
        normals[i] = getMatrixNormal(ms[i]);

    int min = getMin(normals, nMatrix);

    for (size_t i = 0; i < nMatrix; i++)
        if (normals[i] == min)
            outputMatrix(ms[i]);
}
