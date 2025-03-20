#include "../../Lexer/H_Files/lexer.h"
#include "../../Lexer/H_Files/token.h"
#include "../../Lexer/H_Files/state.h"
#include "../../Parser/H_Files/parser.h"
#include "../H_Files/util.h"
#include <stdio.h>
#include <stdlib.h>

// Define the array here
const char enumToString[][30] = {
    "EQUAL_LESSER",           //0
    "GREATER_THAN",           //1
    "LESSER_THAN",            //2
    "EQUAL",                  //3
    "IS_EQUAL",               //4
    "NOT",                    //5
    "NOT_EQUAL",              //6
    "EQUAL_GREATER",          //7
    "PLUS",                   //8
    "INC",                    //9
    "PLUS_EQUAL",             //10
    "MINUS",                  //11
    "DEC",                    //12
    "MINUS_EQUAL",            //13
    "DIVIDE",                 //14
    "DIVIDE_EQUAL",           //15
    "MULTIPLY",               //16
    "MULTIPLY_EQUAL",         //17
    "MODULO",                 //18
    "MODULO_EQUAL",           //19
    "APMERCENT",              //20
    "BITWISE_AND_EQUAL",      //21
    "BITWISE_OR",             //22
    "BITWISE_OR_EQUAL",       //23
    "BITWISE_XOR",            //24
    "BITWISE_XOR_EQUAL",      //25
    "BITWISE_NOT",            //26
    "BITWISE_NOT_EQUAL",      //27
    "LEFT_SHIFT",             //28
    "RIGHT_SHIFT",            //29
    "OPEN_PARENTHESIS",       //30
    "CLOSE_PARENTHESIS",      //31
    "OPEN_CURLY_BRACKETS",    //32
    "CLOSE_CURLY_BRACKETS",   //33
    "OPEN_BRACKETS",          //34
    "CLOSE_BRACKETS",         //35
    

    //literals
    "FLOAT_LITERAL",          //36
    "TRUE",                   //37
    "FALSE",                  //38
    "INT_LITERAL",            //39
    "CHAR_LITERAL",           //40
    
    //variables
    "FLOAT",                  //41
    "INT",                    //42
    "CHAR",                   //43
    "BOOLEAN",                //44

    //conditions
    "IF",                     //45
    "THEN",                   //46 deprecated do not use
    "ELSE",                   //47
    "LOGIC_AND",              //48
    "LOGIC_OR",               //49

    //loops
    "FOR",                    //50
    "WHILE",                  //51
    
    //misc
    "IDENT",                  //52
    "END_OF_FILE",            //53
    "SKIP",                   //54
    "NEXT_LINE",              //55
    "ERROR",                  //56
    "SEMICOLON"               //57
};

const char grammerEnumToString[][30] = {
    "PROGRAM",
    "Start",
    "StmtList",
    "Stmt",
    "Decl",
    "Assi",
    "Expr",
    "Term",
    "Factor",
    "CondExpr",
    "RelOp",
    "IfStmt",
    "LoopStmt",
    "GRAMMER_SYMBOL_COUNT"
};

//prints a single token
void printTokenType(Token token){
    switch (token.type)
    {
    case INT_LITERAL:
        printf("\033[1;94m%s - %d \033[0m", enumToString[token.type], token.value.int_val);
        break;
    case CHAR_LITERAL:
        printf("\033[1;94m%s - '", enumToString[token.type]);
        switch (token.value.char_val) {            
            case '\n': printf("\\n"); break;
            case '\t': printf("\\t"); break;
            case '\r': printf("\\r"); break;
            case '\b': printf("\\b"); break;
            case '\f': printf("\\f"); break;
            case '\v': printf("\\v"); break;
            case '\\': printf("\\\\"); break;
            case '\'': printf("\\'"); break;
            case '\"': printf("\\\""); break;
            default: printf("%c", token.value.char_val); break;
        }
        printf("'\033[0m");
        break;
    
    case FLOAT_LITERAL:
        printf("\033[1;94m%s - %f \033[0m", enumToString[token.type], token.value.float_val);
        break;
    case TRUE:
        printf("\033[1;94m%s - 1 \033[0m", enumToString[token.type]);
        break;
    case FALSE:
        printf("\033[1;94m%s - 0 \033[0m", enumToString[token.type]);
        break;
    case IDENT:
        printf("\033[1;94m%s - \"%s\" \033[0m", enumToString[token.type], token.value.ident_val);
        break;
    case ERROR:
        printf("\033[1;31m%s - Row: %d, Column: %d\033[0m", enumToString[token.type], token.row, token.col);
        fflush(stdout); // Ensure it gets printed properly
        break;
    default:
        printf("\033[94m%s \033[0m", enumToString[token.type]);
    }
}

