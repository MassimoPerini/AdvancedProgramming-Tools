//
//  ArrayHashTable.c
//  AdvancedProgramming
//
//  Created by Massimo Perini on 09/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#include "ArrayHashTable2.h"
#include <stdlib.h>
#include <string.h>

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
}

static int solveConflict (unsigned int pos, char *key, ArrayHashTable2 *hashTable)
{
	if (key==NULL)										//Find a free position from free
	{
		int i=pos;
		while (i<hashTable->size && hashTable->hashArray[i]!=NULL)			//Skip from position
			i++;
		if (i<hashTable->size)
			return i;
		i=0;
		while (i<pos && hashTable->hashArray[i]!=NULL)
			i++;
		if (i<pos)
			return i;
		return -1;													//Array FULL
	}
	int i=pos;
	while ((i<hashTable->size) && (hashTable->hashArray[i]==NULL || (strcmp(key, hashTable->hashArray[i]->key) != 0)))
		   i++;
	if (i<hashTable->size)
		return i;
	i=0;
	while ((i<pos) && (hashTable->hashArray[i]==NULL || (strcmp(key, hashTable->hashArray[i]->key) != 0)))
		i++;
	if (i<pos)
		return i;
	return -1;						//Not found
}

static int changeSameKey (char *key, ArrayHashTable2 *hashTable, ArrayHashTableElement2 *element)
{
	unsigned int pos=generatePosition(key, hashTable->size);
	ArrayHashTableElement2 *try=hashTable->hashArray[pos];
	if (try==NULL) return -1;
	int newIndex=solveConflict(pos, key, hashTable);
	if (newIndex==-1)
		return -1;
	free(hashTable->hashArray[newIndex]);
	hashTable->hashArray[newIndex]=element;
	return 1;
}

static ArrayHashTableElement2 *createArrayHashTableElement ()
{
	ArrayHashTableElement2 *el=malloc(sizeof(ArrayHashTableElement2));
	return el;
}

	//FINE FUNZIONI STATIC

ArrayHashTable2 *initArrayHashTable2 (unsigned int size)
{
	ArrayHashTable2 *new=malloc(sizeof(ArrayHashTable2));
	if (new==NULL) return NULL;
	ArrayHashTableElement2 **arr=calloc(size, sizeof(ArrayHashTableElement2 *));		//NULL pointer inizializer
	if (arr==NULL) return NULL;
	new->hashArray=arr;
	new->nElements=0;
	new->size=size;
	return new;
}


ArrayHashTableElement2 *generateArrayHashTableElementWithKey2 (char *key)
{
	ArrayHashTableElement2 *el=createArrayHashTableElement();
	el->key=key;
	return el;
}

ArrayHashTableElement2 *generateArrayHashTableElementWithKeyAndValue2 (char *key, ArrayHashTableValue2 value)
{
	ArrayHashTableElement2 *el=createArrayHashTableElement();
	el->key=key;
	el->value=value;
	return el;
}
	//-1 if the array is full, 1 if the item was already present (it will be changed), 0 otherwise
int insertArrayHashTableElementInArrayHashTable2 (ArrayHashTableElement2 *el, ArrayHashTable2 *hashTable)
{
	if (el==NULL) return -1;
	unsigned int pos=generatePosition(el->key, hashTable->size);
	if (hashTable->hashArray[pos]==NULL)
		hashTable->hashArray[pos]=el;
	else
	{
		if (changeSameKey(el->key, hashTable, el)!=-1)
			return 1;
		int newIndex=solveConflict(pos, NULL, hashTable);
		if (newIndex==-1)
			return -1;
		hashTable->hashArray[newIndex]=el;
	}
	hashTable->nElements++;
	return 0;
}

	//Null if not present
ArrayHashTableElement2 *getArrayElementFromArrayHashTable2 (char *str, ArrayHashTable2 *hashTable)
{
	if (str==NULL) return NULL;
	unsigned int pos=generatePosition(str, hashTable->size);
	ArrayHashTableElement2 *try=hashTable->hashArray[pos];
	if (try==NULL) return NULL;
	int newIndex=solveConflict(pos, str, hashTable);
	if (newIndex==-1)
		return NULL;
	return hashTable->hashArray[newIndex];
}

ArrayHashTableValue2 getValueFromHashTable2 (char *key, ArrayHashTable2 *hashTable)
{
	ArrayHashTableElement2 *el=getArrayElementFromArrayHashTable2(key, hashTable);
	if (el==NULL)
	{
		// MARK: - gestire ritorno se manca elemento
	}
	return el->value;
}

void freeArrayHashTable2 (ArrayHashTable2 *hashTable)
{
	int i=0;
	for (;i<hashTable->size;i++)
	{
		free(hashTable->hashArray[i]);
	}
	free(hashTable->hashArray);
	hashTable->hashArray=NULL;
}