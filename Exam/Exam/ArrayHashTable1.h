//
//  ArrayHashTable.h
//  AdvancedProgramming
//
//  Created by Massimo Perini on 09/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#ifndef ArrayHashTable1_h
#define ArrayHashTable1_h

typedef int ArrayHashTableValue1;			//Val è il valore associato alla chiave, metti quello che vuoi (anche struct)

typedef struct ArrayHashTableElement
{
	char *key;
	ArrayHashTableValue1 value;

}ArrayHashTableElement1;

typedef struct ArrayHashTable
{
	unsigned int nElements;
	unsigned int size;
	ArrayHashTableElement1 ** hashArray;
}ArrayHashTable1;

extern ArrayHashTable1 *initArrayHashTable1 (unsigned int size);
extern ArrayHashTableElement1 *generateArrayHashTableElementWithKey1 (char *key);
extern ArrayHashTableElement1 *generateArrayHashTableElementWithKeyAndValue1 (char *key, ArrayHashTableValue1 value);
extern int insertArrayHashTableElementInArrayHashTable1 (ArrayHashTableElement1 *el, ArrayHashTable1 *hashTable);
extern ArrayHashTableElement1 *getArrayElementFromArrayHashTable1 (char *str, ArrayHashTable1 *hashTable);
extern void deleteAllArrayHashTable1 (ArrayHashTable1 *hashTable);
extern ArrayHashTableValue1 getValueFromHashTable1 (char *key, ArrayHashTable1 *hashTable);	// MARK: - gestire ritorno se manca elemento
extern void freeArrayHashTable1 (ArrayHashTable1 *hashTable);
extern int insertArrayHashTableElementInArrayHashTable1 (ArrayHashTableElement1 *el, ArrayHashTable1 *hashTable);

#endif /* ArrayHashTable1_h */
