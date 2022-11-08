#include "./libs/stockmap.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  struct Node *root = NULL;
  
  root = stockmap_insert(root, 50);
  root = stockmap_insert(root, 9494);
  root = stockmap_insert(root, 44);
  root = stockmap_insert(root, 88);
  root = stockmap_insert(root, 89);
  root = stockmap_insert(root, 58);
  root = stockmap_insert(root, 75);
  root = stockmap_insert(root, 76);
  root = stockmap_insert(root, 77);
  root = stockmap_insert(root, 9999);
  root = stockmap_insert(root, 9998);
  root = stockmap_insert(root, 9997);
  root = stockmap_insert(root, 9996);
  root = stockmap_insert(root, 90);
  root = stockmap_insert(root, 91);
  root = stockmap_insert(root, 93);
  root = stockmap_insert(root, 92);
  root = stockmap_insert(root, 96);
  root = stockmap_insert(root, 94);

  // root = stockmap_insert(root, 10);
  // root = stockmap_insert(root, 7);
  // root = stockmap_insert(root, 9);
  // root = stockmap_insert(root, 1);
  // root = stockmap_insert(root, 3);
  // root = stockmap_insert(root, 8);
  // root = stockmap_insert(root, 99);
  // root = stockmap_remove(root, 7);

  printf("pre_order_traversal traversal of the constructed AVL"
         " tree is \n");
  // 44 50 58 75 76 77 88 89 90 91 92 93 94 96 9494 9996 9997 9998 9999
  in_order_traversal(root);
  
  return 0;
}
