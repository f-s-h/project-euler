#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getReverseNumber(int n) {
  int reverse = 0;

  while(n > 0) {
    reverse = reverse * 10 + n % 10;
    n /= 10;
  }

  return reverse;
}

bool isPalindrome(int n) {
    return n == getReverseNumber(n);
}

int largest_palindrome(int n) {
  int largest = 0;

  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j++) {
        int product = i * j;
        if(isPalindrome(product)) {
            largest = largest > product ? largest : product;
        }
    }
  }

  return largest;
}

int main(void) {
    int upper_bound = 999;
    int result = largest_palindrome(upper_bound);
    printf("Larges palindrome: %d\n", result);
    return EXIT_SUCCESS;
}
