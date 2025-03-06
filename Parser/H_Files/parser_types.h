#ifndef PARSER_TYPES_H
#define PARSER_TYPES_H
#include <stdio.h>
#include <stdlib.h>
#include "../../Lexer/H_Files/lexer.h"
#include "../../Lexer/H_Files/token.h"





typedef enum {
    PROGRAM, //0
    Start, //1
    StmtList, //2
    Stmt,  //3
    Decl,  //4
    Assi, //5
    Expr, //6
    Term, //7
    Factor, //8
    CondExpr, //9
    RelOp, //10
    IfStmt, //11
    LoopStmt, //12
    GRAMMER_SYMBOL_COUNT //13
} grammarSymbol;

typedef enum DataType{
    GRAMMER_SYMBOL_DATA_TYPE,
    TOKEN_DATA_TYPE,
    NUMBER_DATA_TYPE
} DataType;

#endif