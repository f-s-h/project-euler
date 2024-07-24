#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// Alternative dict with primes?
// returns true, when a number is a prime number
bool isPrime(uint64_t n) {
    for (uint64_t i = 2; i < n>>2; ++i) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

// Calculate the largest prime factor of n.
uint64_t largestPrimeFactor(uint64_t n) {
    for(uint64_t i = 2; i <= n; ++i) {
        if(n % i == 0 && isPrime(i)) {
            if(n > i) {
                return largestPrimeFactor(n / i);
            }
            else {
                return i;
            }
        }
    }
    return -1;
}

int main(void) {
    uint64_t n = 600851475143;
    uint64_t result = largestPrimeFactor(n);
    printf("Largest prime factor of %ld: %ld\n", n, result);
    return EXIT_SUCCESS;
}
