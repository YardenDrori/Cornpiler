#include "stack.h"
#include "token.h"
#include "parser.h"
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
    parser->lexer = initLexer(FILENAME);
    parser->stack = initStack();
    pushInt(parser->stack, 0); 





	
	int rows = 0;
	for (int i = 0; i < TOTAL_ACTIONS+GRAMMER_SYMBOL_COUNT; i++){
		for (int j = 0; j < TOTAL_STATES; j++){
			parser->lrTable[i][j].LRTableFuncP = LRError;
			parser->lrTable[i][j].actionParam = -1;
		}
	}
	parser->lrTable[3][0].LRTableFuncP = LRShift;
	parser->lrTable[3][0].actionParam = 1;
	parser->lrTable[4][0].LRTableFuncP = LRShift;
	parser->lrTable[4][0].actionParam = 2;
	parser->lrTable[5][0].LRTableFuncP = LRShift;
	parser->lrTable[5][0].actionParam = 3;
	parser->lrTable[6][0].LRTableFuncP = LRShift;
	parser->lrTable[6][0].actionParam = 4;
	parser->lrTable[1][0].LRTableFuncP = LRShift;
	parser->lrTable[1][0].actionParam = 5;
	parser->lrTable[12][0].LRTableFuncP = LRGoto;
	parser->lrTable[12][0].actionParam = 6;
	parser->lrTable[13][0].LRTableFuncP = LRGoto;
	parser->lrTable[13][0].actionParam = 7;
	parser->lrTable[14][0].LRTableFuncP = LRGoto;
	parser->lrTable[14][0].actionParam = 8;
	parser->lrTable[15][0].LRTableFuncP = LRGoto;
	parser->lrTable[15][0].actionParam = 9;
	parser->lrTable[16][0].LRTableFuncP = LRGoto;
	parser->lrTable[16][0].actionParam = 10;
	parser->lrTable[5][1].LRTableFuncP = LRShift;
	parser->lrTable[5][1].actionParam = 11;
	parser->lrTable[6][1].LRTableFuncP = LRShift;
	parser->lrTable[6][1].actionParam = 12;
	parser->lrTable[8][1].LRTableFuncP = LRReduce;
	parser->lrTable[8][1].actionParam = 10;
	parser->lrTable[9][1].LRTableFuncP = LRReduce;
	parser->lrTable[9][1].actionParam = 10;
	parser->lrTable[10][1].LRTableFuncP = LRReduce;
	parser->lrTable[10][1].actionParam = 10;
	parser->lrTable[11][1].LRTableFuncP = LRReduce;
	parser->lrTable[11][1].actionParam = 10;
	parser->lrTable[8][2].LRTableFuncP = LRReduce;
	parser->lrTable[8][2].actionParam = 11;
	parser->lrTable[9][2].LRTableFuncP = LRReduce;
	parser->lrTable[9][2].actionParam = 11;
	parser->lrTable[10][2].LRTableFuncP = LRReduce;
	parser->lrTable[10][2].actionParam = 11;
	parser->lrTable[11][2].LRTableFuncP = LRReduce;
	parser->lrTable[11][2].actionParam = 11;
	parser->lrTable[3][3].LRTableFuncP = LRShift;
	parser->lrTable[3][3].actionParam = 13;
	parser->lrTable[3][4].LRTableFuncP = LRShift;
	parser->lrTable[3][4].actionParam = 14;
	parser->lrTable[3][5].LRTableFuncP = LRShift;
	parser->lrTable[3][5].actionParam = 26;
	parser->lrTable[4][5].LRTableFuncP = LRShift;
	parser->lrTable[4][5].actionParam = 27;
	parser->lrTable[5][5].LRTableFuncP = LRShift;
	parser->lrTable[5][5].actionParam = 28;
	parser->lrTable[6][5].LRTableFuncP = LRShift;
	parser->lrTable[6][5].actionParam = 29;
	parser->lrTable[1][5].LRTableFuncP = LRShift;
	parser->lrTable[1][5].actionParam = 30;
	parser->lrTable[14][5].LRTableFuncP = LRGoto;
	parser->lrTable[14][5].actionParam = 15;
	parser->lrTable[15][5].LRTableFuncP = LRGoto;
	parser->lrTable[15][5].actionParam = 31;
	parser->lrTable[16][5].LRTableFuncP = LRGoto;
	parser->lrTable[16][5].actionParam = 32;
	parser->lrTable[8][8].LRTableFuncP = LRShift;
	parser->lrTable[8][8].actionParam = 17;
	parser->lrTable[9][8].LRTableFuncP = LRShift;
	parser->lrTable[9][8].actionParam = 18;
	parser->lrTable[10][9].LRTableFuncP = LRShift;
	parser->lrTable[10][9].actionParam = 19;
	parser->lrTable[11][9].LRTableFuncP = LRShift;
	parser->lrTable[11][9].actionParam = 20;
	parser->lrTable[8][9].LRTableFuncP = LRReduce;
	parser->lrTable[8][9].actionParam = 5;
	parser->lrTable[9][9].LRTableFuncP = LRReduce;
	parser->lrTable[9][9].actionParam = 5;
	parser->lrTable[8][10].LRTableFuncP = LRReduce;
	parser->lrTable[8][10].actionParam = 8;
	parser->lrTable[9][10].LRTableFuncP = LRReduce;
	parser->lrTable[9][10].actionParam = 8;
	parser->lrTable[10][10].LRTableFuncP = LRReduce;
	parser->lrTable[10][10].actionParam = 8;
	parser->lrTable[11][10].LRTableFuncP = LRReduce;
	parser->lrTable[11][10].actionParam = 8;
	parser->lrTable[8][11].LRTableFuncP = LRReduce;
	parser->lrTable[8][11].actionParam = 12;
	parser->lrTable[9][11].LRTableFuncP = LRReduce;
	parser->lrTable[9][11].actionParam = 12;
	parser->lrTable[10][11].LRTableFuncP = LRReduce;
	parser->lrTable[10][11].actionParam = 12;
	parser->lrTable[11][11].LRTableFuncP = LRReduce;
	parser->lrTable[11][11].actionParam = 12;
	parser->lrTable[8][12].LRTableFuncP = LRReduce;
	parser->lrTable[8][12].actionParam = 13;
	parser->lrTable[9][12].LRTableFuncP = LRReduce;
	parser->lrTable[9][12].actionParam = 13;
	parser->lrTable[10][12].LRTableFuncP = LRReduce;
	parser->lrTable[10][12].actionParam = 13;
	parser->lrTable[11][12].LRTableFuncP = LRReduce;
	parser->lrTable[11][12].actionParam = 13;
	parser->lrTable[8][13].LRTableFuncP = LRReduce;
	parser->lrTable[8][13].actionParam = 15;
	parser->lrTable[9][13].LRTableFuncP = LRReduce;
	parser->lrTable[9][13].actionParam = 15;
	parser->lrTable[10][13].LRTableFuncP = LRReduce;
	parser->lrTable[10][13].actionParam = 15;
	parser->lrTable[11][13].LRTableFuncP = LRReduce;
	parser->lrTable[11][13].actionParam = 15;
	parser->lrTable[8][14].LRTableFuncP = LRReduce;
	parser->lrTable[8][14].actionParam = 14;
	parser->lrTable[9][14].LRTableFuncP = LRReduce;
	parser->lrTable[9][14].actionParam = 14;
	parser->lrTable[10][14].LRTableFuncP = LRReduce;
	parser->lrTable[10][14].actionParam = 14;
	parser->lrTable[11][14].LRTableFuncP = LRReduce;
	parser->lrTable[11][14].actionParam = 14;
	parser->lrTable[8][15].LRTableFuncP = LRShift;
	parser->lrTable[8][15].actionParam = 33;
	parser->lrTable[9][15].LRTableFuncP = LRShift;
	parser->lrTable[9][15].actionParam = 34;
	parser->lrTable[2][15].LRTableFuncP = LRShift;
	parser->lrTable[2][15].actionParam = 21;
	parser->lrTable[3][17].LRTableFuncP = LRShift;
	parser->lrTable[3][17].actionParam = 1;
	parser->lrTable[4][17].LRTableFuncP = LRShift;
	parser->lrTable[4][17].actionParam = 2;
	parser->lrTable[5][17].LRTableFuncP = LRShift;
	parser->lrTable[5][17].actionParam = 3;
	parser->lrTable[6][17].LRTableFuncP = LRShift;
	parser->lrTable[6][17].actionParam = 4;
	parser->lrTable[1][17].LRTableFuncP = LRShift;
	parser->lrTable[1][17].actionParam = 5;
	parser->lrTable[15][17].LRTableFuncP = LRGoto;
	parser->lrTable[15][17].actionParam = 22;
	parser->lrTable[16][17].LRTableFuncP = LRGoto;
	parser->lrTable[16][17].actionParam = 10;
	parser->lrTable[3][18].LRTableFuncP = LRShift;
	parser->lrTable[3][18].actionParam = 1;
	parser->lrTable[4][18].LRTableFuncP = LRShift;
	parser->lrTable[4][18].actionParam = 2;
	parser->lrTable[5][18].LRTableFuncP = LRShift;
	parser->lrTable[5][18].actionParam = 3;
	parser->lrTable[6][18].LRTableFuncP = LRShift;
	parser->lrTable[6][18].actionParam = 4;
	parser->lrTable[1][18].LRTableFuncP = LRShift;
	parser->lrTable[1][18].actionParam = 5;
	parser->lrTable[15][18].LRTableFuncP = LRGoto;
	parser->lrTable[15][18].actionParam = 23;
	parser->lrTable[16][18].LRTableFuncP = LRGoto;
	parser->lrTable[16][18].actionParam = 10;
	parser->lrTable[3][19].LRTableFuncP = LRShift;
	parser->lrTable[3][19].actionParam = 1;
	parser->lrTable[4][19].LRTableFuncP = LRShift;
	parser->lrTable[4][19].actionParam = 2;
	parser->lrTable[5][19].LRTableFuncP = LRShift;
	parser->lrTable[5][19].actionParam = 3;
	parser->lrTable[6][19].LRTableFuncP = LRShift;
	parser->lrTable[6][19].actionParam = 4;
	parser->lrTable[1][19].LRTableFuncP = LRShift;
	parser->lrTable[1][19].actionParam = 5;
	parser->lrTable[16][19].LRTableFuncP = LRGoto;
	parser->lrTable[16][19].actionParam = 24;
	parser->lrTable[3][20].LRTableFuncP = LRShift;
	parser->lrTable[3][20].actionParam = 1;
	parser->lrTable[4][20].LRTableFuncP = LRShift;
	parser->lrTable[4][20].actionParam = 2;
	parser->lrTable[5][20].LRTableFuncP = LRShift;
	parser->lrTable[5][20].actionParam = 3;
	parser->lrTable[6][20].LRTableFuncP = LRShift;
	parser->lrTable[6][20].actionParam = 4;
	parser->lrTable[1][20].LRTableFuncP = LRShift;
	parser->lrTable[1][20].actionParam = 5;
	parser->lrTable[16][20].LRTableFuncP = LRGoto;
	parser->lrTable[16][20].actionParam = 25;
	parser->lrTable[8][21].LRTableFuncP = LRReduce;
	parser->lrTable[8][21].actionParam = 9;
	parser->lrTable[9][21].LRTableFuncP = LRReduce;
	parser->lrTable[9][21].actionParam = 9;
	parser->lrTable[10][21].LRTableFuncP = LRReduce;
	parser->lrTable[10][21].actionParam = 9;
	parser->lrTable[11][21].LRTableFuncP = LRReduce;
	parser->lrTable[11][21].actionParam = 9;
	parser->lrTable[10][22].LRTableFuncP = LRShift;
	parser->lrTable[10][22].actionParam = 19;
	parser->lrTable[11][22].LRTableFuncP = LRShift;
	parser->lrTable[11][22].actionParam = 20;
	parser->lrTable[8][22].LRTableFuncP = LRReduce;
	parser->lrTable[8][22].actionParam = 3;
	parser->lrTable[9][22].LRTableFuncP = LRReduce;
	parser->lrTable[9][22].actionParam = 3;
	parser->lrTable[10][23].LRTableFuncP = LRShift;
	parser->lrTable[10][23].actionParam = 19;
	parser->lrTable[11][23].LRTableFuncP = LRShift;
	parser->lrTable[11][23].actionParam = 20;
	parser->lrTable[8][23].LRTableFuncP = LRReduce;
	parser->lrTable[8][23].actionParam = 4;
	parser->lrTable[9][23].LRTableFuncP = LRReduce;
	parser->lrTable[9][23].actionParam = 4;
	parser->lrTable[8][24].LRTableFuncP = LRReduce;
	parser->lrTable[8][24].actionParam = 6;
	parser->lrTable[9][24].LRTableFuncP = LRReduce;
	parser->lrTable[9][24].actionParam = 6;
	parser->lrTable[10][24].LRTableFuncP = LRReduce;
	parser->lrTable[10][24].actionParam = 6;
	parser->lrTable[11][24].LRTableFuncP = LRReduce;
	parser->lrTable[11][24].actionParam = 6;
	parser->lrTable[8][25].LRTableFuncP = LRReduce;
	parser->lrTable[8][25].actionParam = 7;
	parser->lrTable[9][25].LRTableFuncP = LRReduce;
	parser->lrTable[9][25].actionParam = 7;
	parser->lrTable[10][25].LRTableFuncP = LRReduce;
	parser->lrTable[10][25].actionParam = 7;
	parser->lrTable[11][25].LRTableFuncP = LRReduce;
	parser->lrTable[11][25].actionParam = 7;
	parser->lrTable[5][26].LRTableFuncP = LRShift;
	parser->lrTable[5][26].actionParam = 35;
	parser->lrTable[6][26].LRTableFuncP = LRShift;
	parser->lrTable[6][26].actionParam = 36;
	parser->lrTable[8][26].LRTableFuncP = LRReduce;
	parser->lrTable[8][26].actionParam = 10;
	parser->lrTable[9][26].LRTableFuncP = LRReduce;
	parser->lrTable[9][26].actionParam = 10;
	parser->lrTable[10][26].LRTableFuncP = LRReduce;
	parser->lrTable[10][26].actionParam = 10;
	parser->lrTable[11][26].LRTableFuncP = LRReduce;
	parser->lrTable[11][26].actionParam = 10;
	parser->lrTable[2][26].LRTableFuncP = LRReduce;
	parser->lrTable[2][26].actionParam = 10;
	parser->lrTable[8][27].LRTableFuncP = LRReduce;
	parser->lrTable[8][27].actionParam = 11;
	parser->lrTable[9][27].LRTableFuncP = LRReduce;
	parser->lrTable[9][27].actionParam = 11;
	parser->lrTable[10][27].LRTableFuncP = LRReduce;
	parser->lrTable[10][27].actionParam = 11;
	parser->lrTable[11][27].LRTableFuncP = LRReduce;
	parser->lrTable[11][27].actionParam = 11;
	parser->lrTable[2][27].LRTableFuncP = LRReduce;
	parser->lrTable[2][27].actionParam = 11;
	parser->lrTable[3][28].LRTableFuncP = LRShift;
	parser->lrTable[3][28].actionParam = 37;
	parser->lrTable[3][29].LRTableFuncP = LRShift;
	parser->lrTable[3][29].actionParam = 38;
	parser->lrTable[3][30].LRTableFuncP = LRShift;
	parser->lrTable[3][30].actionParam = 26;
	parser->lrTable[4][30].LRTableFuncP = LRShift;
	parser->lrTable[4][30].actionParam = 27;
	parser->lrTable[5][30].LRTableFuncP = LRShift;
	parser->lrTable[5][30].actionParam = 28;
	parser->lrTable[6][30].LRTableFuncP = LRShift;
	parser->lrTable[6][30].actionParam = 29;
	parser->lrTable[1][30].LRTableFuncP = LRShift;
	parser->lrTable[1][30].actionParam = 30;
	parser->lrTable[14][30].LRTableFuncP = LRGoto;
	parser->lrTable[14][30].actionParam = 39;
	parser->lrTable[15][30].LRTableFuncP = LRGoto;
	parser->lrTable[15][30].actionParam = 31;
	parser->lrTable[16][30].LRTableFuncP = LRGoto;
	parser->lrTable[16][30].actionParam = 32;
	parser->lrTable[10][31].LRTableFuncP = LRShift;
	parser->lrTable[10][31].actionParam = 40;
	parser->lrTable[11][31].LRTableFuncP = LRShift;
	parser->lrTable[11][31].actionParam = 41;
	parser->lrTable[8][31].LRTableFuncP = LRReduce;
	parser->lrTable[8][31].actionParam = 5;
	parser->lrTable[9][31].LRTableFuncP = LRReduce;
	parser->lrTable[9][31].actionParam = 5;
	parser->lrTable[2][31].LRTableFuncP = LRReduce;
	parser->lrTable[2][31].actionParam = 5;
	parser->lrTable[8][32].LRTableFuncP = LRReduce;
	parser->lrTable[8][32].actionParam = 8;
	parser->lrTable[9][32].LRTableFuncP = LRReduce;
	parser->lrTable[9][32].actionParam = 8;
	parser->lrTable[10][32].LRTableFuncP = LRReduce;
	parser->lrTable[10][32].actionParam = 8;
	parser->lrTable[11][32].LRTableFuncP = LRReduce;
	parser->lrTable[11][32].actionParam = 8;
	parser->lrTable[2][32].LRTableFuncP = LRReduce;
	parser->lrTable[2][32].actionParam = 8;
	parser->lrTable[3][33].LRTableFuncP = LRShift;
	parser->lrTable[3][33].actionParam = 26;
	parser->lrTable[4][33].LRTableFuncP = LRShift;
	parser->lrTable[4][33].actionParam = 27;
	parser->lrTable[5][33].LRTableFuncP = LRShift;
	parser->lrTable[5][33].actionParam = 28;
	parser->lrTable[6][33].LRTableFuncP = LRShift;
	parser->lrTable[6][33].actionParam = 29;
	parser->lrTable[1][33].LRTableFuncP = LRShift;
	parser->lrTable[1][33].actionParam = 30;
	parser->lrTable[15][33].LRTableFuncP = LRGoto;
	parser->lrTable[15][33].actionParam = 42;
	parser->lrTable[16][33].LRTableFuncP = LRGoto;
	parser->lrTable[16][33].actionParam = 32;
	parser->lrTable[3][34].LRTableFuncP = LRShift;
	parser->lrTable[3][34].actionParam = 26;
	parser->lrTable[4][34].LRTableFuncP = LRShift;
	parser->lrTable[4][34].actionParam = 27;
	parser->lrTable[5][34].LRTableFuncP = LRShift;
	parser->lrTable[5][34].actionParam = 28;
	parser->lrTable[6][34].LRTableFuncP = LRShift;
	parser->lrTable[6][34].actionParam = 29;
	parser->lrTable[1][34].LRTableFuncP = LRShift;
	parser->lrTable[1][34].actionParam = 30;
	parser->lrTable[15][34].LRTableFuncP = LRGoto;
	parser->lrTable[15][34].actionParam = 43;
	parser->lrTable[16][34].LRTableFuncP = LRGoto;
	parser->lrTable[16][34].actionParam = 32;
	parser->lrTable[8][35].LRTableFuncP = LRReduce;
	parser->lrTable[8][35].actionParam = 12;
	parser->lrTable[9][35].LRTableFuncP = LRReduce;
	parser->lrTable[9][35].actionParam = 12;
	parser->lrTable[10][35].LRTableFuncP = LRReduce;
	parser->lrTable[10][35].actionParam = 12;
	parser->lrTable[11][35].LRTableFuncP = LRReduce;
	parser->lrTable[11][35].actionParam = 12;
	parser->lrTable[2][35].LRTableFuncP = LRReduce;
	parser->lrTable[2][35].actionParam = 12;
	parser->lrTable[8][36].LRTableFuncP = LRReduce;
	parser->lrTable[8][36].actionParam = 13;
	parser->lrTable[9][36].LRTableFuncP = LRReduce;
	parser->lrTable[9][36].actionParam = 13;
	parser->lrTable[10][36].LRTableFuncP = LRReduce;
	parser->lrTable[10][36].actionParam = 13;
	parser->lrTable[11][36].LRTableFuncP = LRReduce;
	parser->lrTable[11][36].actionParam = 13;
	parser->lrTable[2][36].LRTableFuncP = LRReduce;
	parser->lrTable[2][36].actionParam = 13;
	parser->lrTable[8][37].LRTableFuncP = LRReduce;
	parser->lrTable[8][37].actionParam = 15;
	parser->lrTable[9][37].LRTableFuncP = LRReduce;
	parser->lrTable[9][37].actionParam = 15;
	parser->lrTable[10][37].LRTableFuncP = LRReduce;
	parser->lrTable[10][37].actionParam = 15;
	parser->lrTable[11][37].LRTableFuncP = LRReduce;
	parser->lrTable[11][37].actionParam = 15;
	parser->lrTable[2][37].LRTableFuncP = LRReduce;
	parser->lrTable[2][37].actionParam = 15;
	parser->lrTable[8][38].LRTableFuncP = LRReduce;
	parser->lrTable[8][38].actionParam = 14;
	parser->lrTable[9][38].LRTableFuncP = LRReduce;
	parser->lrTable[9][38].actionParam = 14;
	parser->lrTable[10][38].LRTableFuncP = LRReduce;
	parser->lrTable[10][38].actionParam = 14;
	parser->lrTable[11][38].LRTableFuncP = LRReduce;
	parser->lrTable[11][38].actionParam = 14;
	parser->lrTable[2][38].LRTableFuncP = LRReduce;
	parser->lrTable[2][38].actionParam = 14;
	parser->lrTable[8][39].LRTableFuncP = LRShift;
	parser->lrTable[8][39].actionParam = 33;
	parser->lrTable[9][39].LRTableFuncP = LRShift;
	parser->lrTable[9][39].actionParam = 34;
	parser->lrTable[2][39].LRTableFuncP = LRShift;
	parser->lrTable[2][39].actionParam = 44;
	parser->lrTable[3][40].LRTableFuncP = LRShift;
	parser->lrTable[3][40].actionParam = 26;
	parser->lrTable[4][40].LRTableFuncP = LRShift;
	parser->lrTable[4][40].actionParam = 27;
	parser->lrTable[5][40].LRTableFuncP = LRShift;
	parser->lrTable[5][40].actionParam = 28;
	parser->lrTable[6][40].LRTableFuncP = LRShift;
	parser->lrTable[6][40].actionParam = 29;
	parser->lrTable[1][40].LRTableFuncP = LRShift;
	parser->lrTable[1][40].actionParam = 30;
	parser->lrTable[16][40].LRTableFuncP = LRGoto;
	parser->lrTable[16][40].actionParam = 45;
	parser->lrTable[3][41].LRTableFuncP = LRShift;
	parser->lrTable[3][41].actionParam = 26;
	parser->lrTable[4][41].LRTableFuncP = LRShift;
	parser->lrTable[4][41].actionParam = 27;
	parser->lrTable[5][41].LRTableFuncP = LRShift;
	parser->lrTable[5][41].actionParam = 28;
	parser->lrTable[6][41].LRTableFuncP = LRShift;
	parser->lrTable[6][41].actionParam = 29;
	parser->lrTable[1][41].LRTableFuncP = LRShift;
	parser->lrTable[1][41].actionParam = 30;
	parser->lrTable[16][41].LRTableFuncP = LRGoto;
	parser->lrTable[16][41].actionParam = 46;
	parser->lrTable[10][42].LRTableFuncP = LRShift;
	parser->lrTable[10][42].actionParam = 40;
	parser->lrTable[11][42].LRTableFuncP = LRShift;
	parser->lrTable[11][42].actionParam = 41;
	parser->lrTable[8][42].LRTableFuncP = LRReduce;
	parser->lrTable[8][42].actionParam = 3;
	parser->lrTable[9][42].LRTableFuncP = LRReduce;
	parser->lrTable[9][42].actionParam = 3;
	parser->lrTable[2][42].LRTableFuncP = LRReduce;
	parser->lrTable[2][42].actionParam = 3;
	parser->lrTable[10][43].LRTableFuncP = LRShift;
	parser->lrTable[10][43].actionParam = 40;
	parser->lrTable[11][43].LRTableFuncP = LRShift;
	parser->lrTable[11][43].actionParam = 41;
	parser->lrTable[8][43].LRTableFuncP = LRReduce;
	parser->lrTable[8][43].actionParam = 4;
	parser->lrTable[9][43].LRTableFuncP = LRReduce;
	parser->lrTable[9][43].actionParam = 4;
	parser->lrTable[2][43].LRTableFuncP = LRReduce;
	parser->lrTable[2][43].actionParam = 4;
	parser->lrTable[8][44].LRTableFuncP = LRReduce;
	parser->lrTable[8][44].actionParam = 9;
	parser->lrTable[9][44].LRTableFuncP = LRReduce;
	parser->lrTable[9][44].actionParam = 9;
	parser->lrTable[10][44].LRTableFuncP = LRReduce;
	parser->lrTable[10][44].actionParam = 9;
	parser->lrTable[11][44].LRTableFuncP = LRReduce;
	parser->lrTable[11][44].actionParam = 9;
	parser->lrTable[2][44].LRTableFuncP = LRReduce;
	parser->lrTable[2][44].actionParam = 9;
	parser->lrTable[8][45].LRTableFuncP = LRReduce;
	parser->lrTable[8][45].actionParam = 6;
	parser->lrTable[9][45].LRTableFuncP = LRReduce;
	parser->lrTable[9][45].actionParam = 6;
	parser->lrTable[10][45].LRTableFuncP = LRReduce;
	parser->lrTable[10][45].actionParam = 6;
	parser->lrTable[11][45].LRTableFuncP = LRReduce;
	parser->lrTable[11][45].actionParam = 6;
	parser->lrTable[2][45].LRTableFuncP = LRReduce;
	parser->lrTable[2][45].actionParam = 6;
	parser->lrTable[8][46].LRTableFuncP = LRReduce;
	parser->lrTable[8][46].actionParam = 7;
	parser->lrTable[9][46].LRTableFuncP = LRReduce;
	parser->lrTable[9][46].actionParam = 7;
	parser->lrTable[10][46].LRTableFuncP = LRReduce;
	parser->lrTable[10][46].actionParam = 7;
	parser->lrTable[11][46].LRTableFuncP = LRReduce;
	parser->lrTable[11][46].actionParam = 7;
	parser->lrTable[2][46].LRTableFuncP = LRReduce;
	parser->lrTable[2][46].actionParam = 7;






	


	if (PRINT_MATRIX){
		char funcP;
		int r;
		int c;
		for(r=0;r<GRAMMER_SYMBOL_COUNT+TOTAL_ACTIONS;r++){
			for(c=0;c<TOTAL_STATES;c++){
				if (parser->lrTable[r][c].LRTableFuncP == LRAccept){
					funcP = 'A';
				}else if (parser->lrTable[r][c].LRTableFuncP == LRError){
					funcP = 'E';
				}else if (parser->lrTable[r][c].LRTableFuncP == LRGoto){
					funcP = 'G';
				}else if (parser->lrTable[r][c].LRTableFuncP == LRReduce){
					funcP = 'R';
				}else if (parser->lrTable[r][c].LRTableFuncP == LRShift){
					funcP = 'S';
				}else{
					printf("Woopsy Daisy1");
				}
				printf("{%c %d} ",funcP,parser->lrTable[r][c].actionParam);
			}
			printf("\n");
		}
    }

    
















    printf("Parser Initialized Succesfully!\n");
    
    return parser;
}

