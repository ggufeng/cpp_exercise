#include <stdio.h>
#include <stdlib.h>

typedef int elem_t;

typedef struct bt_node_t {
    elem_t elem;
    bt_node_t *left;
    bt_node_t *right;
} bt_node_t;


// unchanged: before it is visited, the nodes before it are visited
// pre in the original version is useless
//void in_order_morris(bt_node_t *root, int(*visit)(bt_node_t*)) {
//    printf("x");
//    if (root != NULL) {
//        //bt_node_t *pre;
//        bt_node_t *cur = root;
//        while (cur != NULL) {
//            if (cur->left == NULL) {
//                visit(cur);
//                //pre = cur;
//                cur = cur->right;
//            } else {
//                bt_node_t *node = cur->left;
//                while (node->right != NULL && node->right != cur)
//                    node = node->right;

//                if (node->right == NULL) {
//                    node->right = cur;
//                    cur = cur->left;
//                } else {
//                    visit(cur);
//                    node->right = NULL;
//                    //pre = cur;
//                    cur = cur->right;
//                }
//            }
//        }
//    }
//}

// ref: http://stackoverflow.com/questions/5502916/explain-morris-inorder-tree-traversal-without-using-stacks-or-recursion
// this is the right version
void in_order_morris(bt_node_t *root, int(*visit)(bt_node_t*)) {
    //visit(root); // test
    if (root != NULL) {
        bt_node_t *pre;
        bt_node_t *cur = root;
        while (cur != NULL) {
            if (cur->left == NULL) {
                visit(cur);
                cur = cur->right;
            } else {
                pre = cur->left;
                // the first time it comes back, cur = cur
                while (pre->right != NULL && pre->right != cur)
                    pre = pre->right;

                if (pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    visit(cur);
                    cur = cur->right;
                }
            }
        }
    }
}

// original one is totally wrong
//void pre_order_morris(bt_node_t *root, int(*visit)(bt_node_t*)) {
//    if (root != NULL) {
//        bt_node_t *pre;
//        bt_node_t *cur = root;
//        while (cur != NULL) {
//            if (cur->left == NULL) {
//                visit(cur);
//                cur = cur->right;
//            } else {
//                pre = cur->left;
//                // the first time it comes back, cur = cur
//                while (pre->right != NULL && pre->right != cur)
//                    pre = pre->right;

//                if (pre->right == NULL) {
//                    pre->right = cur;
//                    cur = cur->left;
//                } else {
//                    visit(cur);
//                    pre->right = NULL;
//                    cur = cur->right;
//                }
//            }
//        }
//    }
//}

