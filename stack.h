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
Stack* initStack();
void stackPush(Stack* stack, StackValue value, StackType type);
void pushInt(Stack *stack, int value);
void pushToken(Stack *stack, Token token);
void pushSymbol(Stack *stack, grammarSymbol symbol);
StackValue popStack(Stack *stack);
int stackIsEmpty(Stack *stack);
void freeStack(Stack *stack);
StackValue popStackCount(Stack* stack, int count);

#endif