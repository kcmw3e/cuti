// license
// ---------------------------------------------------------------------------------------------- //
// Copyright (c) 2022, Casey Walker
// All rights reserved.
// 
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
//
// stringy.h
// ---------------------------------------------------------------------------------------------- //
// A collection of string manipulation functions with built-in overflow safety.

#ifndef CUTI_STRINGY_H
#define CUTI_STRINGY_H

#include <stdlib.h>
#include <stdbool.h>


typedef char* str_t;


// creation and freeing
// ---------------------------------------------------------------------------------------------- //
str_t str_new(size_t len);
str_t str_snew(const char* C, size_t len);
void str_free(str_t str);


// manipulation
// ---------------------------------------------------------------------------------------------- //
void str_cpy(str_t str, str_t cpy, size_t n);


// utility
// ---------------------------------------------------------------------------------------------- //
size_t str_len(str_t str, size_t n);
bool str_eq(str_t str1, str_t str2, size_t n);
bool str_in_strs(str_t str, str_t* strs_a, size_t strs_len, size_t n);


// function descriptions
// ---------------------------------------------------------------------------------------------- //

// description
//  |> allocates a new [str_t] object
// parameters
//  |> [len]: length of string to be allocated, not including the terminating nul character
// returns
//  |> a [str_t] string initialized to 0 that can be used in any cuti library function, or [NULL] if
//  |   error
// notes
//  |> if [NULL] is returned an allocation error occurred
str_t str_new(size_t len);

// description
//  |> allocates a new [str_t] object initialized to the string in [char_a]
// parameters
//  |> [char_a]: a character array containing the string to initialize the new [str_t] with, must
//  |   not be NULL
//  |> [len]: length of string to be allocated and the minimum length of [char_a], not including
//  |   any terminating nul character
// return
//  |> a [str_t] string that can be used in any cuti library functions, or [NULL] if error
// notes
//  |> if [NULL] is returned an allocation error occurred
//  |> if the nul character was not reached after [len] characters in [char_a], the returned string
//  |   will have all characters in [char_a] leading up to [char_a[len]] followed by a nul character
//  |   such that the new string is nul-terminated
str_t str_snew(const char* char_a, size_t len);

// description
//  |> frees a valid [str_t]
// parameters
//  |> [str]: a valid [str_t] or [NULL]
void str_free(str_t str);

// description
//  |> get the length of string [str] within the range [n]
// parameters
//  |> [str]: a valid [str_t] to retrieve the length of
//  |> [n]: the minimum length of [str], including any terminating nul character
// return
//  |> the number of characters in [str] before the first nul character, or [n] if a nul character
//  |   was not reached
size_t str_len(str_t str, size_t n);

// description
//  |> copy the string [str] to [cpy] within the range [n]
// parameters
//  |> [str]: a valid [str_t] to copy
//  |> [cpy]: a valid [str_t] that serves as the destination to copy to
//  |> [n]: the minimum length of both [str] and [cpy], including any terminating nul character
// notes
//  |> if a nul character is not reached by [n] characters, cpy will still contain the nul
//  |   character in the [n - 1] position
void str_cpy(str_t str, str_t cpy, size_t n);

// description
//  |> compares the first [n] characters in two strings to check for equality
// parameters
//  |> [str1]: the first string to compare
//  |> [str2]: the second string to compare
//  |> [n]: the minimum number of characters in [str1] and [str2], including any terminating nul
//  |   character
// return
//  |> [true] if all characters in [str1] equal the characters in the same positions of [str2], or
//  |   [false] if any character differs
// notes
//  |> the comparison stops after the first nul character is reached so that any difference in
//  |   characters following is not considered
//  |> only the first [n] characters are checked, so should [str1] or [str2] contain more characters
//  |   they will not be checked
bool str_eq(str_t str1, str_t str2, size_t n);

// description
//  |> checks whether a string is contained in an array of strings
// parameters
//  |> [str]: the string to look for
//  |> [strs_a]: an array of strings to look in for [str]
//  |> [strs_len]: the length of the array [strs_a]
//  |> [n]: the minimum length of any string supplied whether [str] or one of [strs_a], including
//  |   any nul-terminating character
// return
//  |> [true] if [str] could be matched to any string in [strs] or [false] otherwise
// notes
//  |> calls [str_eq()] on each string in [strs_a] until [str] is found or all the strings in
//  |   [strs_a] have been checked
bool str_in_strs(str_t str, str_t* strs_a, size_t strs_len, size_t n);

#endif // CUTI_STRINGY_H
