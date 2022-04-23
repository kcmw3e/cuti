#include <stdbool.h>

#include "cuti.h"

#include "xerr.h"


#define MAX_ERR_STACK_SIZE 255
#define MAX_ERR_CODE_STR_LEN 8 // room for INT_MAX number of error codes represented as hex strings

// the first few errors slots may be reserved for special errors such as error stack overflow
enum special_err_index_e {
    ERR_STACK_OVERFLOW_INDEX = 0,
    ERR_STACK_START
};

struct err_info_s {
    xerr_t e;
    int line;
    const char* func;
    const char* file;
    const char* msg;
    bool is_warning;
};

static const char XERR_PREFIX[] = "[xerr]";
static const char WARNING_PREFIX[] = "WARNING";
static const char ERROR_PREFIX[] = "ERROR";

static const char OVERFLOW_MSG[] =
    "The error stack was not cleared and overflowed. Some errors may have been overwritten.";

static struct err_info_s err_stack[MAX_ERR_STACK_SIZE];
static size_t err_stack_size = 0;
static size_t err_stack_overflows = 0;


bool stack_has_overflow();
bool stack_has_warning();
static inline void put_err(struct err_info_s info, size_t i);
static inline void push(struct err_info_s info);
static inline void push_overflow_err(struct err_info_s info);

void xerr_push_error(xerr_t e, int line, const char* func, const char* file, const char* msg) {
    struct err_info_s info = {
        .e = e,
        .line = line,
        .func = func,
        .file = file,
        .msg = msg,
        .is_warning = false
    };
    push(info);
}

void xerr_push_warning(xerr_t e, int line, const char* func, const char* file, const char* msg) {
    struct err_info_s info = {
        .e = e,
        .line = line,
        .func = func,
        .file = file,
        .msg = msg,
        .is_warning = true
    };
    push(info);
}

void xerr_dump(FILE* dumpfile) {
    int prefix_str_len = stack_has_warning() ? sizeof(WARNING_PREFIX) : sizeof(ERROR_PREFIX);

    for (size_t i = 0; i < MAX_ERR_STACK_SIZE; i++) {
        struct err_info_s info = err_stack[i];
        xerr_t e = info.e;
        
        if (e == XERR_UNDEFINED || e == XERR_SUCCESS) continue;

        int line = info.line;
        const char* func = info.func;
        const char* file = info.file;
        const char* msg = info.msg;

        bool is_warning = info.is_warning;
        const char* prefix = is_warning ? WARNING_PREFIX : ERROR_PREFIX;

        fprintf(dumpfile, "%s %-*s", XERR_PREFIX, prefix_str_len, prefix);
        fprintf(dumpfile, "[%0*x]:", MAX_ERR_CODE_STR_LEN, e);
        fprintf(dumpfile, "%s[%d] in %s(). %s", file, line, func, msg);
        fprintf(dumpfile, "\n");
    }
}


bool stack_has_overflow() {
    return err_stack[ERR_STACK_OVERFLOW_INDEX].e == XERR_ERR_STACK_OVERFLOW;
}

bool stack_has_warning() {
    for (size_t i = ERR_STACK_START; i < MAX_ERR_STACK_SIZE; i++) {
        if (err_stack[i].is_warning == true) return true;
    }
    return false;
}

static inline void put_err(struct err_info_s info, size_t i) {
    info.func = info.func == NULL ? "" : info.func;
    info.file = info.file == NULL ? "" : info.file;
    info.msg = info.msg == NULL ? "" : info.msg;
    err_stack[i] = info;
}

static inline void push(struct err_info_s info) {
    if (err_stack_size >= MAX_ERR_STACK_SIZE) {
        err_stack_size = ERR_STACK_START;
        push_overflow_err(info);
    }
    put_err(info, err_stack_size);
    err_stack_size++;
}

static inline void push_overflow_err(struct err_info_s info) {
    size_t i = ERR_STACK_OVERFLOW_INDEX;
    if (stack_has_overflow()) i = err_stack_size;

    info.e = XERR_ERR_STACK_OVERFLOW;
    info.msg = OVERFLOW_MSG;
    put_err(info, i);
    err_stack_overflows++;
}
