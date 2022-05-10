#include "cuti.h"
#include "arraying.h"

bool array_has(xbyte_t array[], size_t len, size_t size, xbyte_t* match_p, compare_fn* compare_fn, void* args[]) {
    for (size_t i = 0; i < len; i++) {
        xbyte_t* elem_p = array + i*size;
        compare_result_t compare = (*compare_fn)(elem_p, match_p, args);
        if (compare == COMPARISON_EQUAL) return true;
    }
    return false;
}

void array_filter(xbyte_t array[], size_t len, size_t size, xbyte_t* rep_p, filter_fn* filter_fn, void* args[]) {
    for (size_t i = 0; i < len; i++) {
        xbyte_t* elem_p = array + i*size;
        bool passes_filter = (*filter_fn)(elem_p, args);
        if (!passes_filter) xmemcpy(rep_p, elem_p, size);
    }
}
