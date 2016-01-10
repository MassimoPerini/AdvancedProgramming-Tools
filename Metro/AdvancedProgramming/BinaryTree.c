//
//  BinaryTree.c
//  AdvancedProgramming
//
//  Created by Massimo Perini on 07/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#include "BinaryTree.h"
#include <stdlib.h>

static Node *createNode (value val)
{
    Node *n=(Node *)malloc(sizeof(Node));
    n->parent=NULL;
    n->left=NULL;
    n->right=NULL;
    n->elem=val;
    return n;
}

	//Ricerca dalla posizione attuale
Node *successorBinaryTree(Node *n)
{
	if (n->right != NULL)
	{
		Node *temp=n->right;
		while (temp->left != NULL)
			temp=temp->left;
		return temp;
	}
	Node *temp=n->parent;
	while(temp!=NULL && temp->right==n)
	{
		n=temp;
		temp=temp->parent;
	}
	if (temp==NULL){        //Bugfix del codice della prof
		return n;
	}
	return temp;
}

Node *predecessorBinaryTree(Node *n)
{
	if (n->left != NULL)
	{
		Node *temp=n->left;
		while (temp->right != NULL)
			temp=temp->right;
		return temp;
	}
	Node *temp=n->parent;
	while(temp!=NULL && temp->left==n)
	{
		n=temp;
		temp=temp->parent;
	}
	if (temp==NULL){        //Bugfix del codice della prof
		return n;
	}
	return temp;
}

static void skipNode (BinaryTree *head, Node *toRemove, Node *succ)
{
	if(toRemove->parent == NULL)
		head->head = succ;
	else if(toRemove == toRemove->parent->right)
		toRemove->parent->right = succ;
	else
		toRemove->parent->left = succ;
 
	if(succ != NULL)
		succ->parent = toRemove->parent;
}

BinaryTree *initBinaryTree (value val){
    BinaryTree *bin=(BinaryTree *)malloc(sizeof(BinaryTree));
    bin->head=NULL;
    return bin;
}


value minimum (BinaryTree *head)
{
    Node *n=head->head;
    while (n->left!=NULL){
        n=n->left;
    }
    return n->elem;
}

value maximum (BinaryTree *head)
{
    Node *n=head->head;
    while (n->right!=NULL){
        n=n->right;
    }
    return n->elem;
}

Node *searchInBinaryTree (value elem, BinaryTree *head)
{
    Node *n=head->head;
    
    while (n!=NULL){
        if (elem==n->elem)
            return n;
        else if (elem>n->elem)
            n=n->right;
        else
            n=n->left;
    }
    return NULL;
}


value nextElementBinaryTree(BinaryTree *head, value element, int *success)
{
	Node *n=successorBinaryTree(searchInBinaryTree(element, head));
	if (n==NULL){
		*success=0;
		return -1;
	}
	*success=1;
    return n->elem;
}

value prevElementBinaryTree(BinaryTree *head, value element, int *success)
{
	Node *n=predecessorBinaryTree(searchInBinaryTree(element, head));
	if (n==NULL){
		*success=0;
		return -1;
	}
	*success=1;
	return n->elem;
}



//elementi sotto: dx e tutto sx

void insertInBinaryTree (value elem, BinaryTree *head)
{
    Node *n=createNode(elem);
    Node *test=head->head;
	if (test==NULL){
		head->head=n;
		return;
	}
	
	Node *insert=test;
	
	while (test!=NULL){
		insert=test;
		if (elem<test->elem)
			test=test->left;
		else
			test=test->right;
		}
	if (insert->elem > elem)
		insert->left=n;
	else
		insert->right=n;
    
}

void deleteFromBinaryTree (BinaryTree *head, value val)
{
	if (head==NULL) return;
	Node *n=searchInBinaryTree(val, head);
	if (n->left==NULL && n->right!=NULL)
		skipNode(head, n, NULL);
	else if (n->right==NULL && n->left!=NULL)
		skipNode(head, n, n->left);
	else if (n->left==NULL && n->right!=NULL)
		skipNode(head, n, n->right);
	else{
		Node *minNext=n->right;
		while (minNext->left!=NULL)
			minNext=minNext->left;
		if (minNext == n->right){		//No left pointer under right element
			skipNode(head, n, minNext);
			minNext->left=n->left;
			minNext->left->parent=minNext;
		}
		else
		{
			skipNode(head, minNext, minNext->right);
			minNext->right = n->right;
			minNext->right->parent = minNext;
			skipNode(head, n, minNext);
			minNext->left = n->left;
			minNext->left->parent = minNext;
		}
		
	}
	free(n);
}