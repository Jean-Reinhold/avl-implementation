struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    // char name[];
    // float hdi;
    // int population;
    // float area;
};

// --------------- Expostas ao Usuário ----------------------
// Funções com operação de crud básicas
struct Node *stockmap_create_node(int key);
struct Node *stockmap_insert(struct Node *root, int key);
void stockmap_print(struct Node *node);

struct Node *stockmap_remove(struct Node *root, int key);

// Caminhadores
void pre_order_traversal(struct Node *root);
void in_order_traversal(struct Node *root);
// ----------------------------------------------------------