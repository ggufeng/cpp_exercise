#include <stddef.h> // for NULL
#include <stdio.h>

typedef int elem_t;

typedef struct tbt_node_t {
    int ltag;
    int rtag;
    tbt_node_t *left; // u can have struct before it
    tbt_node_t *right;
    elem_t elem;
} tbt_node_t;

static void in_thread(tbt_node_t *p, tbt_node_t *pre);
static tbt_node_t *first(tbt_node_t *p);
static tbt_node_t *next(const tbt_node_t *p);

static tbt_node_t *first(tbt_node_t *p) {
    tbt_node_t *res = p;
    while (p->ltag != NULL) {

    }
}

int main(int argc, char *argv[])
{

    return 0;
}
