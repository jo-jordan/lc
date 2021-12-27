//
// Created by lzjlxebr on 12/28/21.
//

#include <string.h>
#include <printf.h>

// KMP Algorithm
void Build(const char * p, int *nxt, int nlen) {
    int i, j;
    for (i = 2, j = 0; i <= nlen; i++) {
        while (j > 0 && p[i] != p[j + 1])
            j = nxt[j];

        if (p[i] == p[j + 1])
            ++j;
        nxt[i] = j;
    }
}

void strist(char * dst, char * strA, char * strB, int n) {
    strncpy(dst, strA, n);
    dst[n] = '\0';
    strcat(dst, strB);
    strcat(dst, strA + n);
}

int strStr(char * haystack, char * needle){
    if (strlen(needle) == 0) return 0;
    int nlen = (int) strlen(needle);
    int hlen = (int) strlen(haystack);

    // 这里内存消耗可能有点大
    char s[(hlen + 1) * 8];
    strist(s, haystack, "$", 0);

    char p[(nlen + 1) * 8];
    strist(p, needle, "$", 0);

    int nxt[nlen + 1], i, j;
    memset(nxt, 0, (nlen + 1) * sizeof(*nxt));
    Build(p, nxt, nlen);

    for (i = 1,j = 0; i <= hlen; i++) {
        while (j > 0 && s[i] != p[j + 1])
            j = nxt[j];
        if (s[i] == p[j + 1])
            ++j;
        if (j == nlen) {
            return i - nlen;
        }
    }

    return -1;
}

int main() {
    char * haystack = "hello";
    char * needle = "ll";
    printf("%s in %s first happen at index: %d", needle, haystack, strStr(haystack, needle));
}
