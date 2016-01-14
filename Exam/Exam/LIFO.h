//
//  LIFO.h
//  AdvancedProgramming
//
//  Created by Massimo Perini on 09/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#ifndef LIFO_h
#define LIFO_h

#include "IntLinkedList.h"

typedef IntLinkedList ListType;

typedef struct LIFO
{
	IntLinkedList *head;
	int size;
	
}LIFO;

extern LIFO *initLifo ();
extern void pushLifo (LIFO *manager, value element);				//Add at the end
extern value popLifo (LIFO *manager);
extern void deleteLifo (LIFO *manager);



#endif /* LIFO_h */
