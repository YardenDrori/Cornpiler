#include "stack.h"
#include "token.h"
#include "parser.h"
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

void stackPush(Stack* stack, StackValue value, StackType type) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (!newNode) {
        fprintf(stderr, "Stack overflow!\n");
        exit(1);
    }
    newNode->value = value;
    newNode->type = type;
    newNode->next = stack->top;
    stack->top = newNode;
}

void pushInt(Stack* stack, int value) {
    StackValue v;
    v.data.intValue = value;
    stackPush(stack, v, STACK_INT);
}

void pushToken(Stack* stack, Token token) {
    StackValue v;
    v.data.tokenValue = token;
    stackPush(stack, v, STACK_TOKEN);
}

void pushSymbol(Stack* stack, grammarSymbol symbol) {
    StackValue v;
    v.data.symbolValue = symbol;
    stackPush(stack, v, STACK_SYMBOL);
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





TreeStack* treeStackInit(){
    TreeStack *stack = (TreeStack*)malloc(sizeof(TreeStack));
    if (!stack) {
        fprintf(stderr, "Error allocating memory for stack in stack_init\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}
void treeStackPush(TreeStack* stack, parseTreeNode* data){
    TreeStackNode* newNode = (TreeStackNode*)malloc(sizeof(TreeStackNode));
    if (!newNode) {
        fprintf(stderr, "Stack overflow!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}
parseTreeNode* treePopStack(TreeStack *stack){
    if (stack->top == NULL) {
        fprintf(stderr, "Stack underflow!\n");
        exit(1);
    }
    TreeStackNode* temp = stack->top;
    parseTreeNode* value = temp->data;
    stack->top = temp->next;
    free(temp);
    free(value);
    return value;
}
int treeStackIsEmpty(TreeStackNode *stack){
    return stack->top == NULL;
}
void treeFreeStack(TreeStackNode *stack){
    while (!stackIsEmpty(stack)) {
        free(treePopStack(stack));
    }
    free(stack);
}