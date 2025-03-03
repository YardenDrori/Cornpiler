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


#endif