#ifndef UTIL_H
#define UTIL_H

#include "lexer.h"
#include "token.h"
#include "state.h"
#include <stdio.h>
#include <stdlib.h>
#define FILENAME "ExampleScript.txt"

extern const char enumToString[][30];  // Declare as extern

void printTokenType(Token token);
int isCharInArray(char target, char array[]);
void printTokenArray(Lexer *Lexer);
#endif