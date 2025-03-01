#include <stdlib.h>
#include "lexer.h"
#include "stack.h"
#include "parser.h"

// LRTable functions
//=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-
//shift
void LRS(Parser* parser, int actionParam){
    pushToken(parser->stack, parser->lexer->tokens[parser->tokenId++]);
    pushInt(parser->stack, actionParam);
}
//reduce
void LRR(Parser* parser, int actionParam){
    parser->ReduceFunctionTable[actionParam](parser);
}
//goto table
void LRG(Parser* parser, int actionParam){
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
    gotoResult = parser->lrTable[tempNum][temp2.data.intValue].LRTableFuncP;
    pushSymbol(parser->stack, temp1.data.symbolValue);
    pushInt(parser->stack, temp2.data.intValue);
    pushInt(parser->stack, gotoResult);
}
//error
void LRE(Parser* parser, int actionParam){
    /*
    ask michael if error handler should be made
    by saving the pos of each token in token struct
    or if there is a better implementation im unaware of
    */
   printf("\033[1;31mParsing error found in Row: %d, Column: %d\033[0m\n", parser->lexer->tokens[parser->tokenId].row, parser->lexer->tokens[parser->tokenId].col);
   exit(1);
}

//reduce functions
//=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-

void Reduce1(Parser* parser){

}
void Reduce2(Parser* parser){
    
}
void Reduce3(Parser* parser){
    
}
void Reduce4(Parser* parser){
    
}
void Reduce5(Parser* parser){
    
}
void Reduce6(Parser* parser){
    
}
void Reduce7(Parser* parser){
    
}
void Reduce8(Parser* parser){
    
}
void Reduce9(Parser* parser){
    
}
void Reduce10(Parser* parser){
    
}
void Reduce11(Parser* parser){
    
}
void Reduce12(Parser* parser){
    
}
void Reduce13(Parser* parser){
    
}
void Reduce14(Parser* parser){
    
}
