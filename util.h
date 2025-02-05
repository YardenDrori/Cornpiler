#ifndef UTIL_H
#define UTIL_H

#include "lexer.h"
#include "token.h"
#include "state.h"
#include <stdio.h>
#include <stdlib.h>
#define FILENAME "ExampleScript.txt"

extern const char enumToString[][20];  // Declare as extern

void printTokenType(Token token);
int isCharInArray(char chr, char array[]);
#endif