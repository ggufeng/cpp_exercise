#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace::std;

size_t strlen(const char *str) {
    const char *s;
    for (s = str; *s; ++s) {
    }
    return (s - str);
}

void compute_prefix(const char *pattern, int next[]) {
    int i;
    int j = -1;// pointer to the prior pos
    const int m = strlen(pattern);

    next[0] = j;
    for (i = 1; i < m; ++i) {
        if (j > -1 && pattern[i] != pattern[j+1]) j = next[j];

        while (pattern[i] == pattern[j+1]) ++j;

        next[i] = j;
    }

}

int kmp(const char *text, const char *pattern) {
    int i;
    int j = -1;
    const int n = strlen(text);
    const int m = strlen(pattern);
    if (n == 0 && m == 0) return 0; //
    if (m == 0) return 0;//
    int *next = (int *)malloc(sizeof(int) * m);

    compute_prefix(pattern, next);

    for (i = 0; i < n; ++i) {
        if (j > -1 && pattern[j+1] != text[i]) j = next[j];

        if (next[j+1] == next[i])// without && j < m - 1, unnecessary
            ++j;

        if (j == m - 1) {
            free(next);
            return i - j;
        }
    }

    free(next);
    return -1;
}

int main(int argc, char *argv[])
{
    char text[] = "ABC ABCDAB ABCDABDABCDABDDABDE";
    char pattern[] = "ABCDABD";
    char *ch = text;
    int i = kmp(text, pattern);

    if (i > 0) printf("matched @: %s\n", ch + i);
    return 0;
}

