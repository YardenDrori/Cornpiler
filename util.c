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
    "END_OF_FILE"      
};

void printTokenType(Token token){
    printf("%s ", enumToString[token.type]);
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