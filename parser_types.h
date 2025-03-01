#ifndef PARSER_TYPES_H
#define PARSER_TYPES_H
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#define TOTAL_STATES 44
#define TOTAL_ACTIONS 11
#define TOTAL_GRAMMER_RULES 15

typedef enum {
    PROGRAM,
    Start,
    Expr,
    Term,
    Factor,
    GRAMMER_SYMBOL_COUNT
} grammarSymbol;

#endif