#include "xerr.h"
#include <stdio.h>

void xerr_push(xerr_t e, int line, const char* func, const char* file, const char* msg) {
    printf("error %d: %s on line %d in function %s in file %s", e, msg, line, func, file);
}
