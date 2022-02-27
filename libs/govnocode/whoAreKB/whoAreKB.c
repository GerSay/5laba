#include "whoAreKB.h"


int isItPossibleToDoBetter() {
    int c1 = getchar();
    int c2 = getchar();
    int shift = 0;
    int num = 0;
    printf("%c %c\n", (char) c1, (char) c2);

    while (c1 || c2) {
        num |= (c1 & 1) << (shift + 1);
        num |= (c2 & 1) << shift;
        shift += 2;
        c1 >>= 1;
        c2 >>= 1;
    }

    printf("%d", num);

    return 0;
}