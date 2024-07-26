#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// returns true, when a number is a prime number
bool isPrime(int n) {
    for (int i = 2; i <= n>>1; ++i) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int nth_prime(int n) {
    // we start with 3 and add 2 in each step, as prime numbers (except 2) cannot be even
    int nr = 1;
    int cur = 3;


    while(nr < n) {
        if(isPrime(cur)) {
            nr++;
        }
        cur+=2;
    }

    return cur - 2;
}

int main(void) {
    int n = 10001;
    int result = nth_prime(n);
    printf("Smallest multiple from 1 to %d: %d\n", n, result);
    return EXIT_SUCCESS;
}
