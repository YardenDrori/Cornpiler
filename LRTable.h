#ifndef LRTABLE_H
#define LRTABLE_H
#include <stdlib.h>
#include "lexer.h"
#include "stack.h"
#include "parser.h"

void LRS(Parser* parser, int actionParam);
void LRR(Parser* parser, int actionParam);
void LRG(Parser* parser, int actionParam);
void LRE(Parser* parser, int actionParam);

#endif