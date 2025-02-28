#include "stack.h"
#include "token.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

void freeParser(Parser* parser){
    freeLexer(parser->lexer);
    stack_free(parser->stack);
    free(parser);
}

Parser* initParser(Lexer* lexer){
    Parser* parser = (Parser*)malloc(sizeof(Parser));
    if (!parser){
        printf("Failed to allocate memory for parser in parserInit\n");
        exit(1);
    }
    parser->lexer = lexer;
    parser->stack = stack_init();
    //LR(1) table initialization below
    for (int i = 0; i < TOTAL_ACTIONS; i++){
        for (int j = 0; j < TOTAL_STATES; j++){
            parser->LRTable[i][j] = LRTableError;
        }
    }

    return parser;
}

