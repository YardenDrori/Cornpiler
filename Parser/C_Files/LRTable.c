#include <stdlib.h>
#include "../../Lexer/H_Files/lexer.h"   
#include "../H_Files/stack.h"
#include "../H_Files/LRTable.h"
#include "../H_Files/parser.h"


//reduce functions
//=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-
/* TEMPLATE
void Reduce(Parser* parser){
    treeList* children = generateList(parser, );
    treeData data;
    data.dataType = GRAMMER_SYMBOL_TREE_DATA_TYPE;
    data.data.symbol = ;
    pushTreeNode(parser->stack ,generateTreeNodeAncestor(children, data));
}
*/


void ReduceGeneric(Parser* parser, grammarSymbol symbol, int listSize){
    treeList* children = generateList(parser, listSize);
    treeData data;
    data.dataType = GRAMMER_SYMBOL_TREE_DATA_TYPE;
    data.data.symbol = symbol;
    pushTreeNode(parser->stack ,generateTreeNodeAncestor(children, data));
}
void accept(Parser* parser){
    //TODO
    printf("ACCEPT\n");
}
void Reduce1(Parser* parser){
    ReduceGeneric(parser, PROGRAM, 1);
}
void Reduce2(Parser* parser){
    ReduceGeneric(parser, Start, 1);
}
void Reduce3(Parser* parser){
    ReduceGeneric(parser, Expr, 3);
}
void Reduce4(Parser* parser){
    ReduceGeneric(parser, Expr, 3);
}
void Reduce5(Parser* parser){
    ReduceGeneric(parser, Expr, 1);
}
void Reduce6(Parser* parser){
    ReduceGeneric(parser, Term, 3);
}
void Reduce7(Parser* parser){
    ReduceGeneric(parser, Term, 3);
}
void Reduce8(Parser* parser){
    ReduceGeneric(parser, Term, 1);
}
void Reduce9(Parser* parser){
    ReduceGeneric(parser, Factor, 3);
}
void Reduce10(Parser* parser){
    ReduceGeneric(parser, Factor, 1);
}
void Reduce11(Parser* parser){
    ReduceGeneric(parser, Factor, 1);
}
void Reduce12(Parser* parser){
    ReduceGeneric(parser, Factor, 2);
}
void Reduce13(Parser* parser){
    ReduceGeneric(parser, Factor, 2);
}
void Reduce14(Parser* parser){
    ReduceGeneric(parser, Factor, 2);
}
void Reduce15(Parser* parser){
    ReduceGeneric(parser, Factor, 2);
}




// LRTable functions
//=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-
void LRShift(Parser* parser, int actionParam){
    //manage LRTable stack
    pushToken(parser->stack, parser->lexer->tokens[parser->tokenId++]);
    pushInt(parser->stack, actionParam);
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




