#ifndef LRTABLE_H
#define LRTABLE_H
#include <stdlib.h>
#include "lexer.h"
#include "stack.h"
#include "parser.h"

void Shift(Parser* parser, int num/*TEMP NAME*/);
void Reduce(Parser* parser, int num/*TEMP NAME*/);
void GOTO(Parser* parser, int num/*TEMP NAME*/);
void LRTableError(Parser* parser, int num/*TEMP NAME*/);
#endif