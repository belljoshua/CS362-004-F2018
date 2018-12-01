/* Tests getCost() */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int passorfail = 1;

int asserttrue(int a, int b){
	if(a == b){
		return 1;
	}
	else{
		passorfail = 0;
		printf("TEST FAILED. %d does not eqaul %d\n", a, b);
		return 0;
	}
}

int main() {


    printf ("TESTING getCost():\n");
    
	//Assert that correct value is returned for every card
	asserttrue(getCost(curse), 0);
	asserttrue(getCost(estate), 2);
	asserttrue(getCost(duchy), 5);
	asserttrue(getCost(province), 8);
	asserttrue(getCost(copper), 0);
	asserttrue(getCost(silver), 3);
	asserttrue(getCost(gold), 6);
	asserttrue(getCost(adventurer), 6);
	asserttrue(getCost(council_room), 5);
	asserttrue(getCost(feast), 4);
	asserttrue(getCost(gardens), 4);
	asserttrue(getCost(mine), 5);
	asserttrue(getCost(remodel), 4);
	asserttrue(getCost(smithy), 4);
	asserttrue(getCost(village), 3);
	asserttrue(getCost(baron), 4);
	asserttrue(getCost(great_hall), 3);
	asserttrue(getCost(minion), 5);
	asserttrue(getCost(steward), 3);
	asserttrue(getCost(tribute), 5);
	asserttrue(getCost(ambassador), 3);
	asserttrue(getCost(cutpurse), 4);
	asserttrue(getCost(embargo), 2);
	asserttrue(getCost(outpost), 5);
	asserttrue(getCost(salvager), 4);
	asserttrue(getCost(sea_hag), 4);
	asserttrue(getCost(treasure_map), 4);

	//Assert that -1 is returned for anything other than a card
	asserttrue(getCost(34), -1);
	asserttrue(getCost(-1), -1);	

	if(passorfail == 1){
 		printf("All tests passed!\n");
	}

    return 0;
}
