//
//  List.c
//  AdvancedProgramming
//
//  Created by Massimo Perini on 08/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#include <stdlib.h>
#include "IntLinkedList.h"
#include <string.h>

	//private functions

	//Creates a new element of the list and sets the pointer to NULL
static IntLinkedList *createEl ()
{
	IntLinkedList *new= (IntLinkedList *)malloc((sizeof(IntLinkedList)));
	if (new==NULL)
		return NULL;
	new->ptrNext=NULL;
	return new;
}

	//Like the previous function, but sets a new value
static IntLinkedList *createElWithValue(value val)	//Objective-C-like syntax (C doesn't support operator overloading :( )
{
	IntLinkedList *el=createEl();
	if (el==NULL)
		return NULL;
	el->val=val;
	return el;
}

	//Return the position of the pos-th element of the list
static IntLinkedList *seek (IntLinkedList *start, int pos)	//I can do it because I've declared the lengthLinkedList function inside the .h file
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
IntLinkedList *initIntLinkedList ()
{
	return createEl();
}

	//Like the previous one, but it can accept a value. Returns NULL if fails
IntLinkedList *initIntLinkedListWithValue (value val)
{
	return createElWithValue(val);
}
	//Returns the lengthLinkedList of the list
int lengthLinkedList (IntLinkedList *start)
{
	int count=0;
	while (start!=NULL){
		start=start->ptrNext;
		count++;
	}
	return count;
}

	//Insert a new value in a position of the list. It returns the head of the new list (or NULL if fails)
IntLinkedList *insertInPositionOfLinkedList (IntLinkedList *head, int position, value element)		//Manages also the case of position=0 (why create another function?)
{
	if (head==NULL)
		return createElWithValue(element);
	
	if (position==0)
	{
		IntLinkedList *newEl=createElWithValue(element);
		if (newEl==NULL)
			return NULL;
		newEl->ptrNext=head;
		return newEl;
	}
	int len=lengthLinkedList(head);
	if (len==position)
		return insertAtTheEndOfLinkedList(head, element);
	if (position<0 || position > lengthLinkedList(head))
		return NULL;
	
	IntLinkedList *toChangeIndex=seek(head, position-1);			//I have to change the pointer of the element before
	IntLinkedList *toMove=toChangeIndex->ptrNext;
	IntLinkedList *newEl=createElWithValue(element);
	if (newEl==NULL)
		return NULL;
	toChangeIndex->ptrNext=newEl;
	newEl->ptrNext=toMove;
	return head;						//If the program checks the return value, knows the result of the function
		
}

	//The function adds an element at the end of the list. Returns NULL if fails
IntLinkedList *insertAtTheEndOfLinkedList (IntLinkedList *head, IntLinkedList *newEl)		//Works also with head=NULL (creates the first element)
{
	if (newEl==NULL)
		return NULL;
	if(head==NULL)
		return newEl;
	
	IntLinkedList *tmpPtr=head;
	while (tmpPtr->ptrNext!=NULL)
	{
		tmpPtr=tmpPtr->ptrNext;
	}
	tmpPtr->ptrNext=newEl;
	return head;
	
}

	//The function change the value of the element in the specified position
int setValueOfLinkedList (IntLinkedList *head, int position, value newValue)
{
	if (position<0 || position >= lengthLinkedList(head))
		return -1;
	IntLinkedList *toChangeIndex=seek(head, position);
	toChangeIndex->val=newValue;
	return 0;
}

	//Returns the value of tne element in the specified position
IntLinkedList *getValueOfLinkedList (IntLinkedList *head, int position)
{
	if (position<0 || position >= lengthLinkedList(head))
		return NULL;
	return seek(head, position);
}

IntLinkedList *searchInIntLinkedList (IntLinkedList *head, value value)
{
	while (head!=NULL)
	{
			//METRO EXAMPLE
		if (strcmp(head->val,value)==0)
			return head;
		head=head->ptrNext;
	}
	return NULL;
}

int indexOfLinkedList (IntLinkedList *head, value value)
{
	int res=0;
	while (head!=NULL)
	{
			//METRO EXAMPLE
		if (strcmp(head->val,value)==0)
			return res;
		res++;
		head=head->ptrNext;
	}
	return -1;
	
}

	//Delete the element in the specified position (returns NULL if fails)
IntLinkedList *deleteInPositionOfLinkedList (IntLinkedList *head, int position)
{
	if (head==NULL)
		return NULL;
	if (position==0)
	{
		IntLinkedList *next=head->ptrNext;
		free(head);
		return next;
	}
	if (position<0 || position >= lengthLinkedList(head))
		return NULL;
	IntLinkedList *toChangeIndex=seek(head, position-1);				//I have to change the pointer of the element before
	IntLinkedList *toDelete=toChangeIndex->ptrNext;
	toChangeIndex->ptrNext=toDelete->ptrNext;
	free(toDelete);
	return head;
}

	//Delete the element at the end of the list (returns NULL if fails)
IntLinkedList *deleteAtTheEndOfLinkedList (IntLinkedList *head)
{
	return deleteInPositionOfLinkedList(head, lengthLinkedList(head)-1);
}

	//Delete the entire list
void deleteLinkedList (IntLinkedList *head)
{
	IntLinkedList *tmp=head;
	while (head!=NULL)
	{
		head=head->ptrNext;
		free(tmp);
		tmp=head;
	}
}
