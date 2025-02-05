#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>


typedef enum {
    //Opearators
    EQUAL_LESSER,       //0
    GREATER_THAN,       //1
    LESSER_THAN,        //2
    EQUAL,              //3
    IS_EQUAL,           //4
    NOT,                //5
    NOT_EQUAL,          //6
    EQUAL_GREATER,      //7
    PLUS,               //8
    INC,                //9
    PLUS_EQUAL,         //10
    MINUS,              //11
    DEC,                //12
    MINUS_EQUAL,        //13
    DIVIDE,             //14
    DIVIDE_EQUAL,       //15
    MULTIPLY,           //16
    MULTIPLY_EQUAL,     //17
    MODULU,             //18
    MODULU_EQUAL,       //19

    //literals
    FLOAT_LITERAL,      //20
    TRUE,               //21
    FALSE,              //22
    INT_LITERAL,        //23
    CHAR_LITERAL,       //24
    
    //variables
    FLOAT,              //25
    INT,                //26
    CHAR,               //27
    BOOLEAN,            //28
    
    //conditions
    IF,                 //29
    THEN,               //30
    ELSE,               //31
    AND,                //32
    OR,                 //33

    //loops
    FOR,                //34
    WHILE,              //35
    
    //misc
    IDENT,              //36
    END_OF_FILE,        //37
} TokenType;

typedef struct
{ 
    TokenType type;
    char *value;
} Token;


#endif //TOKEN_H