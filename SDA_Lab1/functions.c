#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

#define ERROR -1

void read_ids(Element *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter id for element %d: ", i + 1);
        scanf("%d", &arr[i].id);
    }
}

void read_names(Element *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter name for element %d: ", i + 1);
        scanf("%s", arr[i].name);
    }
}

void read_elements(Element **arr, int *size) {
    scanf("%d", size);
    *arr = (Element *)malloc(*size * sizeof(Element));

    if (*arr == NULL) {
        printf("Memory allocation failed!\n");
        *size = 0;
        return;
    }

    read_ids(*arr, *size);
    read_names(*arr, *size);
}

void print_element(Element e) {
    printf("ID: %d, Name: %s\n", e.id, e.name);
}

void print_elements(Element *arr, int size) {
    printf("\nElements:\n");
    for (int i = 0; i < size; i++) {
        print_element(arr[i]);
    }
}

int search_by_id(Element *arr, int size, int searchId) {
    for (int i = 0; i < size; i++) {
        if (arr[i].id == searchId) {
            return i;
        }
    }
    return -1;
}

void free_memory(Element **arr) {
    free(*arr);
    *arr = NULL;
}

void swap_elements(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void sort_elements(Element *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i].id > arr[j].id) {
                swap_elements(&arr[i], &arr[j]);
            }
        }
    }
}

void push_back(Element **arr, int *size, Element newElement) {
    *arr = (Element *)realloc(*arr, (*size + 1) * sizeof(Element));
    (*arr)[*size] = newElement;
    (*size)++;
}

void push_front(Element **arr, int *size, Element newElement) {
    *arr = (Element *)realloc(*arr, (*size + 1) * sizeof(Element));
    for (int i = *size; i > 0; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[0] = newElement;
    (*size)++;
}

int push_at_position(Element **arr, int *size, Element newElement, int position) {
    if (position < 0 || position > *size) {
        return ERROR;
    }

    *arr = (Element *)realloc(*arr, (*size + 1) * sizeof(Element));
    if (*arr == NULL) {
        return ERROR;
    }

    for (int i = *size; i > position; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }

    (*arr)[position] = newElement;
    (*size)++;

    return 0;
}

int pop_at_position(Element **arr, int *size, int position) {
    if (position < 0 || position >= *size) {
        return ERROR;
    }

    for (int i = position; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    *arr = (Element *)realloc(*arr, (*size - 1) * sizeof(Element));
    if (*arr == NULL && *size > 1) {
        return ERROR;
    }

    (*size)--;

    return 0;
}

void print_menu() {
    printf("\nMenu:\n");
    printf("1. Read elements\n");
    printf("2. Print elements\n");
    printf("3. Search by ID\n");
    printf("4. Sort elements\n");
    printf("5. Insert at end\n");
    printf("6. Insert at beginning\n");
    printf("7. Insert at position\n");
    printf("8. Delete at position\n");
    printf("9. Free memory\n");
    printf("0. Exit\n");
}
