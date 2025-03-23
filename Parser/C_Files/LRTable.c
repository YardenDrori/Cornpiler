#include <stdlib.h>
#include "../../Lexer/H_Files/lexer.h"   
#include "../H_Files/stack.h"
#include "../H_Files/LRTable.h"
#include "../H_Files/parser.h"
#include "../../Misc/H_Files/util.h"
#include "../../Misc/H_Files/global.h"

void ReduceGeneric(Parser* parser, grammarSymbol symbol, int reduceBy){
    treeData data;
    data.dataType = GRAMMER_SYMBOL_DATA_TYPE;
    data.data.symbol = symbol;
    parseTreeNode* ancestor = generateTreeAncestor(parser, reduceBy, data);
    parser->treeHead = ancestor;
    pushTreeNode(parser->stack, ancestor);
}
void ReduceToProgram(Parser* parser,int reduceBy){
    ReduceGeneric(parser, program, reduceBy);
}
void ReduceToExternalDeclerationList(Parser* parser,int reduceBy){
    ReduceGeneric(parser, external_declaration_list, reduceBy);
}
void ReduceToExternalDecleration(Parser* parser,int reduceBy){
    ReduceGeneric(parser, external_declaration, reduceBy);
}
void ReduceToDecleration(Parser* parser,int reduceBy){
    ReduceGeneric(parser, declaration, reduceBy);
}
void ReduceToInitDecleratorList(Parser* parser,int reduceBy){
    ReduceGeneric(parser, init_declarator_list, reduceBy);
}
void ReduceToInitDeclerator(Parser* parser,int reduceBy){
    ReduceGeneric(parser, init_declarator, reduceBy);
}
void ReduceToTypeSpecifier(Parser* parser,int reduceBy){
    ReduceGeneric(parser, type_specifier, reduceBy);
}
void ReduceToFunctionDefintio(Parser* parser,int reduceBy){
    ReduceGeneric(parser, function_definition, reduceBy);
}
void ReduceToParamaterListOpt(Parser* parser,int reduceBy){
    ReduceGeneric(parser, parameter_list_opt, reduceBy);
}
void ReduceToParamaterList(Parser* parser,int reduceBy){
    ReduceGeneric(parser, parameter_list, reduceBy);
}
void ReduceToParamaterDecleration(Parser* parser,int reduceBy){
    ReduceGeneric(parser, parameter_declaration, reduceBy);
}
void ReduceToCompundStatement(Parser* parser,int reduceBy){
    ReduceGeneric(parser, compound_statement, reduceBy);
}
void ReduceToDeclerationListOpt(Parser* parser,int reduceBy){
    ReduceGeneric(parser, declaration_list_opt, reduceBy);
}
void ReduceToDeclerationList(Parser* parser,int reduceBy){
    ReduceGeneric(parser, declaration_list, reduceBy);
}
void ReduceToStatementListOpt(Parser* parser,int reduceBy){
    ReduceGeneric(parser, statement_list_opt, reduceBy);
}
void ReduceToStatementList(Parser* parser,int reduceBy){
    ReduceGeneric(parser, statement_list, reduceBy);
}
void ReduceToStatement(Parser* parser,int reduceBy){
    ReduceGeneric(parser, statement, reduceBy);
}
void ReduceToExpressionStatement(Parser* parser,int reduceBy){
    ReduceGeneric(parser, expression_statement, reduceBy);
}
void ReduceToSelectionStatement(Parser* parser,int reduceBy){
    ReduceGeneric(parser, selection_statement, reduceBy);
}
void ReduceToIterationStatement(Parser* parser,int reduceBy){
    ReduceGeneric(parser, iteration_statement, reduceBy);
}
void ReduceToExpressionOpt(Parser* parser,int reduceBy){
    ReduceGeneric(parser, expression_opt, reduceBy);
}
void ReduceToExpression(Parser* parser,int reduceBy){
    ReduceGeneric(parser, expression, reduceBy);
}
void ReduceToAssignmentExpression(Parser* parser,int reduceBy){
    ReduceGeneric(parser, assignment_expression, reduceBy);
}
void ReduceToAssignmentOperator(Parser* parser,int reduceBy){
    ReduceGeneric(parser, assignment_operator, reduceBy);
}
void ReduceToConditionalExpression(Parser* parser,int reduceBy){
    ReduceGeneric(parser, conditional_expression, reduceBy);
}
void ReduceToLogicalOrExpression(Parser* parser,int reduceBy){
    ReduceGeneric(parser, logical_or_expression, reduceBy);
}
void ReduceToLogicalAndExpression(Parser* parser,int reduceBy){
    ReduceGeneric(parser, logical_and_expression, reduceBy);
}
void ReduceToBitwiseOrExpression(Parser* parser,int reduceBy){
    ReduceGeneric(parser, bitwise_or_expression, reduceBy);
}
void ReduceToBitwiseXorExpressions(Parser* parser,int reduceBy){
    ReduceGeneric(parser, bitwise_xor_expression, reduceBy);
}
void ReduceToBitwiseAndExpression(Parser* parser,int reduceBy){
    ReduceGeneric(parser, bitwise_and_expression, reduceBy);
}
void ReduceToEqualityExpression(Parser* parser,int reduceBy){
    ReduceGeneric(parser, equality_expression, reduceBy);
}
void ReduceToRelationalExpression(Parser* parser,int reduceBy){
    ReduceGeneric(parser, relational_expression, reduceBy);
}
void ReduceToShiftExpression(Parser* parser,int reduceBy){
    ReduceGeneric(parser, shift_expression, reduceBy);
}
void ReduceToAdditiveExpression(Parser* parser,int reduceBy){
    ReduceGeneric(parser, additive_expression, reduceBy);
}
void ReduceToMultiplicativeExpression(Parser* parser,int reduceBy){
    ReduceGeneric(parser, multiplicative_expression, reduceBy);
}
void ReduceToUnaryExpression(Parser* parser,int reduceBy){
    ReduceGeneric(parser, unary_expression, reduceBy);
}
void ReduceToUnaryOperator(Parser* parser,int reduceBy){
    ReduceGeneric(parser, unary_operator, reduceBy);
}
void ReduceToPostfixExpression(Parser* parser,int reduceBy){
    ReduceGeneric(parser, postfix_expression, reduceBy);
}
void ReduceToArgumentExpressionListOpt(Parser* parser,int reduceBy){
    ReduceGeneric(parser, argument_expression_list_opt, reduceBy);
}
void ReduceToArgumentExpressionList(Parser* parser,int reduceBy){
    ReduceGeneric(parser, argument_expression_list, reduceBy);
}
void ReduceToPrimaryExpression(Parser* parser,int reduceBy){
    ReduceGeneric(parser, primary_expression, reduceBy);
    printf("idk this code was written on my iphone");
}

// LRTable functions
//=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-
void LRShift(Parser* parser, int actionParam){
    //manage LRTable stack
    if (parser->lexer->tokens[parser->tokenId].type == END_OF_FILE){
        pushToken(parser->stack, parser->lexer->tokens[parser->tokenId]);
    }else{
        pushToken(parser->stack, parser->lexer->tokens[parser->tokenId++]);
    }
    if (PRINT_PARSER_DEBUG)
        printf("shift %d\n", actionParam);
    pushInt(parser->stack, actionParam);
    parser->action = ACTION_SHIFT;
}

void LRReduce(Parser* parser, int actionParam){
	parser->ReduceGrammerRule[actionParam](parser, parser->reduceGrammerBy[actionParam]);

	parser->action = ACTION_REDUCE;
    if (PRINT_PARSER_DEBUG)
        printf("reduce %d\n", actionParam);
}

void LRGoto(Parser* parser, __unused int actionParam){
    int gotoResult;
    int tempNum; //contains the number represented by the temp1 enum
    StackValue temp1; //contains the GRAMMER SYMBOL
    StackValue temp2; //contains the NUMBER
    temp1 = popStack(parser->stack);
    temp2 = popStack(parser->stack);
    tempNum = temp1.data.treeNode->data.data.symbol;
    tempNum += TOTAL_TOKENS;
    gotoResult = parser->lrTable[tempNum][temp2.data.intValue].actionParam;
    pushInt(parser->stack, temp2.data.intValue);
    pushTreeNode(parser->stack, temp1.data.treeNode);
    pushInt(parser->stack, gotoResult);
    parser->action = ACTION_GOTO;
    if (PRINT_PARSER_DEBUG)
        printf("GOTO %d\n",gotoResult);
}


/*void LRError(Parser* parser, int __unused actionParam){
   parser->action = ACTION_ERROR;
   printTree(parser->treeHead);
   printParsingStep(parser);
   printf("\n\033[1;31mParsing error found in line: %d, at column: %d\033[0m\n", parser->lexer->tokens[parser->tokenId].row, parser->lexer->tokens[parser->tokenId].col);
   exit(1);
}*/

void LRAccept(Parser* parser, __unused int actionParam){
    parser->action = ACTION_ACCEPT;
    parser->treeHead = popStackCount(parser->stack, 4).data.treeNode;
	if (!parser->isError)
    	printf("\033[1;32mparser accepted!\033[0m\n\n");
	else{
		printf("\n\n\033[1;31mPARSING ERRORS FOUND\033[0m\n\n");
	}
}




