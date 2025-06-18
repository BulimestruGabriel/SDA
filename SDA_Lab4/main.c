#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    TreeNode *root = NULL;
    int option, key;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Read tree\n");
        printf("2. Print tree structure\n");
        printf("3. Search node (by key)\n");
        printf("4. Inorder traversal\n");
        printf("5. Preorder traversal\n");
        printf("6. Postorder traversal\n");
        printf("7. Depth-First Search (DFS)\n");
        printf("8. Breadth-First Search (BFS)\n");
        printf("9. Balance tree\n");
        printf("10. Mirror tree\n");
        printf("11. Clear tree (delete nodes)\n");
        printf("12. Free memory\n");
        printf("0. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case MENU_READ_TREE:
                root = read_tree();
                break;
            case MENU_PRINT_TREE:
                print_tree(root, 0);
                break;
            case MENU_SEARCH_NODE: {
                printf("Key to search: ");
                scanf("%d", &key);
                TreeNode *found = search_node(root, key);
                if (found) print_node_fields(found);
                else printf("Node not found.\n");
                break;
            }
            case MENU_PRINT_INORDER:
                inorder_traversal(root);
                break;
            case MENU_PRINT_PREORDER:
                preorder_traversal(root);
                break;
            case MENU_PRINT_POSTORDER:
                postorder_traversal(root);
                break;
            case MENU_DFS:
                dfs_traversal(root);
                break;
            case MENU_BFS:
                bfs_traversal(root);
                break;
            case MENU_BALANCE_TREE:
                root = balance_tree(root);
                printf("Tree balanced.\n");
                break;
            case MENU_MIRROR_TREE:
                mirror_tree(root);
                printf("Tree mirrored.\n");
                break;
            case MENU_CLEAR_TREE:
                clear_tree(&root);
                printf("Tree cleared.\n");
                break;
            case MENU_FREE_MEMORY:
                free_tree(&root);
                option = MENU_EXIT;
                break;
            case MENU_EXIT:
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != MENU_EXIT);

    return 0;
}
