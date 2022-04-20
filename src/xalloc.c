#include "xalloc.h"
#include "xerr.h"

void* xmalloc(size_t size) {
    void* p = malloc(size);
    if (size == NULL) xerr(XERR_ALLOCATION_FAIURE);
    return p;
}

void* xcalloc(size_t num, size_t size) {
    void* p = calloc(num, size);
    if (size == NULL) xerr(XERR_ALLOCATION_FAIURE);
    return p;
}

void* xrealloc(size_t num, size_t size) {
    void* p = realloc(num, size);
    if (size == NULL) xerr(XERR_ALLOCATION_FAIURE);
    return p;
}
