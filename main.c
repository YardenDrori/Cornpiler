#include "lexer.h"
#include "token.h"
#include "util.h"
#include "stack.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
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
    Stack* stack = stack_init();
    
    return 0;
}
