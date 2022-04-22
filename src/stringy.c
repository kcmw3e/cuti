#include "xalloc.h"

#include "stringy.h"

#define nul '\0'

str_t str_new(size_t len) {
    str_t str = xcalloc(len + 1, sizeof(*str));
    return str;
}

str_t str_snew(const char* char_a, size_t len) {
    if (char_a == NULL) return NULL;

    str_t str = xmalloc(sizeof(*str)*(len + 1));
    if (str == NULL) return NULL;
    
    for (size_t i = 0; i < len + 1; i++) {
        char c = char_a[i];
        str[i] = c;
        if (c == nul) break;
    }

    str[len] = nul;

    return str;
}

void str_free(str_t str) {
    free(str);
}

size_t str_len(str_t str, size_t n) {
    for (size_t len = 0; len < n; len++) {
        char c = str[len];
        if (c == nul) return len;
    }
    return n;
}

void str_cpy(str_t str, str_t cpy, size_t n) {
    for (size_t i = 0; i < n; i++) {
        char c = str[i];
        cpy[i] = c;
        if (c == nul) return;
    }
    cpy[n - 1] = nul;
}

bool str_eq(str_t str1, str_t str2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        char c1 = str1[i];
        char c2 = str2[i];
        if (c1 != c2) return false;
        if (c1 == nul) return true;
    }
    return true;
}

bool str_in_strs(str_t str, str_t* strs_a, size_t strs_len, size_t n) {
    for (size_t i = 0; i < strs_len; i++) {
        if (str_eq(str, strs_a[i], n)) return true;
    }
    return false;
}