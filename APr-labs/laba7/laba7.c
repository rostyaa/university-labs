#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define MATRIX_SIZE 10

void printMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int isLocalMinimum(int matrix[MATRIX_SIZE][MATRIX_SIZE], int i, int j) {
    int di[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dj[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int k = 0; k < 8; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni >= 0 && ni < MATRIX_SIZE && nj >= 0 && nj < MATRIX_SIZE && matrix[ni][nj] <= matrix[i][j]) {
            return 0;
        }
    }
    return 1;
}

int main() 
{   
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE* file, * textOutput, * binaryOutput;
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int localMinCount = 0;
    int sumAboveDiagonal = 0;

    file = fopen("input.txt", "r");
    textOutput = fopen("output.txt", "w");
    binaryOutput = fopen("output.bin", "wb");

    char filename[260];
    printf("Введіть назву файлу для читання матриці: ");
    scanf("%259s", filename);

    if (!file || !textOutput || !binaryOutput) {
        printf("Помилка відкриття файлів\n");
        return 1;
    }

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                printf("Помилка читання матриці\n");
                return 1;
            }
        }
    }

    fclose(file);
    printf("Вихідна матриця:\n");
    printMatrix(matrix, MATRIX_SIZE);

    for (int i = 1; i < MATRIX_SIZE - 1; i++) {
        for (int j = 1; j < MATRIX_SIZE - 1; j++) {
            if (isLocalMinimum(matrix, i, j)) {
                localMinCount++;
            }
        }
    }

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = i + 1; j < MATRIX_SIZE; j++) {
            sumAboveDiagonal += abs(matrix[i][j]);
        }
    }

    printf("Кількість локальних мінімумів: %d\n", localMinCount);
    printf("Сума модулів елементів вище головної діагоналі: %d\n", sumAboveDiagonal);

    textOutput = fopen("output.txt", "w");
    if (!textOutput) {
        printf("Помилка відкриття текстового файлу для запису\n");
        return 1;
    }
    fprintf(textOutput, "Кількість локальних мінімумів: %d\n", localMinCount);
    fprintf(textOutput, "Сума модулів елементів вище головної діагоналі: %d\n", sumAboveDiagonal);
    fprintf(textOutput, "\nРезультати обробки:\n");
    printMatrix(matrix, MATRIX_SIZE);
    fclose(textOutput);

    binaryOutput = fopen("output.bin", "wb");
    if (!binaryOutput) {
        printf("Помилка відкриття бінарного файлу для запису\n");
        return 1;
    }
    fwrite(matrix, sizeof(int), MATRIX_SIZE * MATRIX_SIZE, binaryOutput);
    fclose(binaryOutput);

    return 0;
}
