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
    getTokenList(lexer);
    printTokenArray(lexer);
    printf("\ntokens %d\ntoken capacity %d", lexer->token_id, lexer->token_capacity);
    freeLexer(lexer);
    return 0;
}