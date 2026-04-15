Perform mirror matrix creation using parallel for in OpenMP

Input:1 2 3
      4 5 6
      7 8 9
Output:3 2 1
       6 5 4
       9 8 7

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void mirrorMatrix(int **matrix, int rows, int cols) {
    int i, j, temp;


    #pragma omp parallel for private(j, temp) shared(matrix, rows, cols)
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols / 2; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][cols - 1 - j];
            matrix[i][cols - 1 - j] = temp;
        }
    }
}

int main() {
    int rows, cols, i, j;


    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }


    printf("Enter elements for a %dx%d matrix:\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }


    mirrorMatrix(matrix, rows, cols);


    printf("\nMirrored Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
