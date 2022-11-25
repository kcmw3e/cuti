#include "cliarg.h"

#include <string.h>

const char* error_argc_zero = "EROR: No program name available.";
const char* error_argv_null = "EROR: Argv must not be NULL.";
const char* error_cli_arg_type_fn_null = "ERROR: Arg type function must not be NULL.";


const cli_argwalk_t argwalk_error = {
    .arg = {
        .type = CLI_ARG_TYPE_ERROR,
        .str = NULL,
    },
};


cli_argwalk_t cli_argwalk_begin(int argc, const char* argv[], cli_arg_type_fn* cli_arg_type_fn) {
    if (argc == 0) return cli_argwalk_error(error_argc_zero);
    if (argv == NULL) return cli_argwalk_error(error_argv_null);
    if (cli_arg_type_fn == NULL) return cli_argwalk_error(error_cli_arg_type_fn_null);

    // first arg is the program name
    const char* prog = argv[0];

    cli_argwalk_t argwalk = {
        .argc = argc,
        .argv = argv,

        .prog = prog,
        .cli_arg_type_fn = cli_arg_type_fn,

        .i = 0,
        .arg = {
            .str = prog,
            .type = CLI_ARG_TYPE_PROG,
            .parent = NULL,
        },
    };

    return argwalk;
}

cli_argwalk_t cli_argwalk_next(cli_argwalk_t argwalk) {
    if (cli_argwalk_done(argwalk)) return argwalk;
    if (is_cli_argwalk_errored(argwalk)) return argwalk;

    argwalk.i++;

    const char* str = (argwalk.argv)[argwalk.i];

    argwalk.arg = (*(argwalk.cli_arg_type_fn))(argwalk, str);

    return argwalk;
}

bool cli_argwalk_done(cli_argwalk_t argwalk) {
    if (argwalk.i == argwalk.argc) return true;
    if (is_cli_argwalk_errored(argwalk)) return true;
    return false;
}

cli_argwalk_t cli_argwalk_error(const char* error) {
    cli_argwalk_t argwalk = argwalk_error;
    argwalk.arg.str = error;
    return argwalk;
}

bool is_cli_argwalk_errored(cli_argwalk_t argwalk) {
    if (argwalk.arg.type == CLI_ARG_TYPE_ERROR) return true;
    return false;
}
