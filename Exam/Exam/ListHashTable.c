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

static ListHashTableElement1 *solveConflict(char *key, ListHashTableElement1 *head)		//If key==NULL, get the last element
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

static void freeList (ListHashTableElement1 *list)
{
	if (list==NULL)
		return;
	ListHashTableElement1 *prev;
	while (list!=NULL)
	{
		prev=list;
		list=list->ptrNext;
		free(prev);
	}
}

static ListHashTableElement1 *generateListHashTableElement ()
{
	ListHashTableElement1 *el=malloc(sizeof(ListHashTableElement1));
	if (el==NULL) return NULL;
	el->ptrNext=NULL;
	return el;
}

ListHashTable1 *initListHashTable1 (unsigned int size)
{
	ListHashTable1 *new=malloc(sizeof(ListHashTable1));
	if (new==NULL) return NULL;
	ListHashTableElement1 **arr=calloc(size, sizeof(ListHashTableElement1 *));		//NULL pointer inizializer
	if (arr==NULL) return NULL;
	new->hashArray=arr;
	new->nElements=0;
	new->size=size;
	return new;
}

ListHashTableElement1 *generateListHashTableElementWithKey1 (char *key)
{
	ListHashTableElement1 *el=generateListHashTableElement();
	if (el==NULL) return NULL;
	el->key=key;
	return el;
}

ListHashTableElement1 *generateListHashTableElementWithKeyAndValue1 (char *key, ListHashTableValue1 val)
{
	ListHashTableElement1 *el=generateListHashTableElement();
	if (el==NULL) return NULL;
	el->val=val;
	el->key=key;
	return el;
}


void deleteElementFromListHashTable1 (char *str, ListHashTable1 *hashTable)
{
	if (str==NULL) return;
	unsigned int pos=generatePosition(str, hashTable->size);
	ListHashTableElement1 *firstElement=hashTable->hashArray[pos];
	if (firstElement==NULL) return;
	ListHashTableElement1 *prevEl=firstElement;
	
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


void insertInListHashTable (ListHashTableElement1 *el, ListHashTable1 *hashTable)
{
	if (el->key==NULL) return;
	el->ptrNext=NULL;												//Avoid possible problems
	unsigned int pos=generatePosition(el->key, hashTable->size);
	if (hashTable->hashArray[pos]==NULL)
		hashTable->hashArray[pos]=el;
	else
	{
		deleteElementFromListHashTable1(el->key, hashTable);				//If exist another element with the same key, remove it
		if (hashTable->hashArray[pos]==NULL)
			hashTable->hashArray[pos]=el;
		else{
		ListHashTableElement1 *last=solveConflict(NULL, hashTable->hashArray[pos]);
		last->ptrNext=el;
		}
	}
	hashTable->nElements++;
}

void insertListHashTableValueInListHashTable1 (ListHashTableValue1 val, char *key, ListHashTable1 *hashTable)
{
	ListHashTableElement1 *el=generateListHashTableElementWithKeyAndValue1(key, val);
	if (el==NULL) return;
	insertInListHashTable(el, hashTable);
}


	//Return NULL if it can't find the element, otherwise it returns the pointer to the element
ListHashTableElement1 *getElementFromListHashTable (char *str, ListHashTable1 *hashTable)
{
	if (str==NULL) return NULL;
	unsigned int pos=generatePosition(str, hashTable->size);
	ListHashTableElement1 *firstElement=hashTable->hashArray[pos];
	if (firstElement==NULL) return NULL;
	return solveConflict(str, firstElement);
}

ListHashTableValue1 getValueFromListHashTable1 (char *str, ListHashTable1 *hashTable)
{
	ListHashTableElement1 *el=getElementFromListHashTable(str, hashTable);
	if (el==NULL)
	{
			//GESTIRE CASO NON PRESENTE
	}
	return el->val;
}


void freeListHashTable1 (ListHashTable1 *hashTable)
{
	int i=0;
	for (;i<hashTable->size;i++)
	{
		freeList(hashTable->hashArray[i]);
	}
	
	free(hashTable->hashArray);
	hashTable->hashArray=NULL;
}