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


    printf("\n");

    return 0;
}