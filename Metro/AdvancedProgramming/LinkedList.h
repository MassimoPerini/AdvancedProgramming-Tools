//
//  GenericLinkedList.h
//  AdvancedProgramming
//
//  Created by Massimo Perini on 09/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#ifndef GenericLinkedList_h
#define GenericLinkedList_h

#include <stdio.h>
/*

union u{
	char ch;
	int d;
	double dl;
};


typedef struct LinkedList{
	enum {
		typUndefined,
		typInt,           // 1
		typUint,
		typString,
		typLong
	} type;
	
	union
	{
		int i;
		unsigned int u;
		char* s;
		long l;
	}val;
	struct LinkedList *ptrNext;
}LinkedList;


extern LinkedList *init ();
extern LinkedList *initWithValue (value val);

extern LinkedList *insertInPosition (LinkedList *head, int position, value element);
extern LinkedList *insertAtTheEnd (LinkedList *head, value element);

extern int setValue (LinkedList *head, int position, value newValue);
extern value getValue (LinkedList *head, int position);
extern int indexOf (LinkedList *head, value value);

extern LinkedList *deleteInPosition (LinkedList *head, int position);
extern LinkedList *deleteAtTheEnd (LinkedList *head);

extern int length (LinkedList *start);
void deleteList (LinkedList *head);
*/

#endif /* GenericLinkedList_h */
