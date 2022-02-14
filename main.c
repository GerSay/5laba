#include "libs/data_structures/matrix/matrix.h"
int main() {
//    matrix m;
//    inputAndCreateMatrix(&m);

    int a[] = {1, 2, 4};
    int b[] = {1, 2, 4};
    printf("%d", memcmp(a, b, sizeof(int) * 3));

    return 0;
}