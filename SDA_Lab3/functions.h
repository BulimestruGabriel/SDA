#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"

Node* insert_node(Node* root, int key);
void print_tree(Node* root, int level);
int tree_depth(Node* root);
Node* search_node(Node* root, int key);
int node_depth(Node* root, int key, int level);
int node_height(Node* root, int key);
int get_height(Node* node);
void print_leaves(Node* root);
void clear_tree(Node** root);
void free_tree(Node** root);
void save_to_file(Node* root, FILE* file);
void load_from_file(Node** root, const char* filename);

#endif
