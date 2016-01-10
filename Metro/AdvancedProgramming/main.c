//
//  main.c
//  AdvancedProgramming
//
//  Created by Massimo Perini on 07/01/16.
//  Copyright © 2016 Massimo Perini. All rights reserved.
//

	//MANCANO LE LISTE CIRCOLARI
	//MANCA FIFO E LIFO BOUNDED
	//METTERE SEMPRE UNSIGNED INT/LONG

#include <stdio.h>

#include "MetroExample.h"

int main(int argc, const char * argv[]) {
    // insert code here...
	
	initMetroManager(30, 10);
	startTrip("1", "Tokyo");
	startTrip("2", "Kyoto");
	startTrip("3", "Nagoya");
	
	endTrip("2", "Tokyo");
	endTrip("1", "Kyoto");
	endTrip("3", "Kanazawa");
	
	startTrip("3", "Kyoto");
	endTrip("3", "Tokyo");
	
	startTrip("3", "Kyoto");
	endTrip("3", "Tokyo");
	
	startTrip("3", "Nagoya");
	endTrip("3", "Kanazawa");
	
	startTrip("3", "Nagoya");
	endTrip("3", "Kanazawa");
	
	char *s=mostFrequentTrip();
	char *s1=mostFrequentTripPerUser("3");
	
	printf("%s\n%s", s, s1);
	
    return 0;
}
