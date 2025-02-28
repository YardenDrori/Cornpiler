#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "token.h"
#include "parser.h"

// Stack element type
typedef enum {
    STACK_INT,
    STACK_TOKEN,
    STACK_SYMBOL
} StackType;

typedef struct {
    StackType type;
    union {
        int intValue;
        Token tokenValue;
        grammarSymbol symbolValue;
    } data;
} StackValue;

// Stack node
typedef struct StackNode {
    StackValue value;
    StackType type;
    struct StackNode *next;
} StackNode;

// Stack structure
typedef struct {
    StackNode *top;
} Stack;

// Function prototypes
Stack* stack_init();
void stack_push_int(Stack *stack, int value);
void stack_push_token(Stack *stack, Token token);
void stack_push_symbol(Stack *stack, grammarSymbol symbol);
StackValue stack_pop(Stack *stack);
int stack_is_empty(Stack *stack);
void stack_free(Stack *stack);

#endif