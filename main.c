#include <stdio.h>

int main() {
    char c = 'C';
    char m = 'M';
    char y = 'Y';

    int i, j;
    scanf("%d %d", &i, &j);

    long long count = i * j;

    for (size_t j1 = 0; j1 < count; j1++) {
        char x;
        scanf(" %s", &x);

        if (x == c || x == m || x == y)
            goto rgb;
    }

    printf("#Black&White");
    return 0;

    rgb:
    printf("#Color");

    return 0;
}