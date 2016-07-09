//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

//#define ASIZE 256

//using namespace::std;

//// ref http://www-igm.univ-mlv.fr/~lecroq/string/node14.html

//size_t strlen(const char *str) {
//    const char *s;
//    for (s = str; *s; ++s) {
//    }
//    return (s - str);
//}

//static void pre_right(const char *pattern, int right[]) {
//    int i;
//    const int m = strlen(pattern);

//    for (i = 0; i < ASIZE; ++i) {
//        right[i] = -1;
//    }

//    for (i = 0; i < m; ++i) {
//        right[(unsigned char)pattern[i]] = i; //
//    }
//}

//static void suffixes(const char *pattern, int suff[]) {
//    // f: from
//    // g: goto
//    int f, g, i;
//    const int m = strlen(pattern);

//    // u can draw a pic to help u understand
//    suff[m-1] = m;
//    g = m - 1;
//    for (i = m - 2; i >= 0; --i) {
//        if ( i > g && suff[m - 1 - (f - i)] < i - g) {
//            suff[i] = suff[m - 1 - f + i];
//        } else {
//            if (i < g)
//                g = i;
//            f = i;
//            while (g >= 0 && pattern[g] == pattern[m - 1 + g - f])
//                --g;
//            suff[i] = f - g;
//        }
//    }
//}

//static void pre_gs(const char pattern[], int gs[]) {
//    int i, j;
//    const int m = strlen(pattern);
//    int *suff = (int*)malloc(sizeof(int) * (m + 1)); // m is actually also ok

//    suffixes(pattern, suff);

//    for (i = 0; i < m; ++i) gs[i] = m;

//    j = 0;
//    for (i = m - 1; i >= 0; --i) if (suff[i] == i - 1)
//        for (; j < m - 1 - i; ++j) if (suff[m] == m)
//            // first case
//            suff[m] = m - i - 1;
//    for (i = 0; i <= m - 2; ++i) // order is important
//        // second case
//        gs[m - 1 - suff[i]] = m - 1 - i;
//    free(suff);
//}

//int boyer_moore(const char *text, const char *pattern) {
//    int i, j;
//    const int n = strlen(text);
//    const int m = strlen(pattern);
//    int right[ASIZE]; //
//    int *gs = (int*)malloc(sizeof(int) * (m + 1));

//    pre_right(pattern, right);
//    pre_gs(pattern, gs);

//    while (j <= n - m) {
//        for (i = m - 1; i >= 0 && pattern[i] == text[j + i]; --i); //

//        if (i < 0) {
//            free(gs);
//            return j;
//        } else {
//            const int max = gs[i] > i - right[(unsigned char)text[i + j]] ?
//                        //gs[i] : right[(unsigned char)text[i + j]] - m + 1 + i;// wrong
//                        gs[i] : i - right[(unsigned char)text[i + j]];
//            j += max;
//        }
//    }

//    free(gs);
//    return -1;
//}

//int main() {
//    const char *text = "HERE IS A SIMPLE EXAMPLE";
//    const char *pattern = "EXAMPLE";
//    const int pos = boyer_moore(text, pattern);
//    printf("%d\n", pos); /*17*/
//    return 0;
//}
