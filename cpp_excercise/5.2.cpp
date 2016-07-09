//#include <stddef.h> // for NULL
//#include <stdio.h>

//typedef int elem_t;

//typedef struct tbt_node_t {
//    int ltag;
//    int rtag;
//    tbt_node_t *left; // u can have struct before it
//    tbt_node_t *right;
//    elem_t elem;
//} tbt_node_t;

//static void in_thread(tbt_node_t *p, tbt_node_t *pre);
//static tbt_node_t *first(tbt_node_t *p);
//static tbt_node_t *next(const tbt_node_t *p);

//static tbt_node_t *first(tbt_node_t *p) {
//    if (p == NULL) return NULL;//
//    while (p->ltag == 0) {//
//        p = p->left;
//    }
//    return p;//
//}

//static tbt_node_t *next(const tbt_node_t *p) {
//    if (p->rtag == 0) {
//        return first(p->right);
//    } else {
//        return p->right;
//    }
//}

//static void in_thread(tbt_node_t *p, tbt_node_t **pre) {
//    if (p != NULL) {//
//        in_thread(p->left, pre);
//        if (p->left == NULL) {//
//            p->left = *pre;
//            p->ltag = 1;
//        }
//        if (*pre != NULL &&//
//            (*pre)->right == NULL) {//
//            (*pre)->right = p;
//            (*pre)->rtag = 1;
//        }
//        *pre = p;
//        in_thread(p->right, pre);
//    }

//}

//void in_order(tbt_node_t *root, int(*visit)(tbt_node_t*)) {
//    tbt_node_t *p;//
//    for (p = first(root); p != NULL; p = next(p)) { //
//        visit(p);
//    }
//}

//void create_in_thread(tbt_node_t *root) {
//    if (root != NULL) {
//        tbt_node_t *pre = NULL;
//        in_thread(root, &pre);//
//        pre->right = NULL;
//        pre->rtag = 1;
//    }
//}

//int main(int argc, char *argv[])
//{

//    return 0;
//}
