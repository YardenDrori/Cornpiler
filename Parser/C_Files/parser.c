#include "../H_Files/parser.h"
#include "../H_Files/stack.h"
#include "../H_Files/LRTable.h"
#include "../../Lexer/H_Files/token.h"

#include <stdio.h>
#include <stdlib.h>
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
	getTokenList(parser->lexer);
    parser->stack = initStack();
    pushInt(parser->stack, 0); 

	int temp = 0;
	//reduce function pointer assignment
	parser->ReduceFunctionTable[temp++] = accept;
	parser->ReduceFunctionTable[temp++] = ReduceToProgram1;
	parser->ReduceFunctionTable[temp++] = ReduceToStart1;
	parser->ReduceFunctionTable[temp++] = ReduceToExpr3;
	parser->ReduceFunctionTable[temp++] = ReduceToExpr3;
	parser->ReduceFunctionTable[temp++] = ReduceToExpr1;
	parser->ReduceFunctionTable[temp++] = ReduceToTerm3;
	parser->ReduceFunctionTable[temp++] = ReduceToTerm3;
	parser->ReduceFunctionTable[temp++] = ReduceToTerm3;
	parser->ReduceFunctionTable[temp++] = ReduceToTerm1;
	parser->ReduceFunctionTable[temp++] = ReduceToFactor3;
	parser->ReduceFunctionTable[temp++] = ReduceToFactor1;
	parser->ReduceFunctionTable[temp++] = ReduceToFactor1;
	parser->ReduceFunctionTable[temp++] = ReduceToFactor1;
	parser->ReduceFunctionTable[temp++] = ReduceToFactor2;
	parser->ReduceFunctionTable[temp++] = ReduceToFactor2;
	parser->ReduceFunctionTable[temp++] = ReduceToFactor2;
	parser->ReduceFunctionTable[temp++] = ReduceToFactor2;
 


	




	for (int i = 0; i < TOTAL_TOKENS+GRAMMER_SYMBOL_COUNT; i++){
		for (int j = 0; j < TOTAL_STATES; j++){
			parser->lrTable[i][j].LRTableFuncP = LRError;
			parser->lrTable[i][j].actionParam = -1;
		}
	}
	//shift
	parser->lrTable[9][0].LRTableFuncP = LRShift;
	parser->lrTable[9][0].actionParam = 1;
	//shift
	parser->lrTable[12][0].LRTableFuncP = LRShift;
	parser->lrTable[12][0].actionParam = 2;
	//shift
	parser->lrTable[20][0].LRTableFuncP = LRShift;
	parser->lrTable[20][0].actionParam = 3;
	//shift
	parser->lrTable[40][0].LRTableFuncP = LRShift;
	parser->lrTable[40][0].actionParam = 4;
	//shift
	parser->lrTable[27][0].LRTableFuncP = LRShift;
	parser->lrTable[27][0].actionParam = 5;
	//shift
	parser->lrTable[24][0].LRTableFuncP = LRShift;
	parser->lrTable[24][0].actionParam = 6;
	//goto
	parser->lrTable[PROGRAM+TOTAL_VALID_ACTIONS][0].LRTableFuncP = LRGoto;
	parser->lrTable[PROGRAM+TOTAL_VALID_ACTIONS][0].actionParam = 7;
	//goto
	parser->lrTable[Start+TOTAL_VALID_ACTIONS][0].LRTableFuncP = LRGoto;
	parser->lrTable[Start+TOTAL_VALID_ACTIONS][0].actionParam = 8;
	//goto
	parser->lrTable[Expr+TOTAL_VALID_ACTIONS][0].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_VALID_ACTIONS][0].actionParam = 9;
	//goto
	parser->lrTable[Term+TOTAL_VALID_ACTIONS][0].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_VALID_ACTIONS][0].actionParam = 10;
	//goto
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][0].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][0].actionParam = 11;
	//shift
	parser->lrTable[40][1].LRTableFuncP = LRShift;
	parser->lrTable[40][1].actionParam = 12;
	//shift
	parser->lrTable[40][2].LRTableFuncP = LRShift;
	parser->lrTable[40][2].actionParam = 13;
	//shift
	parser->lrTable[9][3].LRTableFuncP = LRShift;
	parser->lrTable[9][3].actionParam = 29;
	//shift
	parser->lrTable[12][3].LRTableFuncP = LRShift;
	parser->lrTable[12][3].actionParam = 30;
	//shift
	parser->lrTable[20][3].LRTableFuncP = LRShift;
	parser->lrTable[20][3].actionParam = 31;
	//shift
	parser->lrTable[40][3].LRTableFuncP = LRShift;
	parser->lrTable[40][3].actionParam = 32;
	//shift
	parser->lrTable[27][3].LRTableFuncP = LRShift;
	parser->lrTable[27][3].actionParam = 33;
	//shift
	parser->lrTable[24][3].LRTableFuncP = LRShift;
	parser->lrTable[24][3].actionParam = 34;
	//goto
	parser->lrTable[Expr+TOTAL_VALID_ACTIONS][3].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_VALID_ACTIONS][3].actionParam = 14;
	//goto
	parser->lrTable[Term+TOTAL_VALID_ACTIONS][3].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_VALID_ACTIONS][3].actionParam = 35;
	//goto
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][3].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][3].actionParam = 36;
	//shift
	parser->lrTable[9][4].LRTableFuncP = LRShift;
	parser->lrTable[9][4].actionParam = 15;
	//shift
	parser->lrTable[12][4].LRTableFuncP = LRShift;
	parser->lrTable[12][4].actionParam = 16;
	//reduce
	parser->lrTable[41][4].LRTableFuncP = LRReduce;
	parser->lrTable[41][4].actionParam = 11;
	//reduce
	parser->lrTable[8][4].LRTableFuncP = LRReduce;
	parser->lrTable[8][4].actionParam = 11;
	//reduce
	parser->lrTable[11][4].LRTableFuncP = LRReduce;
	parser->lrTable[11][4].actionParam = 11;
	//reduce
	parser->lrTable[16][4].LRTableFuncP = LRReduce;
	parser->lrTable[16][4].actionParam = 11;
	//reduce
	parser->lrTable[14][4].LRTableFuncP = LRReduce;
	parser->lrTable[14][4].actionParam = 11;
	//reduce
	parser->lrTable[-2][4].LRTableFuncP = LRReduce;
	parser->lrTable[-2][4].actionParam = 11;
	//reduce
	parser->lrTable[41][5].LRTableFuncP = LRReduce;
	parser->lrTable[41][5].actionParam = 12;
	//reduce
	parser->lrTable[8][5].LRTableFuncP = LRReduce;
	parser->lrTable[8][5].actionParam = 12;
	//reduce
	parser->lrTable[11][5].LRTableFuncP = LRReduce;
	parser->lrTable[11][5].actionParam = 12;
	//reduce
	parser->lrTable[16][5].LRTableFuncP = LRReduce;
	parser->lrTable[16][5].actionParam = 12;
	//reduce
	parser->lrTable[14][5].LRTableFuncP = LRReduce;
	parser->lrTable[14][5].actionParam = 12;
	//reduce
	parser->lrTable[-2][5].LRTableFuncP = LRReduce;
	parser->lrTable[-2][5].actionParam = 12;
	//reduce
	parser->lrTable[41][6].LRTableFuncP = LRReduce;
	parser->lrTable[41][6].actionParam = 13;
	//reduce
	parser->lrTable[8][6].LRTableFuncP = LRReduce;
	parser->lrTable[8][6].actionParam = 13;
	//reduce
	parser->lrTable[11][6].LRTableFuncP = LRReduce;
	parser->lrTable[11][6].actionParam = 13;
	//reduce
	parser->lrTable[16][6].LRTableFuncP = LRReduce;
	parser->lrTable[16][6].actionParam = 13;
	//reduce
	parser->lrTable[14][6].LRTableFuncP = LRReduce;
	parser->lrTable[14][6].actionParam = 13;
	//reduce
	parser->lrTable[-2][6].LRTableFuncP = LRReduce;
	parser->lrTable[-2][6].actionParam = 13;
	//shift
	parser->lrTable[41][7].LRTableFuncP = LRShift;
	parser->lrTable[41][7].actionParam = 17;
	//reduce
	parser->lrTable[41][8].LRTableFuncP = LRReduce;
	parser->lrTable[41][8].actionParam = 1;
	//shift
	parser->lrTable[8][9].LRTableFuncP = LRShift;
	parser->lrTable[8][9].actionParam = 18;
	//shift
	parser->lrTable[11][9].LRTableFuncP = LRShift;
	parser->lrTable[11][9].actionParam = 19;
	//reduce
	parser->lrTable[41][9].LRTableFuncP = LRReduce;
	parser->lrTable[41][9].actionParam = 2;
	//shift
	parser->lrTable[16][10].LRTableFuncP = LRShift;
	parser->lrTable[16][10].actionParam = 20;
	//shift
	parser->lrTable[14][10].LRTableFuncP = LRShift;
	parser->lrTable[14][10].actionParam = 21;
	//shift
	parser->lrTable[-2][10].LRTableFuncP = LRShift;
	parser->lrTable[-2][10].actionParam = 22;
	//reduce
	parser->lrTable[41][10].LRTableFuncP = LRReduce;
	parser->lrTable[41][10].actionParam = 5;
	//reduce
	parser->lrTable[8][10].LRTableFuncP = LRReduce;
	parser->lrTable[8][10].actionParam = 5;
	//reduce
	parser->lrTable[11][10].LRTableFuncP = LRReduce;
	parser->lrTable[11][10].actionParam = 5;
	//reduce
	parser->lrTable[41][11].LRTableFuncP = LRReduce;
	parser->lrTable[41][11].actionParam = 9;
	//reduce
	parser->lrTable[8][11].LRTableFuncP = LRReduce;
	parser->lrTable[8][11].actionParam = 9;
	//reduce
	parser->lrTable[11][11].LRTableFuncP = LRReduce;
	parser->lrTable[11][11].actionParam = 9;
	//reduce
	parser->lrTable[16][11].LRTableFuncP = LRReduce;
	parser->lrTable[16][11].actionParam = 9;
	//reduce
	parser->lrTable[14][11].LRTableFuncP = LRReduce;
	parser->lrTable[14][11].actionParam = 9;
	//reduce
	parser->lrTable[-2][11].LRTableFuncP = LRReduce;
	parser->lrTable[-2][11].actionParam = 9;
	//reduce
	parser->lrTable[41][12].LRTableFuncP = LRReduce;
	parser->lrTable[41][12].actionParam = 17;
	//reduce
	parser->lrTable[8][12].LRTableFuncP = LRReduce;
	parser->lrTable[8][12].actionParam = 17;
	//reduce
	parser->lrTable[11][12].LRTableFuncP = LRReduce;
	parser->lrTable[11][12].actionParam = 17;
	//reduce
	parser->lrTable[16][12].LRTableFuncP = LRReduce;
	parser->lrTable[16][12].actionParam = 17;
	//reduce
	parser->lrTable[14][12].LRTableFuncP = LRReduce;
	parser->lrTable[14][12].actionParam = 17;
	//reduce
	parser->lrTable[-2][12].LRTableFuncP = LRReduce;
	parser->lrTable[-2][12].actionParam = 17;
	//reduce
	parser->lrTable[41][13].LRTableFuncP = LRReduce;
	parser->lrTable[41][13].actionParam = 16;
	//reduce
	parser->lrTable[8][13].LRTableFuncP = LRReduce;
	parser->lrTable[8][13].actionParam = 16;
	//reduce
	parser->lrTable[11][13].LRTableFuncP = LRReduce;
	parser->lrTable[11][13].actionParam = 16;
	//reduce
	parser->lrTable[16][13].LRTableFuncP = LRReduce;
	parser->lrTable[16][13].actionParam = 16;
	//reduce
	parser->lrTable[14][13].LRTableFuncP = LRReduce;
	parser->lrTable[14][13].actionParam = 16;
	//reduce
	parser->lrTable[-2][13].LRTableFuncP = LRReduce;
	parser->lrTable[-2][13].actionParam = 16;
	//shift
	parser->lrTable[8][14].LRTableFuncP = LRShift;
	parser->lrTable[8][14].actionParam = 37;
	//shift
	parser->lrTable[11][14].LRTableFuncP = LRShift;
	parser->lrTable[11][14].actionParam = 38;
	//shift
	parser->lrTable[21][14].LRTableFuncP = LRShift;
	parser->lrTable[21][14].actionParam = 23;
	//reduce
	parser->lrTable[41][15].LRTableFuncP = LRReduce;
	parser->lrTable[41][15].actionParam = 14;
	//reduce
	parser->lrTable[8][15].LRTableFuncP = LRReduce;
	parser->lrTable[8][15].actionParam = 14;
	//reduce
	parser->lrTable[11][15].LRTableFuncP = LRReduce;
	parser->lrTable[11][15].actionParam = 14;
	//reduce
	parser->lrTable[16][15].LRTableFuncP = LRReduce;
	parser->lrTable[16][15].actionParam = 14;
	//reduce
	parser->lrTable[14][15].LRTableFuncP = LRReduce;
	parser->lrTable[14][15].actionParam = 14;
	//reduce
	parser->lrTable[-2][15].LRTableFuncP = LRReduce;
	parser->lrTable[-2][15].actionParam = 14;
	//reduce
	parser->lrTable[41][16].LRTableFuncP = LRReduce;
	parser->lrTable[41][16].actionParam = 15;
	//reduce
	parser->lrTable[8][16].LRTableFuncP = LRReduce;
	parser->lrTable[8][16].actionParam = 15;
	//reduce
	parser->lrTable[11][16].LRTableFuncP = LRReduce;
	parser->lrTable[11][16].actionParam = 15;
	//reduce
	parser->lrTable[16][16].LRTableFuncP = LRReduce;
	parser->lrTable[16][16].actionParam = 15;
	//reduce
	parser->lrTable[14][16].LRTableFuncP = LRReduce;
	parser->lrTable[14][16].actionParam = 15;
	//reduce
	parser->lrTable[-2][16].LRTableFuncP = LRReduce;
	parser->lrTable[-2][16].actionParam = 15;
	//accept
	parser->lrTable[-2][17].LRTableFuncP = LRAccept;
	parser->lrTable[-2][17].actionParam = -1;
	//shift
	parser->lrTable[9][18].LRTableFuncP = LRShift;
	parser->lrTable[9][18].actionParam = 1;
	//shift
	parser->lrTable[12][18].LRTableFuncP = LRShift;
	parser->lrTable[12][18].actionParam = 2;
	//shift
	parser->lrTable[20][18].LRTableFuncP = LRShift;
	parser->lrTable[20][18].actionParam = 3;
	//shift
	parser->lrTable[40][18].LRTableFuncP = LRShift;
	parser->lrTable[40][18].actionParam = 4;
	//shift
	parser->lrTable[27][18].LRTableFuncP = LRShift;
	parser->lrTable[27][18].actionParam = 5;
	//shift
	parser->lrTable[24][18].LRTableFuncP = LRShift;
	parser->lrTable[24][18].actionParam = 6;
	//goto
	parser->lrTable[Term+TOTAL_VALID_ACTIONS][18].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_VALID_ACTIONS][18].actionParam = 24;
	//goto
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][18].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][18].actionParam = 11;
	//shift
	parser->lrTable[9][19].LRTableFuncP = LRShift;
	parser->lrTable[9][19].actionParam = 1;
	//shift
	parser->lrTable[12][19].LRTableFuncP = LRShift;
	parser->lrTable[12][19].actionParam = 2;
	//shift
	parser->lrTable[20][19].LRTableFuncP = LRShift;
	parser->lrTable[20][19].actionParam = 3;
	//shift
	parser->lrTable[40][19].LRTableFuncP = LRShift;
	parser->lrTable[40][19].actionParam = 4;
	//shift
	parser->lrTable[27][19].LRTableFuncP = LRShift;
	parser->lrTable[27][19].actionParam = 5;
	//shift
	parser->lrTable[24][19].LRTableFuncP = LRShift;
	parser->lrTable[24][19].actionParam = 6;
	//goto
	parser->lrTable[Term+TOTAL_VALID_ACTIONS][19].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_VALID_ACTIONS][19].actionParam = 25;
	//goto
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][19].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][19].actionParam = 11;
	//shift
	parser->lrTable[9][20].LRTableFuncP = LRShift;
	parser->lrTable[9][20].actionParam = 1;
	//shift
	parser->lrTable[12][20].LRTableFuncP = LRShift;
	parser->lrTable[12][20].actionParam = 2;
	//shift
	parser->lrTable[20][20].LRTableFuncP = LRShift;
	parser->lrTable[20][20].actionParam = 3;
	//shift
	parser->lrTable[40][20].LRTableFuncP = LRShift;
	parser->lrTable[40][20].actionParam = 4;
	//shift
	parser->lrTable[27][20].LRTableFuncP = LRShift;
	parser->lrTable[27][20].actionParam = 5;
	//shift
	parser->lrTable[24][20].LRTableFuncP = LRShift;
	parser->lrTable[24][20].actionParam = 6;
	//goto
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][20].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][20].actionParam = 26;
	//shift
	parser->lrTable[9][21].LRTableFuncP = LRShift;
	parser->lrTable[9][21].actionParam = 1;
	//shift
	parser->lrTable[12][21].LRTableFuncP = LRShift;
	parser->lrTable[12][21].actionParam = 2;
	//shift
	parser->lrTable[20][21].LRTableFuncP = LRShift;
	parser->lrTable[20][21].actionParam = 3;
	//shift
	parser->lrTable[40][21].LRTableFuncP = LRShift;
	parser->lrTable[40][21].actionParam = 4;
	//shift
	parser->lrTable[27][21].LRTableFuncP = LRShift;
	parser->lrTable[27][21].actionParam = 5;
	//shift
	parser->lrTable[24][21].LRTableFuncP = LRShift;
	parser->lrTable[24][21].actionParam = 6;
	//goto
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][21].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][21].actionParam = 27;
	//shift
	parser->lrTable[9][22].LRTableFuncP = LRShift;
	parser->lrTable[9][22].actionParam = 1;
	//shift
	parser->lrTable[12][22].LRTableFuncP = LRShift;
	parser->lrTable[12][22].actionParam = 2;
	//shift
	parser->lrTable[20][22].LRTableFuncP = LRShift;
	parser->lrTable[20][22].actionParam = 3;
	//shift
	parser->lrTable[40][22].LRTableFuncP = LRShift;
	parser->lrTable[40][22].actionParam = 4;
	//shift
	parser->lrTable[27][22].LRTableFuncP = LRShift;
	parser->lrTable[27][22].actionParam = 5;
	//shift
	parser->lrTable[24][22].LRTableFuncP = LRShift;
	parser->lrTable[24][22].actionParam = 6;
	//goto
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][22].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][22].actionParam = 28;
	//reduce
	parser->lrTable[41][23].LRTableFuncP = LRReduce;
	parser->lrTable[41][23].actionParam = 10;
	//reduce
	parser->lrTable[8][23].LRTableFuncP = LRReduce;
	parser->lrTable[8][23].actionParam = 10;
	//reduce
	parser->lrTable[11][23].LRTableFuncP = LRReduce;
	parser->lrTable[11][23].actionParam = 10;
	//reduce
	parser->lrTable[16][23].LRTableFuncP = LRReduce;
	parser->lrTable[16][23].actionParam = 10;
	//reduce
	parser->lrTable[14][23].LRTableFuncP = LRReduce;
	parser->lrTable[14][23].actionParam = 10;
	//reduce
	parser->lrTable[-2][23].LRTableFuncP = LRReduce;
	parser->lrTable[-2][23].actionParam = 10;
	//shift
	parser->lrTable[16][24].LRTableFuncP = LRShift;
	parser->lrTable[16][24].actionParam = 20;
	//shift
	parser->lrTable[14][24].LRTableFuncP = LRShift;
	parser->lrTable[14][24].actionParam = 21;
	//shift
	parser->lrTable[-2][24].LRTableFuncP = LRShift;
	parser->lrTable[-2][24].actionParam = 22;
	//reduce
	parser->lrTable[41][24].LRTableFuncP = LRReduce;
	parser->lrTable[41][24].actionParam = 3;
	//reduce
	parser->lrTable[8][24].LRTableFuncP = LRReduce;
	parser->lrTable[8][24].actionParam = 3;
	//reduce
	parser->lrTable[11][24].LRTableFuncP = LRReduce;
	parser->lrTable[11][24].actionParam = 3;
	//shift
	parser->lrTable[16][25].LRTableFuncP = LRShift;
	parser->lrTable[16][25].actionParam = 20;
	//shift
	parser->lrTable[14][25].LRTableFuncP = LRShift;
	parser->lrTable[14][25].actionParam = 21;
	//shift
	parser->lrTable[-2][25].LRTableFuncP = LRShift;
	parser->lrTable[-2][25].actionParam = 22;
	//reduce
	parser->lrTable[41][25].LRTableFuncP = LRReduce;
	parser->lrTable[41][25].actionParam = 4;
	//reduce
	parser->lrTable[8][25].LRTableFuncP = LRReduce;
	parser->lrTable[8][25].actionParam = 4;
	//reduce
	parser->lrTable[11][25].LRTableFuncP = LRReduce;
	parser->lrTable[11][25].actionParam = 4;
	//reduce
	parser->lrTable[41][26].LRTableFuncP = LRReduce;
	parser->lrTable[41][26].actionParam = 6;
	//reduce
	parser->lrTable[8][26].LRTableFuncP = LRReduce;
	parser->lrTable[8][26].actionParam = 6;
	//reduce
	parser->lrTable[11][26].LRTableFuncP = LRReduce;
	parser->lrTable[11][26].actionParam = 6;
	//reduce
	parser->lrTable[16][26].LRTableFuncP = LRReduce;
	parser->lrTable[16][26].actionParam = 6;
	//reduce
	parser->lrTable[14][26].LRTableFuncP = LRReduce;
	parser->lrTable[14][26].actionParam = 6;
	//reduce
	parser->lrTable[-2][26].LRTableFuncP = LRReduce;
	parser->lrTable[-2][26].actionParam = 6;
	//reduce
	parser->lrTable[41][27].LRTableFuncP = LRReduce;
	parser->lrTable[41][27].actionParam = 7;
	//reduce
	parser->lrTable[8][27].LRTableFuncP = LRReduce;
	parser->lrTable[8][27].actionParam = 7;
	//reduce
	parser->lrTable[11][27].LRTableFuncP = LRReduce;
	parser->lrTable[11][27].actionParam = 7;
	//reduce
	parser->lrTable[16][27].LRTableFuncP = LRReduce;
	parser->lrTable[16][27].actionParam = 7;
	//reduce
	parser->lrTable[14][27].LRTableFuncP = LRReduce;
	parser->lrTable[14][27].actionParam = 7;
	//reduce
	parser->lrTable[-2][27].LRTableFuncP = LRReduce;
	parser->lrTable[-2][27].actionParam = 7;
	//reduce
	parser->lrTable[41][28].LRTableFuncP = LRReduce;
	parser->lrTable[41][28].actionParam = 8;
	//reduce
	parser->lrTable[8][28].LRTableFuncP = LRReduce;
	parser->lrTable[8][28].actionParam = 8;
	//reduce
	parser->lrTable[11][28].LRTableFuncP = LRReduce;
	parser->lrTable[11][28].actionParam = 8;
	//reduce
	parser->lrTable[16][28].LRTableFuncP = LRReduce;
	parser->lrTable[16][28].actionParam = 8;
	//reduce
	parser->lrTable[14][28].LRTableFuncP = LRReduce;
	parser->lrTable[14][28].actionParam = 8;
	//reduce
	parser->lrTable[-2][28].LRTableFuncP = LRReduce;
	parser->lrTable[-2][28].actionParam = 8;
	//shift
	parser->lrTable[40][29].LRTableFuncP = LRShift;
	parser->lrTable[40][29].actionParam = 39;
	//shift
	parser->lrTable[40][30].LRTableFuncP = LRShift;
	parser->lrTable[40][30].actionParam = 40;
	//shift
	parser->lrTable[9][31].LRTableFuncP = LRShift;
	parser->lrTable[9][31].actionParam = 29;
	//shift
	parser->lrTable[12][31].LRTableFuncP = LRShift;
	parser->lrTable[12][31].actionParam = 30;
	//shift
	parser->lrTable[20][31].LRTableFuncP = LRShift;
	parser->lrTable[20][31].actionParam = 31;
	//shift
	parser->lrTable[40][31].LRTableFuncP = LRShift;
	parser->lrTable[40][31].actionParam = 32;
	//shift
	parser->lrTable[27][31].LRTableFuncP = LRShift;
	parser->lrTable[27][31].actionParam = 33;
	//shift
	parser->lrTable[24][31].LRTableFuncP = LRShift;
	parser->lrTable[24][31].actionParam = 34;
	//goto
	parser->lrTable[Expr+TOTAL_VALID_ACTIONS][31].LRTableFuncP = LRGoto;
	parser->lrTable[Expr+TOTAL_VALID_ACTIONS][31].actionParam = 41;
	//goto
	parser->lrTable[Term+TOTAL_VALID_ACTIONS][31].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_VALID_ACTIONS][31].actionParam = 35;
	//goto
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][31].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][31].actionParam = 36;
	//shift
	parser->lrTable[9][32].LRTableFuncP = LRShift;
	parser->lrTable[9][32].actionParam = 42;
	//shift
	parser->lrTable[12][32].LRTableFuncP = LRShift;
	parser->lrTable[12][32].actionParam = 43;
	//reduce
	parser->lrTable[8][32].LRTableFuncP = LRReduce;
	parser->lrTable[8][32].actionParam = 11;
	//reduce
	parser->lrTable[11][32].LRTableFuncP = LRReduce;
	parser->lrTable[11][32].actionParam = 11;
	//reduce
	parser->lrTable[16][32].LRTableFuncP = LRReduce;
	parser->lrTable[16][32].actionParam = 11;
	//reduce
	parser->lrTable[14][32].LRTableFuncP = LRReduce;
	parser->lrTable[14][32].actionParam = 11;
	//reduce
	parser->lrTable[-2][32].LRTableFuncP = LRReduce;
	parser->lrTable[-2][32].actionParam = 11;
	//reduce
	parser->lrTable[21][32].LRTableFuncP = LRReduce;
	parser->lrTable[21][32].actionParam = 11;
	//reduce
	parser->lrTable[8][33].LRTableFuncP = LRReduce;
	parser->lrTable[8][33].actionParam = 12;
	//reduce
	parser->lrTable[11][33].LRTableFuncP = LRReduce;
	parser->lrTable[11][33].actionParam = 12;
	//reduce
	parser->lrTable[16][33].LRTableFuncP = LRReduce;
	parser->lrTable[16][33].actionParam = 12;
	//reduce
	parser->lrTable[14][33].LRTableFuncP = LRReduce;
	parser->lrTable[14][33].actionParam = 12;
	//reduce
	parser->lrTable[-2][33].LRTableFuncP = LRReduce;
	parser->lrTable[-2][33].actionParam = 12;
	//reduce
	parser->lrTable[21][33].LRTableFuncP = LRReduce;
	parser->lrTable[21][33].actionParam = 12;
	//reduce
	parser->lrTable[8][34].LRTableFuncP = LRReduce;
	parser->lrTable[8][34].actionParam = 13;
	//reduce
	parser->lrTable[11][34].LRTableFuncP = LRReduce;
	parser->lrTable[11][34].actionParam = 13;
	//reduce
	parser->lrTable[16][34].LRTableFuncP = LRReduce;
	parser->lrTable[16][34].actionParam = 13;
	//reduce
	parser->lrTable[14][34].LRTableFuncP = LRReduce;
	parser->lrTable[14][34].actionParam = 13;
	//reduce
	parser->lrTable[-2][34].LRTableFuncP = LRReduce;
	parser->lrTable[-2][34].actionParam = 13;
	//reduce
	parser->lrTable[21][34].LRTableFuncP = LRReduce;
	parser->lrTable[21][34].actionParam = 13;
	//shift
	parser->lrTable[16][35].LRTableFuncP = LRShift;
	parser->lrTable[16][35].actionParam = 44;
	//shift
	parser->lrTable[14][35].LRTableFuncP = LRShift;
	parser->lrTable[14][35].actionParam = 45;
	//shift
	parser->lrTable[-2][35].LRTableFuncP = LRShift;
	parser->lrTable[-2][35].actionParam = 46;
	//reduce
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 5;
	//reduce
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 5;
	//reduce
	parser->lrTable[21][35].LRTableFuncP = LRReduce;
	parser->lrTable[21][35].actionParam = 5;
	//reduce
	parser->lrTable[8][36].LRTableFuncP = LRReduce;
	parser->lrTable[8][36].actionParam = 9;
	//reduce
	parser->lrTable[11][36].LRTableFuncP = LRReduce;
	parser->lrTable[11][36].actionParam = 9;
	//reduce
	parser->lrTable[16][36].LRTableFuncP = LRReduce;
	parser->lrTable[16][36].actionParam = 9;
	//reduce
	parser->lrTable[14][36].LRTableFuncP = LRReduce;
	parser->lrTable[14][36].actionParam = 9;
	//reduce
	parser->lrTable[-2][36].LRTableFuncP = LRReduce;
	parser->lrTable[-2][36].actionParam = 9;
	//reduce
	parser->lrTable[21][36].LRTableFuncP = LRReduce;
	parser->lrTable[21][36].actionParam = 9;
	//shift
	parser->lrTable[9][37].LRTableFuncP = LRShift;
	parser->lrTable[9][37].actionParam = 29;
	//shift
	parser->lrTable[12][37].LRTableFuncP = LRShift;
	parser->lrTable[12][37].actionParam = 30;
	//shift
	parser->lrTable[20][37].LRTableFuncP = LRShift;
	parser->lrTable[20][37].actionParam = 31;
	//shift
	parser->lrTable[40][37].LRTableFuncP = LRShift;
	parser->lrTable[40][37].actionParam = 32;
	//shift
	parser->lrTable[27][37].LRTableFuncP = LRShift;
	parser->lrTable[27][37].actionParam = 33;
	//shift
	parser->lrTable[24][37].LRTableFuncP = LRShift;
	parser->lrTable[24][37].actionParam = 34;
	//goto
	parser->lrTable[Term+TOTAL_VALID_ACTIONS][37].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_VALID_ACTIONS][37].actionParam = 47;
	//goto
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][37].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][37].actionParam = 36;
	//shift
	parser->lrTable[9][38].LRTableFuncP = LRShift;
	parser->lrTable[9][38].actionParam = 29;
	//shift
	parser->lrTable[12][38].LRTableFuncP = LRShift;
	parser->lrTable[12][38].actionParam = 30;
	//shift
	parser->lrTable[20][38].LRTableFuncP = LRShift;
	parser->lrTable[20][38].actionParam = 31;
	//shift
	parser->lrTable[40][38].LRTableFuncP = LRShift;
	parser->lrTable[40][38].actionParam = 32;
	//shift
	parser->lrTable[27][38].LRTableFuncP = LRShift;
	parser->lrTable[27][38].actionParam = 33;
	//shift
	parser->lrTable[24][38].LRTableFuncP = LRShift;
	parser->lrTable[24][38].actionParam = 34;
	//goto
	parser->lrTable[Term+TOTAL_VALID_ACTIONS][38].LRTableFuncP = LRGoto;
	parser->lrTable[Term+TOTAL_VALID_ACTIONS][38].actionParam = 48;
	//goto
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][38].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][38].actionParam = 36;
	//reduce
	parser->lrTable[8][39].LRTableFuncP = LRReduce;
	parser->lrTable[8][39].actionParam = 17;
	//reduce
	parser->lrTable[11][39].LRTableFuncP = LRReduce;
	parser->lrTable[11][39].actionParam = 17;
	//reduce
	parser->lrTable[16][39].LRTableFuncP = LRReduce;
	parser->lrTable[16][39].actionParam = 17;
	//reduce
	parser->lrTable[14][39].LRTableFuncP = LRReduce;
	parser->lrTable[14][39].actionParam = 17;
	//reduce
	parser->lrTable[-2][39].LRTableFuncP = LRReduce;
	parser->lrTable[-2][39].actionParam = 17;
	//reduce
	parser->lrTable[21][39].LRTableFuncP = LRReduce;
	parser->lrTable[21][39].actionParam = 17;
	//reduce
	parser->lrTable[8][40].LRTableFuncP = LRReduce;
	parser->lrTable[8][40].actionParam = 16;
	//reduce
	parser->lrTable[11][40].LRTableFuncP = LRReduce;
	parser->lrTable[11][40].actionParam = 16;
	//reduce
	parser->lrTable[16][40].LRTableFuncP = LRReduce;
	parser->lrTable[16][40].actionParam = 16;
	//reduce
	parser->lrTable[14][40].LRTableFuncP = LRReduce;
	parser->lrTable[14][40].actionParam = 16;
	//reduce
	parser->lrTable[-2][40].LRTableFuncP = LRReduce;
	parser->lrTable[-2][40].actionParam = 16;
	//reduce
	parser->lrTable[21][40].LRTableFuncP = LRReduce;
	parser->lrTable[21][40].actionParam = 16;
	//shift
	parser->lrTable[8][41].LRTableFuncP = LRShift;
	parser->lrTable[8][41].actionParam = 37;
	//shift
	parser->lrTable[11][41].LRTableFuncP = LRShift;
	parser->lrTable[11][41].actionParam = 38;
	//shift
	parser->lrTable[21][41].LRTableFuncP = LRShift;
	parser->lrTable[21][41].actionParam = 49;
	//reduce
	parser->lrTable[8][42].LRTableFuncP = LRReduce;
	parser->lrTable[8][42].actionParam = 14;
	//reduce
	parser->lrTable[11][42].LRTableFuncP = LRReduce;
	parser->lrTable[11][42].actionParam = 14;
	//reduce
	parser->lrTable[16][42].LRTableFuncP = LRReduce;
	parser->lrTable[16][42].actionParam = 14;
	//reduce
	parser->lrTable[14][42].LRTableFuncP = LRReduce;
	parser->lrTable[14][42].actionParam = 14;
	//reduce
	parser->lrTable[-2][42].LRTableFuncP = LRReduce;
	parser->lrTable[-2][42].actionParam = 14;
	//reduce
	parser->lrTable[21][42].LRTableFuncP = LRReduce;
	parser->lrTable[21][42].actionParam = 14;
	//reduce
	parser->lrTable[8][43].LRTableFuncP = LRReduce;
	parser->lrTable[8][43].actionParam = 15;
	//reduce
	parser->lrTable[11][43].LRTableFuncP = LRReduce;
	parser->lrTable[11][43].actionParam = 15;
	//reduce
	parser->lrTable[16][43].LRTableFuncP = LRReduce;
	parser->lrTable[16][43].actionParam = 15;
	//reduce
	parser->lrTable[14][43].LRTableFuncP = LRReduce;
	parser->lrTable[14][43].actionParam = 15;
	//reduce
	parser->lrTable[-2][43].LRTableFuncP = LRReduce;
	parser->lrTable[-2][43].actionParam = 15;
	//reduce
	parser->lrTable[21][43].LRTableFuncP = LRReduce;
	parser->lrTable[21][43].actionParam = 15;
	//shift
	parser->lrTable[9][44].LRTableFuncP = LRShift;
	parser->lrTable[9][44].actionParam = 29;
	//shift
	parser->lrTable[12][44].LRTableFuncP = LRShift;
	parser->lrTable[12][44].actionParam = 30;
	//shift
	parser->lrTable[20][44].LRTableFuncP = LRShift;
	parser->lrTable[20][44].actionParam = 31;
	//shift
	parser->lrTable[40][44].LRTableFuncP = LRShift;
	parser->lrTable[40][44].actionParam = 32;
	//shift
	parser->lrTable[27][44].LRTableFuncP = LRShift;
	parser->lrTable[27][44].actionParam = 33;
	//shift
	parser->lrTable[24][44].LRTableFuncP = LRShift;
	parser->lrTable[24][44].actionParam = 34;
	//goto
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][44].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][44].actionParam = 50;
	//shift
	parser->lrTable[9][45].LRTableFuncP = LRShift;
	parser->lrTable[9][45].actionParam = 29;
	//shift
	parser->lrTable[12][45].LRTableFuncP = LRShift;
	parser->lrTable[12][45].actionParam = 30;
	//shift
	parser->lrTable[20][45].LRTableFuncP = LRShift;
	parser->lrTable[20][45].actionParam = 31;
	//shift
	parser->lrTable[40][45].LRTableFuncP = LRShift;
	parser->lrTable[40][45].actionParam = 32;
	//shift
	parser->lrTable[27][45].LRTableFuncP = LRShift;
	parser->lrTable[27][45].actionParam = 33;
	//shift
	parser->lrTable[24][45].LRTableFuncP = LRShift;
	parser->lrTable[24][45].actionParam = 34;
	//goto
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][45].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][45].actionParam = 51;
	//shift
	parser->lrTable[9][46].LRTableFuncP = LRShift;
	parser->lrTable[9][46].actionParam = 29;
	//shift
	parser->lrTable[12][46].LRTableFuncP = LRShift;
	parser->lrTable[12][46].actionParam = 30;
	//shift
	parser->lrTable[20][46].LRTableFuncP = LRShift;
	parser->lrTable[20][46].actionParam = 31;
	//shift
	parser->lrTable[40][46].LRTableFuncP = LRShift;
	parser->lrTable[40][46].actionParam = 32;
	//shift
	parser->lrTable[27][46].LRTableFuncP = LRShift;
	parser->lrTable[27][46].actionParam = 33;
	//shift
	parser->lrTable[24][46].LRTableFuncP = LRShift;
	parser->lrTable[24][46].actionParam = 34;
	//goto
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][46].LRTableFuncP = LRGoto;
	parser->lrTable[Factor+TOTAL_VALID_ACTIONS][46].actionParam = 52;
	//shift
	parser->lrTable[16][47].LRTableFuncP = LRShift;
	parser->lrTable[16][47].actionParam = 44;
	//shift
	parser->lrTable[14][47].LRTableFuncP = LRShift;
	parser->lrTable[14][47].actionParam = 45;
	//shift
	parser->lrTable[-2][47].LRTableFuncP = LRShift;
	parser->lrTable[-2][47].actionParam = 46;
	//reduce
	parser->lrTable[8][47].LRTableFuncP = LRReduce;
	parser->lrTable[8][47].actionParam = 3;
	//reduce
	parser->lrTable[11][47].LRTableFuncP = LRReduce;
	parser->lrTable[11][47].actionParam = 3;
	//reduce
	parser->lrTable[21][47].LRTableFuncP = LRReduce;
	parser->lrTable[21][47].actionParam = 3;
	//shift
	parser->lrTable[16][48].LRTableFuncP = LRShift;
	parser->lrTable[16][48].actionParam = 44;
	//shift
	parser->lrTable[14][48].LRTableFuncP = LRShift;
	parser->lrTable[14][48].actionParam = 45;
	//shift
	parser->lrTable[-2][48].LRTableFuncP = LRShift;
	parser->lrTable[-2][48].actionParam = 46;
	//reduce
	parser->lrTable[8][48].LRTableFuncP = LRReduce;
	parser->lrTable[8][48].actionParam = 4;
	//reduce
	parser->lrTable[11][48].LRTableFuncP = LRReduce;
	parser->lrTable[11][48].actionParam = 4;
	//reduce
	parser->lrTable[21][48].LRTableFuncP = LRReduce;
	parser->lrTable[21][48].actionParam = 4;
	//reduce
	parser->lrTable[8][49].LRTableFuncP = LRReduce;
	parser->lrTable[8][49].actionParam = 10;
	//reduce
	parser->lrTable[11][49].LRTableFuncP = LRReduce;
	parser->lrTable[11][49].actionParam = 10;
	//reduce
	parser->lrTable[16][49].LRTableFuncP = LRReduce;
	parser->lrTable[16][49].actionParam = 10;
	//reduce
	parser->lrTable[14][49].LRTableFuncP = LRReduce;
	parser->lrTable[14][49].actionParam = 10;
	//reduce
	parser->lrTable[-2][49].LRTableFuncP = LRReduce;
	parser->lrTable[-2][49].actionParam = 10;
	//reduce
	parser->lrTable[21][49].LRTableFuncP = LRReduce;
	parser->lrTable[21][49].actionParam = 10;
	//reduce
	parser->lrTable[8][50].LRTableFuncP = LRReduce;
	parser->lrTable[8][50].actionParam = 6;
	//reduce
	parser->lrTable[11][50].LRTableFuncP = LRReduce;
	parser->lrTable[11][50].actionParam = 6;
	//reduce
	parser->lrTable[16][50].LRTableFuncP = LRReduce;
	parser->lrTable[16][50].actionParam = 6;
	//reduce
	parser->lrTable[14][50].LRTableFuncP = LRReduce;
	parser->lrTable[14][50].actionParam = 6;
	//reduce
	parser->lrTable[-2][50].LRTableFuncP = LRReduce;
	parser->lrTable[-2][50].actionParam = 6;
	//reduce
	parser->lrTable[21][50].LRTableFuncP = LRReduce;
	parser->lrTable[21][50].actionParam = 6;
	//reduce
	parser->lrTable[8][51].LRTableFuncP = LRReduce;
	parser->lrTable[8][51].actionParam = 7;
	//reduce
	parser->lrTable[11][51].LRTableFuncP = LRReduce;
	parser->lrTable[11][51].actionParam = 7;
	//reduce
	parser->lrTable[16][51].LRTableFuncP = LRReduce;
	parser->lrTable[16][51].actionParam = 7;
	//reduce
	parser->lrTable[14][51].LRTableFuncP = LRReduce;
	parser->lrTable[14][51].actionParam = 7;
	//reduce
	parser->lrTable[-2][51].LRTableFuncP = LRReduce;
	parser->lrTable[-2][51].actionParam = 7;
	//reduce
	parser->lrTable[21][51].LRTableFuncP = LRReduce;
	parser->lrTable[21][51].actionParam = 7;
	//reduce
	parser->lrTable[8][52].LRTableFuncP = LRReduce;
	parser->lrTable[8][52].actionParam = 8;
	//reduce
	parser->lrTable[11][52].LRTableFuncP = LRReduce;
	parser->lrTable[11][52].actionParam = 8;
	//reduce
	parser->lrTable[16][52].LRTableFuncP = LRReduce;
	parser->lrTable[16][52].actionParam = 8;
	//reduce
	parser->lrTable[14][52].LRTableFuncP = LRReduce;
	parser->lrTable[14][52].actionParam = 8;
	//reduce
	parser->lrTable[-2][52].LRTableFuncP = LRReduce;
	parser->lrTable[-2][52].actionParam = 8;
	//reduce
	parser->lrTable[21][52].LRTableFuncP = LRReduce;
	parser->lrTable[21][52].actionParam = 8;









    printf("Parser Initialized Succesfully! XD\n");
    return parser;
}

void generateTree(Parser* parser){
	printf("\n\n\n");
	StackValue val1;
	int val2;
	while (parser->tokenId < parser->lexer->token_capacity){
		printParsingStep(parser);
		val1 = getStackValue(parser->stack);
		if (val1.dataType == GRAMMER_SYMBOL_DATA_TYPE){
			LRGoto(parser, -1);
		}else if (val1.dataType == TOKEN_DATA_TYPE){
			LRGoto(parser, -1);
		}else{
			val2 = parser->lexer->tokens[parser->tokenId].type;
			parser->lrTable[val2][val1.data.intValue].LRTableFuncP(parser, parser->lrTable[val2][val1.data.intValue].actionParam);
		}
	}
}