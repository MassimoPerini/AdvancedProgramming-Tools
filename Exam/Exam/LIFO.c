//
//  LIFO.c
//  AdvancedProgramming
//
//  Created by Massimo Perini on 09/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#include "LIFO.h"

#include "IntLinkedList.h"
#include <stdlib.h>

LIFO *initLifo ()
{
	LIFO *new=malloc(sizeof(LIFO));
	new->head=NULL;
	new->size=0;
	return new;
}

void pushLifo (LIFO *manager, value element)				//Add at the end
{
	IntLinkedList *list=insertInPositionOfLinkedList(manager->head,0, element);
	if (list==NULL)
		return;
	manager->size++;
	manager->head=list;
}


value popLifo (LIFO *manager)
{
	if (manager->head==NULL)
		return -1;					//Empty list
	
	value res=manager->head->val;
	IntLinkedList *tmp=manager->head->ptrNext;
	
	deleteInPositionOfLinkedList(manager->head, 0);
	manager->head=tmp;
	manager->size--;
	return res;
}

void deleteLifo (LIFO *manager)
{
	deleteLinkedList(manager->head);
	manager->size=0;
	manager->head=NULL;
}