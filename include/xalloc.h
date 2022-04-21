// License
// ---------------------------------------------------------------------------------------------- //
// Copyright (c) 2022, Casey Walker
// All rights reserved.
// 
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
//
// xalloc.h
// ---------------------------------------------------------------------------------------------- //
// A small set of functions to wrap allocation builtins and handle erros.

#ifndef CUTI_XALLOC_H
#define CUTI_XALLOC_H

#include <stdlib.h>


// wrappers
// ---------------------------------------------------------------------------------------------- //
void* xmalloc(size_t size);
void* xcalloc(size_t size, size_t num);
void* xrealloc(void* p, size_t size);



// function descriptions
// ---------------------------------------------------------------------------------------------- //

// description
// |> same as [malloc] but throws allocation errors
void* xmalloc(size_t size);

// description
// |> same as [calloc] but throws allocation errors
void* xcalloc(size_t size, size_t num);

// description
// |> same as [realloc] but throws allocation errors
void* xrealloc(void* p, size_t size);

#endif // CUTI_XALLOC_H