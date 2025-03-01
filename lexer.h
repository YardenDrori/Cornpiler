#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "state.h"

#define BUFFER_SIZE 4096 //4kb
#define INITIAL_TOKEN_CAPACITY 64
#define MAX_STATES 83
typedef struct
{
    int row;
    int col;
    char *input;
    int input_len;
} Lexme;

typedef struct
{
    FILE *file; //the file containing cce code
    char buffer[BUFFER_SIZE]; //4kb buffer to to read the file
    int pos; //current position in the buffer
    int buffer_length; //how many bytes were read into the buffer so that we can continue reading the file from the end of that point
    int current_state; //the current state of the dfa
    int transition_table[MAX_STATES][256]; //the table for the dfa
    Token *tokens; //dynamic array
    State states[MAX_STATES];
    int token_id; //amount of tokens saved so far
    int token_capacity; //current max capacity of the dynamic array
    Lexme *lexme;
} Lexer;

Lexer *initLexer(const char *filename);
void loadBuffer(Lexer *lexer);
char nextChar(Lexer *lexer);
Token nextToken(Lexer *lexer);
void freeLexer(Lexer *lexer);    
void getTokenList(Lexer *Lexer);
#endif 