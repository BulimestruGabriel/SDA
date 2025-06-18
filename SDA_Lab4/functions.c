#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


TreeNode* insert_node(TreeNode *root, int key, const char *name, float value, const char *description) {
    if (!root) {
        TreeNode *n = malloc(sizeof(TreeNode));
        n->key = key;
        strncpy(n->name, name, 49); n->name[49] = '\0';
        n->value = value;
        strncpy(n->description, description, 99); n->description[99] = '\0';
        n->left = n->right = NULL;
        return n;
    }
    if (key < root->key)
        root->left = insert_node(root->left, key, name, value, description);
    else if (key > root->key)
        root->right = insert_node(root->right, key, name, value, description);
    return root;
}

TreeNode* read_tree() {
    TreeNode *root = NULL;
    int key;
    char name[50], description[100];
    float value;
    printf("Insert nodes (key==0 to stop):\n");
    while (1) {
        printf("Key: "); scanf("%d", &key);
        if (key == 0) break;
        printf("Name: "); scanf(" %[^\n]", name);
        printf("Value: "); scanf("%f", &value);
        printf("Description: "); scanf(" %[^\n]", description);
        root = insert_node(root, key, name, value, description);
    }
    return root;
}


void print_node_fields(TreeNode *node) {
    if (!node) return;
    printf("Key: %d\nName: %s\nValue: %.2f\nDesc: %s\n\n",
           node->key, node->name, node->value, node->description);
}

void print_tree(TreeNode *root, int level) {
    if (!root) return;
    print_tree(root->right, level+1);
    for (int i = 0; i < level; i++) printf("    ");
    printf("%d\n", root->key);
    print_tree(root->left, level+1);
}


TreeNode* search_node(TreeNode *root, int key) {
    if (!root || root->key == key) return root;
    if (key < root->key) return search_node(root->left, key);
    else return search_node(root->right, key);
}


void inorder_traversal(TreeNode *root) {
    if (!root) return;
    inorder_traversal(root->left);
    print_node_fields(root);
    inorder_traversal(root->right);
}

void preorder_traversal(TreeNode *root) {
    if (!root) return;
    print_node_fields(root);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(TreeNode *root) {
    if (!root) return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    print_node_fields(root);
}


typedef struct StackNode {
    TreeNode *tn;
    struct StackNode *next;
} StackNode;

static void push(StackNode **top, TreeNode *tn) {
    StackNode *n = malloc(sizeof(StackNode));
    n->tn = tn; n->next = *top; *top = n;
}
static TreeNode* pop(StackNode **top) {
    if (!*top) return NULL;
    StackNode *t = *top; TreeNode *r = t->tn;
    *top = t->next; free(t); return r;
}

void dfs_traversal(TreeNode *root) {
    StackNode *stack = NULL;
    if (root) push(&stack, root);
    while (stack) {
        TreeNode *cur = pop(&stack);
        print_node_fields(cur);
        if (cur->right) push(&stack, cur->right);
        if (cur->left)  push(&stack, cur->left);
    }
}


typedef struct QNode {
    TreeNode *tn; struct QNode *next;
} QNode;
typedef struct {
    QNode *front, *rear;
} Queue;

static void enqueue(Queue *q, TreeNode *tn) {
    QNode *n = malloc(sizeof(QNode));
    n->tn = tn; n->next = NULL;
    if (!q->rear) q->front = n;
    else q->rear->next = n;
    q->rear = n;
}
static TreeNode* dequeue(Queue *q) {
    if (!q->front) return NULL;
    QNode *t = q->front; TreeNode *r = t->tn;
    q->front = t->next; if (!q->front) q->rear = NULL;
    free(t); return r;
}

void bfs_traversal(TreeNode *root) {
    Queue q = {NULL, NULL};
    if (root) enqueue(&q, root);
    while (q.front) {
        TreeNode *cur = dequeue(&q);
        print_node_fields(cur);
        if (cur->left)  enqueue(&q, cur->left);
        if (cur->right) enqueue(&q, cur->right);
    }
}

/* --- Balansare --- */
static int count_nodes(TreeNode *root) {
    if (!root) return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

static void store_inorder(TreeNode *root, TreeNode **arr, int *idx) {
    if (!root) return;
    store_inorder(root->left, arr, idx);
    arr[(*idx)++] = root;
    store_inorder(root->right, arr, idx);
}

static TreeNode* build_balanced(TreeNode **arr, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    TreeNode *root = arr[mid];
    root->left  = build_balanced(arr, start, mid-1);
    root->right = build_balanced(arr, mid+1, end);
    return root;
}

TreeNode* balance_tree(TreeNode *root) {
    int n = count_nodes(root);
    if (n <= 1) return root;
    TreeNode **arr = malloc(n * sizeof(TreeNode*));
    int idx = 0;
    store_inorder(root, arr, &idx);
    TreeNode *new_root = build_balanced(arr, 0, n-1);
    free(arr);
    return new_root;
}


void mirror_tree(TreeNode *root) {
    if (!root) return;
    TreeNode *tmp = root->left;
    root->left  = root->right;
    root->right = tmp;
    mirror_tree(root->left);
    mirror_tree(root->right);
}


void clear_tree(TreeNode **root) {
    if (!*root) return;
    clear_tree(&(*root)->left);
    clear_tree(&(*root)->right);
    free(*root);
    *root = NULL;
}

void free_tree(TreeNode **root) {
    clear_tree(root);
    printf("Memory freed.\n");
}
