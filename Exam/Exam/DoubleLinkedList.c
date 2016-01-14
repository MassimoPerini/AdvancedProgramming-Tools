//
//  DoubleLinkedList.c
//  AdvancedProgramming
//
//  Created by Massimo Perini on 09/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#include <stdlib.h>

#include "DoubleLinkedList.h"

static DoubleLinkedList *createEl ()
{
	DoubleLinkedList *new= (DoubleLinkedList *)malloc((sizeof(DoubleLinkedList)));
	if (new == NULL)
		return NULL;
	new->ptrNext=NULL;
	new->ptrPrev=NULL;
	
	return new;
}

static DoubleLinkedList *createElWithValue(value val)	//Objective-C-like syntax (C doesn't support operator overloading :( )
{
	DoubleLinkedList *el=createEl();
	if (el==NULL)
		return NULL;
	el->val=val;
	return el;
}

	//Go to the pos-th element of the list
static DoubleLinkedList *seek (DoubleLinkedList *start, int pos)	//I can do it because I've declared the length function inside the .h file
{
	int i=0;
	while (i<pos){
		start=start->ptrNext;
		i++;
	}
	return start;
}

static DoubleLinkedList *seekReverse (DoubleLinkedList *start, int pos)
{
	int i=0;
	while (i<pos){
		start=start->ptrPrev;
		i++;
	}
	return start;
}


	//public functions

DoubleLinkedList *init ()
{
	return createEl();
}

DoubleLinkedList *initWithValue (value val)
{
	return createElWithValue(val);
}

int length (DoubleLinkedList *start)
{
	int count=0;
	while (start!=NULL){
		start=start->ptrNext;
		count++;
	}
	return count;
}

DoubleLinkedList *insertInPosition (DoubleLinkedList *head, int position, value element)		//Manages also the case of position=0 (why create another function?)
{
	if (head==NULL)
		return createElWithValue(element);
	
	if (position==0)
	{
		DoubleLinkedList *newEl=createElWithValue(element);
		if (newEl==NULL)
			return NULL;
		newEl->ptrNext=head;
		head->ptrPrev=newEl;
		return newEl;
	}
	if (position<0 || position >= length(head))
		return NULL;
	DoubleLinkedList *toChangeIndex=seek(head, position-1);			//I have to change the pointer of the element before
	DoubleLinkedList *toMove=toChangeIndex->ptrNext;
	DoubleLinkedList *newEl=createElWithValue(element);
	if (newEl==NULL)
		return NULL;
	toChangeIndex->ptrNext=newEl;
	newEl->ptrPrev=toChangeIndex;
	newEl->ptrNext=toMove;
	toMove->ptrPrev=newEl;
	return head;						//If the program checks the return value, knows the result of the function
	
}

DoubleLinkedList *insertAtTheEnd (DoubleLinkedList *head, value element)		//Works also with head=NULL (creates the first element)
{
	int size=length(head);
	return insertInPosition(head, size-1, element);
}

int setValue (DoubleLinkedList *head, int position, value newValue)
{
	if (position<0 || position >= length(head))
		return -1;
	DoubleLinkedList *toChangeIndex=seek(head, position);
	toChangeIndex->val=newValue;
	return 0;
}

value getValue (DoubleLinkedList *head, int position)
{
	if (position<0 || position >= length(head))
		return -1;
	DoubleLinkedList *readIndex=seek(head, position);
	return readIndex->val;
}

int indexOf (DoubleLinkedList *head, value value)
{
	int res=0;
	while (head!=NULL)
	{
		if (head->val==value)
			return res;
		res++;
		head=head->ptrNext;
	}
	return -1;
	
}

DoubleLinkedList *deleteInPosition (DoubleLinkedList *head, int position)
{
	if (head==NULL)
		return NULL;
	if (position==0)
	{
		DoubleLinkedList *next=head->ptrNext;
		if(next!=NULL)
			next->ptrPrev=NULL;
		free(head);
		return next;
	}
	if (position<0 || position >= length(head))
		return NULL;
	DoubleLinkedList *toChangeIndex=seek(head, position-1);				//I have to change the pointer of the element before
	DoubleLinkedList *toDelete=toChangeIndex->ptrNext;
	DoubleLinkedList *next=toDelete->ptrNext;
	toChangeIndex->ptrNext=next;
	if (next!=NULL)
		next->ptrPrev=toChangeIndex;
	free(toDelete);
	return head;
}

DoubleLinkedList *deleteAtTheEnd (DoubleLinkedList *head)
{
	return deleteInPosition(head, length(head)-1);
}

int isEmpty (DoubleLinkedList *head)
{
	if (head==NULL)
		return 1;
	return 0;
}

void deleteList (DoubleLinkedList *head)
{
	DoubleLinkedList *tmp=head;
	while (head!=NULL)
	{
		head=head->ptrNext;
		free(tmp);
		tmp=head;
	}
}