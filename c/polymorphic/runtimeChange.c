#include <stdio.h>

int tripple(int a) {
    return 3 * a;
}

int square(int a) {
    return a * a;
}

void transform(int array[], size_t len, int (*fun)(int)) {
    size_t i = 0;
    for(; i < len; ++i)
        array[i] = fun(array[i]);
}

int main() {
    int array[3] = {1, 2, 3};
    transform(array, 3, &tripple);
    transform(array, 3, &square);

    size_t i = 0;
    for (; i < 3; ++i)
        printf("%d ", array[i]);

    return 0;
}
