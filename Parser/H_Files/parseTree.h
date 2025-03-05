#ifndef PARSETREE_H
#define PARSETREE_H

#include "../../Lexer/H_Files/token.h"
#include "parser_types.h"
#include <stdlib.h>

struct Parser;

typedef enum NodeType{
    NODE_TERMINAL,
    NODE_NONTERMINAL
} NodeType;

typedef struct treeData
{
    DataType dataType;
    union data
    {
        grammarSymbol symbol;
        Token token;
    } data;
} treeData;

typedef struct parseTreeNode{
    struct parseTreeNode* parent;
    treeData data;
    struct parseTreeNode* children;
    int childrenCount;
} parseTreeNode;

parseTreeNode* generateTreeChildren(struct Parser* parser, int childrenCount);
parseTreeNode* generateTreeNode(treeData data);
parseTreeNode* generateTreeAncestor(struct Parser* parser, int childrenCount, treeData parentData);
//parseTreeNode* generateTreeNodeAncestor(treeList* childrenList, treeData ancestorData);
//treeList* listAssistantGenerator(struct Parser* parser, int size);
//treeList* generateList(struct Parser* parser, int treeListSize);
#endif