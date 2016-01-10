//
//  BinaryTree.h
//  AdvancedProgramming
//
//  Created by Massimo Perini on 07/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

typedef int value;

typedef struct Node
{
    value elem;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
    
}Node;

typedef struct BinaryTree{
    Node *head;
}BinaryTree;


extern BinaryTree *initBinaryTree ();
extern Node *searchInBinaryTree (value elem, BinaryTree *head);


#include <stdio.h>

#endif /* BinaryTree_h */
