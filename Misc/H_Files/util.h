#ifndef UTIL_H
#define UTIL_H

#include "../../Lexer/H_Files/lexer.h"
#include "../../Lexer/H_Files/token.h"
#include "../../Lexer/H_Files/state.h"
#include "../../Parser/H_Files/parseTree.h"
#include "global.h"
#include <stdio.h>
#include <stdlib.h>

extern const char enumToString[][30];  // Declare as extern

void printTokenType(Token token);
int isCharInArray(char target, char array[]);
void printTokenArray(Lexer *Lexer);

void handle_int_literal(Token *token, Lexme *lexme);
void handle_false(Token *token, Lexme *lexme);
void handle_true(Token *token, Lexme *lexme);
void handle_float_literal(Token *token, Lexme *lexme);
void handle_char_literal(Token *token, Lexme *lexme);
void handle_ident(Token *token, Lexme *lexme);
void handle_next_line(Token *token, Lexme *lexme);
void handle_error(Token *token, Lexme *lexme);
void printTree(parseTreeNode* head);

#endif