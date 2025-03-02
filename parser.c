#include "stack.h"
#include "token.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#define PRINT_MATRIX 1
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
	parser->lrTable[rows][3].LRTableFuncP = LRShift;
	parser->lrTable[rows][3].actionParam = 1;
	parser->lrTable[rows][4].LRTableFuncP = LRShift;
	parser->lrTable[rows][4].actionParam = 2;
	parser->lrTable[rows][5].LRTableFuncP = LRShift;
	parser->lrTable[rows][5].actionParam = 3;
	parser->lrTable[rows][6].LRTableFuncP = LRShift;
	parser->lrTable[rows][6].actionParam = 4;
	parser->lrTable[rows][1].LRTableFuncP = LRShift;
	parser->lrTable[rows][1].actionParam = 5;
	parser->lrTable[rows][12].LRTableFuncP = LRGoto;
	parser->lrTable[rows][12].actionParam = 6;
	parser->lrTable[rows][13].LRTableFuncP = LRGoto;
	parser->lrTable[rows][13].actionParam = 7;
	parser->lrTable[rows][14].LRTableFuncP = LRGoto;
	parser->lrTable[rows][14].actionParam = 8;
	parser->lrTable[rows][15].LRTableFuncP = LRGoto;
	parser->lrTable[rows][15].actionParam = 9;
	parser->lrTable[rows][16].LRTableFuncP = LRGoto;
	parser->lrTable[rows][16].actionParam = 10;
	parser->lrTable[rows][5].LRTableFuncP = LRShift;
	parser->lrTable[rows][5].actionParam = 11;
	parser->lrTable[rows][6].LRTableFuncP = LRShift;
	parser->lrTable[rows][6].actionParam = 12;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 10;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 10;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 10;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 10;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 11;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 11;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 11;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 11;
	parser->lrTable[rows][3].LRTableFuncP = LRShift;
	parser->lrTable[rows][3].actionParam = 13;
rows++;
	parser->lrTable[rows][3].LRTableFuncP = LRShift;
	parser->lrTable[rows][3].actionParam = 14;
	parser->lrTable[rows][3].LRTableFuncP = LRShift;
	parser->lrTable[rows][3].actionParam = 26;
	parser->lrTable[rows][4].LRTableFuncP = LRShift;
	parser->lrTable[rows][4].actionParam = 27;
	parser->lrTable[rows][5].LRTableFuncP = LRShift;
	parser->lrTable[rows][5].actionParam = 28;
	parser->lrTable[rows][6].LRTableFuncP = LRShift;
	parser->lrTable[rows][6].actionParam = 29;
	parser->lrTable[rows][1].LRTableFuncP = LRShift;
	parser->lrTable[rows][1].actionParam = 30;
	parser->lrTable[rows][14].LRTableFuncP = LRGoto;
	parser->lrTable[rows][14].actionParam = 15;
	parser->lrTable[rows][15].LRTableFuncP = LRGoto;
	parser->lrTable[rows][15].actionParam = 31;
	parser->lrTable[rows][16].LRTableFuncP = LRGoto;
	parser->lrTable[rows][16].actionParam = 32;
	parser->lrTable[rows][8].LRTableFuncP = LRShift;
	parser->lrTable[rows][8].actionParam = 17;
	parser->lrTable[rows][9].LRTableFuncP = LRShift;
	parser->lrTable[rows][9].actionParam = 18;
	parser->lrTable[rows][10].LRTableFuncP = LRShift;
	parser->lrTable[rows][10].actionParam = 19;
	parser->lrTable[rows][11].LRTableFuncP = LRShift;
	parser->lrTable[rows][11].actionParam = 20;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 5;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 5;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 8;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 8;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 8;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 8;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 12;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 12;
