// license
// ---------------------------------------------------------------------------------------------- //
// Copyright (c) 2022, Casey Walker
// All rights reserved.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
//
// tokenizer.h
// ---------------------------------------------------------------------------------------------- //
// A toolset for tokenizing strings

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "xerr.h"

#include <stdbool.h>
#include <stdlib.h>

typedef struct tk tk_t;

struct tk {
    const char* start;
    const char* end;
};

// iterator functions for tokenization
// ---------------------------------------------------------------------------------------------- //
tk_t tk_begin(const char* s);
tk_t tk_next(tk_t tk);
bool tk_done(tk_t tk);

// function descriptions
// ---------------------------------------------------------------------------------------------- //

// description
//  |> initializes the token iterator and finds/creates the first token
// parameters
//  |> [s]: the string to search for tokens in
// returns
//  |> a [str_t] string initialized to 0 that can be used in any cuti library function, or [NULL] if
//  |   error
// notes
//  |> the string [s] must NOT be freed while using the iterator; if tokens are meant to be kept in
//  |   memory on their own after [s] is freed, they must explicitly be copied somewhere else
tk_t tk_begin(const char* s);

// description
//  |> finds the next token in the string specified when calling [tk_begin()]
// parameters
//  |> [tk]: the iterator being used to find tokens (aka the previous token)
// returns
//  |> the next token found in the string
// notes
//  |> to check if there are no more tokens, use [tk_done()]
tk_t tk_next(tk_t tk);

// description
//  |> check if the iterator is done and there are no more tokens in the string
// parameters
//  |> [tk]: the token iterator being used
// returns
//  |> [true] if there are more tokens in the string or [false] if there are none left
// notes
//  |> if [tk_done()] isn't checked properly, the tokenizer will continuously return empty string
//  |   tokens (which is essentially the same as checking [tk_done()])
bool tk_done(tk_t tk);

#endif // TOKENIZER_H
