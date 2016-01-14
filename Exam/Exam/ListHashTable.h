//
//  ListHashTable.h
//  AdvancedProgramming
//
//  Created by Massimo Perini on 09/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#ifndef ListHashTable_h
#define ListHashTable_h

typedef int ListHashTableValue1;

typedef struct ListHashTableElement1
{
	char *key;
	struct ListHashTableElement1 *ptrNext;
	ListHashTableValue1 val;
	
}ListHashTableElement1;

typedef struct ListHashTable1
{
	unsigned int nElements;
	unsigned int size;
	ListHashTableElement1 ** hashArray;
}ListHashTable1;


extern ListHashTable1 *initListHashTable1 (unsigned int size);
extern ListHashTableElement1 *generateListHashTableElementWithKey1 (char *key);
extern ListHashTableElement1 *generateListHashTableElementWithKeyAndValue1 (char *key, ListHashTableValue1 val);

extern void deleteElementFromListHashTable1 (char *str, ListHashTable1 *hashTable);

extern void insertListHashTableElementInListHashTable1 (ListHashTableElement1 *el, ListHashTable1 *hashTable);
extern void insertListHashTableValueInListHashTable1 (ListHashTableValue1 val, char *key, ListHashTable1 *hashTable);


extern ListHashTableValue1 getValueFromListHashTable1 (char *str, ListHashTable1 *hashTable);
extern ListHashTableElement1 *getElementFromListHashTable (char *str, ListHashTable1 *hashTable); 	//GESTIRE CASO NON PRESENTE


extern void freeListHashTable1 (ListHashTable1 *hashTable);


#endif /* ListHashTable_h */
