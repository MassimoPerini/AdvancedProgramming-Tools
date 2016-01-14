//
//  ArrayHashTable.h
//  AdvancedProgramming
//
//  Created by Massimo Perini on 09/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#ifndef ArrayHashTable2_h
#define ArrayHashTable2_h

/*
 PER USARE IL REFACTORING: copia-incolla dei file h e c. Cambia ifndef, define nel .h
 nel .c includi il nuovo .h, nel main importa il nuovo .h
 
 NON CAMBIARE NIENTE DELLE FUNZIONI STATIC
 */

typedef char *ArrayHashTableValue2;			//Val è il valore associato alla chiave, metti quello che vuoi (anche struct)

typedef struct ArrayHashTableElement2
{
	char *key;
	ArrayHashTableValue2 value;

}ArrayHashTableElement2;

typedef struct ArrayHashTable2
{
	unsigned int nElements;
	unsigned int size;
	ArrayHashTableElement2 ** hashArray;
}ArrayHashTable2;

extern ArrayHashTable2 *initArrayHashTable2 (unsigned int size);
extern ArrayHashTableElement2 *generateArrayHashTableElementWithKey2 (char *key);
extern int insertArrayHashTableElementInArrayHashTable2 (ArrayHashTableElement2 *el, ArrayHashTable2 *hashTable);
extern ArrayHashTableElement2 *generateArrayHashTableElementWithKeyAndValue2 (char *key, ArrayHashTableValue2 value);
extern ArrayHashTableElement2 *getArrayElementFromArrayHashTable2 (char *str, ArrayHashTable2 *hashTable);
extern void deleteAllArrayHashTable2 (ArrayHashTable2 *hashTable);
extern ArrayHashTableValue2 getValueFromHashTable2 (char *key, ArrayHashTable2 *hashTable);	// MARK: - gestire ritorno se manca elemento
extern void freeArrayHashTable2 (ArrayHashTable2 *hashTable);

#endif /* ArrayHashTable1_h */
