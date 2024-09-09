#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Very ugly, but simplest
int coinSums(int n) {
    //pounds to pence
    n = n * 100;
    int result = 0;

    for(int a = 0; a <= n; ++a) {
        for(int b = 0; b <= n / 2; ++b) {
            for(int c = 0; c <= n / 5; ++c) {
                for(int d = 0; d <= n / 10; ++d) {
                    for(int e = 0; e <= n / 20; ++e) {
                        for(int f = 0; f <= n / 50; ++f) {
                            for(int g = 0; g <= n / 100; ++g) {
                                for(int h = 0; h <= n / 200; ++h) {
                                    int cur = 1*a + 2*b + 5*c + 10*d + 20*e + 50*f + 100*g + 200*h;

                                    if(cur == n) {
                                        result++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return result;
}

int main(void) {
    int n = 2;

    int result = coinSums(n);
    printf("Different ways to make %d pounds: %d\n", n, result);
    return EXIT_SUCCESS;
}
