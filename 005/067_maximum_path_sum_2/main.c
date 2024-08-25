#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void printTriangle(int** triangle, int maxLength) {
    for(int i = 0; i < maxLength; i++) {
        for(int j = 0; j < i+1; j++) {
            printf("%2d ", triangle[i][j]);
        }
        printf("\n");
    }
}


int** readInTriangle(FILE* file, int maxLength) {
    char ch[maxLength * 4];
    int** triangle = malloc(sizeof(int*) * maxLength);
    for(int i = 0; i < maxLength; i++) {
      triangle[i] = malloc(sizeof(int) * (i + 1));
    }

    int row = 0;
    while ((fgets(ch, maxLength * 4, file)) != NULL) {
        int index = 0;
        for (int i = 0; i < maxLength * 4; i++) {
            if(ch[i] == '\00' || ch[i] == '\n') {
                break;
            }
            else if(ch[i] == ' ') {
                index++;
            }
            else {
                triangle[row][index] *= 10;
                triangle[row][index] += ch[i] - '0';
            }
        }
        row++;
    }

    return triangle;
}

int maximumPathSum(int **triangle, int maxLength) {
    for(int i = maxLength - 2; i >= 0; i--) {
        for(int j = 0; j < i+1; j++) {
            int left = triangle[i+1][j];
            int right = triangle[i+1][j + 1];
            triangle[i][j] += (left > right ? left: right);
        }
    }
    return triangle[0][0];
}


int main(void) {
    FILE* file = fopen("triangle.txt", "r");
    int maxLength = 100;
    int** triangle = readInTriangle(file, maxLength);
    printTriangle(triangle, maxLength);
    fclose(file);

    int result = maximumPathSum(triangle, maxLength);
    printf("Maximum path sum: %d\n", result);
    return EXIT_SUCCESS;
}
