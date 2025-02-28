#include "lexer.h"
#include "token.h"
#include "util.h"
#include <stdio.h>
#define FILENAME "ExampleScript.txt"

void testLexer(){
    Lexer *lexer = initLexer(FILENAME);
    if (!lexer) {
        fprintf(stderr, "Failed to initialize lexer.\n");
    }
    printTokenArray(lexer);
    freeLexer(lexer);
}

int main() {
    testLexer();


    return 0;
}