#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int cross_sum(int n) {
    int t = n;
    int result = 0;

    while(n > 0) {
        result += n % 10;
        n = n / 10;
    }

    printf("Cross sum of %d: %d\n", t, result);

    return result;
}

int sum_digits_factorial(int n) {
    int sum = 1;
    int rec = 8;
    int rec_gap = 1;
    int factor = 1;

    int cur = rec;
    int cur_gap = rec_gap;

    for(int i = 1; i <= n; ++i) {
        printf("||%d||", i);
        int temp = sum * i;
        int add = 0;
        if(i >= rec + rec_gap) {
            add = 9 * rec_gap * ((factor % 2) + 1);
            printf("add:%d|factor:%d|",add, factor);

            if(i == cur + cur_gap) {
                rec = cur;
                rec_gap = cur_gap;
                if(cur_gap % 2 == 0) {
                    factor = factor % 2 + 1;
                }
                cur_gap = (cur_gap % 2) + 1;
                cur = i + cur_gap;
            }
        }
        sum = cross_sum(temp) + add;
    }

    return sum;
}

int main(void) {
    int n = 100;
    int result = sum_digits_factorial(n);
    printf("Sum of %d!: %d\n", n, result);
    return EXIT_SUCCESS;
}
