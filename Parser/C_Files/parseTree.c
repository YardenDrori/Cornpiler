#include <stdlib.h>
#include "../../Lexer/H_Files/token.h"
#include "../H_Files/parser_types.h"
#include "../H_Files/parser.h"
#include "../H_Files/parseTree.h"

parseTreeNode* generateTreeNode(treeData data){
    parseTreeNode* treeNode = (parseTreeNode*)malloc(sizeof(parseTreeNode));
    if (!treeNode){
        printf("Error allocating memory for tree node");
        exit(1);
    }
    treeNode->data = data;
    return treeNode;
}

parseTreeNode* generateTreeAncestor(Parser* parser, int childrenCount, treeData parentData){
    parseTreeNode* parent = (parseTreeNode*)malloc(sizeof(parseTreeNode));
    if (!parent){
        printf("Error allocating memory for parent tree node");
        exit(1);
    }
    parent->childrenCount = childrenCount;
    parent->data = parentData;
    parent->parent = NULL;
    parent->children = generateTreeChildren(parser, childrenCount);
    return parent;
}

parseTreeNode* generateTreeChildren(Parser* parser, int childrenCount){
    if (childrenCount == 0){
        return NULL;
    }
    StackValue value;
    parseTreeNode* node= (parseTreeNode*)malloc(sizeof(parseTreeNode)*childrenCount);
    if (!node){
        printf("Error allocating memory for tree node children");
        exit(1);
    }
    for (int i = childrenCount-1; i >= 0; i--){
        value = popStackCount(parser->stack, 2);
        node[i].data = value.data.treeNode->data;
        node[i].children = value.data.treeNode->children;
        node[i].childrenCount = value.data.treeNode->childrenCount;
        node[i].parent = NULL;
    }
    return node;    
}
