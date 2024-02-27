#define _CRT_SECURE_NO_WARNINGS
#include "array_macros.h"

int main() {
    int n, zero_count = 0, count_after_min = 0;

    printf("Enter the size of the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    double* array = (double*)malloc(n * sizeof(double));
    if (!array) {
        printf("Unable to allocate memory.\n");
        return 1;
    }

    INPUT_ARRAY(array, n);

    COUNT_ZERO(array, n, zero_count);
    printf("The number of elements equal to 0: %d\n", zero_count);

    COUNT_AFTER_MIN(array, n, count_after_min);
    printf("The number of elements after the minimum: %d\n", count_after_min);

    SORT_ARRAY(array, n);
    printf("The array after sorting: ");
    PRINT_ARRAY(array, n);

    free(array);

    return 0;
}