rows++;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 12;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 12;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 13;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 13;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 13;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 13;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 15;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 15;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 15;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 15;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 14;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 14;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 14;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 14;
	parser->lrTable[rows][8].LRTableFuncP = LRShift;
	parser->lrTable[rows][8].actionParam = 33;
	parser->lrTable[rows][9].LRTableFuncP = LRShift;
	parser->lrTable[rows][9].actionParam = 34;
	parser->lrTable[rows][2].LRTableFuncP = LRShift;
	parser->lrTable[rows][2].actionParam = 21;
	parser->lrTable[rows][3].LRTableFuncP = LRShift;
	parser->lrTable[rows][3].actionParam = 1;
	parser->lrTable[rows][4].LRTableFuncP = LRShift;
	parser->lrTable[rows][4].actionParam = 2;
	parser->lrTable[rows][5].LRTableFuncP = LRShift;
	parser->lrTable[rows][5].actionParam = 3;
	parser->lrTable[rows][6].LRTableFuncP = LRShift;
	parser->lrTable[rows][6].actionParam = 4;
rows++;
	parser->lrTable[rows][1].LRTableFuncP = LRShift;
	parser->lrTable[rows][1].actionParam = 5;
	parser->lrTable[rows][15].LRTableFuncP = LRGoto;
	parser->lrTable[rows][15].actionParam = 22;
	parser->lrTable[rows][16].LRTableFuncP = LRGoto;
	parser->lrTable[rows][16].actionParam = 10;
	parser->lrTable[rows][3].LRTableFuncP = LRShift;
	parser->lrTable[rows][3].actionParam = 1;
	parser->lrTable[rows][4].LRTableFuncP = LRShift;
	parser->lrTable[rows][4].actionParam = 2;
	parser->lrTable[rows][5].LRTableFuncP = LRShift;
	parser->lrTable[rows][5].actionParam = 3;
	parser->lrTable[rows][6].LRTableFuncP = LRShift;
	parser->lrTable[rows][6].actionParam = 4;
	parser->lrTable[rows][1].LRTableFuncP = LRShift;
	parser->lrTable[rows][1].actionParam = 5;
	parser->lrTable[rows][15].LRTableFuncP = LRGoto;
	parser->lrTable[rows][15].actionParam = 23;
	parser->lrTable[rows][16].LRTableFuncP = LRGoto;
	parser->lrTable[rows][16].actionParam = 10;
	parser->lrTable[rows][3].LRTableFuncP = LRShift;
	parser->lrTable[rows][3].actionParam = 1;
	parser->lrTable[rows][4].LRTableFuncP = LRShift;
	parser->lrTable[rows][4].actionParam = 2;
	parser->lrTable[rows][5].LRTableFuncP = LRShift;
	parser->lrTable[rows][5].actionParam = 3;
	parser->lrTable[rows][6].LRTableFuncP = LRShift;
	parser->lrTable[rows][6].actionParam = 4;
	parser->lrTable[rows][1].LRTableFuncP = LRShift;
	parser->lrTable[rows][1].actionParam = 5;
	parser->lrTable[rows][16].LRTableFuncP = LRGoto;
	parser->lrTable[rows][16].actionParam = 24;
	parser->lrTable[rows][3].LRTableFuncP = LRShift;
	parser->lrTable[rows][3].actionParam = 1;
	parser->lrTable[rows][4].LRTableFuncP = LRShift;
	parser->lrTable[rows][4].actionParam = 2;
	parser->lrTable[rows][5].LRTableFuncP = LRShift;
	parser->lrTable[rows][5].actionParam = 3;
	parser->lrTable[rows][6].LRTableFuncP = LRShift;
	parser->lrTable[rows][6].actionParam = 4;
	parser->lrTable[rows][1].LRTableFuncP = LRShift;
	parser->lrTable[rows][1].actionParam = 5;
