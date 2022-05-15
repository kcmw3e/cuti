// license
// ---------------------------------------------------------------------------------------------- //
// Copyright (c) 2022, Casey Walker
// All rights reserved.
// 
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
//
// arraying.h
// ---------------------------------------------------------------------------------------------- //
// A set of functions to work with generic arrays

#ifndef CUTI_ARRAYING_H
#define CUTI_ARRAYING_H

#include <stdbool.h>
#include <stdlib.h>

#include "cuti.h"

enum compare_result {
    COMPARISON_LESS = -1,
    COMPARISON_EQUAL = 0,
    COMPARISON_GREATER = 1,
    COMPARISON_NOT_EQUAL = 2147483647,
};
typedef enum compare_result compare_result_t;

struct arrayable {
    xbyte_t* bytes;
    size_t elem_size;
    size_t len;
};
typedef struct arrayable arrayable_t;
#define QUICKRAY(_bytes, _len)                                                                     \
    {                                                                                              \
        .bytes = (xbyte_t*)_bytes,                                                                 \
        .elem_size = (size_t)sizeof(*_bytes),                                                      \
        .len = (size_t)_len,                                                                       \
    }
#define QUICKRAY_EMPTY(_NULL, _len)                                                                \
    {                                                                                              \
        .bytes = NULL,                                                                             \
        .elem_size = 0,                                                                            \
        .len = 0,                                                                                  \
    }

typedef compare_result_t compare_fn(xbyte_t* elem1, xbyte_t* elem2, void* args);
typedef bool filter_fn(xbyte_t* elem, void* args);

// general
// ---------------------------------------------------------------------------------------------- //
void array_filter(arrayable_t array, xbyte_t* rep_p, filter_fn* filter_fn, void* args);
bool array_has(arrayable_t array, xbyte_t* match_p, compare_fn* compare_fn, void* args);
bool array_hasall(arrayable_t array, arrayable_t matches, compare_fn* compare_fn, void* args);
bool array_hasany(arrayable_t array, arrayable_t matches, compare_fn* compare_fn, void* args);


// function descriptions
// ---------------------------------------------------------------------------------------------- //

// description
//  |> checks whether array elements pass a filter, and replaces any elements that do not
// parameters
//  |> [array]: any generic array
//  |   |> [.bytes]: a pointer the data of the array, must not be [NULL]
//  |   |> [.elem_size]: the size of each element in [.bytes], must be greater than [0]
//  |   |> [.len]: the minimum number of elements in [.bytes], may be [0]
//  |   |> NOTE: [.elem_size*.len] must describe the minimum size of the memory at [.bytes]
//  |> [rep_p]: a pointer to a generic element used to replace any element in [array] that does not
//  |   pass the filter, must not be [NULL]
//  |> [filter_fn]: a function that returns [false] if an element in [array] should be replaced or
//  |   [true] if it should be kept, must not be [NULL]
//  |> [args]: any extra arguments needed for [filter_fn]
void array_filter(arrayable_t array, xbyte_t* rep_p, filter_fn* filter_fn, void* args);

// description
//  |> checks whether an array has a specific element
// parameters
//  |> [array]: any generic array
//  |   |> [.bytes]: a pointer the data of the array, must not be [NULL]
//  |   |> [.elem_size]: the size of each element in [.bytes], must be greater than [0]
//  |   |> [.len]: the minimum number of elements in [.bytes], may be [0]
//  |   |> NOTE: [.elem_size*.len] must describe the minimum size of the memory at [.bytes]
//  |> [match_p]: a pointer to a generic element used to match against any element in [array]
//  |> [compare_fn]: a function that returns [COMPARISON_EQUAL] if an element in [array] matches
//  |   the element at [match_p], must not be [NULL]
//  |> [args]: any extra arguments needed for [compare_fn]
// return
//  |>  [true] if the element at [match_p] was found in [array] or [false] otherwise
// notes
//  |> if the length of [array] is [0], [false] will be returned
bool array_has(arrayable_t array, xbyte_t* match_p, compare_fn* compare_fn, void* args);

// description
//  |> checks whether an array has all elements of another array
// parameters
//  |> [array]: any generic array
//  |   |> [.bytes]: a pointer the data of the array, must not be [NULL]
//  |   |> [.elem_size]: the size of each element in [.bytes], must be greater than [0]
//  |   |> [.len]: the minimum number of elements in [.bytes], may be [0]
//  |   |> NOTE: [.elem_size*.len] must describe the minimum size of the memory at [.bytes]
//  |> [matches]: any generic array with all the elements to check for
//  |   |> [.bytes]: a pointer the data of the array, must not be [NULL]
//  |   |> [.elem_size]: the size of each element in [.bytes], must be greater than [0]
//  |   |> [.len]: the minimum number of elements in [.bytes], may be [0]
//  |   |> NOTE: [.elem_size*.len] must describe the minimum size of the memory at [.bytes]
//  |> [compare_fn]: a function that returns [COMPARISON_EQUAL] if an element in [array] matches
//  |   some element in [matches], must not be [NULL]
//  |> [args]: any extra arguments needed for [compare_fn]
// return
//  |>  [true] if all elements in [matches] were found in [array] or [false] otherwise
// notes
//  |> if the length of [matches] is [0], [true] will be returned
//  |> if the length of [array] is [0], [false] will be returned
//  |> if the length of both [matches] and [array] is [0], [true] will be returned
bool array_hasall(arrayable_t array, arrayable_t matches, compare_fn* compare_fn, void* args);

// description
//  |> checks whether an array has any element of another array
// parameters
//  |> [array]: any generic array
//  |   |> [.bytes]: a pointer the data of the array, must not be [NULL]
//  |   |> [.elem_size]: the size of each element in [.bytes], must be greater than [0]
//  |   |> [.len]: the minimum number of elements in [.bytes], may be [0]
//  |   |> NOTE: [.elem_size*.len] must describe the minimum size of the memory at [.bytes]
//  |> [matches]: any generic array with all the elements to check for
//  |   |> [.bytes]: a pointer the data of the array, must not be [NULL]
//  |   |> [.elem_size]: the size of each element in [.bytes], must be greater than [0]
//  |   |> [.len]: the minimum number of elements in [.bytes], may be [0]
//  |   |> NOTE: [.elem_size*.len] must describe the minimum size of the memory at [.bytes]
//  |> [compare_fn]: a function that returns [COMPARISON_EQUAL] if an element in [array] matches
//  |   some element in [matches], must not be [NULL]
//  |> [args]: any extra arguments needed for [compare_fn]
// return
//  |>  [true] if any element in [matches] was found in [array] or [false] otherwise
// notes
//  |> if the length of [matches] is [0], [false] will be returned
//  |> if the length of [array] is [0], [false] will be returned
//  |> if the length of both [matches] and [array] is [0], [false] will be returned
bool array_hasany(arrayable_t array, arrayable_t matches, compare_fn* compare_fn, void* args);

#endif // CUTI_ARRAYING_H
