#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct TreeNode {
    int key;
    char name[50];
    float value;
    char description[100];
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

enum {
    MENU_READ_TREE = 1,
    MENU_PRINT_TREE,
    MENU_SEARCH_NODE,
    MENU_PRINT_INORDER,
    MENU_PRINT_PREORDER,
    MENU_PRINT_POSTORDER,
    MENU_DFS,
    MENU_BFS,
    MENU_BALANCE_TREE,
    MENU_MIRROR_TREE,
    MENU_CLEAR_TREE,
    MENU_FREE_MEMORY,
    MENU_EXIT = 0
};

#endif
