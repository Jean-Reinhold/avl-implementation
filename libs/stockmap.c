#include <stdio.h>
#include <stdlib.h>
#include "stockmap.h"

// --------------- Auxiliares Escondidas --------------------
int height(struct Node *N);
int max(int a, int b);
struct Node *stockmap_right_rotate(struct Node *up_node);
struct Node *stockmap_left_rotate(struct Node *up_node);
struct Node *get_min_node(struct Node *node);
// ----------------------------------------------------------

// Calcula a altura de um nó
int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

// Calcula o valor máximo entre dois inteiros
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

// Rotação simples para a direita
struct Node *stockmap_right_rotate(struct Node *up_node)
{
    struct Node *mid_node = up_node->left;
    struct Node *down_node = mid_node->right;

    mid_node->right = up_node;
    up_node->left = down_node;

    return mid_node;
}

struct Node *stockmap_left_rotate(struct Node *up_node)
{
    struct Node *mid_node = up_node->right;
    struct Node *down_node = mid_node->left;

    mid_node->left = up_node;
    up_node->right = down_node;

    return mid_node;
}

int stockmap_get_bf(struct Node *node)
{
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

struct Node *get_min_node(struct Node *node)
{
    struct Node *current = node;
    while (current->left != NULL)
        current = current->left;

    return current;
}
// ----------------------------------------------------------------

// -------------------------- CRUD --------------------------------
// Cria um novo nó com valores padrão, apenas a chave é necessária
struct Node *create_node(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

struct Node *stockmap_insert(struct Node *root, int key)
{
    if (root == NULL)
        return (create_node(key));
    if (key > root->key)
        root->right = stockmap_insert(root->right, key);
    else if (key < root->key)
        root->left = stockmap_insert(root->left, key);
    else
        return root;

    int balance = stockmap_get_bf(root);

    if (balance > 1 && key < root->left->key)
        return stockmap_right_rotate(root);

    if (balance < -1 && key > root->right->key)
        return stockmap_left_rotate(root);

    if (balance > 1 && key > root->left->key)
    {
        root->left = stockmap_left_rotate(root->left);
        return stockmap_right_rotate(root);
    }

    if (balance < -1 && key < root->right->key)
    {
        root->right = stockmap_right_rotate(root->right);
        return stockmap_left_rotate(root);
    }

    return root;
}

void stockmap_print(struct Node *node){
    printf("Nó com chave %i \n", node->key);
}

struct Node *stockmap_remove(struct Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = stockmap_remove(root->left, key);

    else if (key > root->key)
        root->right = stockmap_remove(root->right, key);

    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            struct Node *temp = get_min_node(root->right);
            root->key = temp->key;
            root->right = stockmap_remove(root->right,
                                        temp->key);
        }
    }

    int balance = stockmap_get_bf(root);

    if (balance > 1 && stockmap_get_bf(root->left) >= 0)
        return stockmap_right_rotate(root);

    if (balance > 1 && stockmap_get_bf(root->left) < 0)
    {
        root->left = stockmap_left_rotate(root->left);
        return stockmap_right_rotate(root);
    }

    if (balance < -1 && stockmap_get_bf(root->right) <= 0)
        return stockmap_left_rotate(root);

    if (balance < -1 && stockmap_get_bf(root->right) > 0)
    {
        root->right = stockmap_right_rotate(root->right);
        return stockmap_left_rotate(root);
    }

    return root;
}

void in_order_traversal(struct Node *root)
{
    if (root != NULL)
    {
        in_order_traversal(root->left);
        stockmap_print(root);
        in_order_traversal(root->right);
    }
}

void pre_order_traversal(struct Node *root)
{
    if (root != NULL)
    {
        stockmap_print(root);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}
