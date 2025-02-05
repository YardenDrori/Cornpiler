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
    for (int i = 0; i < lexer->token_count; i++){
        printTokenType(lexer->tokens[i]);
    }
    printf("\ntokens %d\ntoken capacity %d", lexer->token_count, lexer->token_capacity);
    freeLexer(lexer);
    return 0;
}