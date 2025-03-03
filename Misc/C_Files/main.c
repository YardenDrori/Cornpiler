#include "../../Lexer/H_Files/lexer.h"
#include "../../Lexer/H_Files/token.h"
#include "../H_Files/util.h"
#include "../../Parser/H_Files/stack.h"
#include "../../Parser/H_Files/parser.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#define FILENAME "ExampleScript.txt"

void testLexer(){
    Lexer *lexer = initLexer(FILENAME);
    if (!lexer) {
        fprintf(stderr, "Failed to initialize lexer.\n");
    }
    getTokenList(lexer);
    printTokenArray(lexer);
    freeLexer(lexer);
}
Lexer* initTokenList(){
    Lexer *lexer = initLexer(FILENAME);
    if (!lexer) {
        fprintf(stderr, "Failed to initialize lexer.\n");
    }
    getTokenList(lexer);
    return lexer;
}






// Helper to create a new tree node with given data.
parseTreeNode* newNode(treeData data) {
    parseTreeNode* node = malloc(sizeof(parseTreeNode));
    if (!node) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->children = NULL;
    node->parent = NULL;
    return node;
}

// Helper to add a child node to a parent.
void addChild(parseTreeNode* parent, parseTreeNode* child) {
    treeList* newItem = malloc(sizeof(treeList));
    if (!newItem) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    newItem->treeNode = child;
    newItem->next = NULL;
    newItem->treeListSize = 1; // Set as needed
    child->parent = parent;

    // Insert at the end of the children list.
    if (parent->children == NULL) {
        parent->children = newItem;
    } else {
        treeList* current = parent->children;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newItem;
    }
}

int main() {
    // We'll use TOKEN_TREE_DATA_TYPE for all nodes.
    treeData data;
    data.dataType = TOKEN_TREE_DATA_TYPE;
    
    // Create leaf nodes.
    data.data.token.type = INT;  // [INT]
    parseTreeNode* nodeInt = newNode(data);

    data.data.token.type = IF;   // [IF]
    parseTreeNode* nodeIf = newNode(data);

    data.data.token.type = ELSE; // [ELSE]
    parseTreeNode* nodeElse = newNode(data);

    data.data.token.type = WHILE; // [WHILE]
    parseTreeNode* nodeWhile = newNode(data);

    // Create intermediate nodes.
    data.data.token.type = PLUS;  // [PLUS]
    parseTreeNode* nodePlus = newNode(data);
    addChild(nodePlus, nodeInt);
    addChild(nodePlus, nodeIf);

    data.data.token.type = MINUS; // [MINUS]
    parseTreeNode* nodeMinus = newNode(data);
    addChild(nodeMinus, nodeElse);
    addChild(nodeMinus, nodeWhile);

    // Create root node.
    data.data.token.type = EQUAL; // [EQUAL]
    parseTreeNode* root = newNode(data);
    addChild(root, nodePlus);
    addChild(root, nodeMinus);

    // Print the tree.
    printTree(root);

    // (Optional) Free allocated memory here.

    return 0;
}