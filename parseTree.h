#ifndef PARSETREE_H
#define PARSETREE_H

#include "token.h"
#include "parser_types.h"
#include <stdlib.h>

struct Parser;

typedef enum NodeType{
    NODE_TERMINAL,
    NODE_NONTERMINAL
} NodeType;


typedef struct parseTreeNode;
typedef struct treeList
{
    parseTreeNode* treeNode;
    treeList* next;
    int treeListSize;
} treeList;

typedef union treeData
{
    grammarSymbol symbol;
    Token token;
} treeData;

typedef struct parseTreeNode{
    treeList *children;
    parseTreeNode* parent;
    treeData data;
} parseTreeNode;

parseTreeNode* generateTreeNode(treeData data);


#endif