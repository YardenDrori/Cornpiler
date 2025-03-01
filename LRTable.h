#ifndef LRTABLE_H
#define LRTABLE_H
#include <stdlib.h>
#include "lexer.h"
#include "stack.h"

// Forward declare struct Parser
struct Parser;

void LRShift(struct Parser* parser, int actionParam);
void LRReduce(struct Parser* parser, int actionParam);
void LRGOTO(struct Parser* parser, int actionParam);
void LRError(struct Parser* parser, int actionParam);
void LRAccept(struct Parser* parser, int actionParam);


#endif