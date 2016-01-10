//
//  MetroExample.c
//  AdvancedProgramming
//
//  Created by Massimo Perini on 10/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#include "MetroExample.h"

#include "ListHashTable.h"
#include "ArrayHashTable.h"
#include "IntLinkedList.h"

#include <string.h>
#include <stdlib.h>

static ListHashTable *travelsHashTable;
static ArrayHashTable *peopleHashTable;
static IntLinkedList *travelsTmp;

static char *generateKey (char *start, char *end)
{
	unsigned long len=strlen(start)+strlen(end)+1;
	char *key=calloc(len, sizeof(char));					//Generate also the terminator ('\0')
	snprintf(key, sizeof(char)*len, "%s%s", start, end);
	return key;
}

static void tripCompleted (char *id, char *startStation, char *endStation)
{
		//MANAGE TRAVELS
	char *key=generateKey(startStation, endStation);			//Storing the key, the start and the end of the station
	int cFree=0;
	
	ListElement *travel=getElementFromListHashTable(key, travelsHashTable);
	
	if (travel==NULL)											//This travel isn't already inside
	{
		travel=generateListHashTableElement();
		travel->from=startStation;
		travel->to=endStation;
		travel->nTimes=1;
		travel->key=key;
		insertInListHashTable(travel, travelsHashTable);
	}
	else{
		travel->nTimes++;
		cFree++;
	}
		//MANAGE PEOPLE
	
	ArrayElement *person= getElementFromArrayHashTable(id, peopleHashTable);
	if (person==NULL)
	{
		person=generateArrayHashTableElement();
		person->key=id;
		person->travels=NULL;
		
		insertInArrayHashTable(person, peopleHashTable);
	}
	else
	{
		IntLinkedList *trav=person->travels;
		IntLinkedList *elem=searchInIntLinkedList(trav, key);
		if (elem!=NULL)
		{
			elem->nTimes++;
			cFree++;
			if (elem->nTimes > trav->nTimes)
			{
				int index=indexOfLinkedList(trav, key)-1;		//Index will never be 0 (elem->nTimes == trav->nTimes)
				IntLinkedList *elBefore=getValueOfLinkedList(trav, index);
				elBefore->ptrNext=elem->ptrNext;
				elem->ptrNext=trav;
				person->travels=elem;
			}
		}
		else
		{
			IntLinkedList *newEl=initIntLinkedList();
			newEl->val=key;
			newEl->from=startStation;
			newEl->to=endStation;
			newEl->nTimes=1;
			
			person->travels=insertAtTheEndOfLinkedList(trav, newEl);
		}
	}
	if (cFree>=2)
		free(key);
}

char *mostFrequentTrip ()
{
	int i;
	unsigned long freqMax=0;
	ListElement *elMax=NULL, *elTmp=NULL;
	
		//Search the greatest value
	
	for (;i<travelsHashTable->size;i++){
		elTmp = travelsHashTable->hashArray[i];
		while (elTmp!=NULL)
		{
			if (elTmp->nTimes > freqMax)
			{
				freqMax=elTmp->nTimes;
				elMax=elTmp;
			}
			elTmp=elTmp->ptrNext;
		}
	}
	if (elMax==NULL)
		return NULL;
	
	unsigned short len=(4+strlen(elMax->from)+strlen(elMax->to));
	char *result=malloc(sizeof(char)*len);
	snprintf(result, sizeof(char)*len, "%s - %s", elMax->from, elMax->to);		//"station from" - "station to"
	return result;
}

char *mostFrequentTripPerUser (char *user)
{
	ArrayElement *person = getElementFromArrayHashTable(user, peopleHashTable);
	if (person==NULL) return NULL;
	IntLinkedList *listTravel=person->travels;
	
/*	IntLinkedList *maxTravel=NULL;
	int nMax=-1;
	
	while (listTravel!=NULL)
	{
		if (listTravel->nTimes > nMax)
		{
			nMax=listTravel->nTimes;
			maxTravel=listTravel;
		}
		listTravel=listTravel->ptrNext;
	}
	if (maxTravel==NULL)
		return NULL;*/
	
	if (listTravel==NULL)
		return NULL;
	
	unsigned short len=(4+strlen(listTravel->from)+strlen(listTravel->to));
	char *str=malloc(sizeof(char)*len);
	snprintf(str, sizeof(char)*len, "%s - %s", listTravel->from, listTravel->to);
	return str;
}

void initMetroManager (int size, int size2)
{
	travelsHashTable=initListHashTable(size);
	peopleHashTable=initArrayHashTable(size2);
	travelsTmp=NULL;
}

void startTrip (char *id, char *startStation)
{
	IntLinkedList *newEl=initIntLinkedListWithValue(id);
	newEl->from=startStation;
	newEl->to=NULL;
	travelsTmp=insertAtTheEndOfLinkedList(travelsTmp, newEl);
		//newEl->nTimes NOT USED (I should create another list, another structure, ...)
}

void endTrip (char *id, char *endStation)
{
	int i=indexOfLinkedList(travelsTmp, id);
	if (i<0)
		return;			//impossible finish a trip if it is not started
	IntLinkedList *prev=getValueOfLinkedList(travelsTmp, i);
	char *from=prev->from;
	deleteInPositionOfLinkedList(travelsTmp, i);
	tripCompleted(id, from, endStation);
}
