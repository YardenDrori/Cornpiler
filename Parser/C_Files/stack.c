#include "../H_Files/stack.h"
#include "../../Lexer/H_Files/token.h"
#include "../H_Files/parser.h"
#include <stdio.h>
#include <stdlib.h>

Stack* initStack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        fprintf(stderr, "Error allocating memory for stack in stack_init\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

void stackPush(Stack* stack, StackValue value) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (!newNode) {
        fprintf(stderr, "Stack overflow!\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

void pushInt(Stack* stack, int value) {
    StackValue v;
    v.data.intValue = value;
    v.dataType = NUMBER_DATA_TYPE;
    stackPush(stack, v);
}

void pushToken(Stack* stack, Token token) {
    StackValue v;
    treeData data;
    data.data.token = token;
    data.dataType = TOKEN_DATA_TYPE;
    v.data.treeNode = generateTreeNode(data);
    v.dataType = TOKEN_DATA_TYPE;
    stackPush(stack, v);
}

void pushSymbol(Stack* stack, grammarSymbol symbol) {
    StackValue v;
    treeData data;
    data.data.symbol = symbol;
    data.dataType = GRAMMER_SYMBOL_DATA_TYPE;
    v.data.treeNode = generateTreeNode(data);
    v.dataType = GRAMMER_SYMBOL_DATA_TYPE;
    stackPush(stack, v);
}

void pushTreeNode(Stack* stack, parseTreeNode *node) {
    StackValue v;
    v.dataType = node->data.dataType;
    v.data.treeNode = node;
    stackPush(stack, v);
}

StackValue popStack(Stack* stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Stack underflow!\n");
        exit(1);
    }
    StackNode* temp = stack->top;
    StackValue value = temp->value;
    stack->top = temp->next;
    free(temp);
    return value;
}

StackValue getStackValue(Stack* stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Stack underflow!\n");
        exit(1);
    }
    StackValue value;
    value.data = stack->top->value.data;
    value.dataType = stack->top->value.dataType;

    return value;
}

int stackIsEmpty(Stack* stack) {
    return stack->top == NULL;
}

void freeStack(Stack* stack) {
    while (!stackIsEmpty(stack)) {
        popStack(stack);
    }
    free(stack);
}

//pop count values and returns the last one popped
StackValue popStackCount(Stack* stack, int count){
    for (int i = 0; i < count-1; i++){
        popStack(stack);
        
    }
    return popStack(stack);
}