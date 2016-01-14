//
//  main.c
//  Exam
//
//  Created by Massimo Perini on 15/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#include <stdio.h>

#include "ArrayHashTable1.h"
#include "ArrayHashTable2.h"



int main(int argc, const char * argv[]) {
	// insert code here...
	
	ArrayHashTable1 *hashTable1=initArrayHashTable1(20);
	ArrayHashTable2 *hashTable2=initArrayHashTable2(50);
	
	ArrayHashTableElement1 *el1=generateArrayHashTableElementWithKeyAndValue1("chiave1", 2);
	ArrayHashTableElement2 *el2=generateArrayHashTableElementWithKeyAndValue2("chiave2", "contenuto");
	
	insertArrayElementInArrayHashTable2() (el1, hashTable1);
	insertArrayElementInArrayHashTable2(el2, hashTable2);
	
	printf("%d", getValueFromHashTable1("chiave1", hashTable1));
	printf("%s", getValueFromHashTable2("chiave2", hashTable2));
	
    return 0;
}
