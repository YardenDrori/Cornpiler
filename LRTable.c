#include <stdlib.h>
#include "lexer.h"
#include "stack.h"
#include "parser.h"

// LRTable functions
//=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-
//shift
void LRShift(Parser* parser, int actionParam){
    pushToken(parser->stack, parser->lexer->tokens[parser->tokenId++]);
    pushInt(parser->stack, actionParam);
}
//reduce
void LRReduce(Parser* parser, int actionParam){
    parser->ReduceFunctionTable[actionParam](parser);
}
//goto table
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
//error
void LRError(Parser* parser, int actionParam){
    /*
    ask michael if error handler should be made
    by saving the pos of each token in token struct
    or if there is a better implementation im unaware of
    */
   printf("\033[1;31mParsing error found in Row: %d, Column: %d\033[0m\n", parser->lexer->tokens[parser->tokenId].row, parser->lexer->tokens[parser->tokenId].col);
   exit(1);
}
//accept
void LRAccept(Parser* parser, int actionParam){
    //TODO
}

//reduce functions
//=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-
void Reduce0(Parser* parser){
    popStackCount(parser->stack, 2);
    pushSymbol(parser->stack, PROGRAM);
}
void Reduce1(Parser* parser){
    popStackCount(parser->stack, 2);
    pushSymbol(parser->stack, Start);
}
void Reduce2(Parser* parser){
    popStackCount(parser->stack, 6);    
    pushSymbol(parser->stack, Expr);
}
void Reduce3(Parser* parser){
    popStackCount(parser->stack, 6);    
    pushSymbol(parser->stack, Expr);
}
void Reduce4(Parser* parser){
    popStackCount(parser->stack, 2);
    pushSymbol(parser->stack, Term);    
}
void Reduce5(Parser* parser){
    popStackCount(parser->stack, 6);    
    pushSymbol(parser->stack, Term);
}
void Reduce6(Parser* parser){
    popStackCount(parser->stack, 6);    
    pushSymbol(parser->stack, Term);
}
void Reduce7(Parser* parser){
    popStackCount(parser->stack, 2);    
    pushSymbol(parser->stack, Term);
}
void Reduce8(Parser* parser){
    popStackCount(parser->stack, 6);    
    pushSymbol(parser->stack, Factor);
}
void Reduce9(Parser* parser){
    popStackCount(parser->stack, 2);    
    pushSymbol(parser->stack, Factor);
}
void Reduce10(Parser* parser){
    popStackCount(parser->stack, 2);    
    pushSymbol(parser->stack, Factor);
}
void Reduce11(Parser* parser){
    popStackCount(parser->stack, 4);    
    pushSymbol(parser->stack, Factor);
}
void Reduce12(Parser* parser){
    popStackCount(parser->stack, 4);    
    pushSymbol(parser->stack, Factor);
}
void Reduce13(Parser* parser){
    popStackCount(parser->stack, 4);    
    pushSymbol(parser->stack, Factor);
}
void Reduce14(Parser* parser){
    popStackCount(parser->stack, 4);    
    pushSymbol(parser->stack, Factor);
}
