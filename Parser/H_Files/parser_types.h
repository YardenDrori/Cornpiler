#ifndef PARSER_TYPES_H
#define PARSER_TYPES_H
#include <stdio.h>
#include <stdlib.h>
#include "../../Lexer/H_Files/lexer.h"
#include "../../Lexer/H_Files/token.h"

#define TOTAL_STATES 53
//#define TOTAL_ACTIONS 18
#define TOTAL_GRAMMER_RULES 18

typedef enum {
    PROGRAM,
    Start,
    Expr,
    Term,
    Factor,
    GRAMMER_SYMBOL_COUNT
} grammarSymbol;

typedef enum DataType{
    GRAMMER_SYMBOL_DATA_TYPE,
    TOKEN_DATA_TYPE,
    NUMBER_DATA_TYPE
} DataType;
#endif