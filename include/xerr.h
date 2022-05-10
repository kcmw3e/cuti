// license
// ---------------------------------------------------------------------------------------------- //
// Copyright (c) 2022, Casey Walker
// All rights reserved.
// 
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
//
// xerr.h
// ---------------------------------------------------------------------------------------------- //
// A small set of functions to handle the tracking of errors as well as logging

#ifndef CUTI_XERR_H
#define CUTI_XERR_H

#include <stdio.h>

enum xerr_e {
    XERR_UNDEFINED,
    XERR_SUCCESS,
    XERR_FAILURE,
    XERR_ALLOCATION_FAILURE,
    XERR_NULL_CHECK_FAILURE,
    XERR_STRING_OVERFLOW,
    XERR_ERR_STACK_OVERFLOW,
    XERR_UNKNOWN,
    XERR_MAX_ENUM
};
typedef enum xerr_e xerr_t;


// error creation and handling
// ---------------------------------------------------------------------------------------------- //
#define xerrm(e, msg) xerr_push_error(e, __LINE__, __func__, __FILE__, msg)
#define xerr(e) xerrm(e, NULL)
void xerr_push_error(xerr_t e, int line, const char* func, const char* file, const char* msg);

#define xwarnm(e, msg) xerr_push_warning(e, __LINE__, __func__, __FILE__, msg)
#define xwarn(e) xwarnm(e, NULL)
void xerr_push_warning(xerr_t e, int line, const char* func, const char* file, const char* msg);

void xerr_dump(FILE* dumpfile);

#endif // CUTI_XERR_H
