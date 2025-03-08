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
	//reduce
	parser->lrTable[41][13].LRTableFuncP = LRReduce;
	parser->lrTable[41][13].actionParam = 5;
	//reduce
	parser->lrTable[23][13].LRTableFuncP = LRReduce;
	parser->lrTable[23][13].actionParam = 5;
	//reduce
	parser->lrTable[29][13].LRTableFuncP = LRReduce;
	parser->lrTable[29][13].actionParam = 5;
	//reduce
	parser->lrTable[30][13].LRTableFuncP = LRReduce;
	parser->lrTable[30][13].actionParam = 5;
	//reduce
	parser->lrTable[31][13].LRTableFuncP = LRReduce;
	parser->lrTable[31][13].actionParam = 5;
	//reduce
	parser->lrTable[32][13].LRTableFuncP = LRReduce;
	parser->lrTable[32][13].actionParam = 5;
	//reduce
	parser->lrTable[33][13].LRTableFuncP = LRReduce;
	parser->lrTable[33][13].actionParam = 5;
	//reduce
	parser->lrTable[38][13].LRTableFuncP = LRReduce;
	parser->lrTable[38][13].actionParam = 5;
	//reduce
	parser->lrTable[39][13].LRTableFuncP = LRReduce;
	parser->lrTable[39][13].actionParam = 5;
	//reduce
	parser->lrTable[40][13].LRTableFuncP = LRReduce;
	parser->lrTable[40][13].actionParam = 5;
	//shift
	parser->lrTable[45][14].LRTableFuncP = LRShift;
	parser->lrTable[45][14].actionParam = 34;
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
	//shift
	parser->lrTable[3][17].LRTableFuncP = LRShift;
	parser->lrTable[3][17].actionParam = 35;
	//shift
	parser->lrTable[45][17].LRTableFuncP = LRShift;
	parser->lrTable[45][17].actionParam = 36;
	//shift
	parser->lrTable[3][18].LRTableFuncP = LRShift;
	parser->lrTable[3][18].actionParam = 37;
	//shift
	parser->lrTable[45][18].LRTableFuncP = LRShift;
	parser->lrTable[45][18].actionParam = 38;
	//shift
	parser->lrTable[3][19].LRTableFuncP = LRShift;
	parser->lrTable[3][19].actionParam = 39;
	//shift
	parser->lrTable[45][19].LRTableFuncP = LRShift;
	parser->lrTable[45][19].actionParam = 40;
	//shift
	parser->lrTable[3][20].LRTableFuncP = LRShift;
	parser->lrTable[3][20].actionParam = 41;
	//shift
	parser->lrTable[45][20].LRTableFuncP = LRShift;
	parser->lrTable[45][20].actionParam = 42;
	//shift
	parser->lrTable[5][21].LRTableFuncP = LRShift;
	parser->lrTable[5][21].actionParam = 43;
	//shift
	parser->lrTable[9][21].LRTableFuncP = LRShift;
	parser->lrTable[9][21].actionParam = 44;
	//shift
	parser->lrTable[11][21].LRTableFuncP = LRShift;
	parser->lrTable[11][21].actionParam = 45;
	//shift
	parser->lrTable[12][21].LRTableFuncP = LRShift;
	parser->lrTable[12][21].actionParam = 46;
	//shift
	parser->lrTable[20][21].LRTableFuncP = LRShift;
	parser->lrTable[20][21].actionParam = 47;
	//shift
	parser->lrTable[24][21].LRTableFuncP = LRShift;
	parser->lrTable[24][21].actionParam = 48;
	//shift
	parser->lrTable[25][21].LRTableFuncP = LRShift;
	parser->lrTable[25][21].actionParam = 49;
	//shift
	parser->lrTable[26][21].LRTableFuncP = LRShift;
	parser->lrTable[26][21].actionParam = 50;
	//shift
	parser->lrTable[27][21].LRTableFuncP = LRShift;
	parser->lrTable[27][21].actionParam = 51;
	//shift
	parser->lrTable[28][21].LRTableFuncP = LRShift;
	parser->lrTable[28][21].actionParam = 52;
	//shift
	parser->lrTable[40][21].LRTableFuncP = LRShift;
	parser->lrTable[40][21].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][21].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][21].actionParam = 54;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][21].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][21].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][21].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][21].actionParam = 56;
	//goto
	parser->lrTable[CondExpr+TOTAL_TOKENS][21].LRTableFuncP = LRGoto;
	parser->lrTable[CondExpr+TOTAL_TOKENS][21].actionParam = 57;
	//shift
	parser->lrTable[40][22].LRTableFuncP = LRShift;
	parser->lrTable[40][22].actionParam = 8;
	//goto
	parser->lrTable[Assi+TOTAL_TOKENS][22].LRTableFuncP = LRGoto;
	parser->lrTable[Assi+TOTAL_TOKENS][22].actionParam = 58;
	//shift
	parser->lrTable[5][23].LRTableFuncP = LRShift;
	parser->lrTable[5][23].actionParam = 43;
	//shift
	parser->lrTable[9][23].LRTableFuncP = LRShift;
	parser->lrTable[9][23].actionParam = 44;
	//shift
	parser->lrTable[11][23].LRTableFuncP = LRShift;
	parser->lrTable[11][23].actionParam = 45;
	//shift
	parser->lrTable[12][23].LRTableFuncP = LRShift;
	parser->lrTable[12][23].actionParam = 46;
	//shift
	parser->lrTable[20][23].LRTableFuncP = LRShift;
	parser->lrTable[20][23].actionParam = 47;
	//shift
	parser->lrTable[24][23].LRTableFuncP = LRShift;
	parser->lrTable[24][23].actionParam = 48;
	//shift
	parser->lrTable[25][23].LRTableFuncP = LRShift;
	parser->lrTable[25][23].actionParam = 49;
	//shift
	parser->lrTable[26][23].LRTableFuncP = LRShift;
	parser->lrTable[26][23].actionParam = 50;
	//shift
	parser->lrTable[27][23].LRTableFuncP = LRShift;
	parser->lrTable[27][23].actionParam = 51;
	//shift
	parser->lrTable[28][23].LRTableFuncP = LRShift;
	parser->lrTable[28][23].actionParam = 52;
	//shift
	parser->lrTable[40][23].LRTableFuncP = LRShift;
	parser->lrTable[40][23].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][23].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][23].actionParam = 54;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][23].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][23].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][23].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][23].actionParam = 56;
	//goto
	parser->lrTable[CondExpr+TOTAL_TOKENS][23].LRTableFuncP = LRGoto;
	parser->lrTable[CondExpr+TOTAL_TOKENS][23].actionParam = 59;
	//shift
	parser->lrTable[9][24].LRTableFuncP = LRShift;
	parser->lrTable[9][24].actionParam = 44;
	//shift
	parser->lrTable[11][24].LRTableFuncP = LRShift;
	parser->lrTable[11][24].actionParam = 45;
	//shift
	parser->lrTable[12][24].LRTableFuncP = LRShift;
	parser->lrTable[12][24].actionParam = 46;
	//shift
	parser->lrTable[20][24].LRTableFuncP = LRShift;
	parser->lrTable[20][24].actionParam = 60;
	//shift
	parser->lrTable[24][24].LRTableFuncP = LRShift;
	parser->lrTable[24][24].actionParam = 48;
	//shift
	parser->lrTable[25][24].LRTableFuncP = LRShift;
	parser->lrTable[25][24].actionParam = 49;
	//shift
	parser->lrTable[26][24].LRTableFuncP = LRShift;
	parser->lrTable[26][24].actionParam = 50;
	//shift
	parser->lrTable[27][24].LRTableFuncP = LRShift;
	parser->lrTable[27][24].actionParam = 51;
	//shift
	parser->lrTable[28][24].LRTableFuncP = LRShift;
	parser->lrTable[28][24].actionParam = 52;
	//shift
	parser->lrTable[40][24].LRTableFuncP = LRShift;
	parser->lrTable[40][24].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][24].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][24].actionParam = 61;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][24].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][24].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][24].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][24].actionParam = 56;
	//reduce
	parser->lrTable[21][25].LRTableFuncP = LRReduce;
	parser->lrTable[21][25].actionParam = 18;
	//reduce
	parser->lrTable[45][25].LRTableFuncP = LRReduce;
	parser->lrTable[45][25].actionParam = 18;
	//shift
	parser->lrTable[9][26].LRTableFuncP = LRShift;
	parser->lrTable[9][26].actionParam = 44;
	//shift
	parser->lrTable[11][26].LRTableFuncP = LRShift;
	parser->lrTable[11][26].actionParam = 45;
	//shift
	parser->lrTable[12][26].LRTableFuncP = LRShift;
	parser->lrTable[12][26].actionParam = 46;
	//shift
	parser->lrTable[20][26].LRTableFuncP = LRShift;
	parser->lrTable[20][26].actionParam = 60;
	//shift
	parser->lrTable[24][26].LRTableFuncP = LRShift;
	parser->lrTable[24][26].actionParam = 48;
	//shift
	parser->lrTable[25][26].LRTableFuncP = LRShift;
	parser->lrTable[25][26].actionParam = 49;
	//shift
	parser->lrTable[26][26].LRTableFuncP = LRShift;
	parser->lrTable[26][26].actionParam = 50;
	//shift
	parser->lrTable[27][26].LRTableFuncP = LRShift;
	parser->lrTable[27][26].actionParam = 51;
	//shift
	parser->lrTable[28][26].LRTableFuncP = LRShift;
	parser->lrTable[28][26].actionParam = 52;
	//shift
	parser->lrTable[40][26].LRTableFuncP = LRShift;
	parser->lrTable[40][26].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][26].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][26].actionParam = 62;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][26].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][26].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][26].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][26].actionParam = 56;
	//reduce
	parser->lrTable[21][27].LRTableFuncP = LRReduce;
	parser->lrTable[21][27].actionParam = 19;
	//reduce
	parser->lrTable[45][27].LRTableFuncP = LRReduce;
	parser->lrTable[45][27].actionParam = 19;
	//shift
	parser->lrTable[9][28].LRTableFuncP = LRShift;
	parser->lrTable[9][28].actionParam = 44;
	//shift
	parser->lrTable[11][28].LRTableFuncP = LRShift;
	parser->lrTable[11][28].actionParam = 45;
	//shift
	parser->lrTable[12][28].LRTableFuncP = LRShift;
	parser->lrTable[12][28].actionParam = 46;
	//shift
	parser->lrTable[20][28].LRTableFuncP = LRShift;
	parser->lrTable[20][28].actionParam = 60;
	//shift
	parser->lrTable[24][28].LRTableFuncP = LRShift;
	parser->lrTable[24][28].actionParam = 48;
	//shift
	parser->lrTable[25][28].LRTableFuncP = LRShift;
	parser->lrTable[25][28].actionParam = 49;
	//shift
	parser->lrTable[26][28].LRTableFuncP = LRShift;
	parser->lrTable[26][28].actionParam = 50;
	//shift
	parser->lrTable[27][28].LRTableFuncP = LRShift;
	parser->lrTable[27][28].actionParam = 51;
	//shift
	parser->lrTable[28][28].LRTableFuncP = LRShift;
	parser->lrTable[28][28].actionParam = 52;
	//shift
	parser->lrTable[40][28].LRTableFuncP = LRShift;
	parser->lrTable[40][28].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][28].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][28].actionParam = 63;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][28].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][28].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][28].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][28].actionParam = 56;
	//shift
	parser->lrTable[9][29].LRTableFuncP = LRShift;
	parser->lrTable[9][29].actionParam = 44;
	//shift
	parser->lrTable[11][29].LRTableFuncP = LRShift;
	parser->lrTable[11][29].actionParam = 45;
	//shift
	parser->lrTable[12][29].LRTableFuncP = LRShift;
	parser->lrTable[12][29].actionParam = 46;
	//shift
	parser->lrTable[20][29].LRTableFuncP = LRShift;
	parser->lrTable[20][29].actionParam = 60;
	//shift
	parser->lrTable[24][29].LRTableFuncP = LRShift;
	parser->lrTable[24][29].actionParam = 48;
	//shift
	parser->lrTable[25][29].LRTableFuncP = LRShift;
	parser->lrTable[25][29].actionParam = 49;
	//shift
	parser->lrTable[26][29].LRTableFuncP = LRShift;
	parser->lrTable[26][29].actionParam = 50;
	//shift
	parser->lrTable[27][29].LRTableFuncP = LRShift;
	parser->lrTable[27][29].actionParam = 51;
	//shift
	parser->lrTable[28][29].LRTableFuncP = LRShift;
	parser->lrTable[28][29].actionParam = 52;
	//shift
	parser->lrTable[40][29].LRTableFuncP = LRShift;
	parser->lrTable[40][29].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][29].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][29].actionParam = 64;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][29].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][29].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][29].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][29].actionParam = 56;
	//shift
	parser->lrTable[9][30].LRTableFuncP = LRShift;
	parser->lrTable[9][30].actionParam = 44;
	//shift
	parser->lrTable[11][30].LRTableFuncP = LRShift;
	parser->lrTable[11][30].actionParam = 45;
	//shift
	parser->lrTable[12][30].LRTableFuncP = LRShift;
	parser->lrTable[12][30].actionParam = 46;
	//shift
	parser->lrTable[20][30].LRTableFuncP = LRShift;
	parser->lrTable[20][30].actionParam = 60;
	//shift
	parser->lrTable[24][30].LRTableFuncP = LRShift;
	parser->lrTable[24][30].actionParam = 48;
	//shift
	parser->lrTable[25][30].LRTableFuncP = LRShift;
	parser->lrTable[25][30].actionParam = 49;
	//shift
	parser->lrTable[26][30].LRTableFuncP = LRShift;
	parser->lrTable[26][30].actionParam = 50;
	//shift
	parser->lrTable[27][30].LRTableFuncP = LRShift;
	parser->lrTable[27][30].actionParam = 51;
	//shift
	parser->lrTable[28][30].LRTableFuncP = LRShift;
	parser->lrTable[28][30].actionParam = 52;
	//shift
	parser->lrTable[40][30].LRTableFuncP = LRShift;
	parser->lrTable[40][30].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][30].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][30].actionParam = 65;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][30].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][30].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][30].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][30].actionParam = 56;
	//shift
	parser->lrTable[9][31].LRTableFuncP = LRShift;
	parser->lrTable[9][31].actionParam = 44;
	//shift
	parser->lrTable[11][31].LRTableFuncP = LRShift;
	parser->lrTable[11][31].actionParam = 45;
	//shift
	parser->lrTable[12][31].LRTableFuncP = LRShift;
	parser->lrTable[12][31].actionParam = 46;
	//shift
	parser->lrTable[20][31].LRTableFuncP = LRShift;
	parser->lrTable[20][31].actionParam = 60;
	//shift
	parser->lrTable[24][31].LRTableFuncP = LRShift;
	parser->lrTable[24][31].actionParam = 48;
	//shift
	parser->lrTable[25][31].LRTableFuncP = LRShift;
	parser->lrTable[25][31].actionParam = 49;
	//shift
	parser->lrTable[26][31].LRTableFuncP = LRShift;
	parser->lrTable[26][31].actionParam = 50;
	//shift
	parser->lrTable[27][31].LRTableFuncP = LRShift;
	parser->lrTable[27][31].actionParam = 51;
	//shift
	parser->lrTable[28][31].LRTableFuncP = LRShift;
	parser->lrTable[28][31].actionParam = 52;
	//shift
	parser->lrTable[40][31].LRTableFuncP = LRShift;
	parser->lrTable[40][31].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][31].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][31].actionParam = 66;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][31].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][31].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][31].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][31].actionParam = 56;
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
	parser->lrTable[41][34].actionParam = 6;
	//reduce
	parser->lrTable[23][34].LRTableFuncP = LRReduce;
	parser->lrTable[23][34].actionParam = 6;
	//reduce
	parser->lrTable[29][34].LRTableFuncP = LRReduce;
	parser->lrTable[29][34].actionParam = 6;
	//reduce
	parser->lrTable[30][34].LRTableFuncP = LRReduce;
	parser->lrTable[30][34].actionParam = 6;
	//reduce
	parser->lrTable[31][34].LRTableFuncP = LRReduce;
	parser->lrTable[31][34].actionParam = 6;
	//reduce
	parser->lrTable[32][34].LRTableFuncP = LRReduce;
	parser->lrTable[32][34].actionParam = 6;
	//reduce
	parser->lrTable[33][34].LRTableFuncP = LRReduce;
	parser->lrTable[33][34].actionParam = 6;
	//reduce
	parser->lrTable[38][34].LRTableFuncP = LRReduce;
	parser->lrTable[38][34].actionParam = 6;
	//reduce
	parser->lrTable[39][34].LRTableFuncP = LRReduce;
	parser->lrTable[39][34].actionParam = 6;
	//reduce
	parser->lrTable[40][34].LRTableFuncP = LRReduce;
	parser->lrTable[40][34].actionParam = 6;
	//shift
	parser->lrTable[9][35].LRTableFuncP = LRShift;
	parser->lrTable[9][35].actionParam = 44;
	//shift
	parser->lrTable[11][35].LRTableFuncP = LRShift;
	parser->lrTable[11][35].actionParam = 45;
	//shift
	parser->lrTable[12][35].LRTableFuncP = LRShift;
	parser->lrTable[12][35].actionParam = 46;
	//shift
	parser->lrTable[20][35].LRTableFuncP = LRShift;
	parser->lrTable[20][35].actionParam = 60;
	//shift
	parser->lrTable[24][35].LRTableFuncP = LRShift;
	parser->lrTable[24][35].actionParam = 48;
	//shift
	parser->lrTable[25][35].LRTableFuncP = LRShift;
	parser->lrTable[25][35].actionParam = 49;
	//shift
	parser->lrTable[26][35].LRTableFuncP = LRShift;
	parser->lrTable[26][35].actionParam = 50;
	//shift
	parser->lrTable[27][35].LRTableFuncP = LRShift;
	parser->lrTable[27][35].actionParam = 51;
	//shift
	parser->lrTable[28][35].LRTableFuncP = LRShift;
	parser->lrTable[28][35].actionParam = 52;
	//shift
	parser->lrTable[40][35].LRTableFuncP = LRShift;
	parser->lrTable[40][35].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][35].actionParam = 67;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][35].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][35].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][35].actionParam = 56;
	//reduce
	parser->lrTable[41][36].LRTableFuncP = LRReduce;
	parser->lrTable[41][36].actionParam = 11;
	//reduce
	parser->lrTable[23][36].LRTableFuncP = LRReduce;
	parser->lrTable[23][36].actionParam = 11;
	//reduce
	parser->lrTable[29][36].LRTableFuncP = LRReduce;
	parser->lrTable[29][36].actionParam = 11;
	//reduce
	parser->lrTable[30][36].LRTableFuncP = LRReduce;
	parser->lrTable[30][36].actionParam = 11;
	//reduce
	parser->lrTable[31][36].LRTableFuncP = LRReduce;
	parser->lrTable[31][36].actionParam = 11;
	//reduce
	parser->lrTable[32][36].LRTableFuncP = LRReduce;
	parser->lrTable[32][36].actionParam = 11;
	//reduce
	parser->lrTable[33][36].LRTableFuncP = LRReduce;
	parser->lrTable[33][36].actionParam = 11;
	//reduce
	parser->lrTable[38][36].LRTableFuncP = LRReduce;
	parser->lrTable[38][36].actionParam = 11;
	//reduce
	parser->lrTable[39][36].LRTableFuncP = LRReduce;
	parser->lrTable[39][36].actionParam = 11;
	//reduce
	parser->lrTable[40][36].LRTableFuncP = LRReduce;
	parser->lrTable[40][36].actionParam = 11;
	//shift
	parser->lrTable[9][37].LRTableFuncP = LRShift;
	parser->lrTable[9][37].actionParam = 44;
	//shift
	parser->lrTable[11][37].LRTableFuncP = LRShift;
	parser->lrTable[11][37].actionParam = 45;
	//shift
	parser->lrTable[12][37].LRTableFuncP = LRShift;
	parser->lrTable[12][37].actionParam = 46;
	//shift
	parser->lrTable[20][37].LRTableFuncP = LRShift;
	parser->lrTable[20][37].actionParam = 60;
	//shift
	parser->lrTable[24][37].LRTableFuncP = LRShift;
	parser->lrTable[24][37].actionParam = 48;
	//shift
	parser->lrTable[25][37].LRTableFuncP = LRShift;
	parser->lrTable[25][37].actionParam = 49;
	//shift
	parser->lrTable[26][37].LRTableFuncP = LRShift;
	parser->lrTable[26][37].actionParam = 50;
	//shift
	parser->lrTable[27][37].LRTableFuncP = LRShift;
	parser->lrTable[27][37].actionParam = 51;
	//shift
	parser->lrTable[28][37].LRTableFuncP = LRShift;
	parser->lrTable[28][37].actionParam = 52;
	//shift
	parser->lrTable[40][37].LRTableFuncP = LRShift;
	parser->lrTable[40][37].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][37].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][37].actionParam = 68;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][37].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][37].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][37].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][37].actionParam = 56;
	//reduce
	parser->lrTable[41][38].LRTableFuncP = LRReduce;
	parser->lrTable[41][38].actionParam = 9;
	//reduce
	parser->lrTable[23][38].LRTableFuncP = LRReduce;
	parser->lrTable[23][38].actionParam = 9;
	//reduce
	parser->lrTable[29][38].LRTableFuncP = LRReduce;
	parser->lrTable[29][38].actionParam = 9;
	//reduce
	parser->lrTable[30][38].LRTableFuncP = LRReduce;
	parser->lrTable[30][38].actionParam = 9;
	//reduce
	parser->lrTable[31][38].LRTableFuncP = LRReduce;
	parser->lrTable[31][38].actionParam = 9;
	//reduce
	parser->lrTable[32][38].LRTableFuncP = LRReduce;
	parser->lrTable[32][38].actionParam = 9;
	//reduce
	parser->lrTable[33][38].LRTableFuncP = LRReduce;
	parser->lrTable[33][38].actionParam = 9;
	//reduce
	parser->lrTable[38][38].LRTableFuncP = LRReduce;
	parser->lrTable[38][38].actionParam = 9;
	//reduce
	parser->lrTable[39][38].LRTableFuncP = LRReduce;
	parser->lrTable[39][38].actionParam = 9;
	//reduce
	parser->lrTable[40][38].LRTableFuncP = LRReduce;
	parser->lrTable[40][38].actionParam = 9;
	//shift
	parser->lrTable[9][39].LRTableFuncP = LRShift;
	parser->lrTable[9][39].actionParam = 44;
	//shift
	parser->lrTable[11][39].LRTableFuncP = LRShift;
	parser->lrTable[11][39].actionParam = 45;
	//shift
	parser->lrTable[12][39].LRTableFuncP = LRShift;
	parser->lrTable[12][39].actionParam = 46;
	//shift
	parser->lrTable[20][39].LRTableFuncP = LRShift;
	parser->lrTable[20][39].actionParam = 60;
	//shift
	parser->lrTable[24][39].LRTableFuncP = LRShift;
	parser->lrTable[24][39].actionParam = 48;
	//shift
	parser->lrTable[25][39].LRTableFuncP = LRShift;
	parser->lrTable[25][39].actionParam = 49;
	//shift
	parser->lrTable[26][39].LRTableFuncP = LRShift;
	parser->lrTable[26][39].actionParam = 50;
	//shift
	parser->lrTable[27][39].LRTableFuncP = LRShift;
	parser->lrTable[27][39].actionParam = 51;
	//shift
	parser->lrTable[28][39].LRTableFuncP = LRShift;
	parser->lrTable[28][39].actionParam = 52;
	//shift
	parser->lrTable[40][39].LRTableFuncP = LRShift;
	parser->lrTable[40][39].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][39].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][39].actionParam = 69;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][39].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][39].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][39].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][39].actionParam = 56;
	//reduce
	parser->lrTable[41][40].LRTableFuncP = LRReduce;
	parser->lrTable[41][40].actionParam = 15;
	//reduce
	parser->lrTable[23][40].LRTableFuncP = LRReduce;
	parser->lrTable[23][40].actionParam = 15;
	//reduce
	parser->lrTable[29][40].LRTableFuncP = LRReduce;
	parser->lrTable[29][40].actionParam = 15;
	//reduce
	parser->lrTable[30][40].LRTableFuncP = LRReduce;
	parser->lrTable[30][40].actionParam = 15;
	//reduce
	parser->lrTable[31][40].LRTableFuncP = LRReduce;
	parser->lrTable[31][40].actionParam = 15;
	//reduce
	parser->lrTable[32][40].LRTableFuncP = LRReduce;
	parser->lrTable[32][40].actionParam = 15;
	//reduce
	parser->lrTable[33][40].LRTableFuncP = LRReduce;
	parser->lrTable[33][40].actionParam = 15;
	//reduce
	parser->lrTable[38][40].LRTableFuncP = LRReduce;
	parser->lrTable[38][40].actionParam = 15;
	//reduce
	parser->lrTable[39][40].LRTableFuncP = LRReduce;
	parser->lrTable[39][40].actionParam = 15;
	//reduce
	parser->lrTable[40][40].LRTableFuncP = LRReduce;
	parser->lrTable[40][40].actionParam = 15;
	//shift
	parser->lrTable[9][41].LRTableFuncP = LRShift;
	parser->lrTable[9][41].actionParam = 44;
	//shift
	parser->lrTable[11][41].LRTableFuncP = LRShift;
	parser->lrTable[11][41].actionParam = 45;
	//shift
	parser->lrTable[12][41].LRTableFuncP = LRShift;
	parser->lrTable[12][41].actionParam = 46;
	//shift
	parser->lrTable[20][41].LRTableFuncP = LRShift;
	parser->lrTable[20][41].actionParam = 60;
	//shift
	parser->lrTable[24][41].LRTableFuncP = LRShift;
	parser->lrTable[24][41].actionParam = 48;
	//shift
	parser->lrTable[25][41].LRTableFuncP = LRShift;
	parser->lrTable[25][41].actionParam = 49;
	//shift
	parser->lrTable[26][41].LRTableFuncP = LRShift;
	parser->lrTable[26][41].actionParam = 50;
	//shift
	parser->lrTable[27][41].LRTableFuncP = LRShift;
	parser->lrTable[27][41].actionParam = 51;
	//shift
	parser->lrTable[28][41].LRTableFuncP = LRShift;
	parser->lrTable[28][41].actionParam = 52;
	//shift
	parser->lrTable[40][41].LRTableFuncP = LRShift;
	parser->lrTable[40][41].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][41].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][41].actionParam = 70;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][41].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][41].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][41].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][41].actionParam = 56;
	//reduce
	parser->lrTable[41][42].LRTableFuncP = LRReduce;
	parser->lrTable[41][42].actionParam = 13;
	//reduce
	parser->lrTable[23][42].LRTableFuncP = LRReduce;
	parser->lrTable[23][42].actionParam = 13;
	//reduce
	parser->lrTable[29][42].LRTableFuncP = LRReduce;
	parser->lrTable[29][42].actionParam = 13;
	//reduce
	parser->lrTable[30][42].LRTableFuncP = LRReduce;
	parser->lrTable[30][42].actionParam = 13;
	//reduce
	parser->lrTable[31][42].LRTableFuncP = LRReduce;
	parser->lrTable[31][42].actionParam = 13;
	//reduce
	parser->lrTable[32][42].LRTableFuncP = LRReduce;
	parser->lrTable[32][42].actionParam = 13;
	//reduce
	parser->lrTable[33][42].LRTableFuncP = LRReduce;
	parser->lrTable[33][42].actionParam = 13;
	//reduce
	parser->lrTable[38][42].LRTableFuncP = LRReduce;
	parser->lrTable[38][42].actionParam = 13;
	//reduce
	parser->lrTable[39][42].LRTableFuncP = LRReduce;
	parser->lrTable[39][42].actionParam = 13;
	//reduce
	parser->lrTable[40][42].LRTableFuncP = LRReduce;
	parser->lrTable[40][42].actionParam = 13;
	//shift
	parser->lrTable[9][43].LRTableFuncP = LRShift;
	parser->lrTable[9][43].actionParam = 44;
	//shift
	parser->lrTable[11][43].LRTableFuncP = LRShift;
	parser->lrTable[11][43].actionParam = 45;
	//shift
	parser->lrTable[12][43].LRTableFuncP = LRShift;
	parser->lrTable[12][43].actionParam = 46;
	//shift
	parser->lrTable[20][43].LRTableFuncP = LRShift;
	parser->lrTable[20][43].actionParam = 60;
	//shift
	parser->lrTable[24][43].LRTableFuncP = LRShift;
	parser->lrTable[24][43].actionParam = 48;
	//shift
	parser->lrTable[25][43].LRTableFuncP = LRShift;
	parser->lrTable[25][43].actionParam = 49;
	//shift
	parser->lrTable[26][43].LRTableFuncP = LRShift;
	parser->lrTable[26][43].actionParam = 50;
	//shift
	parser->lrTable[27][43].LRTableFuncP = LRShift;
	parser->lrTable[27][43].actionParam = 51;
	//shift
	parser->lrTable[28][43].LRTableFuncP = LRShift;
	parser->lrTable[28][43].actionParam = 52;
	//shift
	parser->lrTable[40][43].LRTableFuncP = LRShift;
	parser->lrTable[40][43].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][43].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][43].actionParam = 71;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][43].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][43].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][43].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][43].actionParam = 56;
	//shift
	parser->lrTable[40][44].LRTableFuncP = LRShift;
	parser->lrTable[40][44].actionParam = 72;
	//shift
	parser->lrTable[9][45].LRTableFuncP = LRShift;
	parser->lrTable[9][45].actionParam = 44;
	//shift
	parser->lrTable[11][45].LRTableFuncP = LRShift;
	parser->lrTable[11][45].actionParam = 45;
	//shift
	parser->lrTable[12][45].LRTableFuncP = LRShift;
	parser->lrTable[12][45].actionParam = 46;
	//shift
	parser->lrTable[20][45].LRTableFuncP = LRShift;
	parser->lrTable[20][45].actionParam = 60;
	//shift
	parser->lrTable[24][45].LRTableFuncP = LRShift;
	parser->lrTable[24][45].actionParam = 48;
	//shift
	parser->lrTable[25][45].LRTableFuncP = LRShift;
	parser->lrTable[25][45].actionParam = 49;
	//shift
	parser->lrTable[26][45].LRTableFuncP = LRShift;
	parser->lrTable[26][45].actionParam = 50;
	//shift
	parser->lrTable[27][45].LRTableFuncP = LRShift;
	parser->lrTable[27][45].actionParam = 51;
	//shift
	parser->lrTable[28][45].LRTableFuncP = LRShift;
	parser->lrTable[28][45].actionParam = 52;
	//shift
	parser->lrTable[40][45].LRTableFuncP = LRShift;
	parser->lrTable[40][45].actionParam = 53;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][45].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][45].actionParam = 73;
	//shift
	parser->lrTable[40][46].LRTableFuncP = LRShift;
	parser->lrTable[40][46].actionParam = 74;
	//shift
	parser->lrTable[5][47].LRTableFuncP = LRShift;
	parser->lrTable[5][47].actionParam = 43;
	//shift
	parser->lrTable[9][47].LRTableFuncP = LRShift;
	parser->lrTable[9][47].actionParam = 44;
	//shift
	parser->lrTable[11][47].LRTableFuncP = LRShift;
	parser->lrTable[11][47].actionParam = 45;
	//shift
	parser->lrTable[12][47].LRTableFuncP = LRShift;
	parser->lrTable[12][47].actionParam = 46;
	//shift
	parser->lrTable[20][47].LRTableFuncP = LRShift;
	parser->lrTable[20][47].actionParam = 47;
	//shift
	parser->lrTable[24][47].LRTableFuncP = LRShift;
	parser->lrTable[24][47].actionParam = 48;
	//shift
	parser->lrTable[25][47].LRTableFuncP = LRShift;
	parser->lrTable[25][47].actionParam = 49;
	//shift
	parser->lrTable[26][47].LRTableFuncP = LRShift;
	parser->lrTable[26][47].actionParam = 50;
	//shift
	parser->lrTable[27][47].LRTableFuncP = LRShift;
	parser->lrTable[27][47].actionParam = 51;
	//shift
	parser->lrTable[28][47].LRTableFuncP = LRShift;
	parser->lrTable[28][47].actionParam = 52;
	//shift
	parser->lrTable[40][47].LRTableFuncP = LRShift;
	parser->lrTable[40][47].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][47].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][47].actionParam = 75;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][47].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][47].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][47].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][47].actionParam = 56;
	//goto
	parser->lrTable[CondExpr+TOTAL_TOKENS][47].LRTableFuncP = LRGoto;
	parser->lrTable[CondExpr+TOTAL_TOKENS][47].actionParam = 76;
	//reduce
	parser->lrTable[0][48].LRTableFuncP = LRReduce;
	parser->lrTable[0][48].actionParam = 35;
	//reduce
	parser->lrTable[1][48].LRTableFuncP = LRReduce;
	parser->lrTable[1][48].actionParam = 35;
	//reduce
	parser->lrTable[2][48].LRTableFuncP = LRReduce;
	parser->lrTable[2][48].actionParam = 35;
	//reduce
	parser->lrTable[3][48].LRTableFuncP = LRReduce;
	parser->lrTable[3][48].actionParam = 35;
	//reduce
	parser->lrTable[4][48].LRTableFuncP = LRReduce;
	parser->lrTable[4][48].actionParam = 35;
	//reduce
	parser->lrTable[5][48].LRTableFuncP = LRReduce;
	parser->lrTable[5][48].actionParam = 35;
	//reduce
	parser->lrTable[3][48].LRTableFuncP = LRReduce;
	parser->lrTable[3][48].actionParam = 35;
	//reduce
	parser->lrTable[8][48].LRTableFuncP = LRReduce;
	parser->lrTable[8][48].actionParam = 35;
	//reduce
	parser->lrTable[11][48].LRTableFuncP = LRReduce;
	parser->lrTable[11][48].actionParam = 35;
	//reduce
	parser->lrTable[14][48].LRTableFuncP = LRReduce;
	parser->lrTable[14][48].actionParam = 35;
	//reduce
	parser->lrTable[16][48].LRTableFuncP = LRReduce;
	parser->lrTable[16][48].actionParam = 35;
	//reduce
	parser->lrTable[18][48].LRTableFuncP = LRReduce;
	parser->lrTable[18][48].actionParam = 35;
	//reduce
	parser->lrTable[21][48].LRTableFuncP = LRReduce;
	parser->lrTable[21][48].actionParam = 35;
	//reduce
	parser->lrTable[36][48].LRTableFuncP = LRReduce;
	parser->lrTable[36][48].actionParam = 35;
	//reduce
	parser->lrTable[37][48].LRTableFuncP = LRReduce;
	parser->lrTable[37][48].actionParam = 35;
	//reduce
	parser->lrTable[45][48].LRTableFuncP = LRReduce;
	parser->lrTable[45][48].actionParam = 35;
	//reduce
	parser->lrTable[0][49].LRTableFuncP = LRReduce;
	parser->lrTable[0][49].actionParam = 37;
	//reduce
	parser->lrTable[1][49].LRTableFuncP = LRReduce;
	parser->lrTable[1][49].actionParam = 37;
	//reduce
	parser->lrTable[2][49].LRTableFuncP = LRReduce;
	parser->lrTable[2][49].actionParam = 37;
	//reduce
	parser->lrTable[3][49].LRTableFuncP = LRReduce;
	parser->lrTable[3][49].actionParam = 37;
	//reduce
	parser->lrTable[4][49].LRTableFuncP = LRReduce;
	parser->lrTable[4][49].actionParam = 37;
	//reduce
	parser->lrTable[5][49].LRTableFuncP = LRReduce;
	parser->lrTable[5][49].actionParam = 37;
	//reduce
	parser->lrTable[3][49].LRTableFuncP = LRReduce;
	parser->lrTable[3][49].actionParam = 37;
	//reduce
	parser->lrTable[8][49].LRTableFuncP = LRReduce;
	parser->lrTable[8][49].actionParam = 37;
	//reduce
	parser->lrTable[11][49].LRTableFuncP = LRReduce;
	parser->lrTable[11][49].actionParam = 37;
	//reduce
	parser->lrTable[14][49].LRTableFuncP = LRReduce;
	parser->lrTable[14][49].actionParam = 37;
	//reduce
	parser->lrTable[16][49].LRTableFuncP = LRReduce;
	parser->lrTable[16][49].actionParam = 37;
	//reduce
	parser->lrTable[18][49].LRTableFuncP = LRReduce;
	parser->lrTable[18][49].actionParam = 37;
	//reduce
	parser->lrTable[21][49].LRTableFuncP = LRReduce;
	parser->lrTable[21][49].actionParam = 37;
	//reduce
	parser->lrTable[36][49].LRTableFuncP = LRReduce;
	parser->lrTable[36][49].actionParam = 37;
	//reduce
	parser->lrTable[37][49].LRTableFuncP = LRReduce;
	parser->lrTable[37][49].actionParam = 37;
	//reduce
	parser->lrTable[45][49].LRTableFuncP = LRReduce;
	parser->lrTable[45][49].actionParam = 37;
	//reduce
	parser->lrTable[0][50].LRTableFuncP = LRReduce;
	parser->lrTable[0][50].actionParam = 38;
	//reduce
	parser->lrTable[1][50].LRTableFuncP = LRReduce;
	parser->lrTable[1][50].actionParam = 38;
	//reduce
	parser->lrTable[2][50].LRTableFuncP = LRReduce;
	parser->lrTable[2][50].actionParam = 38;
	//reduce
	parser->lrTable[3][50].LRTableFuncP = LRReduce;
	parser->lrTable[3][50].actionParam = 38;
	//reduce
	parser->lrTable[4][50].LRTableFuncP = LRReduce;
	parser->lrTable[4][50].actionParam = 38;
	//reduce
	parser->lrTable[5][50].LRTableFuncP = LRReduce;
	parser->lrTable[5][50].actionParam = 38;
	//reduce
	parser->lrTable[3][50].LRTableFuncP = LRReduce;
	parser->lrTable[3][50].actionParam = 38;
	//reduce
	parser->lrTable[8][50].LRTableFuncP = LRReduce;
	parser->lrTable[8][50].actionParam = 38;
	//reduce
	parser->lrTable[11][50].LRTableFuncP = LRReduce;
	parser->lrTable[11][50].actionParam = 38;
	//reduce
	parser->lrTable[14][50].LRTableFuncP = LRReduce;
	parser->lrTable[14][50].actionParam = 38;
	//reduce
	parser->lrTable[16][50].LRTableFuncP = LRReduce;
	parser->lrTable[16][50].actionParam = 38;
	//reduce
	parser->lrTable[18][50].LRTableFuncP = LRReduce;
	parser->lrTable[18][50].actionParam = 38;
	//reduce
	parser->lrTable[21][50].LRTableFuncP = LRReduce;
	parser->lrTable[21][50].actionParam = 38;
	//reduce
	parser->lrTable[36][50].LRTableFuncP = LRReduce;
	parser->lrTable[36][50].actionParam = 38;
	//reduce
	parser->lrTable[37][50].LRTableFuncP = LRReduce;
	parser->lrTable[37][50].actionParam = 38;
	//reduce
	parser->lrTable[45][50].LRTableFuncP = LRReduce;
	parser->lrTable[45][50].actionParam = 38;
	//reduce
	parser->lrTable[0][51].LRTableFuncP = LRReduce;
	parser->lrTable[0][51].actionParam = 34;
	//reduce
	parser->lrTable[1][51].LRTableFuncP = LRReduce;
	parser->lrTable[1][51].actionParam = 34;
	//reduce
	parser->lrTable[2][51].LRTableFuncP = LRReduce;
	parser->lrTable[2][51].actionParam = 34;
	//reduce
	parser->lrTable[3][51].LRTableFuncP = LRReduce;
	parser->lrTable[3][51].actionParam = 34;
	//reduce
	parser->lrTable[4][51].LRTableFuncP = LRReduce;
	parser->lrTable[4][51].actionParam = 34;
	//reduce
	parser->lrTable[5][51].LRTableFuncP = LRReduce;
	parser->lrTable[5][51].actionParam = 34;
	//reduce
	parser->lrTable[3][51].LRTableFuncP = LRReduce;
	parser->lrTable[3][51].actionParam = 34;
	//reduce
	parser->lrTable[8][51].LRTableFuncP = LRReduce;
	parser->lrTable[8][51].actionParam = 34;
	//reduce
	parser->lrTable[11][51].LRTableFuncP = LRReduce;
	parser->lrTable[11][51].actionParam = 34;
	//reduce
	parser->lrTable[14][51].LRTableFuncP = LRReduce;
	parser->lrTable[14][51].actionParam = 34;
	//reduce
	parser->lrTable[16][51].LRTableFuncP = LRReduce;
	parser->lrTable[16][51].actionParam = 34;
	//reduce
	parser->lrTable[18][51].LRTableFuncP = LRReduce;
	parser->lrTable[18][51].actionParam = 34;
	//reduce
	parser->lrTable[21][51].LRTableFuncP = LRReduce;
	parser->lrTable[21][51].actionParam = 34;
	//reduce
	parser->lrTable[36][51].LRTableFuncP = LRReduce;
	parser->lrTable[36][51].actionParam = 34;
	//reduce
	parser->lrTable[37][51].LRTableFuncP = LRReduce;
	parser->lrTable[37][51].actionParam = 34;
	//reduce
	parser->lrTable[45][51].LRTableFuncP = LRReduce;
	parser->lrTable[45][51].actionParam = 34;
	//reduce
	parser->lrTable[0][52].LRTableFuncP = LRReduce;
	parser->lrTable[0][52].actionParam = 36;
	//reduce
	parser->lrTable[1][52].LRTableFuncP = LRReduce;
	parser->lrTable[1][52].actionParam = 36;
	//reduce
	parser->lrTable[2][52].LRTableFuncP = LRReduce;
	parser->lrTable[2][52].actionParam = 36;
	//reduce
	parser->lrTable[3][52].LRTableFuncP = LRReduce;
	parser->lrTable[3][52].actionParam = 36;
	//reduce
	parser->lrTable[4][52].LRTableFuncP = LRReduce;
	parser->lrTable[4][52].actionParam = 36;
	//reduce
	parser->lrTable[5][52].LRTableFuncP = LRReduce;
	parser->lrTable[5][52].actionParam = 36;
	//reduce
	parser->lrTable[3][52].LRTableFuncP = LRReduce;
	parser->lrTable[3][52].actionParam = 36;
	//reduce
	parser->lrTable[8][52].LRTableFuncP = LRReduce;
	parser->lrTable[8][52].actionParam = 36;
	//reduce
	parser->lrTable[11][52].LRTableFuncP = LRReduce;
	parser->lrTable[11][52].actionParam = 36;
	//reduce
	parser->lrTable[14][52].LRTableFuncP = LRReduce;
	parser->lrTable[14][52].actionParam = 36;
	//reduce
	parser->lrTable[16][52].LRTableFuncP = LRReduce;
	parser->lrTable[16][52].actionParam = 36;
	//reduce
	parser->lrTable[18][52].LRTableFuncP = LRReduce;
	parser->lrTable[18][52].actionParam = 36;
	//reduce
	parser->lrTable[21][52].LRTableFuncP = LRReduce;
	parser->lrTable[21][52].actionParam = 36;
	//reduce
	parser->lrTable[36][52].LRTableFuncP = LRReduce;
	parser->lrTable[36][52].actionParam = 36;
	//reduce
	parser->lrTable[37][52].LRTableFuncP = LRReduce;
	parser->lrTable[37][52].actionParam = 36;
	//reduce
	parser->lrTable[45][52].LRTableFuncP = LRReduce;
	parser->lrTable[45][52].actionParam = 36;
	//shift
	parser->lrTable[9][53].LRTableFuncP = LRShift;
	parser->lrTable[9][53].actionParam = 77;
	//shift
	parser->lrTable[12][53].LRTableFuncP = LRShift;
	parser->lrTable[12][53].actionParam = 78;
	//reduce
	parser->lrTable[0][53].LRTableFuncP = LRReduce;
	parser->lrTable[0][53].actionParam = 33;
	//reduce
	parser->lrTable[1][53].LRTableFuncP = LRReduce;
	parser->lrTable[1][53].actionParam = 33;
	//reduce
	parser->lrTable[2][53].LRTableFuncP = LRReduce;
	parser->lrTable[2][53].actionParam = 33;
	//reduce
	parser->lrTable[3][53].LRTableFuncP = LRReduce;
	parser->lrTable[3][53].actionParam = 33;
	//reduce
	parser->lrTable[4][53].LRTableFuncP = LRReduce;
	parser->lrTable[4][53].actionParam = 33;
	//reduce
	parser->lrTable[5][53].LRTableFuncP = LRReduce;
	parser->lrTable[5][53].actionParam = 33;
	//reduce
	parser->lrTable[3][53].LRTableFuncP = LRReduce;
	parser->lrTable[3][53].actionParam = 33;
	//reduce
	parser->lrTable[8][53].LRTableFuncP = LRReduce;
	parser->lrTable[8][53].actionParam = 33;
	//reduce
	parser->lrTable[11][53].LRTableFuncP = LRReduce;
	parser->lrTable[11][53].actionParam = 33;
	//reduce
	parser->lrTable[14][53].LRTableFuncP = LRReduce;
	parser->lrTable[14][53].actionParam = 33;
	//reduce
	parser->lrTable[16][53].LRTableFuncP = LRReduce;
	parser->lrTable[16][53].actionParam = 33;
	//reduce
	parser->lrTable[18][53].LRTableFuncP = LRReduce;
	parser->lrTable[18][53].actionParam = 33;
	//reduce
	parser->lrTable[21][53].LRTableFuncP = LRReduce;
	parser->lrTable[21][53].actionParam = 33;
	//reduce
	parser->lrTable[36][53].LRTableFuncP = LRReduce;
	parser->lrTable[36][53].actionParam = 33;
	//reduce
	parser->lrTable[37][53].LRTableFuncP = LRReduce;
	parser->lrTable[37][53].actionParam = 33;
	//reduce
	parser->lrTable[45][53].LRTableFuncP = LRReduce;
	parser->lrTable[45][53].actionParam = 33;
	//shift
	parser->lrTable[0][54].LRTableFuncP = LRShift;
	parser->lrTable[0][54].actionParam = 79;
	//shift
	parser->lrTable[1][54].LRTableFuncP = LRShift;
	parser->lrTable[1][54].actionParam = 80;
	//shift
	parser->lrTable[2][54].LRTableFuncP = LRShift;
	parser->lrTable[2][54].actionParam = 81;
	//shift
	parser->lrTable[3][54].LRTableFuncP = LRShift;
	parser->lrTable[3][54].actionParam = 82;
	//shift
	parser->lrTable[4][54].LRTableFuncP = LRShift;
	parser->lrTable[4][54].actionParam = 83;
	//shift
	parser->lrTable[5][54].LRTableFuncP = LRShift;
	parser->lrTable[5][54].actionParam = 84;
	//shift
	parser->lrTable[3][54].LRTableFuncP = LRShift;
	parser->lrTable[3][54].actionParam = 85;
	//shift
	parser->lrTable[8][54].LRTableFuncP = LRShift;
	parser->lrTable[8][54].actionParam = 86;
	//shift
	parser->lrTable[11][54].LRTableFuncP = LRShift;
	parser->lrTable[11][54].actionParam = 87;
	//shift
	parser->lrTable[36][54].LRTableFuncP = LRShift;
	parser->lrTable[36][54].actionParam = 88;
	//shift
	parser->lrTable[37][54].LRTableFuncP = LRShift;
	parser->lrTable[37][54].actionParam = 89;
	//goto
	parser->lrTable[RelOp+TOTAL_TOKENS][54].LRTableFuncP = LRGoto;
	parser->lrTable[RelOp+TOTAL_TOKENS][54].actionParam = 90;
	//shift
	parser->lrTable[14][55].LRTableFuncP = LRShift;
	parser->lrTable[14][55].actionParam = 91;
	//shift
	parser->lrTable[16][55].LRTableFuncP = LRShift;
	parser->lrTable[16][55].actionParam = 92;
	//shift
	parser->lrTable[18][55].LRTableFuncP = LRShift;
	parser->lrTable[18][55].actionParam = 93;
	//reduce
	parser->lrTable[0][55].LRTableFuncP = LRReduce;
	parser->lrTable[0][55].actionParam = 27;
	//reduce
	parser->lrTable[1][55].LRTableFuncP = LRReduce;
	parser->lrTable[1][55].actionParam = 27;
	//reduce
	parser->lrTable[2][55].LRTableFuncP = LRReduce;
	parser->lrTable[2][55].actionParam = 27;
	//reduce
	parser->lrTable[3][55].LRTableFuncP = LRReduce;
	parser->lrTable[3][55].actionParam = 27;
	//reduce
	parser->lrTable[4][55].LRTableFuncP = LRReduce;
	parser->lrTable[4][55].actionParam = 27;
	//reduce
	parser->lrTable[5][55].LRTableFuncP = LRReduce;
	parser->lrTable[5][55].actionParam = 27;
	//reduce
	parser->lrTable[3][55].LRTableFuncP = LRReduce;
	parser->lrTable[3][55].actionParam = 27;
	//reduce
	parser->lrTable[8][55].LRTableFuncP = LRReduce;
	parser->lrTable[8][55].actionParam = 27;
	//reduce
	parser->lrTable[11][55].LRTableFuncP = LRReduce;
	parser->lrTable[11][55].actionParam = 27;
	//reduce
	parser->lrTable[21][55].LRTableFuncP = LRReduce;
	parser->lrTable[21][55].actionParam = 27;
	//reduce
	parser->lrTable[36][55].LRTableFuncP = LRReduce;
	parser->lrTable[36][55].actionParam = 27;
	//reduce
	parser->lrTable[37][55].LRTableFuncP = LRReduce;
	parser->lrTable[37][55].actionParam = 27;
	//reduce
	parser->lrTable[45][55].LRTableFuncP = LRReduce;
	parser->lrTable[45][55].actionParam = 27;
	//reduce
	parser->lrTable[0][56].LRTableFuncP = LRReduce;
	parser->lrTable[0][56].actionParam = 31;
	//reduce
	parser->lrTable[1][56].LRTableFuncP = LRReduce;
	parser->lrTable[1][56].actionParam = 31;
	//reduce
	parser->lrTable[2][56].LRTableFuncP = LRReduce;
	parser->lrTable[2][56].actionParam = 31;
	//reduce
	parser->lrTable[3][56].LRTableFuncP = LRReduce;
	parser->lrTable[3][56].actionParam = 31;
	//reduce
	parser->lrTable[4][56].LRTableFuncP = LRReduce;
	parser->lrTable[4][56].actionParam = 31;
	//reduce
	parser->lrTable[5][56].LRTableFuncP = LRReduce;
	parser->lrTable[5][56].actionParam = 31;
	//reduce
	parser->lrTable[3][56].LRTableFuncP = LRReduce;
	parser->lrTable[3][56].actionParam = 31;
	//reduce
	parser->lrTable[8][56].LRTableFuncP = LRReduce;
	parser->lrTable[8][56].actionParam = 31;
	//reduce
	parser->lrTable[11][56].LRTableFuncP = LRReduce;
	parser->lrTable[11][56].actionParam = 31;
	//reduce
	parser->lrTable[14][56].LRTableFuncP = LRReduce;
	parser->lrTable[14][56].actionParam = 31;
	//reduce
	parser->lrTable[16][56].LRTableFuncP = LRReduce;
	parser->lrTable[16][56].actionParam = 31;
	//reduce
	parser->lrTable[18][56].LRTableFuncP = LRReduce;
	parser->lrTable[18][56].actionParam = 31;
	//reduce
	parser->lrTable[21][56].LRTableFuncP = LRReduce;
	parser->lrTable[21][56].actionParam = 31;
	//reduce
	parser->lrTable[36][56].LRTableFuncP = LRReduce;
	parser->lrTable[36][56].actionParam = 31;
	//reduce
	parser->lrTable[37][56].LRTableFuncP = LRReduce;
	parser->lrTable[37][56].actionParam = 31;
	//reduce
	parser->lrTable[45][56].LRTableFuncP = LRReduce;
	parser->lrTable[45][56].actionParam = 31;
	//shift
	parser->lrTable[21][57].LRTableFuncP = LRShift;
	parser->lrTable[21][57].actionParam = 94;
	//shift
	parser->lrTable[45][58].LRTableFuncP = LRShift;
	parser->lrTable[45][58].actionParam = 95;
	//shift
	parser->lrTable[21][59].LRTableFuncP = LRShift;
	parser->lrTable[21][59].actionParam = 96;
	//shift
	parser->lrTable[9][60].LRTableFuncP = LRShift;
	parser->lrTable[9][60].actionParam = 44;
	//shift
	parser->lrTable[11][60].LRTableFuncP = LRShift;
	parser->lrTable[11][60].actionParam = 45;
	//shift
	parser->lrTable[12][60].LRTableFuncP = LRShift;
	parser->lrTable[12][60].actionParam = 46;
	//shift
	parser->lrTable[20][60].LRTableFuncP = LRShift;
	parser->lrTable[20][60].actionParam = 60;
	//shift
	parser->lrTable[24][60].LRTableFuncP = LRShift;
	parser->lrTable[24][60].actionParam = 48;
	//shift
	parser->lrTable[25][60].LRTableFuncP = LRShift;
	parser->lrTable[25][60].actionParam = 49;
	//shift
	parser->lrTable[26][60].LRTableFuncP = LRShift;
	parser->lrTable[26][60].actionParam = 50;
	//shift
	parser->lrTable[27][60].LRTableFuncP = LRShift;
	parser->lrTable[27][60].actionParam = 51;
	//shift
	parser->lrTable[28][60].LRTableFuncP = LRShift;
	parser->lrTable[28][60].actionParam = 52;
	//shift
	parser->lrTable[40][60].LRTableFuncP = LRShift;
	parser->lrTable[40][60].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][60].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][60].actionParam = 97;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][60].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][60].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][60].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][60].actionParam = 56;
	//shift
	parser->lrTable[8][61].LRTableFuncP = LRShift;
	parser->lrTable[8][61].actionParam = 86;
	//shift
	parser->lrTable[11][61].LRTableFuncP = LRShift;
	parser->lrTable[11][61].actionParam = 87;
	//reduce
	parser->lrTable[21][61].LRTableFuncP = LRReduce;
	parser->lrTable[21][61].actionParam = 17;
	//reduce
	parser->lrTable[45][61].LRTableFuncP = LRReduce;
	parser->lrTable[45][61].actionParam = 17;
	//shift
	parser->lrTable[8][62].LRTableFuncP = LRShift;
	parser->lrTable[8][62].actionParam = 86;
	//shift
	parser->lrTable[11][62].LRTableFuncP = LRShift;
	parser->lrTable[11][62].actionParam = 87;
	//reduce
	parser->lrTable[21][62].LRTableFuncP = LRReduce;
	parser->lrTable[21][62].actionParam = 20;
	//reduce
	parser->lrTable[45][62].LRTableFuncP = LRReduce;
	parser->lrTable[45][62].actionParam = 20;
	//shift
	parser->lrTable[8][63].LRTableFuncP = LRShift;
	parser->lrTable[8][63].actionParam = 86;
	//shift
	parser->lrTable[11][63].LRTableFuncP = LRShift;
	parser->lrTable[11][63].actionParam = 87;
	//reduce
	parser->lrTable[21][63].LRTableFuncP = LRReduce;
	parser->lrTable[21][63].actionParam = 21;
	//reduce
	parser->lrTable[45][63].LRTableFuncP = LRReduce;
	parser->lrTable[45][63].actionParam = 21;
	//shift
	parser->lrTable[8][64].LRTableFuncP = LRShift;
	parser->lrTable[8][64].actionParam = 86;
	//shift
	parser->lrTable[11][64].LRTableFuncP = LRShift;
	parser->lrTable[11][64].actionParam = 87;
	//reduce
	parser->lrTable[21][64].LRTableFuncP = LRReduce;
	parser->lrTable[21][64].actionParam = 23;
	//reduce
	parser->lrTable[45][64].LRTableFuncP = LRReduce;
	parser->lrTable[45][64].actionParam = 23;
	//shift
	parser->lrTable[8][65].LRTableFuncP = LRShift;
	parser->lrTable[8][65].actionParam = 86;
	//shift
	parser->lrTable[11][65].LRTableFuncP = LRShift;
	parser->lrTable[11][65].actionParam = 87;
	//reduce
	parser->lrTable[21][65].LRTableFuncP = LRReduce;
	parser->lrTable[21][65].actionParam = 22;
	//reduce
	parser->lrTable[45][65].LRTableFuncP = LRReduce;
	parser->lrTable[45][65].actionParam = 22;
	//shift
	parser->lrTable[8][66].LRTableFuncP = LRShift;
	parser->lrTable[8][66].actionParam = 86;
	//shift
	parser->lrTable[11][66].LRTableFuncP = LRShift;
	parser->lrTable[11][66].actionParam = 87;
	//reduce
	parser->lrTable[21][66].LRTableFuncP = LRReduce;
	parser->lrTable[21][66].actionParam = 24;
	//reduce
	parser->lrTable[45][66].LRTableFuncP = LRReduce;
	parser->lrTable[45][66].actionParam = 24;
	//shift
	parser->lrTable[8][67].LRTableFuncP = LRShift;
	parser->lrTable[8][67].actionParam = 86;
	//shift
	parser->lrTable[11][67].LRTableFuncP = LRShift;
	parser->lrTable[11][67].actionParam = 87;
	//shift
	parser->lrTable[45][67].LRTableFuncP = LRShift;
	parser->lrTable[45][67].actionParam = 98;
	//shift
	parser->lrTable[8][68].LRTableFuncP = LRShift;
	parser->lrTable[8][68].actionParam = 86;
	//shift
	parser->lrTable[11][68].LRTableFuncP = LRShift;
	parser->lrTable[11][68].actionParam = 87;
	//shift
	parser->lrTable[45][68].LRTableFuncP = LRShift;
	parser->lrTable[45][68].actionParam = 99;
	//shift
	parser->lrTable[8][69].LRTableFuncP = LRShift;
	parser->lrTable[8][69].actionParam = 86;
	//shift
	parser->lrTable[11][69].LRTableFuncP = LRShift;
	parser->lrTable[11][69].actionParam = 87;
	//shift
	parser->lrTable[45][69].LRTableFuncP = LRShift;
	parser->lrTable[45][69].actionParam = 100;
	//shift
	parser->lrTable[8][70].LRTableFuncP = LRShift;
	parser->lrTable[8][70].actionParam = 86;
	//shift
	parser->lrTable[11][70].LRTableFuncP = LRShift;
	parser->lrTable[11][70].actionParam = 87;
	//shift
	parser->lrTable[45][70].LRTableFuncP = LRShift;
	parser->lrTable[45][70].actionParam = 101;
	//shift
	parser->lrTable[8][71].LRTableFuncP = LRShift;
	parser->lrTable[8][71].actionParam = 86;
	//shift
	parser->lrTable[11][71].LRTableFuncP = LRShift;
	parser->lrTable[11][71].actionParam = 87;
	//reduce
	parser->lrTable[21][71].LRTableFuncP = LRReduce;
	parser->lrTable[21][71].actionParam = 45;
	//reduce
	parser->lrTable[45][71].LRTableFuncP = LRReduce;
	parser->lrTable[45][71].actionParam = 45;
	//reduce
	parser->lrTable[0][72].LRTableFuncP = LRReduce;
	parser->lrTable[0][72].actionParam = 41;
	//reduce
	parser->lrTable[1][72].LRTableFuncP = LRReduce;
	parser->lrTable[1][72].actionParam = 41;
	//reduce
	parser->lrTable[2][72].LRTableFuncP = LRReduce;
	parser->lrTable[2][72].actionParam = 41;
	//reduce
	parser->lrTable[3][72].LRTableFuncP = LRReduce;
	parser->lrTable[3][72].actionParam = 41;
	//reduce
	parser->lrTable[4][72].LRTableFuncP = LRReduce;
	parser->lrTable[4][72].actionParam = 41;
	//reduce
	parser->lrTable[5][72].LRTableFuncP = LRReduce;
	parser->lrTable[5][72].actionParam = 41;
	//reduce
	parser->lrTable[3][72].LRTableFuncP = LRReduce;
	parser->lrTable[3][72].actionParam = 41;
	//reduce
	parser->lrTable[8][72].LRTableFuncP = LRReduce;
	parser->lrTable[8][72].actionParam = 41;
	//reduce
	parser->lrTable[11][72].LRTableFuncP = LRReduce;
	parser->lrTable[11][72].actionParam = 41;
	//reduce
	parser->lrTable[14][72].LRTableFuncP = LRReduce;
	parser->lrTable[14][72].actionParam = 41;
	//reduce
	parser->lrTable[16][72].LRTableFuncP = LRReduce;
	parser->lrTable[16][72].actionParam = 41;
	//reduce
	parser->lrTable[18][72].LRTableFuncP = LRReduce;
	parser->lrTable[18][72].actionParam = 41;
	//reduce
	parser->lrTable[21][72].LRTableFuncP = LRReduce;
	parser->lrTable[21][72].actionParam = 41;
	//reduce
	parser->lrTable[36][72].LRTableFuncP = LRReduce;
	parser->lrTable[36][72].actionParam = 41;
	//reduce
	parser->lrTable[37][72].LRTableFuncP = LRReduce;
	parser->lrTable[37][72].actionParam = 41;
	//reduce
	parser->lrTable[45][72].LRTableFuncP = LRReduce;
	parser->lrTable[45][72].actionParam = 41;
	//reduce
	parser->lrTable[0][73].LRTableFuncP = LRReduce;
	parser->lrTable[0][73].actionParam = 43;
	//reduce
	parser->lrTable[1][73].LRTableFuncP = LRReduce;
	parser->lrTable[1][73].actionParam = 43;
	//reduce
	parser->lrTable[2][73].LRTableFuncP = LRReduce;
	parser->lrTable[2][73].actionParam = 43;
	//reduce
	parser->lrTable[3][73].LRTableFuncP = LRReduce;
	parser->lrTable[3][73].actionParam = 43;
	//reduce
	parser->lrTable[4][73].LRTableFuncP = LRReduce;
	parser->lrTable[4][73].actionParam = 43;
	//reduce
	parser->lrTable[5][73].LRTableFuncP = LRReduce;
	parser->lrTable[5][73].actionParam = 43;
	//reduce
	parser->lrTable[3][73].LRTableFuncP = LRReduce;
	parser->lrTable[3][73].actionParam = 43;
	//reduce
	parser->lrTable[8][73].LRTableFuncP = LRReduce;
	parser->lrTable[8][73].actionParam = 43;
	//reduce
	parser->lrTable[11][73].LRTableFuncP = LRReduce;
	parser->lrTable[11][73].actionParam = 43;
	//reduce
	parser->lrTable[14][73].LRTableFuncP = LRReduce;
	parser->lrTable[14][73].actionParam = 43;
	//reduce
	parser->lrTable[16][73].LRTableFuncP = LRReduce;
	parser->lrTable[16][73].actionParam = 43;
	//reduce
	parser->lrTable[18][73].LRTableFuncP = LRReduce;
	parser->lrTable[18][73].actionParam = 43;
	//reduce
	parser->lrTable[21][73].LRTableFuncP = LRReduce;
	parser->lrTable[21][73].actionParam = 43;
	//reduce
	parser->lrTable[36][73].LRTableFuncP = LRReduce;
	parser->lrTable[36][73].actionParam = 43;
	//reduce
	parser->lrTable[37][73].LRTableFuncP = LRReduce;
	parser->lrTable[37][73].actionParam = 43;
	//reduce
	parser->lrTable[45][73].LRTableFuncP = LRReduce;
	parser->lrTable[45][73].actionParam = 43;
	//reduce
	parser->lrTable[0][74].LRTableFuncP = LRReduce;
	parser->lrTable[0][74].actionParam = 42;
	//reduce
	parser->lrTable[1][74].LRTableFuncP = LRReduce;
	parser->lrTable[1][74].actionParam = 42;
	//reduce
	parser->lrTable[2][74].LRTableFuncP = LRReduce;
	parser->lrTable[2][74].actionParam = 42;
	//reduce
	parser->lrTable[3][74].LRTableFuncP = LRReduce;
	parser->lrTable[3][74].actionParam = 42;
	//reduce
	parser->lrTable[4][74].LRTableFuncP = LRReduce;
	parser->lrTable[4][74].actionParam = 42;
	//reduce
	parser->lrTable[5][74].LRTableFuncP = LRReduce;
	parser->lrTable[5][74].actionParam = 42;
	//reduce
	parser->lrTable[3][74].LRTableFuncP = LRReduce;
	parser->lrTable[3][74].actionParam = 42;
	//reduce
	parser->lrTable[8][74].LRTableFuncP = LRReduce;
	parser->lrTable[8][74].actionParam = 42;
	//reduce
	parser->lrTable[11][74].LRTableFuncP = LRReduce;
	parser->lrTable[11][74].actionParam = 42;
	//reduce
	parser->lrTable[14][74].LRTableFuncP = LRReduce;
	parser->lrTable[14][74].actionParam = 42;
	//reduce
	parser->lrTable[16][74].LRTableFuncP = LRReduce;
	parser->lrTable[16][74].actionParam = 42;
	//reduce
	parser->lrTable[18][74].LRTableFuncP = LRReduce;
	parser->lrTable[18][74].actionParam = 42;
	//reduce
	parser->lrTable[21][74].LRTableFuncP = LRReduce;
	parser->lrTable[21][74].actionParam = 42;
	//reduce
	parser->lrTable[36][74].LRTableFuncP = LRReduce;
	parser->lrTable[36][74].actionParam = 42;
	//reduce
	parser->lrTable[37][74].LRTableFuncP = LRReduce;
	parser->lrTable[37][74].actionParam = 42;
	//reduce
	parser->lrTable[45][74].LRTableFuncP = LRReduce;
	parser->lrTable[45][74].actionParam = 42;
	//shift
	parser->lrTable[0][75].LRTableFuncP = LRShift;
	parser->lrTable[0][75].actionParam = 79;
	//shift
	parser->lrTable[1][75].LRTableFuncP = LRShift;
	parser->lrTable[1][75].actionParam = 80;
	//shift
	parser->lrTable[2][75].LRTableFuncP = LRShift;
	parser->lrTable[2][75].actionParam = 81;
	//shift
	parser->lrTable[3][75].LRTableFuncP = LRShift;
	parser->lrTable[3][75].actionParam = 82;
	//shift
	parser->lrTable[4][75].LRTableFuncP = LRShift;
	parser->lrTable[4][75].actionParam = 83;
	//shift
	parser->lrTable[5][75].LRTableFuncP = LRShift;
	parser->lrTable[5][75].actionParam = 84;
	//shift
	parser->lrTable[3][75].LRTableFuncP = LRShift;
	parser->lrTable[3][75].actionParam = 85;
	//shift
	parser->lrTable[8][75].LRTableFuncP = LRShift;
	parser->lrTable[8][75].actionParam = 86;
	//shift
	parser->lrTable[11][75].LRTableFuncP = LRShift;
	parser->lrTable[11][75].actionParam = 87;
	//shift
	parser->lrTable[21][75].LRTableFuncP = LRShift;
	parser->lrTable[21][75].actionParam = 102;
	//shift
	parser->lrTable[36][75].LRTableFuncP = LRShift;
	parser->lrTable[36][75].actionParam = 88;
	//shift
	parser->lrTable[37][75].LRTableFuncP = LRShift;
	parser->lrTable[37][75].actionParam = 89;
	//goto
	parser->lrTable[RelOp+TOTAL_TOKENS][75].LRTableFuncP = LRGoto;
	parser->lrTable[RelOp+TOTAL_TOKENS][75].actionParam = 90;
	//shift
	parser->lrTable[21][76].LRTableFuncP = LRShift;
	parser->lrTable[21][76].actionParam = 103;
	//reduce
	parser->lrTable[0][77].LRTableFuncP = LRReduce;
	parser->lrTable[0][77].actionParam = 39;
	//reduce
	parser->lrTable[1][77].LRTableFuncP = LRReduce;
	parser->lrTable[1][77].actionParam = 39;
	//reduce
	parser->lrTable[2][77].LRTableFuncP = LRReduce;
	parser->lrTable[2][77].actionParam = 39;
	//reduce
	parser->lrTable[3][77].LRTableFuncP = LRReduce;
	parser->lrTable[3][77].actionParam = 39;
	//reduce
	parser->lrTable[4][77].LRTableFuncP = LRReduce;
	parser->lrTable[4][77].actionParam = 39;
	//reduce
	parser->lrTable[5][77].LRTableFuncP = LRReduce;
	parser->lrTable[5][77].actionParam = 39;
	//reduce
	parser->lrTable[3][77].LRTableFuncP = LRReduce;
	parser->lrTable[3][77].actionParam = 39;
	//reduce
	parser->lrTable[8][77].LRTableFuncP = LRReduce;
	parser->lrTable[8][77].actionParam = 39;
	//reduce
	parser->lrTable[11][77].LRTableFuncP = LRReduce;
	parser->lrTable[11][77].actionParam = 39;
	//reduce
	parser->lrTable[14][77].LRTableFuncP = LRReduce;
	parser->lrTable[14][77].actionParam = 39;
	//reduce
	parser->lrTable[16][77].LRTableFuncP = LRReduce;
	parser->lrTable[16][77].actionParam = 39;
	//reduce
	parser->lrTable[18][77].LRTableFuncP = LRReduce;
	parser->lrTable[18][77].actionParam = 39;
	//reduce
	parser->lrTable[21][77].LRTableFuncP = LRReduce;
	parser->lrTable[21][77].actionParam = 39;
	//reduce
	parser->lrTable[36][77].LRTableFuncP = LRReduce;
	parser->lrTable[36][77].actionParam = 39;
	//reduce
	parser->lrTable[37][77].LRTableFuncP = LRReduce;
	parser->lrTable[37][77].actionParam = 39;
	//reduce
	parser->lrTable[45][77].LRTableFuncP = LRReduce;
	parser->lrTable[45][77].actionParam = 39;
	//reduce
	parser->lrTable[0][78].LRTableFuncP = LRReduce;
	parser->lrTable[0][78].actionParam = 40;
	//reduce
	parser->lrTable[1][78].LRTableFuncP = LRReduce;
	parser->lrTable[1][78].actionParam = 40;
	//reduce
	parser->lrTable[2][78].LRTableFuncP = LRReduce;
	parser->lrTable[2][78].actionParam = 40;
	//reduce
	parser->lrTable[3][78].LRTableFuncP = LRReduce;
	parser->lrTable[3][78].actionParam = 40;
	//reduce
	parser->lrTable[4][78].LRTableFuncP = LRReduce;
	parser->lrTable[4][78].actionParam = 40;
	//reduce
	parser->lrTable[5][78].LRTableFuncP = LRReduce;
	parser->lrTable[5][78].actionParam = 40;
	//reduce
	parser->lrTable[3][78].LRTableFuncP = LRReduce;
	parser->lrTable[3][78].actionParam = 40;
	//reduce
	parser->lrTable[8][78].LRTableFuncP = LRReduce;
	parser->lrTable[8][78].actionParam = 40;
	//reduce
	parser->lrTable[11][78].LRTableFuncP = LRReduce;
	parser->lrTable[11][78].actionParam = 40;
	//reduce
	parser->lrTable[14][78].LRTableFuncP = LRReduce;
	parser->lrTable[14][78].actionParam = 40;
	//reduce
	parser->lrTable[16][78].LRTableFuncP = LRReduce;
	parser->lrTable[16][78].actionParam = 40;
	//reduce
	parser->lrTable[18][78].LRTableFuncP = LRReduce;
	parser->lrTable[18][78].actionParam = 40;
	//reduce
	parser->lrTable[21][78].LRTableFuncP = LRReduce;
	parser->lrTable[21][78].actionParam = 40;
	//reduce
	parser->lrTable[36][78].LRTableFuncP = LRReduce;
	parser->lrTable[36][78].actionParam = 40;
	//reduce
	parser->lrTable[37][78].LRTableFuncP = LRReduce;
	parser->lrTable[37][78].actionParam = 40;
	//reduce
	parser->lrTable[45][78].LRTableFuncP = LRReduce;
	parser->lrTable[45][78].actionParam = 40;
	//reduce
	parser->lrTable[9][79].LRTableFuncP = LRReduce;
	parser->lrTable[9][79].actionParam = 55;
	//reduce
	parser->lrTable[11][79].LRTableFuncP = LRReduce;
	parser->lrTable[11][79].actionParam = 55;
	//reduce
	parser->lrTable[12][79].LRTableFuncP = LRReduce;
	parser->lrTable[12][79].actionParam = 55;
	//reduce
	parser->lrTable[20][79].LRTableFuncP = LRReduce;
	parser->lrTable[20][79].actionParam = 55;
	//reduce
	parser->lrTable[24][79].LRTableFuncP = LRReduce;
	parser->lrTable[24][79].actionParam = 55;
	//reduce
	parser->lrTable[25][79].LRTableFuncP = LRReduce;
	parser->lrTable[25][79].actionParam = 55;
	//reduce
	parser->lrTable[26][79].LRTableFuncP = LRReduce;
	parser->lrTable[26][79].actionParam = 55;
	//reduce
	parser->lrTable[27][79].LRTableFuncP = LRReduce;
	parser->lrTable[27][79].actionParam = 55;
	//reduce
	parser->lrTable[28][79].LRTableFuncP = LRReduce;
	parser->lrTable[28][79].actionParam = 55;
	//reduce
	parser->lrTable[40][79].LRTableFuncP = LRReduce;
	parser->lrTable[40][79].actionParam = 55;
	//reduce
	parser->lrTable[9][80].LRTableFuncP = LRReduce;
	parser->lrTable[9][80].actionParam = 52;
	//reduce
	parser->lrTable[11][80].LRTableFuncP = LRReduce;
	parser->lrTable[11][80].actionParam = 52;
	//reduce
	parser->lrTable[12][80].LRTableFuncP = LRReduce;
	parser->lrTable[12][80].actionParam = 52;
	//reduce
	parser->lrTable[20][80].LRTableFuncP = LRReduce;
	parser->lrTable[20][80].actionParam = 52;
	//reduce
	parser->lrTable[24][80].LRTableFuncP = LRReduce;
	parser->lrTable[24][80].actionParam = 52;
	//reduce
	parser->lrTable[25][80].LRTableFuncP = LRReduce;
	parser->lrTable[25][80].actionParam = 52;
	//reduce
	parser->lrTable[26][80].LRTableFuncP = LRReduce;
	parser->lrTable[26][80].actionParam = 52;
	//reduce
	parser->lrTable[27][80].LRTableFuncP = LRReduce;
	parser->lrTable[27][80].actionParam = 52;
	//reduce
	parser->lrTable[28][80].LRTableFuncP = LRReduce;
	parser->lrTable[28][80].actionParam = 52;
	//reduce
	parser->lrTable[40][80].LRTableFuncP = LRReduce;
	parser->lrTable[40][80].actionParam = 52;
	//reduce
	parser->lrTable[9][81].LRTableFuncP = LRReduce;
	parser->lrTable[9][81].actionParam = 53;
	//reduce
	parser->lrTable[11][81].LRTableFuncP = LRReduce;
	parser->lrTable[11][81].actionParam = 53;
	//reduce
	parser->lrTable[12][81].LRTableFuncP = LRReduce;
	parser->lrTable[12][81].actionParam = 53;
	//reduce
	parser->lrTable[20][81].LRTableFuncP = LRReduce;
	parser->lrTable[20][81].actionParam = 53;
	//reduce
	parser->lrTable[24][81].LRTableFuncP = LRReduce;
	parser->lrTable[24][81].actionParam = 53;
	//reduce
	parser->lrTable[25][81].LRTableFuncP = LRReduce;
	parser->lrTable[25][81].actionParam = 53;
	//reduce
	parser->lrTable[26][81].LRTableFuncP = LRReduce;
	parser->lrTable[26][81].actionParam = 53;
	//reduce
	parser->lrTable[27][81].LRTableFuncP = LRReduce;
	parser->lrTable[27][81].actionParam = 53;
	//reduce
	parser->lrTable[28][81].LRTableFuncP = LRReduce;
	parser->lrTable[28][81].actionParam = 53;
	//reduce
	parser->lrTable[40][81].LRTableFuncP = LRReduce;
	parser->lrTable[40][81].actionParam = 53;
	//reduce
	parser->lrTable[9][82].LRTableFuncP = LRReduce;
	parser->lrTable[9][82].actionParam = 49;
	//reduce
	parser->lrTable[11][82].LRTableFuncP = LRReduce;
	parser->lrTable[11][82].actionParam = 49;
	//reduce
	parser->lrTable[12][82].LRTableFuncP = LRReduce;
	parser->lrTable[12][82].actionParam = 49;
	//reduce
	parser->lrTable[20][82].LRTableFuncP = LRReduce;
	parser->lrTable[20][82].actionParam = 49;
	//reduce
	parser->lrTable[24][82].LRTableFuncP = LRReduce;
	parser->lrTable[24][82].actionParam = 49;
	//reduce
	parser->lrTable[25][82].LRTableFuncP = LRReduce;
	parser->lrTable[25][82].actionParam = 49;
	//reduce
	parser->lrTable[26][82].LRTableFuncP = LRReduce;
	parser->lrTable[26][82].actionParam = 49;
	//reduce
	parser->lrTable[27][82].LRTableFuncP = LRReduce;
	parser->lrTable[27][82].actionParam = 49;
	//reduce
	parser->lrTable[28][82].LRTableFuncP = LRReduce;
	parser->lrTable[28][82].actionParam = 49;
	//reduce
	parser->lrTable[40][82].LRTableFuncP = LRReduce;
	parser->lrTable[40][82].actionParam = 49;
	//reduce
	parser->lrTable[9][83].LRTableFuncP = LRReduce;
	parser->lrTable[9][83].actionParam = 50;
	//reduce
	parser->lrTable[11][83].LRTableFuncP = LRReduce;
	parser->lrTable[11][83].actionParam = 50;
	//reduce
	parser->lrTable[12][83].LRTableFuncP = LRReduce;
	parser->lrTable[12][83].actionParam = 50;
	//reduce
	parser->lrTable[20][83].LRTableFuncP = LRReduce;
	parser->lrTable[20][83].actionParam = 50;
	//reduce
	parser->lrTable[24][83].LRTableFuncP = LRReduce;
	parser->lrTable[24][83].actionParam = 50;
	//reduce
	parser->lrTable[25][83].LRTableFuncP = LRReduce;
	parser->lrTable[25][83].actionParam = 50;
	//reduce
	parser->lrTable[26][83].LRTableFuncP = LRReduce;
	parser->lrTable[26][83].actionParam = 50;
	//reduce
	parser->lrTable[27][83].LRTableFuncP = LRReduce;
	parser->lrTable[27][83].actionParam = 50;
	//reduce
	parser->lrTable[28][83].LRTableFuncP = LRReduce;
	parser->lrTable[28][83].actionParam = 50;
	//reduce
	parser->lrTable[40][83].LRTableFuncP = LRReduce;
	parser->lrTable[40][83].actionParam = 50;
	//reduce
	parser->lrTable[9][84].LRTableFuncP = LRReduce;
	parser->lrTable[9][84].actionParam = 51;
	//reduce
	parser->lrTable[11][84].LRTableFuncP = LRReduce;
	parser->lrTable[11][84].actionParam = 51;
	//reduce
	parser->lrTable[12][84].LRTableFuncP = LRReduce;
	parser->lrTable[12][84].actionParam = 51;
	//reduce
	parser->lrTable[20][84].LRTableFuncP = LRReduce;
	parser->lrTable[20][84].actionParam = 51;
	//reduce
	parser->lrTable[24][84].LRTableFuncP = LRReduce;
	parser->lrTable[24][84].actionParam = 51;
	//reduce
	parser->lrTable[25][84].LRTableFuncP = LRReduce;
	parser->lrTable[25][84].actionParam = 51;
	//reduce
	parser->lrTable[26][84].LRTableFuncP = LRReduce;
	parser->lrTable[26][84].actionParam = 51;
	//reduce
	parser->lrTable[27][84].LRTableFuncP = LRReduce;
	parser->lrTable[27][84].actionParam = 51;
	//reduce
	parser->lrTable[28][84].LRTableFuncP = LRReduce;
	parser->lrTable[28][84].actionParam = 51;
	//reduce
	parser->lrTable[40][84].LRTableFuncP = LRReduce;
	parser->lrTable[40][84].actionParam = 51;
	//reduce
	parser->lrTable[9][85].LRTableFuncP = LRReduce;
	parser->lrTable[9][85].actionParam = 54;
	//reduce
	parser->lrTable[11][85].LRTableFuncP = LRReduce;
	parser->lrTable[11][85].actionParam = 54;
	//reduce
	parser->lrTable[12][85].LRTableFuncP = LRReduce;
	parser->lrTable[12][85].actionParam = 54;
	//reduce
	parser->lrTable[20][85].LRTableFuncP = LRReduce;
	parser->lrTable[20][85].actionParam = 54;
	//reduce
	parser->lrTable[24][85].LRTableFuncP = LRReduce;
	parser->lrTable[24][85].actionParam = 54;
	//reduce
	parser->lrTable[25][85].LRTableFuncP = LRReduce;
	parser->lrTable[25][85].actionParam = 54;
	//reduce
	parser->lrTable[26][85].LRTableFuncP = LRReduce;
	parser->lrTable[26][85].actionParam = 54;
	//reduce
	parser->lrTable[27][85].LRTableFuncP = LRReduce;
	parser->lrTable[27][85].actionParam = 54;
	//reduce
	parser->lrTable[28][85].LRTableFuncP = LRReduce;
	parser->lrTable[28][85].actionParam = 54;
	//reduce
	parser->lrTable[40][85].LRTableFuncP = LRReduce;
	parser->lrTable[40][85].actionParam = 54;
	//shift
	parser->lrTable[9][86].LRTableFuncP = LRShift;
	parser->lrTable[9][86].actionParam = 44;
	//shift
	parser->lrTable[11][86].LRTableFuncP = LRShift;
	parser->lrTable[11][86].actionParam = 45;
	//shift
	parser->lrTable[12][86].LRTableFuncP = LRShift;
	parser->lrTable[12][86].actionParam = 46;
	//shift
	parser->lrTable[20][86].LRTableFuncP = LRShift;
	parser->lrTable[20][86].actionParam = 60;
	//shift
	parser->lrTable[24][86].LRTableFuncP = LRShift;
	parser->lrTable[24][86].actionParam = 48;
	//shift
	parser->lrTable[25][86].LRTableFuncP = LRShift;
	parser->lrTable[25][86].actionParam = 49;
	//shift
	parser->lrTable[26][86].LRTableFuncP = LRShift;
	parser->lrTable[26][86].actionParam = 50;
	//shift
	parser->lrTable[27][86].LRTableFuncP = LRShift;
	parser->lrTable[27][86].actionParam = 51;
	//shift
	parser->lrTable[28][86].LRTableFuncP = LRShift;
	parser->lrTable[28][86].actionParam = 52;
	//shift
	parser->lrTable[40][86].LRTableFuncP = LRShift;
	parser->lrTable[40][86].actionParam = 53;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][86].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][86].actionParam = 104;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][86].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][86].actionParam = 56;
	//shift
	parser->lrTable[9][87].LRTableFuncP = LRShift;
	parser->lrTable[9][87].actionParam = 44;
	//shift
	parser->lrTable[11][87].LRTableFuncP = LRShift;
	parser->lrTable[11][87].actionParam = 45;
	//shift
	parser->lrTable[12][87].LRTableFuncP = LRShift;
	parser->lrTable[12][87].actionParam = 46;
	//shift
	parser->lrTable[20][87].LRTableFuncP = LRShift;
	parser->lrTable[20][87].actionParam = 60;
	//shift
	parser->lrTable[24][87].LRTableFuncP = LRShift;
	parser->lrTable[24][87].actionParam = 48;
	//shift
	parser->lrTable[25][87].LRTableFuncP = LRShift;
	parser->lrTable[25][87].actionParam = 49;
	//shift
	parser->lrTable[26][87].LRTableFuncP = LRShift;
	parser->lrTable[26][87].actionParam = 50;
	//shift
	parser->lrTable[27][87].LRTableFuncP = LRShift;
	parser->lrTable[27][87].actionParam = 51;
	//shift
	parser->lrTable[28][87].LRTableFuncP = LRShift;
	parser->lrTable[28][87].actionParam = 52;
	//shift
	parser->lrTable[40][87].LRTableFuncP = LRShift;
	parser->lrTable[40][87].actionParam = 53;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][87].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][87].actionParam = 105;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][87].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][87].actionParam = 56;
	//shift
	parser->lrTable[9][88].LRTableFuncP = LRShift;
	parser->lrTable[9][88].actionParam = 44;
	//shift
	parser->lrTable[11][88].LRTableFuncP = LRShift;
	parser->lrTable[11][88].actionParam = 45;
	//shift
	parser->lrTable[12][88].LRTableFuncP = LRShift;
	parser->lrTable[12][88].actionParam = 46;
	//shift
	parser->lrTable[20][88].LRTableFuncP = LRShift;
	parser->lrTable[20][88].actionParam = 60;
	//shift
	parser->lrTable[24][88].LRTableFuncP = LRShift;
	parser->lrTable[24][88].actionParam = 48;
	//shift
	parser->lrTable[25][88].LRTableFuncP = LRShift;
	parser->lrTable[25][88].actionParam = 49;
	//shift
	parser->lrTable[26][88].LRTableFuncP = LRShift;
	parser->lrTable[26][88].actionParam = 50;
	//shift
	parser->lrTable[27][88].LRTableFuncP = LRShift;
	parser->lrTable[27][88].actionParam = 51;
	//shift
	parser->lrTable[28][88].LRTableFuncP = LRShift;
	parser->lrTable[28][88].actionParam = 52;
	//shift
	parser->lrTable[40][88].LRTableFuncP = LRShift;
	parser->lrTable[40][88].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][88].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][88].actionParam = 106;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][88].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][88].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][88].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][88].actionParam = 56;
	//shift
	parser->lrTable[9][89].LRTableFuncP = LRShift;
	parser->lrTable[9][89].actionParam = 44;
	//shift
	parser->lrTable[11][89].LRTableFuncP = LRShift;
	parser->lrTable[11][89].actionParam = 45;
	//shift
	parser->lrTable[12][89].LRTableFuncP = LRShift;
	parser->lrTable[12][89].actionParam = 46;
	//shift
	parser->lrTable[20][89].LRTableFuncP = LRShift;
	parser->lrTable[20][89].actionParam = 60;
	//shift
	parser->lrTable[24][89].LRTableFuncP = LRShift;
	parser->lrTable[24][89].actionParam = 48;
	//shift
	parser->lrTable[25][89].LRTableFuncP = LRShift;
	parser->lrTable[25][89].actionParam = 49;
	//shift
	parser->lrTable[26][89].LRTableFuncP = LRShift;
	parser->lrTable[26][89].actionParam = 50;
	//shift
	parser->lrTable[27][89].LRTableFuncP = LRShift;
	parser->lrTable[27][89].actionParam = 51;
	//shift
	parser->lrTable[28][89].LRTableFuncP = LRShift;
	parser->lrTable[28][89].actionParam = 52;
	//shift
	parser->lrTable[40][89].LRTableFuncP = LRShift;
	parser->lrTable[40][89].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][89].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][89].actionParam = 107;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][89].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][89].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][89].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][89].actionParam = 56;
	//shift
	parser->lrTable[9][90].LRTableFuncP = LRShift;
	parser->lrTable[9][90].actionParam = 44;
	//shift
	parser->lrTable[11][90].LRTableFuncP = LRShift;
	parser->lrTable[11][90].actionParam = 45;
	//shift
	parser->lrTable[12][90].LRTableFuncP = LRShift;
	parser->lrTable[12][90].actionParam = 46;
	//shift
	parser->lrTable[20][90].LRTableFuncP = LRShift;
	parser->lrTable[20][90].actionParam = 60;
	//shift
	parser->lrTable[24][90].LRTableFuncP = LRShift;
	parser->lrTable[24][90].actionParam = 48;
	//shift
	parser->lrTable[25][90].LRTableFuncP = LRShift;
	parser->lrTable[25][90].actionParam = 49;
	//shift
	parser->lrTable[26][90].LRTableFuncP = LRShift;
	parser->lrTable[26][90].actionParam = 50;
	//shift
	parser->lrTable[27][90].LRTableFuncP = LRShift;
	parser->lrTable[27][90].actionParam = 51;
	//shift
	parser->lrTable[28][90].LRTableFuncP = LRShift;
	parser->lrTable[28][90].actionParam = 52;
	//shift
	parser->lrTable[40][90].LRTableFuncP = LRShift;
	parser->lrTable[40][90].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][90].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][90].actionParam = 108;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][90].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][90].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][90].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][90].actionParam = 56;
	//shift
	parser->lrTable[9][91].LRTableFuncP = LRShift;
	parser->lrTable[9][91].actionParam = 44;
	//shift
	parser->lrTable[11][91].LRTableFuncP = LRShift;
	parser->lrTable[11][91].actionParam = 45;
	//shift
	parser->lrTable[12][91].LRTableFuncP = LRShift;
	parser->lrTable[12][91].actionParam = 46;
	//shift
	parser->lrTable[20][91].LRTableFuncP = LRShift;
	parser->lrTable[20][91].actionParam = 60;
	//shift
	parser->lrTable[24][91].LRTableFuncP = LRShift;
	parser->lrTable[24][91].actionParam = 48;
	//shift
	parser->lrTable[25][91].LRTableFuncP = LRShift;
	parser->lrTable[25][91].actionParam = 49;
	//shift
	parser->lrTable[26][91].LRTableFuncP = LRShift;
	parser->lrTable[26][91].actionParam = 50;
	//shift
	parser->lrTable[27][91].LRTableFuncP = LRShift;
	parser->lrTable[27][91].actionParam = 51;
	//shift
	parser->lrTable[28][91].LRTableFuncP = LRShift;
	parser->lrTable[28][91].actionParam = 52;
	//shift
	parser->lrTable[40][91].LRTableFuncP = LRShift;
	parser->lrTable[40][91].actionParam = 53;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][91].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][91].actionParam = 109;
	//shift
	parser->lrTable[9][92].LRTableFuncP = LRShift;
	parser->lrTable[9][92].actionParam = 44;
	//shift
	parser->lrTable[11][92].LRTableFuncP = LRShift;
	parser->lrTable[11][92].actionParam = 45;
	//shift
	parser->lrTable[12][92].LRTableFuncP = LRShift;
	parser->lrTable[12][92].actionParam = 46;
	//shift
	parser->lrTable[20][92].LRTableFuncP = LRShift;
	parser->lrTable[20][92].actionParam = 60;
	//shift
	parser->lrTable[24][92].LRTableFuncP = LRShift;
	parser->lrTable[24][92].actionParam = 48;
	//shift
	parser->lrTable[25][92].LRTableFuncP = LRShift;
	parser->lrTable[25][92].actionParam = 49;
	//shift
	parser->lrTable[26][92].LRTableFuncP = LRShift;
	parser->lrTable[26][92].actionParam = 50;
	//shift
	parser->lrTable[27][92].LRTableFuncP = LRShift;
	parser->lrTable[27][92].actionParam = 51;
	//shift
	parser->lrTable[28][92].LRTableFuncP = LRShift;
	parser->lrTable[28][92].actionParam = 52;
	//shift
	parser->lrTable[40][92].LRTableFuncP = LRShift;
	parser->lrTable[40][92].actionParam = 53;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][92].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][92].actionParam = 110;
	//shift
	parser->lrTable[9][93].LRTableFuncP = LRShift;
	parser->lrTable[9][93].actionParam = 44;
	//shift
	parser->lrTable[11][93].LRTableFuncP = LRShift;
	parser->lrTable[11][93].actionParam = 45;
	//shift
	parser->lrTable[12][93].LRTableFuncP = LRShift;
	parser->lrTable[12][93].actionParam = 46;
	//shift
	parser->lrTable[20][93].LRTableFuncP = LRShift;
	parser->lrTable[20][93].actionParam = 60;
	//shift
	parser->lrTable[24][93].LRTableFuncP = LRShift;
	parser->lrTable[24][93].actionParam = 48;
	//shift
	parser->lrTable[25][93].LRTableFuncP = LRShift;
	parser->lrTable[25][93].actionParam = 49;
	//shift
	parser->lrTable[26][93].LRTableFuncP = LRShift;
	parser->lrTable[26][93].actionParam = 50;
	//shift
	parser->lrTable[27][93].LRTableFuncP = LRShift;
	parser->lrTable[27][93].actionParam = 51;
	//shift
	parser->lrTable[28][93].LRTableFuncP = LRShift;
	parser->lrTable[28][93].actionParam = 52;
	//shift
	parser->lrTable[40][93].LRTableFuncP = LRShift;
	parser->lrTable[40][93].actionParam = 53;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][93].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][93].actionParam = 111;
	//shift
	parser->lrTable[22][94].LRTableFuncP = LRShift;
	parser->lrTable[22][94].actionParam = 112;
	//shift
	parser->lrTable[5][95].LRTableFuncP = LRShift;
	parser->lrTable[5][95].actionParam = 43;
	//shift
	parser->lrTable[9][95].LRTableFuncP = LRShift;
	parser->lrTable[9][95].actionParam = 44;
	//shift
	parser->lrTable[11][95].LRTableFuncP = LRShift;
	parser->lrTable[11][95].actionParam = 45;
	//shift
	parser->lrTable[12][95].LRTableFuncP = LRShift;
	parser->lrTable[12][95].actionParam = 46;
	//shift
	parser->lrTable[20][95].LRTableFuncP = LRShift;
	parser->lrTable[20][95].actionParam = 47;
	//shift
	parser->lrTable[24][95].LRTableFuncP = LRShift;
	parser->lrTable[24][95].actionParam = 48;
	//shift
	parser->lrTable[25][95].LRTableFuncP = LRShift;
	parser->lrTable[25][95].actionParam = 49;
	//shift
	parser->lrTable[26][95].LRTableFuncP = LRShift;
	parser->lrTable[26][95].actionParam = 50;
	//shift
	parser->lrTable[27][95].LRTableFuncP = LRShift;
	parser->lrTable[27][95].actionParam = 51;
	//shift
	parser->lrTable[28][95].LRTableFuncP = LRShift;
	parser->lrTable[28][95].actionParam = 52;
	//shift
	parser->lrTable[40][95].LRTableFuncP = LRShift;
	parser->lrTable[40][95].actionParam = 53;
	//goto
	parser->lrTable[Expr+TOTAL_TOKENS][95].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_TOKENS][95].actionParam = 54;
	//goto
	parser->lrTable[Term+TOTAL_TOKENS][95].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_TOKENS][95].actionParam = 55;
	//goto
	parser->lrTable[Factor+TOTAL_TOKENS][95].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_TOKENS][95].actionParam = 56;
	//goto
	parser->lrTable[CondExpr+TOTAL_TOKENS][95].LRTableFuncP = LRGoto;
	parser->lrTable[CondExpr+TOTAL_TOKENS][95].actionParam = 113;
	//shift
	parser->lrTable[22][96].LRTableFuncP = LRShift;
	parser->lrTable[22][96].actionParam = 114;
	//shift
	parser->lrTable[8][97].LRTableFuncP = LRShift;
	parser->lrTable[8][97].actionParam = 86;
	//shift
	parser->lrTable[11][97].LRTableFuncP = LRShift;
	parser->lrTable[11][97].actionParam = 87;
	//shift
	parser->lrTable[21][97].LRTableFuncP = LRShift;
	parser->lrTable[21][97].actionParam = 102;
	//reduce
	parser->lrTable[41][98].LRTableFuncP = LRReduce;
	parser->lrTable[41][98].actionParam = 12;
	//reduce
	parser->lrTable[23][98].LRTableFuncP = LRReduce;
	parser->lrTable[23][98].actionParam = 12;
	//reduce
	parser->lrTable[29][98].LRTableFuncP = LRReduce;
	parser->lrTable[29][98].actionParam = 12;
	//reduce
	parser->lrTable[30][98].LRTableFuncP = LRReduce;
	parser->lrTable[30][98].actionParam = 12;
	//reduce
	parser->lrTable[31][98].LRTableFuncP = LRReduce;
	parser->lrTable[31][98].actionParam = 12;
	//reduce
	parser->lrTable[32][98].LRTableFuncP = LRReduce;
	parser->lrTable[32][98].actionParam = 12;
	//reduce
	parser->lrTable[33][98].LRTableFuncP = LRReduce;
	parser->lrTable[33][98].actionParam = 12;
	//reduce
	parser->lrTable[38][98].LRTableFuncP = LRReduce;
	parser->lrTable[38][98].actionParam = 12;
	//reduce
	parser->lrTable[39][98].LRTableFuncP = LRReduce;
	parser->lrTable[39][98].actionParam = 12;
	//reduce
	parser->lrTable[40][98].LRTableFuncP = LRReduce;
	parser->lrTable[40][98].actionParam = 12;
	//reduce
	parser->lrTable[41][99].LRTableFuncP = LRReduce;
	parser->lrTable[41][99].actionParam = 10;
	//reduce
	parser->lrTable[23][99].LRTableFuncP = LRReduce;
	parser->lrTable[23][99].actionParam = 10;
	//reduce
	parser->lrTable[29][99].LRTableFuncP = LRReduce;
	parser->lrTable[29][99].actionParam = 10;
	//reduce
	parser->lrTable[30][99].LRTableFuncP = LRReduce;
	parser->lrTable[30][99].actionParam = 10;
	//reduce
	parser->lrTable[31][99].LRTableFuncP = LRReduce;
	parser->lrTable[31][99].actionParam = 10;
	//reduce
	parser->lrTable[32][99].LRTableFuncP = LRReduce;
	parser->lrTable[32][99].actionParam = 10;
	//reduce
	parser->lrTable[33][99].LRTableFuncP = LRReduce;
	parser->lrTable[33][99].actionParam = 10;
	//reduce
	parser->lrTable[38][99].LRTableFuncP = LRReduce;
	parser->lrTable[38][99].actionParam = 10;
	//reduce
	parser->lrTable[39][99].LRTableFuncP = LRReduce;
	parser->lrTable[39][99].actionParam = 10;
	//reduce
	parser->lrTable[40][99].LRTableFuncP = LRReduce;
	parser->lrTable[40][99].actionParam = 10;
	//reduce
	parser->lrTable[41][100].LRTableFuncP = LRReduce;
	parser->lrTable[41][100].actionParam = 16;
	//reduce
	parser->lrTable[23][100].LRTableFuncP = LRReduce;
	parser->lrTable[23][100].actionParam = 16;
	//reduce
	parser->lrTable[29][100].LRTableFuncP = LRReduce;
	parser->lrTable[29][100].actionParam = 16;
	//reduce
	parser->lrTable[30][100].LRTableFuncP = LRReduce;
	parser->lrTable[30][100].actionParam = 16;
	//reduce
	parser->lrTable[31][100].LRTableFuncP = LRReduce;
	parser->lrTable[31][100].actionParam = 16;
	//reduce
	parser->lrTable[32][100].LRTableFuncP = LRReduce;
	parser->lrTable[32][100].actionParam = 16;
	//reduce
	parser->lrTable[33][100].LRTableFuncP = LRReduce;
	parser->lrTable[33][100].actionParam = 16;
	//reduce
	parser->lrTable[38][100].LRTableFuncP = LRReduce;
	parser->lrTable[38][100].actionParam = 16;
	//reduce
	parser->lrTable[39][100].LRTableFuncP = LRReduce;
	parser->lrTable[39][100].actionParam = 16;
	//reduce
	parser->lrTable[40][100].LRTableFuncP = LRReduce;
	parser->lrTable[40][100].actionParam = 16;
	//reduce
	parser->lrTable[41][101].LRTableFuncP = LRReduce;
	parser->lrTable[41][101].actionParam = 14;
	//reduce
	parser->lrTable[23][101].LRTableFuncP = LRReduce;
	parser->lrTable[23][101].actionParam = 14;
	//reduce
	parser->lrTable[29][101].LRTableFuncP = LRReduce;
	parser->lrTable[29][101].actionParam = 14;
	//reduce
	parser->lrTable[30][101].LRTableFuncP = LRReduce;
	parser->lrTable[30][101].actionParam = 14;
	//reduce
	parser->lrTable[31][101].LRTableFuncP = LRReduce;
	parser->lrTable[31][101].actionParam = 14;
	//reduce
	parser->lrTable[32][101].LRTableFuncP = LRReduce;
	parser->lrTable[32][101].actionParam = 14;
	//reduce
	parser->lrTable[33][101].LRTableFuncP = LRReduce;
	parser->lrTable[33][101].actionParam = 14;
	//reduce
	parser->lrTable[38][101].LRTableFuncP = LRReduce;
	parser->lrTable[38][101].actionParam = 14;
	//reduce
	parser->lrTable[39][101].LRTableFuncP = LRReduce;
	parser->lrTable[39][101].actionParam = 14;
	//reduce
	parser->lrTable[40][101].LRTableFuncP = LRReduce;
	parser->lrTable[40][101].actionParam = 14;
	//reduce
	parser->lrTable[0][102].LRTableFuncP = LRReduce;
	parser->lrTable[0][102].actionParam = 32;
	//reduce
	parser->lrTable[1][102].LRTableFuncP = LRReduce;
	parser->lrTable[1][102].actionParam = 32;
	//reduce
	parser->lrTable[2][102].LRTableFuncP = LRReduce;
	parser->lrTable[2][102].actionParam = 32;
	//reduce
	parser->lrTable[3][102].LRTableFuncP = LRReduce;
	parser->lrTable[3][102].actionParam = 32;
	//reduce
	parser->lrTable[4][102].LRTableFuncP = LRReduce;
	parser->lrTable[4][102].actionParam = 32;
	//reduce
	parser->lrTable[5][102].LRTableFuncP = LRReduce;
	parser->lrTable[5][102].actionParam = 32;
	//reduce
	parser->lrTable[3][102].LRTableFuncP = LRReduce;
	parser->lrTable[3][102].actionParam = 32;
	//reduce
	parser->lrTable[8][102].LRTableFuncP = LRReduce;
	parser->lrTable[8][102].actionParam = 32;
	//reduce
	parser->lrTable[11][102].LRTableFuncP = LRReduce;
	parser->lrTable[11][102].actionParam = 32;
	//reduce
	parser->lrTable[14][102].LRTableFuncP = LRReduce;
	parser->lrTable[14][102].actionParam = 32;
	//reduce
	parser->lrTable[16][102].LRTableFuncP = LRReduce;
	parser->lrTable[16][102].actionParam = 32;
	//reduce
	parser->lrTable[18][102].LRTableFuncP = LRReduce;
	parser->lrTable[18][102].actionParam = 32;
	//reduce
	parser->lrTable[21][102].LRTableFuncP = LRReduce;
	parser->lrTable[21][102].actionParam = 32;
	//reduce
	parser->lrTable[36][102].LRTableFuncP = LRReduce;
	parser->lrTable[36][102].actionParam = 32;
	//reduce
	parser->lrTable[37][102].LRTableFuncP = LRReduce;
	parser->lrTable[37][102].actionParam = 32;
	//reduce
	parser->lrTable[45][102].LRTableFuncP = LRReduce;
	parser->lrTable[45][102].actionParam = 32;
	//reduce
	parser->lrTable[21][103].LRTableFuncP = LRReduce;
	parser->lrTable[21][103].actionParam = 48;
	//reduce
	parser->lrTable[45][103].LRTableFuncP = LRReduce;
	parser->lrTable[45][103].actionParam = 48;
	//shift
	parser->lrTable[14][104].LRTableFuncP = LRShift;
	parser->lrTable[14][104].actionParam = 91;
	//shift
	parser->lrTable[16][104].LRTableFuncP = LRShift;
	parser->lrTable[16][104].actionParam = 92;
	//shift
	parser->lrTable[18][104].LRTableFuncP = LRShift;
	parser->lrTable[18][104].actionParam = 93;
	//reduce
	parser->lrTable[0][104].LRTableFuncP = LRReduce;
	parser->lrTable[0][104].actionParam = 25;
	//reduce
	parser->lrTable[1][104].LRTableFuncP = LRReduce;
	parser->lrTable[1][104].actionParam = 25;
	//reduce
	parser->lrTable[2][104].LRTableFuncP = LRReduce;
	parser->lrTable[2][104].actionParam = 25;
	//reduce
	parser->lrTable[3][104].LRTableFuncP = LRReduce;
	parser->lrTable[3][104].actionParam = 25;
	//reduce
	parser->lrTable[4][104].LRTableFuncP = LRReduce;
	parser->lrTable[4][104].actionParam = 25;
	//reduce
	parser->lrTable[5][104].LRTableFuncP = LRReduce;
	parser->lrTable[5][104].actionParam = 25;
	//reduce
	parser->lrTable[3][104].LRTableFuncP = LRReduce;
	parser->lrTable[3][104].actionParam = 25;
	//reduce
	parser->lrTable[8][104].LRTableFuncP = LRReduce;
	parser->lrTable[8][104].actionParam = 25;
	//reduce
	parser->lrTable[11][104].LRTableFuncP = LRReduce;
	parser->lrTable[11][104].actionParam = 25;
	//reduce
	parser->lrTable[21][104].LRTableFuncP = LRReduce;
	parser->lrTable[21][104].actionParam = 25;
	//reduce
	parser->lrTable[36][104].LRTableFuncP = LRReduce;
	parser->lrTable[36][104].actionParam = 25;
	//reduce
	parser->lrTable[37][104].LRTableFuncP = LRReduce;
	parser->lrTable[37][104].actionParam = 25;
	//reduce
	parser->lrTable[45][104].LRTableFuncP = LRReduce;
	parser->lrTable[45][104].actionParam = 25;
	//shift
	parser->lrTable[14][105].LRTableFuncP = LRShift;
	parser->lrTable[14][105].actionParam = 91;
	//shift
	parser->lrTable[16][105].LRTableFuncP = LRShift;
	parser->lrTable[16][105].actionParam = 92;
	//shift
	parser->lrTable[18][105].LRTableFuncP = LRShift;
	parser->lrTable[18][105].actionParam = 93;
	//reduce
	parser->lrTable[0][105].LRTableFuncP = LRReduce;
	parser->lrTable[0][105].actionParam = 26;
	//reduce
	parser->lrTable[1][105].LRTableFuncP = LRReduce;
	parser->lrTable[1][105].actionParam = 26;
	//reduce
	parser->lrTable[2][105].LRTableFuncP = LRReduce;
	parser->lrTable[2][105].actionParam = 26;
	//reduce
	parser->lrTable[3][105].LRTableFuncP = LRReduce;
	parser->lrTable[3][105].actionParam = 26;
	//reduce
	parser->lrTable[4][105].LRTableFuncP = LRReduce;
	parser->lrTable[4][105].actionParam = 26;
	//reduce
	parser->lrTable[5][105].LRTableFuncP = LRReduce;
	parser->lrTable[5][105].actionParam = 26;
	//reduce
	parser->lrTable[3][105].LRTableFuncP = LRReduce;
	parser->lrTable[3][105].actionParam = 26;
	//reduce
	parser->lrTable[8][105].LRTableFuncP = LRReduce;
	parser->lrTable[8][105].actionParam = 26;
	//reduce
	parser->lrTable[11][105].LRTableFuncP = LRReduce;
	parser->lrTable[11][105].actionParam = 26;
	//reduce
	parser->lrTable[21][105].LRTableFuncP = LRReduce;
	parser->lrTable[21][105].actionParam = 26;
	//reduce
	parser->lrTable[36][105].LRTableFuncP = LRReduce;
	parser->lrTable[36][105].actionParam = 26;
	//reduce
	parser->lrTable[37][105].LRTableFuncP = LRReduce;
	parser->lrTable[37][105].actionParam = 26;
	//reduce
	parser->lrTable[45][105].LRTableFuncP = LRReduce;
	parser->lrTable[45][105].actionParam = 26;
	//shift
	parser->lrTable[8][106].LRTableFuncP = LRShift;
	parser->lrTable[8][106].actionParam = 86;
	//shift
	parser->lrTable[11][106].LRTableFuncP = LRShift;
	parser->lrTable[11][106].actionParam = 87;
	//reduce
	parser->lrTable[21][106].LRTableFuncP = LRReduce;
	parser->lrTable[21][106].actionParam = 46;
	//reduce
	parser->lrTable[45][106].LRTableFuncP = LRReduce;
	parser->lrTable[45][106].actionParam = 46;
	//shift
	parser->lrTable[8][107].LRTableFuncP = LRShift;
	parser->lrTable[8][107].actionParam = 86;
	//shift
	parser->lrTable[11][107].LRTableFuncP = LRShift;
	parser->lrTable[11][107].actionParam = 87;
	//reduce
	parser->lrTable[21][107].LRTableFuncP = LRReduce;
	parser->lrTable[21][107].actionParam = 47;
	//reduce
	parser->lrTable[45][107].LRTableFuncP = LRReduce;
	parser->lrTable[45][107].actionParam = 47;
	//shift
	parser->lrTable[8][108].LRTableFuncP = LRShift;
	parser->lrTable[8][108].actionParam = 86;
	//shift
	parser->lrTable[11][108].LRTableFuncP = LRShift;
	parser->lrTable[11][108].actionParam = 87;
	//reduce
	parser->lrTable[21][108].LRTableFuncP = LRReduce;
	parser->lrTable[21][108].actionParam = 44;
	//reduce
	parser->lrTable[45][108].LRTableFuncP = LRReduce;
	parser->lrTable[45][108].actionParam = 44;
	//reduce
	parser->lrTable[0][109].LRTableFuncP = LRReduce;
	parser->lrTable[0][109].actionParam = 29;
	//reduce
	parser->lrTable[1][109].LRTableFuncP = LRReduce;
	parser->lrTable[1][109].actionParam = 29;
	//reduce
	parser->lrTable[2][109].LRTableFuncP = LRReduce;
	parser->lrTable[2][109].actionParam = 29;
	//reduce
	parser->lrTable[3][109].LRTableFuncP = LRReduce;
	parser->lrTable[3][109].actionParam = 29;
	//reduce
	parser->lrTable[4][109].LRTableFuncP = LRReduce;
	parser->lrTable[4][109].actionParam = 29;
	//reduce
	parser->lrTable[5][109].LRTableFuncP = LRReduce;
	parser->lrTable[5][109].actionParam = 29;
	//reduce
	parser->lrTable[3][109].LRTableFuncP = LRReduce;
	parser->lrTable[3][109].actionParam = 29;
	//reduce
	parser->lrTable[8][109].LRTableFuncP = LRReduce;
	parser->lrTable[8][109].actionParam = 29;
	//reduce
	parser->lrTable[11][109].LRTableFuncP = LRReduce;
	parser->lrTable[11][109].actionParam = 29;
	//reduce
	parser->lrTable[14][109].LRTableFuncP = LRReduce;
	parser->lrTable[14][109].actionParam = 29;
	//reduce
	parser->lrTable[16][109].LRTableFuncP = LRReduce;
	parser->lrTable[16][109].actionParam = 29;
	//reduce
	parser->lrTable[18][109].LRTableFuncP = LRReduce;
	parser->lrTable[18][109].actionParam = 29;
	//reduce
	parser->lrTable[21][109].LRTableFuncP = LRReduce;
	parser->lrTable[21][109].actionParam = 29;
	//reduce
	parser->lrTable[36][109].LRTableFuncP = LRReduce;
	parser->lrTable[36][109].actionParam = 29;
	//reduce
	parser->lrTable[37][109].LRTableFuncP = LRReduce;
	parser->lrTable[37][109].actionParam = 29;
	//reduce
	parser->lrTable[45][109].LRTableFuncP = LRReduce;
	parser->lrTable[45][109].actionParam = 29;
	//reduce
	parser->lrTable[0][110].LRTableFuncP = LRReduce;
	parser->lrTable[0][110].actionParam = 28;
	//reduce
	parser->lrTable[1][110].LRTableFuncP = LRReduce;
	parser->lrTable[1][110].actionParam = 28;
	//reduce
	parser->lrTable[2][110].LRTableFuncP = LRReduce;
	parser->lrTable[2][110].actionParam = 28;
	//reduce
	parser->lrTable[3][110].LRTableFuncP = LRReduce;
	parser->lrTable[3][110].actionParam = 28;
	//reduce
	parser->lrTable[4][110].LRTableFuncP = LRReduce;
	parser->lrTable[4][110].actionParam = 28;
	//reduce
	parser->lrTable[5][110].LRTableFuncP = LRReduce;
	parser->lrTable[5][110].actionParam = 28;
	//reduce
	parser->lrTable[3][110].LRTableFuncP = LRReduce;
	parser->lrTable[3][110].actionParam = 28;
	//reduce
	parser->lrTable[8][110].LRTableFuncP = LRReduce;
	parser->lrTable[8][110].actionParam = 28;
	//reduce
	parser->lrTable[11][110].LRTableFuncP = LRReduce;
	parser->lrTable[11][110].actionParam = 28;
	//reduce
	parser->lrTable[14][110].LRTableFuncP = LRReduce;
	parser->lrTable[14][110].actionParam = 28;
	//reduce
	parser->lrTable[16][110].LRTableFuncP = LRReduce;
	parser->lrTable[16][110].actionParam = 28;
	//reduce
	parser->lrTable[18][110].LRTableFuncP = LRReduce;
	parser->lrTable[18][110].actionParam = 28;
	//reduce
	parser->lrTable[21][110].LRTableFuncP = LRReduce;
	parser->lrTable[21][110].actionParam = 28;
	//reduce
	parser->lrTable[36][110].LRTableFuncP = LRReduce;
	parser->lrTable[36][110].actionParam = 28;
	//reduce
	parser->lrTable[37][110].LRTableFuncP = LRReduce;
	parser->lrTable[37][110].actionParam = 28;
	//reduce
	parser->lrTable[45][110].LRTableFuncP = LRReduce;
	parser->lrTable[45][110].actionParam = 28;
	//reduce
	parser->lrTable[0][111].LRTableFuncP = LRReduce;
	parser->lrTable[0][111].actionParam = 30;
	//reduce
	parser->lrTable[1][111].LRTableFuncP = LRReduce;
	parser->lrTable[1][111].actionParam = 30;
	//reduce
	parser->lrTable[2][111].LRTableFuncP = LRReduce;
	parser->lrTable[2][111].actionParam = 30;
	//reduce
	parser->lrTable[3][111].LRTableFuncP = LRReduce;
	parser->lrTable[3][111].actionParam = 30;
	//reduce
	parser->lrTable[4][111].LRTableFuncP = LRReduce;
	parser->lrTable[4][111].actionParam = 30;
	//reduce
	parser->lrTable[5][111].LRTableFuncP = LRReduce;
	parser->lrTable[5][111].actionParam = 30;
	//reduce
	parser->lrTable[3][111].LRTableFuncP = LRReduce;
	parser->lrTable[3][111].actionParam = 30;
	//reduce
	parser->lrTable[8][111].LRTableFuncP = LRReduce;
	parser->lrTable[8][111].actionParam = 30;
	//reduce
	parser->lrTable[11][111].LRTableFuncP = LRReduce;
	parser->lrTable[11][111].actionParam = 30;
	//reduce
	parser->lrTable[14][111].LRTableFuncP = LRReduce;
	parser->lrTable[14][111].actionParam = 30;
	//reduce
	parser->lrTable[16][111].LRTableFuncP = LRReduce;
	parser->lrTable[16][111].actionParam = 30;
	//reduce
	parser->lrTable[18][111].LRTableFuncP = LRReduce;
	parser->lrTable[18][111].actionParam = 30;
	//reduce
	parser->lrTable[21][111].LRTableFuncP = LRReduce;
	parser->lrTable[21][111].actionParam = 30;
	//reduce
	parser->lrTable[36][111].LRTableFuncP = LRReduce;
	parser->lrTable[36][111].actionParam = 30;
	//reduce
	parser->lrTable[37][111].LRTableFuncP = LRReduce;
	parser->lrTable[37][111].actionParam = 30;
	//reduce
	parser->lrTable[45][111].LRTableFuncP = LRReduce;
	parser->lrTable[45][111].actionParam = 30;
	//shift
	parser->lrTable[29][112].LRTableFuncP = LRShift;
	parser->lrTable[29][112].actionParam = 1;
	//shift
	parser->lrTable[30][112].LRTableFuncP = LRShift;
	parser->lrTable[30][112].actionParam = 2;
	//shift
	parser->lrTable[31][112].LRTableFuncP = LRShift;
	parser->lrTable[31][112].actionParam = 3;
	//shift
	parser->lrTable[32][112].LRTableFuncP = LRShift;
	parser->lrTable[32][112].actionParam = 4;
	//shift
	parser->lrTable[33][112].LRTableFuncP = LRShift;
	parser->lrTable[33][112].actionParam = 5;
	//shift
	parser->lrTable[38][112].LRTableFuncP = LRShift;
	parser->lrTable[38][112].actionParam = 6;
	//shift
	parser->lrTable[39][112].LRTableFuncP = LRShift;
	parser->lrTable[39][112].actionParam = 7;
	//shift
	parser->lrTable[40][112].LRTableFuncP = LRShift;
	parser->lrTable[40][112].actionParam = 8;
	//reduce
	parser->lrTable[23][112].LRTableFuncP = LRReduce;
	parser->lrTable[23][112].actionParam = 4;
	//goto
	parser->lrTable[StmtList+TOTAL_TOKENS][112].LRTableFuncP = LRGoto;
	parser->lrTable[StmtList+TOTAL_TOKENS][112].actionParam = 115;
	//goto
	parser->lrTable[Stmt+TOTAL_TOKENS][112].LRTableFuncP = LRGoto;
	parser->lrTable[Stmt+TOTAL_TOKENS][112].actionParam = 12;
	//goto
	parser->lrTable[Decl+TOTAL_TOKENS][112].LRTableFuncP = LRGoto;
	parser->lrTable[Decl+TOTAL_TOKENS][112].actionParam = 13;
	//goto
	parser->lrTable[Assi+TOTAL_TOKENS][112].LRTableFuncP = LRGoto;
	parser->lrTable[Assi+TOTAL_TOKENS][112].actionParam = 14;
	//goto
	parser->lrTable[IfStmt+TOTAL_TOKENS][112].LRTableFuncP = LRGoto;
	parser->lrTable[IfStmt+TOTAL_TOKENS][112].actionParam = 15;
	//goto
	parser->lrTable[LoopStmt+TOTAL_TOKENS][112].LRTableFuncP = LRGoto;
	parser->lrTable[LoopStmt+TOTAL_TOKENS][112].actionParam = 16;
	//shift
	parser->lrTable[45][113].LRTableFuncP = LRShift;
	parser->lrTable[45][113].actionParam = 116;
	//shift
	parser->lrTable[29][114].LRTableFuncP = LRShift;
	parser->lrTable[29][114].actionParam = 1;
	//shift
	parser->lrTable[30][114].LRTableFuncP = LRShift;
	parser->lrTable[30][114].actionParam = 2;
	//shift
	parser->lrTable[31][114].LRTableFuncP = LRShift;
	parser->lrTable[31][114].actionParam = 3;
	//shift
	parser->lrTable[32][114].LRTableFuncP = LRShift;
	parser->lrTable[32][114].actionParam = 4;
	//shift
	parser->lrTable[33][114].LRTableFuncP = LRShift;
	parser->lrTable[33][114].actionParam = 5;
	//shift
	parser->lrTable[38][114].LRTableFuncP = LRShift;
	parser->lrTable[38][114].actionParam = 6;
	//shift
	parser->lrTable[39][114].LRTableFuncP = LRShift;
	parser->lrTable[39][114].actionParam = 7;
	//shift
	parser->lrTable[40][114].LRTableFuncP = LRShift;
	parser->lrTable[40][114].actionParam = 8;
	//reduce
	parser->lrTable[23][114].LRTableFuncP = LRReduce;
	parser->lrTable[23][114].actionParam = 4;
	//goto
	parser->lrTable[StmtList+TOTAL_TOKENS][114].LRTableFuncP = LRGoto;
	parser->lrTable[StmtList+TOTAL_TOKENS][114].actionParam = 117;
	//goto
	parser->lrTable[Stmt+TOTAL_TOKENS][114].LRTableFuncP = LRGoto;
	parser->lrTable[Stmt+TOTAL_TOKENS][114].actionParam = 12;
	//goto
	parser->lrTable[Decl+TOTAL_TOKENS][114].LRTableFuncP = LRGoto;
	parser->lrTable[Decl+TOTAL_TOKENS][114].actionParam = 13;
	//goto
	parser->lrTable[Assi+TOTAL_TOKENS][114].LRTableFuncP = LRGoto;
	parser->lrTable[Assi+TOTAL_TOKENS][114].actionParam = 14;
	//goto
	parser->lrTable[IfStmt+TOTAL_TOKENS][114].LRTableFuncP = LRGoto;
	parser->lrTable[IfStmt+TOTAL_TOKENS][114].actionParam = 15;
	//goto
	parser->lrTable[LoopStmt+TOTAL_TOKENS][114].LRTableFuncP = LRGoto;
	parser->lrTable[LoopStmt+TOTAL_TOKENS][114].actionParam = 16;
	//shift
	parser->lrTable[23][115].LRTableFuncP = LRShift;
	parser->lrTable[23][115].actionParam = 118;
	//shift
	parser->lrTable[40][116].LRTableFuncP = LRShift;
	parser->lrTable[40][116].actionParam = 8;
	//goto
	parser->lrTable[Assi+TOTAL_TOKENS][116].LRTableFuncP = LRGoto;
	parser->lrTable[Assi+TOTAL_TOKENS][116].actionParam = 119;
	//shift
	parser->lrTable[23][117].LRTableFuncP = LRShift;
	parser->lrTable[23][117].actionParam = 120;
	//shift
	parser->lrTable[35][118].LRTableFuncP = LRShift;
	parser->lrTable[35][118].actionParam = 121;
	//reduce
	parser->lrTable[41][118].LRTableFuncP = LRReduce;
	parser->lrTable[41][118].actionParam = 56;
	//reduce
	parser->lrTable[23][118].LRTableFuncP = LRReduce;
	parser->lrTable[23][118].actionParam = 56;
	//reduce
	parser->lrTable[29][118].LRTableFuncP = LRReduce;
	parser->lrTable[29][118].actionParam = 56;
	//reduce
	parser->lrTable[30][118].LRTableFuncP = LRReduce;
	parser->lrTable[30][118].actionParam = 56;
	//reduce
	parser->lrTable[31][118].LRTableFuncP = LRReduce;
	parser->lrTable[31][118].actionParam = 56;
	//reduce
	parser->lrTable[32][118].LRTableFuncP = LRReduce;
	parser->lrTable[32][118].actionParam = 56;
	//reduce
	parser->lrTable[33][118].LRTableFuncP = LRReduce;
	parser->lrTable[33][118].actionParam = 56;
	//reduce
	parser->lrTable[38][118].LRTableFuncP = LRReduce;
	parser->lrTable[38][118].actionParam = 56;
	//reduce
	parser->lrTable[39][118].LRTableFuncP = LRReduce;
	parser->lrTable[39][118].actionParam = 56;
	//reduce
	parser->lrTable[40][118].LRTableFuncP = LRReduce;
	parser->lrTable[40][118].actionParam = 56;
	//shift
	parser->lrTable[21][119].LRTableFuncP = LRShift;
	parser->lrTable[21][119].actionParam = 122;
	//reduce
	parser->lrTable[41][120].LRTableFuncP = LRReduce;
	parser->lrTable[41][120].actionParam = 59;
	//reduce
	parser->lrTable[23][120].LRTableFuncP = LRReduce;
	parser->lrTable[23][120].actionParam = 59;
	//reduce
	parser->lrTable[29][120].LRTableFuncP = LRReduce;
	parser->lrTable[29][120].actionParam = 59;
	//reduce
	parser->lrTable[30][120].LRTableFuncP = LRReduce;
	parser->lrTable[30][120].actionParam = 59;
	//reduce
	parser->lrTable[31][120].LRTableFuncP = LRReduce;
	parser->lrTable[31][120].actionParam = 59;
	//reduce
	parser->lrTable[32][120].LRTableFuncP = LRReduce;
	parser->lrTable[32][120].actionParam = 59;
	//reduce
	parser->lrTable[33][120].LRTableFuncP = LRReduce;
	parser->lrTable[33][120].actionParam = 59;
	//reduce
	parser->lrTable[38][120].LRTableFuncP = LRReduce;
	parser->lrTable[38][120].actionParam = 59;
	//reduce
	parser->lrTable[39][120].LRTableFuncP = LRReduce;
	parser->lrTable[39][120].actionParam = 59;
	//reduce
	parser->lrTable[40][120].LRTableFuncP = LRReduce;
	parser->lrTable[40][120].actionParam = 59;
	//shift
	parser->lrTable[22][121].LRTableFuncP = LRShift;
	parser->lrTable[22][121].actionParam = 123;
	//shift
	parser->lrTable[22][122].LRTableFuncP = LRShift;
	parser->lrTable[22][122].actionParam = 124;
	//shift
	parser->lrTable[29][123].LRTableFuncP = LRShift;
	parser->lrTable[29][123].actionParam = 1;
	//shift
	parser->lrTable[30][123].LRTableFuncP = LRShift;
	parser->lrTable[30][123].actionParam = 2;
	//shift
	parser->lrTable[31][123].LRTableFuncP = LRShift;
	parser->lrTable[31][123].actionParam = 3;
	//shift
	parser->lrTable[32][123].LRTableFuncP = LRShift;
	parser->lrTable[32][123].actionParam = 4;
	//shift
	parser->lrTable[33][123].LRTableFuncP = LRShift;
	parser->lrTable[33][123].actionParam = 5;
	//shift
	parser->lrTable[38][123].LRTableFuncP = LRShift;
	parser->lrTable[38][123].actionParam = 6;
	//shift
	parser->lrTable[39][123].LRTableFuncP = LRShift;
	parser->lrTable[39][123].actionParam = 7;
	//shift
	parser->lrTable[40][123].LRTableFuncP = LRShift;
	parser->lrTable[40][123].actionParam = 8;
	//reduce
	parser->lrTable[23][123].LRTableFuncP = LRReduce;
	parser->lrTable[23][123].actionParam = 4;
	//goto
	parser->lrTable[StmtList+TOTAL_TOKENS][123].LRTableFuncP = LRGoto;
	parser->lrTable[StmtList+TOTAL_TOKENS][123].actionParam = 125;
	//goto
	parser->lrTable[Stmt+TOTAL_TOKENS][123].LRTableFuncP = LRGoto;
	parser->lrTable[Stmt+TOTAL_TOKENS][123].actionParam = 12;
	//goto
	parser->lrTable[Decl+TOTAL_TOKENS][123].LRTableFuncP = LRGoto;
	parser->lrTable[Decl+TOTAL_TOKENS][123].actionParam = 13;
	//goto
	parser->lrTable[Assi+TOTAL_TOKENS][123].LRTableFuncP = LRGoto;
	parser->lrTable[Assi+TOTAL_TOKENS][123].actionParam = 14;
	//goto
	parser->lrTable[IfStmt+TOTAL_TOKENS][123].LRTableFuncP = LRGoto;
	parser->lrTable[IfStmt+TOTAL_TOKENS][123].actionParam = 15;
	//goto
	parser->lrTable[LoopStmt+TOTAL_TOKENS][123].LRTableFuncP = LRGoto;
	parser->lrTable[LoopStmt+TOTAL_TOKENS][123].actionParam = 16;
	//shift
	parser->lrTable[29][124].LRTableFuncP = LRShift;
	parser->lrTable[29][124].actionParam = 1;
	//shift
	parser->lrTable[30][124].LRTableFuncP = LRShift;
	parser->lrTable[30][124].actionParam = 2;
	//shift
	parser->lrTable[31][124].LRTableFuncP = LRShift;
	parser->lrTable[31][124].actionParam = 3;
	//shift
	parser->lrTable[32][124].LRTableFuncP = LRShift;
	parser->lrTable[32][124].actionParam = 4;
	//shift
	parser->lrTable[33][124].LRTableFuncP = LRShift;
	parser->lrTable[33][124].actionParam = 5;
	//shift
	parser->lrTable[38][124].LRTableFuncP = LRShift;
	parser->lrTable[38][124].actionParam = 6;
	//shift
	parser->lrTable[39][124].LRTableFuncP = LRShift;
	parser->lrTable[39][124].actionParam = 7;
	//shift
	parser->lrTable[40][124].LRTableFuncP = LRShift;
	parser->lrTable[40][124].actionParam = 8;
	//reduce
	parser->lrTable[23][124].LRTableFuncP = LRReduce;
	parser->lrTable[23][124].actionParam = 4;
	//goto
	parser->lrTable[StmtList+TOTAL_TOKENS][124].LRTableFuncP = LRGoto;
	parser->lrTable[StmtList+TOTAL_TOKENS][124].actionParam = 126;
	//goto
	parser->lrTable[Stmt+TOTAL_TOKENS][124].LRTableFuncP = LRGoto;
	parser->lrTable[Stmt+TOTAL_TOKENS][124].actionParam = 12;
	//goto
	parser->lrTable[Decl+TOTAL_TOKENS][124].LRTableFuncP = LRGoto;
	parser->lrTable[Decl+TOTAL_TOKENS][124].actionParam = 13;
	//goto
	parser->lrTable[Assi+TOTAL_TOKENS][124].LRTableFuncP = LRGoto;
	parser->lrTable[Assi+TOTAL_TOKENS][124].actionParam = 14;
	//goto
	parser->lrTable[IfStmt+TOTAL_TOKENS][124].LRTableFuncP = LRGoto;
	parser->lrTable[IfStmt+TOTAL_TOKENS][124].actionParam = 15;
	//goto
	parser->lrTable[LoopStmt+TOTAL_TOKENS][124].LRTableFuncP = LRGoto;
	parser->lrTable[LoopStmt+TOTAL_TOKENS][124].actionParam = 16;
	//shift
	parser->lrTable[23][125].LRTableFuncP = LRShift;
	parser->lrTable[23][125].actionParam = 127;
	//shift
	parser->lrTable[23][126].LRTableFuncP = LRShift;
	parser->lrTable[23][126].actionParam = 128;
	//reduce
	parser->lrTable[41][127].LRTableFuncP = LRReduce;
	parser->lrTable[41][127].actionParam = 57;
	//reduce
	parser->lrTable[23][127].LRTableFuncP = LRReduce;
	parser->lrTable[23][127].actionParam = 57;
	//reduce
	parser->lrTable[29][127].LRTableFuncP = LRReduce;
	parser->lrTable[29][127].actionParam = 57;
	//reduce
	parser->lrTable[30][127].LRTableFuncP = LRReduce;
	parser->lrTable[30][127].actionParam = 57;
	//reduce
	parser->lrTable[31][127].LRTableFuncP = LRReduce;
	parser->lrTable[31][127].actionParam = 57;
	//reduce
	parser->lrTable[32][127].LRTableFuncP = LRReduce;
	parser->lrTable[32][127].actionParam = 57;
	//reduce
	parser->lrTable[33][127].LRTableFuncP = LRReduce;
	parser->lrTable[33][127].actionParam = 57;
	//reduce
	parser->lrTable[38][127].LRTableFuncP = LRReduce;
	parser->lrTable[38][127].actionParam = 57;
	//reduce
	parser->lrTable[39][127].LRTableFuncP = LRReduce;
	parser->lrTable[39][127].actionParam = 57;
	//reduce
	parser->lrTable[40][127].LRTableFuncP = LRReduce;
	parser->lrTable[40][127].actionParam = 57;
	//reduce
	parser->lrTable[41][128].LRTableFuncP = LRReduce;
	parser->lrTable[41][128].actionParam = 58;
	//reduce
	parser->lrTable[23][128].LRTableFuncP = LRReduce;
	parser->lrTable[23][128].actionParam = 58;
	//reduce
	parser->lrTable[29][128].LRTableFuncP = LRReduce;
	parser->lrTable[29][128].actionParam = 58;
	//reduce
	parser->lrTable[30][128].LRTableFuncP = LRReduce;
	parser->lrTable[30][128].actionParam = 58;
	//reduce
	parser->lrTable[31][128].LRTableFuncP = LRReduce;
	parser->lrTable[31][128].actionParam = 58;
	//reduce
	parser->lrTable[32][128].LRTableFuncP = LRReduce;
	parser->lrTable[32][128].actionParam = 58;
	//reduce
	parser->lrTable[33][128].LRTableFuncP = LRReduce;
	parser->lrTable[33][128].actionParam = 58;
	//reduce
	parser->lrTable[38][128].LRTableFuncP = LRReduce;
	parser->lrTable[38][128].actionParam = 58;
	//reduce
	parser->lrTable[39][128].LRTableFuncP = LRReduce;
	parser->lrTable[39][128].actionParam = 58;
	//reduce
	parser->lrTable[40][128].LRTableFuncP = LRReduce;
	parser->lrTable[40][128].actionParam = 58;
}