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

// general
// ---------------------------------------------------------------------------------------------- //
bool array_has(xbyte_t array[], size_t len, size_t size, xbyte_t* match_p, compare_fn* compare_fn, void* args[]);
void array_filter(xbyte_t array[], size_t len, size_t size, xbyte_t* rep_p, filter_fn* filter_fn, void* args[]);


// function descriptions
// ---------------------------------------------------------------------------------------------- //

// description
//  |> checks whether an array has a specific element
// parameters
//  |> [array]: a generic array, represented as bytes in memory
//  |> [len]: length of array in number of elements
//  |> [size]: length of each element in the array
//  |> [match_p]: a pointer to an element to check for
//  |> [compare_fn]: a function used to compare two elements in the array
//  |> [args]: any extra arguments needed for [compare_fn]
// return
//  |> [true] if any element in [array] was found using [compare_fn] to match with the element at
//  |   [match_p], or [false] if not found in the array
// notes
//  |> [compare_fn] is a function that takes a pointer to two elements passed as [xbyte_t] and
//  |   returns a [compare_result_t], and if the result is [COMPARISON_EQUAL] the element at
//  |   [match_p] is considered found
//  |> [compare_fn] should also have a parameter for [args] even if not used, in which case [args]
//  |   may be passed to [array_has()] as [NULL]
//  |> [args] is never used in [array_has()] and can be any pointer
bool array_has(xbyte_t array[], size_t len, size_t size, xbyte_t* match_p, compare_fn* compare_fn, void* args[]);

// description
//  |> checks whether array elements pass a filter, and replaces any elements that do not
// parameters
//  |> [array]: a generic array, represented as bytes in memory
//  |> [len]: length of array in number of elements
//  |> [size]: length of each element in the array
//  |> [rep_p]: a pointer to an element used to replace the elements that fail the filter
//  |> [filter_fn]: a function used to filter the elements in [array]
//  |> [args]: any extra arguments needed for [filter_fn]
// notes
//  |> [filter_fn] is a function that takes a pointer to an element passed as [xbyte_t] and
//  |   returns [true] if it should be kept or [false] if it should be replaced
//  |> [filter_fn] should also have a parameter for [args] even if not used, in which case [args]
//  |   may be passed to [array_has()] as [NULL]
//  |> [args] is never used in [array_has()] and can be any pointer
void array_filter(xbyte_t array[], size_t len, size_t size, xbyte_t* rep_p, filter_fn* filter_fn, void* args[]);

#endif // CUTI_ARRAYING_H
