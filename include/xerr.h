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

enum xerr_e {
    XERR_FAILURE,
    XERR_SUCCESS,
    XERR_ALLOCATION_FAIURE,
    XERR_STRING_OVERFLOW,
    XERR_UNKNOWN,
    XERR_UNDEFINED,
    XERR_MAX_ENUM
};
typedef enum xerr_e xerr_t;


// error creation and handling
// ---------------------------------------------------------------------------------------------- //
#define xerr(e) xerr_push(e, __LINE__, __func__, __FILE__, NULL) // macro for grabbing error info
#define xerrm(e, msg) xerr(e, msg)
void xerr_push(xerr_t e, int line, const char* func, const char* file, const char* msg);

#endif // CUTI_XERR_H