#ifndef LRTABLE_H
#define LRTABLE_H
#include <stdlib.h>
#include "../../Lexer/H_Files/lexer.h"
#include "../H_Files/stack.h"

// Forward declare struct Parser
struct Parser;



void LRShift(struct Parser* parser, int actionParam);
void LRReduce(struct Parser* parser, int actionParam);
void LRGoto(struct Parser* parser, int actionParam);
void LRError(struct Parser* parser, int actionParam);
void LRAccept(struct Parser* parser, int actionParam);
void ReduceGeneric(struct Parser* parser, grammarSymbol symbol, int reduceBy);
void ReduceToProgram(struct Parser* parser,int reduceBy);
void ReduceToStart(struct Parser* parser,int reduceBy);
void ReduceToStmtList(struct Parser* parser,int reduceBy);
void ReduceToStmt(struct Parser* parser,int reduceBy);
void ReduceToDecl(struct Parser* parser,int reduceBy);
void ReduceToAssi(struct Parser* parser,int reduceBy);
void ReduceToExpr(struct Parser* parser,int reduceBy);
void ReduceToTerm(struct Parser* parser,int reduceBy);
void ReduceToFactor(struct Parser* parser,int reduceBy);
void ReduceToCondExpr(struct Parser* parser,int reduceBy);
void ReduceToRelOp(struct Parser* parser,int reduceBy);
void ReduceToIfStmt(struct Parser* parser,int reduceBy);
void ReduceToLoopStmt(struct Parser* parser,int reduceBy);
void initParserLRTable(struct Parser* parser);
#endif