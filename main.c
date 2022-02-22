#include "libs/algorithms/base/base.h"

int main() {
    int x = 5;
    int y = 6;
    printf("%d %d", (int) max(&x, &y), (int) min(&x, &y));

    return 0;
}