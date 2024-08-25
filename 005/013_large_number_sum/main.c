#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define divisor 10 000 000 000
#define NR_LENGTH 4
#define NR_COUNT 4

char numbers[NR_COUNT][NR_LENGTH + 1];

void readInFile(FILE *file) {
    for(int i = 0; i < NR_COUNT; ++i) {
        getline(numbers[i], NR_LENGTH +1 , file);
        printf("Number: %s\n", numbers[i]);
    }
}

int64_t large_sum(FILE *file) {
    readInFile(file);

    int64_t sum = 0;

    for(int64_t offset = NR_LENGTH - 1; offset >= 0; --offset) {
        for(int64_t number = 0; number < NR_COUNT; ++number) {
            // Substracts the acsii value of the number by the ascii value of 0, resulting in the number in its integer form
            int64_t nr = numbers[number][offset];
            //printf("[%c]", numbers[number][offset]);
            sum += nr;
            //printf("%ld ", sum);
        }
        //printf("\nSum:%ld\n", sum);
        sum /= 10;
    }

    return sum;
}

int main(void) {
    FILE *fptr;
    //fptr = fopen("numbers.txt", "r");
    fptr = fopen("numbers_short.txt", "r");
    int64_t result = large_sum(fptr);
    printf("Large sum: %ld * 10e40\n", result);
    fclose(fptr);
    return EXIT_SUCCESS;
}
