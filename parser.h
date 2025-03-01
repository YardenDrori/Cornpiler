#ifndef PARSER_H
#define PARSER_H
#include <stdlib.h>
#include "lexer.h"
#include "stack.h"
#include "LRTable.h"
#define TOTAL_STATES 45
#define TOTAL_ACTIONS 11
#define TOTAL_GRAMMER_RULES 15

/* FOR NOW ONLY THESE WILL BE USED
Program -> S
S -> Expr
Expr -> Expr + Term
Expr -> Expr - Term
Expr -> Term
Term -> Term * Factor
Term -> Term / Factor
Term -> Factor
Factor -> ( Expr )
Factor -> id
Factor -> intlit
Factor -> id inc
Factor -> id dec
Factor -> dec id
Factor -> inc id
*/
typedef enum {
    PROGRAM,
    Start,
    Expr,
    Term,
    Factor,
    GRAMMER_SYMBOL_COUNT
} grammarSymbol;

typedef enum {
    ACTION_SHIFT,
    ACTION_REDUCE,
    ACTION_ACCEPT,
    ACTION_ERROR
} ActionType;

typedef struct parser
{
    int tokenId;
    Lexer* lexer;
    Stack* stack;
    void (*LRTable[TOTAL_ACTIONS+GRAMMER_SYMBOL_COUNT][TOTAL_STATES])(Stack* stack, int actionParam);
    void (*ReduceFunctionTable[TOTAL_GRAMMER_RULES])(Stack* stack);
} Parser;

void freeParser(Parser* parser);
Parser* initParser(Lexer* lexer);


#endif