//prints all tokens in a lexer array
void printTokenArray(Lexer *lexer){
    printf("\n\033[1;4;32mTokens:\033[0m");
    for (int i = 0; i < lexer->token_id+1; i++){
        printf("\n\033[30m---------------------\033[0m\n");
        printTokenType(lexer->tokens[i]);
    }
    printf("\n\033[33m=-=-=-=-=-=-=-=-=-=-=\033[0m");
    printf("\n\033[33mtokens: %d\ntoken capacity: %d\nfinal row: %d, final collumn: %d\033[0m", lexer->token_id+1, lexer->token_capacity, lexer->lexme->row, lexer->lexme->col);
    printf("\n\033[33m=-=-=-=-=-=-=-=-=-=-=\033[0m\n");
}

//returns 1 if a char has been found in a string and 0 otherwise
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

//handle value for all the literals
void handle_int_literal(Token *token, Lexme *lexme) {
    token->value.int_val = atoi(lexme->input);
}
void handle_false(Token *token,__unused Lexme *lexme) {
    token->value.bool_val = 0;
}

void handle_true(Token *token,__unused Lexme *lexme) {
    token->value.bool_val = 1;
}

void handle_float_literal(Token *token, Lexme *lexme) {
    token->value.float_val = strtof(lexme->input, NULL);
}

void handle_char_literal(Token *token, Lexme *lexme) {
    if (lexme->input[0] == '\\') { // Check if it's an escape sequence
        switch (lexme->input[1]) {
            case 'n': token->value.char_val = '\n'; break;
            case 't': token->value.char_val = '\t'; break;
            case 'r': token->value.char_val = '\r'; break;
            case 'b': token->value.char_val = '\b'; break;
            case 'f': token->value.char_val = '\f'; break;
            case 'v': token->value.char_val = '\v'; break;
            case '\\': token->value.char_val = '\\'; break;
            case '\'': token->value.char_val = '\''; break;
            case '\"': token->value.char_val = '\"'; break;
            default: 
                token->value.char_val = lexme->input[1]; // Fallback to normal character
        }
    } else {
        token->value.char_val = lexme->input[0]; // Store as-is if not an escape sequence
    }
}

void handle_ident(Token *token, Lexme *lexme) {
    token->value.ident_val = malloc(sizeof(char) * lexme->input_len);
    if (!token->value.ident_val) {
        printf("Error allocating memory for IDENT value.\n");
        return;
    }
    token->value.ident_val = lexme->input;
}

void handle_next_line(__unused Token *token, Lexme *lexme){
    lexme->row++;
    lexme->col = -1;
}

void handle_error(__unused Token *token, Lexme *lexme){
    lexme->pos++;
}

#include <stdio.h>
#include <string.h>

void printTreeHelper(parseTreeNode* node, const char* prefix, int isLast) {
    // Print the current prefix.
    printf("%s", prefix);
    // Print the branch: use └── for the last child and ├── for others.
    if (isLast)
        printf("└── ");
    else
        printf("├── ");
    
    // Print the node's data.
    if (node->data.dataType == TOKEN_DATA_TYPE) {
        printf("%s\n", enumToString[node->data.data.token.type]);
    } else {
        printf("%s\n", grammerEnumToString[node->data.data.symbol]);
    }
    
    // Prepare the prefix for the children.
    // If this node is the last child, add spaces; otherwise, add a vertical line.
    char newPrefix[256];
    snprintf(newPrefix, sizeof(newPrefix), "%s%s", prefix, isLast ? "    " : "│   ");
    
    // Recursively print each child.
    for (int i = 0; i < node->childrenCount; i++) {
        printTreeHelper(&(node->children[i]), newPrefix, i == node->childrenCount - 1);
    }
}

void printTree(parseTreeNode* head) {
    printf("\nParse Tree:\n");
    if (head != NULL) {
        // Print the root node without any branch lines.
        if (head->data.dataType == TOKEN_DATA_TYPE)
            printf("%s\n", enumToString[head->data.data.token.type]);
        else
            printf("%s\n", grammerEnumToString[head->data.data.symbol]);
        
        // Print each child of the root with the appropriate prefix.
        for (int i = 0; i < head->childrenCount; i++) {
            printTreeHelper(&(head->children[i]), "", i == head->childrenCount - 1);
        }
    }
}

void printStack(StackNode* stack){
    if (stack->next != NULL){
        printStack(stack->next);
    }
    
    if (stack->value.dataType == TOKEN_DATA_TYPE){
        printf("%s ", enumToString[stack->value.data.treeNode->data.data.token.type]);
    }else if (stack->value.dataType == GRAMMER_SYMBOL_DATA_TYPE){
        printf("%s ", grammerEnumToString[stack->value.data.treeNode->data.data.symbol]);
    }else {
        printf("%d ", stack->value.data.intValue);
    }
    
}


void printParsingStep(Parser* parser){
    int tokenID = parser->tokenId;
    printf("\nSTACK: ");
    printStack(parser->stack->top);
    printf("\nINPUT: ");
    while (tokenID < parser->lexer->token_capacity){
        printf("%s ", enumToString[parser->lexer->tokens[tokenID++].type]);
    }
}