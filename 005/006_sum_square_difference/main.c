#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sum_of_squares(int n) {
  int sum = 0;

  for(int i = 1; i <= n; i++) {
    sum += i * i;
  }

  return sum;
}

int square_of_sum(int n) {
  int sum = (n * (n + 1)) / 2;
  int square = sum * sum;
  return square;
}

int sum_square_difference(int n) {
  int sumSquare = sum_of_squares(n);
  int squareSum = square_of_sum(n);

  printf("sumSquare: %d, squareSum %d\n", sumSquare, squareSum);

  int difference = squareSum - sumSquare;

  return difference;
}

int main(void) {
    int number = 100;
    int result = sum_square_difference(number);
    printf("Sum Square Difference: %d\n", result);
    return EXIT_SUCCESS;
}