rows++;
	parser->lrTable[rows][16].LRTableFuncP = LRGoto;
	parser->lrTable[rows][16].actionParam = 25;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 9;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 9;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 9;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 9;
	parser->lrTable[rows][10].LRTableFuncP = LRShift;
	parser->lrTable[rows][10].actionParam = 19;
	parser->lrTable[rows][11].LRTableFuncP = LRShift;
	parser->lrTable[rows][11].actionParam = 20;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 3;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 3;
	parser->lrTable[rows][10].LRTableFuncP = LRShift;
	parser->lrTable[rows][10].actionParam = 19;
	parser->lrTable[rows][11].LRTableFuncP = LRShift;
	parser->lrTable[rows][11].actionParam = 20;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 4;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 4;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 6;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 6;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 6;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 6;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 7;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 7;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 7;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 7;
rows++;
	parser->lrTable[rows][5].LRTableFuncP = LRShift;
	parser->lrTable[rows][5].actionParam = 35;
	parser->lrTable[rows][6].LRTableFuncP = LRShift;
	parser->lrTable[rows][6].actionParam = 36;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 10;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 10;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 10;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 10;
	parser->lrTable[rows][2].LRTableFuncP = LRReduce;
	parser->lrTable[rows][2].actionParam = 10;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 11;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 11;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 11;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 11;
	parser->lrTable[rows][2].LRTableFuncP = LRReduce;
	parser->lrTable[rows][2].actionParam = 11;
	parser->lrTable[rows][3].LRTableFuncP = LRShift;
	parser->lrTable[rows][3].actionParam = 37;
	parser->lrTable[rows][3].LRTableFuncP = LRShift;
	parser->lrTable[rows][3].actionParam = 38;
	parser->lrTable[rows][3].LRTableFuncP = LRShift;
	parser->lrTable[rows][3].actionParam = 26;
	parser->lrTable[rows][4].LRTableFuncP = LRShift;
	parser->lrTable[rows][4].actionParam = 27;
	parser->lrTable[rows][5].LRTableFuncP = LRShift;
	parser->lrTable[rows][5].actionParam = 28;
	parser->lrTable[rows][6].LRTableFuncP = LRShift;
	parser->lrTable[rows][6].actionParam = 29;
	parser->lrTable[rows][1].LRTableFuncP = LRShift;
	parser->lrTable[rows][1].actionParam = 30;
	parser->lrTable[rows][14].LRTableFuncP = LRGoto;
	parser->lrTable[rows][14].actionParam = 39;
	parser->lrTable[rows][15].LRTableFuncP = LRGoto;
	parser->lrTable[rows][15].actionParam = 31;
rows++;
	parser->lrTable[rows][16].LRTableFuncP = LRGoto;
	parser->lrTable[rows][16].actionParam = 32;
	parser->lrTable[rows][10].LRTableFuncP = LRShift;
	parser->lrTable[rows][10].actionParam = 40;
	parser->lrTable[rows][11].LRTableFuncP = LRShift;
	parser->lrTable[rows][11].actionParam = 41;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 5;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 5;
	parser->lrTable[rows][2].LRTableFuncP = LRReduce;
	parser->lrTable[rows][2].actionParam = 5;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 8;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 8;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 8;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 8;
	parser->lrTable[rows][2].LRTableFuncP = LRReduce;
	parser->lrTable[rows][2].actionParam = 8;
	parser->lrTable[rows][3].LRTableFuncP = LRShift;
	parser->lrTable[rows][3].actionParam = 26;
	parser->lrTable[rows][4].LRTableFuncP = LRShift;
	parser->lrTable[rows][4].actionParam = 27;
	parser->lrTable[rows][5].LRTableFuncP = LRShift;
	parser->lrTable[rows][5].actionParam = 28;
	parser->lrTable[rows][6].LRTableFuncP = LRShift;
	parser->lrTable[rows][6].actionParam = 29;
	parser->lrTable[rows][1].LRTableFuncP = LRShift;
	parser->lrTable[rows][1].actionParam = 30;
	parser->lrTable[rows][15].LRTableFuncP = LRGoto;
	parser->lrTable[rows][15].actionParam = 42;
	parser->lrTable[rows][16].LRTableFuncP = LRGoto;
	parser->lrTable[rows][16].actionParam = 32;
	parser->lrTable[rows][3].LRTableFuncP = LRShift;
	parser->lrTable[rows][3].actionParam = 26;
	parser->lrTable[rows][4].LRTableFuncP = LRShift;
	parser->lrTable[rows][4].actionParam = 27;
	parser->lrTable[rows][5].LRTableFuncP = LRShift;
	parser->lrTable[rows][5].actionParam = 28;
