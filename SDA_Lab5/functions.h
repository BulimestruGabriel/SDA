#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void init_array(int **arr, int size);
void print_array(int *arr, int size);
void free_array(int **arr);
void selection_sort(int *arr, int size);
void insertion_sort(int *arr, int size);
void bubble_sort(int *arr, int size);
void merge_sort(int *arr, int left, int right);
void quick_sort(int *arr, int left, int right);
void heap_sort(int *arr, int size);
void swap(int *a, int *b);
void copy_array(int *dest, int *src, int size);
void analyze_sorts();

#endif
