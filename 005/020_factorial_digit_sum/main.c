#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int cross_sum(int64_t n) {
    int result = 0;

    while(n > 0) {
        result += n % 10;
        n = n / 10;
    }

    return result;
}

int sum_digits_factorial(int64_t n) {
    int64_t result = 0;
    for(int i = 1; i<=n; ++i) {
        result *= n;
        if(result % 10 == 0) {
            result /= 10;
        }
    }
    return cross_sum(result);
}

int main(void) {
    int64_t n = 10;
    int result = sum_digits_factorial(n);
    printf("Sum of %ld!: %d\n", n, result);
    return EXIT_SUCCESS;
}
