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
    parseTreeNode* temp;
    parseTreeNode* parentNode = generateTreeNode(parentData);
    parentNode->parent = NULL;
    parentNode->firstChild = generateTreeSiblings(parser, childrenCount);
    temp = parentNode->firstChild;
    while (temp != NULL){
        temp->parent = parentNode;
        temp = temp->sibling;
    }
    return parentNode;
}


parseTreeNode* generateTreeSiblings(Parser* parser, int familySize){
    if (familySize == 0){
        return NULL;
    }
    StackValue value = popStackCount(parser->stack, 2);
    parseTreeNode* treeNode = generateTreeNode(value.data.treeNode->data);  //data
    treeNode->firstChild = value.data.treeNode->firstChild;                 //first child
    treeNode->parent = value.data.treeNode->parent;                         //parent
    treeNode->sibling = generateTreeSiblings(parser, familySize-1);         //sibling
    return treeNode;
}
