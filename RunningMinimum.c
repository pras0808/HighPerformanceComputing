Find the running minimum of given array and store the result in another array.(Prefix Minimum)

Input:5 3 6 2 7 
Output:5 3 3 2 2

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void findRunningMinimum(int *arr, int *min_arr, int n) {
    int current_min = arr[0];

    #pragma omp parallel for reduction(minscan, current_min)
    for (int i = 0; i < n; i++) {

        if (arr[i] < current_min) {
            current_min = arr[i];
        }

        #pragma omp scan inclusive(current_min)
        min_arr[i] = current_min;
    }
}

int main() {
    int n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int *min_arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findRunningMinimum(arr, min_arr, n);

    printf("\nRunning Minimum Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", min_arr[i]);
    }
    printf("\n");

    free(arr);
    free(min_arr);
    return 0;
}