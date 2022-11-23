#include "xalloc.h"

#include "stringy.h"

#define nul '\0'

str_t str_new(const char* s, size_t len) {
    str_t str = {
        .s = s,
        .e = s + len,
    };
    return str;
}

size_t str_len(str_t str) {
    return str.e - str.s;
}

str_t str_cpy(str_t str, char* dest, size_t len) {
    str_t cpy = str_new(dest, len);

    while (str.s < str.e && dest < cpy.e) {
        *(dest) = *(str.s);
        str.s++;
        dest++;
    }

    return cpy;
}

bool str_eq(str_t str0, str_t str1) {
    while (str0.s < str0.e && str1.s < str1.e) {
        if (*(str0.s) != *(str1.s)) return false;
        str0.s++;
        str1.s++;
    }
    return true;
}

bool str_cont(str_t cont, str_t test) {
    while (cont.s < cont.e) {
        if (str_len(cont) < str_len(test)) return false; // in this case, there is no more room for test to exist in cont
        if (str_eq(cont, test)) return true;
        cont.s++;
    }
    return false;
}

bool str_in_strs(str_t str, str_t* strs, size_t len) {
    for (size_t i = 0; i < len; i++) {
        if (str_eq(str, strs[i])) return true;
    }
    return false;
}
