#include <stdlib.h>
#include "token.h"
#include "parser_types.h"
#include "parser.h"
#include "parseTree.h"




parseTreeNode* generateTreeNode(treeData data){
    parseTreeNode* treeNode = (parseTreeNode*)malloc(sizeof(parseTreeNode));
    if (!treeNode){
        printf("Error allocating memory for tree node");
        exit(1);
    }
    treeNode->data = data;
    return treeNode;
}

parseTreeNode* generateTreeNodeAncestor(treeData ancestorData, treeList* childrenList){
    parseTreeNode *ancestor = generateTreeNode(ancestorData);
    ancestor->data = ancestorData;
    ancestor->children = childrenList;
    parseTreeNode *temp;
    temp = childrenList;
    for (int i = 0; i < childrenList->treeListSize; i++){
        temp->parent = ancestor;
        temp = childrenList->next;
    }
    free(temp);
    return ancestor;
}
