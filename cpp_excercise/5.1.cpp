#include <iostream>
#include <stack>
#include <queue>

using namespace::std;

typedef int tree_node_elem_t;

struct binary_tree_node_t {
    binary_tree_node_t *left;
    binary_tree_node_t *right;
    tree_node_elem_t elem;
};

void pre_order_r(const binary_tree_node_t *root,
                  int (*visit)(const binary_tree_node_t*)) {
    if (root == nullptr) return;

    visit(root);
    pre_order_r(root->left, visit);
    pre_order_r(root->right, visit);
}

void in_order_r(const binary_tree_node_t *root,
                  int (*visit)(const binary_tree_node_t*)) {
    if (root == nullptr) return;

    pre_order_r(root->left, visit);
    visit(root);
    pre_order_r(root->right, visit);
}

void post_order_r(const binary_tree_node_t *root,
                  int (*visit)(const binary_tree_node_t*)) {
    if (root == nullptr) return;

    pre_order_r(root->left, visit);
    pre_order_r(root->right, visit);
    visit(root);
}

void pre_order(const binary_tree_node_t *root,
               int (*visit)(const binary_tree_node_t *)) {
    const binary_tree_node_t *p;
    stack<const binary_tree_node_t *> s;

    p = root;

    if (p != nullptr) s.push(p);

    while (!s.empty()) {
        p = s.top();
        s.pop();
        visit(p);

        if (p->right != nullptr) s.push(p->right);
        if (p->left != nullptr) s.push(p->left);
    }
}

void in_order(const binary_tree_node_t *root,
               int (*visit)(const binary_tree_node_t *)) {
    const binary_tree_node_t *p;
    stack<const binary_tree_node_t *> s;

    p = root;

    if (p != nullptr) s.push(p);

    while (!s.empty() || p != nullptr) {
        if (p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            visit(p);
            p = p->right;
        }
    }
}

void post_order(const binary_tree_node_t *root,
               int (*visit)(const binary_tree_node_t *)) {
    const binary_tree_node_t *p, *q;
    stack<const binary_tree_node_t *> s;

    p = root;

    do {
        while (p != nullptr) {
            s.push(p);
            p = p->left;
        }
        q = nullptr;
        while(!s.empty()) {
            p = s.top();
            s.pop();
            if (p->right == q) {
                visit(p);
                q = p;
            } else {
                s.push(p);
                p = p->right;
                break;
            }
        }
    } while (!s.empty());
}

void level_order(const binary_tree_node_t *root,
                 int (*visit)(const binary_tree_node_t*)) {
    const binary_tree_node_t *p;
    queue<const binary_tree_node_t *> q;

    p = root;

    if (p != nullptr) q.push(p);

    while(!q.empty()) {
        p = q.front();
        q.pop();
        visit(p);

        if(p->left != nullptr) q.push(p->left);
        if(p->right!= nullptr) q.push(p->right);
    }
}

int main(int argc, char *argv[])
{

    return 0;
}


