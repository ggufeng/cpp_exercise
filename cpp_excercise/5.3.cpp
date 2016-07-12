#include <stdio.h>
#include <stdlib.h>

typedef int elem_t;

typedef struct bt_node_t {
    elem_t elem;
    bt_node_t *left;
    bt_node_t *right;
} bt_node_t;


// unchanged: before it is visited, the nodes before it are visited
void in_order_morris(bt_node_t *root, int(*visit)(bt_node_t*)) {
    if (root != NULL) {
        bt_node_t *pre;
        bt_node_t *cur = root;
        if (cur->left == NULL) {
            visit(cur);
            pre = cur;
            cur = cur->right;
        } else {
            bt_node_t *node = cur->left;
            while (node->right != NULL && node->right != cur)
                node = node->right;

            if (node->right == NULL) {
                node->right = cur;
                cur = cur->left;
            } else {
                visit(cur);
                node->right = NULL;
                pre = cur;
                cur = cur->right;
            }
        }
    }
}
