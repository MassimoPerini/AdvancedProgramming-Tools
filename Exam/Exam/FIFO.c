//
//  FIFO.c
//  AdvancedProgramming
//
//  Created by Massimo Perini on 09/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#include "FIFO.h"
#include "intLinkedList.h"
#include <stdlib.h>

FIFO *initFifo ()
{
	FIFO *new=malloc(sizeof(FIFO));
	new->head=NULL;
	new->tail=NULL;
	new->size=0;
	return new;
}

void pushFifo (FIFO *manager, value element)				//Add at the end
{
	IntLinkedList *list=insertAtTheEndOfLinkedList(manager->tail, element);
	if (list==NULL)
		return;
	manager->size++;
	
	if (manager->tail==NULL)
	{
		manager->tail=list;
		manager->head=list;
		return;
	}
	
	manager->tail=manager->tail->ptrNext;
}


value popFifo (FIFO *manager)
{
	if (manager->head==NULL)
		return -1;					//Empty list
	
	value res=manager->head->val;
	IntLinkedList *tmp=manager->head->ptrNext;
	
	deleteInPositionOfLinkedList(manager->head, 0);
	manager->head=tmp;

	if (manager->head==NULL)		//Last item
		manager->tail=NULL;
	manager->size--;
	return res;
}

void deleteFifo (FIFO *manager)
{
	deleteLinkedList(manager->head);
	manager->size=0;
	manager->head=NULL;
	manager->tail=NULL;
}