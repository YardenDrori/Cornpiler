#include "../H_Files/parser.h"
#include "../H_Files/stack.h"
#include "../H_Files/parser_types.h"
#include "../H_Files/LRTable.h"
#include "../../Lexer/H_Files/token.h"
#include "../../Misc/H_Files/util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRINT_MATRIX 0


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
    parser->lexer = lexer;
	int isLexingError = getTokenList(parser->lexer);
	if (isLexingError){
		return NULL;
	}
    parser->stack = initStack();
    pushInt(parser->stack, 0);
	initParserLRTable(parser);

	void (*tempRules[TOTAL_GRAMMAR_RULES])(struct Parser*, int) = {
		LRAccept, //1
		ReduceToProgram, //1 
		ReduceToStart,  // 1
		ReduceToStmtList, ReduceToStmtList, //2
		ReduceToStmt, ReduceToStmt, ReduceToStmt, ReduceToStmt, //4
		ReduceToDecl, ReduceToDecl, ReduceToDecl, ReduceToDecl, ReduceToDecl, ReduceToDecl, ReduceToDecl, ReduceToDecl,// 8
		ReduceToAssi, ReduceToAssi, ReduceToAssi, ReduceToAssi, ReduceToAssi, ReduceToAssi, ReduceToAssi, ReduceToAssi, //8
		ReduceToExpr, ReduceToExpr, ReduceToExpr,  //3
		ReduceToTerm, ReduceToTerm, ReduceToTerm, ReduceToTerm, //4
		ReduceToFactor, ReduceToFactor, ReduceToFactor, ReduceToFactor, ReduceToFactor, ReduceToFactor, ReduceToFactor, ReduceToFactor, ReduceToFactor, ReduceToFactor, ReduceToFactor, //11
		ReduceToCondExpr, ReduceToCondExpr, ReduceToCondExpr, ReduceToCondExpr, ReduceToCondExpr, //5
		ReduceToRelOp, ReduceToRelOp, ReduceToRelOp, ReduceToRelOp, ReduceToRelOp, ReduceToRelOp, ReduceToRelOp, //7
		ReduceToIfStmt, ReduceToIfStmt, //2
		ReduceToLoopStmt, ReduceToLoopStmt}; //2
	int tempRuleReduceBy[TOTAL_GRAMMAR_RULES] = {
		0, //1
		1, //1
		1, //1
		2, 0, //2
		1, 2, 1, 1,//4 
		3, 5, 3, 5, 3, 5, 3, 5, //4
		3, 2, 2, 3, 3, 3, 3, 3, //8
		3, 3, 1,  //3
		3, 3, 3, 1, //4
		3, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, //11
		3, 2, 3, 3, 3,  //5
		1, 1, 1, 1, 1, 1, 1, //7 
		7, 11, //2
		11, 7}; //2
	memcpy(parser->reduceGrammerBy, tempRuleReduceBy, sizeof(tempRuleReduceBy));
	memcpy(parser->ReduceGrammerRule, tempRules, sizeof(tempRules));

    printf("Parser Initialized Succesfully! XD\n");
    return parser;
}

void generateTree(Parser* parser){
	printf("\n");
	StackValue val1;
	int val2;
	while (parser->action != ACTION_ACCEPT){
		if (PRINT_PARSER_DEBUG){
			printf("\n\n\n");
			printParsingStep(parser);
			printTree(parser->treeHead);
		}
		val1 = getStackValue(parser->stack);
		if (val1.dataType == NUMBER_DATA_TYPE){
			val2 = parser->lexer->tokens[parser->tokenId].type;
			parser->lrTable[val2][val1.data.intValue].LRTableFuncP(parser, parser->lrTable[val2][val1.data.intValue].actionParam);
		}else{
			LRGoto(parser, -1);
		}
	}
}