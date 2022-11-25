// license
// ---------------------------------------------------------------------------------------------- //
// Copyright (c) 2022, Casey Walker
// All rights reserved.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//
//
// clitil.h
// ---------------------------------------------------------------------------------------------- //
// utils for working with CLI

#ifndef CUTI_CLITIL_H
#define CUTI_CLITIL_H

#include <stdbool.h>

enum cli_arg_type {
    CLI_ARG_TYPE_ERROR = -1,
    CLI_ARG_TYPE_NONE,
    CLI_ARG_TYPE_PROG,
    CLI_ARG_TYPE_FILE,
    CLI_ARG_TYPE_FLAG,
    CLI_ARG_TYPE_FLAG_ARG,
};
typedef enum cli_arg_type cli_arg_type_t;

typedef struct cli_arg cli_arg_t;
typedef struct cli_argwalk cli_argwalk_t;

typedef cli_arg_t cli_arg_type_fn(cli_argwalk_t argwalk, const char* str);




struct cli_arg {
    const char* str;
    cli_arg_type_t type;
    const char* parent;
};

struct cli_argwalk {
    int argc;
    const char** argv;

    const char* prog;
    cli_arg_type_fn* cli_arg_type_fn;

    int i;
    cli_arg_t arg;
};


cli_argwalk_t cli_argwalk_begin(int argc, const char* argv[], cli_arg_type_fn* cli_arg_type_fn);
cli_argwalk_t cli_argwalk_next(cli_argwalk_t argwalk);
bool cli_argwalk_done(cli_argwalk_t argwalk);

cli_argwalk_t cli_argwalk_error(const char* error);
bool is_cli_argwalk_errored(cli_argwalk_t argwalk);

#endif // CUTI_CLITIL_H
