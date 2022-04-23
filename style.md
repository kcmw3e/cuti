# Style guide for cuti library

The preferred method for word-combining is snake case.

```C
// this_is_snake_case
int snake_case_named_function();
float snake_case_named_variable;
```

Macros should always be uppercase unless there is a very clear reason for not doing so.

```C
#define MACRO(x) x

#define SNAKE_MACRO(x, y) x##y
```

Enums, structs, unuions, pointers, types, and arrays are preferred to be named with a trailing subscript indicating what they are.

```C
struct this_struct_s {
    bool b;
};

enum an_enum_e {
    ENUM1,
    ENUM2
};

union the_union_u {
    int,
    float
};

int* integer_p;

typedef char* str_t;

int array_a[];
// or, when appropriate
int* array_a = malloc(5*sizeof(int));
```

All lines should be at most 100 characters in length, **including comments**.

Functions should generally be fewer than 50 lines long, and should use helpers and/or inlined funcitons when approaching this length. Under rare circumstances is it acceptable to go over this limit.

Variable and functions names should aim to be below 30 characters, and should never reach 40 characters in length unless there is no other way to keep the meaning of the variable (i.e. any abbreviation would result in obscurity). An exception to this is when using an outside library that does not follow this guide.

Header files should begin with license information followed by information about the header, or in the case that the header is describing a library/set of headers information about the set of headers.

Generally, sections will be commented with a full break line such as

```C
// section title
// ----------------------------------- //
```

There should be at least one empty line between function definitions belonging to the same section, and any prototypes may be grouped without spacing.

```C
void util1();
void util2();
void util3();

void util1() {
    return;
}

void util2() {
    return;
}

void util3() {
    return;
}

```

Any helper functions should be declared at the top of a source file, generally grouped with precedence for functions they help with.

```C
void help1();
void help2();

void util_help();

void need_help() {
    help1();
    help2();
}

void util_use_help() {
    util_help();
}
```

This is a WIP style guide, and will likely change as the library isexpanded.
