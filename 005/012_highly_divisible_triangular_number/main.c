#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/*
int64_t numberDivisors(int64_t n) {
    int64_t nr = 1;
    for(int64_t i = 1; i*i <= n; ++i) {
        if(n % i == 0) {
            nr+=2;
        }
        if(i*i == n) {
            nr--;
        }
    }
    return nr;
}

int64_t triangularNumber(int64_t index) {
    return index*(index + 1) / 2;
}

int64_t firstTriangleNumberWithNDivisors(int64_t n) {
    int64_t lower_bound = 0;
    int64_t upper_bound = n * n;
    int64_t triangular_number = 0;
    int64_t bot = 0;

    // We are searching for the first number that has a minimum of n divisors.
    int64_t cur = upper_bound / 2;
    while(true) {
        triangular_number = triangularNumber(cur);
        bot = triangularNumber(cur - 1);

        int64_t nrDivisorsCur = numberDivisors(triangular_number);
        printf("Triangular number: %ld (%ld) with %ld divisors.\n", triangular_number, cur, nrDivisorsCur);
        int64_t nrDivisorsBot = numberDivisors( bot);
        printf("Triangular number bot: %ld with %ld divisors.\n", bot, nrDivisorsBot);
        if(nrDivisorsCur >= n) {
            if(nrDivisorsBot < n) {
                break;
            }
            else {
                upper_bound = cur - 1;
                cur = (upper_bound - lower_bound)/2 + lower_bound;
            }
        }
        else {
            lower_bound = cur;
            cur = (upper_bound - lower_bound)/2 + lower_bound;
        }
    }

    return triangular_number;
}
*/

int64_t numberDivisors(int64_t n) {
    int nrDivisors = 0;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            nrDivisors++;
        }
    }
    return nrDivisors;
}

int64_t firstTriangularNumberWithNDivisors(int64_t n) {
    int64_t triangularNumber = 1;
    int64_t i = 2;
    while(numberDivisors(triangularNumber) <= n) {
        //printf("%ld: %ld\n", triangularNumber, numberDivisors(triangularNumber));
        triangularNumber = (i * (i + 1)) / 2;
        i++;
    }
    return triangularNumber;
}

int main(void) {
    int64_t n = 500;
    int64_t result = firstTriangularNumberWithNDivisors(n);
    printf("First triangular number with %ld divisors: %ld\n", n, result);
    return EXIT_SUCCESS;
}
