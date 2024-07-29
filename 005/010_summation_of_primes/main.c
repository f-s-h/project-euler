#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

uint64_t* sieve;

// returns true, when a number is a prime number
bool isPrime(uint64_t n) {
    for (uint64_t i = 2; i <= n>>1; ++i) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

// Sieve of Erathosthenes
void init_sieve_of_erathosthenes(uint64_t n) {
    sieve = malloc(n * sizeof(uint64_t));

    // Initialize sieve
    for (uint64_t i = 1; i <= n; ++i) {
        sieve[i] = i;
    }

    sieve[1] = 0;

    for(uint64_t i = 1; i <= n; ++i) {
        if(sieve[i] != 0) {
            uint64_t c = 2 * i;
            while (c <= n) {
                sieve[c] = 0;
                c += i;
            }
        }
    }
}

void printPrimes(uint64_t n) {
    for(uint64_t i = 0; i < n; ++i) {
        if(sieve[i] != 0) {
            printf("%ld\n", sieve[i]);
        }
    }
}

bool isPrime_sieve_of_erthosthenes(uint64_t n) {
    return sieve[n] != 0;
}

uint64_t summation_of_primes(uint64_t n) {
    // we start with 3 and add 2 in each step, as prime numbers (except 2) cannot be even
    uint64_t sum = 2;
    uint64_t cur = 3;


    while(cur < n) {
        if(isPrime_sieve_of_erthosthenes(cur)) {
            sum+=cur;
        }
        cur+=2;
    }

    return sum;
}

int main(void) {
    uint64_t n = 2000000;
    init_sieve_of_erathosthenes(n);
    uint64_t result = summation_of_primes(n);
    printf("Summation of primes from 1 to %ld: %ld\n", n, result);
    return EXIT_SUCCESS;
}
