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
    ReduceGeneric(parser, PROGRAM, reduceBy);
}
void ReduceToStart(Parser* parser,int reduceBy){
    ReduceGeneric(parser, Start, reduceBy);
}
void ReduceToStmtList(Parser* parser,int reduceBy){
    ReduceGeneric(parser, StmtList, reduceBy);
}
void ReduceToStmt(Parser* parser,int reduceBy){
    ReduceGeneric(parser, Stmt, reduceBy);
}
void ReduceToDecl(Parser* parser,int reduceBy){
    ReduceGeneric(parser, Decl, reduceBy);
}
void ReduceToAssi(Parser* parser,int reduceBy){
    ReduceGeneric(parser, Assi, reduceBy);
}
void ReduceToExpr(Parser* parser,int reduceBy){
    ReduceGeneric(parser, Expr, reduceBy);
}
void ReduceToTerm(Parser* parser,int reduceBy){
    ReduceGeneric(parser, Term, reduceBy);
}
void ReduceToFactor(Parser* parser,int reduceBy){
    ReduceGeneric(parser, Factor, reduceBy);
}
void ReduceToCondExpr(Parser* parser,int reduceBy){
    ReduceGeneric(parser, CondExpr, reduceBy);
}
void ReduceToRelOp(Parser* parser,int reduceBy){
    ReduceGeneric(parser, RelOp, reduceBy);
}
void ReduceToIfStmt(Parser* parser,int reduceBy){
    ReduceGeneric(parser, IfStmt, reduceBy);
}
void ReduceToLoopStmt(Parser* parser,int reduceBy){
    ReduceGeneric(parser, LoopStmt, reduceBy);
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
	return;
	return;
	return;
	return;
	return;
	return;
	return;
	return;
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


void LRError(Parser* parser, int __unused actionParam){
   parser->action = ACTION_ERROR;
   printTree(parser->treeHead);
   printParsingStep(parser);
   printf("\n\033[1;31mParsing error found in line: %d, at column: %d\033[0m\n", parser->lexer->tokens[parser->tokenId].row, parser->lexer->tokens[parser->tokenId].col);
   exit(1);
}

void LRAccept(Parser* parser, __unused int actionParam){
    parser->action = ACTION_ACCEPT;
    parser->treeHead = popStackCount(parser->stack, 4).data.treeNode;
    printTree(parser->treeHead);
    printf("\n\033[1;32mparser accepted!\033[0m\n\n");
    //TODO
}




//WARNING A MONSTER OF A FUNCTION BELOW OVER 2000 LINES OF CODE
void initParserLRTable(Parser* parser){
		for (int i = 0; i < TOTAL_TOKENS+GRAMMER_SYMBOL_COUNT; i++){
			for (int j = 0; j < TOTAL_STATES; j++){
				parser->lrTable[i][j].LRTableFuncP = LRError;
				parser->lrTable[i][j].actionParam = -1;
			}
		}
	//shift
	parser->lrTable[29][0].LRTableFuncP = LRShift;
	parser->lrTable[29][0].actionParam = 1;
	//shift
	parser->lrTable[30][0].LRTableFuncP = LRShift;
	parser->lrTable[30][0].actionParam = 2;
	//shift
	parser->lrTable[31][0].LRTableFuncP = LRShift;
	parser->lrTable[31][0].actionParam = 3;
	//shift
	parser->lrTable[32][0].LRTableFuncP = LRShift;
	parser->lrTable[32][0].actionParam = 4;
	//shift
	parser->lrTable[33][0].LRTableFuncP = LRShift;
	parser->lrTable[33][0].actionParam = 5;
	//shift
	parser->lrTable[38][0].LRTableFuncP = LRShift;
	parser->lrTable[38][0].actionParam = 6;
	//shift
	parser->lrTable[39][0].LRTableFuncP = LRShift;
	parser->lrTable[39][0].actionParam = 7;
	//shift
	parser->lrTable[40][0].LRTableFuncP = LRShift;
	parser->lrTable[40][0].actionParam = 8;
	//reduce
	parser->lrTable[41][0].LRTableFuncP = LRReduce;
	parser->lrTable[41][0].actionParam = 4;
	//goto
	parser->lrTable[PROGRAM+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[PROGRAM+TOTAL_TOKENS][0].actionParam = 9;
	//goto
	parser->lrTable[Start+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[Start+TOTAL_TOKENS][0].actionParam = 10;
	//goto
	parser->lrTable[StmtList+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[StmtList+TOTAL_TOKENS][0].actionParam = 11;
	//goto
	parser->lrTable[Stmt+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[Stmt+TOTAL_TOKENS][0].actionParam = 12;
	//goto
	parser->lrTable[Decl+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[Decl+TOTAL_TOKENS][0].actionParam = 13;
	//goto
	parser->lrTable[Assi+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[Assi+TOTAL_TOKENS][0].actionParam = 14;
	//goto
	parser->lrTable[IfStmt+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[IfStmt+TOTAL_TOKENS][0].actionParam = 15;
	//goto
	parser->lrTable[LoopStmt+TOTAL_TOKENS][0].LRTableFuncP = LRGoto;
	parser->lrTable[LoopStmt+TOTAL_TOKENS][0].actionParam = 16;
	//shift
	parser->lrTable[40][1].LRTableFuncP = LRShift;
	parser->lrTable[40][1].actionParam = 17;
	//shift
	parser->lrTable[40][2].LRTableFuncP = LRShift;
	parser->lrTable[40][2].actionParam = 18;
	//shift
	parser->lrTable[40][3].LRTableFuncP = LRShift;
	parser->lrTable[40][3].actionParam = 19;
	//shift
	parser->lrTable[40][4].LRTableFuncP = LRShift;
	parser->lrTable[40][4].actionParam = 20;
	//shift
	parser->lrTable[20][5].LRTableFuncP = LRShift;
	parser->lrTable[20][5].actionParam = 21;
	//shift
	parser->lrTable[20][6].LRTableFuncP = LRShift;
	parser->lrTable[20][6].actionParam = 22;
	//shift
	parser->lrTable[20][7].LRTableFuncP = LRShift;
	parser->lrTable[20][7].actionParam = 23;
	//shift
	parser->lrTable[3][8].LRTableFuncP = LRShift;
	parser->lrTable[3][8].actionParam = 24;
	//shift
	parser->lrTable[9][8].LRTableFuncP = LRShift;
	parser->lrTable[9][8].actionParam = 25;
	//shift
	parser->lrTable[8][8].LRTableFuncP = LRShift;
	parser->lrTable[8][8].actionParam = 26;
	//shift
	parser->lrTable[12][8].LRTableFuncP = LRShift;
	parser->lrTable[12][8].actionParam = 27;
	//shift
	parser->lrTable[11][8].LRTableFuncP = LRShift;
	parser->lrTable[11][8].actionParam = 28;
	//shift
	parser->lrTable[14][8].LRTableFuncP = LRShift;
	parser->lrTable[14][8].actionParam = 29;
	//shift
	parser->lrTable[16][8].LRTableFuncP = LRShift;
	parser->lrTable[16][8].actionParam = 30;
	//shift
	parser->lrTable[18][8].LRTableFuncP = LRShift;
	parser->lrTable[18][8].actionParam = 31;
	//shift
	parser->lrTable[41][9].LRTableFuncP = LRShift;
	parser->lrTable[41][9].actionParam = 32;
	//reduce
	parser->lrTable[41][10].LRTableFuncP = LRReduce;
	parser->lrTable[41][10].actionParam = 1;
	//reduce
	parser->lrTable[41][11].LRTableFuncP = LRReduce;
	parser->lrTable[41][11].actionParam = 2;
	//shift
	parser->lrTable[29][12].LRTableFuncP = LRShift;
	parser->lrTable[29][12].actionParam = 1;
	//shift
	parser->lrTable[30][12].LRTableFuncP = LRShift;
	parser->lrTable[30][12].actionParam = 2;
	//shift
	parser->lrTable[31][12].LRTableFuncP = LRShift;
	parser->lrTable[31][12].actionParam = 3;
	//shift
	parser->lrTable[32][12].LRTableFuncP = LRShift;
	parser->lrTable[32][12].actionParam = 4;
	//shift
	parser->lrTable[33][12].LRTableFuncP = LRShift;
	parser->lrTable[33][12].actionParam = 5;
	//shift
	parser->lrTable[38][12].LRTableFuncP = LRShift;
	parser->lrTable[38][12].actionParam = 6;
	//shift
	parser->lrTable[39][12].LRTableFuncP = LRShift;
	parser->lrTable[39][12].actionParam = 7;
	//shift
	parser->lrTable[40][12].LRTableFuncP = LRShift;
	parser->lrTable[40][12].actionParam = 8;
	//reduce
	parser->lrTable[41][12].LRTableFuncP = LRReduce;
	parser->lrTable[41][12].actionParam = 4;
	//reduce
	parser->lrTable[23][12].LRTableFuncP = LRReduce;
	parser->lrTable[23][12].actionParam = 4;
	//goto
	parser->lrTable[StmtList+TOTAL_TOKENS][12].LRTableFuncP = LRGoto;
	parser->lrTable[StmtList+TOTAL_TOKENS][12].actionParam = 33;
	//goto
	parser->lrTable[Stmt+TOTAL_TOKENS][12].LRTableFuncP = LRGoto;
	parser->lrTable[Stmt+TOTAL_TOKENS][12].actionParam = 12;
	//goto
	parser->lrTable[Decl+TOTAL_TOKENS][12].LRTableFuncP = LRGoto;
	parser->lrTable[Decl+TOTAL_TOKENS][12].actionParam = 13;
	//goto
	parser->lrTable[Assi+TOTAL_TOKENS][12].LRTableFuncP = LRGoto;
	parser->lrTable[Assi+TOTAL_TOKENS][12].actionParam = 14;
	//goto
	parser->lrTable[IfStmt+TOTAL_TOKENS][12].LRTableFuncP = LRGoto;
	parser->lrTable[IfStmt+TOTAL_TOKENS][12].actionParam = 15;
	//goto
	parser->lrTable[LoopStmt+TOTAL_TOKENS][12].LRTableFuncP = LRGoto;
	parser->lrTable[LoopStmt+TOTAL_TOKENS][12].actionParam = 16;
	//shift
	parser->lrTable[45][13].LRTableFuncP = LRShift;
	parser->lrTable[45][13].actionParam = 34;
	//shift
	parser->lrTable[45][14].LRTableFuncP = LRShift;
	parser->lrTable[45][14].actionParam = 35;
	//reduce
	parser->lrTable[41][15].LRTableFuncP = LRReduce;
	parser->lrTable[41][15].actionParam = 7;
	//reduce
	parser->lrTable[23][15].LRTableFuncP = LRReduce;
	parser->lrTable[23][15].actionParam = 7;
	//reduce
	parser->lrTable[29][15].LRTableFuncP = LRReduce;
	parser->lrTable[29][15].actionParam = 7;
	//reduce
	parser->lrTable[30][15].LRTableFuncP = LRReduce;
	parser->lrTable[30][15].actionParam = 7;
	//reduce
	parser->lrTable[31][15].LRTableFuncP = LRReduce;
	parser->lrTable[31][15].actionParam = 7;
	//reduce
	parser->lrTable[32][15].LRTableFuncP = LRReduce;
	parser->lrTable[32][15].actionParam = 7;
	//reduce
	parser->lrTable[33][15].LRTableFuncP = LRReduce;
	parser->lrTable[33][15].actionParam = 7;
	//reduce
	parser->lrTable[38][15].LRTableFuncP = LRReduce;
	parser->lrTable[38][15].actionParam = 7;
	//reduce
	parser->lrTable[39][15].LRTableFuncP = LRReduce;
	parser->lrTable[39][15].actionParam = 7;
	//reduce
	parser->lrTable[40][15].LRTableFuncP = LRReduce;
	parser->lrTable[40][15].actionParam = 7;
	//reduce
	parser->lrTable[41][16].LRTableFuncP = LRReduce;
	parser->lrTable[41][16].actionParam = 8;
	//reduce
	parser->lrTable[23][16].LRTableFuncP = LRReduce;
	parser->lrTable[23][16].actionParam = 8;
	//reduce
	parser->lrTable[29][16].LRTableFuncP = LRReduce;
	parser->lrTable[29][16].actionParam = 8;
	//reduce
	parser->lrTable[30][16].LRTableFuncP = LRReduce;
	parser->lrTable[30][16].actionParam = 8;
	//reduce
	parser->lrTable[31][16].LRTableFuncP = LRReduce;
	parser->lrTable[31][16].actionParam = 8;
	//reduce
	parser->lrTable[32][16].LRTableFuncP = LRReduce;
	parser->lrTable[32][16].actionParam = 8;
	//reduce
	parser->lrTable[33][16].LRTableFuncP = LRReduce;
	parser->lrTable[33][16].actionParam = 8;
	//reduce
	parser->lrTable[38][16].LRTableFuncP = LRReduce;
	parser->lrTable[38][16].actionParam = 8;
	//reduce
	parser->lrTable[39][16].LRTableFuncP = LRReduce;
	parser->lrTable[39][16].actionParam = 8;
	//reduce
	parser->lrTable[40][16].LRTableFuncP = LRReduce;
	parser->lrTable[40][16].actionParam = 8;
	//reduce
	parser->lrTable[45][17].LRTableFuncP = LRReduce;
	parser->lrTable[45][17].actionParam = 10;
	//reduce
	parser->lrTable[45][18].LRTableFuncP = LRReduce;
	parser->lrTable[45][18].actionParam = 9;
	//reduce
	parser->lrTable[45][19].LRTableFuncP = LRReduce;
	parser->lrTable[45][19].actionParam = 12;
	//reduce
	parser->lrTable[45][20].LRTableFuncP = LRReduce;
	parser->lrTable[45][20].actionParam = 11;
	//shift
	parser->lrTable[5][21].LRTableFuncP = LRShift;
	parser->lrTable[5][21].actionParam = 36;
	//shift
	parser->lrTable[9][21].LRTableFuncP = LRShift;
	parser->lrTable[9][21].actionParam = 37;
	//shift
	parser->lrTable[12][21].LRTableFuncP = LRShift;
	parser->lrTable[12][21].actionParam = 38;
	//shift
	parser->lrTable[20][21].LRTableFuncP = LRShift;
	parser->lrTable[20][21].actionParam = 39;
	//shift
	parser->lrTable[24][21].LRTableFuncP = LRShift;
	parser->lrTable[24][21].actionParam = 40;
	//shift
	parser->lrTable[25][21].LRTableFuncP = LRShift;
	parser->lrTable[25][21].actionParam = 41;
	//shift
	parser->lrTable[26][21].LRTableFuncP = LRShift;
	parser->lrTable[26][21].actionParam = 42;
	//shift
	parser->lrTable[27][21].LRTableFuncP = LRShift;
	parser->lrTable[27][21].actionParam = 43;
	//shift
	parser->lrTable[28][21].LRTableFuncP = LRShift;
	parser->lrTable[28][21].actionParam = 44;
	//shift
	parser->lrTable[40][21].LRTableFuncP = LRShift;
	parser->lrTable[40][21].actionParam = 45;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][21].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][21].actionParam = 46;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][21].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][21].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][21].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][21].actionParam = 48;
	//goto
	parser->lrTable[CondExpr+TOTAL_TOKENS][21].LRTableFuncP = LRGoto;
	parser->lrTable[CondExpr+TOTAL_TOKENS][21].actionParam = 49;
	//shift
	parser->lrTable[40][22].LRTableFuncP = LRShift;
	parser->lrTable[40][22].actionParam = 8;
	//goto
	parser->lrTable[Assi+TOTAL_TOKENS][22].LRTableFuncP = LRGoto;
	parser->lrTable[Assi+TOTAL_TOKENS][22].actionParam = 50;
	//shift
	parser->lrTable[5][23].LRTableFuncP = LRShift;
	parser->lrTable[5][23].actionParam = 36;
	//shift
	parser->lrTable[9][23].LRTableFuncP = LRShift;
	parser->lrTable[9][23].actionParam = 37;
	//shift
	parser->lrTable[12][23].LRTableFuncP = LRShift;
	parser->lrTable[12][23].actionParam = 38;
	//shift
	parser->lrTable[20][23].LRTableFuncP = LRShift;
	parser->lrTable[20][23].actionParam = 39;
	//shift
	parser->lrTable[24][23].LRTableFuncP = LRShift;
	parser->lrTable[24][23].actionParam = 40;
	//shift
	parser->lrTable[25][23].LRTableFuncP = LRShift;
	parser->lrTable[25][23].actionParam = 41;
	//shift
	parser->lrTable[26][23].LRTableFuncP = LRShift;
	parser->lrTable[26][23].actionParam = 42;
	//shift
	parser->lrTable[27][23].LRTableFuncP = LRShift;
	parser->lrTable[27][23].actionParam = 43;
	//shift
	parser->lrTable[28][23].LRTableFuncP = LRShift;
	parser->lrTable[28][23].actionParam = 44;
	//shift
	parser->lrTable[40][23].LRTableFuncP = LRShift;
	parser->lrTable[40][23].actionParam = 45;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][23].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][23].actionParam = 46;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][23].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][23].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][23].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][23].actionParam = 48;
	//goto
	parser->lrTable[CondExpr+TOTAL_TOKENS][23].LRTableFuncP = LRGoto;
	parser->lrTable[CondExpr+TOTAL_TOKENS][23].actionParam = 51;
	//shift
	parser->lrTable[9][24].LRTableFuncP = LRShift;
	parser->lrTable[9][24].actionParam = 37;
	//shift
	parser->lrTable[12][24].LRTableFuncP = LRShift;
	parser->lrTable[12][24].actionParam = 38;
	//shift
	parser->lrTable[20][24].LRTableFuncP = LRShift;
	parser->lrTable[20][24].actionParam = 52;
	//shift
	parser->lrTable[24][24].LRTableFuncP = LRShift;
	parser->lrTable[24][24].actionParam = 40;
	//shift
	parser->lrTable[25][24].LRTableFuncP = LRShift;
	parser->lrTable[25][24].actionParam = 41;
	//shift
	parser->lrTable[26][24].LRTableFuncP = LRShift;
	parser->lrTable[26][24].actionParam = 42;
	//shift
	parser->lrTable[27][24].LRTableFuncP = LRShift;
	parser->lrTable[27][24].actionParam = 43;
	//shift
	parser->lrTable[28][24].LRTableFuncP = LRShift;
	parser->lrTable[28][24].actionParam = 44;
	//shift
	parser->lrTable[40][24].LRTableFuncP = LRShift;
	parser->lrTable[40][24].actionParam = 45;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][24].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][24].actionParam = 53;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][24].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][24].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][24].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][24].actionParam = 48;
	//reduce
	parser->lrTable[21][25].LRTableFuncP = LRReduce;
	parser->lrTable[21][25].actionParam = 14;
	//reduce
	parser->lrTable[45][25].LRTableFuncP = LRReduce;
	parser->lrTable[45][25].actionParam = 14;
	//shift
	parser->lrTable[9][26].LRTableFuncP = LRShift;
	parser->lrTable[9][26].actionParam = 37;
	//shift
	parser->lrTable[12][26].LRTableFuncP = LRShift;
	parser->lrTable[12][26].actionParam = 38;
	//shift
	parser->lrTable[20][26].LRTableFuncP = LRShift;
	parser->lrTable[20][26].actionParam = 52;
	//shift
	parser->lrTable[24][26].LRTableFuncP = LRShift;
	parser->lrTable[24][26].actionParam = 40;
	//shift
	parser->lrTable[25][26].LRTableFuncP = LRShift;
	parser->lrTable[25][26].actionParam = 41;
	//shift
	parser->lrTable[26][26].LRTableFuncP = LRShift;
	parser->lrTable[26][26].actionParam = 42;
	//shift
	parser->lrTable[27][26].LRTableFuncP = LRShift;
	parser->lrTable[27][26].actionParam = 43;
	//shift
	parser->lrTable[28][26].LRTableFuncP = LRShift;
	parser->lrTable[28][26].actionParam = 44;
	//shift
	parser->lrTable[40][26].LRTableFuncP = LRShift;
	parser->lrTable[40][26].actionParam = 45;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][26].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][26].actionParam = 54;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][26].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][26].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][26].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][26].actionParam = 48;
	//reduce
	parser->lrTable[21][27].LRTableFuncP = LRReduce;
	parser->lrTable[21][27].actionParam = 15;
	//reduce
	parser->lrTable[45][27].LRTableFuncP = LRReduce;
	parser->lrTable[45][27].actionParam = 15;
	//shift
	parser->lrTable[9][28].LRTableFuncP = LRShift;
	parser->lrTable[9][28].actionParam = 37;
	//shift
	parser->lrTable[12][28].LRTableFuncP = LRShift;
	parser->lrTable[12][28].actionParam = 38;
	//shift
	parser->lrTable[20][28].LRTableFuncP = LRShift;
	parser->lrTable[20][28].actionParam = 52;
	//shift
	parser->lrTable[24][28].LRTableFuncP = LRShift;
	parser->lrTable[24][28].actionParam = 40;
	//shift
	parser->lrTable[25][28].LRTableFuncP = LRShift;
	parser->lrTable[25][28].actionParam = 41;
	//shift
	parser->lrTable[26][28].LRTableFuncP = LRShift;
	parser->lrTable[26][28].actionParam = 42;
	//shift
	parser->lrTable[27][28].LRTableFuncP = LRShift;
	parser->lrTable[27][28].actionParam = 43;
	//shift
	parser->lrTable[28][28].LRTableFuncP = LRShift;
	parser->lrTable[28][28].actionParam = 44;
	//shift
	parser->lrTable[40][28].LRTableFuncP = LRShift;
	parser->lrTable[40][28].actionParam = 45;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][28].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][28].actionParam = 55;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][28].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][28].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][28].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][28].actionParam = 48;
	//shift
	parser->lrTable[9][29].LRTableFuncP = LRShift;
	parser->lrTable[9][29].actionParam = 37;
	//shift
	parser->lrTable[12][29].LRTableFuncP = LRShift;
	parser->lrTable[12][29].actionParam = 38;
	//shift
	parser->lrTable[20][29].LRTableFuncP = LRShift;
	parser->lrTable[20][29].actionParam = 52;
	//shift
	parser->lrTable[24][29].LRTableFuncP = LRShift;
	parser->lrTable[24][29].actionParam = 40;
	//shift
	parser->lrTable[25][29].LRTableFuncP = LRShift;
	parser->lrTable[25][29].actionParam = 41;
	//shift
	parser->lrTable[26][29].LRTableFuncP = LRShift;
	parser->lrTable[26][29].actionParam = 42;
	//shift
	parser->lrTable[27][29].LRTableFuncP = LRShift;
	parser->lrTable[27][29].actionParam = 43;
	//shift
	parser->lrTable[28][29].LRTableFuncP = LRShift;
	parser->lrTable[28][29].actionParam = 44;
	//shift
	parser->lrTable[40][29].LRTableFuncP = LRShift;
	parser->lrTable[40][29].actionParam = 45;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][29].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][29].actionParam = 56;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][29].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][29].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][29].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][29].actionParam = 48;
	//shift
	parser->lrTable[9][30].LRTableFuncP = LRShift;
	parser->lrTable[9][30].actionParam = 37;
	//shift
	parser->lrTable[12][30].LRTableFuncP = LRShift;
	parser->lrTable[12][30].actionParam = 38;
	//shift
	parser->lrTable[20][30].LRTableFuncP = LRShift;
	parser->lrTable[20][30].actionParam = 52;
	//shift
	parser->lrTable[24][30].LRTableFuncP = LRShift;
	parser->lrTable[24][30].actionParam = 40;
	//shift
	parser->lrTable[25][30].LRTableFuncP = LRShift;
	parser->lrTable[25][30].actionParam = 41;
	//shift
	parser->lrTable[26][30].LRTableFuncP = LRShift;
	parser->lrTable[26][30].actionParam = 42;
	//shift
	parser->lrTable[27][30].LRTableFuncP = LRShift;
	parser->lrTable[27][30].actionParam = 43;
	//shift
	parser->lrTable[28][30].LRTableFuncP = LRShift;
	parser->lrTable[28][30].actionParam = 44;
	//shift
	parser->lrTable[40][30].LRTableFuncP = LRShift;
	parser->lrTable[40][30].actionParam = 45;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][30].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][30].actionParam = 57;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][30].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][30].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][30].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][30].actionParam = 48;
	//shift
	parser->lrTable[9][31].LRTableFuncP = LRShift;
	parser->lrTable[9][31].actionParam = 37;
	//shift
	parser->lrTable[12][31].LRTableFuncP = LRShift;
	parser->lrTable[12][31].actionParam = 38;
	//shift
	parser->lrTable[20][31].LRTableFuncP = LRShift;
	parser->lrTable[20][31].actionParam = 52;
	//shift
	parser->lrTable[24][31].LRTableFuncP = LRShift;
	parser->lrTable[24][31].actionParam = 40;
	//shift
	parser->lrTable[25][31].LRTableFuncP = LRShift;
	parser->lrTable[25][31].actionParam = 41;
	//shift
	parser->lrTable[26][31].LRTableFuncP = LRShift;
	parser->lrTable[26][31].actionParam = 42;
	//shift
	parser->lrTable[27][31].LRTableFuncP = LRShift;
	parser->lrTable[27][31].actionParam = 43;
	//shift
	parser->lrTable[28][31].LRTableFuncP = LRShift;
	parser->lrTable[28][31].actionParam = 44;
	//shift
	parser->lrTable[40][31].LRTableFuncP = LRShift;
	parser->lrTable[40][31].actionParam = 45;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][31].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][31].actionParam = 58;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][31].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][31].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][31].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][31].actionParam = 48;
	//accept
	for (int i = 0; i < TOTAL_TOKENS+GRAMMER_SYMBOL_COUNT; i++){
		parser->lrTable[i][32].LRTableFuncP = LRAccept;
		parser->lrTable[i][32].actionParam = -1;
	}
	//reduce
	parser->lrTable[41][33].LRTableFuncP = LRReduce;
	parser->lrTable[41][33].actionParam = 3;
	//reduce
	parser->lrTable[23][33].LRTableFuncP = LRReduce;
	parser->lrTable[23][33].actionParam = 3;
	//reduce
	parser->lrTable[41][34].LRTableFuncP = LRReduce;
	parser->lrTable[41][34].actionParam = 5;
	//reduce
	parser->lrTable[23][34].LRTableFuncP = LRReduce;
	parser->lrTable[23][34].actionParam = 5;
	//reduce
	parser->lrTable[29][34].LRTableFuncP = LRReduce;
	parser->lrTable[29][34].actionParam = 5;
	//reduce
	parser->lrTable[30][34].LRTableFuncP = LRReduce;
	parser->lrTable[30][34].actionParam = 5;
	//reduce
	parser->lrTable[31][34].LRTableFuncP = LRReduce;
	parser->lrTable[31][34].actionParam = 5;
	//reduce
	parser->lrTable[32][34].LRTableFuncP = LRReduce;
	parser->lrTable[32][34].actionParam = 5;
	//reduce
	parser->lrTable[33][34].LRTableFuncP = LRReduce;
	parser->lrTable[33][34].actionParam = 5;
	//reduce
	parser->lrTable[38][34].LRTableFuncP = LRReduce;
	parser->lrTable[38][34].actionParam = 5;
	//reduce
	parser->lrTable[39][34].LRTableFuncP = LRReduce;
	parser->lrTable[39][34].actionParam = 5;
	//reduce
	parser->lrTable[40][34].LRTableFuncP = LRReduce;
	parser->lrTable[40][34].actionParam = 5;
	//reduce
	parser->lrTable[41][35].LRTableFuncP = LRReduce;
	parser->lrTable[41][35].actionParam = 6;
	//reduce
	parser->lrTable[23][35].LRTableFuncP = LRReduce;
	parser->lrTable[23][35].actionParam = 6;
	//reduce
	parser->lrTable[29][35].LRTableFuncP = LRReduce;
	parser->lrTable[29][35].actionParam = 6;
	//reduce
	parser->lrTable[30][35].LRTableFuncP = LRReduce;
	parser->lrTable[30][35].actionParam = 6;
	//reduce
	parser->lrTable[31][35].LRTableFuncP = LRReduce;
	parser->lrTable[31][35].actionParam = 6;
	//reduce
	parser->lrTable[32][35].LRTableFuncP = LRReduce;
	parser->lrTable[32][35].actionParam = 6;
	//reduce
	parser->lrTable[33][35].LRTableFuncP = LRReduce;
	parser->lrTable[33][35].actionParam = 6;
	//reduce
	parser->lrTable[38][35].LRTableFuncP = LRReduce;
	parser->lrTable[38][35].actionParam = 6;
	//reduce
	parser->lrTable[39][35].LRTableFuncP = LRReduce;
	parser->lrTable[39][35].actionParam = 6;
	//reduce
	parser->lrTable[40][35].LRTableFuncP = LRReduce;
	parser->lrTable[40][35].actionParam = 6;
	//shift
	parser->lrTable[9][36].LRTableFuncP = LRShift;
	parser->lrTable[9][36].actionParam = 37;
	//shift
	parser->lrTable[12][36].LRTableFuncP = LRShift;
	parser->lrTable[12][36].actionParam = 38;
	//shift
	parser->lrTable[20][36].LRTableFuncP = LRShift;
	parser->lrTable[20][36].actionParam = 52;
	//shift
	parser->lrTable[24][36].LRTableFuncP = LRShift;
	parser->lrTable[24][36].actionParam = 40;
	//shift
	parser->lrTable[25][36].LRTableFuncP = LRShift;
	parser->lrTable[25][36].actionParam = 41;
	//shift
	parser->lrTable[26][36].LRTableFuncP = LRShift;
	parser->lrTable[26][36].actionParam = 42;
	//shift
	parser->lrTable[27][36].LRTableFuncP = LRShift;
	parser->lrTable[27][36].actionParam = 43;
	//shift
	parser->lrTable[28][36].LRTableFuncP = LRShift;
	parser->lrTable[28][36].actionParam = 44;
	//shift
	parser->lrTable[40][36].LRTableFuncP = LRShift;
	parser->lrTable[40][36].actionParam = 45;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][36].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][36].actionParam = 59;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][36].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][36].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][36].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][36].actionParam = 48;
	//shift
	parser->lrTable[40][37].LRTableFuncP = LRShift;
	parser->lrTable[40][37].actionParam = 60;
	//shift
	parser->lrTable[40][38].LRTableFuncP = LRShift;
	parser->lrTable[40][38].actionParam = 61;
	//shift
	parser->lrTable[5][39].LRTableFuncP = LRShift;
	parser->lrTable[5][39].actionParam = 36;
	//shift
	parser->lrTable[9][39].LRTableFuncP = LRShift;
	parser->lrTable[9][39].actionParam = 37;
	//shift
	parser->lrTable[12][39].LRTableFuncP = LRShift;
	parser->lrTable[12][39].actionParam = 38;
	//shift
	parser->lrTable[20][39].LRTableFuncP = LRShift;
	parser->lrTable[20][39].actionParam = 39;
	//shift
	parser->lrTable[24][39].LRTableFuncP = LRShift;
	parser->lrTable[24][39].actionParam = 40;
	//shift
	parser->lrTable[25][39].LRTableFuncP = LRShift;
	parser->lrTable[25][39].actionParam = 41;
	//shift
	parser->lrTable[26][39].LRTableFuncP = LRShift;
	parser->lrTable[26][39].actionParam = 42;
	//shift
	parser->lrTable[27][39].LRTableFuncP = LRShift;
	parser->lrTable[27][39].actionParam = 43;
	//shift
	parser->lrTable[28][39].LRTableFuncP = LRShift;
	parser->lrTable[28][39].actionParam = 44;
	//shift
	parser->lrTable[40][39].LRTableFuncP = LRShift;
	parser->lrTable[40][39].actionParam = 45;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][39].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][39].actionParam = 62;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][39].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][39].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][39].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][39].actionParam = 48;
	//goto
	parser->lrTable[CondExpr+TOTAL_TOKENS][39].LRTableFuncP = LRGoto;
	parser->lrTable[CondExpr+TOTAL_TOKENS][39].actionParam = 63;
	//reduce
	parser->lrTable[0][40].LRTableFuncP = LRReduce;
	parser->lrTable[0][40].actionParam = 31;
	//reduce
	parser->lrTable[1][40].LRTableFuncP = LRReduce;
	parser->lrTable[1][40].actionParam = 31;
	//reduce
	parser->lrTable[2][40].LRTableFuncP = LRReduce;
	parser->lrTable[2][40].actionParam = 31;
	//reduce
	parser->lrTable[3][40].LRTableFuncP = LRReduce;
	parser->lrTable[3][40].actionParam = 31;
	//reduce
	parser->lrTable[4][40].LRTableFuncP = LRReduce;
	parser->lrTable[4][40].actionParam = 31;
	//reduce
	parser->lrTable[5][40].LRTableFuncP = LRReduce;
	parser->lrTable[5][40].actionParam = 31;
	//reduce
	parser->lrTable[3][40].LRTableFuncP = LRReduce;
	parser->lrTable[3][40].actionParam = 31;
	//reduce
	parser->lrTable[8][40].LRTableFuncP = LRReduce;
	parser->lrTable[8][40].actionParam = 31;
	//reduce
	parser->lrTable[11][40].LRTableFuncP = LRReduce;
	parser->lrTable[11][40].actionParam = 31;
	//reduce
	parser->lrTable[14][40].LRTableFuncP = LRReduce;
	parser->lrTable[14][40].actionParam = 31;
	//reduce
	parser->lrTable[16][40].LRTableFuncP = LRReduce;
	parser->lrTable[16][40].actionParam = 31;
	//reduce
	parser->lrTable[18][40].LRTableFuncP = LRReduce;
	parser->lrTable[18][40].actionParam = 31;
	//reduce
	parser->lrTable[21][40].LRTableFuncP = LRReduce;
	parser->lrTable[21][40].actionParam = 31;
	//reduce
	parser->lrTable[36][40].LRTableFuncP = LRReduce;
	parser->lrTable[36][40].actionParam = 31;
	//reduce
	parser->lrTable[37][40].LRTableFuncP = LRReduce;
	parser->lrTable[37][40].actionParam = 31;
	//reduce
	parser->lrTable[45][40].LRTableFuncP = LRReduce;
	parser->lrTable[45][40].actionParam = 31;
	//reduce
	parser->lrTable[0][41].LRTableFuncP = LRReduce;
	parser->lrTable[0][41].actionParam = 33;
	//reduce
	parser->lrTable[1][41].LRTableFuncP = LRReduce;
	parser->lrTable[1][41].actionParam = 33;
	//reduce
	parser->lrTable[2][41].LRTableFuncP = LRReduce;
	parser->lrTable[2][41].actionParam = 33;
	//reduce
	parser->lrTable[3][41].LRTableFuncP = LRReduce;
	parser->lrTable[3][41].actionParam = 33;
	//reduce
	parser->lrTable[4][41].LRTableFuncP = LRReduce;
	parser->lrTable[4][41].actionParam = 33;
	//reduce
	parser->lrTable[5][41].LRTableFuncP = LRReduce;
	parser->lrTable[5][41].actionParam = 33;
	//reduce
	parser->lrTable[3][41].LRTableFuncP = LRReduce;
	parser->lrTable[3][41].actionParam = 33;
	//reduce
	parser->lrTable[8][41].LRTableFuncP = LRReduce;
	parser->lrTable[8][41].actionParam = 33;
	//reduce
	parser->lrTable[11][41].LRTableFuncP = LRReduce;
	parser->lrTable[11][41].actionParam = 33;
	//reduce
	parser->lrTable[14][41].LRTableFuncP = LRReduce;
	parser->lrTable[14][41].actionParam = 33;
	//reduce
	parser->lrTable[16][41].LRTableFuncP = LRReduce;
	parser->lrTable[16][41].actionParam = 33;
	//reduce
	parser->lrTable[18][41].LRTableFuncP = LRReduce;
	parser->lrTable[18][41].actionParam = 33;
	//reduce
	parser->lrTable[21][41].LRTableFuncP = LRReduce;
	parser->lrTable[21][41].actionParam = 33;
	//reduce
	parser->lrTable[36][41].LRTableFuncP = LRReduce;
	parser->lrTable[36][41].actionParam = 33;
	//reduce
	parser->lrTable[37][41].LRTableFuncP = LRReduce;
	parser->lrTable[37][41].actionParam = 33;
	//reduce
	parser->lrTable[45][41].LRTableFuncP = LRReduce;
	parser->lrTable[45][41].actionParam = 33;
	//reduce
	parser->lrTable[0][42].LRTableFuncP = LRReduce;
	parser->lrTable[0][42].actionParam = 34;
	//reduce
	parser->lrTable[1][42].LRTableFuncP = LRReduce;
	parser->lrTable[1][42].actionParam = 34;
	//reduce
	parser->lrTable[2][42].LRTableFuncP = LRReduce;
	parser->lrTable[2][42].actionParam = 34;
	//reduce
	parser->lrTable[3][42].LRTableFuncP = LRReduce;
	parser->lrTable[3][42].actionParam = 34;
	//reduce
	parser->lrTable[4][42].LRTableFuncP = LRReduce;
	parser->lrTable[4][42].actionParam = 34;
	//reduce
	parser->lrTable[5][42].LRTableFuncP = LRReduce;
	parser->lrTable[5][42].actionParam = 34;
	//reduce
	parser->lrTable[3][42].LRTableFuncP = LRReduce;
	parser->lrTable[3][42].actionParam = 34;
	//reduce
	parser->lrTable[8][42].LRTableFuncP = LRReduce;
	parser->lrTable[8][42].actionParam = 34;
	//reduce
	parser->lrTable[11][42].LRTableFuncP = LRReduce;
	parser->lrTable[11][42].actionParam = 34;
	//reduce
	parser->lrTable[14][42].LRTableFuncP = LRReduce;
	parser->lrTable[14][42].actionParam = 34;
	//reduce
	parser->lrTable[16][42].LRTableFuncP = LRReduce;
	parser->lrTable[16][42].actionParam = 34;
	//reduce
	parser->lrTable[18][42].LRTableFuncP = LRReduce;
	parser->lrTable[18][42].actionParam = 34;
	//reduce
	parser->lrTable[21][42].LRTableFuncP = LRReduce;
	parser->lrTable[21][42].actionParam = 34;
	//reduce
	parser->lrTable[36][42].LRTableFuncP = LRReduce;
	parser->lrTable[36][42].actionParam = 34;
	//reduce
	parser->lrTable[37][42].LRTableFuncP = LRReduce;
	parser->lrTable[37][42].actionParam = 34;
	//reduce
	parser->lrTable[45][42].LRTableFuncP = LRReduce;
	parser->lrTable[45][42].actionParam = 34;
	//reduce
	parser->lrTable[0][43].LRTableFuncP = LRReduce;
	parser->lrTable[0][43].actionParam = 30;
	//reduce
	parser->lrTable[1][43].LRTableFuncP = LRReduce;
	parser->lrTable[1][43].actionParam = 30;
	//reduce
	parser->lrTable[2][43].LRTableFuncP = LRReduce;
	parser->lrTable[2][43].actionParam = 30;
	//reduce
	parser->lrTable[3][43].LRTableFuncP = LRReduce;
	parser->lrTable[3][43].actionParam = 30;
	//reduce
	parser->lrTable[4][43].LRTableFuncP = LRReduce;
	parser->lrTable[4][43].actionParam = 30;
	//reduce
	parser->lrTable[5][43].LRTableFuncP = LRReduce;
	parser->lrTable[5][43].actionParam = 30;
	//reduce
	parser->lrTable[3][43].LRTableFuncP = LRReduce;
	parser->lrTable[3][43].actionParam = 30;
	//reduce
	parser->lrTable[8][43].LRTableFuncP = LRReduce;
	parser->lrTable[8][43].actionParam = 30;
	//reduce
	parser->lrTable[11][43].LRTableFuncP = LRReduce;
	parser->lrTable[11][43].actionParam = 30;
	//reduce
	parser->lrTable[14][43].LRTableFuncP = LRReduce;
	parser->lrTable[14][43].actionParam = 30;
	//reduce
	parser->lrTable[16][43].LRTableFuncP = LRReduce;
	parser->lrTable[16][43].actionParam = 30;
	//reduce
	parser->lrTable[18][43].LRTableFuncP = LRReduce;
	parser->lrTable[18][43].actionParam = 30;
	//reduce
	parser->lrTable[21][43].LRTableFuncP = LRReduce;
	parser->lrTable[21][43].actionParam = 30;
	//reduce
	parser->lrTable[36][43].LRTableFuncP = LRReduce;
	parser->lrTable[36][43].actionParam = 30;
	//reduce
	parser->lrTable[37][43].LRTableFuncP = LRReduce;
	parser->lrTable[37][43].actionParam = 30;
	//reduce
	parser->lrTable[45][43].LRTableFuncP = LRReduce;
	parser->lrTable[45][43].actionParam = 30;
	//reduce
	parser->lrTable[0][44].LRTableFuncP = LRReduce;
	parser->lrTable[0][44].actionParam = 32;
	//reduce
	parser->lrTable[1][44].LRTableFuncP = LRReduce;
	parser->lrTable[1][44].actionParam = 32;
	//reduce
	parser->lrTable[2][44].LRTableFuncP = LRReduce;
	parser->lrTable[2][44].actionParam = 32;
	//reduce
	parser->lrTable[3][44].LRTableFuncP = LRReduce;
	parser->lrTable[3][44].actionParam = 32;
	//reduce
	parser->lrTable[4][44].LRTableFuncP = LRReduce;
	parser->lrTable[4][44].actionParam = 32;
	//reduce
	parser->lrTable[5][44].LRTableFuncP = LRReduce;
	parser->lrTable[5][44].actionParam = 32;
	//reduce
	parser->lrTable[3][44].LRTableFuncP = LRReduce;
	parser->lrTable[3][44].actionParam = 32;
	//reduce
	parser->lrTable[8][44].LRTableFuncP = LRReduce;
	parser->lrTable[8][44].actionParam = 32;
	//reduce
	parser->lrTable[11][44].LRTableFuncP = LRReduce;
	parser->lrTable[11][44].actionParam = 32;
	//reduce
	parser->lrTable[14][44].LRTableFuncP = LRReduce;
	parser->lrTable[14][44].actionParam = 32;
	//reduce
	parser->lrTable[16][44].LRTableFuncP = LRReduce;
	parser->lrTable[16][44].actionParam = 32;
	//reduce
	parser->lrTable[18][44].LRTableFuncP = LRReduce;
	parser->lrTable[18][44].actionParam = 32;
	//reduce
	parser->lrTable[21][44].LRTableFuncP = LRReduce;
	parser->lrTable[21][44].actionParam = 32;
	//reduce
	parser->lrTable[36][44].LRTableFuncP = LRReduce;
	parser->lrTable[36][44].actionParam = 32;
	//reduce
	parser->lrTable[37][44].LRTableFuncP = LRReduce;
	parser->lrTable[37][44].actionParam = 32;
	//reduce
	parser->lrTable[45][44].LRTableFuncP = LRReduce;
	parser->lrTable[45][44].actionParam = 32;
	//shift
	parser->lrTable[9][45].LRTableFuncP = LRShift;
	parser->lrTable[9][45].actionParam = 64;
	//shift
	parser->lrTable[12][45].LRTableFuncP = LRShift;
	parser->lrTable[12][45].actionParam = 65;
	//reduce
	parser->lrTable[0][45].LRTableFuncP = LRReduce;
	parser->lrTable[0][45].actionParam = 29;
	//reduce
	parser->lrTable[1][45].LRTableFuncP = LRReduce;
	parser->lrTable[1][45].actionParam = 29;
	//reduce
	parser->lrTable[2][45].LRTableFuncP = LRReduce;
	parser->lrTable[2][45].actionParam = 29;
	//reduce
	parser->lrTable[3][45].LRTableFuncP = LRReduce;
	parser->lrTable[3][45].actionParam = 29;
	//reduce
	parser->lrTable[4][45].LRTableFuncP = LRReduce;
	parser->lrTable[4][45].actionParam = 29;
	//reduce
	parser->lrTable[5][45].LRTableFuncP = LRReduce;
	parser->lrTable[5][45].actionParam = 29;
	//reduce
	parser->lrTable[3][45].LRTableFuncP = LRReduce;
	parser->lrTable[3][45].actionParam = 29;
	//reduce
	parser->lrTable[8][45].LRTableFuncP = LRReduce;
	parser->lrTable[8][45].actionParam = 29;
	//reduce
	parser->lrTable[11][45].LRTableFuncP = LRReduce;
	parser->lrTable[11][45].actionParam = 29;
	//reduce
	parser->lrTable[14][45].LRTableFuncP = LRReduce;
	parser->lrTable[14][45].actionParam = 29;
	//reduce
	parser->lrTable[16][45].LRTableFuncP = LRReduce;
	parser->lrTable[16][45].actionParam = 29;
	//reduce
	parser->lrTable[18][45].LRTableFuncP = LRReduce;
	parser->lrTable[18][45].actionParam = 29;
	//reduce
	parser->lrTable[21][45].LRTableFuncP = LRReduce;
	parser->lrTable[21][45].actionParam = 29;
	//reduce
	parser->lrTable[36][45].LRTableFuncP = LRReduce;
	parser->lrTable[36][45].actionParam = 29;
	//reduce
	parser->lrTable[37][45].LRTableFuncP = LRReduce;
	parser->lrTable[37][45].actionParam = 29;
	//reduce
	parser->lrTable[45][45].LRTableFuncP = LRReduce;
	parser->lrTable[45][45].actionParam = 29;
	//shift
	parser->lrTable[0][46].LRTableFuncP = LRShift;
	parser->lrTable[0][46].actionParam = 66;
	//shift
	parser->lrTable[1][46].LRTableFuncP = LRShift;
	parser->lrTable[1][46].actionParam = 67;
	//shift
	parser->lrTable[2][46].LRTableFuncP = LRShift;
	parser->lrTable[2][46].actionParam = 68;
	//shift
	parser->lrTable[3][46].LRTableFuncP = LRShift;
	parser->lrTable[3][46].actionParam = 69;
	//shift
	parser->lrTable[4][46].LRTableFuncP = LRShift;
	parser->lrTable[4][46].actionParam = 70;
	//shift
	parser->lrTable[5][46].LRTableFuncP = LRShift;
	parser->lrTable[5][46].actionParam = 71;
	//shift
	parser->lrTable[3][46].LRTableFuncP = LRShift;
	parser->lrTable[3][46].actionParam = 72;
	//shift
	parser->lrTable[8][46].LRTableFuncP = LRShift;
	parser->lrTable[8][46].actionParam = 73;
	//shift
	parser->lrTable[11][46].LRTableFuncP = LRShift;
	parser->lrTable[11][46].actionParam = 74;
	//shift
	parser->lrTable[36][46].LRTableFuncP = LRShift;
	parser->lrTable[36][46].actionParam = 75;
	//shift
	parser->lrTable[37][46].LRTableFuncP = LRShift;
	parser->lrTable[37][46].actionParam = 76;
	//goto
	parser->lrTable[RelOp+TOTAL_TOKENS][46].LRTableFuncP = LRGoto;
	parser->lrTable[RelOp+TOTAL_TOKENS][46].actionParam = 77;
	//shift
	parser->lrTable[14][47].LRTableFuncP = LRShift;
	parser->lrTable[14][47].actionParam = 78;
	//shift
	parser->lrTable[16][47].LRTableFuncP = LRShift;
	parser->lrTable[16][47].actionParam = 79;
	//shift
	parser->lrTable[18][47].LRTableFuncP = LRShift;
	parser->lrTable[18][47].actionParam = 80;
	//reduce
	parser->lrTable[0][47].LRTableFuncP = LRReduce;
	parser->lrTable[0][47].actionParam = 23;
	//reduce
	parser->lrTable[1][47].LRTableFuncP = LRReduce;
	parser->lrTable[1][47].actionParam = 23;
	//reduce
	parser->lrTable[2][47].LRTableFuncP = LRReduce;
	parser->lrTable[2][47].actionParam = 23;
	//reduce
	parser->lrTable[3][47].LRTableFuncP = LRReduce;
	parser->lrTable[3][47].actionParam = 23;
	//reduce
	parser->lrTable[4][47].LRTableFuncP = LRReduce;
	parser->lrTable[4][47].actionParam = 23;
	//reduce
	parser->lrTable[5][47].LRTableFuncP = LRReduce;
	parser->lrTable[5][47].actionParam = 23;
	//reduce
	parser->lrTable[3][47].LRTableFuncP = LRReduce;
	parser->lrTable[3][47].actionParam = 23;
	//reduce
	parser->lrTable[8][47].LRTableFuncP = LRReduce;
	parser->lrTable[8][47].actionParam = 23;
	//reduce
	parser->lrTable[11][47].LRTableFuncP = LRReduce;
	parser->lrTable[11][47].actionParam = 23;
	//reduce
	parser->lrTable[21][47].LRTableFuncP = LRReduce;
	parser->lrTable[21][47].actionParam = 23;
	//reduce
	parser->lrTable[36][47].LRTableFuncP = LRReduce;
	parser->lrTable[36][47].actionParam = 23;
	//reduce
	parser->lrTable[37][47].LRTableFuncP = LRReduce;
	parser->lrTable[37][47].actionParam = 23;
	//reduce
	parser->lrTable[45][47].LRTableFuncP = LRReduce;
	parser->lrTable[45][47].actionParam = 23;
	//reduce
	parser->lrTable[0][48].LRTableFuncP = LRReduce;
	parser->lrTable[0][48].actionParam = 27;
	//reduce
	parser->lrTable[1][48].LRTableFuncP = LRReduce;
	parser->lrTable[1][48].actionParam = 27;
	//reduce
	parser->lrTable[2][48].LRTableFuncP = LRReduce;
	parser->lrTable[2][48].actionParam = 27;
	//reduce
	parser->lrTable[3][48].LRTableFuncP = LRReduce;
	parser->lrTable[3][48].actionParam = 27;
	//reduce
	parser->lrTable[4][48].LRTableFuncP = LRReduce;
	parser->lrTable[4][48].actionParam = 27;
	//reduce
	parser->lrTable[5][48].LRTableFuncP = LRReduce;
	parser->lrTable[5][48].actionParam = 27;
	//reduce
	parser->lrTable[3][48].LRTableFuncP = LRReduce;
	parser->lrTable[3][48].actionParam = 27;
	//reduce
	parser->lrTable[8][48].LRTableFuncP = LRReduce;
	parser->lrTable[8][48].actionParam = 27;
	//reduce
	parser->lrTable[11][48].LRTableFuncP = LRReduce;
	parser->lrTable[11][48].actionParam = 27;
	//reduce
	parser->lrTable[14][48].LRTableFuncP = LRReduce;
	parser->lrTable[14][48].actionParam = 27;
	//reduce
	parser->lrTable[16][48].LRTableFuncP = LRReduce;
	parser->lrTable[16][48].actionParam = 27;
	//reduce
	parser->lrTable[18][48].LRTableFuncP = LRReduce;
	parser->lrTable[18][48].actionParam = 27;
	//reduce
	parser->lrTable[21][48].LRTableFuncP = LRReduce;
	parser->lrTable[21][48].actionParam = 27;
	//reduce
	parser->lrTable[36][48].LRTableFuncP = LRReduce;
	parser->lrTable[36][48].actionParam = 27;
	//reduce
	parser->lrTable[37][48].LRTableFuncP = LRReduce;
	parser->lrTable[37][48].actionParam = 27;
	//reduce
	parser->lrTable[45][48].LRTableFuncP = LRReduce;
	parser->lrTable[45][48].actionParam = 27;
	//shift
	parser->lrTable[21][49].LRTableFuncP = LRShift;
	parser->lrTable[21][49].actionParam = 81;
	//shift
	parser->lrTable[45][50].LRTableFuncP = LRShift;
	parser->lrTable[45][50].actionParam = 82;
	//shift
	parser->lrTable[21][51].LRTableFuncP = LRShift;
	parser->lrTable[21][51].actionParam = 83;
	//shift
	parser->lrTable[9][52].LRTableFuncP = LRShift;
	parser->lrTable[9][52].actionParam = 37;
	//shift
	parser->lrTable[12][52].LRTableFuncP = LRShift;
	parser->lrTable[12][52].actionParam = 38;
	//shift
	parser->lrTable[20][52].LRTableFuncP = LRShift;
	parser->lrTable[20][52].actionParam = 52;
	//shift
	parser->lrTable[24][52].LRTableFuncP = LRShift;
	parser->lrTable[24][52].actionParam = 40;
	//shift
	parser->lrTable[25][52].LRTableFuncP = LRShift;
	parser->lrTable[25][52].actionParam = 41;
	//shift
	parser->lrTable[26][52].LRTableFuncP = LRShift;
	parser->lrTable[26][52].actionParam = 42;
	//shift
	parser->lrTable[27][52].LRTableFuncP = LRShift;
	parser->lrTable[27][52].actionParam = 43;
	//shift
	parser->lrTable[28][52].LRTableFuncP = LRShift;
	parser->lrTable[28][52].actionParam = 44;
	//shift
	parser->lrTable[40][52].LRTableFuncP = LRShift;
	parser->lrTable[40][52].actionParam = 45;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][52].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][52].actionParam = 84;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][52].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][52].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][52].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][52].actionParam = 48;
	//shift
	parser->lrTable[8][53].LRTableFuncP = LRShift;
	parser->lrTable[8][53].actionParam = 73;
	//shift
	parser->lrTable[11][53].LRTableFuncP = LRShift;
	parser->lrTable[11][53].actionParam = 74;
	//reduce
	parser->lrTable[21][53].LRTableFuncP = LRReduce;
	parser->lrTable[21][53].actionParam = 13;
	//reduce
	parser->lrTable[45][53].LRTableFuncP = LRReduce;
	parser->lrTable[45][53].actionParam = 13;
	//shift
	parser->lrTable[8][54].LRTableFuncP = LRShift;
	parser->lrTable[8][54].actionParam = 73;
	//shift
	parser->lrTable[11][54].LRTableFuncP = LRShift;
	parser->lrTable[11][54].actionParam = 74;
	//reduce
	parser->lrTable[21][54].LRTableFuncP = LRReduce;
	parser->lrTable[21][54].actionParam = 16;
	//reduce
	parser->lrTable[45][54].LRTableFuncP = LRReduce;
	parser->lrTable[45][54].actionParam = 16;
	//shift
	parser->lrTable[8][55].LRTableFuncP = LRShift;
	parser->lrTable[8][55].actionParam = 73;
	//shift
	parser->lrTable[11][55].LRTableFuncP = LRShift;
	parser->lrTable[11][55].actionParam = 74;
	//reduce
	parser->lrTable[21][55].LRTableFuncP = LRReduce;
	parser->lrTable[21][55].actionParam = 17;
	//reduce
	parser->lrTable[45][55].LRTableFuncP = LRReduce;
	parser->lrTable[45][55].actionParam = 17;
	//shift
	parser->lrTable[8][56].LRTableFuncP = LRShift;
	parser->lrTable[8][56].actionParam = 73;
	//shift
	parser->lrTable[11][56].LRTableFuncP = LRShift;
	parser->lrTable[11][56].actionParam = 74;
	//reduce
	parser->lrTable[21][56].LRTableFuncP = LRReduce;
	parser->lrTable[21][56].actionParam = 19;
	//reduce
	parser->lrTable[45][56].LRTableFuncP = LRReduce;
	parser->lrTable[45][56].actionParam = 19;
	//shift
	parser->lrTable[8][57].LRTableFuncP = LRShift;
	parser->lrTable[8][57].actionParam = 73;
	//shift
	parser->lrTable[11][57].LRTableFuncP = LRShift;
	parser->lrTable[11][57].actionParam = 74;
	//reduce
	parser->lrTable[21][57].LRTableFuncP = LRReduce;
	parser->lrTable[21][57].actionParam = 18;
	//reduce
	parser->lrTable[45][57].LRTableFuncP = LRReduce;
	parser->lrTable[45][57].actionParam = 18;
	//shift
	parser->lrTable[8][58].LRTableFuncP = LRShift;
	parser->lrTable[8][58].actionParam = 73;
	//shift
	parser->lrTable[11][58].LRTableFuncP = LRShift;
	parser->lrTable[11][58].actionParam = 74;
	//reduce
	parser->lrTable[21][58].LRTableFuncP = LRReduce;
	parser->lrTable[21][58].actionParam = 20;
	//reduce
	parser->lrTable[45][58].LRTableFuncP = LRReduce;
	parser->lrTable[45][58].actionParam = 20;
	//shift
	parser->lrTable[8][59].LRTableFuncP = LRShift;
	parser->lrTable[8][59].actionParam = 73;
	//shift
	parser->lrTable[11][59].LRTableFuncP = LRShift;
	parser->lrTable[11][59].actionParam = 74;
	//reduce
	parser->lrTable[21][59].LRTableFuncP = LRReduce;
	parser->lrTable[21][59].actionParam = 40;
	//reduce
	parser->lrTable[45][59].LRTableFuncP = LRReduce;
	parser->lrTable[45][59].actionParam = 40;
	//reduce
	parser->lrTable[0][60].LRTableFuncP = LRReduce;
	parser->lrTable[0][60].actionParam = 37;
	//reduce
	parser->lrTable[1][60].LRTableFuncP = LRReduce;
	parser->lrTable[1][60].actionParam = 37;
	//reduce
	parser->lrTable[2][60].LRTableFuncP = LRReduce;
	parser->lrTable[2][60].actionParam = 37;
	//reduce
	parser->lrTable[3][60].LRTableFuncP = LRReduce;
	parser->lrTable[3][60].actionParam = 37;
	//reduce
	parser->lrTable[4][60].LRTableFuncP = LRReduce;
	parser->lrTable[4][60].actionParam = 37;
	//reduce
	parser->lrTable[5][60].LRTableFuncP = LRReduce;
	parser->lrTable[5][60].actionParam = 37;
	//reduce
	parser->lrTable[3][60].LRTableFuncP = LRReduce;
	parser->lrTable[3][60].actionParam = 37;
	//reduce
	parser->lrTable[8][60].LRTableFuncP = LRReduce;
	parser->lrTable[8][60].actionParam = 37;
	//reduce
	parser->lrTable[11][60].LRTableFuncP = LRReduce;
	parser->lrTable[11][60].actionParam = 37;
	//reduce
	parser->lrTable[14][60].LRTableFuncP = LRReduce;
	parser->lrTable[14][60].actionParam = 37;
	//reduce
	parser->lrTable[16][60].LRTableFuncP = LRReduce;
	parser->lrTable[16][60].actionParam = 37;
	//reduce
	parser->lrTable[18][60].LRTableFuncP = LRReduce;
	parser->lrTable[18][60].actionParam = 37;
	//reduce
	parser->lrTable[21][60].LRTableFuncP = LRReduce;
	parser->lrTable[21][60].actionParam = 37;
	//reduce
	parser->lrTable[36][60].LRTableFuncP = LRReduce;
	parser->lrTable[36][60].actionParam = 37;
	//reduce
	parser->lrTable[37][60].LRTableFuncP = LRReduce;
	parser->lrTable[37][60].actionParam = 37;
	//reduce
	parser->lrTable[45][60].LRTableFuncP = LRReduce;
	parser->lrTable[45][60].actionParam = 37;
	//reduce
	parser->lrTable[0][61].LRTableFuncP = LRReduce;
	parser->lrTable[0][61].actionParam = 38;
	//reduce
	parser->lrTable[1][61].LRTableFuncP = LRReduce;
	parser->lrTable[1][61].actionParam = 38;
	//reduce
	parser->lrTable[2][61].LRTableFuncP = LRReduce;
	parser->lrTable[2][61].actionParam = 38;
	//reduce
	parser->lrTable[3][61].LRTableFuncP = LRReduce;
	parser->lrTable[3][61].actionParam = 38;
	//reduce
	parser->lrTable[4][61].LRTableFuncP = LRReduce;
	parser->lrTable[4][61].actionParam = 38;
	//reduce
	parser->lrTable[5][61].LRTableFuncP = LRReduce;
	parser->lrTable[5][61].actionParam = 38;
	//reduce
	parser->lrTable[3][61].LRTableFuncP = LRReduce;
	parser->lrTable[3][61].actionParam = 38;
	//reduce
	parser->lrTable[8][61].LRTableFuncP = LRReduce;
	parser->lrTable[8][61].actionParam = 38;
	//reduce
	parser->lrTable[11][61].LRTableFuncP = LRReduce;
	parser->lrTable[11][61].actionParam = 38;
	//reduce
	parser->lrTable[14][61].LRTableFuncP = LRReduce;
	parser->lrTable[14][61].actionParam = 38;
	//reduce
	parser->lrTable[16][61].LRTableFuncP = LRReduce;
	parser->lrTable[16][61].actionParam = 38;
	//reduce
	parser->lrTable[18][61].LRTableFuncP = LRReduce;
	parser->lrTable[18][61].actionParam = 38;
	//reduce
	parser->lrTable[21][61].LRTableFuncP = LRReduce;
	parser->lrTable[21][61].actionParam = 38;
	//reduce
	parser->lrTable[36][61].LRTableFuncP = LRReduce;
	parser->lrTable[36][61].actionParam = 38;
	//reduce
	parser->lrTable[37][61].LRTableFuncP = LRReduce;
	parser->lrTable[37][61].actionParam = 38;
	//reduce
	parser->lrTable[45][61].LRTableFuncP = LRReduce;
	parser->lrTable[45][61].actionParam = 38;
	//shift
	parser->lrTable[0][62].LRTableFuncP = LRShift;
	parser->lrTable[0][62].actionParam = 66;
	//shift
	parser->lrTable[1][62].LRTableFuncP = LRShift;
	parser->lrTable[1][62].actionParam = 67;
	//shift
	parser->lrTable[2][62].LRTableFuncP = LRShift;
	parser->lrTable[2][62].actionParam = 68;
	//shift
	parser->lrTable[3][62].LRTableFuncP = LRShift;
	parser->lrTable[3][62].actionParam = 69;
	//shift
	parser->lrTable[4][62].LRTableFuncP = LRShift;
	parser->lrTable[4][62].actionParam = 70;
	//shift
	parser->lrTable[5][62].LRTableFuncP = LRShift;
	parser->lrTable[5][62].actionParam = 71;
	//shift
	parser->lrTable[3][62].LRTableFuncP = LRShift;
	parser->lrTable[3][62].actionParam = 72;
	//shift
	parser->lrTable[8][62].LRTableFuncP = LRShift;
	parser->lrTable[8][62].actionParam = 73;
	//shift
	parser->lrTable[11][62].LRTableFuncP = LRShift;
	parser->lrTable[11][62].actionParam = 74;
	//shift
	parser->lrTable[21][62].LRTableFuncP = LRShift;
	parser->lrTable[21][62].actionParam = 85;
	//shift
	parser->lrTable[36][62].LRTableFuncP = LRShift;
	parser->lrTable[36][62].actionParam = 75;
	//shift
	parser->lrTable[37][62].LRTableFuncP = LRShift;
	parser->lrTable[37][62].actionParam = 76;
	//goto
	parser->lrTable[RelOp+TOTAL_TOKENS][62].LRTableFuncP = LRGoto;
	parser->lrTable[RelOp+TOTAL_TOKENS][62].actionParam = 77;
	//shift
	parser->lrTable[21][63].LRTableFuncP = LRShift;
	parser->lrTable[21][63].actionParam = 86;
	//reduce
	parser->lrTable[0][64].LRTableFuncP = LRReduce;
	parser->lrTable[0][64].actionParam = 35;
	//reduce
	parser->lrTable[1][64].LRTableFuncP = LRReduce;
	parser->lrTable[1][64].actionParam = 35;
	//reduce
	parser->lrTable[2][64].LRTableFuncP = LRReduce;
	parser->lrTable[2][64].actionParam = 35;
	//reduce
	parser->lrTable[3][64].LRTableFuncP = LRReduce;
	parser->lrTable[3][64].actionParam = 35;
	//reduce
	parser->lrTable[4][64].LRTableFuncP = LRReduce;
	parser->lrTable[4][64].actionParam = 35;
	//reduce
	parser->lrTable[5][64].LRTableFuncP = LRReduce;
	parser->lrTable[5][64].actionParam = 35;
	//reduce
	parser->lrTable[3][64].LRTableFuncP = LRReduce;
	parser->lrTable[3][64].actionParam = 35;
	//reduce
	parser->lrTable[8][64].LRTableFuncP = LRReduce;
	parser->lrTable[8][64].actionParam = 35;
	//reduce
	parser->lrTable[11][64].LRTableFuncP = LRReduce;
	parser->lrTable[11][64].actionParam = 35;
	//reduce
	parser->lrTable[14][64].LRTableFuncP = LRReduce;
	parser->lrTable[14][64].actionParam = 35;
	//reduce
	parser->lrTable[16][64].LRTableFuncP = LRReduce;
	parser->lrTable[16][64].actionParam = 35;
	//reduce
	parser->lrTable[18][64].LRTableFuncP = LRReduce;
	parser->lrTable[18][64].actionParam = 35;
	//reduce
	parser->lrTable[21][64].LRTableFuncP = LRReduce;
	parser->lrTable[21][64].actionParam = 35;
	//reduce
	parser->lrTable[36][64].LRTableFuncP = LRReduce;
	parser->lrTable[36][64].actionParam = 35;
	//reduce
	parser->lrTable[37][64].LRTableFuncP = LRReduce;
	parser->lrTable[37][64].actionParam = 35;
	//reduce
	parser->lrTable[45][64].LRTableFuncP = LRReduce;
	parser->lrTable[45][64].actionParam = 35;
	//reduce
	parser->lrTable[0][65].LRTableFuncP = LRReduce;
	parser->lrTable[0][65].actionParam = 36;
	//reduce
	parser->lrTable[1][65].LRTableFuncP = LRReduce;
	parser->lrTable[1][65].actionParam = 36;
	//reduce
	parser->lrTable[2][65].LRTableFuncP = LRReduce;
	parser->lrTable[2][65].actionParam = 36;
	//reduce
	parser->lrTable[3][65].LRTableFuncP = LRReduce;
	parser->lrTable[3][65].actionParam = 36;
	//reduce
	parser->lrTable[4][65].LRTableFuncP = LRReduce;
	parser->lrTable[4][65].actionParam = 36;
	//reduce
	parser->lrTable[5][65].LRTableFuncP = LRReduce;
	parser->lrTable[5][65].actionParam = 36;
	//reduce
	parser->lrTable[3][65].LRTableFuncP = LRReduce;
	parser->lrTable[3][65].actionParam = 36;
	//reduce
	parser->lrTable[8][65].LRTableFuncP = LRReduce;
	parser->lrTable[8][65].actionParam = 36;
	//reduce
	parser->lrTable[11][65].LRTableFuncP = LRReduce;
	parser->lrTable[11][65].actionParam = 36;
	//reduce
	parser->lrTable[14][65].LRTableFuncP = LRReduce;
	parser->lrTable[14][65].actionParam = 36;
	//reduce
	parser->lrTable[16][65].LRTableFuncP = LRReduce;
	parser->lrTable[16][65].actionParam = 36;
	//reduce
	parser->lrTable[18][65].LRTableFuncP = LRReduce;
	parser->lrTable[18][65].actionParam = 36;
	//reduce
	parser->lrTable[21][65].LRTableFuncP = LRReduce;
	parser->lrTable[21][65].actionParam = 36;
	//reduce
	parser->lrTable[36][65].LRTableFuncP = LRReduce;
	parser->lrTable[36][65].actionParam = 36;
	//reduce
	parser->lrTable[37][65].LRTableFuncP = LRReduce;
	parser->lrTable[37][65].actionParam = 36;
	//reduce
	parser->lrTable[45][65].LRTableFuncP = LRReduce;
	parser->lrTable[45][65].actionParam = 36;
	//reduce
	parser->lrTable[9][66].LRTableFuncP = LRReduce;
	parser->lrTable[9][66].actionParam = 50;
	//reduce
	parser->lrTable[12][66].LRTableFuncP = LRReduce;
	parser->lrTable[12][66].actionParam = 50;
	//reduce
	parser->lrTable[20][66].LRTableFuncP = LRReduce;
	parser->lrTable[20][66].actionParam = 50;
	//reduce
	parser->lrTable[24][66].LRTableFuncP = LRReduce;
	parser->lrTable[24][66].actionParam = 50;
	//reduce
	parser->lrTable[25][66].LRTableFuncP = LRReduce;
	parser->lrTable[25][66].actionParam = 50;
	//reduce
	parser->lrTable[26][66].LRTableFuncP = LRReduce;
	parser->lrTable[26][66].actionParam = 50;
	//reduce
	parser->lrTable[27][66].LRTableFuncP = LRReduce;
	parser->lrTable[27][66].actionParam = 50;
	//reduce
	parser->lrTable[28][66].LRTableFuncP = LRReduce;
	parser->lrTable[28][66].actionParam = 50;
	//reduce
	parser->lrTable[40][66].LRTableFuncP = LRReduce;
	parser->lrTable[40][66].actionParam = 50;
	//reduce
	parser->lrTable[9][67].LRTableFuncP = LRReduce;
	parser->lrTable[9][67].actionParam = 47;
	//reduce
	parser->lrTable[12][67].LRTableFuncP = LRReduce;
	parser->lrTable[12][67].actionParam = 47;
	//reduce
	parser->lrTable[20][67].LRTableFuncP = LRReduce;
	parser->lrTable[20][67].actionParam = 47;
	//reduce
	parser->lrTable[24][67].LRTableFuncP = LRReduce;
	parser->lrTable[24][67].actionParam = 47;
	//reduce
	parser->lrTable[25][67].LRTableFuncP = LRReduce;
	parser->lrTable[25][67].actionParam = 47;
	//reduce
	parser->lrTable[26][67].LRTableFuncP = LRReduce;
	parser->lrTable[26][67].actionParam = 47;
	//reduce
	parser->lrTable[27][67].LRTableFuncP = LRReduce;
	parser->lrTable[27][67].actionParam = 47;
	//reduce
	parser->lrTable[28][67].LRTableFuncP = LRReduce;
	parser->lrTable[28][67].actionParam = 47;
	//reduce
	parser->lrTable[40][67].LRTableFuncP = LRReduce;
	parser->lrTable[40][67].actionParam = 47;
	//reduce
	parser->lrTable[9][68].LRTableFuncP = LRReduce;
	parser->lrTable[9][68].actionParam = 48;
	//reduce
	parser->lrTable[12][68].LRTableFuncP = LRReduce;
	parser->lrTable[12][68].actionParam = 48;
	//reduce
	parser->lrTable[20][68].LRTableFuncP = LRReduce;
	parser->lrTable[20][68].actionParam = 48;
	//reduce
	parser->lrTable[24][68].LRTableFuncP = LRReduce;
	parser->lrTable[24][68].actionParam = 48;
	//reduce
	parser->lrTable[25][68].LRTableFuncP = LRReduce;
	parser->lrTable[25][68].actionParam = 48;
	//reduce
	parser->lrTable[26][68].LRTableFuncP = LRReduce;
	parser->lrTable[26][68].actionParam = 48;
	//reduce
	parser->lrTable[27][68].LRTableFuncP = LRReduce;
	parser->lrTable[27][68].actionParam = 48;
	//reduce
	parser->lrTable[28][68].LRTableFuncP = LRReduce;
	parser->lrTable[28][68].actionParam = 48;
	//reduce
	parser->lrTable[40][68].LRTableFuncP = LRReduce;
	parser->lrTable[40][68].actionParam = 48;
	//reduce
	parser->lrTable[9][69].LRTableFuncP = LRReduce;
	parser->lrTable[9][69].actionParam = 44;
	//reduce
	parser->lrTable[12][69].LRTableFuncP = LRReduce;
	parser->lrTable[12][69].actionParam = 44;
	//reduce
	parser->lrTable[20][69].LRTableFuncP = LRReduce;
	parser->lrTable[20][69].actionParam = 44;
	//reduce
	parser->lrTable[24][69].LRTableFuncP = LRReduce;
	parser->lrTable[24][69].actionParam = 44;
	//reduce
	parser->lrTable[25][69].LRTableFuncP = LRReduce;
	parser->lrTable[25][69].actionParam = 44;
	//reduce
	parser->lrTable[26][69].LRTableFuncP = LRReduce;
	parser->lrTable[26][69].actionParam = 44;
	//reduce
	parser->lrTable[27][69].LRTableFuncP = LRReduce;
	parser->lrTable[27][69].actionParam = 44;
	//reduce
	parser->lrTable[28][69].LRTableFuncP = LRReduce;
	parser->lrTable[28][69].actionParam = 44;
	//reduce
	parser->lrTable[40][69].LRTableFuncP = LRReduce;
	parser->lrTable[40][69].actionParam = 44;
	//reduce
	parser->lrTable[9][70].LRTableFuncP = LRReduce;
	parser->lrTable[9][70].actionParam = 45;
	//reduce
	parser->lrTable[12][70].LRTableFuncP = LRReduce;
	parser->lrTable[12][70].actionParam = 45;
	//reduce
	parser->lrTable[20][70].LRTableFuncP = LRReduce;
	parser->lrTable[20][70].actionParam = 45;
	//reduce
	parser->lrTable[24][70].LRTableFuncP = LRReduce;
	parser->lrTable[24][70].actionParam = 45;
	//reduce
	parser->lrTable[25][70].LRTableFuncP = LRReduce;
	parser->lrTable[25][70].actionParam = 45;
	//reduce
	parser->lrTable[26][70].LRTableFuncP = LRReduce;
	parser->lrTable[26][70].actionParam = 45;
	//reduce
	parser->lrTable[27][70].LRTableFuncP = LRReduce;
	parser->lrTable[27][70].actionParam = 45;
	//reduce
	parser->lrTable[28][70].LRTableFuncP = LRReduce;
	parser->lrTable[28][70].actionParam = 45;
	//reduce
	parser->lrTable[40][70].LRTableFuncP = LRReduce;
	parser->lrTable[40][70].actionParam = 45;
	//reduce
	parser->lrTable[9][71].LRTableFuncP = LRReduce;
	parser->lrTable[9][71].actionParam = 46;
	//reduce
	parser->lrTable[12][71].LRTableFuncP = LRReduce;
	parser->lrTable[12][71].actionParam = 46;
	//reduce
	parser->lrTable[20][71].LRTableFuncP = LRReduce;
	parser->lrTable[20][71].actionParam = 46;
	//reduce
	parser->lrTable[24][71].LRTableFuncP = LRReduce;
	parser->lrTable[24][71].actionParam = 46;
	//reduce
	parser->lrTable[25][71].LRTableFuncP = LRReduce;
	parser->lrTable[25][71].actionParam = 46;
	//reduce
	parser->lrTable[26][71].LRTableFuncP = LRReduce;
	parser->lrTable[26][71].actionParam = 46;
	//reduce
	parser->lrTable[27][71].LRTableFuncP = LRReduce;
	parser->lrTable[27][71].actionParam = 46;
	//reduce
	parser->lrTable[28][71].LRTableFuncP = LRReduce;
	parser->lrTable[28][71].actionParam = 46;
	//reduce
	parser->lrTable[40][71].LRTableFuncP = LRReduce;
	parser->lrTable[40][71].actionParam = 46;
	//reduce
	parser->lrTable[9][72].LRTableFuncP = LRReduce;
	parser->lrTable[9][72].actionParam = 49;
	//reduce
	parser->lrTable[12][72].LRTableFuncP = LRReduce;
	parser->lrTable[12][72].actionParam = 49;
	//reduce
	parser->lrTable[20][72].LRTableFuncP = LRReduce;
	parser->lrTable[20][72].actionParam = 49;
	//reduce
	parser->lrTable[24][72].LRTableFuncP = LRReduce;
	parser->lrTable[24][72].actionParam = 49;
	//reduce
	parser->lrTable[25][72].LRTableFuncP = LRReduce;
	parser->lrTable[25][72].actionParam = 49;
	//reduce
	parser->lrTable[26][72].LRTableFuncP = LRReduce;
	parser->lrTable[26][72].actionParam = 49;
	//reduce
	parser->lrTable[27][72].LRTableFuncP = LRReduce;
	parser->lrTable[27][72].actionParam = 49;
	//reduce
	parser->lrTable[28][72].LRTableFuncP = LRReduce;
	parser->lrTable[28][72].actionParam = 49;
	//reduce
	parser->lrTable[40][72].LRTableFuncP = LRReduce;
	parser->lrTable[40][72].actionParam = 49;
	//shift
	parser->lrTable[9][73].LRTableFuncP = LRShift;
	parser->lrTable[9][73].actionParam = 37;
	//shift
	parser->lrTable[12][73].LRTableFuncP = LRShift;
	parser->lrTable[12][73].actionParam = 38;
	//shift
	parser->lrTable[20][73].LRTableFuncP = LRShift;
	parser->lrTable[20][73].actionParam = 52;
	//shift
	parser->lrTable[24][73].LRTableFuncP = LRShift;
	parser->lrTable[24][73].actionParam = 40;
	//shift
	parser->lrTable[25][73].LRTableFuncP = LRShift;
	parser->lrTable[25][73].actionParam = 41;
	//shift
	parser->lrTable[26][73].LRTableFuncP = LRShift;
	parser->lrTable[26][73].actionParam = 42;
	//shift
	parser->lrTable[27][73].LRTableFuncP = LRShift;
	parser->lrTable[27][73].actionParam = 43;
	//shift
	parser->lrTable[28][73].LRTableFuncP = LRShift;
	parser->lrTable[28][73].actionParam = 44;
	//shift
	parser->lrTable[40][73].LRTableFuncP = LRShift;
	parser->lrTable[40][73].actionParam = 45;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][73].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][73].actionParam = 87;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][73].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][73].actionParam = 48;
	//shift
	parser->lrTable[9][74].LRTableFuncP = LRShift;
	parser->lrTable[9][74].actionParam = 37;
	//shift
	parser->lrTable[12][74].LRTableFuncP = LRShift;
	parser->lrTable[12][74].actionParam = 38;
	//shift
	parser->lrTable[20][74].LRTableFuncP = LRShift;
	parser->lrTable[20][74].actionParam = 52;
	//shift
	parser->lrTable[24][74].LRTableFuncP = LRShift;
	parser->lrTable[24][74].actionParam = 40;
	//shift
	parser->lrTable[25][74].LRTableFuncP = LRShift;
	parser->lrTable[25][74].actionParam = 41;
	//shift
	parser->lrTable[26][74].LRTableFuncP = LRShift;
	parser->lrTable[26][74].actionParam = 42;
	//shift
	parser->lrTable[27][74].LRTableFuncP = LRShift;
	parser->lrTable[27][74].actionParam = 43;
	//shift
	parser->lrTable[28][74].LRTableFuncP = LRShift;
	parser->lrTable[28][74].actionParam = 44;
	//shift
	parser->lrTable[40][74].LRTableFuncP = LRShift;
	parser->lrTable[40][74].actionParam = 45;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][74].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][74].actionParam = 88;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][74].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][74].actionParam = 48;
	//shift
	parser->lrTable[9][75].LRTableFuncP = LRShift;
	parser->lrTable[9][75].actionParam = 37;
	//shift
	parser->lrTable[12][75].LRTableFuncP = LRShift;
	parser->lrTable[12][75].actionParam = 38;
	//shift
	parser->lrTable[20][75].LRTableFuncP = LRShift;
	parser->lrTable[20][75].actionParam = 52;
	//shift
	parser->lrTable[24][75].LRTableFuncP = LRShift;
	parser->lrTable[24][75].actionParam = 40;
	//shift
	parser->lrTable[25][75].LRTableFuncP = LRShift;
	parser->lrTable[25][75].actionParam = 41;
	//shift
	parser->lrTable[26][75].LRTableFuncP = LRShift;
	parser->lrTable[26][75].actionParam = 42;
	//shift
	parser->lrTable[27][75].LRTableFuncP = LRShift;
	parser->lrTable[27][75].actionParam = 43;
	//shift
	parser->lrTable[28][75].LRTableFuncP = LRShift;
	parser->lrTable[28][75].actionParam = 44;
	//shift
	parser->lrTable[40][75].LRTableFuncP = LRShift;
	parser->lrTable[40][75].actionParam = 45;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][75].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][75].actionParam = 89;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][75].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][75].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][75].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][75].actionParam = 48;
	//shift
	parser->lrTable[9][76].LRTableFuncP = LRShift;
	parser->lrTable[9][76].actionParam = 37;
	//shift
	parser->lrTable[12][76].LRTableFuncP = LRShift;
	parser->lrTable[12][76].actionParam = 38;
	//shift
	parser->lrTable[20][76].LRTableFuncP = LRShift;
	parser->lrTable[20][76].actionParam = 52;
	//shift
	parser->lrTable[24][76].LRTableFuncP = LRShift;
	parser->lrTable[24][76].actionParam = 40;
	//shift
	parser->lrTable[25][76].LRTableFuncP = LRShift;
	parser->lrTable[25][76].actionParam = 41;
	//shift
	parser->lrTable[26][76].LRTableFuncP = LRShift;
	parser->lrTable[26][76].actionParam = 42;
	//shift
	parser->lrTable[27][76].LRTableFuncP = LRShift;
	parser->lrTable[27][76].actionParam = 43;
	//shift
	parser->lrTable[28][76].LRTableFuncP = LRShift;
	parser->lrTable[28][76].actionParam = 44;
	//shift
	parser->lrTable[40][76].LRTableFuncP = LRShift;
	parser->lrTable[40][76].actionParam = 45;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][76].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][76].actionParam = 90;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][76].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][76].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][76].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][76].actionParam = 48;
	//shift
	parser->lrTable[9][77].LRTableFuncP = LRShift;
	parser->lrTable[9][77].actionParam = 37;
	//shift
	parser->lrTable[12][77].LRTableFuncP = LRShift;
	parser->lrTable[12][77].actionParam = 38;
	//shift
	parser->lrTable[20][77].LRTableFuncP = LRShift;
	parser->lrTable[20][77].actionParam = 52;
	//shift
	parser->lrTable[24][77].LRTableFuncP = LRShift;
	parser->lrTable[24][77].actionParam = 40;
	//shift
	parser->lrTable[25][77].LRTableFuncP = LRShift;
	parser->lrTable[25][77].actionParam = 41;
	//shift
	parser->lrTable[26][77].LRTableFuncP = LRShift;
	parser->lrTable[26][77].actionParam = 42;
	//shift
	parser->lrTable[27][77].LRTableFuncP = LRShift;
	parser->lrTable[27][77].actionParam = 43;
	//shift
	parser->lrTable[28][77].LRTableFuncP = LRShift;
	parser->lrTable[28][77].actionParam = 44;
	//shift
	parser->lrTable[40][77].LRTableFuncP = LRShift;
	parser->lrTable[40][77].actionParam = 45;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][77].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][77].actionParam = 91;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][77].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][77].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][77].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][77].actionParam = 48;
	//shift
	parser->lrTable[9][78].LRTableFuncP = LRShift;
	parser->lrTable[9][78].actionParam = 37;
	//shift
	parser->lrTable[12][78].LRTableFuncP = LRShift;
	parser->lrTable[12][78].actionParam = 38;
	//shift
	parser->lrTable[20][78].LRTableFuncP = LRShift;
	parser->lrTable[20][78].actionParam = 52;
	//shift
	parser->lrTable[24][78].LRTableFuncP = LRShift;
	parser->lrTable[24][78].actionParam = 40;
	//shift
	parser->lrTable[25][78].LRTableFuncP = LRShift;
	parser->lrTable[25][78].actionParam = 41;
	//shift
	parser->lrTable[26][78].LRTableFuncP = LRShift;
	parser->lrTable[26][78].actionParam = 42;
	//shift
	parser->lrTable[27][78].LRTableFuncP = LRShift;
	parser->lrTable[27][78].actionParam = 43;
	//shift
	parser->lrTable[28][78].LRTableFuncP = LRShift;
	parser->lrTable[28][78].actionParam = 44;
	//shift
	parser->lrTable[40][78].LRTableFuncP = LRShift;
	parser->lrTable[40][78].actionParam = 45;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][78].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][78].actionParam = 92;
	//shift
	parser->lrTable[9][79].LRTableFuncP = LRShift;
	parser->lrTable[9][79].actionParam = 37;
	//shift
	parser->lrTable[12][79].LRTableFuncP = LRShift;
	parser->lrTable[12][79].actionParam = 38;
	//shift
	parser->lrTable[20][79].LRTableFuncP = LRShift;
	parser->lrTable[20][79].actionParam = 52;
	//shift
	parser->lrTable[24][79].LRTableFuncP = LRShift;
	parser->lrTable[24][79].actionParam = 40;
	//shift
	parser->lrTable[25][79].LRTableFuncP = LRShift;
	parser->lrTable[25][79].actionParam = 41;
	//shift
	parser->lrTable[26][79].LRTableFuncP = LRShift;
	parser->lrTable[26][79].actionParam = 42;
	//shift
	parser->lrTable[27][79].LRTableFuncP = LRShift;
	parser->lrTable[27][79].actionParam = 43;
	//shift
	parser->lrTable[28][79].LRTableFuncP = LRShift;
	parser->lrTable[28][79].actionParam = 44;
	//shift
	parser->lrTable[40][79].LRTableFuncP = LRShift;
	parser->lrTable[40][79].actionParam = 45;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][79].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][79].actionParam = 93;
	//shift
	parser->lrTable[9][80].LRTableFuncP = LRShift;
	parser->lrTable[9][80].actionParam = 37;
	//shift
	parser->lrTable[12][80].LRTableFuncP = LRShift;
	parser->lrTable[12][80].actionParam = 38;
	//shift
	parser->lrTable[20][80].LRTableFuncP = LRShift;
	parser->lrTable[20][80].actionParam = 52;
	//shift
	parser->lrTable[24][80].LRTableFuncP = LRShift;
	parser->lrTable[24][80].actionParam = 40;
	//shift
	parser->lrTable[25][80].LRTableFuncP = LRShift;
	parser->lrTable[25][80].actionParam = 41;
	//shift
	parser->lrTable[26][80].LRTableFuncP = LRShift;
	parser->lrTable[26][80].actionParam = 42;
	//shift
	parser->lrTable[27][80].LRTableFuncP = LRShift;
	parser->lrTable[27][80].actionParam = 43;
	//shift
	parser->lrTable[28][80].LRTableFuncP = LRShift;
	parser->lrTable[28][80].actionParam = 44;
	//shift
	parser->lrTable[40][80].LRTableFuncP = LRShift;
	parser->lrTable[40][80].actionParam = 45;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][80].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][80].actionParam = 94;
	//shift
	parser->lrTable[22][81].LRTableFuncP = LRShift;
	parser->lrTable[22][81].actionParam = 95;
	//shift
	parser->lrTable[5][82].LRTableFuncP = LRShift;
	parser->lrTable[5][82].actionParam = 36;
	//shift
	parser->lrTable[9][82].LRTableFuncP = LRShift;
	parser->lrTable[9][82].actionParam = 37;
	//shift
	parser->lrTable[12][82].LRTableFuncP = LRShift;
	parser->lrTable[12][82].actionParam = 38;
	//shift
	parser->lrTable[20][82].LRTableFuncP = LRShift;
	parser->lrTable[20][82].actionParam = 39;
	//shift
	parser->lrTable[24][82].LRTableFuncP = LRShift;
	parser->lrTable[24][82].actionParam = 40;
	//shift
	parser->lrTable[25][82].LRTableFuncP = LRShift;
	parser->lrTable[25][82].actionParam = 41;
	//shift
	parser->lrTable[26][82].LRTableFuncP = LRShift;
	parser->lrTable[26][82].actionParam = 42;
	//shift
	parser->lrTable[27][82].LRTableFuncP = LRShift;
	parser->lrTable[27][82].actionParam = 43;
	//shift
	parser->lrTable[28][82].LRTableFuncP = LRShift;
	parser->lrTable[28][82].actionParam = 44;
	//shift
	parser->lrTable[40][82].LRTableFuncP = LRShift;
	parser->lrTable[40][82].actionParam = 45;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][82].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][82].actionParam = 46;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][82].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][82].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][82].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][82].actionParam = 48;
	//goto
	parser->lrTable[CondExpr+TOTAL_TOKENS][82].LRTableFuncP = LRGoto;
	parser->lrTable[CondExpr+TOTAL_TOKENS][82].actionParam = 96;
	//shift
	parser->lrTable[22][83].LRTableFuncP = LRShift;
	parser->lrTable[22][83].actionParam = 97;
	//shift
	parser->lrTable[8][84].LRTableFuncP = LRShift;
	parser->lrTable[8][84].actionParam = 73;
	//shift
	parser->lrTable[11][84].LRTableFuncP = LRShift;
	parser->lrTable[11][84].actionParam = 74;
	//shift
	parser->lrTable[21][84].LRTableFuncP = LRShift;
	parser->lrTable[21][84].actionParam = 85;
	//reduce
	parser->lrTable[0][85].LRTableFuncP = LRReduce;
	parser->lrTable[0][85].actionParam = 28;
	//reduce
	parser->lrTable[1][85].LRTableFuncP = LRReduce;
	parser->lrTable[1][85].actionParam = 28;
	//reduce
	parser->lrTable[2][85].LRTableFuncP = LRReduce;
	parser->lrTable[2][85].actionParam = 28;
	//reduce
	parser->lrTable[3][85].LRTableFuncP = LRReduce;
	parser->lrTable[3][85].actionParam = 28;
	//reduce
	parser->lrTable[4][85].LRTableFuncP = LRReduce;
	parser->lrTable[4][85].actionParam = 28;
	//reduce
	parser->lrTable[5][85].LRTableFuncP = LRReduce;
	parser->lrTable[5][85].actionParam = 28;
	//reduce
	parser->lrTable[3][85].LRTableFuncP = LRReduce;
	parser->lrTable[3][85].actionParam = 28;
	//reduce
	parser->lrTable[8][85].LRTableFuncP = LRReduce;
	parser->lrTable[8][85].actionParam = 28;
	//reduce
	parser->lrTable[11][85].LRTableFuncP = LRReduce;
	parser->lrTable[11][85].actionParam = 28;
	//reduce
	parser->lrTable[14][85].LRTableFuncP = LRReduce;
	parser->lrTable[14][85].actionParam = 28;
	//reduce
	parser->lrTable[16][85].LRTableFuncP = LRReduce;
	parser->lrTable[16][85].actionParam = 28;
	//reduce
	parser->lrTable[18][85].LRTableFuncP = LRReduce;
	parser->lrTable[18][85].actionParam = 28;
	//reduce
	parser->lrTable[21][85].LRTableFuncP = LRReduce;
	parser->lrTable[21][85].actionParam = 28;
	//reduce
	parser->lrTable[36][85].LRTableFuncP = LRReduce;
	parser->lrTable[36][85].actionParam = 28;
	//reduce
	parser->lrTable[37][85].LRTableFuncP = LRReduce;
	parser->lrTable[37][85].actionParam = 28;
	//reduce
	parser->lrTable[45][85].LRTableFuncP = LRReduce;
	parser->lrTable[45][85].actionParam = 28;
	//reduce
	parser->lrTable[21][86].LRTableFuncP = LRReduce;
	parser->lrTable[21][86].actionParam = 43;
	//reduce
	parser->lrTable[45][86].LRTableFuncP = LRReduce;
	parser->lrTable[45][86].actionParam = 43;
	//shift
	parser->lrTable[14][87].LRTableFuncP = LRShift;
	parser->lrTable[14][87].actionParam = 78;
	//shift
	parser->lrTable[16][87].LRTableFuncP = LRShift;
	parser->lrTable[16][87].actionParam = 79;
	//shift
	parser->lrTable[18][87].LRTableFuncP = LRShift;
	parser->lrTable[18][87].actionParam = 80;
	//reduce
	parser->lrTable[0][87].LRTableFuncP = LRReduce;
	parser->lrTable[0][87].actionParam = 21;
	//reduce
	parser->lrTable[1][87].LRTableFuncP = LRReduce;
	parser->lrTable[1][87].actionParam = 21;
	//reduce
	parser->lrTable[2][87].LRTableFuncP = LRReduce;
	parser->lrTable[2][87].actionParam = 21;
	//reduce
	parser->lrTable[3][87].LRTableFuncP = LRReduce;
	parser->lrTable[3][87].actionParam = 21;
	//reduce
	parser->lrTable[4][87].LRTableFuncP = LRReduce;
	parser->lrTable[4][87].actionParam = 21;
	//reduce
	parser->lrTable[5][87].LRTableFuncP = LRReduce;
	parser->lrTable[5][87].actionParam = 21;
	//reduce
	parser->lrTable[3][87].LRTableFuncP = LRReduce;
	parser->lrTable[3][87].actionParam = 21;
	//reduce
	parser->lrTable[8][87].LRTableFuncP = LRReduce;
	parser->lrTable[8][87].actionParam = 21;
	//reduce
	parser->lrTable[11][87].LRTableFuncP = LRReduce;
	parser->lrTable[11][87].actionParam = 21;
	//reduce
	parser->lrTable[21][87].LRTableFuncP = LRReduce;
	parser->lrTable[21][87].actionParam = 21;
	//reduce
	parser->lrTable[36][87].LRTableFuncP = LRReduce;
	parser->lrTable[36][87].actionParam = 21;
	//reduce
	parser->lrTable[37][87].LRTableFuncP = LRReduce;
	parser->lrTable[37][87].actionParam = 21;
	//reduce
	parser->lrTable[45][87].LRTableFuncP = LRReduce;
	parser->lrTable[45][87].actionParam = 21;
	//shift
	parser->lrTable[14][88].LRTableFuncP = LRShift;
	parser->lrTable[14][88].actionParam = 78;
	//shift
	parser->lrTable[16][88].LRTableFuncP = LRShift;
	parser->lrTable[16][88].actionParam = 79;
	//shift
	parser->lrTable[18][88].LRTableFuncP = LRShift;
	parser->lrTable[18][88].actionParam = 80;
	//reduce
	parser->lrTable[0][88].LRTableFuncP = LRReduce;
	parser->lrTable[0][88].actionParam = 22;
	//reduce
	parser->lrTable[1][88].LRTableFuncP = LRReduce;
	parser->lrTable[1][88].actionParam = 22;
	//reduce
	parser->lrTable[2][88].LRTableFuncP = LRReduce;
	parser->lrTable[2][88].actionParam = 22;
	//reduce
	parser->lrTable[3][88].LRTableFuncP = LRReduce;
	parser->lrTable[3][88].actionParam = 22;
	//reduce
	parser->lrTable[4][88].LRTableFuncP = LRReduce;
	parser->lrTable[4][88].actionParam = 22;
	//reduce
	parser->lrTable[5][88].LRTableFuncP = LRReduce;
	parser->lrTable[5][88].actionParam = 22;
	//reduce
	parser->lrTable[3][88].LRTableFuncP = LRReduce;
	parser->lrTable[3][88].actionParam = 22;
	//reduce
	parser->lrTable[8][88].LRTableFuncP = LRReduce;
	parser->lrTable[8][88].actionParam = 22;
	//reduce
	parser->lrTable[11][88].LRTableFuncP = LRReduce;
	parser->lrTable[11][88].actionParam = 22;
	//reduce
	parser->lrTable[21][88].LRTableFuncP = LRReduce;
	parser->lrTable[21][88].actionParam = 22;
	//reduce
	parser->lrTable[36][88].LRTableFuncP = LRReduce;
	parser->lrTable[36][88].actionParam = 22;
	//reduce
	parser->lrTable[37][88].LRTableFuncP = LRReduce;
	parser->lrTable[37][88].actionParam = 22;
	//reduce
	parser->lrTable[45][88].LRTableFuncP = LRReduce;
	parser->lrTable[45][88].actionParam = 22;
	//shift
	parser->lrTable[8][89].LRTableFuncP = LRShift;
	parser->lrTable[8][89].actionParam = 73;
	//shift
	parser->lrTable[11][89].LRTableFuncP = LRShift;
	parser->lrTable[11][89].actionParam = 74;
	//reduce
	parser->lrTable[21][89].LRTableFuncP = LRReduce;
	parser->lrTable[21][89].actionParam = 41;
	//reduce
	parser->lrTable[45][89].LRTableFuncP = LRReduce;
	parser->lrTable[45][89].actionParam = 41;
	//shift
	parser->lrTable[8][90].LRTableFuncP = LRShift;
	parser->lrTable[8][90].actionParam = 73;
	//shift
	parser->lrTable[11][90].LRTableFuncP = LRShift;
	parser->lrTable[11][90].actionParam = 74;
	//reduce
	parser->lrTable[21][90].LRTableFuncP = LRReduce;
	parser->lrTable[21][90].actionParam = 42;
	//reduce
	parser->lrTable[45][90].LRTableFuncP = LRReduce;
	parser->lrTable[45][90].actionParam = 42;
	//shift
	parser->lrTable[8][91].LRTableFuncP = LRShift;
	parser->lrTable[8][91].actionParam = 73;
	//shift
	parser->lrTable[11][91].LRTableFuncP = LRShift;
	parser->lrTable[11][91].actionParam = 74;
	//reduce
	parser->lrTable[21][91].LRTableFuncP = LRReduce;
	parser->lrTable[21][91].actionParam = 39;
	//reduce
	parser->lrTable[45][91].LRTableFuncP = LRReduce;
	parser->lrTable[45][91].actionParam = 39;
	//reduce
	parser->lrTable[0][92].LRTableFuncP = LRReduce;
	parser->lrTable[0][92].actionParam = 25;
	//reduce
	parser->lrTable[1][92].LRTableFuncP = LRReduce;
	parser->lrTable[1][92].actionParam = 25;
	//reduce
	parser->lrTable[2][92].LRTableFuncP = LRReduce;
	parser->lrTable[2][92].actionParam = 25;
	//reduce
	parser->lrTable[3][92].LRTableFuncP = LRReduce;
	parser->lrTable[3][92].actionParam = 25;
	//reduce
	parser->lrTable[4][92].LRTableFuncP = LRReduce;
	parser->lrTable[4][92].actionParam = 25;
	//reduce
	parser->lrTable[5][92].LRTableFuncP = LRReduce;
	parser->lrTable[5][92].actionParam = 25;
	//reduce
	parser->lrTable[3][92].LRTableFuncP = LRReduce;
	parser->lrTable[3][92].actionParam = 25;
	//reduce
	parser->lrTable[8][92].LRTableFuncP = LRReduce;
	parser->lrTable[8][92].actionParam = 25;
	//reduce
	parser->lrTable[11][92].LRTableFuncP = LRReduce;
	parser->lrTable[11][92].actionParam = 25;
	//reduce
	parser->lrTable[14][92].LRTableFuncP = LRReduce;
	parser->lrTable[14][92].actionParam = 25;
	//reduce
	parser->lrTable[16][92].LRTableFuncP = LRReduce;
	parser->lrTable[16][92].actionParam = 25;
	//reduce
	parser->lrTable[18][92].LRTableFuncP = LRReduce;
	parser->lrTable[18][92].actionParam = 25;
	//reduce
	parser->lrTable[21][92].LRTableFuncP = LRReduce;
	parser->lrTable[21][92].actionParam = 25;
	//reduce
	parser->lrTable[36][92].LRTableFuncP = LRReduce;
	parser->lrTable[36][92].actionParam = 25;
	//reduce
	parser->lrTable[37][92].LRTableFuncP = LRReduce;
	parser->lrTable[37][92].actionParam = 25;
	//reduce
	parser->lrTable[45][92].LRTableFuncP = LRReduce;
	parser->lrTable[45][92].actionParam = 25;
	//reduce
	parser->lrTable[0][93].LRTableFuncP = LRReduce;
	parser->lrTable[0][93].actionParam = 24;
	//reduce
	parser->lrTable[1][93].LRTableFuncP = LRReduce;
	parser->lrTable[1][93].actionParam = 24;
	//reduce
	parser->lrTable[2][93].LRTableFuncP = LRReduce;
	parser->lrTable[2][93].actionParam = 24;
	//reduce
	parser->lrTable[3][93].LRTableFuncP = LRReduce;
	parser->lrTable[3][93].actionParam = 24;
	//reduce
	parser->lrTable[4][93].LRTableFuncP = LRReduce;
	parser->lrTable[4][93].actionParam = 24;
	//reduce
	parser->lrTable[5][93].LRTableFuncP = LRReduce;
	parser->lrTable[5][93].actionParam = 24;
	//reduce
	parser->lrTable[3][93].LRTableFuncP = LRReduce;
	parser->lrTable[3][93].actionParam = 24;
	//reduce
	parser->lrTable[8][93].LRTableFuncP = LRReduce;
	parser->lrTable[8][93].actionParam = 24;
	//reduce
	parser->lrTable[11][93].LRTableFuncP = LRReduce;
	parser->lrTable[11][93].actionParam = 24;
	//reduce
	parser->lrTable[14][93].LRTableFuncP = LRReduce;
	parser->lrTable[14][93].actionParam = 24;
	//reduce
	parser->lrTable[16][93].LRTableFuncP = LRReduce;
	parser->lrTable[16][93].actionParam = 24;
	//reduce
	parser->lrTable[18][93].LRTableFuncP = LRReduce;
	parser->lrTable[18][93].actionParam = 24;
	//reduce
	parser->lrTable[21][93].LRTableFuncP = LRReduce;
	parser->lrTable[21][93].actionParam = 24;
	//reduce
	parser->lrTable[36][93].LRTableFuncP = LRReduce;
	parser->lrTable[36][93].actionParam = 24;
	//reduce
	parser->lrTable[37][93].LRTableFuncP = LRReduce;
	parser->lrTable[37][93].actionParam = 24;
	//reduce
	parser->lrTable[45][93].LRTableFuncP = LRReduce;
	parser->lrTable[45][93].actionParam = 24;
	//reduce
	parser->lrTable[0][94].LRTableFuncP = LRReduce;
	parser->lrTable[0][94].actionParam = 26;
	//reduce
	parser->lrTable[1][94].LRTableFuncP = LRReduce;
	parser->lrTable[1][94].actionParam = 26;
	//reduce
	parser->lrTable[2][94].LRTableFuncP = LRReduce;
	parser->lrTable[2][94].actionParam = 26;
	//reduce
	parser->lrTable[3][94].LRTableFuncP = LRReduce;
	parser->lrTable[3][94].actionParam = 26;
	//reduce
	parser->lrTable[4][94].LRTableFuncP = LRReduce;
	parser->lrTable[4][94].actionParam = 26;
	//reduce
	parser->lrTable[5][94].LRTableFuncP = LRReduce;
	parser->lrTable[5][94].actionParam = 26;
	//reduce
	parser->lrTable[3][94].LRTableFuncP = LRReduce;
	parser->lrTable[3][94].actionParam = 26;
	//reduce
	parser->lrTable[8][94].LRTableFuncP = LRReduce;
	parser->lrTable[8][94].actionParam = 26;
	//reduce
	parser->lrTable[11][94].LRTableFuncP = LRReduce;
	parser->lrTable[11][94].actionParam = 26;
	//reduce
	parser->lrTable[14][94].LRTableFuncP = LRReduce;
	parser->lrTable[14][94].actionParam = 26;
	//reduce
	parser->lrTable[16][94].LRTableFuncP = LRReduce;
	parser->lrTable[16][94].actionParam = 26;
	//reduce
	parser->lrTable[18][94].LRTableFuncP = LRReduce;
	parser->lrTable[18][94].actionParam = 26;
	//reduce
	parser->lrTable[21][94].LRTableFuncP = LRReduce;
	parser->lrTable[21][94].actionParam = 26;
	//reduce
	parser->lrTable[36][94].LRTableFuncP = LRReduce;
	parser->lrTable[36][94].actionParam = 26;
	//reduce
	parser->lrTable[37][94].LRTableFuncP = LRReduce;
	parser->lrTable[37][94].actionParam = 26;
	//reduce
	parser->lrTable[45][94].LRTableFuncP = LRReduce;
	parser->lrTable[45][94].actionParam = 26;
	//shift
	parser->lrTable[29][95].LRTableFuncP = LRShift;
	parser->lrTable[29][95].actionParam = 1;
	//shift
	parser->lrTable[30][95].LRTableFuncP = LRShift;
	parser->lrTable[30][95].actionParam = 2;
	//shift
	parser->lrTable[31][95].LRTableFuncP = LRShift;
	parser->lrTable[31][95].actionParam = 3;
	//shift
	parser->lrTable[32][95].LRTableFuncP = LRShift;
	parser->lrTable[32][95].actionParam = 4;
	//shift
	parser->lrTable[33][95].LRTableFuncP = LRShift;
	parser->lrTable[33][95].actionParam = 5;
	//shift
	parser->lrTable[38][95].LRTableFuncP = LRShift;
	parser->lrTable[38][95].actionParam = 6;
	//shift
	parser->lrTable[39][95].LRTableFuncP = LRShift;
	parser->lrTable[39][95].actionParam = 7;
	//shift
	parser->lrTable[40][95].LRTableFuncP = LRShift;
	parser->lrTable[40][95].actionParam = 8;
	//reduce
	parser->lrTable[23][95].LRTableFuncP = LRReduce;
	parser->lrTable[23][95].actionParam = 4;
	//goto
	parser->lrTable[StmtList+TOTAL_TOKENS][95].LRTableFuncP = LRGoto;
	parser->lrTable[StmtList+TOTAL_TOKENS][95].actionParam = 98;
	//goto
	parser->lrTable[Stmt+TOTAL_TOKENS][95].LRTableFuncP = LRGoto;
	parser->lrTable[Stmt+TOTAL_TOKENS][95].actionParam = 12;
	//goto
	parser->lrTable[Decl+TOTAL_TOKENS][95].LRTableFuncP = LRGoto;
	parser->lrTable[Decl+TOTAL_TOKENS][95].actionParam = 13;
	//goto
	parser->lrTable[Assi+TOTAL_TOKENS][95].LRTableFuncP = LRGoto;
	parser->lrTable[Assi+TOTAL_TOKENS][95].actionParam = 14;
	//goto
	parser->lrTable[IfStmt+TOTAL_TOKENS][95].LRTableFuncP = LRGoto;
	parser->lrTable[IfStmt+TOTAL_TOKENS][95].actionParam = 15;
	//goto
	parser->lrTable[LoopStmt+TOTAL_TOKENS][95].LRTableFuncP = LRGoto;
	parser->lrTable[LoopStmt+TOTAL_TOKENS][95].actionParam = 16;
	//shift
	parser->lrTable[45][96].LRTableFuncP = LRShift;
	parser->lrTable[45][96].actionParam = 99;
	//shift
	parser->lrTable[29][97].LRTableFuncP = LRShift;
	parser->lrTable[29][97].actionParam = 1;
	//shift
	parser->lrTable[30][97].LRTableFuncP = LRShift;
	parser->lrTable[30][97].actionParam = 2;
	//shift
	parser->lrTable[31][97].LRTableFuncP = LRShift;
	parser->lrTable[31][97].actionParam = 3;
	//shift
	parser->lrTable[32][97].LRTableFuncP = LRShift;
	parser->lrTable[32][97].actionParam = 4;
	//shift
	parser->lrTable[33][97].LRTableFuncP = LRShift;
	parser->lrTable[33][97].actionParam = 5;
	//shift
	parser->lrTable[38][97].LRTableFuncP = LRShift;
	parser->lrTable[38][97].actionParam = 6;
	//shift
	parser->lrTable[39][97].LRTableFuncP = LRShift;
	parser->lrTable[39][97].actionParam = 7;
	//shift
	parser->lrTable[40][97].LRTableFuncP = LRShift;
	parser->lrTable[40][97].actionParam = 8;
	//reduce
	parser->lrTable[23][97].LRTableFuncP = LRReduce;
	parser->lrTable[23][97].actionParam = 4;
	//goto
	parser->lrTable[StmtList+TOTAL_TOKENS][97].LRTableFuncP = LRGoto;
	parser->lrTable[StmtList+TOTAL_TOKENS][97].actionParam = 100;
	//goto
	parser->lrTable[Stmt+TOTAL_TOKENS][97].LRTableFuncP = LRGoto;
	parser->lrTable[Stmt+TOTAL_TOKENS][97].actionParam = 12;
	//goto
	parser->lrTable[Decl+TOTAL_TOKENS][97].LRTableFuncP = LRGoto;
	parser->lrTable[Decl+TOTAL_TOKENS][97].actionParam = 13;
	//goto
	parser->lrTable[Assi+TOTAL_TOKENS][97].LRTableFuncP = LRGoto;
	parser->lrTable[Assi+TOTAL_TOKENS][97].actionParam = 14;
	//goto
	parser->lrTable[IfStmt+TOTAL_TOKENS][97].LRTableFuncP = LRGoto;
	parser->lrTable[IfStmt+TOTAL_TOKENS][97].actionParam = 15;
	//goto
	parser->lrTable[LoopStmt+TOTAL_TOKENS][97].LRTableFuncP = LRGoto;
	parser->lrTable[LoopStmt+TOTAL_TOKENS][97].actionParam = 16;
	//shift
	parser->lrTable[23][98].LRTableFuncP = LRShift;
	parser->lrTable[23][98].actionParam = 101;
	//shift
	parser->lrTable[40][99].LRTableFuncP = LRShift;
	parser->lrTable[40][99].actionParam = 8;
	//goto
	parser->lrTable[Assi+TOTAL_TOKENS][99].LRTableFuncP = LRGoto;
	parser->lrTable[Assi+TOTAL_TOKENS][99].actionParam = 102;
	//shift
	parser->lrTable[23][100].LRTableFuncP = LRShift;
	parser->lrTable[23][100].actionParam = 103;
	//shift
	parser->lrTable[35][101].LRTableFuncP = LRShift;
	parser->lrTable[35][101].actionParam = 104;
	//reduce
	parser->lrTable[41][101].LRTableFuncP = LRReduce;
	parser->lrTable[41][101].actionParam = 51;
	//reduce
	parser->lrTable[23][101].LRTableFuncP = LRReduce;
	parser->lrTable[23][101].actionParam = 51;
	//reduce
	parser->lrTable[29][101].LRTableFuncP = LRReduce;
	parser->lrTable[29][101].actionParam = 51;
	//reduce
	parser->lrTable[30][101].LRTableFuncP = LRReduce;
	parser->lrTable[30][101].actionParam = 51;
	//reduce
	parser->lrTable[31][101].LRTableFuncP = LRReduce;
	parser->lrTable[31][101].actionParam = 51;
	//reduce
	parser->lrTable[32][101].LRTableFuncP = LRReduce;
	parser->lrTable[32][101].actionParam = 51;
	//reduce
	parser->lrTable[33][101].LRTableFuncP = LRReduce;
	parser->lrTable[33][101].actionParam = 51;
	//reduce
	parser->lrTable[38][101].LRTableFuncP = LRReduce;
	parser->lrTable[38][101].actionParam = 51;
	//reduce
	parser->lrTable[39][101].LRTableFuncP = LRReduce;
	parser->lrTable[39][101].actionParam = 51;
	//reduce
	parser->lrTable[40][101].LRTableFuncP = LRReduce;
	parser->lrTable[40][101].actionParam = 51;
	//shift
	parser->lrTable[21][102].LRTableFuncP = LRShift;
	parser->lrTable[21][102].actionParam = 105;
	//reduce
	parser->lrTable[41][103].LRTableFuncP = LRReduce;
	parser->lrTable[41][103].actionParam = 54;
	//reduce
	parser->lrTable[23][103].LRTableFuncP = LRReduce;
	parser->lrTable[23][103].actionParam = 54;
	//reduce
	parser->lrTable[29][103].LRTableFuncP = LRReduce;
	parser->lrTable[29][103].actionParam = 54;
	//reduce
	parser->lrTable[30][103].LRTableFuncP = LRReduce;
	parser->lrTable[30][103].actionParam = 54;
	//reduce
	parser->lrTable[31][103].LRTableFuncP = LRReduce;
	parser->lrTable[31][103].actionParam = 54;
	//reduce
	parser->lrTable[32][103].LRTableFuncP = LRReduce;
	parser->lrTable[32][103].actionParam = 54;
	//reduce
	parser->lrTable[33][103].LRTableFuncP = LRReduce;
	parser->lrTable[33][103].actionParam = 54;
	//reduce
	parser->lrTable[38][103].LRTableFuncP = LRReduce;
	parser->lrTable[38][103].actionParam = 54;
	//reduce
	parser->lrTable[39][103].LRTableFuncP = LRReduce;
	parser->lrTable[39][103].actionParam = 54;
	//reduce
	parser->lrTable[40][103].LRTableFuncP = LRReduce;
	parser->lrTable[40][103].actionParam = 54;
	//shift
	parser->lrTable[22][104].LRTableFuncP = LRShift;
	parser->lrTable[22][104].actionParam = 106;
	//shift
	parser->lrTable[22][105].LRTableFuncP = LRShift;
	parser->lrTable[22][105].actionParam = 107;
	//shift
	parser->lrTable[29][106].LRTableFuncP = LRShift;
	parser->lrTable[29][106].actionParam = 1;
	//shift
	parser->lrTable[30][106].LRTableFuncP = LRShift;
	parser->lrTable[30][106].actionParam = 2;
	//shift
	parser->lrTable[31][106].LRTableFuncP = LRShift;
	parser->lrTable[31][106].actionParam = 3;
	//shift
	parser->lrTable[32][106].LRTableFuncP = LRShift;
	parser->lrTable[32][106].actionParam = 4;
	//shift
	parser->lrTable[33][106].LRTableFuncP = LRShift;
	parser->lrTable[33][106].actionParam = 5;
	//shift
	parser->lrTable[38][106].LRTableFuncP = LRShift;
	parser->lrTable[38][106].actionParam = 6;
	//shift
	parser->lrTable[39][106].LRTableFuncP = LRShift;
	parser->lrTable[39][106].actionParam = 7;
	//shift
	parser->lrTable[40][106].LRTableFuncP = LRShift;
	parser->lrTable[40][106].actionParam = 8;
	//reduce
	parser->lrTable[23][106].LRTableFuncP = LRReduce;
	parser->lrTable[23][106].actionParam = 4;
	//goto
	parser->lrTable[StmtList+TOTAL_TOKENS][106].LRTableFuncP = LRGoto;
	parser->lrTable[StmtList+TOTAL_TOKENS][106].actionParam = 108;
	//goto
	parser->lrTable[Stmt+TOTAL_TOKENS][106].LRTableFuncP = LRGoto;
	parser->lrTable[Stmt+TOTAL_TOKENS][106].actionParam = 12;
	//goto
	parser->lrTable[Decl+TOTAL_TOKENS][106].LRTableFuncP = LRGoto;
	parser->lrTable[Decl+TOTAL_TOKENS][106].actionParam = 13;
	//goto
	parser->lrTable[Assi+TOTAL_TOKENS][106].LRTableFuncP = LRGoto;
	parser->lrTable[Assi+TOTAL_TOKENS][106].actionParam = 14;
	//goto
	parser->lrTable[IfStmt+TOTAL_TOKENS][106].LRTableFuncP = LRGoto;
	parser->lrTable[IfStmt+TOTAL_TOKENS][106].actionParam = 15;
	//goto
	parser->lrTable[LoopStmt+TOTAL_TOKENS][106].LRTableFuncP = LRGoto;
	parser->lrTable[LoopStmt+TOTAL_TOKENS][106].actionParam = 16;
	//shift
	parser->lrTable[29][107].LRTableFuncP = LRShift;
	parser->lrTable[29][107].actionParam = 1;
	//shift
	parser->lrTable[30][107].LRTableFuncP = LRShift;
	parser->lrTable[30][107].actionParam = 2;
	//shift
	parser->lrTable[31][107].LRTableFuncP = LRShift;
	parser->lrTable[31][107].actionParam = 3;
	//shift
	parser->lrTable[32][107].LRTableFuncP = LRShift;
	parser->lrTable[32][107].actionParam = 4;
	//shift
	parser->lrTable[33][107].LRTableFuncP = LRShift;
	parser->lrTable[33][107].actionParam = 5;
	//shift
	parser->lrTable[38][107].LRTableFuncP = LRShift;
	parser->lrTable[38][107].actionParam = 6;
	//shift
	parser->lrTable[39][107].LRTableFuncP = LRShift;
	parser->lrTable[39][107].actionParam = 7;
	//shift
	parser->lrTable[40][107].LRTableFuncP = LRShift;
	parser->lrTable[40][107].actionParam = 8;
	//reduce
	parser->lrTable[23][107].LRTableFuncP = LRReduce;
	parser->lrTable[23][107].actionParam = 4;
	//goto
	parser->lrTable[StmtList+TOTAL_TOKENS][107].LRTableFuncP = LRGoto;
	parser->lrTable[StmtList+TOTAL_TOKENS][107].actionParam = 109;
	//goto
	parser->lrTable[Stmt+TOTAL_TOKENS][107].LRTableFuncP = LRGoto;
	parser->lrTable[Stmt+TOTAL_TOKENS][107].actionParam = 12;
	//goto
	parser->lrTable[Decl+TOTAL_TOKENS][107].LRTableFuncP = LRGoto;
	parser->lrTable[Decl+TOTAL_TOKENS][107].actionParam = 13;
	//goto
	parser->lrTable[Assi+TOTAL_TOKENS][107].LRTableFuncP = LRGoto;
	parser->lrTable[Assi+TOTAL_TOKENS][107].actionParam = 14;
	//goto
	parser->lrTable[IfStmt+TOTAL_TOKENS][107].LRTableFuncP = LRGoto;
	parser->lrTable[IfStmt+TOTAL_TOKENS][107].actionParam = 15;
	//goto
	parser->lrTable[LoopStmt+TOTAL_TOKENS][107].LRTableFuncP = LRGoto;
	parser->lrTable[LoopStmt+TOTAL_TOKENS][107].actionParam = 16;
	//shift
	parser->lrTable[23][108].LRTableFuncP = LRShift;
	parser->lrTable[23][108].actionParam = 110;
	//shift
	parser->lrTable[23][109].LRTableFuncP = LRShift;
	parser->lrTable[23][109].actionParam = 111;
	//reduce
	parser->lrTable[41][110].LRTableFuncP = LRReduce;
	parser->lrTable[41][110].actionParam = 52;
	//reduce
	parser->lrTable[23][110].LRTableFuncP = LRReduce;
	parser->lrTable[23][110].actionParam = 52;
	//reduce
	parser->lrTable[29][110].LRTableFuncP = LRReduce;
	parser->lrTable[29][110].actionParam = 52;
	//reduce
	parser->lrTable[30][110].LRTableFuncP = LRReduce;
	parser->lrTable[30][110].actionParam = 52;
	//reduce
	parser->lrTable[31][110].LRTableFuncP = LRReduce;
	parser->lrTable[31][110].actionParam = 52;
	//reduce
	parser->lrTable[32][110].LRTableFuncP = LRReduce;
	parser->lrTable[32][110].actionParam = 52;
	//reduce
	parser->lrTable[33][110].LRTableFuncP = LRReduce;
	parser->lrTable[33][110].actionParam = 52;
	//reduce
	parser->lrTable[38][110].LRTableFuncP = LRReduce;
	parser->lrTable[38][110].actionParam = 52;
	//reduce
	parser->lrTable[39][110].LRTableFuncP = LRReduce;
	parser->lrTable[39][110].actionParam = 52;
	//reduce
	parser->lrTable[40][110].LRTableFuncP = LRReduce;
	parser->lrTable[40][110].actionParam = 52;
	//reduce
	parser->lrTable[41][111].LRTableFuncP = LRReduce;
	parser->lrTable[41][111].actionParam = 53;
	//reduce
	parser->lrTable[23][111].LRTableFuncP = LRReduce;
	parser->lrTable[23][111].actionParam = 53;
	//reduce
	parser->lrTable[29][111].LRTableFuncP = LRReduce;
	parser->lrTable[29][111].actionParam = 53;
	//reduce
	parser->lrTable[30][111].LRTableFuncP = LRReduce;
	parser->lrTable[30][111].actionParam = 53;
	//reduce
	parser->lrTable[31][111].LRTableFuncP = LRReduce;
	parser->lrTable[31][111].actionParam = 53;
	//reduce
	parser->lrTable[32][111].LRTableFuncP = LRReduce;
	parser->lrTable[32][111].actionParam = 53;
	//reduce
	parser->lrTable[33][111].LRTableFuncP = LRReduce;
	parser->lrTable[33][111].actionParam = 53;
	//reduce
	parser->lrTable[38][111].LRTableFuncP = LRReduce;
	parser->lrTable[38][111].actionParam = 53;
	//reduce
	parser->lrTable[39][111].LRTableFuncP = LRReduce;
	parser->lrTable[39][111].actionParam = 53;
	//reduce
	parser->lrTable[40][111].LRTableFuncP = LRReduce;
	parser->lrTable[40][111].actionParam = 53;
}