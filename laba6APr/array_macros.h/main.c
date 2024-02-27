#ifndef ARRAY_MACROS_H
#define ARRAY_MACROS_H

#include <stdio.h>
#include <stdlib.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

#define INPUT_ARRAY(arr, n) do { \
    printf("Enter %d elements of the array: ", n); \
    for(int i = 0; i < n; i++) { \
        scanf("%lf", &arr[i]); \
    } \
} while(0)

#define PRINT_ARRAY(arr, n) do { \
    for(int i = 0; i < n; i++) { \
        printf("%.2f ", arr[i]); \
    } \
    printf("\n"); \
} while(0)

#define COMPARE_FUNCTION ((int (*)(const void *, const void *))compare)
 compare(const void* a, const void* b) {
    double abs_a = ABS(*(double*)a);
    double abs_b = ABS(*(double*)b);
    return (abs_b < abs_a) - (abs_b > abs_a);
}

#define COUNT_ZERO(arr, n, count) do { \
    count = 0; \
    for(int i = 0; i < n; i++) { \
        if(arr[i] == 0) count++; \
    } \
} while(0)

#define COUNT_AFTER_MIN(arr, n, count) do { \
    double min_element = arr[0]; \
    int min_index = 0; \
    for(int i = 1; i < n; i++) { \
        if(arr[i] < min_element) { \
            min_element = arr[i]; \
            min_index = i; \
        } \
    } \
    count = n - min_index; \
} while(0)

#define SORT_ARRAY(arr, n) qsort(arr, n, sizeof(double), compare)

#endif
