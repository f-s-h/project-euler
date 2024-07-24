#include <stdio.h>
#include <stdlib.h>

// Find the sum of even fibonacci numbers up to n
int sumEvenFibonacci(int n) {
    int fib_0 = 1;
    int fib_1 = 2;
    int sum = fib_1;

    while(fib_1 < n) {
        int temp = fib_0 + fib_1;

        if(temp % 2 == 0) {
            sum += temp;
        }

        fib_0 = fib_1;
        fib_1 = temp;
    }
    return sum;
}

int main(void) {
    int n = 4000000;
    int sum = sumEvenFibonacci(n);
    printf("Sum of even Fibonacci numbers not exceeding %d: %d\n", n, sum);
    return EXIT_SUCCESS;
}
