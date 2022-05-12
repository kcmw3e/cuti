#include "cuti.h"
#include "arraying.h"

void array_filter(arrayable_t array, xbyte_t* rep_p, filter_fn* filter_fn, void* args) {
    for (size_t i = 0; i < array.len; i++) {
        xbyte_t* elem_p = array.bytes + array.elem_size*i;

        bool passes_filter = (*filter_fn)(elem_p, args);
        if (!passes_filter) xmemcpy(rep_p, elem_p, array.elem_size);
    }
}

bool array_has(arrayable_t array, xbyte_t* match_p, compare_fn* compare_fn, void* args) {
    for (size_t i = 0; i < array.len; i++) {
        xbyte_t* elem_p = array.bytes + array.elem_size*i;
        compare_result_t compare = (*compare_fn)(elem_p, match_p, args);
        if (compare == COMPARISON_EQUAL) return true;
    }
    return false;
}

bool array_hasall(arrayable_t array, arrayable_t matches, compare_fn* compare_fn, void* args) {
    for (size_t i = 0; i < matches.len; i++) {
        xbyte_t* match_p = matches.bytes + matches.elem_size*i;
        if (!array_has(array, match_p, compare_fn, args)) return false;
    }
    return true;
}

bool array_hasany(arrayable_t array, arrayable_t matches, compare_fn* compare_fn, void* args) {
    for (size_t i = 0; i < matches.len; i++) {
        xbyte_t* match_p = matches.bytes + matches.elem_size*i;
        if (array_has(array, match_p, compare_fn, args)) return true;
    }
    return false;
}
