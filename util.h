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

void handle_int_literal(Token *token, char *input);
void handle_false(Token *token, char *input);
void handle_true(Token *token, char *input);
void handle_float_literal(Token *token, char *input);
void handle_char_literal(Token *token, char *input);
void handle_ident(Token *token, char *input);


#endif