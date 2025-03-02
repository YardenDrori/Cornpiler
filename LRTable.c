#include <stdlib.h>
#include "lexer.h"   
#include "stack.h"
#include "LRTable.h"
#include "lexer.h"
#include "parser.h"





// LRTable functions
//=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-
void LRShift(Parser* parser, int actionParam){
    pushToken(parser->stack, parser->lexer->tokens[parser->tokenId]);
    pushInt(parser->stack, actionParam);

    treeData data;
    data.token = parser->lexer->tokens[parser->tokenId++];
    parseTreeNode *node = generateTreeNode(data);
    
}

void LRReduce(Parser* parser, int actionParam){
    parser->ReduceFunctionTable[actionParam](parser);
}

void LRGoto(Parser* parser, int actionParam){
    /*
    ASK MICHAEL IF THIS IS BETTER OF MODIFYING
    THE STACK TO STORE THE VALUE BEFORE THE LAST
    */
    int gotoResult;
    int tempNum; //contains the number represented by the temp1 enum
    StackValue temp1; //contains the GRAMMER SYMBOL
    StackValue temp2; //contains the NUMBER
    temp1 = popStack(parser->stack);
    temp2 = popStack(parser->stack);
    tempNum = temp1.data.symbolValue;
    tempNum += TOTAL_ACTIONS;
    gotoResult = parser->lrTable[tempNum][temp2.data.intValue].actionParam;
    pushSymbol(parser->stack, temp1.data.symbolValue);
    pushInt(parser->stack, temp2.data.intValue);
    pushInt(parser->stack, gotoResult);
}

void LRError(Parser* parser, int actionParam){
    /*
    ask michael if error handler should be made
    by saving the pos of each token in token struct
    or if there is a better implementation im unaware of
    */
   printf("\033[1;31mParsing error found in Row: %d, Column: %d\033[0m\n", parser->lexer->tokens[parser->tokenId].row, parser->lexer->tokens[parser->tokenId].col);
   exit(1);
}

void LRAccept(Parser* parser, int actionParam){
    //TODO
}

//reduce functions
//=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-

void Reduce3(Parser* parser){
    popStackCount(parser->stack, 6);
    pushSymbol(parser->stack, Expr);
}
