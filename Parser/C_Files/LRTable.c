#include <stdlib.h>
#include "../../Lexer/H_Files/lexer.h"   
#include "../H_Files/stack.h"
#include "../H_Files/LRTable.h"
#include "../H_Files/parser.h"
#include "../../Misc/H_Files/util.h"

void ReduceGeneric(Parser* parser, grammarSymbol symbol, int reduceBy){
    treeData data;
    data.dataType = GRAMMER_SYMBOL_DATA_TYPE;
    data.data.symbol = symbol;
    parseTreeNode* ancestor = generateTreeAncestor(parser, reduceBy, data);
    parser->treeHead = ancestor;
    pushTreeNode(parser->stack, ancestor);
}
void ReduceToProgram1(Parser* parser){
    ReduceGeneric(parser, PROGRAM, 1);
}
void ReduceToStart1(Parser* parser){
    ReduceGeneric(parser, Start, 1);
}
void ReduceToExpr3(Parser* parser){
    ReduceGeneric(parser, Expr, 3);
}
void ReduceToExpr1(Parser* parser){
    ReduceGeneric(parser, Expr, 1);
}
void ReduceToTerm3(Parser* parser){
    ReduceGeneric(parser, Term, 3);
}
void ReduceToTerm1(Parser* parser){
    ReduceGeneric(parser, Term, 1);
}
void ReduceToFactor3(Parser* parser){
    ReduceGeneric(parser, Factor, 3);
}
void ReduceToFactor1(Parser* parser){
    ReduceGeneric(parser, Factor, 1);
}
void ReduceToFactor2(Parser* parser){
    ReduceGeneric(parser, Factor, 2);
}




// LRTable functions
//=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-
void LRShift(Parser* parser, int actionParam){
    //manage LRTable stack
    if (parser->lexer->tokens[parser->tokenId].type == END_OF_FILE){
        pushToken(parser->stack, parser->lexer->tokens[parser->tokenId]);
    }else{
        pushToken(parser->stack, parser->lexer->tokens[parser->tokenId++]);
    }
    if (PRINT_PARSER_DEBUG)
        printf("shift %d\n", actionParam);
    pushInt(parser->stack, actionParam);
    parser->action = ACTION_SHIFT;
    if (actionParam == 37){
        printf(" ");
    }
}

void LRReduce(Parser* parser, int actionParam){
    parser->ReduceFunctionTable[actionParam](parser);
    parser->action = ACTION_REDUCE;
    if (PRINT_PARSER_DEBUG)
        printf("reduce %d\n", actionParam);
}

void LRGoto(Parser* parser, __unused int actionParam){
    int gotoResult;
    int tempNum; //contains the number represented by the temp1 enum
    StackValue temp1; //contains the GRAMMER SYMBOL
    StackValue temp2; //contains the NUMBER
    temp1 = popStack(parser->stack);
    if (temp1.dataType != GRAMMER_SYMBOL_DATA_TYPE)
        LRError(parser, -1);
    temp2 = popStack(parser->stack);
    tempNum = temp1.data.treeNode->data.data.symbol;
    tempNum += TOTAL_VALID_ACTIONS;
    gotoResult = parser->lrTable[tempNum][temp2.data.intValue].actionParam;
    pushInt(parser->stack, temp2.data.intValue);
    pushTreeNode(parser->stack, temp1.data.treeNode);
    pushInt(parser->stack, gotoResult);
    parser->action = ACTION_GOTO;
    if (PRINT_PARSER_DEBUG)
        printf("GOTO %d\n",gotoResult);
}


void LRError(Parser* parser, int __unused actionParam){
   parser->action = ACTION_ERROR;
   printTree(parser->treeHead);
   printParsingStep(parser);
   printf("\n\033[1;31mParsing error found in Row: %d, Column: %d\033[0m\n", parser->lexer->tokens[parser->tokenId].row, parser->lexer->tokens[parser->tokenId].col);
   exit(1);
}

void LRAccept(Parser* parser, __unused int actionParam){
    parser->action = ACTION_ACCEPT;
    parser->treeHead = popStackCount(parser->stack, 4).data.treeNode;
    printTree(parser->treeHead);
    printf("\n\033[1;32mparser accepted!\033[0m\n\n");
    //TODO
}