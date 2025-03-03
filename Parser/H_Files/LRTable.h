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
void Reduce1(struct Parser* parser);
void Reduce2(struct Parser* parser);
void Reduce3(struct Parser* parser);
void Reduce4(struct Parser* parser);
void Reduce5(struct Parser* parser);
void Reduce6(struct Parser* parser);
void Reduce7(struct Parser* parser);
void Reduce8(struct Parser* parser);
void Reduce9(struct Parser* parser);
void Reduce10(struct Parser* parser);
void Reduce11(struct Parser* parser);
void Reduce12(struct Parser* parser);
void Reduce13(struct Parser* parser);
void Reduce14(struct Parser* parser);
void Reduce15(struct Parser* parser);

#endif