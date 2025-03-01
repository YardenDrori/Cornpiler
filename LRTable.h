#ifndef LRTABLE_H
#define LRTABLE_H
#include <stdlib.h>
#include "lexer.h"
#include "stack.h"
#include "parser.h"

void LRShift(Parser* parser, int actionParam);
void LRReduce(Parser* parser, int actionParam);
void LRGoto(Parser* parser, int actionParam);
void LRError(Parser* parser, int actionParam);
void LRAccept(Parser* parser, int actionParam);

#endif