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

tk_t tk_begin(const char* s);
tk_t tk_next(tk_t tk);
bool tk_done(tk_t tk);

#endif // TOKENIZER_H
