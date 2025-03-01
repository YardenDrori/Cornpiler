#include "stack.h"
#include "token.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

void freeParser(Parser* parser){
    freeLexer(parser->lexer);
    freeStack(parser->stack);
    free(parser);
}

Parser* initParser(Lexer* lexer){
    Parser* parser = (Parser*)malloc(sizeof(Parser));
    if (!parser){
        printf("Failed to allocate memory for parser in parserInit\n");
        exit(1);
    }
    parser->tokenId = 0;
    parser->lexer = initLexer(FILENAME);
    parser->stack = initStack();
    pushInt(parser->stack, 0); 
    
    return parser;
}

