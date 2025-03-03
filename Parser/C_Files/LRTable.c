#include <stdlib.h>
#include "../../Lexer/H_Files/lexer.h"   
#include "../H_Files/stack.h"
#include "../H_Files/LRTable.h"
#include "../H_Files/parser.h"


//reduce functions
//=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-






// LRTable functions
//=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-
void LRShift(Parser* parser, int actionParam){
    //manage LRTable stack
    pushToken(parser->stack, parser->lexer->tokens[parser->tokenId++]);
    pushInt(parser->stack, actionParam);


}

void LRReduce(Parser* parser, int actionParam){
    //manage LRTable stack
    grammarSymbol symbol = parser->ReduceFunctionTable[actionParam](parser);
    pushSymbol(parser->stack, symbol);



    //manage treeStack
    /*treeData data;
    data.symbol = symbol;
    parseTreeNode *node = generateTreeNode(data);
    treeStackPush(parser->treeStack, node);*/
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
    tempNum = temp1.data.treeNode->data.data.symbol;
    tempNum += TOTAL_ACTIONS;
    gotoResult = parser->lrTable[tempNum][temp2.data.intValue].actionParam;
    pushSymbol(parser->stack, temp1.data.treeNode->data.data.symbol);
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




