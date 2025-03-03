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

parseTreeNode* generateTreeNodeAncestor(treeList* childrenList ,treeData ancestorData){
    parseTreeNode *ancestor = generateTreeNode(ancestorData);
    ancestor->data = ancestorData;
    ancestor->children = childrenList;
    parseTreeNode *temp;
    temp = childrenList->treeNode;
    for (int i = 0; i < childrenList->treeListSize; i++){
        temp->parent = ancestor;
        temp = childrenList->next->treeNode;
    }
    free(temp);
    return ancestor;
}


treeList* listAssistantGenerator(Parser* parser, int size, treeList* list){
    if (size == 0){
        return NULL;
    }
    treeList* list2 = (treeList*)malloc(sizeof(treeList));
    if (!list2){
        printf("Error allocating memory for TreeList");
        exit(1);
    }
    
    list->next = list2;
    StackValue stackValue;
    parseTreeNode* treeNode;
    stackValue = popStackCount(parser->stack, 2);
    treeNode = stackValue.data.treeNode;
    list2->treeListSize = size;
    list2->treeNode = treeNode;
    list2->next = listAssistantGenerator(parser, size-1, list2);
    
    return list2;
}

treeList* generateList(Parser *parser, int size){
    treeList* list = (treeList*)malloc(sizeof(treeList));
    if (!list){
        printf("Error allocating memory for TreeList");
        exit(1);
    }
    treeList returnVal;
    returnVal.next = list->next;
    free(list);
    return returnVal.next;
}