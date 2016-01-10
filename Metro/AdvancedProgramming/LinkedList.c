//
//  GenericLinkedList.c
//  AdvancedProgramming
//
//  Created by Massimo Perini on 09/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#include "LinkedList.h"

#include <stdlib.h>
#include "LinkedList.h"

	//private functions

	//Creates a new element of the list and sets the pointer to NULL
/*
static LinkedList *createEl ()
{
	LinkedList *new= (LinkedList *)malloc((sizeof(LinkedList)));
	if (new==NULL)
		return NULL;
	new->ptrNext=NULL;
	return new;
}

	//Like the previous function, but sets a new value
static LinkedList *createElWithValue(value val)	//Objective-C-like syntax (C doesn't support operator overloading :( )
{
	LinkedList *el=createEl();
	if (el==NULL)
		return NULL;
	el->val=val;
	return el;
}

	//Return the position of the pos-th element of the list
static LinkedList *seek (LinkedList *start, int pos)	//I can do it because I've declared the length function inside the .h file
{
	int i=0;
	while (i<pos){
		start=start->ptrNext;
		i++;
	}
	return start;
}

	//public functions

	//This function creates a new list (or element). Returns NULL if fails
LinkedList *init ()
{
	return createEl();
}

	//Like the previous one, but it can accept a value. Returns NULL if fails
LinkedList *initWithValue (value val)
{
	return createElWithValue(val);
}
	//Returns the length of the list
int length (LinkedList *start)
{
	int count=0;
	while (start!=NULL){
		start=start->ptrNext;
		count++;
	}
	return count;
}

	//Insert a new value in a position of the list. It returns the head of the new list (or NULL if fails)
LinkedList *insertInPosition (LinkedList *head, int position, value element)		//Manages also the case of position=0 (why create another function?)
{
	if (head==NULL)
		return createElWithValue(element);
	
	if (position==0)
	{
		LinkedList *newEl=createElWithValue(element);
		if (newEl==NULL)
			return NULL;
		newEl->ptrNext=head;
		return newEl;
	}
	if (position<0 || position >= length(head))
		return NULL;
	LinkedList *toChangeIndex=seek(head, position-1);			//I have to change the pointer of the element before
	LinkedList *toMove=toChangeIndex->ptrNext;
	LinkedList *newEl=createElWithValue(element);
	if (newEl==NULL)
		return NULL;
	toChangeIndex->ptrNext=newEl;
	newEl->ptrNext=toMove;
	return head;						//If the program checks the return value, knows the result of the function
	
}

	//The function adds an element at the end of the list. Returns NULL if fails
LinkedList *insertAtTheEnd (LinkedList *head, value element)		//Works also with head=NULL (creates the first element)
{
	int size=length(head);
	return insertInPosition(head, size-1, element);
}

	//The function change the value of the element in the specified position
int setValue (LinkedList *head, int position, value newValue)
{
	if (position<0 || position >= length(head))
		return -1;
	LinkedList *toChangeIndex=seek(head, position);
	toChangeIndex->val=newValue;
	return 0;
}

	//Returns the value of tne element in the specified position
value getValue (LinkedList *head, int position)
{
	if (position<0 || position >= length(head))
		return -1;
	LinkedList *readIndex=seek(head, position);
	return readIndex->val;
}

int indexOf (LinkedList *head, value value)
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

	//Delete the element in the specified position (returns NULL if fails)
LinkedList *deleteInPosition (LinkedList *head, int position)
{
	if (head==NULL)
		return NULL;
	if (position==0)
	{
		LinkedList *next=head->ptrNext;
		free(head);
		return next;
	}
	if (position<0 || position >= length(head))
		return NULL;
	LinkedList *toChangeIndex=seek(head, position-1);				//I have to change the pointer of the element before
	LinkedList *toDelete=toChangeIndex->ptrNext;
	toChangeIndex->ptrNext=toDelete->ptrNext;
	free(toDelete);
	return head;
}

	//Delete the element at the end of the list (returns NULL if fails)
LinkedList *deleteAtTheEnd (LinkedList *head)
{
	return deleteInPosition(head, length(head)-1);
}

	//Delete the entire list
void deleteList (LinkedList *head)
{
	LinkedList *tmp=head;
	while (head!=NULL)
	{
		head=head->ptrNext;
		free(tmp);
		tmp=head;
	}
}
*/