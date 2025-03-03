#include "../../Lexer/H_Files/lexer.h"
#include "../../Lexer/H_Files/token.h"
#include "../H_Files/util.h"
#include "../../Parser/H_Files/stack.h"
#include "../../Parser/H_Files/parser.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

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
    generateTree(parser);

    return 0;
}