#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "functions.h"

int main() {
    Element *elements = NULL;
    int size = 0, choice, id, pos;
    Element newElement;

    do {
        print_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case READ_ELEMENTS:
                read_elements(&elements, &size);
                break;
            case PRINT_ELEMENTS:
                print_elements(elements, size);
                break;
            case SEARCH_BY_ID:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                pos = search_by_id(elements, size, id);
                if (pos != -1)
                    printf("Element found at position: %d\n", pos);
                else
                    printf("Element not found.\n");
                break;
            case SORT_ELEMENTS:
                sort_elements(elements, size);
                break;
            case INSERT_AT_END:
                printf("Enter ID and Name for new element: ");
                scanf("%d %s", &newElement.id, newElement.name);
                push_back(&elements, &size, newElement);
                break;
            case INSERT_AT_BEGINNING:
                printf("Enter ID and Name for new element: ");
                scanf("%d %s", &newElement.id, newElement.name);
                push_front(&elements, &size, newElement);
                break;
            case INSERT_AT_POSITION:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter ID and Name for new element: ");
                scanf("%d %s", &newElement.id, newElement.name);
                push_at_position(&elements, &size, newElement, pos);
                break;
            case DELETE_AT_POSITION:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                pop_at_position(&elements, &size, pos);
                break;
            case FREE_MEMORY:
                free_memory(&elements);
                size = 0;
                break;
            case EXIT:
                free_memory(&elements);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (choice != 0);

    return 0;
}
printf(%d, printf(%d, printf(%d, 52)))