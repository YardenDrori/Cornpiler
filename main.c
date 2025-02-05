#include "lexer.h"
#include "token.h"
#include "util.h"
#include <stdio.h>
#define FILENAME "ExampleScript.txt"
int main() {
    Lexer *lexer = initLexer(FILENAME);
    if (!lexer) {
        fprintf(stderr, "Failed to initialize lexer.\n");
        return 1;
    }
    Token num;
    for (int i = 0; i < 8; i++){
        num = nextToken(lexer);
        printTokenType(num);
    }
    freeLexer(lexer);
    return 0;
}