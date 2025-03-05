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

parseTreeNode* generateTreeNodeAncestor(treeList* children, treeData data) {
    parseTreeNode* node = malloc(sizeof(parseTreeNode));
    if (!node) { perror("malloc failed"); exit(1); }
    node->data = data;
    node->children = children;
    node->parent = NULL; // or set appropriately

    // Link each child’s parent pointer to the new node
    treeList* curr = children;
    while (curr != NULL) {
        if (curr->treeNode != NULL) {
            curr->treeNode->parent = node;
        }
        curr = curr->next;
    }
    return node;
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

treeList* generateList(Parser* parser, int treeListSize) {
    treeList* list = malloc(sizeof(treeList));
    if (!list) { perror("malloc failed"); exit(1); }
    list->treeNode = NULL;
    list->next = NULL;
    list->treeListSize = treeListSize;
    return listAssistantGenerator(parser, treeListSize, list);
}