#include "../../Lexer/H_Files/lexer.h"
#include "../../Lexer/H_Files/token.h"
#include "../H_Files/util.h"
#include "../../Parser/H_Files/stack.h"
#include "../../Parser/H_Files/parser.h"
#include "../../Parser/H_Files/parser_types.h"
#include "../H_Files/errorHandler.h"
#include <stdio.h>
#include <stdarg.h>

void handleLexingError(Token token){
    printf("\033[1;31mLexing error found in line: %d, at column: %d\033[0m\n",token.row, token.col);
}
void handleParsingError(struct Parser* parser,__unused int actionParam){
    parser->action = ACTION_ERROR;
    if (PRINT_PARSER_DEBUG){
        printTree(parser->treeHead);
        printParsingStep(parser);
    }
    printf("\n\033[1;31mParsing error found in line: %d, at column: %d\033[0m", parser->lexer->tokens[parser->tokenId].row, parser->lexer->tokens[parser->tokenId].col);
    //exit(1);
    parser->tokenId++;
 }