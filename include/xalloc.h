// license
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
#include <stdbool.h>

typedef char xbyte_t;

// wrappers
// ---------------------------------------------------------------------------------------------- //
void* xmalloc(size_t size);
void* xcalloc(size_t size, size_t num);
void* xrealloc(void* p, size_t size);

// memory utility
// ---------------------------------------------------------------------------------------------- //
void xmemset(xbyte_t mem[], xbyte_t b, size_t len);
void xmemcpy(xbyte_t src[], xbyte_t cpy[], size_t len);
bool xmemeq(xbyte_t mem1[], xbyte_t mem2[], size_t len);

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

// description
//  |> sets the bytes in [mem] to [b]
// parameters
//  |> [mem]: an array of bytes to be changed
//  |> [b]: the value to set each byte in [mem] to
//  |> [len]: minimum length of [mem], may be [0]
// notes
//  |> if [len] is greater than [0] and [mem] is passed as [NULL] [xerr()] will be called and
//  |   nothing else will happen
//  |> all bytes in [mem] will be changed up to and including [len - 1]
void xmemset(xbyte_t mem[], xbyte_t b, size_t len);

// description
//  |> copies the bytes in [src] to [cpy]
// parameters
//  |> [src]: an array of bytes containing the memory to be copied
//  |> [cpy]: an array of bytes to serve as the destination of the copied memory
//  |> [len]: minimum length of both [src] and [cpy], may be [0]
// notes
//  |> if [len] is greater than [0] and [src] or [cpy] is passed as [NULL] [xerr()] will be called
//  |   and nothing else will happen
//  |> all bytes in [cpy] will be changed up to and including [len - 1] using the corresponding
//  |   bytes in [src]
void xmemcpy(xbyte_t src[], xbyte_t cpy[], size_t len);

// description
//  |> check whether all bytes in two memory locations match
// parameters
//  |> [mem1]: a pointer to bytes in memory
//  |> [mem2]: a pointer to bytes in memory
//  |> [len]: minimum length of both [mem1] and [mem2]
// return
//  |> [true] if all bytes at [mem1] equal all bytes at [mem2]
// notes
//  |> if [len] is greater than [0] and [mem1] or [mem2] is passed as [NULL] [xerr()] will be called
//  |   and nothing else will happen
//  |> if [len] is [0] [mem1] and [mem2] will be considered equal
bool xmemeq(xbyte_t mem1[], xbyte_t mem2[], size_t len);

#endif // CUTI_XALLOC_H
