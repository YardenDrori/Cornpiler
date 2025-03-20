#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>

//i need a bison parser.y file that utilizes all these tokens similarly to C

typedef enum {
    //Opearators
    EQUAL_LESSER,           //0 for conditions
    GREATER_THAN,           //1 for conditions
    LESSER_THAN,            //2 for conditions
    EQUAL,                  //3 for setting values
    IS_EQUAL,               //4 for conditions
    NOT,                    //5 for conditions
    NOT_EQUAL,              //6 for conditions
    EQUAL_GREATER,          //7 for conditions
    PLUS,                   //8 for adding two Expr
    INC,                    //9 basicallt like ++ i.e x++
    PLUS_EQUAL,             //10 adding a value to a ident i.e x+=3
    MINUS,                  //11 for substracting values
    DEC,                    //12 oppesote of inc i.e x--
    MINUS_EQUAL,            //13 substracting value from ident i.e x-=3
    DIVIDE,                 //14 for divisions
    DIVIDE_EQUAL,           //15 same as plus equal or minus equal just for divide
    MULTIPLY,               //16 multiplicatiom and pointer decleration i.e int* x
    MULTIPLY_EQUAL,         //17 same as plus equal just for multiplication
    MODULO,                 //18 modulo operations
    MODULO_EQUAL,           //19 same as before
    AMPERCENT,              //20 for getting adress of idents i.e int* x = &y and for bitwise and operator
    BITWISE_AND_EQUAL,      //21 same as plus equal but bitwise i.e x &= 3
    BITWISE_OR,             //22 bitwise or operator: '|'
    BITWISE_OR_EQUAL,       //23 same as before
    BITWISE_XOR,            //24 bitwise xor operator: '^'
    BITWISE_XOR_EQUAL,      //25 same as before
    BITWISE_NOT,            //26 bitwise not operator '~'
    BITWISE_NOT_EQUAL,      //27 same as before
    LEFT_SHIFT,             //28 left shift bits of ident i.e x << 3
    RIGHT_SHIFT,            //29 same as left shift but with right shift i.e x >> 3
    OPEN_PARENTHESIS,       //30 where you'd expect to find it in C
    CLOSE_PARENTHESIS,      //31 where you'd expect to find it in C
    OPEN_CURLY_BRACKETS,    //32 for starting blocks
    CLOSE_CURLY_BRACKETS,   //33 for ending blocks
    OPEN_BRACKETS,          //34 for creating arrays
    CLOSE_BRACKETS,         //35 for creating arrays
    

    //literals
    FLOAT_LITERAL,          //36 float values i.e 3.2
    TRUE,                   //37 self explanetory
    FALSE,                  //38 self explanetory
    INT_LITERAL,            //39 int values i.e 13
    CHAR_LITERAL,           //40 char values i.e 'h'
    
    //variables
    FLOAT,                  //41 float decl i.e float x = 3.2
    INT,                    //42 int decl i.e int x = 1
    CHAR,                   //43 char decl i.e char x = '\n'
    BOOLEAN,                //44 boolean decl i.e bool x = true

    //conditions
    IF,                     //45 starting an if statement
    THEN,                   //46 DEPRECATED DO NOT USE
    ELSE,                   //47 self explanetory
    LOGIC_AND,              //48 the "&&" for checking 2 cond in one if i.e if (x == 1 && y == 2)
    LOGIC_OR,               //49 the "||" for checking if either condition is true

    //loops
    FOR,                    //50 initializing for loops i.e (decl / assignment; condition; assignment){
    WHILE,                  //51 initializing while loops i.e while (condition){
    
    //misc
    IDENT,                  //52 variable or function names
    END_OF_FILE,            //53 internal
    SKIP,                   //54 internal
    NEXT_LINE,              //55 internal
    ERROR,                  //56 internal
    SEMICOLON,              //57 semicolon for seperating lines i.e int x;
    COMMA,                  //58 comma for functions
    QUESTION_MARK,          //59 idk why
    COLON                   //60 idk again why
} TokenType;




typedef union
{
    int int_val;
    float float_val;
    int bool_val; //1 or zero
    char char_val;
    char *ident_val;
} TokenValue;

typedef struct
{ 
    TokenType type;
    TokenValue value;
    int row;
    int col;
} Token;




#endif //TOKEN_H