#ifndef PARSER_H
#define PARSER_H
#include <stdlib.h>
#include "stack.h"
#include "../../Lexer/H_Files/lexer.h"
#include "LRTable.h"
#include "parser_types.h"
#include "parseTree.h"


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
    ACTION_SHIFT,
    ACTION_REDUCE,
    ACTION_ACCEPT,
    ACTION_ERROR
} ActionType;

typedef struct LRTable
{
    int actionParam;
    void (*LRTableFuncP)(struct Parser* parser, int actionParam);
} LRTable;


typedef struct Parser
{
    int tokenId;
    struct Lexer* lexer;
    struct Stack* stack;
    LRTable lrTable[TOTAL_ACTIONS+GRAMMER_SYMBOL_COUNT][TOTAL_STATES];
    void (*ReduceFunctionTable[TOTAL_GRAMMER_RULES])(struct Parser* parser);
    parseTreeNode* treeHead;
} Parser;

void freeParser(Parser* parser);
Parser* initParser(Lexer* lexer);


#endif





