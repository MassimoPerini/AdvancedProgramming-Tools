//
//  ListHashTable.h
//  AdvancedProgramming
//
//  Created by Massimo Perini on 09/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#ifndef ListHashTable_h
#define ListHashTable_h

#include <stdio.h>


typedef struct ListElement
{
		//METRO EXAMPLE
	char *from;
	char *to;
	unsigned long nTimes;
		//----------
	char *key;
	struct ListElement *ptrNext;
}ListElement;

typedef struct ListHashTable
{
	unsigned int nElements;
	unsigned int size;
	ListElement ** hashArray;
}ListHashTable;


extern ListHashTable *initListHashTable (unsigned int size);
extern ListElement *generateListHashTableElement ();
extern void deleteElementFromListHashTable (char *str, ListHashTable *hashTable);
extern void insertInListHashTable (ListElement *el, ListHashTable *hashTable);
extern ListElement *getElementFromListHashTable (char *str, ListHashTable *hashTable);
extern void deleteAllListHashTable (ListHashTable *hashTable);


#endif /* ListHashTable_h */
