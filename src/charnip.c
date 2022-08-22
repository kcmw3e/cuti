#include "charnip.h"

bool isalph(char c) {
    if ('a' <= c && c <= 'z') return true;
    if ('A' <= c && c <= 'Z') return true;

    return false;
}

bool isnum(char c) {
    return ('0' <= c && c <= '9');
}

bool isalphnum(char c) {
    return isalph(c) || isnum(c);
}

bool iswhite(char c) {
    switch(c) {
        case (' '):
        case ('\n'):
        case ('\t'):
        case ('\r'):
        case ('\v'):
        case ('\f'):
            return true;
        default:
            break;
    }
    return false;
}

bool isgroup(char c) {
    switch (c) {
        case ('{'):
        case ('}'):
        case ('('):
        case (')'):
        case ('['):
        case (']'):
        case ('<'):
        case ('>'):
        case ('"'):
        case ('\''):
            return true;
        default:
            break;
    }
    return false;
}

bool ispunc(char c) {
    switch (c) {
        case ('.'):
        case (','):
        case (';'):
        case ('?'):
        case ('!'):
        case (':'):
            return true;
        default:
            break;
    }
    return false;
}

bool ismathop(char c) {
    switch (c) {
        case ('+'):
        case ('-'):
        case ('/'):
        case ('%'):
        case ('*'):
        case ('^'):
        case ('='):
            return true;
        default:
            break;
    }
    return false;
}

bool isspecial(char c) {
    switch (c) {
        case ('@'):
        case ('#'):
        case ('$'):
        case ('&'):
        case ('|'):
        case ('`'):
        case ('~'):
        case ('_'):
        case ('\\'):
            return true;
        default:
            break;
    }
    return false;
}
