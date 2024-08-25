#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define THRESH 2048

int64_t getCollatzLength(int64_t n) {
  int64_t length = 3;
  int64_t minValue = 4;

  while (n > minValue) {
    if(n % 2 == 0) {
        n /= 2;
    }
    else {
        n = 3 * n + 1;
    }
    length++;
  }

  return length;
}

int64_t longestCollatzSequence(int64_t upperBound) {
    int64_t minLength = 3;
    int64_t minValue = 4;
    int64_t longestSequence = minValue;
    int64_t longestLength = minLength;

    for(int64_t i = minLength; i < upperBound; i++) {
        int64_t currentLength = getCollatzLength(i);
        if(currentLength > longestLength) {
            longestSequence = i;
            longestLength = currentLength;
        }
    }

    return longestSequence;
}

int main(void) {
    int64_t n = 1000000;
    int64_t result = longestCollatzSequence(n);
    printf("Longest collatz sequence below %ld: %ld\n", n, result);
    return EXIT_SUCCESS;
}
