//
//  MetroExample.h
//  AdvancedProgramming
//
//  Created by Massimo Perini on 10/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

#ifndef MetroExample_h
#define MetroExample_h

#include "IntLinkedList.h"

void initMetroManager (int size, int size2);

void startTrip (char *id, char *startStation);
void endTrip (char *id, char *endStation);
char *mostFrequentTrip ();
char *mostFrequentTripPerUser (char *user);

#endif /* MetroExample_h */
