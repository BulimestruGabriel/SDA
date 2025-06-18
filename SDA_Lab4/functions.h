#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"

TreeNode* insert_node(TreeNode *root, int key, const char *name, float value, const char *description);
TreeNode* read_tree();
void print_tree(TreeNode *root, int level);
void print_node_fields(TreeNode *node);
TreeNode* search_node(TreeNode *root, int key);
void inorder_traversal(TreeNode *root);
void preorder_traversal(TreeNode *root);
void postorder_traversal(TreeNode *root);
void dfs_traversal(TreeNode *root);
void bfs_traversal(TreeNode *root);
TreeNode* balance_tree(TreeNode *root);
void mirror_tree(TreeNode *root);
void clear_tree(TreeNode **root);
void free_tree(TreeNode **root);

#endif