//WARNING A MONSTER OF A FUNCTION BELOW OVER 8000 LINES OF CODE
void initParserLRTable(Parser* parser){
		for (int i = 0; i < TOTAL_TOKENS+GRAMMER_SYMBOL_COUNT; i++){
			for (int j = 0; j < TOTAL_PARSE_STATES; j++){
				parser->lrTable[i][j].LRTableFuncP = handleParsingError;
				parser->lrTable[i][j].actionParam = -1;
			}
		}
	//reduce
	parser->lrTable[52][0].LRTableFuncP = LRReduce;
	parser->lrTable[52][0].actionParam = 2;
	//reduce
	parser->lrTable[40][0].LRTableFuncP = LRReduce;
	parser->lrTable[40][0].actionParam = 2;
	//reduce
	parser->lrTable[41][0].LRTableFuncP = LRReduce;
	parser->lrTable[41][0].actionParam = 2;
	//reduce
	parser->lrTable[42][0].LRTableFuncP = LRReduce;
	parser->lrTable[42][0].actionParam = 2;
	//reduce
	parser->lrTable[43][0].LRTableFuncP = LRReduce;
	parser->lrTable[43][0].actionParam = 2;
	//goto
	parser->lrTable[program+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[program+TOTAL_TOKENS][0].actionParam = 1;
	//goto
	parser->lrTable[external_declaration_list+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[external_declaration_list+TOTAL_TOKENS][0].actionParam = 2;
	//shift
	parser->lrTable[52][0].LRTableFuncP = LRShift;
	parser->lrTable[52][0].actionParam = 3;
	//shift
	parser->lrTable[40][0].LRTableFuncP = LRShift;
	parser->lrTable[40][0].actionParam = 4;
	//shift
	parser->lrTable[41][0].LRTableFuncP = LRShift;
	parser->lrTable[41][0].actionParam = 5;
	//shift
	parser->lrTable[42][0].LRTableFuncP = LRShift;
	parser->lrTable[42][0].actionParam = 6;
	//shift
	parser->lrTable[43][0].LRTableFuncP = LRShift;
	parser->lrTable[43][0].actionParam = 7;
	//reduce
	parser->lrTable[52][0].LRTableFuncP = LRReduce;
	parser->lrTable[52][0].actionParam = 1;
	//goto
	parser->lrTable[external_declaration+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[external_declaration+TOTAL_TOKENS][0].actionParam = 8;
	//goto
	parser->lrTable[type_specifier+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[type_specifier+TOTAL_TOKENS][0].actionParam = 10;
	//goto
	parser->lrTable[function_definition+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[function_definition+TOTAL_TOKENS][0].actionParam = 11;
	//accept
	for (int i = 0; i < TOTAL_TOKENS+GRAMMER_SYMBOL_COUNT; i++){
		parser->lrTable[i][0].LRTableFuncP = LRAccept;
		parser->lrTable[i][0].actionParam = -1;
	}
	//reduce
	parser->lrTable[51][0].LRTableFuncP = LRReduce;
	parser->lrTable[51][0].actionParam = 12;
	//reduce
	parser->lrTable[51][0].LRTableFuncP = LRReduce;
	parser->lrTable[51][0].actionParam = 11;
	//reduce
	parser->lrTable[51][0].LRTableFuncP = LRReduce;
	parser->lrTable[51][0].actionParam = 13;
	//reduce
	parser->lrTable[51][0].LRTableFuncP = LRReduce;
	parser->lrTable[51][0].actionParam = 14;
	//reduce
	parser->lrTable[52][0].LRTableFuncP = LRReduce;
	parser->lrTable[52][0].actionParam = 3;
	//reduce
	parser->lrTable[40][0].LRTableFuncP = LRReduce;
	parser->lrTable[40][0].actionParam = 3;
	//reduce
	parser->lrTable[41][0].LRTableFuncP = LRReduce;
	parser->lrTable[41][0].actionParam = 3;
	//reduce
	parser->lrTable[42][0].LRTableFuncP = LRReduce;
	parser->lrTable[42][0].actionParam = 3;
	//reduce
	parser->lrTable[43][0].LRTableFuncP = LRReduce;
	parser->lrTable[43][0].actionParam = 3;
	//reduce
	parser->lrTable[52][0].LRTableFuncP = LRReduce;
	parser->lrTable[52][0].actionParam = 4;
	//reduce
	parser->lrTable[40][0].LRTableFuncP = LRReduce;
	parser->lrTable[40][0].actionParam = 4;
	//reduce
	parser->lrTable[41][0].LRTableFuncP = LRReduce;
	parser->lrTable[41][0].actionParam = 4;
	//reduce
	parser->lrTable[42][0].LRTableFuncP = LRReduce;
	parser->lrTable[42][0].actionParam = 4;
	//reduce
	parser->lrTable[43][0].LRTableFuncP = LRReduce;
	parser->lrTable[43][0].actionParam = 4;
	//shift
	parser->lrTable[51][0].LRTableFuncP = LRShift;
	parser->lrTable[51][0].actionParam = 12;
	//reduce
	parser->lrTable[52][0].LRTableFuncP = LRReduce;
	parser->lrTable[52][0].actionParam = 5;
	//reduce
	parser->lrTable[40][0].LRTableFuncP = LRReduce;
	parser->lrTable[40][0].actionParam = 5;
	//reduce
	parser->lrTable[41][0].LRTableFuncP = LRReduce;
	parser->lrTable[41][0].actionParam = 5;
	//reduce
	parser->lrTable[42][0].LRTableFuncP = LRReduce;
	parser->lrTable[42][0].actionParam = 5;
	//reduce
	parser->lrTable[43][0].LRTableFuncP = LRReduce;
	parser->lrTable[43][0].actionParam = 5;
	//shift
	parser->lrTable[2][0].LRTableFuncP = LRShift;
	parser->lrTable[2][0].actionParam = 15;
	//shift
	parser->lrTable[29][0].LRTableFuncP = LRShift;
	parser->lrTable[29][0].actionParam = 16;
	//reduce
	parser->lrTable[56][0].LRTableFuncP = LRReduce;
	parser->lrTable[56][0].actionParam = 9;
	//reduce
	parser->lrTable[57][0].LRTableFuncP = LRReduce;
	parser->lrTable[57][0].actionParam = 9;
	//shift
	parser->lrTable[56][0].LRTableFuncP = LRShift;
	parser->lrTable[56][0].actionParam = 17;
	//shift
	parser->lrTable[57][0].LRTableFuncP = LRShift;
	parser->lrTable[57][0].actionParam = 18;
	//reduce
	parser->lrTable[56][0].LRTableFuncP = LRReduce;
	parser->lrTable[56][0].actionParam = 7;
	//reduce
	parser->lrTable[57][0].LRTableFuncP = LRReduce;
	parser->lrTable[57][0].actionParam = 7;
	//shift
	parser->lrTable[4][0].LRTableFuncP = LRShift;
	parser->lrTable[4][0].actionParam = 19;
	//shift
	parser->lrTable[7][0].LRTableFuncP = LRShift;
	parser->lrTable[7][0].actionParam = 20;
	//shift
	parser->lrTable[8][0].LRTableFuncP = LRShift;
	parser->lrTable[8][0].actionParam = 21;
	//shift
	parser->lrTable[10][0].LRTableFuncP = LRShift;
	parser->lrTable[10][0].actionParam = 22;
	//shift
	parser->lrTable[11][0].LRTableFuncP = LRShift;
	parser->lrTable[11][0].actionParam = 23;
	//shift
	parser->lrTable[25][0].LRTableFuncP = LRShift;
	parser->lrTable[25][0].actionParam = 24;
	//shift
	parser->lrTable[29][0].LRTableFuncP = LRShift;
	parser->lrTable[29][0].actionParam = 25;
	//shift
	parser->lrTable[35][0].LRTableFuncP = LRShift;
	parser->lrTable[35][0].actionParam = 26;
	//shift
	parser->lrTable[36][0].LRTableFuncP = LRShift;
	parser->lrTable[36][0].actionParam = 27;
	//shift
	parser->lrTable[37][0].LRTableFuncP = LRShift;
	parser->lrTable[37][0].actionParam = 28;
	//shift
	parser->lrTable[38][0].LRTableFuncP = LRShift;
	parser->lrTable[38][0].actionParam = 29;
	//shift
	parser->lrTable[39][0].LRTableFuncP = LRShift;
	parser->lrTable[39][0].actionParam = 30;
	//shift
	parser->lrTable[51][0].LRTableFuncP = LRShift;
	parser->lrTable[51][0].actionParam = 31;
	//goto
	parser->lrTable[expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[expression+TOTAL_TOKENS][0].actionParam = 32;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][0].actionParam = 33;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][0].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][0].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][0].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][0].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][0].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][0].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][0].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][0].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][0].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][0].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][0].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][0].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][0].actionParam = 47;
	//shift
	parser->lrTable[40][0].LRTableFuncP = LRShift;
	parser->lrTable[40][0].actionParam = 4;
	//shift
	parser->lrTable[41][0].LRTableFuncP = LRShift;
	parser->lrTable[41][0].actionParam = 5;
	//shift
	parser->lrTable[42][0].LRTableFuncP = LRShift;
	parser->lrTable[42][0].actionParam = 6;
	//shift
	parser->lrTable[43][0].LRTableFuncP = LRShift;
	parser->lrTable[43][0].actionParam = 7;
	//reduce
	parser->lrTable[30][0].LRTableFuncP = LRReduce;
	parser->lrTable[30][0].actionParam = 16;
	//goto
	parser->lrTable[type_specifier+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[type_specifier+TOTAL_TOKENS][0].actionParam = 49;
	//goto
	parser->lrTable[parameter_list_opt+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[parameter_list_opt+TOTAL_TOKENS][0].actionParam = 50;
	//goto
	parser->lrTable[parameter_list+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[parameter_list+TOTAL_TOKENS][0].actionParam = 51;
	//reduce
	parser->lrTable[52][0].LRTableFuncP = LRReduce;
	parser->lrTable[52][0].actionParam = 6;
	//reduce
	parser->lrTable[4][0].LRTableFuncP = LRReduce;
	parser->lrTable[4][0].actionParam = 6;
	//reduce
	parser->lrTable[7][0].LRTableFuncP = LRReduce;
	parser->lrTable[7][0].actionParam = 6;
	//reduce
	parser->lrTable[8][0].LRTableFuncP = LRReduce;
	parser->lrTable[8][0].actionParam = 6;
	//reduce
	parser->lrTable[10][0].LRTableFuncP = LRReduce;
	parser->lrTable[10][0].actionParam = 6;
	//reduce
	parser->lrTable[11][0].LRTableFuncP = LRReduce;
	parser->lrTable[11][0].actionParam = 6;
	//reduce
	parser->lrTable[25][0].LRTableFuncP = LRReduce;
	parser->lrTable[25][0].actionParam = 6;
	//reduce
	parser->lrTable[29][0].LRTableFuncP = LRReduce;
	parser->lrTable[29][0].actionParam = 6;
	//reduce
	parser->lrTable[31][0].LRTableFuncP = LRReduce;
	parser->lrTable[31][0].actionParam = 6;
	//reduce
	parser->lrTable[32][0].LRTableFuncP = LRReduce;
	parser->lrTable[32][0].actionParam = 6;
	//reduce
	parser->lrTable[35][0].LRTableFuncP = LRReduce;
	parser->lrTable[35][0].actionParam = 6;
	//reduce
	parser->lrTable[36][0].LRTableFuncP = LRReduce;
	parser->lrTable[36][0].actionParam = 6;
	//reduce
	parser->lrTable[37][0].LRTableFuncP = LRReduce;
	parser->lrTable[37][0].actionParam = 6;
	//reduce
	parser->lrTable[38][0].LRTableFuncP = LRReduce;
	parser->lrTable[38][0].actionParam = 6;
	//reduce
	parser->lrTable[39][0].LRTableFuncP = LRReduce;
	parser->lrTable[39][0].actionParam = 6;
	//reduce
	parser->lrTable[40][0].LRTableFuncP = LRReduce;
	parser->lrTable[40][0].actionParam = 6;
	//reduce
	parser->lrTable[41][0].LRTableFuncP = LRReduce;
	parser->lrTable[41][0].actionParam = 6;
	//reduce
	parser->lrTable[42][0].LRTableFuncP = LRReduce;
	parser->lrTable[42][0].actionParam = 6;
	//reduce
	parser->lrTable[43][0].LRTableFuncP = LRReduce;
	parser->lrTable[43][0].actionParam = 6;
	//reduce
	parser->lrTable[44][0].LRTableFuncP = LRReduce;
	parser->lrTable[44][0].actionParam = 6;
	//reduce
	parser->lrTable[49][0].LRTableFuncP = LRReduce;
	parser->lrTable[49][0].actionParam = 6;
	//reduce
	parser->lrTable[50][0].LRTableFuncP = LRReduce;
	parser->lrTable[50][0].actionParam = 6;
	//reduce
	parser->lrTable[56][0].LRTableFuncP = LRReduce;
	parser->lrTable[56][0].actionParam = 6;
	//reduce
	parser->lrTable[51][0].LRTableFuncP = LRReduce;
	parser->lrTable[51][0].actionParam = 6;
	//shift
	parser->lrTable[51][0].LRTableFuncP = LRShift;
	parser->lrTable[51][0].actionParam = 53;
	//reduce
	parser->lrTable[4][0].LRTableFuncP = LRReduce;
	parser->lrTable[4][0].actionParam = 91;
	//reduce
	parser->lrTable[7][0].LRTableFuncP = LRReduce;
	parser->lrTable[7][0].actionParam = 91;
	//reduce
	parser->lrTable[8][0].LRTableFuncP = LRReduce;
	parser->lrTable[8][0].actionParam = 91;
	//reduce
	parser->lrTable[10][0].LRTableFuncP = LRReduce;
	parser->lrTable[10][0].actionParam = 91;
	//reduce
	parser->lrTable[11][0].LRTableFuncP = LRReduce;
	parser->lrTable[11][0].actionParam = 91;
	//reduce
	parser->lrTable[25][0].LRTableFuncP = LRReduce;
	parser->lrTable[25][0].actionParam = 91;
	//reduce
	parser->lrTable[29][0].LRTableFuncP = LRReduce;
	parser->lrTable[29][0].actionParam = 91;
	//reduce
	parser->lrTable[35][0].LRTableFuncP = LRReduce;
	parser->lrTable[35][0].actionParam = 91;
	//reduce
	parser->lrTable[36][0].LRTableFuncP = LRReduce;
	parser->lrTable[36][0].actionParam = 91;
	//reduce
	parser->lrTable[37][0].LRTableFuncP = LRReduce;
	parser->lrTable[37][0].actionParam = 91;
	//reduce
	parser->lrTable[38][0].LRTableFuncP = LRReduce;
	parser->lrTable[38][0].actionParam = 91;
	//reduce
	parser->lrTable[39][0].LRTableFuncP = LRReduce;
	parser->lrTable[39][0].actionParam = 91;
	//reduce
	parser->lrTable[51][0].LRTableFuncP = LRReduce;
	parser->lrTable[51][0].actionParam = 91;
	//reduce
	parser->lrTable[4][0].LRTableFuncP = LRReduce;
	parser->lrTable[4][0].actionParam = 89;
	//reduce
	parser->lrTable[7][0].LRTableFuncP = LRReduce;
	parser->lrTable[7][0].actionParam = 89;
	//reduce
	parser->lrTable[8][0].LRTableFuncP = LRReduce;
	parser->lrTable[8][0].actionParam = 89;
	//reduce
	parser->lrTable[10][0].LRTableFuncP = LRReduce;
	parser->lrTable[10][0].actionParam = 89;
	//reduce
	parser->lrTable[11][0].LRTableFuncP = LRReduce;
	parser->lrTable[11][0].actionParam = 89;
	//reduce
	parser->lrTable[25][0].LRTableFuncP = LRReduce;
	parser->lrTable[25][0].actionParam = 89;
	//reduce
	parser->lrTable[29][0].LRTableFuncP = LRReduce;
	parser->lrTable[29][0].actionParam = 89;
	//reduce
	parser->lrTable[35][0].LRTableFuncP = LRReduce;
	parser->lrTable[35][0].actionParam = 89;
	//reduce
	parser->lrTable[36][0].LRTableFuncP = LRReduce;
	parser->lrTable[36][0].actionParam = 89;
	//reduce
	parser->lrTable[37][0].LRTableFuncP = LRReduce;
	parser->lrTable[37][0].actionParam = 89;
	//reduce
	parser->lrTable[38][0].LRTableFuncP = LRReduce;
	parser->lrTable[38][0].actionParam = 89;
	//reduce
	parser->lrTable[39][0].LRTableFuncP = LRReduce;
	parser->lrTable[39][0].actionParam = 89;
	//reduce
	parser->lrTable[51][0].LRTableFuncP = LRReduce;
	parser->lrTable[51][0].actionParam = 89;
	//shift
	parser->lrTable[4][0].LRTableFuncP = LRShift;
	parser->lrTable[4][0].actionParam = 19;
	//shift
	parser->lrTable[7][0].LRTableFuncP = LRShift;
	parser->lrTable[7][0].actionParam = 20;
	//shift
	parser->lrTable[8][0].LRTableFuncP = LRShift;
	parser->lrTable[8][0].actionParam = 21;
	//shift
	parser->lrTable[10][0].LRTableFuncP = LRShift;
	parser->lrTable[10][0].actionParam = 22;
	//shift
	parser->lrTable[11][0].LRTableFuncP = LRShift;
	parser->lrTable[11][0].actionParam = 23;
	//shift
	parser->lrTable[25][0].LRTableFuncP = LRShift;
	parser->lrTable[25][0].actionParam = 24;
	//shift
	parser->lrTable[29][0].LRTableFuncP = LRShift;
	parser->lrTable[29][0].actionParam = 25;
	//shift
	parser->lrTable[35][0].LRTableFuncP = LRShift;
	parser->lrTable[35][0].actionParam = 26;
	//shift
	parser->lrTable[36][0].LRTableFuncP = LRShift;
	parser->lrTable[36][0].actionParam = 27;
	//shift
	parser->lrTable[37][0].LRTableFuncP = LRShift;
	parser->lrTable[37][0].actionParam = 28;
	//shift
	parser->lrTable[38][0].LRTableFuncP = LRShift;
	parser->lrTable[38][0].actionParam = 29;
	//shift
	parser->lrTable[39][0].LRTableFuncP = LRShift;
	parser->lrTable[39][0].actionParam = 30;
	//shift
	parser->lrTable[51][0].LRTableFuncP = LRShift;
	parser->lrTable[51][0].actionParam = 31;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][0].actionParam = 55;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][0].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][0].actionParam = 47;
	//reduce
	parser->lrTable[4][0].LRTableFuncP = LRReduce;
	parser->lrTable[4][0].actionParam = 90;
	//reduce
	parser->lrTable[7][0].LRTableFuncP = LRReduce;
	parser->lrTable[7][0].actionParam = 90;
	//reduce
	parser->lrTable[8][0].LRTableFuncP = LRReduce;
	parser->lrTable[8][0].actionParam = 90;
	//reduce
	parser->lrTable[10][0].LRTableFuncP = LRReduce;
	parser->lrTable[10][0].actionParam = 90;
	//reduce
	parser->lrTable[11][0].LRTableFuncP = LRReduce;
	parser->lrTable[11][0].actionParam = 90;
	//reduce
	parser->lrTable[25][0].LRTableFuncP = LRReduce;
	parser->lrTable[25][0].actionParam = 90;
	//reduce
	parser->lrTable[29][0].LRTableFuncP = LRReduce;
	parser->lrTable[29][0].actionParam = 90;
	//reduce
	parser->lrTable[35][0].LRTableFuncP = LRReduce;
	parser->lrTable[35][0].actionParam = 90;
	//reduce
	parser->lrTable[36][0].LRTableFuncP = LRReduce;
	parser->lrTable[36][0].actionParam = 90;
	//reduce
	parser->lrTable[37][0].LRTableFuncP = LRReduce;
	parser->lrTable[37][0].actionParam = 90;
	//reduce
	parser->lrTable[38][0].LRTableFuncP = LRReduce;
	parser->lrTable[38][0].actionParam = 90;
	//reduce
	parser->lrTable[39][0].LRTableFuncP = LRReduce;
	parser->lrTable[39][0].actionParam = 90;
	//reduce
	parser->lrTable[51][0].LRTableFuncP = LRReduce;
	parser->lrTable[51][0].actionParam = 90;
	//shift
	parser->lrTable[4][0].LRTableFuncP = LRShift;
	parser->lrTable[4][0].actionParam = 19;
	//shift
	parser->lrTable[7][0].LRTableFuncP = LRShift;
	parser->lrTable[7][0].actionParam = 20;
	//shift
	parser->lrTable[8][0].LRTableFuncP = LRShift;
	parser->lrTable[8][0].actionParam = 21;
	//shift
	parser->lrTable[10][0].LRTableFuncP = LRShift;
	parser->lrTable[10][0].actionParam = 22;
	//shift
	parser->lrTable[11][0].LRTableFuncP = LRShift;
	parser->lrTable[11][0].actionParam = 23;
	//shift
	parser->lrTable[25][0].LRTableFuncP = LRShift;
	parser->lrTable[25][0].actionParam = 24;
	//shift
	parser->lrTable[29][0].LRTableFuncP = LRShift;
	parser->lrTable[29][0].actionParam = 25;
	//shift
	parser->lrTable[35][0].LRTableFuncP = LRShift;
	parser->lrTable[35][0].actionParam = 26;
	//shift
	parser->lrTable[36][0].LRTableFuncP = LRShift;
	parser->lrTable[36][0].actionParam = 27;
	//shift
	parser->lrTable[37][0].LRTableFuncP = LRShift;
	parser->lrTable[37][0].actionParam = 28;
	//shift
	parser->lrTable[38][0].LRTableFuncP = LRShift;
	parser->lrTable[38][0].actionParam = 29;
	//shift
	parser->lrTable[39][0].LRTableFuncP = LRShift;
	parser->lrTable[39][0].actionParam = 30;
	//shift
	parser->lrTable[51][0].LRTableFuncP = LRShift;
	parser->lrTable[51][0].actionParam = 31;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][0].actionParam = 56;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][0].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][0].actionParam = 47;
	//reduce
	parser->lrTable[4][0].LRTableFuncP = LRReduce;
	parser->lrTable[4][0].actionParam = 92;
	//reduce
	parser->lrTable[7][0].LRTableFuncP = LRReduce;
	parser->lrTable[7][0].actionParam = 92;
	//reduce
	parser->lrTable[8][0].LRTableFuncP = LRReduce;
	parser->lrTable[8][0].actionParam = 92;
	//reduce
	parser->lrTable[10][0].LRTableFuncP = LRReduce;
	parser->lrTable[10][0].actionParam = 92;
	//reduce
	parser->lrTable[11][0].LRTableFuncP = LRReduce;
	parser->lrTable[11][0].actionParam = 92;
	//reduce
	parser->lrTable[25][0].LRTableFuncP = LRReduce;
	parser->lrTable[25][0].actionParam = 92;
	//reduce
	parser->lrTable[29][0].LRTableFuncP = LRReduce;
	parser->lrTable[29][0].actionParam = 92;
	//reduce
	parser->lrTable[35][0].LRTableFuncP = LRReduce;
	parser->lrTable[35][0].actionParam = 92;
	//reduce
	parser->lrTable[36][0].LRTableFuncP = LRReduce;
	parser->lrTable[36][0].actionParam = 92;
	//reduce
	parser->lrTable[37][0].LRTableFuncP = LRReduce;
	parser->lrTable[37][0].actionParam = 92;
	//reduce
	parser->lrTable[38][0].LRTableFuncP = LRReduce;
	parser->lrTable[38][0].actionParam = 92;
	//reduce
	parser->lrTable[39][0].LRTableFuncP = LRReduce;
	parser->lrTable[39][0].actionParam = 92;
	//reduce
	parser->lrTable[51][0].LRTableFuncP = LRReduce;
	parser->lrTable[51][0].actionParam = 92;
	//shift
	parser->lrTable[4][0].LRTableFuncP = LRShift;
	parser->lrTable[4][0].actionParam = 19;
	//shift
	parser->lrTable[7][0].LRTableFuncP = LRShift;
	parser->lrTable[7][0].actionParam = 20;
	//shift
	parser->lrTable[8][0].LRTableFuncP = LRShift;
	parser->lrTable[8][0].actionParam = 21;
	//shift
	parser->lrTable[10][0].LRTableFuncP = LRShift;
	parser->lrTable[10][0].actionParam = 22;
	//shift
	parser->lrTable[11][0].LRTableFuncP = LRShift;
	parser->lrTable[11][0].actionParam = 23;
	//shift
	parser->lrTable[25][0].LRTableFuncP = LRShift;
	parser->lrTable[25][0].actionParam = 24;
	//shift
	parser->lrTable[29][0].LRTableFuncP = LRShift;
	parser->lrTable[29][0].actionParam = 25;
	//shift
	parser->lrTable[35][0].LRTableFuncP = LRShift;
	parser->lrTable[35][0].actionParam = 26;
	//shift
	parser->lrTable[36][0].LRTableFuncP = LRShift;
	parser->lrTable[36][0].actionParam = 27;
	//shift
	parser->lrTable[37][0].LRTableFuncP = LRShift;
	parser->lrTable[37][0].actionParam = 28;
	//shift
	parser->lrTable[38][0].LRTableFuncP = LRShift;
	parser->lrTable[38][0].actionParam = 29;
	//shift
	parser->lrTable[39][0].LRTableFuncP = LRShift;
	parser->lrTable[39][0].actionParam = 30;
	//shift
	parser->lrTable[51][0].LRTableFuncP = LRShift;
	parser->lrTable[51][0].actionParam = 31;
	//goto
	parser->lrTable[expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[expression+TOTAL_TOKENS][0].actionParam = 57;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][0].actionParam = 33;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][0].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][0].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][0].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][0].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][0].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][0].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][0].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][0].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][0].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][0].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][0].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][0].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][0].actionParam = 47;
	//reduce
	parser->lrTable[0][1].LRTableFuncP = LRReduce;
	parser->lrTable[0][1].actionParam = 104;
	//reduce
	parser->lrTable[1][1].LRTableFuncP = LRReduce;
	parser->lrTable[1][1].actionParam = 104;
	//reduce
	parser->lrTable[2][1].LRTableFuncP = LRReduce;
	parser->lrTable[2][1].actionParam = 104;
	//reduce
	parser->lrTable[3][1].LRTableFuncP = LRReduce;
	parser->lrTable[3][1].actionParam = 104;
	//reduce
	parser->lrTable[4][1].LRTableFuncP = LRReduce;
	parser->lrTable[4][1].actionParam = 104;
	//reduce
	parser->lrTable[2][1].LRTableFuncP = LRReduce;
	parser->lrTable[2][1].actionParam = 104;
	//reduce
	parser->lrTable[7][1].LRTableFuncP = LRReduce;
	parser->lrTable[7][1].actionParam = 104;
	//reduce
	parser->lrTable[8][1].LRTableFuncP = LRReduce;
	parser->lrTable[8][1].actionParam = 104;
	//reduce
	parser->lrTable[7][1].LRTableFuncP = LRReduce;
	parser->lrTable[7][1].actionParam = 104;
	//reduce
	parser->lrTable[10][1].LRTableFuncP = LRReduce;
	parser->lrTable[10][1].actionParam = 104;
	//reduce
	parser->lrTable[11][1].LRTableFuncP = LRReduce;
	parser->lrTable[11][1].actionParam = 104;
	//reduce
	parser->lrTable[10][1].LRTableFuncP = LRReduce;
	parser->lrTable[10][1].actionParam = 104;
	//reduce
	parser->lrTable[13][1].LRTableFuncP = LRReduce;
	parser->lrTable[13][1].actionParam = 104;
	//reduce
	parser->lrTable[13][1].LRTableFuncP = LRReduce;
	parser->lrTable[13][1].actionParam = 104;
	//reduce
	parser->lrTable[15][1].LRTableFuncP = LRReduce;
	parser->lrTable[15][1].actionParam = 104;
	//reduce
	parser->lrTable[15][1].LRTableFuncP = LRReduce;
	parser->lrTable[15][1].actionParam = 104;
	//reduce
	parser->lrTable[17][1].LRTableFuncP = LRReduce;
	parser->lrTable[17][1].actionParam = 104;
	//reduce
	parser->lrTable[17][1].LRTableFuncP = LRReduce;
	parser->lrTable[17][1].actionParam = 104;
	//reduce
	parser->lrTable[19][1].LRTableFuncP = LRReduce;
	parser->lrTable[19][1].actionParam = 104;
	//reduce
	parser->lrTable[20][1].LRTableFuncP = LRReduce;
	parser->lrTable[20][1].actionParam = 104;
	//reduce
	parser->lrTable[21][1].LRTableFuncP = LRReduce;
	parser->lrTable[21][1].actionParam = 104;
	//reduce
	parser->lrTable[21][1].LRTableFuncP = LRReduce;
	parser->lrTable[21][1].actionParam = 104;
	//reduce
	parser->lrTable[23][1].LRTableFuncP = LRReduce;
	parser->lrTable[23][1].actionParam = 104;
	//reduce
	parser->lrTable[23][1].LRTableFuncP = LRReduce;
	parser->lrTable[23][1].actionParam = 104;
	//reduce
	parser->lrTable[27][1].LRTableFuncP = LRReduce;
	parser->lrTable[27][1].actionParam = 104;
	//reduce
	parser->lrTable[28][1].LRTableFuncP = LRReduce;
	parser->lrTable[28][1].actionParam = 104;
	//reduce
	parser->lrTable[29][1].LRTableFuncP = LRReduce;
	parser->lrTable[29][1].actionParam = 104;
	//reduce
	parser->lrTable[30][1].LRTableFuncP = LRReduce;
	parser->lrTable[30][1].actionParam = 104;
	//reduce
	parser->lrTable[33][1].LRTableFuncP = LRReduce;
	parser->lrTable[33][1].actionParam = 104;
	//reduce
	parser->lrTable[34][1].LRTableFuncP = LRReduce;
	parser->lrTable[34][1].actionParam = 104;
	//reduce
	parser->lrTable[47][1].LRTableFuncP = LRReduce;
	parser->lrTable[47][1].actionParam = 104;
	//reduce
	parser->lrTable[48][1].LRTableFuncP = LRReduce;
	parser->lrTable[48][1].actionParam = 104;
	//reduce
	parser->lrTable[56][1].LRTableFuncP = LRReduce;
	parser->lrTable[56][1].actionParam = 104;
	//reduce
	parser->lrTable[57][1].LRTableFuncP = LRReduce;
	parser->lrTable[57][1].actionParam = 104;
	//reduce
	parser->lrTable[58][1].LRTableFuncP = LRReduce;
	parser->lrTable[58][1].actionParam = 104;
	//reduce
	parser->lrTable[59][1].LRTableFuncP = LRReduce;
	parser->lrTable[59][1].actionParam = 104;
	//reduce
	parser->lrTable[0][2].LRTableFuncP = LRReduce;
	parser->lrTable[0][2].actionParam = 106;
	//reduce
	parser->lrTable[1][2].LRTableFuncP = LRReduce;
	parser->lrTable[1][2].actionParam = 106;
	//reduce
	parser->lrTable[2][2].LRTableFuncP = LRReduce;
	parser->lrTable[2][2].actionParam = 106;
	//reduce
	parser->lrTable[3][2].LRTableFuncP = LRReduce;
	parser->lrTable[3][2].actionParam = 106;
	//reduce
	parser->lrTable[4][2].LRTableFuncP = LRReduce;
	parser->lrTable[4][2].actionParam = 106;
	//reduce
	parser->lrTable[2][2].LRTableFuncP = LRReduce;
	parser->lrTable[2][2].actionParam = 106;
	//reduce
	parser->lrTable[7][2].LRTableFuncP = LRReduce;
	parser->lrTable[7][2].actionParam = 106;
	//reduce
	parser->lrTable[8][2].LRTableFuncP = LRReduce;
	parser->lrTable[8][2].actionParam = 106;
	//reduce
	parser->lrTable[7][2].LRTableFuncP = LRReduce;
	parser->lrTable[7][2].actionParam = 106;
	//reduce
	parser->lrTable[10][2].LRTableFuncP = LRReduce;
	parser->lrTable[10][2].actionParam = 106;
	//reduce
	parser->lrTable[11][2].LRTableFuncP = LRReduce;
	parser->lrTable[11][2].actionParam = 106;
	//reduce
	parser->lrTable[10][2].LRTableFuncP = LRReduce;
	parser->lrTable[10][2].actionParam = 106;
	//reduce
	parser->lrTable[13][2].LRTableFuncP = LRReduce;
	parser->lrTable[13][2].actionParam = 106;
	//reduce
	parser->lrTable[13][2].LRTableFuncP = LRReduce;
	parser->lrTable[13][2].actionParam = 106;
	//reduce
	parser->lrTable[15][2].LRTableFuncP = LRReduce;
	parser->lrTable[15][2].actionParam = 106;
	//reduce
	parser->lrTable[15][2].LRTableFuncP = LRReduce;
	parser->lrTable[15][2].actionParam = 106;
	//reduce
	parser->lrTable[17][2].LRTableFuncP = LRReduce;
	parser->lrTable[17][2].actionParam = 106;
	//reduce
	parser->lrTable[17][2].LRTableFuncP = LRReduce;
	parser->lrTable[17][2].actionParam = 106;
	//reduce
	parser->lrTable[19][2].LRTableFuncP = LRReduce;
	parser->lrTable[19][2].actionParam = 106;
	//reduce
	parser->lrTable[20][2].LRTableFuncP = LRReduce;
	parser->lrTable[20][2].actionParam = 106;
	//reduce
	parser->lrTable[21][2].LRTableFuncP = LRReduce;
	parser->lrTable[21][2].actionParam = 106;
	//reduce
	parser->lrTable[21][2].LRTableFuncP = LRReduce;
	parser->lrTable[21][2].actionParam = 106;
	//reduce
	parser->lrTable[23][2].LRTableFuncP = LRReduce;
	parser->lrTable[23][2].actionParam = 106;
	//reduce
	parser->lrTable[23][2].LRTableFuncP = LRReduce;
	parser->lrTable[23][2].actionParam = 106;
	//reduce
	parser->lrTable[27][2].LRTableFuncP = LRReduce;
	parser->lrTable[27][2].actionParam = 106;
	//reduce
	parser->lrTable[28][2].LRTableFuncP = LRReduce;
	parser->lrTable[28][2].actionParam = 106;
	//reduce
	parser->lrTable[29][2].LRTableFuncP = LRReduce;
	parser->lrTable[29][2].actionParam = 106;
	//reduce
	parser->lrTable[30][2].LRTableFuncP = LRReduce;
	parser->lrTable[30][2].actionParam = 106;
	//reduce
	parser->lrTable[33][2].LRTableFuncP = LRReduce;
	parser->lrTable[33][2].actionParam = 106;
	//reduce
	parser->lrTable[34][2].LRTableFuncP = LRReduce;
	parser->lrTable[34][2].actionParam = 106;
	//reduce
	parser->lrTable[47][2].LRTableFuncP = LRReduce;
	parser->lrTable[47][2].actionParam = 106;
	//reduce
	parser->lrTable[48][2].LRTableFuncP = LRReduce;
	parser->lrTable[48][2].actionParam = 106;
	//reduce
	parser->lrTable[56][2].LRTableFuncP = LRReduce;
	parser->lrTable[56][2].actionParam = 106;
	//reduce
	parser->lrTable[57][2].LRTableFuncP = LRReduce;
	parser->lrTable[57][2].actionParam = 106;
	//reduce
	parser->lrTable[58][2].LRTableFuncP = LRReduce;
	parser->lrTable[58][2].actionParam = 106;
	//reduce
	parser->lrTable[59][2].LRTableFuncP = LRReduce;
	parser->lrTable[59][2].actionParam = 106;
	//reduce
	parser->lrTable[0][3].LRTableFuncP = LRReduce;
	parser->lrTable[0][3].actionParam = 107;
	//reduce
	parser->lrTable[1][3].LRTableFuncP = LRReduce;
	parser->lrTable[1][3].actionParam = 107;
	//reduce
	parser->lrTable[2][3].LRTableFuncP = LRReduce;
	parser->lrTable[2][3].actionParam = 107;
	//reduce
	parser->lrTable[3][3].LRTableFuncP = LRReduce;
	parser->lrTable[3][3].actionParam = 107;
	//reduce
	parser->lrTable[4][3].LRTableFuncP = LRReduce;
	parser->lrTable[4][3].actionParam = 107;
	//reduce
	parser->lrTable[2][3].LRTableFuncP = LRReduce;
	parser->lrTable[2][3].actionParam = 107;
	//reduce
	parser->lrTable[7][3].LRTableFuncP = LRReduce;
	parser->lrTable[7][3].actionParam = 107;
	//reduce
	parser->lrTable[8][3].LRTableFuncP = LRReduce;
	parser->lrTable[8][3].actionParam = 107;
	//reduce
	parser->lrTable[7][3].LRTableFuncP = LRReduce;
	parser->lrTable[7][3].actionParam = 107;
	//reduce
	parser->lrTable[10][3].LRTableFuncP = LRReduce;
	parser->lrTable[10][3].actionParam = 107;
	//reduce
	parser->lrTable[11][3].LRTableFuncP = LRReduce;
	parser->lrTable[11][3].actionParam = 107;
	//reduce
	parser->lrTable[10][3].LRTableFuncP = LRReduce;
	parser->lrTable[10][3].actionParam = 107;
	//reduce
	parser->lrTable[13][3].LRTableFuncP = LRReduce;
	parser->lrTable[13][3].actionParam = 107;
	//reduce
	parser->lrTable[13][3].LRTableFuncP = LRReduce;
	parser->lrTable[13][3].actionParam = 107;
	//reduce
	parser->lrTable[15][3].LRTableFuncP = LRReduce;
	parser->lrTable[15][3].actionParam = 107;
	//reduce
	parser->lrTable[15][3].LRTableFuncP = LRReduce;
	parser->lrTable[15][3].actionParam = 107;
	//reduce
	parser->lrTable[17][3].LRTableFuncP = LRReduce;
	parser->lrTable[17][3].actionParam = 107;
	//reduce
	parser->lrTable[17][3].LRTableFuncP = LRReduce;
	parser->lrTable[17][3].actionParam = 107;
	//reduce
	parser->lrTable[19][3].LRTableFuncP = LRReduce;
	parser->lrTable[19][3].actionParam = 107;
	//reduce
	parser->lrTable[20][3].LRTableFuncP = LRReduce;
	parser->lrTable[20][3].actionParam = 107;
	//reduce
	parser->lrTable[21][3].LRTableFuncP = LRReduce;
	parser->lrTable[21][3].actionParam = 107;
	//reduce
	parser->lrTable[21][3].LRTableFuncP = LRReduce;
	parser->lrTable[21][3].actionParam = 107;
	//reduce
	parser->lrTable[23][3].LRTableFuncP = LRReduce;
	parser->lrTable[23][3].actionParam = 107;
	//reduce
	parser->lrTable[23][3].LRTableFuncP = LRReduce;
	parser->lrTable[23][3].actionParam = 107;
	//reduce
	parser->lrTable[27][3].LRTableFuncP = LRReduce;
	parser->lrTable[27][3].actionParam = 107;
	//reduce
	parser->lrTable[28][3].LRTableFuncP = LRReduce;
	parser->lrTable[28][3].actionParam = 107;
	//reduce
	parser->lrTable[29][3].LRTableFuncP = LRReduce;
	parser->lrTable[29][3].actionParam = 107;
	//reduce
	parser->lrTable[30][3].LRTableFuncP = LRReduce;
	parser->lrTable[30][3].actionParam = 107;
	//reduce
	parser->lrTable[33][3].LRTableFuncP = LRReduce;
	parser->lrTable[33][3].actionParam = 107;
	//reduce
	parser->lrTable[34][3].LRTableFuncP = LRReduce;
	parser->lrTable[34][3].actionParam = 107;
	//reduce
	parser->lrTable[47][3].LRTableFuncP = LRReduce;
	parser->lrTable[47][3].actionParam = 107;
	//reduce
	parser->lrTable[48][3].LRTableFuncP = LRReduce;
	parser->lrTable[48][3].actionParam = 107;
	//reduce
	parser->lrTable[56][3].LRTableFuncP = LRReduce;
	parser->lrTable[56][3].actionParam = 107;
	//reduce
	parser->lrTable[57][3].LRTableFuncP = LRReduce;
	parser->lrTable[57][3].actionParam = 107;
	//reduce
	parser->lrTable[58][3].LRTableFuncP = LRReduce;
	parser->lrTable[58][3].actionParam = 107;
	//reduce
	parser->lrTable[59][3].LRTableFuncP = LRReduce;
	parser->lrTable[59][3].actionParam = 107;
	//reduce
	parser->lrTable[0][4].LRTableFuncP = LRReduce;
	parser->lrTable[0][4].actionParam = 103;
	//reduce
	parser->lrTable[1][4].LRTableFuncP = LRReduce;
	parser->lrTable[1][4].actionParam = 103;
	//reduce
	parser->lrTable[2][4].LRTableFuncP = LRReduce;
	parser->lrTable[2][4].actionParam = 103;
	//reduce
	parser->lrTable[3][4].LRTableFuncP = LRReduce;
	parser->lrTable[3][4].actionParam = 103;
	//reduce
	parser->lrTable[4][4].LRTableFuncP = LRReduce;
	parser->lrTable[4][4].actionParam = 103;
	//reduce
	parser->lrTable[2][4].LRTableFuncP = LRReduce;
	parser->lrTable[2][4].actionParam = 103;
	//reduce
	parser->lrTable[7][4].LRTableFuncP = LRReduce;
	parser->lrTable[7][4].actionParam = 103;
	//reduce
	parser->lrTable[8][4].LRTableFuncP = LRReduce;
	parser->lrTable[8][4].actionParam = 103;
	//reduce
	parser->lrTable[7][4].LRTableFuncP = LRReduce;
	parser->lrTable[7][4].actionParam = 103;
	//reduce
	parser->lrTable[10][4].LRTableFuncP = LRReduce;
	parser->lrTable[10][4].actionParam = 103;
	//reduce
	parser->lrTable[11][4].LRTableFuncP = LRReduce;
	parser->lrTable[11][4].actionParam = 103;
	//reduce
	parser->lrTable[10][4].LRTableFuncP = LRReduce;
	parser->lrTable[10][4].actionParam = 103;
	//reduce
	parser->lrTable[13][4].LRTableFuncP = LRReduce;
	parser->lrTable[13][4].actionParam = 103;
	//reduce
	parser->lrTable[13][4].LRTableFuncP = LRReduce;
	parser->lrTable[13][4].actionParam = 103;
	//reduce
	parser->lrTable[15][4].LRTableFuncP = LRReduce;
	parser->lrTable[15][4].actionParam = 103;
	//reduce
	parser->lrTable[15][4].LRTableFuncP = LRReduce;
	parser->lrTable[15][4].actionParam = 103;
	//reduce
	parser->lrTable[17][4].LRTableFuncP = LRReduce;
	parser->lrTable[17][4].actionParam = 103;
	//reduce
	parser->lrTable[17][4].LRTableFuncP = LRReduce;
	parser->lrTable[17][4].actionParam = 103;
	//reduce
	parser->lrTable[19][4].LRTableFuncP = LRReduce;
	parser->lrTable[19][4].actionParam = 103;
	//reduce
	parser->lrTable[20][4].LRTableFuncP = LRReduce;
	parser->lrTable[20][4].actionParam = 103;
	//reduce
	parser->lrTable[21][4].LRTableFuncP = LRReduce;
	parser->lrTable[21][4].actionParam = 103;
	//reduce
	parser->lrTable[21][4].LRTableFuncP = LRReduce;
	parser->lrTable[21][4].actionParam = 103;
	//reduce
	parser->lrTable[23][4].LRTableFuncP = LRReduce;
	parser->lrTable[23][4].actionParam = 103;
	//reduce
	parser->lrTable[23][4].LRTableFuncP = LRReduce;
	parser->lrTable[23][4].actionParam = 103;
	//reduce
	parser->lrTable[27][4].LRTableFuncP = LRReduce;
	parser->lrTable[27][4].actionParam = 103;
	//reduce
	parser->lrTable[28][4].LRTableFuncP = LRReduce;
	parser->lrTable[28][4].actionParam = 103;
	//reduce
	parser->lrTable[29][4].LRTableFuncP = LRReduce;
	parser->lrTable[29][4].actionParam = 103;
	//reduce
	parser->lrTable[30][4].LRTableFuncP = LRReduce;
	parser->lrTable[30][4].actionParam = 103;
	//reduce
	parser->lrTable[33][4].LRTableFuncP = LRReduce;
	parser->lrTable[33][4].actionParam = 103;
	//reduce
	parser->lrTable[34][4].LRTableFuncP = LRReduce;
	parser->lrTable[34][4].actionParam = 103;
	//reduce
	parser->lrTable[47][4].LRTableFuncP = LRReduce;
	parser->lrTable[47][4].actionParam = 103;
	//reduce
	parser->lrTable[48][4].LRTableFuncP = LRReduce;
	parser->lrTable[48][4].actionParam = 103;
	//reduce
	parser->lrTable[56][4].LRTableFuncP = LRReduce;
	parser->lrTable[56][4].actionParam = 103;
	//reduce
	parser->lrTable[57][4].LRTableFuncP = LRReduce;
	parser->lrTable[57][4].actionParam = 103;
	//reduce
	parser->lrTable[58][4].LRTableFuncP = LRReduce;
	parser->lrTable[58][4].actionParam = 103;
	//reduce
	parser->lrTable[59][4].LRTableFuncP = LRReduce;
	parser->lrTable[59][4].actionParam = 103;
	//reduce
	parser->lrTable[0][5].LRTableFuncP = LRReduce;
	parser->lrTable[0][5].actionParam = 105;
	//reduce
	parser->lrTable[1][5].LRTableFuncP = LRReduce;
	parser->lrTable[1][5].actionParam = 105;
	//reduce
	parser->lrTable[2][5].LRTableFuncP = LRReduce;
	parser->lrTable[2][5].actionParam = 105;
	//reduce
	parser->lrTable[3][5].LRTableFuncP = LRReduce;
	parser->lrTable[3][5].actionParam = 105;
	//reduce
	parser->lrTable[4][5].LRTableFuncP = LRReduce;
	parser->lrTable[4][5].actionParam = 105;
	//reduce
	parser->lrTable[2][5].LRTableFuncP = LRReduce;
	parser->lrTable[2][5].actionParam = 105;
	//reduce
	parser->lrTable[7][5].LRTableFuncP = LRReduce;
	parser->lrTable[7][5].actionParam = 105;
	//reduce
	parser->lrTable[8][5].LRTableFuncP = LRReduce;
	parser->lrTable[8][5].actionParam = 105;
	//reduce
	parser->lrTable[7][5].LRTableFuncP = LRReduce;
	parser->lrTable[7][5].actionParam = 105;
	//reduce
	parser->lrTable[10][5].LRTableFuncP = LRReduce;
	parser->lrTable[10][5].actionParam = 105;
	//reduce
	parser->lrTable[11][5].LRTableFuncP = LRReduce;
	parser->lrTable[11][5].actionParam = 105;
	//reduce
	parser->lrTable[10][5].LRTableFuncP = LRReduce;
	parser->lrTable[10][5].actionParam = 105;
	//reduce
	parser->lrTable[13][5].LRTableFuncP = LRReduce;
	parser->lrTable[13][5].actionParam = 105;
	//reduce
	parser->lrTable[13][5].LRTableFuncP = LRReduce;
	parser->lrTable[13][5].actionParam = 105;
	//reduce
	parser->lrTable[15][5].LRTableFuncP = LRReduce;
	parser->lrTable[15][5].actionParam = 105;
	//reduce
	parser->lrTable[15][5].LRTableFuncP = LRReduce;
	parser->lrTable[15][5].actionParam = 105;
	//reduce
	parser->lrTable[17][5].LRTableFuncP = LRReduce;
	parser->lrTable[17][5].actionParam = 105;
	//reduce
	parser->lrTable[17][5].LRTableFuncP = LRReduce;
	parser->lrTable[17][5].actionParam = 105;
	//reduce
	parser->lrTable[19][5].LRTableFuncP = LRReduce;
	parser->lrTable[19][5].actionParam = 105;
	//reduce
	parser->lrTable[20][5].LRTableFuncP = LRReduce;
	parser->lrTable[20][5].actionParam = 105;
	//reduce
	parser->lrTable[21][5].LRTableFuncP = LRReduce;
	parser->lrTable[21][5].actionParam = 105;
	//reduce
	parser->lrTable[21][5].LRTableFuncP = LRReduce;
	parser->lrTable[21][5].actionParam = 105;
	//reduce
	parser->lrTable[23][5].LRTableFuncP = LRReduce;
	parser->lrTable[23][5].actionParam = 105;
	//reduce
	parser->lrTable[23][5].LRTableFuncP = LRReduce;
	parser->lrTable[23][5].actionParam = 105;
	//reduce
	parser->lrTable[27][5].LRTableFuncP = LRReduce;
	parser->lrTable[27][5].actionParam = 105;
	//reduce
	parser->lrTable[28][5].LRTableFuncP = LRReduce;
	parser->lrTable[28][5].actionParam = 105;
	//reduce
	parser->lrTable[29][5].LRTableFuncP = LRReduce;
	parser->lrTable[29][5].actionParam = 105;
	//reduce
	parser->lrTable[30][5].LRTableFuncP = LRReduce;
	parser->lrTable[30][5].actionParam = 105;
	//reduce
	parser->lrTable[33][5].LRTableFuncP = LRReduce;
	parser->lrTable[33][5].actionParam = 105;
	//reduce
	parser->lrTable[34][5].LRTableFuncP = LRReduce;
	parser->lrTable[34][5].actionParam = 105;
	//reduce
	parser->lrTable[47][5].LRTableFuncP = LRReduce;
	parser->lrTable[47][5].actionParam = 105;
	//reduce
	parser->lrTable[48][5].LRTableFuncP = LRReduce;
	parser->lrTable[48][5].actionParam = 105;
	//reduce
	parser->lrTable[56][5].LRTableFuncP = LRReduce;
	parser->lrTable[56][5].actionParam = 105;
	//reduce
	parser->lrTable[57][5].LRTableFuncP = LRReduce;
	parser->lrTable[57][5].actionParam = 105;
	//reduce
	parser->lrTable[58][5].LRTableFuncP = LRReduce;
	parser->lrTable[58][5].actionParam = 105;
	//reduce
	parser->lrTable[59][5].LRTableFuncP = LRReduce;
	parser->lrTable[59][5].actionParam = 105;
	//reduce
	parser->lrTable[0][6].LRTableFuncP = LRReduce;
	parser->lrTable[0][6].actionParam = 102;
	//reduce
	parser->lrTable[1][6].LRTableFuncP = LRReduce;
	parser->lrTable[1][6].actionParam = 102;
	//reduce
	parser->lrTable[2][6].LRTableFuncP = LRReduce;
	parser->lrTable[2][6].actionParam = 102;
	//reduce
	parser->lrTable[3][6].LRTableFuncP = LRReduce;
	parser->lrTable[3][6].actionParam = 102;
	//reduce
	parser->lrTable[4][6].LRTableFuncP = LRReduce;
	parser->lrTable[4][6].actionParam = 102;
	//reduce
	parser->lrTable[2][6].LRTableFuncP = LRReduce;
	parser->lrTable[2][6].actionParam = 102;
	//reduce
	parser->lrTable[7][6].LRTableFuncP = LRReduce;
	parser->lrTable[7][6].actionParam = 102;
	//reduce
	parser->lrTable[8][6].LRTableFuncP = LRReduce;
	parser->lrTable[8][6].actionParam = 102;
	//reduce
	parser->lrTable[7][6].LRTableFuncP = LRReduce;
	parser->lrTable[7][6].actionParam = 102;
	//reduce
	parser->lrTable[10][6].LRTableFuncP = LRReduce;
	parser->lrTable[10][6].actionParam = 102;
	//reduce
	parser->lrTable[11][6].LRTableFuncP = LRReduce;
	parser->lrTable[11][6].actionParam = 102;
	//reduce
	parser->lrTable[10][6].LRTableFuncP = LRReduce;
	parser->lrTable[10][6].actionParam = 102;
	//reduce
	parser->lrTable[13][6].LRTableFuncP = LRReduce;
	parser->lrTable[13][6].actionParam = 102;
	//reduce
	parser->lrTable[13][6].LRTableFuncP = LRReduce;
	parser->lrTable[13][6].actionParam = 102;
	//reduce
	parser->lrTable[15][6].LRTableFuncP = LRReduce;
	parser->lrTable[15][6].actionParam = 102;
	//reduce
	parser->lrTable[15][6].LRTableFuncP = LRReduce;
	parser->lrTable[15][6].actionParam = 102;
	//reduce
	parser->lrTable[17][6].LRTableFuncP = LRReduce;
	parser->lrTable[17][6].actionParam = 102;
	//reduce
	parser->lrTable[17][6].LRTableFuncP = LRReduce;
	parser->lrTable[17][6].actionParam = 102;
	//reduce
	parser->lrTable[19][6].LRTableFuncP = LRReduce;
	parser->lrTable[19][6].actionParam = 102;
	//reduce
	parser->lrTable[20][6].LRTableFuncP = LRReduce;
	parser->lrTable[20][6].actionParam = 102;
	//reduce
	parser->lrTable[21][6].LRTableFuncP = LRReduce;
	parser->lrTable[21][6].actionParam = 102;
	//reduce
	parser->lrTable[21][6].LRTableFuncP = LRReduce;
	parser->lrTable[21][6].actionParam = 102;
	//reduce
	parser->lrTable[23][6].LRTableFuncP = LRReduce;
	parser->lrTable[23][6].actionParam = 102;
	//reduce
	parser->lrTable[23][6].LRTableFuncP = LRReduce;
	parser->lrTable[23][6].actionParam = 102;
	//reduce
	parser->lrTable[27][6].LRTableFuncP = LRReduce;
	parser->lrTable[27][6].actionParam = 102;
	//reduce
	parser->lrTable[28][6].LRTableFuncP = LRReduce;
	parser->lrTable[28][6].actionParam = 102;
	//reduce
	parser->lrTable[29][6].LRTableFuncP = LRReduce;
	parser->lrTable[29][6].actionParam = 102;
	//reduce
	parser->lrTable[30][6].LRTableFuncP = LRReduce;
	parser->lrTable[30][6].actionParam = 102;
	//reduce
	parser->lrTable[33][6].LRTableFuncP = LRReduce;
	parser->lrTable[33][6].actionParam = 102;
	//reduce
	parser->lrTable[34][6].LRTableFuncP = LRReduce;
	parser->lrTable[34][6].actionParam = 102;
	//reduce
	parser->lrTable[47][6].LRTableFuncP = LRReduce;
	parser->lrTable[47][6].actionParam = 102;
	//reduce
	parser->lrTable[48][6].LRTableFuncP = LRReduce;
	parser->lrTable[48][6].actionParam = 102;
	//reduce
	parser->lrTable[56][6].LRTableFuncP = LRReduce;
	parser->lrTable[56][6].actionParam = 102;
	//reduce
	parser->lrTable[57][6].LRTableFuncP = LRReduce;
	parser->lrTable[57][6].actionParam = 102;
	//reduce
	parser->lrTable[58][6].LRTableFuncP = LRReduce;
	parser->lrTable[58][6].actionParam = 102;
	//reduce
	parser->lrTable[59][6].LRTableFuncP = LRReduce;
	parser->lrTable[59][6].actionParam = 102;
	//shift
	parser->lrTable[57][6].LRTableFuncP = LRShift;
	parser->lrTable[57][6].actionParam = 58;
	//reduce
	parser->lrTable[56][6].LRTableFuncP = LRReduce;
	parser->lrTable[56][6].actionParam = 10;
	//reduce
	parser->lrTable[57][6].LRTableFuncP = LRReduce;
	parser->lrTable[57][6].actionParam = 10;
	//reduce
	parser->lrTable[30][6].LRTableFuncP = LRReduce;
	parser->lrTable[30][6].actionParam = 42;
	//reduce
	parser->lrTable[34][6].LRTableFuncP = LRReduce;
	parser->lrTable[34][6].actionParam = 42;
	//reduce
	parser->lrTable[56][6].LRTableFuncP = LRReduce;
	parser->lrTable[56][6].actionParam = 42;
	//reduce
	parser->lrTable[57][6].LRTableFuncP = LRReduce;
	parser->lrTable[57][6].actionParam = 42;
	//reduce
	parser->lrTable[59][6].LRTableFuncP = LRReduce;
	parser->lrTable[59][6].actionParam = 42;
	//reduce
	parser->lrTable[30][6].LRTableFuncP = LRReduce;
	parser->lrTable[30][6].actionParam = 44;
	//reduce
	parser->lrTable[34][6].LRTableFuncP = LRReduce;
	parser->lrTable[34][6].actionParam = 44;
	//reduce
	parser->lrTable[56][6].LRTableFuncP = LRReduce;
	parser->lrTable[56][6].actionParam = 44;
	//reduce
	parser->lrTable[57][6].LRTableFuncP = LRReduce;
	parser->lrTable[57][6].actionParam = 44;
	//reduce
	parser->lrTable[59][6].LRTableFuncP = LRReduce;
	parser->lrTable[59][6].actionParam = 44;
	//shift
	parser->lrTable[48][6].LRTableFuncP = LRShift;
	parser->lrTable[48][6].actionParam = 59;
	//shift
	parser->lrTable[58][6].LRTableFuncP = LRShift;
	parser->lrTable[58][6].actionParam = 60;
	//reduce
	parser->lrTable[30][6].LRTableFuncP = LRReduce;
	parser->lrTable[30][6].actionParam = 55;
	//reduce
	parser->lrTable[34][6].LRTableFuncP = LRReduce;
	parser->lrTable[34][6].actionParam = 55;
	//reduce
	parser->lrTable[56][6].LRTableFuncP = LRReduce;
	parser->lrTable[56][6].actionParam = 55;
	//reduce
	parser->lrTable[57][6].LRTableFuncP = LRReduce;
	parser->lrTable[57][6].actionParam = 55;
	//reduce
	parser->lrTable[59][6].LRTableFuncP = LRReduce;
	parser->lrTable[59][6].actionParam = 55;
	//shift
	parser->lrTable[47][6].LRTableFuncP = LRShift;
	parser->lrTable[47][6].actionParam = 61;
	//reduce
	parser->lrTable[30][6].LRTableFuncP = LRReduce;
	parser->lrTable[30][6].actionParam = 57;
	//reduce
	parser->lrTable[34][6].LRTableFuncP = LRReduce;
	parser->lrTable[34][6].actionParam = 57;
	//reduce
	parser->lrTable[48][6].LRTableFuncP = LRReduce;
	parser->lrTable[48][6].actionParam = 57;
	//reduce
	parser->lrTable[56][6].LRTableFuncP = LRReduce;
	parser->lrTable[56][6].actionParam = 57;
	//reduce
	parser->lrTable[57][6].LRTableFuncP = LRReduce;
	parser->lrTable[57][6].actionParam = 57;
	//reduce
	parser->lrTable[58][6].LRTableFuncP = LRReduce;
	parser->lrTable[58][6].actionParam = 57;
	//reduce
	parser->lrTable[59][6].LRTableFuncP = LRReduce;
	parser->lrTable[59][6].actionParam = 57;
	//shift
	parser->lrTable[21][6].LRTableFuncP = LRShift;
	parser->lrTable[21][6].actionParam = 62;
	//reduce
	parser->lrTable[30][6].LRTableFuncP = LRReduce;
	parser->lrTable[30][6].actionParam = 59;
	//reduce
	parser->lrTable[34][6].LRTableFuncP = LRReduce;
	parser->lrTable[34][6].actionParam = 59;
	//reduce
	parser->lrTable[47][6].LRTableFuncP = LRReduce;
	parser->lrTable[47][6].actionParam = 59;
	//reduce
	parser->lrTable[48][6].LRTableFuncP = LRReduce;
	parser->lrTable[48][6].actionParam = 59;
	//reduce
	parser->lrTable[56][6].LRTableFuncP = LRReduce;
	parser->lrTable[56][6].actionParam = 59;
	//reduce
	parser->lrTable[57][6].LRTableFuncP = LRReduce;
	parser->lrTable[57][6].actionParam = 59;
	//reduce
	parser->lrTable[58][6].LRTableFuncP = LRReduce;
	parser->lrTable[58][6].actionParam = 59;
	//reduce
	parser->lrTable[59][6].LRTableFuncP = LRReduce;
	parser->lrTable[59][6].actionParam = 59;
	//shift
	parser->lrTable[23][6].LRTableFuncP = LRShift;
	parser->lrTable[23][6].actionParam = 63;
	//reduce
	parser->lrTable[21][6].LRTableFuncP = LRReduce;
	parser->lrTable[21][6].actionParam = 61;
	//reduce
	parser->lrTable[30][6].LRTableFuncP = LRReduce;
	parser->lrTable[30][6].actionParam = 61;
	//reduce
	parser->lrTable[34][6].LRTableFuncP = LRReduce;
	parser->lrTable[34][6].actionParam = 61;
	//reduce
	parser->lrTable[47][6].LRTableFuncP = LRReduce;
	parser->lrTable[47][6].actionParam = 61;
	//reduce
	parser->lrTable[48][6].LRTableFuncP = LRReduce;
	parser->lrTable[48][6].actionParam = 61;
	//reduce
	parser->lrTable[56][6].LRTableFuncP = LRReduce;
	parser->lrTable[56][6].actionParam = 61;
	//reduce
	parser->lrTable[57][6].LRTableFuncP = LRReduce;
	parser->lrTable[57][6].actionParam = 61;
	//reduce
	parser->lrTable[58][6].LRTableFuncP = LRReduce;
	parser->lrTable[58][6].actionParam = 61;
	//reduce
	parser->lrTable[59][6].LRTableFuncP = LRReduce;
	parser->lrTable[59][6].actionParam = 61;
	//shift
	parser->lrTable[19][6].LRTableFuncP = LRShift;
	parser->lrTable[19][6].actionParam = 64;
	//reduce
	parser->lrTable[21][6].LRTableFuncP = LRReduce;
	parser->lrTable[21][6].actionParam = 63;
	//reduce
	parser->lrTable[23][6].LRTableFuncP = LRReduce;
	parser->lrTable[23][6].actionParam = 63;
	//reduce
	parser->lrTable[30][6].LRTableFuncP = LRReduce;
	parser->lrTable[30][6].actionParam = 63;
	//reduce
	parser->lrTable[34][6].LRTableFuncP = LRReduce;
	parser->lrTable[34][6].actionParam = 63;
	//reduce
	parser->lrTable[47][6].LRTableFuncP = LRReduce;
	parser->lrTable[47][6].actionParam = 63;
	//reduce
	parser->lrTable[48][6].LRTableFuncP = LRReduce;
	parser->lrTable[48][6].actionParam = 63;
	//reduce
	parser->lrTable[56][6].LRTableFuncP = LRReduce;
	parser->lrTable[56][6].actionParam = 63;
	//reduce
	parser->lrTable[57][6].LRTableFuncP = LRReduce;
	parser->lrTable[57][6].actionParam = 63;
	//reduce
	parser->lrTable[58][6].LRTableFuncP = LRReduce;
	parser->lrTable[58][6].actionParam = 63;
	//reduce
	parser->lrTable[59][6].LRTableFuncP = LRReduce;
	parser->lrTable[59][6].actionParam = 63;
	//shift
	parser->lrTable[3][6].LRTableFuncP = LRShift;
	parser->lrTable[3][6].actionParam = 65;
	//shift
	parser->lrTable[4][6].LRTableFuncP = LRShift;
	parser->lrTable[4][6].actionParam = 66;
	//reduce
	parser->lrTable[19][6].LRTableFuncP = LRReduce;
	parser->lrTable[19][6].actionParam = 65;
	//reduce
	parser->lrTable[21][6].LRTableFuncP = LRReduce;
	parser->lrTable[21][6].actionParam = 65;
	//reduce
	parser->lrTable[23][6].LRTableFuncP = LRReduce;
	parser->lrTable[23][6].actionParam = 65;
	//reduce
	parser->lrTable[30][6].LRTableFuncP = LRReduce;
	parser->lrTable[30][6].actionParam = 65;
	//reduce
	parser->lrTable[34][6].LRTableFuncP = LRReduce;
	parser->lrTable[34][6].actionParam = 65;
	//reduce
	parser->lrTable[47][6].LRTableFuncP = LRReduce;
	parser->lrTable[47][6].actionParam = 65;
	//reduce
	parser->lrTable[48][6].LRTableFuncP = LRReduce;
	parser->lrTable[48][6].actionParam = 65;
	//reduce
	parser->lrTable[56][6].LRTableFuncP = LRReduce;
	parser->lrTable[56][6].actionParam = 65;
	//reduce
	parser->lrTable[57][6].LRTableFuncP = LRReduce;
	parser->lrTable[57][6].actionParam = 65;
	//reduce
	parser->lrTable[58][6].LRTableFuncP = LRReduce;
	parser->lrTable[58][6].actionParam = 65;
	//reduce
	parser->lrTable[59][6].LRTableFuncP = LRReduce;
	parser->lrTable[59][6].actionParam = 65;
	//shift
	parser->lrTable[0][7].LRTableFuncP = LRShift;
	parser->lrTable[0][7].actionParam = 68;
	//shift
	parser->lrTable[1][7].LRTableFuncP = LRShift;
	parser->lrTable[1][7].actionParam = 69;
	//shift
	parser->lrTable[2][7].LRTableFuncP = LRShift;
	parser->lrTable[2][7].actionParam = 70;
	//reduce
	parser->lrTable[3][7].LRTableFuncP = LRReduce;
	parser->lrTable[3][7].actionParam = 67;
	//reduce
	parser->lrTable[4][7].LRTableFuncP = LRReduce;
	parser->lrTable[4][7].actionParam = 67;
	//reduce
	parser->lrTable[19][7].LRTableFuncP = LRReduce;
	parser->lrTable[19][7].actionParam = 67;
	//reduce
	parser->lrTable[21][7].LRTableFuncP = LRReduce;
	parser->lrTable[21][7].actionParam = 67;
	//reduce
	parser->lrTable[23][7].LRTableFuncP = LRReduce;
	parser->lrTable[23][7].actionParam = 67;
	//reduce
	parser->lrTable[30][7].LRTableFuncP = LRReduce;
	parser->lrTable[30][7].actionParam = 67;
	//reduce
	parser->lrTable[34][7].LRTableFuncP = LRReduce;
	parser->lrTable[34][7].actionParam = 67;
	//reduce
	parser->lrTable[47][7].LRTableFuncP = LRReduce;
	parser->lrTable[47][7].actionParam = 67;
	//reduce
	parser->lrTable[48][7].LRTableFuncP = LRReduce;
	parser->lrTable[48][7].actionParam = 67;
	//reduce
	parser->lrTable[56][7].LRTableFuncP = LRReduce;
	parser->lrTable[56][7].actionParam = 67;
	//reduce
	parser->lrTable[57][7].LRTableFuncP = LRReduce;
	parser->lrTable[57][7].actionParam = 67;
	//reduce
	parser->lrTable[58][7].LRTableFuncP = LRReduce;
	parser->lrTable[58][7].actionParam = 67;
	//reduce
	parser->lrTable[59][7].LRTableFuncP = LRReduce;
	parser->lrTable[59][7].actionParam = 67;
	//shift
	parser->lrTable[27][7].LRTableFuncP = LRShift;
	parser->lrTable[27][7].actionParam = 71;
	//shift
	parser->lrTable[28][7].LRTableFuncP = LRShift;
	parser->lrTable[28][7].actionParam = 72;
	//reduce
	parser->lrTable[0][8].LRTableFuncP = LRReduce;
	parser->lrTable[0][8].actionParam = 70;
	//reduce
	parser->lrTable[1][8].LRTableFuncP = LRReduce;
	parser->lrTable[1][8].actionParam = 70;
	//reduce
	parser->lrTable[3][8].LRTableFuncP = LRReduce;
	parser->lrTable[3][8].actionParam = 70;
	//reduce
	parser->lrTable[4][8].LRTableFuncP = LRReduce;
	parser->lrTable[4][8].actionParam = 70;
	//reduce
	parser->lrTable[2][8].LRTableFuncP = LRReduce;
	parser->lrTable[2][8].actionParam = 70;
	//reduce
	parser->lrTable[19][8].LRTableFuncP = LRReduce;
	parser->lrTable[19][8].actionParam = 70;
	//reduce
	parser->lrTable[21][8].LRTableFuncP = LRReduce;
	parser->lrTable[21][8].actionParam = 70;
	//reduce
	parser->lrTable[23][8].LRTableFuncP = LRReduce;
	parser->lrTable[23][8].actionParam = 70;
	//reduce
	parser->lrTable[30][8].LRTableFuncP = LRReduce;
	parser->lrTable[30][8].actionParam = 70;
	//reduce
	parser->lrTable[34][8].LRTableFuncP = LRReduce;
	parser->lrTable[34][8].actionParam = 70;
	//reduce
	parser->lrTable[47][8].LRTableFuncP = LRReduce;
	parser->lrTable[47][8].actionParam = 70;
	//reduce
	parser->lrTable[48][8].LRTableFuncP = LRReduce;
	parser->lrTable[48][8].actionParam = 70;
	//reduce
	parser->lrTable[56][8].LRTableFuncP = LRReduce;
	parser->lrTable[56][8].actionParam = 70;
	//reduce
	parser->lrTable[57][8].LRTableFuncP = LRReduce;
	parser->lrTable[57][8].actionParam = 70;
	//reduce
	parser->lrTable[58][8].LRTableFuncP = LRReduce;
	parser->lrTable[58][8].actionParam = 70;
	//reduce
	parser->lrTable[59][8].LRTableFuncP = LRReduce;
	parser->lrTable[59][8].actionParam = 70;
	//shift
	parser->lrTable[7][8].LRTableFuncP = LRShift;
	parser->lrTable[7][8].actionParam = 73;
	//shift
	parser->lrTable[10][8].LRTableFuncP = LRShift;
	parser->lrTable[10][8].actionParam = 74;
	//reduce
	parser->lrTable[0][9].LRTableFuncP = LRReduce;
	parser->lrTable[0][9].actionParam = 75;
	//reduce
	parser->lrTable[1][9].LRTableFuncP = LRReduce;
	parser->lrTable[1][9].actionParam = 75;
	//reduce
	parser->lrTable[3][9].LRTableFuncP = LRReduce;
	parser->lrTable[3][9].actionParam = 75;
	//reduce
	parser->lrTable[4][9].LRTableFuncP = LRReduce;
	parser->lrTable[4][9].actionParam = 75;
	//reduce
	parser->lrTable[2][9].LRTableFuncP = LRReduce;
	parser->lrTable[2][9].actionParam = 75;
	//reduce
	parser->lrTable[19][9].LRTableFuncP = LRReduce;
	parser->lrTable[19][9].actionParam = 75;
	//reduce
	parser->lrTable[21][9].LRTableFuncP = LRReduce;
	parser->lrTable[21][9].actionParam = 75;
	//reduce
	parser->lrTable[23][9].LRTableFuncP = LRReduce;
	parser->lrTable[23][9].actionParam = 75;
	//reduce
	parser->lrTable[27][9].LRTableFuncP = LRReduce;
	parser->lrTable[27][9].actionParam = 75;
	//reduce
	parser->lrTable[28][9].LRTableFuncP = LRReduce;
	parser->lrTable[28][9].actionParam = 75;
	//reduce
	parser->lrTable[30][9].LRTableFuncP = LRReduce;
	parser->lrTable[30][9].actionParam = 75;
	//reduce
	parser->lrTable[34][9].LRTableFuncP = LRReduce;
	parser->lrTable[34][9].actionParam = 75;
	//reduce
	parser->lrTable[47][9].LRTableFuncP = LRReduce;
	parser->lrTable[47][9].actionParam = 75;
	//reduce
	parser->lrTable[48][9].LRTableFuncP = LRReduce;
	parser->lrTable[48][9].actionParam = 75;
	//reduce
	parser->lrTable[56][9].LRTableFuncP = LRReduce;
	parser->lrTable[56][9].actionParam = 75;
	//reduce
	parser->lrTable[57][9].LRTableFuncP = LRReduce;
	parser->lrTable[57][9].actionParam = 75;
	//reduce
	parser->lrTable[58][9].LRTableFuncP = LRReduce;
	parser->lrTable[58][9].actionParam = 75;
	//reduce
	parser->lrTable[59][9].LRTableFuncP = LRReduce;
	parser->lrTable[59][9].actionParam = 75;
	//shift
	parser->lrTable[13][9].LRTableFuncP = LRShift;
	parser->lrTable[13][9].actionParam = 75;
	//shift
	parser->lrTable[15][9].LRTableFuncP = LRShift;
	parser->lrTable[15][9].actionParam = 76;
	//shift
	parser->lrTable[17][9].LRTableFuncP = LRShift;
	parser->lrTable[17][9].actionParam = 77;
	//reduce
	parser->lrTable[0][10].LRTableFuncP = LRReduce;
	parser->lrTable[0][10].actionParam = 78;
	//reduce
	parser->lrTable[1][10].LRTableFuncP = LRReduce;
	parser->lrTable[1][10].actionParam = 78;
	//reduce
	parser->lrTable[3][10].LRTableFuncP = LRReduce;
	parser->lrTable[3][10].actionParam = 78;
	//reduce
	parser->lrTable[4][10].LRTableFuncP = LRReduce;
	parser->lrTable[4][10].actionParam = 78;
	//reduce
	parser->lrTable[2][10].LRTableFuncP = LRReduce;
	parser->lrTable[2][10].actionParam = 78;
	//reduce
	parser->lrTable[7][10].LRTableFuncP = LRReduce;
	parser->lrTable[7][10].actionParam = 78;
	//reduce
	parser->lrTable[10][10].LRTableFuncP = LRReduce;
	parser->lrTable[10][10].actionParam = 78;
	//reduce
	parser->lrTable[19][10].LRTableFuncP = LRReduce;
	parser->lrTable[19][10].actionParam = 78;
	//reduce
	parser->lrTable[21][10].LRTableFuncP = LRReduce;
	parser->lrTable[21][10].actionParam = 78;
	//reduce
	parser->lrTable[23][10].LRTableFuncP = LRReduce;
	parser->lrTable[23][10].actionParam = 78;
	//reduce
	parser->lrTable[27][10].LRTableFuncP = LRReduce;
	parser->lrTable[27][10].actionParam = 78;
	//reduce
	parser->lrTable[28][10].LRTableFuncP = LRReduce;
	parser->lrTable[28][10].actionParam = 78;
	//reduce
	parser->lrTable[30][10].LRTableFuncP = LRReduce;
	parser->lrTable[30][10].actionParam = 78;
	//reduce
	parser->lrTable[34][10].LRTableFuncP = LRReduce;
	parser->lrTable[34][10].actionParam = 78;
	//reduce
	parser->lrTable[47][10].LRTableFuncP = LRReduce;
	parser->lrTable[47][10].actionParam = 78;
	//reduce
	parser->lrTable[48][10].LRTableFuncP = LRReduce;
	parser->lrTable[48][10].actionParam = 78;
	//reduce
	parser->lrTable[56][10].LRTableFuncP = LRReduce;
	parser->lrTable[56][10].actionParam = 78;
	//reduce
	parser->lrTable[57][10].LRTableFuncP = LRReduce;
	parser->lrTable[57][10].actionParam = 78;
	//reduce
	parser->lrTable[58][10].LRTableFuncP = LRReduce;
	parser->lrTable[58][10].actionParam = 78;
	//reduce
	parser->lrTable[59][10].LRTableFuncP = LRReduce;
	parser->lrTable[59][10].actionParam = 78;
	//shift
	parser->lrTable[2][10].LRTableFuncP = LRShift;
	parser->lrTable[2][10].actionParam = 78;
	//shift
	parser->lrTable[7][10].LRTableFuncP = LRShift;
	parser->lrTable[7][10].actionParam = 79;
	//shift
	parser->lrTable[10][10].LRTableFuncP = LRShift;
	parser->lrTable[10][10].actionParam = 80;
	//shift
	parser->lrTable[13][10].LRTableFuncP = LRShift;
	parser->lrTable[13][10].actionParam = 81;
	//shift
	parser->lrTable[15][10].LRTableFuncP = LRShift;
	parser->lrTable[15][10].actionParam = 82;
	//shift
	parser->lrTable[17][10].LRTableFuncP = LRShift;
	parser->lrTable[17][10].actionParam = 83;
	//shift
	parser->lrTable[20][10].LRTableFuncP = LRShift;
	parser->lrTable[20][10].actionParam = 84;
	//shift
	parser->lrTable[21][10].LRTableFuncP = LRShift;
	parser->lrTable[21][10].actionParam = 85;
	//shift
	parser->lrTable[23][10].LRTableFuncP = LRShift;
	parser->lrTable[23][10].actionParam = 86;
	//reduce
	parser->lrTable[0][11].LRTableFuncP = LRReduce;
	parser->lrTable[0][11].actionParam = 81;
	//reduce
	parser->lrTable[1][11].LRTableFuncP = LRReduce;
	parser->lrTable[1][11].actionParam = 81;
	//reduce
	parser->lrTable[3][11].LRTableFuncP = LRReduce;
	parser->lrTable[3][11].actionParam = 81;
	//reduce
	parser->lrTable[4][11].LRTableFuncP = LRReduce;
	parser->lrTable[4][11].actionParam = 81;
	//reduce
	parser->lrTable[2][11].LRTableFuncP = LRReduce;
	parser->lrTable[2][11].actionParam = 81;
	//reduce
	parser->lrTable[7][11].LRTableFuncP = LRReduce;
	parser->lrTable[7][11].actionParam = 81;
	//reduce
	parser->lrTable[10][11].LRTableFuncP = LRReduce;
	parser->lrTable[10][11].actionParam = 81;
	//reduce
	parser->lrTable[13][11].LRTableFuncP = LRReduce;
	parser->lrTable[13][11].actionParam = 81;
	//reduce
	parser->lrTable[15][11].LRTableFuncP = LRReduce;
	parser->lrTable[15][11].actionParam = 81;
	//reduce
	parser->lrTable[17][11].LRTableFuncP = LRReduce;
	parser->lrTable[17][11].actionParam = 81;
	//reduce
	parser->lrTable[19][11].LRTableFuncP = LRReduce;
	parser->lrTable[19][11].actionParam = 81;
	//reduce
	parser->lrTable[21][11].LRTableFuncP = LRReduce;
	parser->lrTable[21][11].actionParam = 81;
	//reduce
	parser->lrTable[23][11].LRTableFuncP = LRReduce;
	parser->lrTable[23][11].actionParam = 81;
	//reduce
	parser->lrTable[27][11].LRTableFuncP = LRReduce;
	parser->lrTable[27][11].actionParam = 81;
	//reduce
	parser->lrTable[28][11].LRTableFuncP = LRReduce;
	parser->lrTable[28][11].actionParam = 81;
	//reduce
	parser->lrTable[30][11].LRTableFuncP = LRReduce;
	parser->lrTable[30][11].actionParam = 81;
	//reduce
	parser->lrTable[34][11].LRTableFuncP = LRReduce;
	parser->lrTable[34][11].actionParam = 81;
	//reduce
	parser->lrTable[47][11].LRTableFuncP = LRReduce;
	parser->lrTable[47][11].actionParam = 81;
	//reduce
	parser->lrTable[48][11].LRTableFuncP = LRReduce;
	parser->lrTable[48][11].actionParam = 81;
	//reduce
	parser->lrTable[56][11].LRTableFuncP = LRReduce;
	parser->lrTable[56][11].actionParam = 81;
	//reduce
	parser->lrTable[57][11].LRTableFuncP = LRReduce;
	parser->lrTable[57][11].actionParam = 81;
	//reduce
	parser->lrTable[58][11].LRTableFuncP = LRReduce;
	parser->lrTable[58][11].actionParam = 81;
	//reduce
	parser->lrTable[59][11].LRTableFuncP = LRReduce;
	parser->lrTable[59][11].actionParam = 81;
	//goto
	parser->lrTable[assignment_operator+TOTAL_TOKENS][11].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_operator+TOTAL_TOKENS][11].actionParam = 87;
	//shift
	parser->lrTable[4][11].LRTableFuncP = LRShift;
	parser->lrTable[4][11].actionParam = 19;
	//shift
	parser->lrTable[7][11].LRTableFuncP = LRShift;
	parser->lrTable[7][11].actionParam = 20;
	//shift
	parser->lrTable[8][11].LRTableFuncP = LRShift;
	parser->lrTable[8][11].actionParam = 21;
	//shift
	parser->lrTable[10][11].LRTableFuncP = LRShift;
	parser->lrTable[10][11].actionParam = 22;
	//shift
	parser->lrTable[11][11].LRTableFuncP = LRShift;
	parser->lrTable[11][11].actionParam = 23;
	//shift
	parser->lrTable[25][11].LRTableFuncP = LRShift;
	parser->lrTable[25][11].actionParam = 24;
	//shift
	parser->lrTable[29][11].LRTableFuncP = LRShift;
	parser->lrTable[29][11].actionParam = 25;
	//shift
	parser->lrTable[35][11].LRTableFuncP = LRShift;
	parser->lrTable[35][11].actionParam = 26;
	//shift
	parser->lrTable[36][11].LRTableFuncP = LRShift;
	parser->lrTable[36][11].actionParam = 27;
	//shift
	parser->lrTable[37][11].LRTableFuncP = LRShift;
	parser->lrTable[37][11].actionParam = 28;
	//shift
	parser->lrTable[38][11].LRTableFuncP = LRShift;
	parser->lrTable[38][11].actionParam = 29;
	//shift
	parser->lrTable[39][11].LRTableFuncP = LRShift;
	parser->lrTable[39][11].actionParam = 30;
	//shift
	parser->lrTable[51][11].LRTableFuncP = LRShift;
	parser->lrTable[51][11].actionParam = 31;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][11].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][11].actionParam = 88;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][11].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][11].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][11].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][11].actionParam = 47;
	//shift
	parser->lrTable[8][11].LRTableFuncP = LRShift;
	parser->lrTable[8][11].actionParam = 89;
	//shift
	parser->lrTable[11][11].LRTableFuncP = LRShift;
	parser->lrTable[11][11].actionParam = 90;
	//shift
	parser->lrTable[29][11].LRTableFuncP = LRShift;
	parser->lrTable[29][11].actionParam = 91;
	//shift
	parser->lrTable[33][11].LRTableFuncP = LRShift;
	parser->lrTable[33][11].actionParam = 92;
	//reduce
	parser->lrTable[0][12].LRTableFuncP = LRReduce;
	parser->lrTable[0][12].actionParam = 85;
	//reduce
	parser->lrTable[1][12].LRTableFuncP = LRReduce;
	parser->lrTable[1][12].actionParam = 85;
	//reduce
	parser->lrTable[2][12].LRTableFuncP = LRReduce;
	parser->lrTable[2][12].actionParam = 85;
	//reduce
	parser->lrTable[3][12].LRTableFuncP = LRReduce;
	parser->lrTable[3][12].actionParam = 85;
	//reduce
	parser->lrTable[4][12].LRTableFuncP = LRReduce;
	parser->lrTable[4][12].actionParam = 85;
	//reduce
	parser->lrTable[2][12].LRTableFuncP = LRReduce;
	parser->lrTable[2][12].actionParam = 85;
	//reduce
	parser->lrTable[7][12].LRTableFuncP = LRReduce;
	parser->lrTable[7][12].actionParam = 85;
	//reduce
	parser->lrTable[7][12].LRTableFuncP = LRReduce;
	parser->lrTable[7][12].actionParam = 85;
	//reduce
	parser->lrTable[10][12].LRTableFuncP = LRReduce;
	parser->lrTable[10][12].actionParam = 85;
	//reduce
	parser->lrTable[10][12].LRTableFuncP = LRReduce;
	parser->lrTable[10][12].actionParam = 85;
	//reduce
	parser->lrTable[13][12].LRTableFuncP = LRReduce;
	parser->lrTable[13][12].actionParam = 85;
	//reduce
	parser->lrTable[13][12].LRTableFuncP = LRReduce;
	parser->lrTable[13][12].actionParam = 85;
	//reduce
	parser->lrTable[15][12].LRTableFuncP = LRReduce;
	parser->lrTable[15][12].actionParam = 85;
	//reduce
	parser->lrTable[15][12].LRTableFuncP = LRReduce;
	parser->lrTable[15][12].actionParam = 85;
	//reduce
	parser->lrTable[17][12].LRTableFuncP = LRReduce;
	parser->lrTable[17][12].actionParam = 85;
	//reduce
	parser->lrTable[17][12].LRTableFuncP = LRReduce;
	parser->lrTable[17][12].actionParam = 85;
	//reduce
	parser->lrTable[19][12].LRTableFuncP = LRReduce;
	parser->lrTable[19][12].actionParam = 85;
	//reduce
	parser->lrTable[20][12].LRTableFuncP = LRReduce;
	parser->lrTable[20][12].actionParam = 85;
	//reduce
	parser->lrTable[21][12].LRTableFuncP = LRReduce;
	parser->lrTable[21][12].actionParam = 85;
	//reduce
	parser->lrTable[21][12].LRTableFuncP = LRReduce;
	parser->lrTable[21][12].actionParam = 85;
	//reduce
	parser->lrTable[23][12].LRTableFuncP = LRReduce;
	parser->lrTable[23][12].actionParam = 85;
	//reduce
	parser->lrTable[23][12].LRTableFuncP = LRReduce;
	parser->lrTable[23][12].actionParam = 85;
	//reduce
	parser->lrTable[27][12].LRTableFuncP = LRReduce;
	parser->lrTable[27][12].actionParam = 85;
	//reduce
	parser->lrTable[28][12].LRTableFuncP = LRReduce;
	parser->lrTable[28][12].actionParam = 85;
	//reduce
	parser->lrTable[30][12].LRTableFuncP = LRReduce;
	parser->lrTable[30][12].actionParam = 85;
	//reduce
	parser->lrTable[34][12].LRTableFuncP = LRReduce;
	parser->lrTable[34][12].actionParam = 85;
	//reduce
	parser->lrTable[47][12].LRTableFuncP = LRReduce;
	parser->lrTable[47][12].actionParam = 85;
	//reduce
	parser->lrTable[48][12].LRTableFuncP = LRReduce;
	parser->lrTable[48][12].actionParam = 85;
	//reduce
	parser->lrTable[56][12].LRTableFuncP = LRReduce;
	parser->lrTable[56][12].actionParam = 85;
	//reduce
	parser->lrTable[57][12].LRTableFuncP = LRReduce;
	parser->lrTable[57][12].actionParam = 85;
	//reduce
	parser->lrTable[58][12].LRTableFuncP = LRReduce;
	parser->lrTable[58][12].actionParam = 85;
	//reduce
	parser->lrTable[59][12].LRTableFuncP = LRReduce;
	parser->lrTable[59][12].actionParam = 85;
	//reduce
	parser->lrTable[0][13].LRTableFuncP = LRReduce;
	parser->lrTable[0][13].actionParam = 93;
	//reduce
	parser->lrTable[1][13].LRTableFuncP = LRReduce;
	parser->lrTable[1][13].actionParam = 93;
	//reduce
	parser->lrTable[2][13].LRTableFuncP = LRReduce;
	parser->lrTable[2][13].actionParam = 93;
	//reduce
	parser->lrTable[3][13].LRTableFuncP = LRReduce;
	parser->lrTable[3][13].actionParam = 93;
	//reduce
	parser->lrTable[4][13].LRTableFuncP = LRReduce;
	parser->lrTable[4][13].actionParam = 93;
	//reduce
	parser->lrTable[2][13].LRTableFuncP = LRReduce;
	parser->lrTable[2][13].actionParam = 93;
	//reduce
	parser->lrTable[7][13].LRTableFuncP = LRReduce;
	parser->lrTable[7][13].actionParam = 93;
	//reduce
	parser->lrTable[8][13].LRTableFuncP = LRReduce;
	parser->lrTable[8][13].actionParam = 93;
	//reduce
	parser->lrTable[7][13].LRTableFuncP = LRReduce;
	parser->lrTable[7][13].actionParam = 93;
	//reduce
	parser->lrTable[10][13].LRTableFuncP = LRReduce;
	parser->lrTable[10][13].actionParam = 93;
	//reduce
	parser->lrTable[11][13].LRTableFuncP = LRReduce;
	parser->lrTable[11][13].actionParam = 93;
	//reduce
	parser->lrTable[10][13].LRTableFuncP = LRReduce;
	parser->lrTable[10][13].actionParam = 93;
	//reduce
	parser->lrTable[13][13].LRTableFuncP = LRReduce;
	parser->lrTable[13][13].actionParam = 93;
	//reduce
	parser->lrTable[13][13].LRTableFuncP = LRReduce;
	parser->lrTable[13][13].actionParam = 93;
	//reduce
	parser->lrTable[15][13].LRTableFuncP = LRReduce;
	parser->lrTable[15][13].actionParam = 93;
	//reduce
	parser->lrTable[15][13].LRTableFuncP = LRReduce;
	parser->lrTable[15][13].actionParam = 93;
	//reduce
	parser->lrTable[17][13].LRTableFuncP = LRReduce;
	parser->lrTable[17][13].actionParam = 93;
	//reduce
	parser->lrTable[17][13].LRTableFuncP = LRReduce;
	parser->lrTable[17][13].actionParam = 93;
	//reduce
	parser->lrTable[19][13].LRTableFuncP = LRReduce;
	parser->lrTable[19][13].actionParam = 93;
	//reduce
	parser->lrTable[20][13].LRTableFuncP = LRReduce;
	parser->lrTable[20][13].actionParam = 93;
	//reduce
	parser->lrTable[21][13].LRTableFuncP = LRReduce;
	parser->lrTable[21][13].actionParam = 93;
	//reduce
	parser->lrTable[21][13].LRTableFuncP = LRReduce;
	parser->lrTable[21][13].actionParam = 93;
	//reduce
	parser->lrTable[23][13].LRTableFuncP = LRReduce;
	parser->lrTable[23][13].actionParam = 93;
	//reduce
	parser->lrTable[23][13].LRTableFuncP = LRReduce;
	parser->lrTable[23][13].actionParam = 93;
	//reduce
	parser->lrTable[27][13].LRTableFuncP = LRReduce;
	parser->lrTable[27][13].actionParam = 93;
	//reduce
	parser->lrTable[28][13].LRTableFuncP = LRReduce;
	parser->lrTable[28][13].actionParam = 93;
	//reduce
	parser->lrTable[29][13].LRTableFuncP = LRReduce;
	parser->lrTable[29][13].actionParam = 93;
	//reduce
	parser->lrTable[30][13].LRTableFuncP = LRReduce;
	parser->lrTable[30][13].actionParam = 93;
	//reduce
	parser->lrTable[33][13].LRTableFuncP = LRReduce;
	parser->lrTable[33][13].actionParam = 93;
	//reduce
	parser->lrTable[34][13].LRTableFuncP = LRReduce;
	parser->lrTable[34][13].actionParam = 93;
	//reduce
	parser->lrTable[47][13].LRTableFuncP = LRReduce;
	parser->lrTable[47][13].actionParam = 93;
	//reduce
	parser->lrTable[48][13].LRTableFuncP = LRReduce;
	parser->lrTable[48][13].actionParam = 93;
	//reduce
	parser->lrTable[56][13].LRTableFuncP = LRReduce;
	parser->lrTable[56][13].actionParam = 93;
	//reduce
	parser->lrTable[57][13].LRTableFuncP = LRReduce;
	parser->lrTable[57][13].actionParam = 93;
	//reduce
	parser->lrTable[58][13].LRTableFuncP = LRReduce;
	parser->lrTable[58][13].actionParam = 93;
	//reduce
	parser->lrTable[59][13].LRTableFuncP = LRReduce;
	parser->lrTable[59][13].actionParam = 93;
	//shift
	parser->lrTable[51][13].LRTableFuncP = LRShift;
	parser->lrTable[51][13].actionParam = 93;
	//shift
	parser->lrTable[30][13].LRTableFuncP = LRShift;
	parser->lrTable[30][13].actionParam = 94;
	//shift
	parser->lrTable[57][13].LRTableFuncP = LRShift;
	parser->lrTable[57][13].actionParam = 95;
	//reduce
	parser->lrTable[30][13].LRTableFuncP = LRReduce;
	parser->lrTable[30][13].actionParam = 17;
	//reduce
	parser->lrTable[30][13].LRTableFuncP = LRReduce;
	parser->lrTable[30][13].actionParam = 18;
	//reduce
	parser->lrTable[57][13].LRTableFuncP = LRReduce;
	parser->lrTable[57][13].actionParam = 18;
	//shift
	parser->lrTable[2][13].LRTableFuncP = LRShift;
	parser->lrTable[2][13].actionParam = 15;
	//reduce
	parser->lrTable[56][13].LRTableFuncP = LRReduce;
	parser->lrTable[56][13].actionParam = 9;
	//reduce
	parser->lrTable[57][13].LRTableFuncP = LRReduce;
	parser->lrTable[57][13].actionParam = 9;
	//reduce
	parser->lrTable[56][13].LRTableFuncP = LRReduce;
	parser->lrTable[56][13].actionParam = 8;
	//reduce
	parser->lrTable[57][13].LRTableFuncP = LRReduce;
	parser->lrTable[57][13].actionParam = 8;
	//reduce
	parser->lrTable[0][14].LRTableFuncP = LRReduce;
	parser->lrTable[0][14].actionParam = 86;
	//reduce
	parser->lrTable[1][14].LRTableFuncP = LRReduce;
	parser->lrTable[1][14].actionParam = 86;
	//reduce
	parser->lrTable[2][14].LRTableFuncP = LRReduce;
	parser->lrTable[2][14].actionParam = 86;
	//reduce
	parser->lrTable[3][14].LRTableFuncP = LRReduce;
	parser->lrTable[3][14].actionParam = 86;
	//reduce
	parser->lrTable[4][14].LRTableFuncP = LRReduce;
	parser->lrTable[4][14].actionParam = 86;
	//reduce
	parser->lrTable[2][14].LRTableFuncP = LRReduce;
	parser->lrTable[2][14].actionParam = 86;
	//reduce
	parser->lrTable[7][14].LRTableFuncP = LRReduce;
	parser->lrTable[7][14].actionParam = 86;
	//reduce
	parser->lrTable[7][14].LRTableFuncP = LRReduce;
	parser->lrTable[7][14].actionParam = 86;
	//reduce
	parser->lrTable[10][14].LRTableFuncP = LRReduce;
	parser->lrTable[10][14].actionParam = 86;
	//reduce
	parser->lrTable[10][14].LRTableFuncP = LRReduce;
	parser->lrTable[10][14].actionParam = 86;
	//reduce
	parser->lrTable[13][14].LRTableFuncP = LRReduce;
	parser->lrTable[13][14].actionParam = 86;
	//reduce
	parser->lrTable[13][14].LRTableFuncP = LRReduce;
	parser->lrTable[13][14].actionParam = 86;
	//reduce
	parser->lrTable[15][14].LRTableFuncP = LRReduce;
	parser->lrTable[15][14].actionParam = 86;
	//reduce
	parser->lrTable[15][14].LRTableFuncP = LRReduce;
	parser->lrTable[15][14].actionParam = 86;
	//reduce
	parser->lrTable[17][14].LRTableFuncP = LRReduce;
	parser->lrTable[17][14].actionParam = 86;
	//reduce
	parser->lrTable[17][14].LRTableFuncP = LRReduce;
	parser->lrTable[17][14].actionParam = 86;
	//reduce
	parser->lrTable[19][14].LRTableFuncP = LRReduce;
	parser->lrTable[19][14].actionParam = 86;
	//reduce
	parser->lrTable[20][14].LRTableFuncP = LRReduce;
	parser->lrTable[20][14].actionParam = 86;
	//reduce
	parser->lrTable[21][14].LRTableFuncP = LRReduce;
	parser->lrTable[21][14].actionParam = 86;
	//reduce
	parser->lrTable[21][14].LRTableFuncP = LRReduce;
	parser->lrTable[21][14].actionParam = 86;
	//reduce
	parser->lrTable[23][14].LRTableFuncP = LRReduce;
	parser->lrTable[23][14].actionParam = 86;
	//reduce
	parser->lrTable[23][14].LRTableFuncP = LRReduce;
	parser->lrTable[23][14].actionParam = 86;
	//reduce
	parser->lrTable[27][14].LRTableFuncP = LRReduce;
	parser->lrTable[27][14].actionParam = 86;
	//reduce
	parser->lrTable[28][14].LRTableFuncP = LRReduce;
	parser->lrTable[28][14].actionParam = 86;
	//reduce
	parser->lrTable[30][14].LRTableFuncP = LRReduce;
	parser->lrTable[30][14].actionParam = 86;
	//reduce
	parser->lrTable[34][14].LRTableFuncP = LRReduce;
	parser->lrTable[34][14].actionParam = 86;
	//reduce
	parser->lrTable[47][14].LRTableFuncP = LRReduce;
	parser->lrTable[47][14].actionParam = 86;
	//reduce
	parser->lrTable[48][14].LRTableFuncP = LRReduce;
	parser->lrTable[48][14].actionParam = 86;
	//reduce
	parser->lrTable[56][14].LRTableFuncP = LRReduce;
	parser->lrTable[56][14].actionParam = 86;
	//reduce
	parser->lrTable[57][14].LRTableFuncP = LRReduce;
	parser->lrTable[57][14].actionParam = 86;
	//reduce
	parser->lrTable[58][14].LRTableFuncP = LRReduce;
	parser->lrTable[58][14].actionParam = 86;
	//reduce
	parser->lrTable[59][14].LRTableFuncP = LRReduce;
	parser->lrTable[59][14].actionParam = 86;
	//reduce
	parser->lrTable[0][15].LRTableFuncP = LRReduce;
	parser->lrTable[0][15].actionParam = 87;
	//reduce
	parser->lrTable[1][15].LRTableFuncP = LRReduce;
	parser->lrTable[1][15].actionParam = 87;
	//reduce
	parser->lrTable[2][15].LRTableFuncP = LRReduce;
	parser->lrTable[2][15].actionParam = 87;
	//reduce
	parser->lrTable[3][15].LRTableFuncP = LRReduce;
	parser->lrTable[3][15].actionParam = 87;
	//reduce
	parser->lrTable[4][15].LRTableFuncP = LRReduce;
	parser->lrTable[4][15].actionParam = 87;
	//reduce
	parser->lrTable[2][15].LRTableFuncP = LRReduce;
	parser->lrTable[2][15].actionParam = 87;
	//reduce
	parser->lrTable[7][15].LRTableFuncP = LRReduce;
	parser->lrTable[7][15].actionParam = 87;
	//reduce
	parser->lrTable[7][15].LRTableFuncP = LRReduce;
	parser->lrTable[7][15].actionParam = 87;
	//reduce
	parser->lrTable[10][15].LRTableFuncP = LRReduce;
	parser->lrTable[10][15].actionParam = 87;
	//reduce
	parser->lrTable[10][15].LRTableFuncP = LRReduce;
	parser->lrTable[10][15].actionParam = 87;
	//reduce
	parser->lrTable[13][15].LRTableFuncP = LRReduce;
	parser->lrTable[13][15].actionParam = 87;
	//reduce
	parser->lrTable[13][15].LRTableFuncP = LRReduce;
	parser->lrTable[13][15].actionParam = 87;
	//reduce
	parser->lrTable[15][15].LRTableFuncP = LRReduce;
	parser->lrTable[15][15].actionParam = 87;
	//reduce
	parser->lrTable[15][15].LRTableFuncP = LRReduce;
	parser->lrTable[15][15].actionParam = 87;
	//reduce
	parser->lrTable[17][15].LRTableFuncP = LRReduce;
	parser->lrTable[17][15].actionParam = 87;
	//reduce
	parser->lrTable[17][15].LRTableFuncP = LRReduce;
	parser->lrTable[17][15].actionParam = 87;
	//reduce
	parser->lrTable[19][15].LRTableFuncP = LRReduce;
	parser->lrTable[19][15].actionParam = 87;
	//reduce
	parser->lrTable[20][15].LRTableFuncP = LRReduce;
	parser->lrTable[20][15].actionParam = 87;
	//reduce
	parser->lrTable[21][15].LRTableFuncP = LRReduce;
	parser->lrTable[21][15].actionParam = 87;
	//reduce
	parser->lrTable[21][15].LRTableFuncP = LRReduce;
	parser->lrTable[21][15].actionParam = 87;
	//reduce
	parser->lrTable[23][15].LRTableFuncP = LRReduce;
	parser->lrTable[23][15].actionParam = 87;
	//reduce
	parser->lrTable[23][15].LRTableFuncP = LRReduce;
	parser->lrTable[23][15].actionParam = 87;
	//reduce
	parser->lrTable[27][15].LRTableFuncP = LRReduce;
	parser->lrTable[27][15].actionParam = 87;
	//reduce
	parser->lrTable[28][15].LRTableFuncP = LRReduce;
	parser->lrTable[28][15].actionParam = 87;
	//reduce
	parser->lrTable[30][15].LRTableFuncP = LRReduce;
	parser->lrTable[30][15].actionParam = 87;
	//reduce
	parser->lrTable[34][15].LRTableFuncP = LRReduce;
	parser->lrTable[34][15].actionParam = 87;
	//reduce
	parser->lrTable[47][15].LRTableFuncP = LRReduce;
	parser->lrTable[47][15].actionParam = 87;
	//reduce
	parser->lrTable[48][15].LRTableFuncP = LRReduce;
	parser->lrTable[48][15].actionParam = 87;
	//reduce
	parser->lrTable[56][15].LRTableFuncP = LRReduce;
	parser->lrTable[56][15].actionParam = 87;
	//reduce
	parser->lrTable[57][15].LRTableFuncP = LRReduce;
	parser->lrTable[57][15].actionParam = 87;
	//reduce
	parser->lrTable[58][15].LRTableFuncP = LRReduce;
	parser->lrTable[58][15].actionParam = 87;
	//reduce
	parser->lrTable[59][15].LRTableFuncP = LRReduce;
	parser->lrTable[59][15].actionParam = 87;
	//shift
	parser->lrTable[30][15].LRTableFuncP = LRShift;
	parser->lrTable[30][15].actionParam = 96;
	//shift
	parser->lrTable[57][15].LRTableFuncP = LRShift;
	parser->lrTable[57][15].actionParam = 58;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][15].actionParam = 97;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][15].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][15].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][15].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][15].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][15].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][15].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][15].actionParam = 98;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][15].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][15].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][15].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[expression+TOTAL_TOKENS][15].actionParam = 100;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][15].actionParam = 33;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][15].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][15].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][15].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][15].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][15].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][15].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][15].actionParam = 101;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][15].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][15].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][15].actionParam = 102;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][15].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][15].actionParam = 103;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].actionParam = 104;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].actionParam = 105;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].actionParam = 106;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 111;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 112;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 113;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 114;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 115;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 116;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 117;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//reduce
	parser->lrTable[4][15].LRTableFuncP = LRReduce;
	parser->lrTable[4][15].actionParam = 46;
	//reduce
	parser->lrTable[7][15].LRTableFuncP = LRReduce;
	parser->lrTable[7][15].actionParam = 46;
	//reduce
	parser->lrTable[8][15].LRTableFuncP = LRReduce;
	parser->lrTable[8][15].actionParam = 46;
	//reduce
	parser->lrTable[10][15].LRTableFuncP = LRReduce;
	parser->lrTable[10][15].actionParam = 46;
	//reduce
	parser->lrTable[11][15].LRTableFuncP = LRReduce;
	parser->lrTable[11][15].actionParam = 46;
	//reduce
	parser->lrTable[25][15].LRTableFuncP = LRReduce;
	parser->lrTable[25][15].actionParam = 46;
	//reduce
	parser->lrTable[29][15].LRTableFuncP = LRReduce;
	parser->lrTable[29][15].actionParam = 46;
	//reduce
	parser->lrTable[35][15].LRTableFuncP = LRReduce;
	parser->lrTable[35][15].actionParam = 46;
	//reduce
	parser->lrTable[36][15].LRTableFuncP = LRReduce;
	parser->lrTable[36][15].actionParam = 46;
	//reduce
	parser->lrTable[37][15].LRTableFuncP = LRReduce;
	parser->lrTable[37][15].actionParam = 46;
	//reduce
	parser->lrTable[38][15].LRTableFuncP = LRReduce;
	parser->lrTable[38][15].actionParam = 46;
	//reduce
	parser->lrTable[39][15].LRTableFuncP = LRReduce;
	parser->lrTable[39][15].actionParam = 46;
	//reduce
	parser->lrTable[51][15].LRTableFuncP = LRReduce;
	parser->lrTable[51][15].actionParam = 46;
	//reduce
	parser->lrTable[4][15].LRTableFuncP = LRReduce;
	parser->lrTable[4][15].actionParam = 47;
	//reduce
	parser->lrTable[7][15].LRTableFuncP = LRReduce;
	parser->lrTable[7][15].actionParam = 47;
	//reduce
	parser->lrTable[8][15].LRTableFuncP = LRReduce;
	parser->lrTable[8][15].actionParam = 47;
	//reduce
	parser->lrTable[10][15].LRTableFuncP = LRReduce;
	parser->lrTable[10][15].actionParam = 47;
	//reduce
	parser->lrTable[11][15].LRTableFuncP = LRReduce;
	parser->lrTable[11][15].actionParam = 47;
	//reduce
	parser->lrTable[25][15].LRTableFuncP = LRReduce;
	parser->lrTable[25][15].actionParam = 47;
	//reduce
	parser->lrTable[29][15].LRTableFuncP = LRReduce;
	parser->lrTable[29][15].actionParam = 47;
	//reduce
	parser->lrTable[35][15].LRTableFuncP = LRReduce;
	parser->lrTable[35][15].actionParam = 47;
	//reduce
	parser->lrTable[36][15].LRTableFuncP = LRReduce;
	parser->lrTable[36][15].actionParam = 47;
	//reduce
	parser->lrTable[37][15].LRTableFuncP = LRReduce;
	parser->lrTable[37][15].actionParam = 47;
	//reduce
	parser->lrTable[38][15].LRTableFuncP = LRReduce;
	parser->lrTable[38][15].actionParam = 47;
	//reduce
	parser->lrTable[39][15].LRTableFuncP = LRReduce;
	parser->lrTable[39][15].actionParam = 47;
	//reduce
	parser->lrTable[51][15].LRTableFuncP = LRReduce;
	parser->lrTable[51][15].actionParam = 47;
	//reduce
	parser->lrTable[4][15].LRTableFuncP = LRReduce;
	parser->lrTable[4][15].actionParam = 48;
	//reduce
	parser->lrTable[7][15].LRTableFuncP = LRReduce;
	parser->lrTable[7][15].actionParam = 48;
	//reduce
	parser->lrTable[8][15].LRTableFuncP = LRReduce;
	parser->lrTable[8][15].actionParam = 48;
	//reduce
	parser->lrTable[10][15].LRTableFuncP = LRReduce;
	parser->lrTable[10][15].actionParam = 48;
	//reduce
	parser->lrTable[11][15].LRTableFuncP = LRReduce;
	parser->lrTable[11][15].actionParam = 48;
	//reduce
	parser->lrTable[25][15].LRTableFuncP = LRReduce;
	parser->lrTable[25][15].actionParam = 48;
	//reduce
	parser->lrTable[29][15].LRTableFuncP = LRReduce;
	parser->lrTable[29][15].actionParam = 48;
	//reduce
	parser->lrTable[35][15].LRTableFuncP = LRReduce;
	parser->lrTable[35][15].actionParam = 48;
	//reduce
	parser->lrTable[36][15].LRTableFuncP = LRReduce;
	parser->lrTable[36][15].actionParam = 48;
	//reduce
	parser->lrTable[37][15].LRTableFuncP = LRReduce;
	parser->lrTable[37][15].actionParam = 48;
	//reduce
	parser->lrTable[38][15].LRTableFuncP = LRReduce;
	parser->lrTable[38][15].actionParam = 48;
	//reduce
	parser->lrTable[39][15].LRTableFuncP = LRReduce;
	parser->lrTable[39][15].actionParam = 48;
	//reduce
	parser->lrTable[51][15].LRTableFuncP = LRReduce;
	parser->lrTable[51][15].actionParam = 48;
	//reduce
	parser->lrTable[4][15].LRTableFuncP = LRReduce;
	parser->lrTable[4][15].actionParam = 50;
	//reduce
	parser->lrTable[7][15].LRTableFuncP = LRReduce;
	parser->lrTable[7][15].actionParam = 50;
	//reduce
	parser->lrTable[8][15].LRTableFuncP = LRReduce;
	parser->lrTable[8][15].actionParam = 50;
	//reduce
	parser->lrTable[10][15].LRTableFuncP = LRReduce;
	parser->lrTable[10][15].actionParam = 50;
	//reduce
	parser->lrTable[11][15].LRTableFuncP = LRReduce;
	parser->lrTable[11][15].actionParam = 50;
	//reduce
	parser->lrTable[25][15].LRTableFuncP = LRReduce;
	parser->lrTable[25][15].actionParam = 50;
	//reduce
	parser->lrTable[29][15].LRTableFuncP = LRReduce;
	parser->lrTable[29][15].actionParam = 50;
	//reduce
	parser->lrTable[35][15].LRTableFuncP = LRReduce;
	parser->lrTable[35][15].actionParam = 50;
	//reduce
	parser->lrTable[36][15].LRTableFuncP = LRReduce;
	parser->lrTable[36][15].actionParam = 50;
	//reduce
	parser->lrTable[37][15].LRTableFuncP = LRReduce;
	parser->lrTable[37][15].actionParam = 50;
	//reduce
	parser->lrTable[38][15].LRTableFuncP = LRReduce;
	parser->lrTable[38][15].actionParam = 50;
	//reduce
	parser->lrTable[39][15].LRTableFuncP = LRReduce;
	parser->lrTable[39][15].actionParam = 50;
	//reduce
	parser->lrTable[51][15].LRTableFuncP = LRReduce;
	parser->lrTable[51][15].actionParam = 50;
	//reduce
	parser->lrTable[4][15].LRTableFuncP = LRReduce;
	parser->lrTable[4][15].actionParam = 49;
	//reduce
	parser->lrTable[7][15].LRTableFuncP = LRReduce;
	parser->lrTable[7][15].actionParam = 49;
	//reduce
	parser->lrTable[8][15].LRTableFuncP = LRReduce;
	parser->lrTable[8][15].actionParam = 49;
	//reduce
	parser->lrTable[10][15].LRTableFuncP = LRReduce;
	parser->lrTable[10][15].actionParam = 49;
	//reduce
	parser->lrTable[11][15].LRTableFuncP = LRReduce;
	parser->lrTable[11][15].actionParam = 49;
	//reduce
	parser->lrTable[25][15].LRTableFuncP = LRReduce;
	parser->lrTable[25][15].actionParam = 49;
	//reduce
	parser->lrTable[29][15].LRTableFuncP = LRReduce;
	parser->lrTable[29][15].actionParam = 49;
	//reduce
	parser->lrTable[35][15].LRTableFuncP = LRReduce;
	parser->lrTable[35][15].actionParam = 49;
	//reduce
	parser->lrTable[36][15].LRTableFuncP = LRReduce;
	parser->lrTable[36][15].actionParam = 49;
	//reduce
	parser->lrTable[37][15].LRTableFuncP = LRReduce;
	parser->lrTable[37][15].actionParam = 49;
	//reduce
	parser->lrTable[38][15].LRTableFuncP = LRReduce;
	parser->lrTable[38][15].actionParam = 49;
	//reduce
	parser->lrTable[39][15].LRTableFuncP = LRReduce;
	parser->lrTable[39][15].actionParam = 49;
	//reduce
	parser->lrTable[51][15].LRTableFuncP = LRReduce;
	parser->lrTable[51][15].actionParam = 49;
	//reduce
	parser->lrTable[4][15].LRTableFuncP = LRReduce;
	parser->lrTable[4][15].actionParam = 51;
	//reduce
	parser->lrTable[7][15].LRTableFuncP = LRReduce;
	parser->lrTable[7][15].actionParam = 51;
	//reduce
	parser->lrTable[8][15].LRTableFuncP = LRReduce;
	parser->lrTable[8][15].actionParam = 51;
	//reduce
	parser->lrTable[10][15].LRTableFuncP = LRReduce;
	parser->lrTable[10][15].actionParam = 51;
	//reduce
	parser->lrTable[11][15].LRTableFuncP = LRReduce;
	parser->lrTable[11][15].actionParam = 51;
	//reduce
	parser->lrTable[25][15].LRTableFuncP = LRReduce;
	parser->lrTable[25][15].actionParam = 51;
	//reduce
	parser->lrTable[29][15].LRTableFuncP = LRReduce;
	parser->lrTable[29][15].actionParam = 51;
	//reduce
	parser->lrTable[35][15].LRTableFuncP = LRReduce;
	parser->lrTable[35][15].actionParam = 51;
	//reduce
	parser->lrTable[36][15].LRTableFuncP = LRReduce;
	parser->lrTable[36][15].actionParam = 51;
	//reduce
	parser->lrTable[37][15].LRTableFuncP = LRReduce;
	parser->lrTable[37][15].actionParam = 51;
	//reduce
	parser->lrTable[38][15].LRTableFuncP = LRReduce;
	parser->lrTable[38][15].actionParam = 51;
	//reduce
	parser->lrTable[39][15].LRTableFuncP = LRReduce;
	parser->lrTable[39][15].actionParam = 51;
	//reduce
	parser->lrTable[51][15].LRTableFuncP = LRReduce;
	parser->lrTable[51][15].actionParam = 51;
	//reduce
	parser->lrTable[4][15].LRTableFuncP = LRReduce;
	parser->lrTable[4][15].actionParam = 52;
	//reduce
	parser->lrTable[7][15].LRTableFuncP = LRReduce;
	parser->lrTable[7][15].actionParam = 52;
	//reduce
	parser->lrTable[8][15].LRTableFuncP = LRReduce;
	parser->lrTable[8][15].actionParam = 52;
	//reduce
	parser->lrTable[10][15].LRTableFuncP = LRReduce;
	parser->lrTable[10][15].actionParam = 52;
	//reduce
	parser->lrTable[11][15].LRTableFuncP = LRReduce;
	parser->lrTable[11][15].actionParam = 52;
	//reduce
	parser->lrTable[25][15].LRTableFuncP = LRReduce;
	parser->lrTable[25][15].actionParam = 52;
	//reduce
	parser->lrTable[29][15].LRTableFuncP = LRReduce;
	parser->lrTable[29][15].actionParam = 52;
	//reduce
	parser->lrTable[35][15].LRTableFuncP = LRReduce;
	parser->lrTable[35][15].actionParam = 52;
	//reduce
	parser->lrTable[36][15].LRTableFuncP = LRReduce;
	parser->lrTable[36][15].actionParam = 52;
	//reduce
	parser->lrTable[37][15].LRTableFuncP = LRReduce;
	parser->lrTable[37][15].actionParam = 52;
	//reduce
	parser->lrTable[38][15].LRTableFuncP = LRReduce;
	parser->lrTable[38][15].actionParam = 52;
	//reduce
	parser->lrTable[39][15].LRTableFuncP = LRReduce;
	parser->lrTable[39][15].actionParam = 52;
	//reduce
	parser->lrTable[51][15].LRTableFuncP = LRReduce;
	parser->lrTable[51][15].actionParam = 52;
	//reduce
	parser->lrTable[4][15].LRTableFuncP = LRReduce;
	parser->lrTable[4][15].actionParam = 53;
	//reduce
	parser->lrTable[7][15].LRTableFuncP = LRReduce;
	parser->lrTable[7][15].actionParam = 53;
	//reduce
	parser->lrTable[8][15].LRTableFuncP = LRReduce;
	parser->lrTable[8][15].actionParam = 53;
	//reduce
	parser->lrTable[10][15].LRTableFuncP = LRReduce;
	parser->lrTable[10][15].actionParam = 53;
	//reduce
	parser->lrTable[11][15].LRTableFuncP = LRReduce;
	parser->lrTable[11][15].actionParam = 53;
	//reduce
	parser->lrTable[25][15].LRTableFuncP = LRReduce;
	parser->lrTable[25][15].actionParam = 53;
	//reduce
	parser->lrTable[29][15].LRTableFuncP = LRReduce;
	parser->lrTable[29][15].actionParam = 53;
	//reduce
	parser->lrTable[35][15].LRTableFuncP = LRReduce;
	parser->lrTable[35][15].actionParam = 53;
	//reduce
	parser->lrTable[36][15].LRTableFuncP = LRReduce;
	parser->lrTable[36][15].actionParam = 53;
	//reduce
	parser->lrTable[37][15].LRTableFuncP = LRReduce;
	parser->lrTable[37][15].actionParam = 53;
	//reduce
	parser->lrTable[38][15].LRTableFuncP = LRReduce;
	parser->lrTable[38][15].actionParam = 53;
	//reduce
	parser->lrTable[39][15].LRTableFuncP = LRReduce;
	parser->lrTable[39][15].actionParam = 53;
	//reduce
	parser->lrTable[51][15].LRTableFuncP = LRReduce;
	parser->lrTable[51][15].actionParam = 53;
	//reduce
	parser->lrTable[4][15].LRTableFuncP = LRReduce;
	parser->lrTable[4][15].actionParam = 54;
	//reduce
	parser->lrTable[7][15].LRTableFuncP = LRReduce;
	parser->lrTable[7][15].actionParam = 54;
	//reduce
	parser->lrTable[8][15].LRTableFuncP = LRReduce;
	parser->lrTable[8][15].actionParam = 54;
	//reduce
	parser->lrTable[10][15].LRTableFuncP = LRReduce;
	parser->lrTable[10][15].actionParam = 54;
	//reduce
	parser->lrTable[11][15].LRTableFuncP = LRReduce;
	parser->lrTable[11][15].actionParam = 54;
	//reduce
	parser->lrTable[25][15].LRTableFuncP = LRReduce;
	parser->lrTable[25][15].actionParam = 54;
	//reduce
	parser->lrTable[29][15].LRTableFuncP = LRReduce;
	parser->lrTable[29][15].actionParam = 54;
	//reduce
	parser->lrTable[35][15].LRTableFuncP = LRReduce;
	parser->lrTable[35][15].actionParam = 54;
	//reduce
	parser->lrTable[36][15].LRTableFuncP = LRReduce;
	parser->lrTable[36][15].actionParam = 54;
	//reduce
	parser->lrTable[37][15].LRTableFuncP = LRReduce;
	parser->lrTable[37][15].actionParam = 54;
	//reduce
	parser->lrTable[38][15].LRTableFuncP = LRReduce;
	parser->lrTable[38][15].actionParam = 54;
	//reduce
	parser->lrTable[39][15].LRTableFuncP = LRReduce;
	parser->lrTable[39][15].actionParam = 54;
	//reduce
	parser->lrTable[51][15].LRTableFuncP = LRReduce;
	parser->lrTable[51][15].actionParam = 54;
	//shift
	parser->lrTable[4][15].LRTableFuncP = LRShift;
	parser->lrTable[4][15].actionParam = 19;
	//shift
	parser->lrTable[7][15].LRTableFuncP = LRShift;
	parser->lrTable[7][15].actionParam = 20;
	//shift
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 21;
	//shift
	parser->lrTable[10][15].LRTableFuncP = LRShift;
	parser->lrTable[10][15].actionParam = 22;
	//shift
	parser->lrTable[11][15].LRTableFuncP = LRShift;
	parser->lrTable[11][15].actionParam = 23;
	//shift
	parser->lrTable[25][15].LRTableFuncP = LRShift;
	parser->lrTable[25][15].actionParam = 24;
	//shift
	parser->lrTable[29][15].LRTableFuncP = LRShift;
	parser->lrTable[29][15].actionParam = 25;
	//shift
	parser->lrTable[35][15].LRTableFuncP = LRShift;
	parser->lrTable[35][15].actionParam = 26;
	//shift
	parser->lrTable[36][15].LRTableFuncP = LRShift;
	parser->lrTable[36][15].actionParam = 27;
	//shift
	parser->lrTable[37][15].LRTableFuncP = LRShift;
	parser->lrTable[37][15].actionParam = 28;
	//shift
	parser->lrTable[38][15].LRTableFuncP = LRShift;
	parser->lrTable[38][15].actionParam = 29;
	//shift
	parser->lrTable[39][15].LRTableFuncP = LRShift;
	parser->lrTable[39][15].actionParam = 30;
	//shift
	parser->lrTable[51][15].LRTableFuncP = LRShift;
	parser->lrTable[51][15].actionParam = 31;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][15].actionParam = 118;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][15].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][15].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][15].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][15].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][15].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][15].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][15].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][15].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][15].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][15].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][15].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][15].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][15].actionParam = 47;
	//reduce
	parser->lrTable[0][16].LRTableFuncP = LRReduce;
	parser->lrTable[0][16].actionParam = 88;
	//reduce
	parser->lrTable[1][16].LRTableFuncP = LRReduce;
	parser->lrTable[1][16].actionParam = 88;
	//reduce
	parser->lrTable[2][16].LRTableFuncP = LRReduce;
	parser->lrTable[2][16].actionParam = 88;
	//reduce
	parser->lrTable[3][16].LRTableFuncP = LRReduce;
	parser->lrTable[3][16].actionParam = 88;
	//reduce
	parser->lrTable[4][16].LRTableFuncP = LRReduce;
	parser->lrTable[4][16].actionParam = 88;
	//reduce
	parser->lrTable[2][16].LRTableFuncP = LRReduce;
	parser->lrTable[2][16].actionParam = 88;
	//reduce
	parser->lrTable[7][16].LRTableFuncP = LRReduce;
	parser->lrTable[7][16].actionParam = 88;
	//reduce
	parser->lrTable[7][16].LRTableFuncP = LRReduce;
	parser->lrTable[7][16].actionParam = 88;
	//reduce
	parser->lrTable[10][16].LRTableFuncP = LRReduce;
	parser->lrTable[10][16].actionParam = 88;
	//reduce
	parser->lrTable[10][16].LRTableFuncP = LRReduce;
	parser->lrTable[10][16].actionParam = 88;
	//reduce
	parser->lrTable[13][16].LRTableFuncP = LRReduce;
	parser->lrTable[13][16].actionParam = 88;
	//reduce
	parser->lrTable[13][16].LRTableFuncP = LRReduce;
	parser->lrTable[13][16].actionParam = 88;
	//reduce
	parser->lrTable[15][16].LRTableFuncP = LRReduce;
	parser->lrTable[15][16].actionParam = 88;
	//reduce
	parser->lrTable[15][16].LRTableFuncP = LRReduce;
	parser->lrTable[15][16].actionParam = 88;
	//reduce
	parser->lrTable[17][16].LRTableFuncP = LRReduce;
	parser->lrTable[17][16].actionParam = 88;
	//reduce
	parser->lrTable[17][16].LRTableFuncP = LRReduce;
	parser->lrTable[17][16].actionParam = 88;
	//reduce
	parser->lrTable[19][16].LRTableFuncP = LRReduce;
	parser->lrTable[19][16].actionParam = 88;
	//reduce
	parser->lrTable[20][16].LRTableFuncP = LRReduce;
	parser->lrTable[20][16].actionParam = 88;
	//reduce
	parser->lrTable[21][16].LRTableFuncP = LRReduce;
	parser->lrTable[21][16].actionParam = 88;
	//reduce
	parser->lrTable[21][16].LRTableFuncP = LRReduce;
	parser->lrTable[21][16].actionParam = 88;
	//reduce
	parser->lrTable[23][16].LRTableFuncP = LRReduce;
	parser->lrTable[23][16].actionParam = 88;
	//reduce
	parser->lrTable[23][16].LRTableFuncP = LRReduce;
	parser->lrTable[23][16].actionParam = 88;
	//reduce
	parser->lrTable[27][16].LRTableFuncP = LRReduce;
	parser->lrTable[27][16].actionParam = 88;
	//reduce
	parser->lrTable[28][16].LRTableFuncP = LRReduce;
	parser->lrTable[28][16].actionParam = 88;
	//reduce
	parser->lrTable[30][16].LRTableFuncP = LRReduce;
	parser->lrTable[30][16].actionParam = 88;
	//reduce
	parser->lrTable[34][16].LRTableFuncP = LRReduce;
	parser->lrTable[34][16].actionParam = 88;
	//reduce
	parser->lrTable[47][16].LRTableFuncP = LRReduce;
	parser->lrTable[47][16].actionParam = 88;
	//reduce
	parser->lrTable[48][16].LRTableFuncP = LRReduce;
	parser->lrTable[48][16].actionParam = 88;
	//reduce
	parser->lrTable[56][16].LRTableFuncP = LRReduce;
	parser->lrTable[56][16].actionParam = 88;
	//reduce
	parser->lrTable[57][16].LRTableFuncP = LRReduce;
	parser->lrTable[57][16].actionParam = 88;
	//reduce
	parser->lrTable[58][16].LRTableFuncP = LRReduce;
	parser->lrTable[58][16].actionParam = 88;
	//reduce
	parser->lrTable[59][16].LRTableFuncP = LRReduce;
	parser->lrTable[59][16].actionParam = 88;
	//reduce
	parser->lrTable[0][17].LRTableFuncP = LRReduce;
	parser->lrTable[0][17].actionParam = 96;
	//reduce
	parser->lrTable[1][17].LRTableFuncP = LRReduce;
	parser->lrTable[1][17].actionParam = 96;
	//reduce
	parser->lrTable[2][17].LRTableFuncP = LRReduce;
	parser->lrTable[2][17].actionParam = 96;
	//reduce
	parser->lrTable[3][17].LRTableFuncP = LRReduce;
	parser->lrTable[3][17].actionParam = 96;
	//reduce
	parser->lrTable[4][17].LRTableFuncP = LRReduce;
	parser->lrTable[4][17].actionParam = 96;
	//reduce
	parser->lrTable[2][17].LRTableFuncP = LRReduce;
	parser->lrTable[2][17].actionParam = 96;
	//reduce
	parser->lrTable[7][17].LRTableFuncP = LRReduce;
	parser->lrTable[7][17].actionParam = 96;
	//reduce
	parser->lrTable[8][17].LRTableFuncP = LRReduce;
	parser->lrTable[8][17].actionParam = 96;
	//reduce
	parser->lrTable[7][17].LRTableFuncP = LRReduce;
	parser->lrTable[7][17].actionParam = 96;
	//reduce
	parser->lrTable[10][17].LRTableFuncP = LRReduce;
	parser->lrTable[10][17].actionParam = 96;
	//reduce
	parser->lrTable[11][17].LRTableFuncP = LRReduce;
	parser->lrTable[11][17].actionParam = 96;
	//reduce
	parser->lrTable[10][17].LRTableFuncP = LRReduce;
	parser->lrTable[10][17].actionParam = 96;
	//reduce
	parser->lrTable[13][17].LRTableFuncP = LRReduce;
	parser->lrTable[13][17].actionParam = 96;
	//reduce
	parser->lrTable[13][17].LRTableFuncP = LRReduce;
	parser->lrTable[13][17].actionParam = 96;
	//reduce
	parser->lrTable[15][17].LRTableFuncP = LRReduce;
	parser->lrTable[15][17].actionParam = 96;
	//reduce
	parser->lrTable[15][17].LRTableFuncP = LRReduce;
	parser->lrTable[15][17].actionParam = 96;
	//reduce
	parser->lrTable[17][17].LRTableFuncP = LRReduce;
	parser->lrTable[17][17].actionParam = 96;
	//reduce
	parser->lrTable[17][17].LRTableFuncP = LRReduce;
	parser->lrTable[17][17].actionParam = 96;
	//reduce
	parser->lrTable[19][17].LRTableFuncP = LRReduce;
	parser->lrTable[19][17].actionParam = 96;
	//reduce
	parser->lrTable[20][17].LRTableFuncP = LRReduce;
	parser->lrTable[20][17].actionParam = 96;
	//reduce
	parser->lrTable[21][17].LRTableFuncP = LRReduce;
	parser->lrTable[21][17].actionParam = 96;
	//reduce
	parser->lrTable[21][17].LRTableFuncP = LRReduce;
	parser->lrTable[21][17].actionParam = 96;
	//reduce
	parser->lrTable[23][17].LRTableFuncP = LRReduce;
	parser->lrTable[23][17].actionParam = 96;
	//reduce
	parser->lrTable[23][17].LRTableFuncP = LRReduce;
	parser->lrTable[23][17].actionParam = 96;
	//reduce
	parser->lrTable[27][17].LRTableFuncP = LRReduce;
	parser->lrTable[27][17].actionParam = 96;
	//reduce
	parser->lrTable[28][17].LRTableFuncP = LRReduce;
	parser->lrTable[28][17].actionParam = 96;
	//reduce
	parser->lrTable[29][17].LRTableFuncP = LRReduce;
	parser->lrTable[29][17].actionParam = 96;
	//reduce
	parser->lrTable[30][17].LRTableFuncP = LRReduce;
	parser->lrTable[30][17].actionParam = 96;
	//reduce
	parser->lrTable[33][17].LRTableFuncP = LRReduce;
	parser->lrTable[33][17].actionParam = 96;
	//reduce
	parser->lrTable[34][17].LRTableFuncP = LRReduce;
	parser->lrTable[34][17].actionParam = 96;
	//reduce
	parser->lrTable[47][17].LRTableFuncP = LRReduce;
	parser->lrTable[47][17].actionParam = 96;
	//reduce
	parser->lrTable[48][17].LRTableFuncP = LRReduce;
	parser->lrTable[48][17].actionParam = 96;
	//reduce
	parser->lrTable[56][17].LRTableFuncP = LRReduce;
	parser->lrTable[56][17].actionParam = 96;
	//reduce
	parser->lrTable[57][17].LRTableFuncP = LRReduce;
	parser->lrTable[57][17].actionParam = 96;
	//reduce
	parser->lrTable[58][17].LRTableFuncP = LRReduce;
	parser->lrTable[58][17].actionParam = 96;
	//reduce
	parser->lrTable[59][17].LRTableFuncP = LRReduce;
	parser->lrTable[59][17].actionParam = 96;
	//reduce
	parser->lrTable[0][18].LRTableFuncP = LRReduce;
	parser->lrTable[0][18].actionParam = 97;
	//reduce
	parser->lrTable[1][18].LRTableFuncP = LRReduce;
	parser->lrTable[1][18].actionParam = 97;
	//reduce
	parser->lrTable[2][18].LRTableFuncP = LRReduce;
	parser->lrTable[2][18].actionParam = 97;
	//reduce
	parser->lrTable[3][18].LRTableFuncP = LRReduce;
	parser->lrTable[3][18].actionParam = 97;
	//reduce
	parser->lrTable[4][18].LRTableFuncP = LRReduce;
	parser->lrTable[4][18].actionParam = 97;
	//reduce
	parser->lrTable[2][18].LRTableFuncP = LRReduce;
	parser->lrTable[2][18].actionParam = 97;
	//reduce
	parser->lrTable[7][18].LRTableFuncP = LRReduce;
	parser->lrTable[7][18].actionParam = 97;
	//reduce
	parser->lrTable[8][18].LRTableFuncP = LRReduce;
	parser->lrTable[8][18].actionParam = 97;
	//reduce
	parser->lrTable[7][18].LRTableFuncP = LRReduce;
	parser->lrTable[7][18].actionParam = 97;
	//reduce
	parser->lrTable[10][18].LRTableFuncP = LRReduce;
	parser->lrTable[10][18].actionParam = 97;
	//reduce
	parser->lrTable[11][18].LRTableFuncP = LRReduce;
	parser->lrTable[11][18].actionParam = 97;
	//reduce
	parser->lrTable[10][18].LRTableFuncP = LRReduce;
	parser->lrTable[10][18].actionParam = 97;
	//reduce
	parser->lrTable[13][18].LRTableFuncP = LRReduce;
	parser->lrTable[13][18].actionParam = 97;
	//reduce
	parser->lrTable[13][18].LRTableFuncP = LRReduce;
	parser->lrTable[13][18].actionParam = 97;
	//reduce
	parser->lrTable[15][18].LRTableFuncP = LRReduce;
	parser->lrTable[15][18].actionParam = 97;
	//reduce
	parser->lrTable[15][18].LRTableFuncP = LRReduce;
	parser->lrTable[15][18].actionParam = 97;
	//reduce
	parser->lrTable[17][18].LRTableFuncP = LRReduce;
	parser->lrTable[17][18].actionParam = 97;
	//reduce
	parser->lrTable[17][18].LRTableFuncP = LRReduce;
	parser->lrTable[17][18].actionParam = 97;
	//reduce
	parser->lrTable[19][18].LRTableFuncP = LRReduce;
	parser->lrTable[19][18].actionParam = 97;
	//reduce
	parser->lrTable[20][18].LRTableFuncP = LRReduce;
	parser->lrTable[20][18].actionParam = 97;
	//reduce
	parser->lrTable[21][18].LRTableFuncP = LRReduce;
	parser->lrTable[21][18].actionParam = 97;
	//reduce
	parser->lrTable[21][18].LRTableFuncP = LRReduce;
	parser->lrTable[21][18].actionParam = 97;
	//reduce
	parser->lrTable[23][18].LRTableFuncP = LRReduce;
	parser->lrTable[23][18].actionParam = 97;
	//reduce
	parser->lrTable[23][18].LRTableFuncP = LRReduce;
	parser->lrTable[23][18].actionParam = 97;
	//reduce
	parser->lrTable[27][18].LRTableFuncP = LRReduce;
	parser->lrTable[27][18].actionParam = 97;
	//reduce
	parser->lrTable[28][18].LRTableFuncP = LRReduce;
	parser->lrTable[28][18].actionParam = 97;
	//reduce
	parser->lrTable[29][18].LRTableFuncP = LRReduce;
	parser->lrTable[29][18].actionParam = 97;
	//reduce
	parser->lrTable[30][18].LRTableFuncP = LRReduce;
	parser->lrTable[30][18].actionParam = 97;
	//reduce
	parser->lrTable[33][18].LRTableFuncP = LRReduce;
	parser->lrTable[33][18].actionParam = 97;
	//reduce
	parser->lrTable[34][18].LRTableFuncP = LRReduce;
	parser->lrTable[34][18].actionParam = 97;
	//reduce
	parser->lrTable[47][18].LRTableFuncP = LRReduce;
	parser->lrTable[47][18].actionParam = 97;
	//reduce
	parser->lrTable[48][18].LRTableFuncP = LRReduce;
	parser->lrTable[48][18].actionParam = 97;
	//reduce
	parser->lrTable[56][18].LRTableFuncP = LRReduce;
	parser->lrTable[56][18].actionParam = 97;
	//reduce
	parser->lrTable[57][18].LRTableFuncP = LRReduce;
	parser->lrTable[57][18].actionParam = 97;
	//reduce
	parser->lrTable[58][18].LRTableFuncP = LRReduce;
	parser->lrTable[58][18].actionParam = 97;
	//reduce
	parser->lrTable[59][18].LRTableFuncP = LRReduce;
	parser->lrTable[59][18].actionParam = 97;
	//shift
	parser->lrTable[4][18].LRTableFuncP = LRShift;
	parser->lrTable[4][18].actionParam = 19;
	//shift
	parser->lrTable[7][18].LRTableFuncP = LRShift;
	parser->lrTable[7][18].actionParam = 20;
	//shift
	parser->lrTable[8][18].LRTableFuncP = LRShift;
	parser->lrTable[8][18].actionParam = 21;
	//shift
	parser->lrTable[10][18].LRTableFuncP = LRShift;
	parser->lrTable[10][18].actionParam = 22;
	//shift
	parser->lrTable[11][18].LRTableFuncP = LRShift;
	parser->lrTable[11][18].actionParam = 23;
	//shift
	parser->lrTable[25][18].LRTableFuncP = LRShift;
	parser->lrTable[25][18].actionParam = 24;
	//shift
	parser->lrTable[29][18].LRTableFuncP = LRShift;
	parser->lrTable[29][18].actionParam = 25;
	//shift
	parser->lrTable[35][18].LRTableFuncP = LRShift;
	parser->lrTable[35][18].actionParam = 26;
	//shift
	parser->lrTable[36][18].LRTableFuncP = LRShift;
	parser->lrTable[36][18].actionParam = 27;
	//shift
	parser->lrTable[37][18].LRTableFuncP = LRShift;
	parser->lrTable[37][18].actionParam = 28;
	//shift
	parser->lrTable[38][18].LRTableFuncP = LRShift;
	parser->lrTable[38][18].actionParam = 29;
	//shift
	parser->lrTable[39][18].LRTableFuncP = LRShift;
	parser->lrTable[39][18].actionParam = 30;
	//shift
	parser->lrTable[51][18].LRTableFuncP = LRShift;
	parser->lrTable[51][18].actionParam = 31;
	//reduce
	parser->lrTable[30][18].LRTableFuncP = LRReduce;
	parser->lrTable[30][18].actionParam = 98;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][18].actionParam = 119;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][18].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][18].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][18].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][18].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][18].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][18].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][18].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][18].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][18].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][18].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][18].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][18].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][18].actionParam = 47;
	//goto
	parser->lrTable[argument_expression_list_opt+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[argument_expression_list_opt+TOTAL_TOKENS][18].actionParam = 120;
	//goto
	parser->lrTable[argument_expression_list+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[argument_expression_list+TOTAL_TOKENS][18].actionParam = 121;
	//shift
	parser->lrTable[4][18].LRTableFuncP = LRShift;
	parser->lrTable[4][18].actionParam = 19;
	//shift
	parser->lrTable[7][18].LRTableFuncP = LRShift;
	parser->lrTable[7][18].actionParam = 20;
	//shift
	parser->lrTable[8][18].LRTableFuncP = LRShift;
	parser->lrTable[8][18].actionParam = 21;
	//shift
	parser->lrTable[10][18].LRTableFuncP = LRShift;
	parser->lrTable[10][18].actionParam = 22;
	//shift
	parser->lrTable[11][18].LRTableFuncP = LRShift;
	parser->lrTable[11][18].actionParam = 23;
	//shift
	parser->lrTable[25][18].LRTableFuncP = LRShift;
	parser->lrTable[25][18].actionParam = 24;
	//shift
	parser->lrTable[29][18].LRTableFuncP = LRShift;
	parser->lrTable[29][18].actionParam = 25;
	//shift
	parser->lrTable[35][18].LRTableFuncP = LRShift;
	parser->lrTable[35][18].actionParam = 26;
	//shift
	parser->lrTable[36][18].LRTableFuncP = LRShift;
	parser->lrTable[36][18].actionParam = 27;
	//shift
	parser->lrTable[37][18].LRTableFuncP = LRShift;
	parser->lrTable[37][18].actionParam = 28;
	//shift
	parser->lrTable[38][18].LRTableFuncP = LRShift;
	parser->lrTable[38][18].actionParam = 29;
	//shift
	parser->lrTable[39][18].LRTableFuncP = LRShift;
	parser->lrTable[39][18].actionParam = 30;
	//shift
	parser->lrTable[51][18].LRTableFuncP = LRShift;
	parser->lrTable[51][18].actionParam = 31;
	//goto
	parser->lrTable[expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[expression+TOTAL_TOKENS][18].actionParam = 122;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][18].actionParam = 33;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][18].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][18].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][18].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][18].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][18].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][18].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][18].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][18].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][18].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][18].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][18].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][18].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][18].actionParam = 47;
	//reduce
	parser->lrTable[30][18].LRTableFuncP = LRReduce;
	parser->lrTable[30][18].actionParam = 20;
	//reduce
	parser->lrTable[57][18].LRTableFuncP = LRReduce;
	parser->lrTable[57][18].actionParam = 20;
	//shift
	parser->lrTable[31][18].LRTableFuncP = LRShift;
	parser->lrTable[31][18].actionParam = 123;
	//shift
	parser->lrTable[40][18].LRTableFuncP = LRShift;
	parser->lrTable[40][18].actionParam = 4;
	//shift
	parser->lrTable[41][18].LRTableFuncP = LRShift;
	parser->lrTable[41][18].actionParam = 5;
	//shift
	parser->lrTable[42][18].LRTableFuncP = LRShift;
	parser->lrTable[42][18].actionParam = 6;
	//shift
	parser->lrTable[43][18].LRTableFuncP = LRShift;
	parser->lrTable[43][18].actionParam = 7;
	//goto
	parser->lrTable[type_specifier+TOTAL_TOKENS][18].LRTableFuncP = LRGoto;
	parser->lrTable[type_specifier+TOTAL_TOKENS][18].actionParam = 49;
	//reduce
	parser->lrTable[0][19].LRTableFuncP = LRReduce;
	parser->lrTable[0][19].actionParam = 108;
	//reduce
	parser->lrTable[1][19].LRTableFuncP = LRReduce;
	parser->lrTable[1][19].actionParam = 108;
	//reduce
	parser->lrTable[2][19].LRTableFuncP = LRReduce;
	parser->lrTable[2][19].actionParam = 108;
	//reduce
	parser->lrTable[3][19].LRTableFuncP = LRReduce;
	parser->lrTable[3][19].actionParam = 108;
	//reduce
	parser->lrTable[4][19].LRTableFuncP = LRReduce;
	parser->lrTable[4][19].actionParam = 108;
	//reduce
	parser->lrTable[2][19].LRTableFuncP = LRReduce;
	parser->lrTable[2][19].actionParam = 108;
	//reduce
	parser->lrTable[7][19].LRTableFuncP = LRReduce;
	parser->lrTable[7][19].actionParam = 108;
	//reduce
	parser->lrTable[8][19].LRTableFuncP = LRReduce;
	parser->lrTable[8][19].actionParam = 108;
	//reduce
	parser->lrTable[7][19].LRTableFuncP = LRReduce;
	parser->lrTable[7][19].actionParam = 108;
	//reduce
	parser->lrTable[10][19].LRTableFuncP = LRReduce;
	parser->lrTable[10][19].actionParam = 108;
	//reduce
	parser->lrTable[11][19].LRTableFuncP = LRReduce;
	parser->lrTable[11][19].actionParam = 108;
	//reduce
	parser->lrTable[10][19].LRTableFuncP = LRReduce;
	parser->lrTable[10][19].actionParam = 108;
	//reduce
	parser->lrTable[13][19].LRTableFuncP = LRReduce;
	parser->lrTable[13][19].actionParam = 108;
	//reduce
	parser->lrTable[13][19].LRTableFuncP = LRReduce;
	parser->lrTable[13][19].actionParam = 108;
	//reduce
	parser->lrTable[15][19].LRTableFuncP = LRReduce;
	parser->lrTable[15][19].actionParam = 108;
	//reduce
	parser->lrTable[15][19].LRTableFuncP = LRReduce;
	parser->lrTable[15][19].actionParam = 108;
	//reduce
	parser->lrTable[17][19].LRTableFuncP = LRReduce;
	parser->lrTable[17][19].actionParam = 108;
	//reduce
	parser->lrTable[17][19].LRTableFuncP = LRReduce;
	parser->lrTable[17][19].actionParam = 108;
	//reduce
	parser->lrTable[19][19].LRTableFuncP = LRReduce;
	parser->lrTable[19][19].actionParam = 108;
	//reduce
	parser->lrTable[20][19].LRTableFuncP = LRReduce;
	parser->lrTable[20][19].actionParam = 108;
	//reduce
	parser->lrTable[21][19].LRTableFuncP = LRReduce;
	parser->lrTable[21][19].actionParam = 108;
	//reduce
	parser->lrTable[21][19].LRTableFuncP = LRReduce;
	parser->lrTable[21][19].actionParam = 108;
	//reduce
	parser->lrTable[23][19].LRTableFuncP = LRReduce;
	parser->lrTable[23][19].actionParam = 108;
	//reduce
	parser->lrTable[23][19].LRTableFuncP = LRReduce;
	parser->lrTable[23][19].actionParam = 108;
	//reduce
	parser->lrTable[27][19].LRTableFuncP = LRReduce;
	parser->lrTable[27][19].actionParam = 108;
	//reduce
	parser->lrTable[28][19].LRTableFuncP = LRReduce;
	parser->lrTable[28][19].actionParam = 108;
	//reduce
	parser->lrTable[29][19].LRTableFuncP = LRReduce;
	parser->lrTable[29][19].actionParam = 108;
	//reduce
	parser->lrTable[30][19].LRTableFuncP = LRReduce;
	parser->lrTable[30][19].actionParam = 108;
	//reduce
	parser->lrTable[33][19].LRTableFuncP = LRReduce;
	parser->lrTable[33][19].actionParam = 108;
	//reduce
	parser->lrTable[34][19].LRTableFuncP = LRReduce;
	parser->lrTable[34][19].actionParam = 108;
	//reduce
	parser->lrTable[47][19].LRTableFuncP = LRReduce;
	parser->lrTable[47][19].actionParam = 108;
	//reduce
	parser->lrTable[48][19].LRTableFuncP = LRReduce;
	parser->lrTable[48][19].actionParam = 108;
	//reduce
	parser->lrTable[56][19].LRTableFuncP = LRReduce;
	parser->lrTable[56][19].actionParam = 108;
	//reduce
	parser->lrTable[57][19].LRTableFuncP = LRReduce;
	parser->lrTable[57][19].actionParam = 108;
	//reduce
	parser->lrTable[58][19].LRTableFuncP = LRReduce;
	parser->lrTable[58][19].actionParam = 108;
	//reduce
	parser->lrTable[59][19].LRTableFuncP = LRReduce;
	parser->lrTable[59][19].actionParam = 108;
	//reduce
	parser->lrTable[30][19].LRTableFuncP = LRReduce;
	parser->lrTable[30][19].actionParam = 43;
	//reduce
	parser->lrTable[34][19].LRTableFuncP = LRReduce;
	parser->lrTable[34][19].actionParam = 43;
	//reduce
	parser->lrTable[56][19].LRTableFuncP = LRReduce;
	parser->lrTable[56][19].actionParam = 43;
	//reduce
	parser->lrTable[57][19].LRTableFuncP = LRReduce;
	parser->lrTable[57][19].actionParam = 43;
	//reduce
	parser->lrTable[59][19].LRTableFuncP = LRReduce;
	parser->lrTable[59][19].actionParam = 43;
	//shift
	parser->lrTable[47][19].LRTableFuncP = LRShift;
	parser->lrTable[47][19].actionParam = 61;
	//reduce
	parser->lrTable[30][19].LRTableFuncP = LRReduce;
	parser->lrTable[30][19].actionParam = 58;
	//reduce
	parser->lrTable[34][19].LRTableFuncP = LRReduce;
	parser->lrTable[34][19].actionParam = 58;
	//reduce
	parser->lrTable[48][19].LRTableFuncP = LRReduce;
	parser->lrTable[48][19].actionParam = 58;
	//reduce
	parser->lrTable[56][19].LRTableFuncP = LRReduce;
	parser->lrTable[56][19].actionParam = 58;
	//reduce
	parser->lrTable[57][19].LRTableFuncP = LRReduce;
	parser->lrTable[57][19].actionParam = 58;
	//reduce
	parser->lrTable[58][19].LRTableFuncP = LRReduce;
	parser->lrTable[58][19].actionParam = 58;
	//reduce
	parser->lrTable[59][19].LRTableFuncP = LRReduce;
	parser->lrTable[59][19].actionParam = 58;
	//reduce
	parser->lrTable[0][20].LRTableFuncP = LRReduce;
	parser->lrTable[0][20].actionParam = 81;
	//reduce
	parser->lrTable[1][20].LRTableFuncP = LRReduce;
	parser->lrTable[1][20].actionParam = 81;
	//reduce
	parser->lrTable[3][20].LRTableFuncP = LRReduce;
	parser->lrTable[3][20].actionParam = 81;
	//reduce
	parser->lrTable[4][20].LRTableFuncP = LRReduce;
	parser->lrTable[4][20].actionParam = 81;
	//reduce
	parser->lrTable[2][20].LRTableFuncP = LRReduce;
	parser->lrTable[2][20].actionParam = 81;
	//reduce
	parser->lrTable[7][20].LRTableFuncP = LRReduce;
	parser->lrTable[7][20].actionParam = 81;
	//reduce
	parser->lrTable[10][20].LRTableFuncP = LRReduce;
	parser->lrTable[10][20].actionParam = 81;
	//reduce
	parser->lrTable[13][20].LRTableFuncP = LRReduce;
	parser->lrTable[13][20].actionParam = 81;
	//reduce
	parser->lrTable[15][20].LRTableFuncP = LRReduce;
	parser->lrTable[15][20].actionParam = 81;
	//reduce
	parser->lrTable[17][20].LRTableFuncP = LRReduce;
	parser->lrTable[17][20].actionParam = 81;
	//reduce
	parser->lrTable[19][20].LRTableFuncP = LRReduce;
	parser->lrTable[19][20].actionParam = 81;
	//reduce
	parser->lrTable[21][20].LRTableFuncP = LRReduce;
	parser->lrTable[21][20].actionParam = 81;
	//reduce
	parser->lrTable[23][20].LRTableFuncP = LRReduce;
	parser->lrTable[23][20].actionParam = 81;
	//reduce
	parser->lrTable[27][20].LRTableFuncP = LRReduce;
	parser->lrTable[27][20].actionParam = 81;
	//reduce
	parser->lrTable[28][20].LRTableFuncP = LRReduce;
	parser->lrTable[28][20].actionParam = 81;
	//reduce
	parser->lrTable[30][20].LRTableFuncP = LRReduce;
	parser->lrTable[30][20].actionParam = 81;
	//reduce
	parser->lrTable[34][20].LRTableFuncP = LRReduce;
	parser->lrTable[34][20].actionParam = 81;
	//reduce
	parser->lrTable[47][20].LRTableFuncP = LRReduce;
	parser->lrTable[47][20].actionParam = 81;
	//reduce
	parser->lrTable[48][20].LRTableFuncP = LRReduce;
	parser->lrTable[48][20].actionParam = 81;
	//reduce
	parser->lrTable[56][20].LRTableFuncP = LRReduce;
	parser->lrTable[56][20].actionParam = 81;
	//reduce
	parser->lrTable[57][20].LRTableFuncP = LRReduce;
	parser->lrTable[57][20].actionParam = 81;
	//reduce
	parser->lrTable[58][20].LRTableFuncP = LRReduce;
	parser->lrTable[58][20].actionParam = 81;
	//reduce
	parser->lrTable[59][20].LRTableFuncP = LRReduce;
	parser->lrTable[59][20].actionParam = 81;
	//shift
	parser->lrTable[57][20].LRTableFuncP = LRShift;
	parser->lrTable[57][20].actionParam = 58;
	//shift
	parser->lrTable[59][20].LRTableFuncP = LRShift;
	parser->lrTable[59][20].actionParam = 126;
	//shift
	parser->lrTable[21][20].LRTableFuncP = LRShift;
	parser->lrTable[21][20].actionParam = 62;
	//reduce
	parser->lrTable[30][20].LRTableFuncP = LRReduce;
	parser->lrTable[30][20].actionParam = 60;
	//reduce
	parser->lrTable[34][20].LRTableFuncP = LRReduce;
	parser->lrTable[34][20].actionParam = 60;
	//reduce
	parser->lrTable[47][20].LRTableFuncP = LRReduce;
	parser->lrTable[47][20].actionParam = 60;
	//reduce
	parser->lrTable[48][20].LRTableFuncP = LRReduce;
	parser->lrTable[48][20].actionParam = 60;
	//reduce
	parser->lrTable[56][20].LRTableFuncP = LRReduce;
	parser->lrTable[56][20].actionParam = 60;
	//reduce
	parser->lrTable[57][20].LRTableFuncP = LRReduce;
	parser->lrTable[57][20].actionParam = 60;
	//reduce
	parser->lrTable[58][20].LRTableFuncP = LRReduce;
	parser->lrTable[58][20].actionParam = 60;
	//reduce
	parser->lrTable[59][20].LRTableFuncP = LRReduce;
	parser->lrTable[59][20].actionParam = 60;
	//shift
	parser->lrTable[23][20].LRTableFuncP = LRShift;
	parser->lrTable[23][20].actionParam = 63;
	//reduce
	parser->lrTable[21][20].LRTableFuncP = LRReduce;
	parser->lrTable[21][20].actionParam = 62;
	//reduce
	parser->lrTable[30][20].LRTableFuncP = LRReduce;
	parser->lrTable[30][20].actionParam = 62;
	//reduce
	parser->lrTable[34][20].LRTableFuncP = LRReduce;
	parser->lrTable[34][20].actionParam = 62;
	//reduce
	parser->lrTable[47][20].LRTableFuncP = LRReduce;
	parser->lrTable[47][20].actionParam = 62;
	//reduce
	parser->lrTable[48][20].LRTableFuncP = LRReduce;
	parser->lrTable[48][20].actionParam = 62;
	//reduce
	parser->lrTable[56][20].LRTableFuncP = LRReduce;
	parser->lrTable[56][20].actionParam = 62;
	//reduce
	parser->lrTable[57][20].LRTableFuncP = LRReduce;
	parser->lrTable[57][20].actionParam = 62;
	//reduce
	parser->lrTable[58][20].LRTableFuncP = LRReduce;
	parser->lrTable[58][20].actionParam = 62;
	//reduce
	parser->lrTable[59][20].LRTableFuncP = LRReduce;
	parser->lrTable[59][20].actionParam = 62;
	//shift
	parser->lrTable[19][20].LRTableFuncP = LRShift;
	parser->lrTable[19][20].actionParam = 64;
	//reduce
	parser->lrTable[21][20].LRTableFuncP = LRReduce;
	parser->lrTable[21][20].actionParam = 64;
	//reduce
	parser->lrTable[23][20].LRTableFuncP = LRReduce;
	parser->lrTable[23][20].actionParam = 64;
	//reduce
	parser->lrTable[30][20].LRTableFuncP = LRReduce;
	parser->lrTable[30][20].actionParam = 64;
	//reduce
	parser->lrTable[34][20].LRTableFuncP = LRReduce;
	parser->lrTable[34][20].actionParam = 64;
	//reduce
	parser->lrTable[47][20].LRTableFuncP = LRReduce;
	parser->lrTable[47][20].actionParam = 64;
	//reduce
	parser->lrTable[48][20].LRTableFuncP = LRReduce;
	parser->lrTable[48][20].actionParam = 64;
	//reduce
	parser->lrTable[56][20].LRTableFuncP = LRReduce;
	parser->lrTable[56][20].actionParam = 64;
	//reduce
	parser->lrTable[57][20].LRTableFuncP = LRReduce;
	parser->lrTable[57][20].actionParam = 64;
	//reduce
	parser->lrTable[58][20].LRTableFuncP = LRReduce;
	parser->lrTable[58][20].actionParam = 64;
	//reduce
	parser->lrTable[59][20].LRTableFuncP = LRReduce;
	parser->lrTable[59][20].actionParam = 64;
	//shift
	parser->lrTable[3][20].LRTableFuncP = LRShift;
	parser->lrTable[3][20].actionParam = 65;
	//shift
	parser->lrTable[4][20].LRTableFuncP = LRShift;
	parser->lrTable[4][20].actionParam = 66;
	//reduce
	parser->lrTable[19][20].LRTableFuncP = LRReduce;
	parser->lrTable[19][20].actionParam = 66;
	//reduce
	parser->lrTable[21][20].LRTableFuncP = LRReduce;
	parser->lrTable[21][20].actionParam = 66;
	//reduce
	parser->lrTable[23][20].LRTableFuncP = LRReduce;
	parser->lrTable[23][20].actionParam = 66;
	//reduce
	parser->lrTable[30][20].LRTableFuncP = LRReduce;
	parser->lrTable[30][20].actionParam = 66;
	//reduce
	parser->lrTable[34][20].LRTableFuncP = LRReduce;
	parser->lrTable[34][20].actionParam = 66;
	//reduce
	parser->lrTable[47][20].LRTableFuncP = LRReduce;
	parser->lrTable[47][20].actionParam = 66;
	//reduce
	parser->lrTable[48][20].LRTableFuncP = LRReduce;
	parser->lrTable[48][20].actionParam = 66;
	//reduce
	parser->lrTable[56][20].LRTableFuncP = LRReduce;
	parser->lrTable[56][20].actionParam = 66;
	//reduce
	parser->lrTable[57][20].LRTableFuncP = LRReduce;
	parser->lrTable[57][20].actionParam = 66;
	//reduce
	parser->lrTable[58][20].LRTableFuncP = LRReduce;
	parser->lrTable[58][20].actionParam = 66;
	//reduce
	parser->lrTable[59][20].LRTableFuncP = LRReduce;
	parser->lrTable[59][20].actionParam = 66;
	//shift
	parser->lrTable[0][21].LRTableFuncP = LRShift;
	parser->lrTable[0][21].actionParam = 68;
	//shift
	parser->lrTable[1][21].LRTableFuncP = LRShift;
	parser->lrTable[1][21].actionParam = 69;
	//shift
	parser->lrTable[2][21].LRTableFuncP = LRShift;
	parser->lrTable[2][21].actionParam = 70;
	//reduce
	parser->lrTable[3][21].LRTableFuncP = LRReduce;
	parser->lrTable[3][21].actionParam = 68;
	//reduce
	parser->lrTable[4][21].LRTableFuncP = LRReduce;
	parser->lrTable[4][21].actionParam = 68;
	//reduce
	parser->lrTable[19][21].LRTableFuncP = LRReduce;
	parser->lrTable[19][21].actionParam = 68;
	//reduce
	parser->lrTable[21][21].LRTableFuncP = LRReduce;
	parser->lrTable[21][21].actionParam = 68;
	//reduce
	parser->lrTable[23][21].LRTableFuncP = LRReduce;
	parser->lrTable[23][21].actionParam = 68;
	//reduce
	parser->lrTable[30][21].LRTableFuncP = LRReduce;
	parser->lrTable[30][21].actionParam = 68;
	//reduce
	parser->lrTable[34][21].LRTableFuncP = LRReduce;
	parser->lrTable[34][21].actionParam = 68;
	//reduce
	parser->lrTable[47][21].LRTableFuncP = LRReduce;
	parser->lrTable[47][21].actionParam = 68;
	//reduce
	parser->lrTable[48][21].LRTableFuncP = LRReduce;
	parser->lrTable[48][21].actionParam = 68;
	//reduce
	parser->lrTable[56][21].LRTableFuncP = LRReduce;
	parser->lrTable[56][21].actionParam = 68;
	//reduce
	parser->lrTable[57][21].LRTableFuncP = LRReduce;
	parser->lrTable[57][21].actionParam = 68;
	//reduce
	parser->lrTable[58][21].LRTableFuncP = LRReduce;
	parser->lrTable[58][21].actionParam = 68;
	//reduce
	parser->lrTable[59][21].LRTableFuncP = LRReduce;
	parser->lrTable[59][21].actionParam = 68;
	//shift
	parser->lrTable[0][22].LRTableFuncP = LRShift;
	parser->lrTable[0][22].actionParam = 68;
	//shift
	parser->lrTable[1][22].LRTableFuncP = LRShift;
	parser->lrTable[1][22].actionParam = 69;
	//shift
	parser->lrTable[2][22].LRTableFuncP = LRShift;
	parser->lrTable[2][22].actionParam = 70;
	//reduce
	parser->lrTable[3][22].LRTableFuncP = LRReduce;
	parser->lrTable[3][22].actionParam = 69;
	//reduce
	parser->lrTable[4][22].LRTableFuncP = LRReduce;
	parser->lrTable[4][22].actionParam = 69;
	//reduce
	parser->lrTable[19][22].LRTableFuncP = LRReduce;
	parser->lrTable[19][22].actionParam = 69;
	//reduce
	parser->lrTable[21][22].LRTableFuncP = LRReduce;
	parser->lrTable[21][22].actionParam = 69;
	//reduce
	parser->lrTable[23][22].LRTableFuncP = LRReduce;
	parser->lrTable[23][22].actionParam = 69;
	//reduce
	parser->lrTable[30][22].LRTableFuncP = LRReduce;
	parser->lrTable[30][22].actionParam = 69;
	//reduce
	parser->lrTable[34][22].LRTableFuncP = LRReduce;
	parser->lrTable[34][22].actionParam = 69;
	//reduce
	parser->lrTable[47][22].LRTableFuncP = LRReduce;
	parser->lrTable[47][22].actionParam = 69;
	//reduce
	parser->lrTable[48][22].LRTableFuncP = LRReduce;
	parser->lrTable[48][22].actionParam = 69;
	//reduce
	parser->lrTable[56][22].LRTableFuncP = LRReduce;
	parser->lrTable[56][22].actionParam = 69;
	//reduce
	parser->lrTable[57][22].LRTableFuncP = LRReduce;
	parser->lrTable[57][22].actionParam = 69;
	//reduce
	parser->lrTable[58][22].LRTableFuncP = LRReduce;
	parser->lrTable[58][22].actionParam = 69;
	//reduce
	parser->lrTable[59][22].LRTableFuncP = LRReduce;
	parser->lrTable[59][22].actionParam = 69;
	//shift
	parser->lrTable[27][22].LRTableFuncP = LRShift;
	parser->lrTable[27][22].actionParam = 71;
	//shift
	parser->lrTable[28][22].LRTableFuncP = LRShift;
	parser->lrTable[28][22].actionParam = 72;
	//reduce
	parser->lrTable[0][23].LRTableFuncP = LRReduce;
	parser->lrTable[0][23].actionParam = 73;
	//reduce
	parser->lrTable[1][23].LRTableFuncP = LRReduce;
	parser->lrTable[1][23].actionParam = 73;
	//reduce
	parser->lrTable[3][23].LRTableFuncP = LRReduce;
	parser->lrTable[3][23].actionParam = 73;
	//reduce
	parser->lrTable[4][23].LRTableFuncP = LRReduce;
	parser->lrTable[4][23].actionParam = 73;
	//reduce
	parser->lrTable[2][23].LRTableFuncP = LRReduce;
	parser->lrTable[2][23].actionParam = 73;
	//reduce
	parser->lrTable[19][23].LRTableFuncP = LRReduce;
	parser->lrTable[19][23].actionParam = 73;
	//reduce
	parser->lrTable[21][23].LRTableFuncP = LRReduce;
	parser->lrTable[21][23].actionParam = 73;
	//reduce
	parser->lrTable[23][23].LRTableFuncP = LRReduce;
	parser->lrTable[23][23].actionParam = 73;
	//reduce
	parser->lrTable[30][23].LRTableFuncP = LRReduce;
	parser->lrTable[30][23].actionParam = 73;
	//reduce
	parser->lrTable[34][23].LRTableFuncP = LRReduce;
	parser->lrTable[34][23].actionParam = 73;
	//reduce
	parser->lrTable[47][23].LRTableFuncP = LRReduce;
	parser->lrTable[47][23].actionParam = 73;
	//reduce
	parser->lrTable[48][23].LRTableFuncP = LRReduce;
	parser->lrTable[48][23].actionParam = 73;
	//reduce
	parser->lrTable[56][23].LRTableFuncP = LRReduce;
	parser->lrTable[56][23].actionParam = 73;
	//reduce
	parser->lrTable[57][23].LRTableFuncP = LRReduce;
	parser->lrTable[57][23].actionParam = 73;
	//reduce
	parser->lrTable[58][23].LRTableFuncP = LRReduce;
	parser->lrTable[58][23].actionParam = 73;
	//reduce
	parser->lrTable[59][23].LRTableFuncP = LRReduce;
	parser->lrTable[59][23].actionParam = 73;
	//shift
	parser->lrTable[27][23].LRTableFuncP = LRShift;
	parser->lrTable[27][23].actionParam = 71;
	//shift
	parser->lrTable[28][23].LRTableFuncP = LRShift;
	parser->lrTable[28][23].actionParam = 72;
	//reduce
	parser->lrTable[0][24].LRTableFuncP = LRReduce;
	parser->lrTable[0][24].actionParam = 72;
	//reduce
	parser->lrTable[1][24].LRTableFuncP = LRReduce;
	parser->lrTable[1][24].actionParam = 72;
	//reduce
	parser->lrTable[3][24].LRTableFuncP = LRReduce;
	parser->lrTable[3][24].actionParam = 72;
	//reduce
	parser->lrTable[4][24].LRTableFuncP = LRReduce;
	parser->lrTable[4][24].actionParam = 72;
	//reduce
	parser->lrTable[2][24].LRTableFuncP = LRReduce;
	parser->lrTable[2][24].actionParam = 72;
	//reduce
	parser->lrTable[19][24].LRTableFuncP = LRReduce;
	parser->lrTable[19][24].actionParam = 72;
	//reduce
	parser->lrTable[21][24].LRTableFuncP = LRReduce;
	parser->lrTable[21][24].actionParam = 72;
	//reduce
	parser->lrTable[23][24].LRTableFuncP = LRReduce;
	parser->lrTable[23][24].actionParam = 72;
	//reduce
	parser->lrTable[30][24].LRTableFuncP = LRReduce;
	parser->lrTable[30][24].actionParam = 72;
	//reduce
	parser->lrTable[34][24].LRTableFuncP = LRReduce;
	parser->lrTable[34][24].actionParam = 72;
	//reduce
	parser->lrTable[47][24].LRTableFuncP = LRReduce;
	parser->lrTable[47][24].actionParam = 72;
	//reduce
	parser->lrTable[48][24].LRTableFuncP = LRReduce;
	parser->lrTable[48][24].actionParam = 72;
	//reduce
	parser->lrTable[56][24].LRTableFuncP = LRReduce;
	parser->lrTable[56][24].actionParam = 72;
	//reduce
	parser->lrTable[57][24].LRTableFuncP = LRReduce;
	parser->lrTable[57][24].actionParam = 72;
	//reduce
	parser->lrTable[58][24].LRTableFuncP = LRReduce;
	parser->lrTable[58][24].actionParam = 72;
	//reduce
	parser->lrTable[59][24].LRTableFuncP = LRReduce;
	parser->lrTable[59][24].actionParam = 72;
	//shift
	parser->lrTable[27][24].LRTableFuncP = LRShift;
	parser->lrTable[27][24].actionParam = 71;
	//shift
	parser->lrTable[28][24].LRTableFuncP = LRShift;
	parser->lrTable[28][24].actionParam = 72;
	//reduce
	parser->lrTable[0][25].LRTableFuncP = LRReduce;
	parser->lrTable[0][25].actionParam = 71;
	//reduce
	parser->lrTable[1][25].LRTableFuncP = LRReduce;
	parser->lrTable[1][25].actionParam = 71;
	//reduce
	parser->lrTable[3][25].LRTableFuncP = LRReduce;
	parser->lrTable[3][25].actionParam = 71;
	//reduce
	parser->lrTable[4][25].LRTableFuncP = LRReduce;
	parser->lrTable[4][25].actionParam = 71;
	//reduce
	parser->lrTable[2][25].LRTableFuncP = LRReduce;
	parser->lrTable[2][25].actionParam = 71;
	//reduce
	parser->lrTable[19][25].LRTableFuncP = LRReduce;
	parser->lrTable[19][25].actionParam = 71;
	//reduce
	parser->lrTable[21][25].LRTableFuncP = LRReduce;
	parser->lrTable[21][25].actionParam = 71;
	//reduce
	parser->lrTable[23][25].LRTableFuncP = LRReduce;
	parser->lrTable[23][25].actionParam = 71;
	//reduce
	parser->lrTable[30][25].LRTableFuncP = LRReduce;
	parser->lrTable[30][25].actionParam = 71;
	//reduce
	parser->lrTable[34][25].LRTableFuncP = LRReduce;
	parser->lrTable[34][25].actionParam = 71;
	//reduce
	parser->lrTable[47][25].LRTableFuncP = LRReduce;
	parser->lrTable[47][25].actionParam = 71;
	//reduce
	parser->lrTable[48][25].LRTableFuncP = LRReduce;
	parser->lrTable[48][25].actionParam = 71;
	//reduce
	parser->lrTable[56][25].LRTableFuncP = LRReduce;
	parser->lrTable[56][25].actionParam = 71;
	//reduce
	parser->lrTable[57][25].LRTableFuncP = LRReduce;
	parser->lrTable[57][25].actionParam = 71;
	//reduce
	parser->lrTable[58][25].LRTableFuncP = LRReduce;
	parser->lrTable[58][25].actionParam = 71;
	//reduce
	parser->lrTable[59][25].LRTableFuncP = LRReduce;
	parser->lrTable[59][25].actionParam = 71;
	//shift
	parser->lrTable[27][25].LRTableFuncP = LRShift;
	parser->lrTable[27][25].actionParam = 71;
	//shift
	parser->lrTable[28][25].LRTableFuncP = LRShift;
	parser->lrTable[28][25].actionParam = 72;
	//reduce
	parser->lrTable[0][26].LRTableFuncP = LRReduce;
	parser->lrTable[0][26].actionParam = 74;
	//reduce
	parser->lrTable[1][26].LRTableFuncP = LRReduce;
	parser->lrTable[1][26].actionParam = 74;
	//reduce
	parser->lrTable[3][26].LRTableFuncP = LRReduce;
	parser->lrTable[3][26].actionParam = 74;
	//reduce
	parser->lrTable[4][26].LRTableFuncP = LRReduce;
	parser->lrTable[4][26].actionParam = 74;
	//reduce
	parser->lrTable[2][26].LRTableFuncP = LRReduce;
	parser->lrTable[2][26].actionParam = 74;
	//reduce
	parser->lrTable[19][26].LRTableFuncP = LRReduce;
	parser->lrTable[19][26].actionParam = 74;
	//reduce
	parser->lrTable[21][26].LRTableFuncP = LRReduce;
	parser->lrTable[21][26].actionParam = 74;
	//reduce
	parser->lrTable[23][26].LRTableFuncP = LRReduce;
	parser->lrTable[23][26].actionParam = 74;
	//reduce
	parser->lrTable[30][26].LRTableFuncP = LRReduce;
	parser->lrTable[30][26].actionParam = 74;
	//reduce
	parser->lrTable[34][26].LRTableFuncP = LRReduce;
	parser->lrTable[34][26].actionParam = 74;
	//reduce
	parser->lrTable[47][26].LRTableFuncP = LRReduce;
	parser->lrTable[47][26].actionParam = 74;
	//reduce
	parser->lrTable[48][26].LRTableFuncP = LRReduce;
	parser->lrTable[48][26].actionParam = 74;
	//reduce
	parser->lrTable[56][26].LRTableFuncP = LRReduce;
	parser->lrTable[56][26].actionParam = 74;
	//reduce
	parser->lrTable[57][26].LRTableFuncP = LRReduce;
	parser->lrTable[57][26].actionParam = 74;
	//reduce
	parser->lrTable[58][26].LRTableFuncP = LRReduce;
	parser->lrTable[58][26].actionParam = 74;
	//reduce
	parser->lrTable[59][26].LRTableFuncP = LRReduce;
	parser->lrTable[59][26].actionParam = 74;
	//shift
	parser->lrTable[7][26].LRTableFuncP = LRShift;
	parser->lrTable[7][26].actionParam = 73;
	//shift
	parser->lrTable[10][26].LRTableFuncP = LRShift;
	parser->lrTable[10][26].actionParam = 74;
	//reduce
	parser->lrTable[0][27].LRTableFuncP = LRReduce;
	parser->lrTable[0][27].actionParam = 76;
	//reduce
	parser->lrTable[1][27].LRTableFuncP = LRReduce;
	parser->lrTable[1][27].actionParam = 76;
	//reduce
	parser->lrTable[3][27].LRTableFuncP = LRReduce;
	parser->lrTable[3][27].actionParam = 76;
	//reduce
	parser->lrTable[4][27].LRTableFuncP = LRReduce;
	parser->lrTable[4][27].actionParam = 76;
	//reduce
	parser->lrTable[2][27].LRTableFuncP = LRReduce;
	parser->lrTable[2][27].actionParam = 76;
	//reduce
	parser->lrTable[19][27].LRTableFuncP = LRReduce;
	parser->lrTable[19][27].actionParam = 76;
	//reduce
	parser->lrTable[21][27].LRTableFuncP = LRReduce;
	parser->lrTable[21][27].actionParam = 76;
	//reduce
	parser->lrTable[23][27].LRTableFuncP = LRReduce;
	parser->lrTable[23][27].actionParam = 76;
	//reduce
	parser->lrTable[27][27].LRTableFuncP = LRReduce;
	parser->lrTable[27][27].actionParam = 76;
	//reduce
	parser->lrTable[28][27].LRTableFuncP = LRReduce;
	parser->lrTable[28][27].actionParam = 76;
	//reduce
	parser->lrTable[30][27].LRTableFuncP = LRReduce;
	parser->lrTable[30][27].actionParam = 76;
	//reduce
	parser->lrTable[34][27].LRTableFuncP = LRReduce;
	parser->lrTable[34][27].actionParam = 76;
	//reduce
	parser->lrTable[47][27].LRTableFuncP = LRReduce;
	parser->lrTable[47][27].actionParam = 76;
	//reduce
	parser->lrTable[48][27].LRTableFuncP = LRReduce;
	parser->lrTable[48][27].actionParam = 76;
	//reduce
	parser->lrTable[56][27].LRTableFuncP = LRReduce;
	parser->lrTable[56][27].actionParam = 76;
	//reduce
	parser->lrTable[57][27].LRTableFuncP = LRReduce;
	parser->lrTable[57][27].actionParam = 76;
	//reduce
	parser->lrTable[58][27].LRTableFuncP = LRReduce;
	parser->lrTable[58][27].actionParam = 76;
	//reduce
	parser->lrTable[59][27].LRTableFuncP = LRReduce;
	parser->lrTable[59][27].actionParam = 76;
	//shift
	parser->lrTable[7][27].LRTableFuncP = LRShift;
	parser->lrTable[7][27].actionParam = 73;
	//shift
	parser->lrTable[10][27].LRTableFuncP = LRShift;
	parser->lrTable[10][27].actionParam = 74;
	//reduce
	parser->lrTable[0][28].LRTableFuncP = LRReduce;
	parser->lrTable[0][28].actionParam = 77;
	//reduce
	parser->lrTable[1][28].LRTableFuncP = LRReduce;
	parser->lrTable[1][28].actionParam = 77;
	//reduce
	parser->lrTable[3][28].LRTableFuncP = LRReduce;
	parser->lrTable[3][28].actionParam = 77;
	//reduce
	parser->lrTable[4][28].LRTableFuncP = LRReduce;
	parser->lrTable[4][28].actionParam = 77;
	//reduce
	parser->lrTable[2][28].LRTableFuncP = LRReduce;
	parser->lrTable[2][28].actionParam = 77;
	//reduce
	parser->lrTable[19][28].LRTableFuncP = LRReduce;
	parser->lrTable[19][28].actionParam = 77;
	//reduce
	parser->lrTable[21][28].LRTableFuncP = LRReduce;
	parser->lrTable[21][28].actionParam = 77;
	//reduce
	parser->lrTable[23][28].LRTableFuncP = LRReduce;
	parser->lrTable[23][28].actionParam = 77;
	//reduce
	parser->lrTable[27][28].LRTableFuncP = LRReduce;
	parser->lrTable[27][28].actionParam = 77;
	//reduce
	parser->lrTable[28][28].LRTableFuncP = LRReduce;
	parser->lrTable[28][28].actionParam = 77;
	//reduce
	parser->lrTable[30][28].LRTableFuncP = LRReduce;
	parser->lrTable[30][28].actionParam = 77;
	//reduce
	parser->lrTable[34][28].LRTableFuncP = LRReduce;
	parser->lrTable[34][28].actionParam = 77;
	//reduce
	parser->lrTable[47][28].LRTableFuncP = LRReduce;
	parser->lrTable[47][28].actionParam = 77;
	//reduce
	parser->lrTable[48][28].LRTableFuncP = LRReduce;
	parser->lrTable[48][28].actionParam = 77;
	//reduce
	parser->lrTable[56][28].LRTableFuncP = LRReduce;
	parser->lrTable[56][28].actionParam = 77;
	//reduce
	parser->lrTable[57][28].LRTableFuncP = LRReduce;
	parser->lrTable[57][28].actionParam = 77;
	//reduce
	parser->lrTable[58][28].LRTableFuncP = LRReduce;
	parser->lrTable[58][28].actionParam = 77;
	//reduce
	parser->lrTable[59][28].LRTableFuncP = LRReduce;
	parser->lrTable[59][28].actionParam = 77;
	//shift
	parser->lrTable[13][28].LRTableFuncP = LRShift;
	parser->lrTable[13][28].actionParam = 75;
	//shift
	parser->lrTable[15][28].LRTableFuncP = LRShift;
	parser->lrTable[15][28].actionParam = 76;
	//shift
	parser->lrTable[17][28].LRTableFuncP = LRShift;
	parser->lrTable[17][28].actionParam = 77;
	//reduce
	parser->lrTable[0][29].LRTableFuncP = LRReduce;
	parser->lrTable[0][29].actionParam = 79;
	//reduce
	parser->lrTable[1][29].LRTableFuncP = LRReduce;
	parser->lrTable[1][29].actionParam = 79;
	//reduce
	parser->lrTable[3][29].LRTableFuncP = LRReduce;
	parser->lrTable[3][29].actionParam = 79;
	//reduce
	parser->lrTable[4][29].LRTableFuncP = LRReduce;
	parser->lrTable[4][29].actionParam = 79;
	//reduce
	parser->lrTable[2][29].LRTableFuncP = LRReduce;
	parser->lrTable[2][29].actionParam = 79;
	//reduce
	parser->lrTable[7][29].LRTableFuncP = LRReduce;
	parser->lrTable[7][29].actionParam = 79;
	//reduce
	parser->lrTable[10][29].LRTableFuncP = LRReduce;
	parser->lrTable[10][29].actionParam = 79;
	//reduce
	parser->lrTable[19][29].LRTableFuncP = LRReduce;
	parser->lrTable[19][29].actionParam = 79;
	//reduce
	parser->lrTable[21][29].LRTableFuncP = LRReduce;
	parser->lrTable[21][29].actionParam = 79;
	//reduce
	parser->lrTable[23][29].LRTableFuncP = LRReduce;
	parser->lrTable[23][29].actionParam = 79;
	//reduce
	parser->lrTable[27][29].LRTableFuncP = LRReduce;
	parser->lrTable[27][29].actionParam = 79;
	//reduce
	parser->lrTable[28][29].LRTableFuncP = LRReduce;
	parser->lrTable[28][29].actionParam = 79;
	//reduce
	parser->lrTable[30][29].LRTableFuncP = LRReduce;
	parser->lrTable[30][29].actionParam = 79;
	//reduce
	parser->lrTable[34][29].LRTableFuncP = LRReduce;
	parser->lrTable[34][29].actionParam = 79;
	//reduce
	parser->lrTable[47][29].LRTableFuncP = LRReduce;
	parser->lrTable[47][29].actionParam = 79;
	//reduce
	parser->lrTable[48][29].LRTableFuncP = LRReduce;
	parser->lrTable[48][29].actionParam = 79;
	//reduce
	parser->lrTable[56][29].LRTableFuncP = LRReduce;
	parser->lrTable[56][29].actionParam = 79;
	//reduce
	parser->lrTable[57][29].LRTableFuncP = LRReduce;
	parser->lrTable[57][29].actionParam = 79;
	//reduce
	parser->lrTable[58][29].LRTableFuncP = LRReduce;
	parser->lrTable[58][29].actionParam = 79;
	//reduce
	parser->lrTable[59][29].LRTableFuncP = LRReduce;
	parser->lrTable[59][29].actionParam = 79;
	//shift
	parser->lrTable[13][29].LRTableFuncP = LRShift;
	parser->lrTable[13][29].actionParam = 75;
	//shift
	parser->lrTable[15][29].LRTableFuncP = LRShift;
	parser->lrTable[15][29].actionParam = 76;
	//shift
	parser->lrTable[17][29].LRTableFuncP = LRShift;
	parser->lrTable[17][29].actionParam = 77;
	//reduce
	parser->lrTable[0][30].LRTableFuncP = LRReduce;
	parser->lrTable[0][30].actionParam = 80;
	//reduce
	parser->lrTable[1][30].LRTableFuncP = LRReduce;
	parser->lrTable[1][30].actionParam = 80;
	//reduce
	parser->lrTable[3][30].LRTableFuncP = LRReduce;
	parser->lrTable[3][30].actionParam = 80;
	//reduce
	parser->lrTable[4][30].LRTableFuncP = LRReduce;
	parser->lrTable[4][30].actionParam = 80;
	//reduce
	parser->lrTable[2][30].LRTableFuncP = LRReduce;
	parser->lrTable[2][30].actionParam = 80;
	//reduce
	parser->lrTable[7][30].LRTableFuncP = LRReduce;
	parser->lrTable[7][30].actionParam = 80;
	//reduce
	parser->lrTable[10][30].LRTableFuncP = LRReduce;
	parser->lrTable[10][30].actionParam = 80;
	//reduce
	parser->lrTable[19][30].LRTableFuncP = LRReduce;
	parser->lrTable[19][30].actionParam = 80;
	//reduce
	parser->lrTable[21][30].LRTableFuncP = LRReduce;
	parser->lrTable[21][30].actionParam = 80;
	//reduce
	parser->lrTable[23][30].LRTableFuncP = LRReduce;
	parser->lrTable[23][30].actionParam = 80;
	//reduce
	parser->lrTable[27][30].LRTableFuncP = LRReduce;
	parser->lrTable[27][30].actionParam = 80;
	//reduce
	parser->lrTable[28][30].LRTableFuncP = LRReduce;
	parser->lrTable[28][30].actionParam = 80;
	//reduce
	parser->lrTable[30][30].LRTableFuncP = LRReduce;
	parser->lrTable[30][30].actionParam = 80;
	//reduce
	parser->lrTable[34][30].LRTableFuncP = LRReduce;
	parser->lrTable[34][30].actionParam = 80;
	//reduce
	parser->lrTable[47][30].LRTableFuncP = LRReduce;
	parser->lrTable[47][30].actionParam = 80;
	//reduce
	parser->lrTable[48][30].LRTableFuncP = LRReduce;
	parser->lrTable[48][30].actionParam = 80;
	//reduce
	parser->lrTable[56][30].LRTableFuncP = LRReduce;
	parser->lrTable[56][30].actionParam = 80;
	//reduce
	parser->lrTable[57][30].LRTableFuncP = LRReduce;
	parser->lrTable[57][30].actionParam = 80;
	//reduce
	parser->lrTable[58][30].LRTableFuncP = LRReduce;
	parser->lrTable[58][30].actionParam = 80;
	//reduce
	parser->lrTable[59][30].LRTableFuncP = LRReduce;
	parser->lrTable[59][30].actionParam = 80;
	//reduce
	parser->lrTable[0][31].LRTableFuncP = LRReduce;
	parser->lrTable[0][31].actionParam = 83;
	//reduce
	parser->lrTable[1][31].LRTableFuncP = LRReduce;
	parser->lrTable[1][31].actionParam = 83;
	//reduce
	parser->lrTable[3][31].LRTableFuncP = LRReduce;
	parser->lrTable[3][31].actionParam = 83;
	//reduce
	parser->lrTable[4][31].LRTableFuncP = LRReduce;
	parser->lrTable[4][31].actionParam = 83;
	//reduce
	parser->lrTable[2][31].LRTableFuncP = LRReduce;
	parser->lrTable[2][31].actionParam = 83;
	//reduce
	parser->lrTable[7][31].LRTableFuncP = LRReduce;
	parser->lrTable[7][31].actionParam = 83;
	//reduce
	parser->lrTable[10][31].LRTableFuncP = LRReduce;
	parser->lrTable[10][31].actionParam = 83;
	//reduce
	parser->lrTable[13][31].LRTableFuncP = LRReduce;
	parser->lrTable[13][31].actionParam = 83;
	//reduce
	parser->lrTable[15][31].LRTableFuncP = LRReduce;
	parser->lrTable[15][31].actionParam = 83;
	//reduce
	parser->lrTable[17][31].LRTableFuncP = LRReduce;
	parser->lrTable[17][31].actionParam = 83;
	//reduce
	parser->lrTable[19][31].LRTableFuncP = LRReduce;
	parser->lrTable[19][31].actionParam = 83;
	//reduce
	parser->lrTable[21][31].LRTableFuncP = LRReduce;
	parser->lrTable[21][31].actionParam = 83;
	//reduce
	parser->lrTable[23][31].LRTableFuncP = LRReduce;
	parser->lrTable[23][31].actionParam = 83;
	//reduce
	parser->lrTable[27][31].LRTableFuncP = LRReduce;
	parser->lrTable[27][31].actionParam = 83;
	//reduce
	parser->lrTable[28][31].LRTableFuncP = LRReduce;
	parser->lrTable[28][31].actionParam = 83;
	//reduce
	parser->lrTable[30][31].LRTableFuncP = LRReduce;
	parser->lrTable[30][31].actionParam = 83;
	//reduce
	parser->lrTable[34][31].LRTableFuncP = LRReduce;
	parser->lrTable[34][31].actionParam = 83;
	//reduce
	parser->lrTable[47][31].LRTableFuncP = LRReduce;
	parser->lrTable[47][31].actionParam = 83;
	//reduce
	parser->lrTable[48][31].LRTableFuncP = LRReduce;
	parser->lrTable[48][31].actionParam = 83;
	//reduce
	parser->lrTable[56][31].LRTableFuncP = LRReduce;
	parser->lrTable[56][31].actionParam = 83;
	//reduce
	parser->lrTable[57][31].LRTableFuncP = LRReduce;
	parser->lrTable[57][31].actionParam = 83;
	//reduce
	parser->lrTable[58][31].LRTableFuncP = LRReduce;
	parser->lrTable[58][31].actionParam = 83;
	//reduce
	parser->lrTable[59][31].LRTableFuncP = LRReduce;
	parser->lrTable[59][31].actionParam = 83;
	//reduce
	parser->lrTable[0][32].LRTableFuncP = LRReduce;
	parser->lrTable[0][32].actionParam = 82;
	//reduce
	parser->lrTable[1][32].LRTableFuncP = LRReduce;
	parser->lrTable[1][32].actionParam = 82;
	//reduce
	parser->lrTable[3][32].LRTableFuncP = LRReduce;
	parser->lrTable[3][32].actionParam = 82;
	//reduce
	parser->lrTable[4][32].LRTableFuncP = LRReduce;
	parser->lrTable[4][32].actionParam = 82;
	//reduce
	parser->lrTable[2][32].LRTableFuncP = LRReduce;
	parser->lrTable[2][32].actionParam = 82;
	//reduce
	parser->lrTable[7][32].LRTableFuncP = LRReduce;
	parser->lrTable[7][32].actionParam = 82;
	//reduce
	parser->lrTable[10][32].LRTableFuncP = LRReduce;
	parser->lrTable[10][32].actionParam = 82;
	//reduce
	parser->lrTable[13][32].LRTableFuncP = LRReduce;
	parser->lrTable[13][32].actionParam = 82;
	//reduce
	parser->lrTable[15][32].LRTableFuncP = LRReduce;
	parser->lrTable[15][32].actionParam = 82;
	//reduce
	parser->lrTable[17][32].LRTableFuncP = LRReduce;
	parser->lrTable[17][32].actionParam = 82;
	//reduce
	parser->lrTable[19][32].LRTableFuncP = LRReduce;
	parser->lrTable[19][32].actionParam = 82;
	//reduce
	parser->lrTable[21][32].LRTableFuncP = LRReduce;
	parser->lrTable[21][32].actionParam = 82;
	//reduce
	parser->lrTable[23][32].LRTableFuncP = LRReduce;
	parser->lrTable[23][32].actionParam = 82;
	//reduce
	parser->lrTable[27][32].LRTableFuncP = LRReduce;
	parser->lrTable[27][32].actionParam = 82;
	//reduce
	parser->lrTable[28][32].LRTableFuncP = LRReduce;
	parser->lrTable[28][32].actionParam = 82;
	//reduce
	parser->lrTable[30][32].LRTableFuncP = LRReduce;
	parser->lrTable[30][32].actionParam = 82;
	//reduce
	parser->lrTable[34][32].LRTableFuncP = LRReduce;
	parser->lrTable[34][32].actionParam = 82;
	//reduce
	parser->lrTable[47][32].LRTableFuncP = LRReduce;
	parser->lrTable[47][32].actionParam = 82;
	//reduce
	parser->lrTable[48][32].LRTableFuncP = LRReduce;
	parser->lrTable[48][32].actionParam = 82;
	//reduce
	parser->lrTable[56][32].LRTableFuncP = LRReduce;
	parser->lrTable[56][32].actionParam = 82;
	//reduce
	parser->lrTable[57][32].LRTableFuncP = LRReduce;
	parser->lrTable[57][32].actionParam = 82;
	//reduce
	parser->lrTable[58][32].LRTableFuncP = LRReduce;
	parser->lrTable[58][32].actionParam = 82;
	//reduce
	parser->lrTable[59][32].LRTableFuncP = LRReduce;
	parser->lrTable[59][32].actionParam = 82;
	//reduce
	parser->lrTable[0][33].LRTableFuncP = LRReduce;
	parser->lrTable[0][33].actionParam = 84;
	//reduce
	parser->lrTable[1][33].LRTableFuncP = LRReduce;
	parser->lrTable[1][33].actionParam = 84;
	//reduce
	parser->lrTable[3][33].LRTableFuncP = LRReduce;
	parser->lrTable[3][33].actionParam = 84;
	//reduce
	parser->lrTable[4][33].LRTableFuncP = LRReduce;
	parser->lrTable[4][33].actionParam = 84;
	//reduce
	parser->lrTable[2][33].LRTableFuncP = LRReduce;
	parser->lrTable[2][33].actionParam = 84;
	//reduce
	parser->lrTable[7][33].LRTableFuncP = LRReduce;
	parser->lrTable[7][33].actionParam = 84;
	//reduce
	parser->lrTable[10][33].LRTableFuncP = LRReduce;
	parser->lrTable[10][33].actionParam = 84;
	//reduce
	parser->lrTable[13][33].LRTableFuncP = LRReduce;
	parser->lrTable[13][33].actionParam = 84;
	//reduce
	parser->lrTable[15][33].LRTableFuncP = LRReduce;
	parser->lrTable[15][33].actionParam = 84;
	//reduce
	parser->lrTable[17][33].LRTableFuncP = LRReduce;
	parser->lrTable[17][33].actionParam = 84;
	//reduce
	parser->lrTable[19][33].LRTableFuncP = LRReduce;
	parser->lrTable[19][33].actionParam = 84;
	//reduce
	parser->lrTable[21][33].LRTableFuncP = LRReduce;
	parser->lrTable[21][33].actionParam = 84;
	//reduce
	parser->lrTable[23][33].LRTableFuncP = LRReduce;
	parser->lrTable[23][33].actionParam = 84;
	//reduce
	parser->lrTable[27][33].LRTableFuncP = LRReduce;
	parser->lrTable[27][33].actionParam = 84;
	//reduce
	parser->lrTable[28][33].LRTableFuncP = LRReduce;
	parser->lrTable[28][33].actionParam = 84;
	//reduce
	parser->lrTable[30][33].LRTableFuncP = LRReduce;
	parser->lrTable[30][33].actionParam = 84;
	//reduce
	parser->lrTable[34][33].LRTableFuncP = LRReduce;
	parser->lrTable[34][33].actionParam = 84;
	//reduce
	parser->lrTable[47][33].LRTableFuncP = LRReduce;
	parser->lrTable[47][33].actionParam = 84;
	//reduce
	parser->lrTable[48][33].LRTableFuncP = LRReduce;
	parser->lrTable[48][33].actionParam = 84;
	//reduce
	parser->lrTable[56][33].LRTableFuncP = LRReduce;
	parser->lrTable[56][33].actionParam = 84;
	//reduce
	parser->lrTable[57][33].LRTableFuncP = LRReduce;
	parser->lrTable[57][33].actionParam = 84;
	//reduce
	parser->lrTable[58][33].LRTableFuncP = LRReduce;
	parser->lrTable[58][33].actionParam = 84;
	//reduce
	parser->lrTable[59][33].LRTableFuncP = LRReduce;
	parser->lrTable[59][33].actionParam = 84;
	//reduce
	parser->lrTable[30][33].LRTableFuncP = LRReduce;
	parser->lrTable[30][33].actionParam = 45;
	//reduce
	parser->lrTable[34][33].LRTableFuncP = LRReduce;
	parser->lrTable[34][33].actionParam = 45;
	//reduce
	parser->lrTable[56][33].LRTableFuncP = LRReduce;
	parser->lrTable[56][33].actionParam = 45;
	//reduce
	parser->lrTable[57][33].LRTableFuncP = LRReduce;
	parser->lrTable[57][33].actionParam = 45;
	//reduce
	parser->lrTable[59][33].LRTableFuncP = LRReduce;
	parser->lrTable[59][33].actionParam = 45;
	//reduce
	parser->lrTable[30][33].LRTableFuncP = LRReduce;
	parser->lrTable[30][33].actionParam = 100;
	//reduce
	parser->lrTable[57][33].LRTableFuncP = LRReduce;
	parser->lrTable[57][33].actionParam = 100;
	//shift
	parser->lrTable[30][33].LRTableFuncP = LRShift;
	parser->lrTable[30][33].actionParam = 127;
	//shift
	parser->lrTable[57][33].LRTableFuncP = LRShift;
	parser->lrTable[57][33].actionParam = 128;
	//reduce
	parser->lrTable[30][33].LRTableFuncP = LRReduce;
	parser->lrTable[30][33].actionParam = 99;
	//shift
	parser->lrTable[34][33].LRTableFuncP = LRShift;
	parser->lrTable[34][33].actionParam = 129;
	//shift
	parser->lrTable[57][33].LRTableFuncP = LRShift;
	parser->lrTable[57][33].actionParam = 58;
	//shift
	parser->lrTable[40][33].LRTableFuncP = LRShift;
	parser->lrTable[40][33].actionParam = 4;
	//shift
	parser->lrTable[41][33].LRTableFuncP = LRShift;
	parser->lrTable[41][33].actionParam = 5;
	//shift
	parser->lrTable[42][33].LRTableFuncP = LRShift;
	parser->lrTable[42][33].actionParam = 6;
	//shift
	parser->lrTable[43][33].LRTableFuncP = LRShift;
	parser->lrTable[43][33].actionParam = 7;
	//reduce
	parser->lrTable[4][33].LRTableFuncP = LRReduce;
	parser->lrTable[4][33].actionParam = 22;
	//reduce
	parser->lrTable[7][33].LRTableFuncP = LRReduce;
	parser->lrTable[7][33].actionParam = 22;
	//reduce
	parser->lrTable[8][33].LRTableFuncP = LRReduce;
	parser->lrTable[8][33].actionParam = 22;
	//reduce
	parser->lrTable[10][33].LRTableFuncP = LRReduce;
	parser->lrTable[10][33].actionParam = 22;
	//reduce
	parser->lrTable[11][33].LRTableFuncP = LRReduce;
	parser->lrTable[11][33].actionParam = 22;
	//reduce
	parser->lrTable[25][33].LRTableFuncP = LRReduce;
	parser->lrTable[25][33].actionParam = 22;
	//reduce
	parser->lrTable[29][33].LRTableFuncP = LRReduce;
	parser->lrTable[29][33].actionParam = 22;
	//reduce
	parser->lrTable[31][33].LRTableFuncP = LRReduce;
	parser->lrTable[31][33].actionParam = 22;
	//reduce
	parser->lrTable[32][33].LRTableFuncP = LRReduce;
	parser->lrTable[32][33].actionParam = 22;
	//reduce
	parser->lrTable[35][33].LRTableFuncP = LRReduce;
	parser->lrTable[35][33].actionParam = 22;
	//reduce
	parser->lrTable[36][33].LRTableFuncP = LRReduce;
	parser->lrTable[36][33].actionParam = 22;
	//reduce
	parser->lrTable[37][33].LRTableFuncP = LRReduce;
	parser->lrTable[37][33].actionParam = 22;
	//reduce
	parser->lrTable[38][33].LRTableFuncP = LRReduce;
	parser->lrTable[38][33].actionParam = 22;
	//reduce
	parser->lrTable[39][33].LRTableFuncP = LRReduce;
	parser->lrTable[39][33].actionParam = 22;
	//reduce
	parser->lrTable[44][33].LRTableFuncP = LRReduce;
	parser->lrTable[44][33].actionParam = 22;
	//reduce
	parser->lrTable[49][33].LRTableFuncP = LRReduce;
	parser->lrTable[49][33].actionParam = 22;
	//reduce
	parser->lrTable[50][33].LRTableFuncP = LRReduce;
	parser->lrTable[50][33].actionParam = 22;
	//reduce
	parser->lrTable[56][33].LRTableFuncP = LRReduce;
	parser->lrTable[56][33].actionParam = 22;
	//reduce
	parser->lrTable[51][33].LRTableFuncP = LRReduce;
	parser->lrTable[51][33].actionParam = 22;
	//goto
	parser->lrTable[type_specifier+TOTAL_TOKENS][33].LRTableFuncP = LRGoto;
	parser->lrTable[type_specifier+TOTAL_TOKENS][33].actionParam = 131;
	//reduce
	parser->lrTable[52][33].LRTableFuncP = LRReduce;
	parser->lrTable[52][33].actionParam = 15;
	//reduce
	parser->lrTable[40][33].LRTableFuncP = LRReduce;
	parser->lrTable[40][33].actionParam = 15;
	//reduce
	parser->lrTable[41][33].LRTableFuncP = LRReduce;
	parser->lrTable[41][33].actionParam = 15;
	//reduce
	parser->lrTable[42][33].LRTableFuncP = LRReduce;
	parser->lrTable[42][33].actionParam = 15;
	//reduce
	parser->lrTable[43][33].LRTableFuncP = LRReduce;
	parser->lrTable[43][33].actionParam = 15;
	//reduce
	parser->lrTable[30][33].LRTableFuncP = LRReduce;
	parser->lrTable[30][33].actionParam = 19;
	//reduce
	parser->lrTable[57][33].LRTableFuncP = LRReduce;
	parser->lrTable[57][33].actionParam = 19;
	//shift
	parser->lrTable[4][33].LRTableFuncP = LRShift;
	parser->lrTable[4][33].actionParam = 19;
	//shift
	parser->lrTable[7][33].LRTableFuncP = LRShift;
	parser->lrTable[7][33].actionParam = 20;
	//shift
	parser->lrTable[8][33].LRTableFuncP = LRShift;
	parser->lrTable[8][33].actionParam = 21;
	//shift
	parser->lrTable[10][33].LRTableFuncP = LRShift;
	parser->lrTable[10][33].actionParam = 22;
	//shift
	parser->lrTable[11][33].LRTableFuncP = LRShift;
	parser->lrTable[11][33].actionParam = 23;
	//shift
	parser->lrTable[25][33].LRTableFuncP = LRShift;
	parser->lrTable[25][33].actionParam = 24;
	//shift
	parser->lrTable[29][33].LRTableFuncP = LRShift;
	parser->lrTable[29][33].actionParam = 25;
	//shift
	parser->lrTable[35][33].LRTableFuncP = LRShift;
	parser->lrTable[35][33].actionParam = 26;
	//shift
	parser->lrTable[36][33].LRTableFuncP = LRShift;
	parser->lrTable[36][33].actionParam = 27;
	//shift
	parser->lrTable[37][33].LRTableFuncP = LRShift;
	parser->lrTable[37][33].actionParam = 28;
	//shift
	parser->lrTable[38][33].LRTableFuncP = LRShift;
	parser->lrTable[38][33].actionParam = 29;
	//shift
	parser->lrTable[39][33].LRTableFuncP = LRShift;
	parser->lrTable[39][33].actionParam = 30;
	//shift
	parser->lrTable[51][33].LRTableFuncP = LRShift;
	parser->lrTable[51][33].actionParam = 31;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][33].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][33].actionParam = 134;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][33].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][33].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][33].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][33].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][33].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][33].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][33].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][33].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][33].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][33].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][33].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][33].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][33].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][33].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][33].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][33].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][33].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][33].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][33].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][33].actionParam = 99;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][33].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][33].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][33].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][33].actionParam = 47;
	//reduce
	parser->lrTable[0][34].LRTableFuncP = LRReduce;
	parser->lrTable[0][34].actionParam = 94;
	//reduce
	parser->lrTable[1][34].LRTableFuncP = LRReduce;
	parser->lrTable[1][34].actionParam = 94;
	//reduce
	parser->lrTable[2][34].LRTableFuncP = LRReduce;
	parser->lrTable[2][34].actionParam = 94;
	//reduce
	parser->lrTable[3][34].LRTableFuncP = LRReduce;
	parser->lrTable[3][34].actionParam = 94;
	//reduce
	parser->lrTable[4][34].LRTableFuncP = LRReduce;
	parser->lrTable[4][34].actionParam = 94;
	//reduce
	parser->lrTable[2][34].LRTableFuncP = LRReduce;
	parser->lrTable[2][34].actionParam = 94;
	//reduce
	parser->lrTable[7][34].LRTableFuncP = LRReduce;
	parser->lrTable[7][34].actionParam = 94;
	//reduce
	parser->lrTable[8][34].LRTableFuncP = LRReduce;
	parser->lrTable[8][34].actionParam = 94;
	//reduce
	parser->lrTable[7][34].LRTableFuncP = LRReduce;
	parser->lrTable[7][34].actionParam = 94;
	//reduce
	parser->lrTable[10][34].LRTableFuncP = LRReduce;
	parser->lrTable[10][34].actionParam = 94;
	//reduce
	parser->lrTable[11][34].LRTableFuncP = LRReduce;
	parser->lrTable[11][34].actionParam = 94;
	//reduce
	parser->lrTable[10][34].LRTableFuncP = LRReduce;
	parser->lrTable[10][34].actionParam = 94;
	//reduce
	parser->lrTable[13][34].LRTableFuncP = LRReduce;
	parser->lrTable[13][34].actionParam = 94;
	//reduce
	parser->lrTable[13][34].LRTableFuncP = LRReduce;
	parser->lrTable[13][34].actionParam = 94;
	//reduce
	parser->lrTable[15][34].LRTableFuncP = LRReduce;
	parser->lrTable[15][34].actionParam = 94;
	//reduce
	parser->lrTable[15][34].LRTableFuncP = LRReduce;
	parser->lrTable[15][34].actionParam = 94;
	//reduce
	parser->lrTable[17][34].LRTableFuncP = LRReduce;
	parser->lrTable[17][34].actionParam = 94;
	//reduce
	parser->lrTable[17][34].LRTableFuncP = LRReduce;
	parser->lrTable[17][34].actionParam = 94;
	//reduce
	parser->lrTable[19][34].LRTableFuncP = LRReduce;
	parser->lrTable[19][34].actionParam = 94;
	//reduce
	parser->lrTable[20][34].LRTableFuncP = LRReduce;
	parser->lrTable[20][34].actionParam = 94;
	//reduce
	parser->lrTable[21][34].LRTableFuncP = LRReduce;
	parser->lrTable[21][34].actionParam = 94;
	//reduce
	parser->lrTable[21][34].LRTableFuncP = LRReduce;
	parser->lrTable[21][34].actionParam = 94;
	//reduce
	parser->lrTable[23][34].LRTableFuncP = LRReduce;
	parser->lrTable[23][34].actionParam = 94;
	//reduce
	parser->lrTable[23][34].LRTableFuncP = LRReduce;
	parser->lrTable[23][34].actionParam = 94;
	//reduce
	parser->lrTable[27][34].LRTableFuncP = LRReduce;
	parser->lrTable[27][34].actionParam = 94;
	//reduce
	parser->lrTable[28][34].LRTableFuncP = LRReduce;
	parser->lrTable[28][34].actionParam = 94;
	//reduce
	parser->lrTable[29][34].LRTableFuncP = LRReduce;
	parser->lrTable[29][34].actionParam = 94;
	//reduce
	parser->lrTable[30][34].LRTableFuncP = LRReduce;
	parser->lrTable[30][34].actionParam = 94;
	//reduce
	parser->lrTable[33][34].LRTableFuncP = LRReduce;
	parser->lrTable[33][34].actionParam = 94;
	//reduce
	parser->lrTable[34][34].LRTableFuncP = LRReduce;
	parser->lrTable[34][34].actionParam = 94;
	//reduce
	parser->lrTable[47][34].LRTableFuncP = LRReduce;
	parser->lrTable[47][34].actionParam = 94;
	//reduce
	parser->lrTable[48][34].LRTableFuncP = LRReduce;
	parser->lrTable[48][34].actionParam = 94;
	//reduce
	parser->lrTable[56][34].LRTableFuncP = LRReduce;
	parser->lrTable[56][34].actionParam = 94;
	//reduce
	parser->lrTable[57][34].LRTableFuncP = LRReduce;
	parser->lrTable[57][34].actionParam = 94;
	//reduce
	parser->lrTable[58][34].LRTableFuncP = LRReduce;
	parser->lrTable[58][34].actionParam = 94;
	//reduce
	parser->lrTable[59][34].LRTableFuncP = LRReduce;
	parser->lrTable[59][34].actionParam = 94;
	//shift
	parser->lrTable[4][34].LRTableFuncP = LRShift;
	parser->lrTable[4][34].actionParam = 19;
	//shift
	parser->lrTable[7][34].LRTableFuncP = LRShift;
	parser->lrTable[7][34].actionParam = 20;
	//shift
	parser->lrTable[8][34].LRTableFuncP = LRShift;
	parser->lrTable[8][34].actionParam = 21;
	//shift
	parser->lrTable[10][34].LRTableFuncP = LRShift;
	parser->lrTable[10][34].actionParam = 22;
	//shift
	parser->lrTable[11][34].LRTableFuncP = LRShift;
	parser->lrTable[11][34].actionParam = 23;
	//shift
	parser->lrTable[25][34].LRTableFuncP = LRShift;
	parser->lrTable[25][34].actionParam = 24;
	//shift
	parser->lrTable[29][34].LRTableFuncP = LRShift;
	parser->lrTable[29][34].actionParam = 25;
	//shift
	parser->lrTable[35][34].LRTableFuncP = LRShift;
	parser->lrTable[35][34].actionParam = 26;
	//shift
	parser->lrTable[36][34].LRTableFuncP = LRShift;
	parser->lrTable[36][34].actionParam = 27;
	//shift
	parser->lrTable[37][34].LRTableFuncP = LRShift;
	parser->lrTable[37][34].actionParam = 28;
	//shift
	parser->lrTable[38][34].LRTableFuncP = LRShift;
	parser->lrTable[38][34].actionParam = 29;
	//shift
	parser->lrTable[39][34].LRTableFuncP = LRShift;
	parser->lrTable[39][34].actionParam = 30;
	//shift
	parser->lrTable[51][34].LRTableFuncP = LRShift;
	parser->lrTable[51][34].actionParam = 31;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][34].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][34].actionParam = 135;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][34].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][34].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][34].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][34].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][34].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][34].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][34].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][34].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][34].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][34].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][34].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][34].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][34].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][34].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][34].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][34].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][34].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][34].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][34].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][34].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][34].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][34].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][34].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][34].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][34].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][34].actionParam = 47;
	//reduce
	parser->lrTable[0][35].LRTableFuncP = LRReduce;
	parser->lrTable[0][35].actionParam = 95;
	//reduce
	parser->lrTable[1][35].LRTableFuncP = LRReduce;
	parser->lrTable[1][35].actionParam = 95;
	//reduce
	parser->lrTable[2][35].LRTableFuncP = LRReduce;
	parser->lrTable[2][35].actionParam = 95;
	//reduce
	parser->lrTable[3][35].LRTableFuncP = LRReduce;
	parser->lrTable[3][35].actionParam = 95;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 95;
	//reduce
	parser->lrTable[2][35].LRTableFuncP = LRReduce;
	parser->lrTable[2][35].actionParam = 95;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 95;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 95;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 95;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 95;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 95;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 95;
	//reduce
	parser->lrTable[13][35].LRTableFuncP = LRReduce;
	parser->lrTable[13][35].actionParam = 95;
	//reduce
	parser->lrTable[13][35].LRTableFuncP = LRReduce;
	parser->lrTable[13][35].actionParam = 95;
	//reduce
	parser->lrTable[15][35].LRTableFuncP = LRReduce;
	parser->lrTable[15][35].actionParam = 95;
	//reduce
	parser->lrTable[15][35].LRTableFuncP = LRReduce;
	parser->lrTable[15][35].actionParam = 95;
	//reduce
	parser->lrTable[17][35].LRTableFuncP = LRReduce;
	parser->lrTable[17][35].actionParam = 95;
	//reduce
	parser->lrTable[17][35].LRTableFuncP = LRReduce;
	parser->lrTable[17][35].actionParam = 95;
	//reduce
	parser->lrTable[19][35].LRTableFuncP = LRReduce;
	parser->lrTable[19][35].actionParam = 95;
	//reduce
	parser->lrTable[20][35].LRTableFuncP = LRReduce;
	parser->lrTable[20][35].actionParam = 95;
	//reduce
	parser->lrTable[21][35].LRTableFuncP = LRReduce;
	parser->lrTable[21][35].actionParam = 95;
	//reduce
	parser->lrTable[21][35].LRTableFuncP = LRReduce;
	parser->lrTable[21][35].actionParam = 95;
	//reduce
	parser->lrTable[23][35].LRTableFuncP = LRReduce;
	parser->lrTable[23][35].actionParam = 95;
	//reduce
	parser->lrTable[23][35].LRTableFuncP = LRReduce;
	parser->lrTable[23][35].actionParam = 95;
	//reduce
	parser->lrTable[27][35].LRTableFuncP = LRReduce;
	parser->lrTable[27][35].actionParam = 95;
	//reduce
	parser->lrTable[28][35].LRTableFuncP = LRReduce;
	parser->lrTable[28][35].actionParam = 95;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 95;
	//reduce
	parser->lrTable[30][35].LRTableFuncP = LRReduce;
	parser->lrTable[30][35].actionParam = 95;
	//reduce
	parser->lrTable[33][35].LRTableFuncP = LRReduce;
	parser->lrTable[33][35].actionParam = 95;
	//reduce
	parser->lrTable[34][35].LRTableFuncP = LRReduce;
	parser->lrTable[34][35].actionParam = 95;
	//reduce
	parser->lrTable[47][35].LRTableFuncP = LRReduce;
	parser->lrTable[47][35].actionParam = 95;
	//reduce
	parser->lrTable[48][35].LRTableFuncP = LRReduce;
	parser->lrTable[48][35].actionParam = 95;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 95;
	//reduce
	parser->lrTable[57][35].LRTableFuncP = LRReduce;
	parser->lrTable[57][35].actionParam = 95;
	//reduce
	parser->lrTable[58][35].LRTableFuncP = LRReduce;
	parser->lrTable[58][35].actionParam = 95;
	//reduce
	parser->lrTable[59][35].LRTableFuncP = LRReduce;
	parser->lrTable[59][35].actionParam = 95;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 24;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 24;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 24;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 24;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 24;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 24;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 24;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 24;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 24;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 24;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 24;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 24;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 24;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 24;
	//reduce
	parser->lrTable[40][35].LRTableFuncP = LRReduce;
	parser->lrTable[40][35].actionParam = 24;
	//reduce
	parser->lrTable[41][35].LRTableFuncP = LRReduce;
	parser->lrTable[41][35].actionParam = 24;
	//reduce
	parser->lrTable[42][35].LRTableFuncP = LRReduce;
	parser->lrTable[42][35].actionParam = 24;
	//reduce
	parser->lrTable[43][35].LRTableFuncP = LRReduce;
	parser->lrTable[43][35].actionParam = 24;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 24;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 24;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 24;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 24;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 24;
	//shift
	parser->lrTable[51][35].LRTableFuncP = LRShift;
	parser->lrTable[51][35].actionParam = 53;
	//shift
	parser->lrTable[4][35].LRTableFuncP = LRShift;
	parser->lrTable[4][35].actionParam = 19;
	//shift
	parser->lrTable[7][35].LRTableFuncP = LRShift;
	parser->lrTable[7][35].actionParam = 20;
	//shift
	parser->lrTable[8][35].LRTableFuncP = LRShift;
	parser->lrTable[8][35].actionParam = 21;
	//shift
	parser->lrTable[10][35].LRTableFuncP = LRShift;
	parser->lrTable[10][35].actionParam = 22;
	//shift
	parser->lrTable[11][35].LRTableFuncP = LRShift;
	parser->lrTable[11][35].actionParam = 23;
	//shift
	parser->lrTable[25][35].LRTableFuncP = LRShift;
	parser->lrTable[25][35].actionParam = 24;
	//shift
	parser->lrTable[29][35].LRTableFuncP = LRShift;
	parser->lrTable[29][35].actionParam = 25;
	//shift
	parser->lrTable[31][35].LRTableFuncP = LRShift;
	parser->lrTable[31][35].actionParam = 123;
	//shift
	parser->lrTable[35][35].LRTableFuncP = LRShift;
	parser->lrTable[35][35].actionParam = 26;
	//shift
	parser->lrTable[36][35].LRTableFuncP = LRShift;
	parser->lrTable[36][35].actionParam = 27;
	//shift
	parser->lrTable[37][35].LRTableFuncP = LRShift;
	parser->lrTable[37][35].actionParam = 28;
	//shift
	parser->lrTable[38][35].LRTableFuncP = LRShift;
	parser->lrTable[38][35].actionParam = 29;
	//shift
	parser->lrTable[39][35].LRTableFuncP = LRShift;
	parser->lrTable[39][35].actionParam = 30;
	//shift
	parser->lrTable[44][35].LRTableFuncP = LRShift;
	parser->lrTable[44][35].actionParam = 136;
	//shift
	parser->lrTable[49][35].LRTableFuncP = LRShift;
	parser->lrTable[49][35].actionParam = 137;
	//shift
	parser->lrTable[50][35].LRTableFuncP = LRShift;
	parser->lrTable[50][35].actionParam = 138;
	//shift
	parser->lrTable[56][35].LRTableFuncP = LRShift;
	parser->lrTable[56][35].actionParam = 139;
	//shift
	parser->lrTable[51][35].LRTableFuncP = LRShift;
	parser->lrTable[51][35].actionParam = 31;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 26;
	//goto
	parser->lrTable[statement_list_opt+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[statement_list_opt+TOTAL_TOKENS][35].actionParam = 141;
	//goto
	parser->lrTable[statement_list+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[statement_list+TOTAL_TOKENS][35].actionParam = 142;
	//goto
	parser->lrTable[statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[statement+TOTAL_TOKENS][35].actionParam = 143;
	//goto
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].actionParam = 144;
	//goto
	parser->lrTable[selection_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[selection_statement+TOTAL_TOKENS][35].actionParam = 145;
	//goto
	parser->lrTable[iteration_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[iteration_statement+TOTAL_TOKENS][35].actionParam = 146;
	//goto
	parser->lrTable[expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression+TOTAL_TOKENS][35].actionParam = 147;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].actionParam = 33;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].actionParam = 47;
	//shift
	parser->lrTable[40][35].LRTableFuncP = LRShift;
	parser->lrTable[40][35].actionParam = 4;
	//shift
	parser->lrTable[41][35].LRTableFuncP = LRShift;
	parser->lrTable[41][35].actionParam = 5;
	//shift
	parser->lrTable[42][35].LRTableFuncP = LRShift;
	parser->lrTable[42][35].actionParam = 6;
	//shift
	parser->lrTable[43][35].LRTableFuncP = LRShift;
	parser->lrTable[43][35].actionParam = 7;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 23;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 23;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 23;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 23;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 23;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 23;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 23;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 23;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 23;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 23;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 23;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 23;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 23;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 23;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 23;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 23;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 23;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 23;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 23;
	//goto
	parser->lrTable[type_specifier+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[type_specifier+TOTAL_TOKENS][35].actionParam = 131;
	//reduce
	parser->lrTable[30][35].LRTableFuncP = LRReduce;
	parser->lrTable[30][35].actionParam = 56;
	//reduce
	parser->lrTable[34][35].LRTableFuncP = LRReduce;
	parser->lrTable[34][35].actionParam = 56;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 56;
	//reduce
	parser->lrTable[57][35].LRTableFuncP = LRReduce;
	parser->lrTable[57][35].actionParam = 56;
	//reduce
	parser->lrTable[59][35].LRTableFuncP = LRReduce;
	parser->lrTable[59][35].actionParam = 56;
	//reduce
	parser->lrTable[30][35].LRTableFuncP = LRReduce;
	parser->lrTable[30][35].actionParam = 101;
	//reduce
	parser->lrTable[57][35].LRTableFuncP = LRReduce;
	parser->lrTable[57][35].actionParam = 101;
	//shift
	parser->lrTable[29][35].LRTableFuncP = LRShift;
	parser->lrTable[29][35].actionParam = 149;
	//shift
	parser->lrTable[29][35].LRTableFuncP = LRShift;
	parser->lrTable[29][35].actionParam = 150;
	//shift
	parser->lrTable[29][35].LRTableFuncP = LRShift;
	parser->lrTable[29][35].actionParam = 151;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 35;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 35;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 35;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 35;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 35;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 35;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 35;
	//reduce
	parser->lrTable[30][35].LRTableFuncP = LRReduce;
	parser->lrTable[30][35].actionParam = 35;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 35;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 35;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 35;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 35;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 35;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 35;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 35;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 35;
	//reduce
	parser->lrTable[46][35].LRTableFuncP = LRReduce;
	parser->lrTable[46][35].actionParam = 35;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 35;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 35;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 35;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 35;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 31;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 31;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 31;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 31;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 31;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 31;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 31;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 31;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 31;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 31;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 31;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 31;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 31;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 31;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 31;
	//reduce
	parser->lrTable[46][35].LRTableFuncP = LRReduce;
	parser->lrTable[46][35].actionParam = 31;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 31;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 31;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 31;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 31;
	//shift
	parser->lrTable[32][35].LRTableFuncP = LRShift;
	parser->lrTable[32][35].actionParam = 152;
	//shift
	parser->lrTable[4][35].LRTableFuncP = LRShift;
	parser->lrTable[4][35].actionParam = 19;
	//shift
	parser->lrTable[7][35].LRTableFuncP = LRShift;
	parser->lrTable[7][35].actionParam = 20;
	//shift
	parser->lrTable[8][35].LRTableFuncP = LRShift;
	parser->lrTable[8][35].actionParam = 21;
	//shift
	parser->lrTable[10][35].LRTableFuncP = LRShift;
	parser->lrTable[10][35].actionParam = 22;
	//shift
	parser->lrTable[11][35].LRTableFuncP = LRShift;
	parser->lrTable[11][35].actionParam = 23;
	//shift
	parser->lrTable[25][35].LRTableFuncP = LRShift;
	parser->lrTable[25][35].actionParam = 24;
	//shift
	parser->lrTable[29][35].LRTableFuncP = LRShift;
	parser->lrTable[29][35].actionParam = 25;
	//shift
	parser->lrTable[31][35].LRTableFuncP = LRShift;
	parser->lrTable[31][35].actionParam = 123;
	//shift
	parser->lrTable[35][35].LRTableFuncP = LRShift;
	parser->lrTable[35][35].actionParam = 26;
	//shift
	parser->lrTable[36][35].LRTableFuncP = LRShift;
	parser->lrTable[36][35].actionParam = 27;
	//shift
	parser->lrTable[37][35].LRTableFuncP = LRShift;
	parser->lrTable[37][35].actionParam = 28;
	//shift
	parser->lrTable[38][35].LRTableFuncP = LRShift;
	parser->lrTable[38][35].actionParam = 29;
	//shift
	parser->lrTable[39][35].LRTableFuncP = LRShift;
	parser->lrTable[39][35].actionParam = 30;
	//shift
	parser->lrTable[44][35].LRTableFuncP = LRShift;
	parser->lrTable[44][35].actionParam = 136;
	//shift
	parser->lrTable[49][35].LRTableFuncP = LRShift;
	parser->lrTable[49][35].actionParam = 137;
	//shift
	parser->lrTable[50][35].LRTableFuncP = LRShift;
	parser->lrTable[50][35].actionParam = 138;
	//shift
	parser->lrTable[56][35].LRTableFuncP = LRShift;
	parser->lrTable[56][35].actionParam = 139;
	//shift
	parser->lrTable[51][35].LRTableFuncP = LRShift;
	parser->lrTable[51][35].actionParam = 31;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 27;
	//goto
	parser->lrTable[statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[statement+TOTAL_TOKENS][35].actionParam = 153;
	//goto
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].actionParam = 144;
	//goto
	parser->lrTable[selection_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[selection_statement+TOTAL_TOKENS][35].actionParam = 145;
	//goto
	parser->lrTable[iteration_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[iteration_statement+TOTAL_TOKENS][35].actionParam = 146;
	//goto
	parser->lrTable[expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression+TOTAL_TOKENS][35].actionParam = 147;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].actionParam = 33;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].actionParam = 47;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 28;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 28;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 28;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 28;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 28;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 28;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 28;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 28;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 28;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 28;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 28;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 28;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 28;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 28;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 28;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 28;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 28;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 28;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 28;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 30;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 30;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 30;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 30;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 30;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 30;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 30;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 30;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 30;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 30;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 30;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 30;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 30;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 30;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 30;
	//reduce
	parser->lrTable[46][35].LRTableFuncP = LRReduce;
	parser->lrTable[46][35].actionParam = 30;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 30;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 30;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 30;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 30;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 32;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 32;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 32;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 32;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 32;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 32;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 32;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 32;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 32;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 32;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 32;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 32;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 32;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 32;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 32;
	//reduce
	parser->lrTable[46][35].LRTableFuncP = LRReduce;
	parser->lrTable[46][35].actionParam = 32;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 32;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 32;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 32;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 32;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 33;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 33;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 33;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 33;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 33;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 33;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 33;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 33;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 33;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 33;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 33;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 33;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 33;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 33;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 33;
	//reduce
	parser->lrTable[46][35].LRTableFuncP = LRReduce;
	parser->lrTable[46][35].actionParam = 33;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 33;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 33;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 33;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 33;
	//shift
	parser->lrTable[56][35].LRTableFuncP = LRShift;
	parser->lrTable[56][35].actionParam = 154;
	//shift
	parser->lrTable[57][35].LRTableFuncP = LRShift;
	parser->lrTable[57][35].actionParam = 58;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 25;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 25;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 25;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 25;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 25;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 25;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 25;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 25;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 25;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 25;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 25;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 25;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 25;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 25;
	//reduce
	parser->lrTable[40][35].LRTableFuncP = LRReduce;
	parser->lrTable[40][35].actionParam = 25;
	//reduce
	parser->lrTable[41][35].LRTableFuncP = LRReduce;
	parser->lrTable[41][35].actionParam = 25;
	//reduce
	parser->lrTable[42][35].LRTableFuncP = LRReduce;
	parser->lrTable[42][35].actionParam = 25;
	//reduce
	parser->lrTable[43][35].LRTableFuncP = LRReduce;
	parser->lrTable[43][35].actionParam = 25;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 25;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 25;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 25;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 25;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 25;
	//shift
	parser->lrTable[4][35].LRTableFuncP = LRShift;
	parser->lrTable[4][35].actionParam = 19;
	//shift
	parser->lrTable[7][35].LRTableFuncP = LRShift;
	parser->lrTable[7][35].actionParam = 20;
	//shift
	parser->lrTable[8][35].LRTableFuncP = LRShift;
	parser->lrTable[8][35].actionParam = 21;
	//shift
	parser->lrTable[10][35].LRTableFuncP = LRShift;
	parser->lrTable[10][35].actionParam = 22;
	//shift
	parser->lrTable[11][35].LRTableFuncP = LRShift;
	parser->lrTable[11][35].actionParam = 23;
	//shift
	parser->lrTable[25][35].LRTableFuncP = LRShift;
	parser->lrTable[25][35].actionParam = 24;
	//shift
	parser->lrTable[29][35].LRTableFuncP = LRShift;
	parser->lrTable[29][35].actionParam = 25;
	//shift
	parser->lrTable[35][35].LRTableFuncP = LRShift;
	parser->lrTable[35][35].actionParam = 26;
	//shift
	parser->lrTable[36][35].LRTableFuncP = LRShift;
	parser->lrTable[36][35].actionParam = 27;
	//shift
	parser->lrTable[37][35].LRTableFuncP = LRShift;
	parser->lrTable[37][35].actionParam = 28;
	//shift
	parser->lrTable[38][35].LRTableFuncP = LRShift;
	parser->lrTable[38][35].actionParam = 29;
	//shift
	parser->lrTable[39][35].LRTableFuncP = LRShift;
	parser->lrTable[39][35].actionParam = 30;
	//shift
	parser->lrTable[51][35].LRTableFuncP = LRShift;
	parser->lrTable[51][35].actionParam = 31;
	//goto
	parser->lrTable[expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression+TOTAL_TOKENS][35].actionParam = 155;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].actionParam = 33;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].actionParam = 47;
	//shift
	parser->lrTable[4][35].LRTableFuncP = LRShift;
	parser->lrTable[4][35].actionParam = 19;
	//shift
	parser->lrTable[7][35].LRTableFuncP = LRShift;
	parser->lrTable[7][35].actionParam = 20;
	//shift
	parser->lrTable[8][35].LRTableFuncP = LRShift;
	parser->lrTable[8][35].actionParam = 21;
	//shift
	parser->lrTable[10][35].LRTableFuncP = LRShift;
	parser->lrTable[10][35].actionParam = 22;
	//shift
	parser->lrTable[11][35].LRTableFuncP = LRShift;
	parser->lrTable[11][35].actionParam = 23;
	//shift
	parser->lrTable[25][35].LRTableFuncP = LRShift;
	parser->lrTable[25][35].actionParam = 24;
	//shift
	parser->lrTable[29][35].LRTableFuncP = LRShift;
	parser->lrTable[29][35].actionParam = 25;
	//shift
	parser->lrTable[35][35].LRTableFuncP = LRShift;
	parser->lrTable[35][35].actionParam = 26;
	//shift
	parser->lrTable[36][35].LRTableFuncP = LRShift;
	parser->lrTable[36][35].actionParam = 27;
	//shift
	parser->lrTable[37][35].LRTableFuncP = LRShift;
	parser->lrTable[37][35].actionParam = 28;
	//shift
	parser->lrTable[38][35].LRTableFuncP = LRShift;
	parser->lrTable[38][35].actionParam = 29;
	//shift
	parser->lrTable[39][35].LRTableFuncP = LRShift;
	parser->lrTable[39][35].actionParam = 30;
	//shift
	parser->lrTable[56][35].LRTableFuncP = LRShift;
	parser->lrTable[56][35].actionParam = 139;
	//shift
	parser->lrTable[51][35].LRTableFuncP = LRShift;
	parser->lrTable[51][35].actionParam = 31;
	//goto
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].actionParam = 156;
	//goto
	parser->lrTable[expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression+TOTAL_TOKENS][35].actionParam = 147;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].actionParam = 33;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].actionParam = 47;
	//shift
	parser->lrTable[4][35].LRTableFuncP = LRShift;
	parser->lrTable[4][35].actionParam = 19;
	//shift
	parser->lrTable[7][35].LRTableFuncP = LRShift;
	parser->lrTable[7][35].actionParam = 20;
	//shift
	parser->lrTable[8][35].LRTableFuncP = LRShift;
	parser->lrTable[8][35].actionParam = 21;
	//shift
	parser->lrTable[10][35].LRTableFuncP = LRShift;
	parser->lrTable[10][35].actionParam = 22;
	//shift
	parser->lrTable[11][35].LRTableFuncP = LRShift;
	parser->lrTable[11][35].actionParam = 23;
	//shift
	parser->lrTable[25][35].LRTableFuncP = LRShift;
	parser->lrTable[25][35].actionParam = 24;
	//shift
	parser->lrTable[29][35].LRTableFuncP = LRShift;
	parser->lrTable[29][35].actionParam = 25;
	//shift
	parser->lrTable[35][35].LRTableFuncP = LRShift;
	parser->lrTable[35][35].actionParam = 26;
	//shift
	parser->lrTable[36][35].LRTableFuncP = LRShift;
	parser->lrTable[36][35].actionParam = 27;
	//shift
	parser->lrTable[37][35].LRTableFuncP = LRShift;
	parser->lrTable[37][35].actionParam = 28;
	//shift
	parser->lrTable[38][35].LRTableFuncP = LRShift;
	parser->lrTable[38][35].actionParam = 29;
	//shift
	parser->lrTable[39][35].LRTableFuncP = LRShift;
	parser->lrTable[39][35].actionParam = 30;
	//shift
	parser->lrTable[51][35].LRTableFuncP = LRShift;
	parser->lrTable[51][35].actionParam = 31;
	//goto
	parser->lrTable[expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression+TOTAL_TOKENS][35].actionParam = 157;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].actionParam = 33;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].actionParam = 47;
	//reduce
	parser->lrTable[52][35].LRTableFuncP = LRReduce;
	parser->lrTable[52][35].actionParam = 21;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 21;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 21;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 21;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 21;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 21;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 21;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 21;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 21;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 21;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 21;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 21;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 21;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 21;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 21;
	//reduce
	parser->lrTable[40][35].LRTableFuncP = LRReduce;
	parser->lrTable[40][35].actionParam = 21;
	//reduce
	parser->lrTable[41][35].LRTableFuncP = LRReduce;
	parser->lrTable[41][35].actionParam = 21;
	//reduce
	parser->lrTable[42][35].LRTableFuncP = LRReduce;
	parser->lrTable[42][35].actionParam = 21;
	//reduce
	parser->lrTable[43][35].LRTableFuncP = LRReduce;
	parser->lrTable[43][35].actionParam = 21;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 21;
	//reduce
	parser->lrTable[46][35].LRTableFuncP = LRReduce;
	parser->lrTable[46][35].actionParam = 21;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 21;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 21;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 21;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 21;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 29;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 29;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 29;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 29;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 29;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 29;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 29;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 29;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 29;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 29;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 29;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 29;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 29;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 29;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 29;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 29;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 29;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 29;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 29;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 34;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 34;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 34;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 34;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 34;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 34;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 34;
	//reduce
	parser->lrTable[30][35].LRTableFuncP = LRReduce;
	parser->lrTable[30][35].actionParam = 34;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 34;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 34;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 34;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 34;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 34;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 34;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 34;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 34;
	//reduce
	parser->lrTable[46][35].LRTableFuncP = LRReduce;
	parser->lrTable[46][35].actionParam = 34;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 34;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 34;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 34;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 34;
	//shift
	parser->lrTable[30][35].LRTableFuncP = LRShift;
	parser->lrTable[30][35].actionParam = 158;
	//shift
	parser->lrTable[57][35].LRTableFuncP = LRShift;
	parser->lrTable[57][35].actionParam = 58;
	//shift
	parser->lrTable[4][35].LRTableFuncP = LRShift;
	parser->lrTable[4][35].actionParam = 19;
	//shift
	parser->lrTable[7][35].LRTableFuncP = LRShift;
	parser->lrTable[7][35].actionParam = 20;
	//shift
	parser->lrTable[8][35].LRTableFuncP = LRShift;
	parser->lrTable[8][35].actionParam = 21;
	//shift
	parser->lrTable[10][35].LRTableFuncP = LRShift;
	parser->lrTable[10][35].actionParam = 22;
	//shift
	parser->lrTable[11][35].LRTableFuncP = LRShift;
	parser->lrTable[11][35].actionParam = 23;
	//shift
	parser->lrTable[25][35].LRTableFuncP = LRShift;
	parser->lrTable[25][35].actionParam = 24;
	//shift
	parser->lrTable[29][35].LRTableFuncP = LRShift;
	parser->lrTable[29][35].actionParam = 25;
	//shift
	parser->lrTable[35][35].LRTableFuncP = LRShift;
	parser->lrTable[35][35].actionParam = 26;
	//shift
	parser->lrTable[36][35].LRTableFuncP = LRShift;
	parser->lrTable[36][35].actionParam = 27;
	//shift
	parser->lrTable[37][35].LRTableFuncP = LRShift;
	parser->lrTable[37][35].actionParam = 28;
	//shift
	parser->lrTable[38][35].LRTableFuncP = LRShift;
	parser->lrTable[38][35].actionParam = 29;
	//shift
	parser->lrTable[39][35].LRTableFuncP = LRShift;
	parser->lrTable[39][35].actionParam = 30;
	//shift
	parser->lrTable[56][35].LRTableFuncP = LRShift;
	parser->lrTable[56][35].actionParam = 139;
	//shift
	parser->lrTable[51][35].LRTableFuncP = LRShift;
	parser->lrTable[51][35].actionParam = 31;
	//goto
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].actionParam = 159;
	//goto
	parser->lrTable[expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression+TOTAL_TOKENS][35].actionParam = 147;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].actionParam = 33;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].actionParam = 47;
	//shift
	parser->lrTable[30][35].LRTableFuncP = LRShift;
	parser->lrTable[30][35].actionParam = 160;
	//shift
	parser->lrTable[57][35].LRTableFuncP = LRShift;
	parser->lrTable[57][35].actionParam = 58;
	//shift
	parser->lrTable[4][35].LRTableFuncP = LRShift;
	parser->lrTable[4][35].actionParam = 19;
	//shift
	parser->lrTable[7][35].LRTableFuncP = LRShift;
	parser->lrTable[7][35].actionParam = 20;
	//shift
	parser->lrTable[8][35].LRTableFuncP = LRShift;
	parser->lrTable[8][35].actionParam = 21;
	//shift
	parser->lrTable[10][35].LRTableFuncP = LRShift;
	parser->lrTable[10][35].actionParam = 22;
	//shift
	parser->lrTable[11][35].LRTableFuncP = LRShift;
	parser->lrTable[11][35].actionParam = 23;
	//shift
	parser->lrTable[25][35].LRTableFuncP = LRShift;
	parser->lrTable[25][35].actionParam = 24;
	//shift
	parser->lrTable[29][35].LRTableFuncP = LRShift;
	parser->lrTable[29][35].actionParam = 25;
	//shift
	parser->lrTable[31][35].LRTableFuncP = LRShift;
	parser->lrTable[31][35].actionParam = 123;
	//shift
	parser->lrTable[35][35].LRTableFuncP = LRShift;
	parser->lrTable[35][35].actionParam = 26;
	//shift
	parser->lrTable[36][35].LRTableFuncP = LRShift;
	parser->lrTable[36][35].actionParam = 27;
	//shift
	parser->lrTable[37][35].LRTableFuncP = LRShift;
	parser->lrTable[37][35].actionParam = 28;
	//shift
	parser->lrTable[38][35].LRTableFuncP = LRShift;
	parser->lrTable[38][35].actionParam = 29;
	//shift
	parser->lrTable[39][35].LRTableFuncP = LRShift;
	parser->lrTable[39][35].actionParam = 30;
	//shift
	parser->lrTable[44][35].LRTableFuncP = LRShift;
	parser->lrTable[44][35].actionParam = 136;
	//shift
	parser->lrTable[49][35].LRTableFuncP = LRShift;
	parser->lrTable[49][35].actionParam = 137;
	//shift
	parser->lrTable[50][35].LRTableFuncP = LRShift;
	parser->lrTable[50][35].actionParam = 138;
	//shift
	parser->lrTable[56][35].LRTableFuncP = LRShift;
	parser->lrTable[56][35].actionParam = 139;
	//shift
	parser->lrTable[51][35].LRTableFuncP = LRShift;
	parser->lrTable[51][35].actionParam = 31;
	//goto
	parser->lrTable[statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[statement+TOTAL_TOKENS][35].actionParam = 161;
	//goto
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].actionParam = 144;
	//goto
	parser->lrTable[selection_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[selection_statement+TOTAL_TOKENS][35].actionParam = 145;
	//goto
	parser->lrTable[iteration_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[iteration_statement+TOTAL_TOKENS][35].actionParam = 146;
	//goto
	parser->lrTable[expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression+TOTAL_TOKENS][35].actionParam = 147;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].actionParam = 33;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].actionParam = 47;
	//shift
	parser->lrTable[4][35].LRTableFuncP = LRShift;
	parser->lrTable[4][35].actionParam = 19;
	//shift
	parser->lrTable[7][35].LRTableFuncP = LRShift;
	parser->lrTable[7][35].actionParam = 20;
	//shift
	parser->lrTable[8][35].LRTableFuncP = LRShift;
	parser->lrTable[8][35].actionParam = 21;
	//shift
	parser->lrTable[10][35].LRTableFuncP = LRShift;
	parser->lrTable[10][35].actionParam = 22;
	//shift
	parser->lrTable[11][35].LRTableFuncP = LRShift;
	parser->lrTable[11][35].actionParam = 23;
	//shift
	parser->lrTable[25][35].LRTableFuncP = LRShift;
	parser->lrTable[25][35].actionParam = 24;
	//shift
	parser->lrTable[29][35].LRTableFuncP = LRShift;
	parser->lrTable[29][35].actionParam = 25;
	//shift
	parser->lrTable[35][35].LRTableFuncP = LRShift;
	parser->lrTable[35][35].actionParam = 26;
	//shift
	parser->lrTable[36][35].LRTableFuncP = LRShift;
	parser->lrTable[36][35].actionParam = 27;
	//shift
	parser->lrTable[37][35].LRTableFuncP = LRShift;
	parser->lrTable[37][35].actionParam = 28;
	//shift
	parser->lrTable[38][35].LRTableFuncP = LRShift;
	parser->lrTable[38][35].actionParam = 29;
	//shift
	parser->lrTable[39][35].LRTableFuncP = LRShift;
	parser->lrTable[39][35].actionParam = 30;
	//shift
	parser->lrTable[51][35].LRTableFuncP = LRShift;
	parser->lrTable[51][35].actionParam = 31;
	//reduce
	parser->lrTable[30][35].LRTableFuncP = LRReduce;
	parser->lrTable[30][35].actionParam = 40;
	//goto
	parser->lrTable[expression_opt+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression_opt+TOTAL_TOKENS][35].actionParam = 162;
	//goto
	parser->lrTable[expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression+TOTAL_TOKENS][35].actionParam = 163;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].actionParam = 33;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].actionParam = 47;
	//shift
	parser->lrTable[4][35].LRTableFuncP = LRShift;
	parser->lrTable[4][35].actionParam = 19;
	//shift
	parser->lrTable[7][35].LRTableFuncP = LRShift;
	parser->lrTable[7][35].actionParam = 20;
	//shift
	parser->lrTable[8][35].LRTableFuncP = LRShift;
	parser->lrTable[8][35].actionParam = 21;
	//shift
	parser->lrTable[10][35].LRTableFuncP = LRShift;
	parser->lrTable[10][35].actionParam = 22;
	//shift
	parser->lrTable[11][35].LRTableFuncP = LRShift;
	parser->lrTable[11][35].actionParam = 23;
	//shift
	parser->lrTable[25][35].LRTableFuncP = LRShift;
	parser->lrTable[25][35].actionParam = 24;
	//shift
	parser->lrTable[29][35].LRTableFuncP = LRShift;
	parser->lrTable[29][35].actionParam = 25;
	//shift
	parser->lrTable[31][35].LRTableFuncP = LRShift;
	parser->lrTable[31][35].actionParam = 123;
	//shift
	parser->lrTable[35][35].LRTableFuncP = LRShift;
	parser->lrTable[35][35].actionParam = 26;
	//shift
	parser->lrTable[36][35].LRTableFuncP = LRShift;
	parser->lrTable[36][35].actionParam = 27;
	//shift
	parser->lrTable[37][35].LRTableFuncP = LRShift;
	parser->lrTable[37][35].actionParam = 28;
	//shift
	parser->lrTable[38][35].LRTableFuncP = LRShift;
	parser->lrTable[38][35].actionParam = 29;
	//shift
	parser->lrTable[39][35].LRTableFuncP = LRShift;
	parser->lrTable[39][35].actionParam = 30;
	//shift
	parser->lrTable[44][35].LRTableFuncP = LRShift;
	parser->lrTable[44][35].actionParam = 136;
	//shift
	parser->lrTable[49][35].LRTableFuncP = LRShift;
	parser->lrTable[49][35].actionParam = 137;
	//shift
	parser->lrTable[50][35].LRTableFuncP = LRShift;
	parser->lrTable[50][35].actionParam = 138;
	//shift
	parser->lrTable[56][35].LRTableFuncP = LRShift;
	parser->lrTable[56][35].actionParam = 139;
	//shift
	parser->lrTable[51][35].LRTableFuncP = LRShift;
	parser->lrTable[51][35].actionParam = 31;
	//goto
	parser->lrTable[statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[statement+TOTAL_TOKENS][35].actionParam = 164;
	//goto
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].actionParam = 144;
	//goto
	parser->lrTable[selection_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[selection_statement+TOTAL_TOKENS][35].actionParam = 145;
	//goto
	parser->lrTable[iteration_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[iteration_statement+TOTAL_TOKENS][35].actionParam = 146;
	//goto
	parser->lrTable[expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression+TOTAL_TOKENS][35].actionParam = 147;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].actionParam = 33;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].actionParam = 47;
	//shift
	parser->lrTable[46][35].LRTableFuncP = LRShift;
	parser->lrTable[46][35].actionParam = 165;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 36;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 36;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 36;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 36;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 36;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 36;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 36;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 36;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 36;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 36;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 36;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 36;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 36;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 36;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 36;
	//reduce
	parser->lrTable[46][35].LRTableFuncP = LRReduce;
	parser->lrTable[46][35].actionParam = 36;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 36;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 36;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 36;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 36;
	//shift
	parser->lrTable[30][35].LRTableFuncP = LRShift;
	parser->lrTable[30][35].actionParam = 166;
	//shift
	parser->lrTable[57][35].LRTableFuncP = LRShift;
	parser->lrTable[57][35].actionParam = 58;
	//reduce
	parser->lrTable[30][35].LRTableFuncP = LRReduce;
	parser->lrTable[30][35].actionParam = 41;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 38;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 38;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 38;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 38;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 38;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 38;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 38;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 38;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 38;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 38;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 38;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 38;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 38;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 38;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 38;
	//reduce
	parser->lrTable[46][35].LRTableFuncP = LRReduce;
	parser->lrTable[46][35].actionParam = 38;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 38;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 38;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 38;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 38;
	//shift
	parser->lrTable[4][35].LRTableFuncP = LRShift;
	parser->lrTable[4][35].actionParam = 19;
	//shift
	parser->lrTable[7][35].LRTableFuncP = LRShift;
	parser->lrTable[7][35].actionParam = 20;
	//shift
	parser->lrTable[8][35].LRTableFuncP = LRShift;
	parser->lrTable[8][35].actionParam = 21;
	//shift
	parser->lrTable[10][35].LRTableFuncP = LRShift;
	parser->lrTable[10][35].actionParam = 22;
	//shift
	parser->lrTable[11][35].LRTableFuncP = LRShift;
	parser->lrTable[11][35].actionParam = 23;
	//shift
	parser->lrTable[25][35].LRTableFuncP = LRShift;
	parser->lrTable[25][35].actionParam = 24;
	//shift
	parser->lrTable[29][35].LRTableFuncP = LRShift;
	parser->lrTable[29][35].actionParam = 25;
	//shift
	parser->lrTable[31][35].LRTableFuncP = LRShift;
	parser->lrTable[31][35].actionParam = 123;
	//shift
	parser->lrTable[35][35].LRTableFuncP = LRShift;
	parser->lrTable[35][35].actionParam = 26;
	//shift
	parser->lrTable[36][35].LRTableFuncP = LRShift;
	parser->lrTable[36][35].actionParam = 27;
	//shift
	parser->lrTable[37][35].LRTableFuncP = LRShift;
	parser->lrTable[37][35].actionParam = 28;
	//shift
	parser->lrTable[38][35].LRTableFuncP = LRShift;
	parser->lrTable[38][35].actionParam = 29;
	//shift
	parser->lrTable[39][35].LRTableFuncP = LRShift;
	parser->lrTable[39][35].actionParam = 30;
	//shift
	parser->lrTable[44][35].LRTableFuncP = LRShift;
	parser->lrTable[44][35].actionParam = 136;
	//shift
	parser->lrTable[49][35].LRTableFuncP = LRShift;
	parser->lrTable[49][35].actionParam = 137;
	//shift
	parser->lrTable[50][35].LRTableFuncP = LRShift;
	parser->lrTable[50][35].actionParam = 138;
	//shift
	parser->lrTable[56][35].LRTableFuncP = LRShift;
	parser->lrTable[56][35].actionParam = 139;
	//shift
	parser->lrTable[51][35].LRTableFuncP = LRShift;
	parser->lrTable[51][35].actionParam = 31;
	//goto
	parser->lrTable[statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[statement+TOTAL_TOKENS][35].actionParam = 167;
	//goto
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].actionParam = 144;
	//goto
	parser->lrTable[selection_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[selection_statement+TOTAL_TOKENS][35].actionParam = 145;
	//goto
	parser->lrTable[iteration_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[iteration_statement+TOTAL_TOKENS][35].actionParam = 146;
	//goto
	parser->lrTable[expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression+TOTAL_TOKENS][35].actionParam = 147;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].actionParam = 33;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].actionParam = 47;
	//shift
	parser->lrTable[4][35].LRTableFuncP = LRShift;
	parser->lrTable[4][35].actionParam = 19;
	//shift
	parser->lrTable[7][35].LRTableFuncP = LRShift;
	parser->lrTable[7][35].actionParam = 20;
	//shift
	parser->lrTable[8][35].LRTableFuncP = LRShift;
	parser->lrTable[8][35].actionParam = 21;
	//shift
	parser->lrTable[10][35].LRTableFuncP = LRShift;
	parser->lrTable[10][35].actionParam = 22;
	//shift
	parser->lrTable[11][35].LRTableFuncP = LRShift;
	parser->lrTable[11][35].actionParam = 23;
	//shift
	parser->lrTable[25][35].LRTableFuncP = LRShift;
	parser->lrTable[25][35].actionParam = 24;
	//shift
	parser->lrTable[29][35].LRTableFuncP = LRShift;
	parser->lrTable[29][35].actionParam = 25;
	//shift
	parser->lrTable[31][35].LRTableFuncP = LRShift;
	parser->lrTable[31][35].actionParam = 123;
	//shift
	parser->lrTable[35][35].LRTableFuncP = LRShift;
	parser->lrTable[35][35].actionParam = 26;
	//shift
	parser->lrTable[36][35].LRTableFuncP = LRShift;
	parser->lrTable[36][35].actionParam = 27;
	//shift
	parser->lrTable[37][35].LRTableFuncP = LRShift;
	parser->lrTable[37][35].actionParam = 28;
	//shift
	parser->lrTable[38][35].LRTableFuncP = LRShift;
	parser->lrTable[38][35].actionParam = 29;
	//shift
	parser->lrTable[39][35].LRTableFuncP = LRShift;
	parser->lrTable[39][35].actionParam = 30;
	//shift
	parser->lrTable[44][35].LRTableFuncP = LRShift;
	parser->lrTable[44][35].actionParam = 136;
	//shift
	parser->lrTable[49][35].LRTableFuncP = LRShift;
	parser->lrTable[49][35].actionParam = 137;
	//shift
	parser->lrTable[50][35].LRTableFuncP = LRShift;
	parser->lrTable[50][35].actionParam = 138;
	//shift
	parser->lrTable[56][35].LRTableFuncP = LRShift;
	parser->lrTable[56][35].actionParam = 139;
	//shift
	parser->lrTable[51][35].LRTableFuncP = LRShift;
	parser->lrTable[51][35].actionParam = 31;
	//goto
	parser->lrTable[statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[statement+TOTAL_TOKENS][35].actionParam = 168;
	//goto
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression_statement+TOTAL_TOKENS][35].actionParam = 144;
	//goto
	parser->lrTable[selection_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[selection_statement+TOTAL_TOKENS][35].actionParam = 145;
	//goto
	parser->lrTable[iteration_statement+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[iteration_statement+TOTAL_TOKENS][35].actionParam = 146;
	//goto
	parser->lrTable[expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[expression+TOTAL_TOKENS][35].actionParam = 147;
	//goto
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[assignment_expression+TOTAL_TOKENS][35].actionParam = 33;
	//goto
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[conditional_expression+TOTAL_TOKENS][35].actionParam = 34;
	//goto
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_or_expression+TOTAL_TOKENS][35].actionParam = 35;
	//goto
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[logical_and_expression+TOTAL_TOKENS][35].actionParam = 36;
	//goto
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_or_expression+TOTAL_TOKENS][35].actionParam = 37;
	//goto
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_xor_expression+TOTAL_TOKENS][35].actionParam = 38;
	//goto
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[bitwise_and_expression+TOTAL_TOKENS][35].actionParam = 39;
	//goto
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[equality_expression+TOTAL_TOKENS][35].actionParam = 40;
	//goto
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[relational_expression+TOTAL_TOKENS][35].actionParam = 41;
	//goto
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[additive_expression+TOTAL_TOKENS][35].actionParam = 43;
	//goto
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[multiplicative_expression+TOTAL_TOKENS][35].actionParam = 44;
	//goto
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_expression+TOTAL_TOKENS][35].actionParam = 45;
	//goto
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[unary_operator+TOTAL_TOKENS][35].actionParam = 46;
	//goto
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[postfix_expression+TOTAL_TOKENS][35].actionParam = 47;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 37;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 37;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 37;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 37;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 37;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 37;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 37;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 37;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 37;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 37;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 37;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 37;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 37;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 37;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 37;
	//reduce
	parser->lrTable[46][35].LRTableFuncP = LRReduce;
	parser->lrTable[46][35].actionParam = 37;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 37;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 37;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 37;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 37;
	//reduce
	parser->lrTable[4][35].LRTableFuncP = LRReduce;
	parser->lrTable[4][35].actionParam = 39;
	//reduce
	parser->lrTable[7][35].LRTableFuncP = LRReduce;
	parser->lrTable[7][35].actionParam = 39;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 39;
	//reduce
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 39;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 39;
	//reduce
	parser->lrTable[25][35].LRTableFuncP = LRReduce;
	parser->lrTable[25][35].actionParam = 39;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 39;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 39;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 39;
	//reduce
	parser->lrTable[35][35].LRTableFuncP = LRReduce;
	parser->lrTable[35][35].actionParam = 39;
	//reduce
	parser->lrTable[36][35].LRTableFuncP = LRReduce;
	parser->lrTable[36][35].actionParam = 39;
	//reduce
	parser->lrTable[37][35].LRTableFuncP = LRReduce;
	parser->lrTable[37][35].actionParam = 39;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 39;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 39;
	//reduce
	parser->lrTable[44][35].LRTableFuncP = LRReduce;
	parser->lrTable[44][35].actionParam = 39;
	//reduce
	parser->lrTable[46][35].LRTableFuncP = LRReduce;
	parser->lrTable[46][35].actionParam = 39;
	//reduce
	parser->lrTable[49][35].LRTableFuncP = LRReduce;
	parser->lrTable[49][35].actionParam = 39;
	//reduce
	parser->lrTable[50][35].LRTableFuncP = LRReduce;
	parser->lrTable[50][35].actionParam = 39;
	//reduce
	parser->lrTable[56][35].LRTableFuncP = LRReduce;
	parser->lrTable[56][35].actionParam = 39;
	//reduce
	parser->lrTable[51][35].LRTableFuncP = LRReduce;
	parser->lrTable[51][35].actionParam = 39;
}