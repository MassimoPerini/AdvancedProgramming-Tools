//
//  DoubleLinkedList.h
//  AdvancedProgramming
//
//  Created by Massimo Perini on 09/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

typedef int value;

typedef struct DoubleLinkedList{
	value val;
	struct DoubleLinkedList *ptrNext;
	struct DoubleLinkedList *ptrPrev;
	
}DoubleLinkedList;


#endif /* DoubleLinkedList_h */
