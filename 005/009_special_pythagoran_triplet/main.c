#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int special_pythagoras(int n) {
    for(int a = 1; a < n; ++a) {
        for (int b = 1; b < a && b <= (n - a); ++b) {
            int c = n - (a + b);
            if (a * a + b * b == c * c) {
                return a * b * c;
            }
        }
    }
    return -1;
}

int main(void) {
    int n = 1000;
    int result = special_pythagoras(n);
    printf("Special pythagoras of %d: %d\n", n, result);
    return EXIT_SUCCESS;
}
