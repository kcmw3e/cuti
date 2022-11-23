// license
// ---------------------------------------------------------------------------------------------- //
// Copyright (c) 2022, Casey Walker
// All rights reserved.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
//
// charnip.h
// ---------------------------------------------------------------------------------------------- //
// A collection of string manipulation functions with built-in overflow safety.

#ifndef CUTI_CHARNIP_H
#define CUTI_CHARNIP_H

#include <stdbool.h>

bool isalph(char c);
bool isnum(char c);
bool isalphnum(char c);
bool iswhite(char c);
bool isgroup(char c);
bool ispunc(char c);
bool ismathop(char c);
bool isspecial(char c);

#endif // CUTI_CHARNIP_H
