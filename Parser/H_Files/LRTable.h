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
void ReduceGeneric(struct Parser* parser, grammarSymbol symbol, int listSize);
void accept(struct Parser* parser);
void ReduceToProgram1(struct Parser* parser);
void ReduceToStart1(struct Parser* parser);
void ReduceToExpr3(struct Parser* parser);
void ReduceToExpr1(struct Parser* parser);
void ReduceToTerm3(struct Parser* parser);
void ReduceToTerm1(struct Parser* parser);
void ReduceToFactor3(struct Parser* parser);
void ReduceToFactor1(struct Parser* parser);
void ReduceToFactor2(struct Parser* parser);

#endif