//
//  ListHashTable.c
//  AdvancedProgramming
//
//  Created by Massimo Perini on 09/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#include "ListHashTable.h"
#include <stdlib.h>
#include <string.h>


	//XOR djb2 hashing
static unsigned long generateHashFromString (char *str)
{
	unsigned long hash = 5381;
	int c;
	while ((c = *str++))
		hash = ((hash << 5) + hash) ^ c; // hash(i - 1) * 33 ^ str[i]
	return hash;
}

static unsigned int generatePosition (char *str, unsigned int size)
{
		return (generateHashFromString(str)%size);
	return 1;
}

	//If key==NULL, get the last element (allowing insert), otherwise search the element

static ListElement *solveConflict(char *key, ListElement *head)		//If key==NULL, get the last element
{
	if (key==NULL)
	{
		while(head->ptrNext!=NULL)
			head=head->ptrNext;
		return head;
	}
	while (head!=NULL)
	{
		if (strcmp(head->key, key)==0)
			return head;
		head=head->ptrNext;
	}
	return head;	//Head==NULL means not found
}

static void freeList (ListElement *list)
{
	if (list==NULL)
		return;
	ListElement *prev;
	while (list!=NULL)
	{
		prev=list;
		list=list->ptrNext;
		free(prev);
	}
}

ListHashTable *initListHashTable (unsigned int size)
{
	ListHashTable *new=malloc(sizeof(ListHashTable));
	if (new==NULL) return NULL;
	ListElement **arr=calloc(size, sizeof(ListElement *));		//NULL pointer inizializer
	if (arr==NULL) return NULL;
	new->hashArray=arr;
	new->nElements=0;
	new->size=size;
	return new;
}

ListElement *generateListHashTableElement ()
{
	ListElement *el=malloc(sizeof(ListElement));
	el->ptrNext=NULL;
	return el;
}

void deleteElementFromListHashTable (char *str, ListHashTable *hashTable)
{
	if (str==NULL) return;
	unsigned int pos=generatePosition(str, hashTable->size);
	ListElement *firstElement=hashTable->hashArray[pos];
	if (firstElement==NULL) return;
	ListElement *prevEl=firstElement;
	
	while (firstElement->ptrNext!=NULL && strcmp(firstElement->key, str)!=0)
	{
		prevEl=firstElement;
		firstElement=firstElement->ptrNext;
	}
	if (strcmp(firstElement->key, str)==0)
	{
		if (prevEl==firstElement)
			hashTable->hashArray[pos]=firstElement->ptrNext;
		else
			prevEl->ptrNext=firstElement->ptrNext;
		free(firstElement);
		hashTable->nElements--;

	}
	
}

void insertInListHashTable (ListElement *el, ListHashTable *hashTable)
{
	if (el->key==NULL) return;
	el->ptrNext=NULL;												//Avoid possible problems
	unsigned int pos=generatePosition(el->key, hashTable->size);
	if (hashTable->hashArray[pos]==NULL)
		hashTable->hashArray[pos]=el;
	else
	{
		deleteElementFromListHashTable(el->key, hashTable);				//If exist another element with the same key, remove it
		if (hashTable->hashArray[pos]==NULL)
			hashTable->hashArray[pos]=el;
		else{
		ListElement *last=solveConflict(NULL, hashTable->hashArray[pos]);
		last->ptrNext=el;
		}
	}
	hashTable->nElements++;
}

	//Return NULL if it can't find the element, otherwise it returns the pointer to the element
ListElement *getElementFromListHashTable (char *str, ListHashTable *hashTable)
{
	if (str==NULL) return NULL;
	unsigned int pos=generatePosition(str, hashTable->size);
	ListElement *firstElement=hashTable->hashArray[pos];
	if (firstElement==NULL) return NULL;
	return solveConflict(str, firstElement);
}

void deleteAllListHashTable (ListHashTable *hashTable)
{
	int i=0;
	for (;i<hashTable->size;i++)
	{
		freeList(hashTable->hashArray[i]);
	}
	
	free(hashTable->hashArray);
	hashTable->hashArray=NULL;
}