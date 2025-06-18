#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void init_array(int **arr, int size) {
    *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        (*arr)[i] = rand() % 1000;
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void free_array(int **arr) {
    if (*arr) {
        free(*arr);
        *arr = NULL;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[i], &arr[min_idx]);
    }
}

void insertion_sort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

// Merge Sort
void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;
    int *L = malloc(n1 * sizeof(int)), *R = malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}

void merge_sort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(int *arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j <= high - 1; j++)
        if (arr[j] < pivot)
            swap(&arr[++i], &arr[j]);
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Heap Sort
void heapify(int *arr, int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void analyze_sorts() {
    int sizes[] = {100, 1000, 10000, 100000};
    int n_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("\n%-10s | %-15s | %-15s | %-15s | %-15s | %-15s | %-15s\n",
           "N", "Bubble Sort", "Insertion Sort", "Selection Sort",
           "Merge Sort", "Quick Sort", "Heap Sort");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n_sizes; i++) {
        int n = sizes[i];
        int *original = (int *)malloc(n * sizeof(int));
        int *copy = (int *)malloc(n * sizeof(int));

        for (int j = 0; j < n; j++)
            original[j] = rand() % 10000;

        double times[6] = {0};
        clock_t start, end;

        // Bubble Sort
        copy_array(copy, original, n);
        start = clock();
        bubble_sort(copy, n);
        end = clock();
        times[0] = (double)(end - start) / CLOCKS_PER_SEC;

        // Insertion Sort
        copy_array(copy, original, n);
        start = clock();
        insertion_sort(copy, n);
        end = clock();
        times[1] = (double)(end - start) / CLOCKS_PER_SEC;

        // Selection Sort
        copy_array(copy, original, n);
        start = clock();
        selection_sort(copy, n);
        end = clock();
        times[2] = (double)(end - start) / CLOCKS_PER_SEC;

        // Merge Sort
        copy_array(copy, original, n);
        start = clock();
        merge_sort(copy, 0, n - 1);
        end = clock();
        times[3] = (double)(end - start) / CLOCKS_PER_SEC;

        // Quick Sort
        copy_array(copy, original, n);
        start = clock();
        quick_sort(copy, 0, n - 1);
        end = clock();
        times[4] = (double)(end - start) / CLOCKS_PER_SEC;

        // Heap Sort
        copy_array(copy, original, n);
        start = clock();
        heap_sort(copy, n);
        end = clock();
        times[5] = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%-10d | %-15.6f | %-15.6f | %-15.6f | %-15.6f | %-15.6f | %-15.6f\n",
               n, times[0], times[1], times[2], times[3], times[4], times[5]);

        free(original);
        free(copy);
    }
}

