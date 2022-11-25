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


typedef struct str str_t;

struct str {
    const char* s;
    const char* e;
};

static const str_t NULLSTR = {
    .s = NULL,
    .e = NULL,
};

// creation
// ---------------------------------------------------------------------------------------------- //
str_t str_new(const char* s, size_t len);

// manipulation
// ---------------------------------------------------------------------------------------------- //
str_t str_cpy(str_t str, char* dest, size_t len);

// utility
// ---------------------------------------------------------------------------------------------- //
size_t str_len(str_t str);
bool str_eq(str_t str1, str_t str2);
bool str_cont(str_t cont, str_t test);
bool str_in_strs(str_t str, str_t* strs, size_t len);

// function descriptions
// ---------------------------------------------------------------------------------------------- //

#endif // CUTI_STRINGY_H
