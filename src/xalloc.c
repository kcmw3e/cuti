#include "xalloc.h"
#include "xerr.h"

void* xmalloc(size_t size) {
    void* p = malloc(size);
    if (p == NULL) xerr(XERR_ALLOCATION_FAILURE);
    return p;
}

void* xcalloc(size_t num, size_t size) {
    void* p = calloc(num, size);
    if (p == NULL) xerr(XERR_ALLOCATION_FAILURE);
    return p;
}

void* xrealloc(void* p, size_t size) {
    p = realloc(p, size);
    if (p == NULL) xerr(XERR_ALLOCATION_FAILURE);
    return p;
}

void xmemset(xbyte_t mem[], xbyte_t b, size_t len) {
    if (len == 0) return;
    if (mem == NULL) {
        xerr(XERR_NULL_CHECK_FAILURE);
        return;
    }

    for (size_t i = 0; i < len; i++) mem[i] = b;
}

void xmemcpy(xbyte_t src[], xbyte_t cpy[], size_t len) {
    if (len == 0) return;
    if (src == NULL) {
        xerrm(XERR_NULL_CHECK_FAILURE, "src cannot be [NULL]");
        return;
    }
    if (cpy == NULL) {
        xerrm(XERR_NULL_CHECK_FAILURE, "cpy cannot be [NULL]");
        return;
    }

    for (size_t i = 0; i < len; i++) cpy[i] = src[i];
}

bool xmemeq(xbyte_t mem1[], xbyte_t mem2[], size_t len) {
    for (size_t i = 0; i < len; i++) if (mem1[i] != mem2[i]) return false;
    return true;
}
