#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
} Element;

void read_elements(Element **arr, int *size) {
    printf("Enter number of elements: ");
    scanf("%d", size);
    *arr = (Element *)malloc(*size * sizeof(Element));
    for (int i = 0; i < *size; i++) {
        printf("Enter id for element %d: ", i + 1);
        scanf("%d", &(*arr)[i].id);
        printf("Enter name for element %d: ", i + 1);
        scanf("%s", (*arr)[i].name);
    }
}

void print_elements(Element *arr, int size) {
    printf("\nElements:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s\n", arr[i].id, arr[i].name);
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

void sort_elements(Element *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i].id > arr[j].id) {
                Element temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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

void push_at_position(Element **arr, int *size, Element newElement, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }
    *arr = (Element *)realloc(*arr, (*size + 1) * sizeof(Element));
    for (int i = *size; i > position; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[position] = newElement;
    (*size)++;
}

void pop_at_position(Element **arr, int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    *arr = (Element *)realloc(*arr, (*size - 1) * sizeof(Element));
    (*size)--;
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

int main() {
    Element *elements = NULL;
    int size = 0, choice, id, pos;
    Element newElement;

    do {
        print_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                read_elements(&elements, &size);
                break;
            case 2:
                print_elements(elements, size);
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                pos = search_by_id(elements, size, id);
                if (pos != -1)
                    printf("Element found at position: %d\n", pos);
                else
                    printf("Element not found.\n");
                break;
            case 4:
                sort_elements(elements, size);
                break;
            case 5:
                printf("Enter ID and Name for new element: ");
                scanf("%d %s", &newElement.id, newElement.name);
                push_back(&elements, &size, newElement);
                break;
            case 6:
                printf("Enter ID and Name for new element: ");
                scanf("%d %s", &newElement.id, newElement.name);
                push_front(&elements, &size, newElement);
                break;
            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter ID and Name for new element: ");
                scanf("%d %s", &newElement.id, newElement.name);
                push_at_position(&elements, &size, newElement, pos);
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                pop_at_position(&elements, &size, pos);
                break;
            case 9:
                free_memory(&elements);
                size = 0;
                break;
            case 0:
                free_memory(&elements);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (choice != 0);

    return 0;
}
