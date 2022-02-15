#include "libs/data_structures/matrix/matrix.h"

int main() {
    matrix m;
    inputAndCreateMatrix(&m);

    swapRowsSquareMatrixWithMaxMinElement(m);

    outputMatrix(m);
    freeMemMatrix(m);

    return 0;
}