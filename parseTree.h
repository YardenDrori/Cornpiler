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

struct parseTreeNode;
typedef struct treeList
{
    struct parseTreeNode* treeNode;
    struct treeList* next;
    int treeListSize;
} treeList;

typedef union treeData
{
    grammarSymbol symbol;
    Token token;
} treeData;

typedef struct parseTreeNode{
    treeList *children;
    struct parseTreeNode* parent;
    treeData data;
} parseTreeNode;

parseTreeNode* generateTreeNode(treeData data);
parseTreeNode* generateTreeNodeAncestor(treeList* childrenList, treeData ancestorData);
treeList* listAssistantGenerator(struct Parser* parser, int size, treeList* list);
treeList* generateList(struct Parser *parser, int size);
#endif