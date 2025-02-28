#ifndef PARSER_H
#define PARSER_H
#include <stdlib.h>
#include "lexer.h"
#include "stack.h"
#include "LRTable.h"
#define TOTAL_STATES 14
#define TOTAL_ACTIONS 11
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
    S,
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
    void (*LRTable[TOTAL_ACTIONS][TOTAL_STATES+GRAMMER_SYMBOL_COUNT])(Stack* stack, /*temp name*/int num/*temp name*/);
} Parser;

void freeParser(Parser* parser);
Parser* initParser(Lexer* lexer);


#endif