#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main() {
    int n, i;

    printf("Enter size of arrays: ");
    scanf("%d", &n);

    int *A = (int*) malloc(n * sizeof(int));
    int *B = (int*) malloc(n * sizeof(int));
    int *C = (int*) malloc(n * sizeof(int));


    srand(time(NULL));


    for (i = 0; i < n; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }


    #pragma omp parallel for
    for (i = 0; i < n; i++) {
        C[i] = A[i] + B[i];
    }


    if (n < 25) {
        printf("\nArray A:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", A[i]);
        }

        printf("\nArray B:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", B[i]);
        }

        printf("\nResult Array C (A + B):\n");        for (i = 0; i < n; i++) {
            printf("%d ", C[i]);
        }
        printf("\n");
    } else {
        printf("\nArrays are large. Result not displayed.\n");
    }


    free(A);
    free(B);
    free(C);

    return 0;
}