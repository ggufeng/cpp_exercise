#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

// @F to be understand!
void build_post(const char *pre, const char *in, const int n, char *post) {
    int left_len = strchr(in, pre[0]) - in;
    if (n <= 0) return;

    build_post(pre + 1, in, left_len, post);
    build_post(pre + left_len + 1, in + left_len + 1,
               n - left_len - 1, post + left_len);
    post[n - 1] = pre[0];
}

#define MAX 64
void build_post_test() {
    char pre[MAX] = {0};
    char in[MAX] = {0};
    char post[MAX] {0};
    int n;

    scanf("%s%s", pre, in);
    n = strlen(pre);

    build_post(pre, in, n, post);
    printf("%s\n", post);
}

typedef char elem_t;

typedef struct bt_node_t {
    elem_t elem;
    bt_node_t *left;
    bt_node_t *right;
} bt_node_t;

void rebuild(const char *pre, const char *in, int n, bt_node_t **root) {
    int left_len;
    if (n <= 0 || pre == NULL || in == NULL)
        return;

    *root = (bt_node_t*) malloc(sizeof(bt_node_t));
    (*root)->elem = *pre;
    (*root)->left = NULL;
    (*root)->right = NULL;

    left_len = strchr(in, pre[0]) - in;
    rebuild(pre + 1, in, left_len, &((*root)->left));
    rebuild(pre + left_len + 1, in + left_len + 1, n - left_len -1,
            &((*root)->right));
}


void print_post_order(const bt_node_t *root) {
    if (root != NULL) {
        print_post_order(root->left);
        print_post_order(root->right);
        printf("%c", root->elem);
    }
}

void rebuild_test() {
    char pre[MAX] = {0};
    char in[MAX] = {0};
    int n;
    bt_node_t *root;
    scanf("%s%s", pre, in);
    n = strlen(pre);

    rebuild(pre, in, n, &root);
    print_post_order(root);
}

int main() {
    build_post_test();
    rebuild_test();
    return 0;
}







