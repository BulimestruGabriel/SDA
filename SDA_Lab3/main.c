#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    Node* root = NULL;
    int option, key;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Read tree (insert nodes)\n");
        printf("2. Print tree\n");
        printf("3. Calculate tree depth\n");
        printf("4. Search node by key\n");
        printf("5. Calculate depth of a node\n");
        printf("6. Calculate height of a node\n");
        printf("7. Print leaves\n");
        printf("8. Clear tree\n");
        printf("9. Free memory and exit\n");
        printf("10. Save tree to file\n");
        printf("11. Load tree from file\n");
        printf("12. Delete tree from file\n");
        printf("0. Exit without freeing memory\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case READ_TREE:
                printf("Enter key (0 to stop): ");
                while (scanf("%d", &key) && key != 0)
                    root = insert_node(root, key);
                break;
            case PRINT_TREE:
                print_tree(root, 0);
                break;
            case CALCULATE_DEPTH:
                printf("Tree depth: %d\n", tree_depth(root));
                break;
            case SEARCH_NODE:
                printf("Key to search: ");
                scanf("%d", &key);
                Node* found = search_node(root, key);
                if (found)
                    printf("Key found: %d\n", found->key);
                else
                    printf("Key not found.\n");
                break;
            case NODE_DEPTH:
                printf("Key to check depth: ");
                scanf("%d", &key);
                int d = node_depth(root, key, 0);
                if (d == -1)
                    printf("Key not found.\n");
                else
                    printf("Depth: %d\n", d);
                break;
            case NODE_HEIGHT:
                printf("Key to check height: ");
                scanf("%d", &key);
                int h = node_height(root, key);
                if (h == -1)
                    printf("Key not found.\n");
                else
                    printf("Height: %d\n", h);
                break;
            case PRINT_LEAVES:
                printf("Leaves: ");
                print_leaves(root);
                printf("\n");
                break;
            case CLEAR_TREE:
                clear_tree(&root);
                printf("Tree cleared.\n");
                break;
            case FREE_TREE:
                free_tree(&root);
                option = EXIT_PROGRAM;
                break;
            case SAVE_TO_FILE: {
                FILE* file = fopen("tree.txt", "w");
                if (!file)
                    printf("Cannot open file for writing.\n");
                else {
                    save_to_file(root, file);
                    fclose(file);
                    printf("Tree saved to file.\n");
                }
                break;
            }
            case LOAD_FROM_FILE:
                load_from_file(&root, "tree.txt");
                break;
            case EXIT_PROGRAM:
                break;
            default:
                printf("Invalid option.\n");
            case CLEAR_FILE: {
                FILE* file = fopen("tree.txt", "w");
                if (!file)
                    printf("Cannot open file to clear.\n");
                else {
                    fclose(file);
                    printf("File cleared.\n");
                }
                break;
            }
        }
    } while (option != EXIT_PROGRAM);

    return 0;
}
