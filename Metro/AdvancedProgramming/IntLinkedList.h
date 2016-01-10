//
//  List.h
//  AdvancedProgramming
//
//  Created by Massimo Perini on 08/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

	//METRO EXAMPLE
#ifndef IntLinkedList_h
#define IntLinkedList_h

	//CIRCULAR LIST MISSING!!!

	//METRO EXAMPLE
typedef char *value;

typedef struct IntLinkedList{
	value val;
	value from;
	value to;
	int nTimes;
	
	struct IntLinkedList *ptrNext;
}IntLinkedList;


extern IntLinkedList *initIntLinkedList ();
extern IntLinkedList *initIntLinkedListWithValue (value val);

extern IntLinkedList *insertInPositionOfLinkedList (IntLinkedList *head, int position, value element);
IntLinkedList *insertAtTheEndOfLinkedList (IntLinkedList *head, IntLinkedList *newEl);

extern int setValueOfLinkedList (IntLinkedList *head, int position, value newValue);
extern IntLinkedList *getValueOfLinkedList (IntLinkedList *head, int position);
extern int indexOfLinkedList (IntLinkedList *head, value value);
extern IntLinkedList *searchInIntLinkedList (IntLinkedList *head, value value);

extern IntLinkedList *deleteInPositionOfLinkedList (IntLinkedList *head, int position);
extern IntLinkedList *deleteAtTheEndOfLinkedList (IntLinkedList *head);

extern int lengthLinkedList (IntLinkedList *start);
extern void deleteLinkedList (IntLinkedList *head);

#endif /* IntLinkedList_h */
