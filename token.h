#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>


typedef enum {
    //Opearators
    EQUAL_LESSER,           //0
    GREATER_THAN,           //1
    LESSER_THAN,            //2
    EQUAL,                  //3
    IS_EQUAL,               //4
    NOT,                    //5
    NOT_EQUAL,              //6
    EQUAL_GREATER,          //7
    PLUS,                   //8
    INC,                    //9
    PLUS_EQUAL,             //10
    MINUS,                  //11
    DEC,                    //12
    MINUS_EQUAL,            //13
    DIVIDE,                 //14
    DIVIDE_EQUAL,           //15
    MULTIPLY,               //16
    MULTIPLY_EQUAL,         //17
    MODULU,                 //18
    MODULU_EQUAL,           //19
    OPEN_PARENTHESIS,       //20
    CLOSE_PARENTHESIS,      //21
    OPEN_CURLY_BRACKETS,    //22
    CLOSE_CURLY_BRACKETS,   //23

    //literals
    FLOAT_LITERAL,          //24
    TRUE,                   //25
    FALSE,                  //26
    INT_LITERAL,            //27
    CHAR_LITERAL,           //28
    
    //variables
    FLOAT,                  //29
    INT,                    //30
    CHAR,                   //31
    BOOLEAN,                //32
    
    //conditions
    IF,                     //33
    THEN,                   //34
    ELSE,                   //35
    AND,                    //36
    OR,                     //37

    //loops
    FOR,                    //38
    WHILE,                  //39
    
    //misc
    IDENT,                  //40
    END_OF_FILE,            //41
    SKIP,                   //42
    NEXT_LINE,              //43
    ERROR                   //44
} TokenType;
#define TOTAL_TOKENS 45

typedef struct
{
    int row;
    int col;
} Error;

typedef union
{
    int int_val;
    float float_val;
    int bool_val; //1 or zero
    char char_val;
    char *ident_val;
    Error error_val;
} TokenValue;

typedef struct
{ 
    TokenType type;
    TokenValue value;
} Token;




#endif //TOKEN_H