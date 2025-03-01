#ifndef LRTABLE_H
#define LRTABLE_H
#include <stdlib.h>
#include "lexer.h"
#include "stack.h"
#include "parser.h"

void Shift(Parser* parser, int actionParam);
void Reduce(Parser* parser, int actionParam);
void GOTO(Parser* parser, int actionParam);
void LRTableError(Parser* parser, int actionParam);
#endif