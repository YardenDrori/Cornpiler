#ifndef PARSER_H
#define PARSER_H
#include <stdlib.h>
#include "stack.h"
#include "../../Lexer/H_Files/lexer.h"
#include "LRTable.h"
#include "parser_types.h"
#include "parseTree.h"
#define PRINT_PARSER_DEBUG 0

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
    ACTION_ERROR,
    ACTION_GOTO
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
    LRTable lrTable[TOTAL_PARSE_STATES+GRAMMER_SYMBOL_COUNT][TOTAL_PARSE_STATES];
    parseTreeNode* treeHead;
    ActionType action;
    void (*ReduceGrammerRule[TOTAL_GRAMMAR_RULES])(struct Parser*, int);
    int reduceGrammerBy[TOTAL_GRAMMAR_RULES];
    int isError;
} Parser;

void freeParser(Parser* parser);
Parser* initParser(Lexer* lexer);
void generateTree(Parser* parser);

#endif





