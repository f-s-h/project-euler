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

int maximumPathSumBruteForceRec(int **triangle, int maxLength, int offsetRow, int offsetColumn) {
    if(offsetRow == maxLength - 1) {
        return triangle[offsetRow][offsetColumn];
    }
    int left = maximumPathSumBruteForceRec(triangle, maxLength, offsetRow + 1, offsetColumn);;
    int right = maximumPathSumBruteForceRec(triangle, maxLength, offsetRow + 1, offsetColumn + 1);;
    return (left > right ? left : right) + triangle[offsetRow][offsetColumn];
}

int maximumPathSumBruteForce(int **triangle, int maxLength) {
    return maximumPathSumBruteForceRec(triangle, maxLength, 0, 0);
}



int main(void) {
    FILE* file = fopen("triangle.txt", "r");
    int maxLength = 15;
    int** triangle = readInTriangle(file, maxLength);
    printTriangle(triangle, maxLength);
    fclose(file);

    int result = maximumPathSumBruteForce(triangle, maxLength);
    printf("Maximum path sum: %d\n", result);
    return EXIT_SUCCESS;
}
