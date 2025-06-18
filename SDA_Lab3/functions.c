#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

Node* insert_node(Node* root, int key) {
    if (root == NULL) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->key = key;
        node->left = node->right = NULL;
        return node;
    }
    if (key < root->key)
        root->left = insert_node(root->left, key);
    else
        root->right = insert_node(root->right, key);
    return root;
}

void print_tree(Node* root, int level) {
    if (root == NULL) return;
    print_tree(root->right, level + 1);
    for (int i = 0; i < level; i++) printf("    ");
    printf("%d\n", root->key);
    print_tree(root->left, level + 1);
}

int tree_depth(Node* root) {
    if (root == NULL) return 0;
    int left = tree_depth(root->left);
    int right = tree_depth(root->right);
    return (left > right ? left : right) + 1;
}

Node* search_node(Node* root, int key) {
  if   (root == NULL || root->key == key) return root;
    if (key < root->key)
        return search_node(root->left, key);
    else
        return search_node(root->right, key);
}

int node_depth(Node* root, int key, int level) {
    if (root == NULL) return -1;
    if (root->key == key) return level;
    if (key < root->key)
        return node_depth(root->left, key, level + 1);
    else
        return node_depth(root->right, key, level + 1);
}

int get_height(Node* node) {
    if (node == NULL) return 0;
    int left = get_height(node->left);
    int right = get_height(node->right);
    return (left > right ? left : right) + 1;
}

int node_height(Node* root, int key) {
    Node* node = search_node(root, key);
    if (node == NULL) return -1;
    return get_height(node) - 1;
}

void print_leaves(Node* root) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->key);
    print_leaves(root->left);
    print_leaves(root->right);
}

void clear_tree(Node** root) {
    if (*root == NULL) return;
    clear_tree(&((*root)->left));
    clear_tree(&((*root)->right));
    free(*root);
    *root = NULL;
}

void free_tree(Node** root) {
    clear_tree(root);
    printf("Memory freed.\n");
}

void save_to_file(Node* root, FILE* file) {
    if (root == NULL) {
        fprintf(file, "# ");
        return;
    }
    fprintf(file, "%d ", root->key);
    save_to_file(root->left, file);
    save_to_file(root->right, file);
}

Node* load_helper(FILE* file) {
    char buffer[16];
    if (fscanf(file, "%s", buffer) != 1)
        return NULL;
    if (buffer[0] == '#')
        return NULL;

    int key = atoi(buffer);
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = load_helper(file);
    node->right = load_helper(file);
    return node;
}

void load_from_file(Node** root, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file.\n");
        return;
    }
    clear_tree(root);
    *root = load_helper(file);
    fclose(file);
    printf("Tree loaded.\n");
}
