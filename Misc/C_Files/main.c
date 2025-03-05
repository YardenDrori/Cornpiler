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

    /*parseTreeNode* node1 = (parseTreeNode*)malloc(sizeof(parseTreeNode));
    parseTreeNode* node2 = (parseTreeNode*)malloc(sizeof(parseTreeNode));
    parseTreeNode* node3 = (parseTreeNode*)malloc(sizeof(parseTreeNode));
    parseTreeNode* node4 = (parseTreeNode*)malloc(sizeof(parseTreeNode));
    parseTreeNode* node5 = (parseTreeNode*)malloc(sizeof(parseTreeNode));
    node1->data.dataType = GRAMMER_SYMBOL_DATA_TYPE;
    node2->data.dataType = GRAMMER_SYMBOL_DATA_TYPE;
    node3->data.dataType = GRAMMER_SYMBOL_DATA_TYPE;
    node4->data.dataType = TOKEN_DATA_TYPE;
    node5->data.dataType = TOKEN_DATA_TYPE;
    node1->data.data.symbol = Expr;
    node2->data.data.symbol = Term;
    node3->data.data.symbol = Factor;
    node4->data.data.token.type = INT_LITERAL;
    node5->data.data.token.type = IDENT;

    node1->firstChild = node2;
    node2->firstChild = node3;
    node3->firstChild = node4;
    node4 ->sibling = node5;

    printTree(node1);*/


    return 0;
}