rows++;
	parser->lrTable[rows][6].LRTableFuncP = LRShift;
	parser->lrTable[rows][6].actionParam = 29;
	parser->lrTable[rows][1].LRTableFuncP = LRShift;
	parser->lrTable[rows][1].actionParam = 30;
	parser->lrTable[rows][15].LRTableFuncP = LRGoto;
	parser->lrTable[rows][15].actionParam = 43;
	parser->lrTable[rows][16].LRTableFuncP = LRGoto;
	parser->lrTable[rows][16].actionParam = 32;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 12;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 12;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 12;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 12;
	parser->lrTable[rows][2].LRTableFuncP = LRReduce;
	parser->lrTable[rows][2].actionParam = 12;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 13;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 13;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 13;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 13;
	parser->lrTable[rows][2].LRTableFuncP = LRReduce;
	parser->lrTable[rows][2].actionParam = 13;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 15;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 15;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 15;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 15;
	parser->lrTable[rows][2].LRTableFuncP = LRReduce;
	parser->lrTable[rows][2].actionParam = 15;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 14;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 14;
rows++;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 14;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 14;
	parser->lrTable[rows][2].LRTableFuncP = LRReduce;
	parser->lrTable[rows][2].actionParam = 14;
	parser->lrTable[rows][8].LRTableFuncP = LRShift;
	parser->lrTable[rows][8].actionParam = 33;
	parser->lrTable[rows][9].LRTableFuncP = LRShift;
	parser->lrTable[rows][9].actionParam = 34;
	parser->lrTable[rows][2].LRTableFuncP = LRShift;
	parser->lrTable[rows][2].actionParam = 44;
	parser->lrTable[rows][3].LRTableFuncP = LRShift;
	parser->lrTable[rows][3].actionParam = 26;
	parser->lrTable[rows][4].LRTableFuncP = LRShift;
	parser->lrTable[rows][4].actionParam = 27;
	parser->lrTable[rows][5].LRTableFuncP = LRShift;
	parser->lrTable[rows][5].actionParam = 28;
	parser->lrTable[rows][6].LRTableFuncP = LRShift;
	parser->lrTable[rows][6].actionParam = 29;
	parser->lrTable[rows][1].LRTableFuncP = LRShift;
	parser->lrTable[rows][1].actionParam = 30;
	parser->lrTable[rows][16].LRTableFuncP = LRGoto;
	parser->lrTable[rows][16].actionParam = 45;
	parser->lrTable[rows][3].LRTableFuncP = LRShift;
	parser->lrTable[rows][3].actionParam = 26;
	parser->lrTable[rows][4].LRTableFuncP = LRShift;
	parser->lrTable[rows][4].actionParam = 27;
	parser->lrTable[rows][5].LRTableFuncP = LRShift;
	parser->lrTable[rows][5].actionParam = 28;
	parser->lrTable[rows][6].LRTableFuncP = LRShift;
	parser->lrTable[rows][6].actionParam = 29;
	parser->lrTable[rows][1].LRTableFuncP = LRShift;
	parser->lrTable[rows][1].actionParam = 30;
	parser->lrTable[rows][16].LRTableFuncP = LRGoto;
	parser->lrTable[rows][16].actionParam = 46;
	parser->lrTable[rows][10].LRTableFuncP = LRShift;
	parser->lrTable[rows][10].actionParam = 40;
	parser->lrTable[rows][11].LRTableFuncP = LRShift;
	parser->lrTable[rows][11].actionParam = 41;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 3;
