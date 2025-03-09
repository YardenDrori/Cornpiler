#include "../../Lexer/H_Files/lexer.h"
// Including necessary headers for lexical and syntactical analysis
// as well as utility functions.
#include "../../Lexer/H_Files/token.h"
#include "../H_Files/util.h"
#include "../../Parser/H_Files/stack.h"
#include "../../Parser/H_Files/parser.h"
#include "../../Parser/H_Files/parser_types.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

// testLexer function demonstrates the usage of the lexer by initializing it,
// retrieving a list of tokens, printing them, and then cleaning up.
void testLexer(){
    Lexer *lexer = initLexer(FILENAME);
    if (!lexer) {
        fprintf(stderr, "Failed to initialize lexer.\n");
    }
    getTokenList(lexer);
    printTokenArray(lexer);
    freeLexer(lexer);
}
// initTokenList function creates and returns a lexer after generating
// its token list. This function is useful for quickly setting up tokens.
Lexer* initTokenList(){
    Lexer *lexer = initLexer(FILENAME);
    if (!lexer) {
        fprintf(stderr, "Failed to initialize lexer.\n");
    }
    getTokenList(lexer);
    return lexer;
}






// The main function serves as the entry point to the program.
// It initializes a lexer and a parser, and generates a parse tree.
int main() {
    Lexer* lexer = initLexer(FILENAME);
    Parser* parser = initParser(lexer);
    generateTree(parser);
    return 0;
}