#include "tokenizer.h"
#include "charnip.h"

#include <stdio.h>

// for these purposes, the definition of a token:
//  * a continuous string of alphanumeric characters unbroken by any other character
//  * a special character on its own
//  * a math character on its own
//  * a punctuation character on its own
// examples:
// 1.  "this is some text"
//      yeilds {"this", "is", "some", "text"}
// 2.  "15/2 = 7.5"
//      yeilds {"15", "/", "2", "=", "7", ".", "5"}
// 3.  "struct being {.name = "Frodo", .race = "Hobbit"};
//      yields {"struct", "being", "{", ".", "name", "=", "\"", "Frodo", "\"", ",", ".", "race", "=", "\"", "Hobbit", "\"", "}", ";"

tk_t tk_begin(str_t s) {
    tk_t tk = {
        .s = s,
        .t = {
            .s = s.s,
            .e = s.s,
        },
    };
    return tk_next(tk); // go ahead and get the first token
}

tk_t tk_next(tk_t tk) {
    tk.t.s = tk.t.e; // adjust to new start based on previous token (or if first run, tk.t.e should be beginning of text)

    // iterate along the string and find the end of the token
    while (tk.t.e != tk.s.e && *(tk.t.e) != '\0') {
        // the search happens like the following
        //  (the tokens and spaces are broken up for clarity and each is surrounded by brackets):
        // "[G   a   n   d   a   l   f] [ ] [t   h   e] [ ] [G   r   a   y] [ ] [.]"
        //   ^c0 ^c1 |           |   |   |
        //       ^c0 ^c1         |   |   |
        //                ...    |   |   |
        //                       ^c0 ^c1 |
        //                           ^c0 ^c1
        // tk.t.e points to a character not part of the token, the loop is broken
        char c0 = *(tk.t.e); // current last character of the token
        tk.t.e++;
        char c1 = *(tk.t.e); // current character that tk.t.e points to

        if (iswhite(c0)) {
            tk.t.s++; // ignore the beginning whitespace characters and move the start until a non-whitespace is found
            continue;
        }

        if (isalphnum(c0) && isalphnum(c1)) continue; // keep looking for the end of the alphanueric string

        // at this point, the characters c0 and c1 are some sort of mismatched combo, whether it be alphanumeric (AN) and whitespace (WS),
        //  AN and special/punc/math (SPM), SPM and AN, SPM and SPM, SPM and WS, etc.; all of which denote the end of a token
        break;
    }

    return tk;
}

bool tk_done(tk_t tk) {
    return tk.t.s == tk.t.e;
}
