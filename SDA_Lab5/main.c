#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include "structs.h"

int main() {
    int *array = NULL, size, choice;

    printf("Enter array size: ");
    scanf("%d", &size);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Initialize array\n");
        printf("2. Print array\n");
        printf("3. Free array\n");
        printf("4. Sort (selection/insertion/bubble)\n");
        printf("5. Sort (merge/quick/heap)\n");
        printf("6. Analyze sorting times\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        int *copy = malloc(size * sizeof(int));
        clock_t start, end;
        double time_taken;

        switch (choice) {
            case INIT_ARRAY:
                init_array(&array, size);
                break;
            case PRINT_ARRAY:
                if (array) print_array(array, size);
                else printf("Array not initialized.\n");
                break;
            case FREE_ARRAY:
                free_array(&array);
                break;
            case SLOW_SORT:
                if (!array) break;
                copy_array(copy, array, size);
                start = clock();
                bubble_sort(copy, size);  // change to selection_sort or insertion_sort if needed
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                print_array(copy, size);
                printf("Sort time: %.6fs\n", time_taken);
                break;
            case FAST_SORT:
                if (!array) break;
                copy_array(copy, array, size);
                start = clock();
                quick_sort(copy, 0, size - 1);  // change to merge_sort or heap_sort if needed
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                print_array(copy, size);
                printf("Sort time: %.6fs\n", time_taken);
                break;
            case EXIT_PROGRAM:
                free_array(&array);
                break;
            case ANALYZE_SORTS:
                analyze_sorts();
                break;
            default:
                printf("Invalid option.\n");
        }

        free(copy);
    } while (choice != EXIT_PROGRAM);

    return 0;
}

void copy_array(int *dest, int *src, int size) {
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
}