void pre_order_morris(bt_node_t *root, int(*visit)(bt_node_t*)) {
    if (root != NULL) {
        bt_node_t *pre;
        bt_node_t *cur = root;
        while (cur != NULL) {
//            visit(cur);
            if (cur->left == NULL) {
                visit(cur);
                cur = cur->right;
            } else {
                pre = cur->left;
                // the first time it comes back, cur = cur
                while (pre->right != NULL && pre->right != cur)
                    pre = pre->right;

                if (pre->right == NULL) {
                    visit(cur);
                    pre->right = cur;
                    cur = cur->left;
                } else {
//                    visit(cur);
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
    }
}

//static void reverse(bt_node_t *from, bt_node_t *to) {
//    bt_node_t *x = from, *y = from->right, *z;
//    if (from == to) return;

//    while (x != to) {
//        z = y->right;
//        y->right = x;
//        x = y;
//        y = z;
//    }
//}

//static void visit_reverse(bt_node_t *from, bt_node_t *to,
//                          int (*visit)(bt_node_t*)) {
//    bt_node_t *p = to;
//    reverse(from, to);

//    while (1) {
//        visit(p);
//        if (p == from)
//            break;
//        p = p->right;
//    }

//    reverse(to, from);
//}

// original is wrong
//void post_order_morris(bt_node_t *root, int(*visit)(bt_node_t*)) {
//    bt_node_t dummy = {0, NULL, NULL};
//    bt_node_t *cur, *pre = NULL;

//    dummy.left = root;
//    cur = &dummy;
//    while (cur != NULL) {
//        if (cur != NULL) {
//            pre = cur;
//            cur = cur->right;
//        } else {
//            bt_node_t *node = cur->left;
//            while (node->right != NULL && node->right != cur)
//                node = node->right;

//            if (node->right == NULL) {
//                node->right = cur;
//                pre = cur;
//                cur = cur->left;
//            } else {
//                visit_reverse(cur->left, pre, visit);
//                pre->right = NULL;
//                pre = cur;
//                cur = cur->right;
//            }
//        }
//    }
//}

// @F to be understand
// need to be modified
/*
* @brief 逆转路径.
* @param[in] from from
* @param[to] to to
* @return � 
5.3 Morris Traversal 31
*/
static void reverse(bt_node_t *from, bt_node_t *to)
{
    bt_node_t *x = from, *y = from->right, *z;
    if (from == to) return;
    while (x != to)
    {
        z = y->right;
        y->right = x;
        x = y;
        y = z;
    }
}

/*
* @brief 访问逆转后的路径上的所有结点.
* @param[in] from from
* @param[to] to to
* @return � 
*/
static void visit_reverse(bt_node_t* from, bt_node_t *to,int (*visit)(bt_node_t*))
{
    bt_node_t *p = to;
    reverse(from, to);
    while (1)
    {
        visit(p);
        if (p == from)
            break;
        p = p->right;
    }
    reverse(to, from);
}

/**
* @brief 后序遍历，Morris 算法.
* @param[in] root� �节点
* @param[in] visit 访问函数
* @return � 
*/
void post_order_morris(bt_node_t *root, int (*visit)(bt_node_t*))
{
    bt_node_t dump = { 0, NULL, NULL };
    bt_node_t *cur, *prev = NULL;
    dump.left = root;
    cur = &dump;
    while (cur != NULL )
    {
        if (cur->left == NULL )
        {
            prev = cur; /* 必须要有*/
            cur = cur->right;
        }
        else
        {
            bt_node_t *node = cur->left;
            while (node->right != NULL && node->right != cur)
                node = node->right;
            if (node->right == NULL )   /* 还没线索化，则建立线索*/
            {
                node->right = cur;
                prev = cur; /* 必须要有*/
                cur = cur->left;
            }
            else     /* 已经线索化，则访问节点，并� 除线索 */
            {
                visit_reverse(cur->left, prev, visit); // call print
                prev->right = NULL;
                prev = cur; /* 必须要有*/
                cur = cur->right;
            }
        }
    }
}


bt_node_t *new_node(int i) {
    bt_node_t *node = (bt_node_t*)malloc(sizeof(bt_node_t));
    node->elem = i;
    node->left = NULL;
    node->right = NULL;
}

bt_node_t nodes[9];

void set_children(int node, int left, int right) {
    if (node != 0) {
        if (left != 0) {
            nodes[node - 1].left = &nodes[left-1];
        }
        if (right != 0) {
            nodes[node - 1].right = &nodes[right-1];
        }
    }
}

int visit(bt_node_t *node) {
    printf("%d ", node->elem);
    return 0;
}

void print_node_info(bt_node_t *node) {
    printf("%d ", node->elem);
    if (node->left != NULL) {
        printf("%d ", node->left->elem);
    } else {
        printf("0 ");
    }

    if (node->right != NULL) {
        printf("%d\n", node->right->elem);
    } else {
        printf("0\n");
    }
}

int main(int argc, char *argv[])
{

    for (int i = 0; i < 9; ++i) {        
        nodes[i].elem = i + 1;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }

    // in_order
//    set_children(6, 2, 7);
//    set_children(2, 1, 4);
//    set_children(4, 3, 5);
//    set_children(7, 0, 9);
//    set_children(9, 8, 0);

//    // pre_order
//    set_children(1, 2, 7);
//    set_children(2, 3, 4);
//    set_children(4, 5, 6);
//    set_children(7, 0 ,8);
//    set_children(8, 9, 0);

    // post_order
    set_children(9, 5, 8);
    set_children(5, 1, 4);
    set_children(4, 2, 3);
    set_children(8, 0 ,7);
    set_children(7, 6, 0);

//    in_order_morris(&nodes[5], visit);// this is ok// note that elem = id + 1
//    pre_order_morris(&nodes[0], visit);// this is ok// note that elem = id + 1
    post_order_morris(&nodes[8], visit);// this is ok// note that elem = id + 1

    return 0;
}

