#include "xalloc.h"
#include "xerr.h"

void* xmalloc(size_t size) {
    void* p = malloc(size);
    if (p == NULL) xerr(XERR_ALLOCATION_FAIURE);
    return p;
}

void* xcalloc(size_t num, size_t size) {
    void* p = calloc(num, size);
    if (p == NULL) xerr(XERR_ALLOCATION_FAIURE);
    return p;
}

void* xrealloc(void* p, size_t size) {
    p = realloc(p, size);
    if (p == NULL) xerr(XERR_ALLOCATION_FAIURE);
    return p;
}

void xmemset(xbyte_t mem[], xbyte_t b, size_t len) {
    if (mem == NULL) {
        xerr(XERR_NULL_CHECK_FAILED);
        return;
    }

    for (size_t i = 0; i < len; i++) mem[i] = b;
}

void xmemcpy(xbyte_t src[], xbyte_t cpy[], size_t len) {
    if (src == NULL || cpy == NULL) {
        xerr(XERR_NULL_CHECK_FAILED);
        return;
    }

    for (size_t i = 0; i < len; i++) cpy[i] = src[i];
}
