//
//  FIFO.h
//  AdvancedProgramming
//
//  Created by Massimo Perini on 09/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#ifndef FIFO_h
#define FIFO_h

#include "IntLinkedList.h"

typedef IntLinkedList ListType;

typedef struct FIFO{
	ListType *head;
	ListType *tail;
	int size;
}FIFO;


extern FIFO *initFifo ();
void pushFifo (FIFO *manager, value element);
value popFifo (FIFO *manager);
void deleteFifo (FIFO *manager);


#endif /* FIFO_h */
