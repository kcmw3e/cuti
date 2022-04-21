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
