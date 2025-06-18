#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

enum {
    READ_TREE = 1,
    PRINT_TREE,
    CALCULATE_DEPTH,
    SEARCH_NODE,
    NODE_DEPTH,
    NODE_HEIGHT,
    PRINT_LEAVES,
    CLEAR_TREE,
    FREE_TREE,
    SAVE_TO_FILE,
    LOAD_FROM_FILE,
    CLEAR_FILE,
    EXIT_PROGRAM = 0
};

#endif
