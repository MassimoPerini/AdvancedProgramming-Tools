//
//  ArrayHashTable.h
//  AdvancedProgramming
//
//  Created by Massimo Perini on 09/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

	//METRO EXAMPLE
#include "IntLinkedList.h"

#ifndef ArrayHashTable_h
#define ArrayHashTable_h

typedef struct ArrayElement
{
	char *key;
	IntLinkedList *travels;

}ArrayElement;

typedef struct ArrayHashTable
{
	unsigned int nElements;
	unsigned int size;
	ArrayElement ** hashArray;
}ArrayHashTable;

ArrayHashTable *initArrayHashTable (unsigned int size);
ArrayElement *generateArrayHashTableElement ();
int insertInArrayHashTable (ArrayElement *el, ArrayHashTable *hashTable);
ArrayElement *getElementFromArrayHashTable (char *str, ArrayHashTable *hashTable);
void deleteAllArrayHashTable (ArrayHashTable *hashTable);


#endif /* ArrayHashTable_h */
