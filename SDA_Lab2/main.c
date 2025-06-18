#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    LinkedList list;
    list.head = NULL;
    int choice, id, poz;
    Book* b;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Read list\n");
        printf("2. Show list\n");
        printf("3. Search by ID\n");
        printf("4. Sort by price\n");
        printf("5. Insert at end\n");
        printf("6. Insert at start\n");
        printf("7. Insert at position\n");
        printf("8. Delete element at position\n");
        printf("9. Invert list\n");
        printf("10. Empty list\n");
        printf("0. EXIT\n");
        printf("Option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: read_list(&list); break;
            case 2: print_list(list); break;
            case 3:
                printf("Search ID: "); scanf("%d", &id);
            poz = search_by_id(list, id);
            if (poz == -1) printf("Element not found.\n");
            else printf("Found at position %d.\n", poz);
            break;
            case 4: sort_after_price(&list); break;
            case 5:
                b = read_book();
            insert_at_end(&list, b);
            break;
            case 6:
                b = read_book();
            insert_at_start(&list, b);
            break;
            case 7:
                printf("Position: "); scanf("%d", &poz);
            b = read_book();
            insert_at_position(&list, b, poz);
            break;
            case 8:
                printf("Position: "); scanf("%d", &poz);
            delete_at_position(&list, poz);
            break;
            case 9: invert_list(&list); break;
            case 10: empty_list(&list); break;
            case 0: free_list(&list); break;
            default: printf("Invalid option.\n");
        }

    } while (choice != 0);

    return 0;
}
