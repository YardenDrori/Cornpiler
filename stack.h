#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "token.h"
#include "parser_types.h"
#include "parseTree.h"



typedef struct {
    union {
        int intValue;
        parseTreeNode* treeNode;
    } data;
} StackValue;

typedef struct StackNode {
    StackValue value;
    struct StackNode *next;
} StackNode;

// Stack structure
typedef struct Stack{
    StackNode *top;
} Stack;

// Function prototypes
Stack* initStack();
void stackPush(Stack* stack, StackValue value);
void pushInt(Stack *stack, int value);
void pushToken(Stack *stack, Token token);
void pushSymbol(Stack *stack, grammarSymbol symbol);
StackValue popStack(Stack *stack);
int stackIsEmpty(Stack *stack);
void freeStack(Stack *stack);
StackValue popStackCount(Stack* stack, int count);
void pushTreeNode(Stack* stack, parseTreeNode *node);
#endif