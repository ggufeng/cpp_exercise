#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASIZE 256

using namespace::std;

size_t strlen(const char *str) {
    const char *s;
    for (s = str; *s; ++s) {
    }
    return (s - str);
}

static void pre_right(const char *pattern, int right[]) {
    int i;
    const int m = strlen(pattern);

    for (i = 0; i < ASIZE; ++i) {
        right[i] = -1;
    }

    for (i = 0; i < m; ++i) {
        right[(unsigned char)pattern[i]] = i; //
    }
}

static void suffixes(const char *pattern, int suff[]) {

}

static void pre_gs(const char pattern[], int gs[]) {

}

int boyer_moore(const char *text, const char *pattern) {

}

int main() {
    const char *text = "HERE IS A SIMPLE EXAMPLE";
    const char *pattern = "EXAMPLE";
    const int pos = boyer_moore(text, pattern);
    printf("%d\n", pos); /*17*/
    return 0;
}