rows++;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 3;
	parser->lrTable[rows][2].LRTableFuncP = LRReduce;
	parser->lrTable[rows][2].actionParam = 3;
	parser->lrTable[rows][10].LRTableFuncP = LRShift;
	parser->lrTable[rows][10].actionParam = 40;
	parser->lrTable[rows][11].LRTableFuncP = LRShift;
	parser->lrTable[rows][11].actionParam = 41;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 4;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 4;
	parser->lrTable[rows][2].LRTableFuncP = LRReduce;
	parser->lrTable[rows][2].actionParam = 4;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 9;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 9;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 9;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 9;
	parser->lrTable[rows][2].LRTableFuncP = LRReduce;
	parser->lrTable[rows][2].actionParam = 9;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 6;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 6;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 6;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 6;
	parser->lrTable[rows][2].LRTableFuncP = LRReduce;
	parser->lrTable[rows][2].actionParam = 6;
	parser->lrTable[rows][8].LRTableFuncP = LRReduce;
	parser->lrTable[rows][8].actionParam = 7;
	parser->lrTable[rows][9].LRTableFuncP = LRReduce;
	parser->lrTable[rows][9].actionParam = 7;
	parser->lrTable[rows][10].LRTableFuncP = LRReduce;
	parser->lrTable[rows][10].actionParam = 7;
	parser->lrTable[rows][11].LRTableFuncP = LRReduce;
	parser->lrTable[rows][11].actionParam = 7;
rows++;
	parser->lrTable[rows][2].LRTableFuncP = LRReduce;
	parser->lrTable[rows][2].actionParam = 7;



	if (PRINT_MATRIX){
        int count = 0;
        int count2 = 0;
        char funcP;
        printf("\n\n\n\n");
		printf("     ");
		for (int i = 0; i < TOTAL_ACTIONS+GRAMMER_SYMBOL_COUNT; i++){
			if (i < 10) {printf("  %d   ", i);}else{
				printf("  %d  ", i);
			}
		}




		printf("\n\n");
		printf("00:  ");
        for (int i = 0; i < TOTAL_ACTIONS+GRAMMER_SYMBOL_COUNT;i++){
            for (int j = 0; j < TOTAL_STATES; j++){
                if (parser->lrTable[i][j].LRTableFuncP == LRAccept){
                    funcP = 'A';
                }else if (parser->lrTable[i][j].LRTableFuncP == LRError){
                    funcP = 'E';
                }else if (parser->lrTable[i][j].LRTableFuncP == LRGoto){
                    funcP = 'G';
                }else if (parser->lrTable[i][j].LRTableFuncP == LRReduce){
                    funcP = 'R';
                }else if (parser->lrTable[i][j].LRTableFuncP == LRShift){
                    funcP = 'S';
                }else{
                    printf("Woopsy Daisy1");
                }

				

                /*if (parser->lrTable[i][j].actionParam > 9){
                    printf ("{%c%d} ", funcP, parser->lrTable[i][j].actionParam);
                }else if (parser->lrTable[i][j].actionParam < 0) {
                    printf ("{%c%d} ", funcP, parser->lrTable[i][j].actionParam);
                }else{
                    printf ("{%c0%d} ", funcP, parser->lrTable[i][j].actionParam);
                }
                count++;
                if (count == 16){
                    count2++;
                    printf("          %d\n", count);
					if (count2 < 10 && count2+1 <= TOTAL_STATES){
						printf("0%d:  ",count2);
					}else if (count2+1 <= TOTAL_STATES){
						printf("%d:  ",count2);
					}
                    count = 0;
                }*/
            }
        }
        printf("\n\n\n\n");
    }

    
















    printf("Parser Initialized Succesfully!\n");
    
    return parser;
}

