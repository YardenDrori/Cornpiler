#include "lexer.h"
#include "token.h"
#include "state.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#define FILENAME "ExampleScript.txt"

// Define the array here
const char enumToString[][30] = {
    "EQUAL_LESSER",   
    "GREATER_THAN",     
    "LESSER_THAN",      
    "EQUAL",           
    "IS_EQUAL",          
    "NOT",               
    "NOT_EQUAL",         
    "EQUAL_GREATER",    
    "PLUS",              
    "INC",              
    "PLUS_EQUAL",        
    "MINUS",             
    "DEC",               
    "MINUS_EQUAL",       
    "DIVIDE",            
    "DIVIDE_EQUAL",      
    "MULTIPLY",          
    "MULTIPLY_EQUAL",    
    "MODULU",            
    "MODULU_EQUAL",      
    "OPEN_PARENTHESIS",   
    "CLOSE_PARENTHESIS",
    "OPEN_CURLY_BRACKETS",
    "CLOSE_CURLY_BRACKETS",
    "FLOAT_LITERAL",
    "TRUE",             
    "FALSE",           
    "INT_LITERAL",    
    "CHAR_LITERAL",  
    "FLOAT",        
    "INT",               
    "CHAR",              
    "BOOLEAN",         
    "IF",              
    "THEN",          
    "ELSE",        
    "AND",            
    "OR",                
    "FOR",        
    "WHILE",          
    "IDENT",     
    "END_OF_FILE",
    "SKIP"
};

void printTokenType(Token token){
    switch (token.type)
    {
    case INT_LITERAL:
        printf("%s - %d ", enumToString[token.type], token.value.int_val);
        break;
    case CHAR_LITERAL:
        printf("%s - \'%c\' ", enumToString[token.type], token.value.char_val);
        break;
    case FLOAT_LITERAL:
        printf("%s - %f ", enumToString[token.type], token.value.float_val);
        break;
    case TRUE:
        printf("%s - 1 ", enumToString[token.type]);
        break;
    case FALSE:
        printf("%s - 0 ", enumToString[token.type]);
        break;
    case IDENT:
        printf("%s - \"%s\" ", enumToString[token.type], token.value.ident_val);
        break;
    default:
        printf("%s ", enumToString[token.type]);

    }
}

void printTokenArray(Lexer *lexer){
    getTokenList(lexer);
    printf("\n");
    for (int i = 0; i < lexer->token_id+1; i++){
        printf("\n---------------------\n");
        printTokenType(lexer->tokens[i]);
    }
    printf("\n=-=-=-=-=-=-=-=-=-=-=");
    printf("\ntokens %d\ntoken capacity %d", lexer->token_id, lexer->token_capacity);
    printf("\n=-=-=-=-=-=-=-=-=-=-=\n");
}

int isCharInArray(char target, char array[]){
    int i = 0;
    char current_char = array[i];
    while (current_char != '\0'){
        if (current_char == target){
            return 1;
        }
        i++;
        current_char = array[i];
    }
    return 0;
}

void handle_int_literal(Token *token, char *input) {
    token->value.int_val = atoi(input);
}
void handle_false(Token *token, char *input) {
    token->value.bool_val = 0;
}

void handle_true(Token *token, char *input) {
    token->value.bool_val = 1;
}

void handle_float_literal(Token *token, char *input) {
    token->value.float_val = strtof(input, NULL);
}

void handle_char_literal(Token *token, char *input) {
    token->value.char_val = input[1];
}

void handle_ident(Token *token, char *input) {
    int size = 0;
    while (input[size++] != '\0');
    size--;
    token->value.ident_val = malloc(sizeof(char) * size);
    if (!token->value.ident_val) {
        printf("Error allocating memory for IDENT value.\n");
        return;
    }
    token->value.ident_val = input;
}