#include <stdio.h>
#include <stdlib.h>

// Find the sum of the multiples from 3 and 5 up to n
int sumMultiples3and5(int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 3 == 0) {
            sum += i;
        }
        // Due to the else if, if i is a multiple of 3 AND 5, it is only added one time.
        else if (i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

int main(void) {
    int n = 1000;
    int sum = sumMultiples3and5(n);
    printf("Sum of multiples from 3 and 5 up to %d: %d\n", n, sum);
    return EXIT_SUCCESS;
}
