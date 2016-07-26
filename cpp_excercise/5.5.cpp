#include <stdlib.h>
#include <stralign.h>

typedef int heap_elem_t;

typedef struct heap_t {
    int size;
    int capacity;
    heap_elem_t *elems;
    int (*cmp)(const heap_elem_t*, const heap_elem_t*);
} heap_t;

int cmp_int(const int *x, const int *y) {
    const int sub = *x - *y;
    if (sub > 0) {
        return 1;
    } else if (sub < 0) {
        return -1;
    } else {
        return 0;
    }
}

heap_t *heap_create(const int capacity,
                    int (*cmp)(const heap_elem_t*, const heap_elem_t*)) {
    heap_t *h = (heap_t*)malloc(sizeof(heap_t));
    h->size = 0;
    h->capacity = capacity;
    h->elems = (heap_elem_t*)malloc(capacity * sizeof(heap_elem_t));
    h->cmp = cmp;

    return h;
}

voi dheap_destroy(heap_t *h) {
    free(h->elems);
    free(h);
}

int heap_empty(const heap_t *h) {
    return h->size == 0;
}

int heap_size(const heap_t *h) {
    return h->size;
}

void heap_sift_down(const heap_t *h, const int start) {
    int i = start;
    int j;
    const heap_elem_t tmp = h->elems[start];

    for (j = 2 * i + 1; j < h->size; j = 2*j + 1) {
        if (j < h->size - 1 &&
    }
}











