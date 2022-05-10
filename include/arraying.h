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

typedef compare_result_t compare_fn(xbyte_t* elem1, xbyte_t* elem2, void* args[]);
typedef bool filter_fn(xbyte_t* elem, void* args[]);

bool array_has(xbyte_t array[], size_t len, size_t size, xbyte_t* match_p, compare_fn* compare_fn, void* args[]);
void array_filter(xbyte_t array[], size_t len, size_t size, xbyte_t* rep_p, filter_fn* filter_fn, void* args[]);

#endif // CUTI_ARRAYING_H
