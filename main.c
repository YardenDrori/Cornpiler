#include "lexer.h"
#include "token.h"
#include "util.h"
#include "stack.h"
#include "parser.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#define FILENAME "ExampleScript.txt"

void testLexer(){
    Lexer *lexer = initLexer(FILENAME);
    if (!lexer) {
        fprintf(stderr, "Failed to initialize lexer.\n");
    }
    getTokenList(lexer);
    printTokenArray(lexer);
    freeLexer(lexer);
}
Lexer* initTokenList(){
    Lexer *lexer = initLexer(FILENAME);
    if (!lexer) {
        fprintf(stderr, "Failed to initialize lexer.\n");
    }
    getTokenList(lexer);
    return lexer;
}







int main() {
    Lexer* lexer = initLexer(FILENAME);
    Parser* parser = initParser(lexer);
    /*
    ( - 1
    ) - 2
    IDENT - 3
    INT_LITERAL - 4
    INC - 5
    DEC - 6
    EOF - 7
    PLUS - 8
    MINUS - 9
    MULTIPY - 10
    DIVIDE - 11
    PROGRAM - 12
    Start - 13
    Expr - 14
    Term - 15
    Factor - 16

    char funcP;
    int i = 3;
    int j = 3;
    if (parser->lrTable[i][j].LRTableFuncP == LRAccept){
        funcP = 'A';
    }else if (parser->lrTable[i][j].LRTableFuncP == LRError){
        funcP = 'E';
    }else if (parser->lrTable[i][j].LRTableFuncP == LRGoto){
        funcP = 'G';
    }else if (parser->lrTable[i][j].LRTableFuncP == LRReduce){
        funcP = 'R';
    }else if (parser->lrTable[i][j].LRTableFuncP == LRShift){
        funcP = 'S';
    }else{
        printf("Woopsy Daisy1");
    }
    printf("%c %d\n", funcP, parser->lrTable[i][j].actionParam);

    printf("\n");*/


    
    return 0;
}