/* Tests getCost() */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


/* //Compares two gameStates for equality
int cmpGameState(struct gameState a, struct gameState b){
	if(a.numPlayers != b.numPlayers)
		return 0;
	if(a.numPlayers != b.numPlayers)
		return 0;
	if(a.numPlayers != b.numPlayers)
		return 0;
	if(a.outpostPlayed != b.outpostPlayed)
		return 0;
	if(a.outpostTurn != b.outpostTurn)
		return 0;
	if(a.whoseTurn != b.whoseTurn)
		return 0;
	if(a.phase != b.phase)
		return 0;
	if(a.numActions != b.numActions)
		return 0;
	if(a.coins != b.coins)
		return 0;
	if(a.numBuys != b.numBuys)
		return 0;
	if(a.numPlayers != b.numPlayers)
		return 0;
	if(a.numPlayers != b.numPlayers)
		return 0;
	if(a.numPlayers != b.numPlayers)
		return 0;
	if(a.numPlayers != b.numPlayers)
		return 0;
	if(a.numPlayers != b.numPlayers)
		return 0;
	if(a.numPlayers != b.numPlayers)
		return 0;
	if(a.numPlayers != b.numPlayers)
		return 0;
	if(a.numPlayers != b.numPlayers)
		return 0;
	if(a.numPlayers != b.numPlayers)
		return 0;
} */

int main() {


    printf ("TESTING getCost():\n");
    
	//Assert that correct value is returned for every card
	assert(getCost(curse) == 0);
	assert(getCost(estate) == 2);
	assert(getCost(duchy) == 5);
	assert(getCost(province) == 8);
	assert(getCost(copper) == 0);
	assert(getCost(silver) == 3);
	assert(getCost(gold) == 6);
	assert(getCost(adventurer) == 6);
	assert(getCost(council_room) == 5);
	assert(getCost(feast) == 4);
	assert(getCost(gardens) == 4);
	assert(getCost(mine) == 5);
	assert(getCost(remodel) == 4);
	assert(getCost(smithy) == 4);
	assert(getCost(village) == 3);
	assert(getCost(baron) == 4);
	assert(getCost(great_hall) == 3);
	assert(getCost(minion) == 5);
	assert(getCost(steward) == 3);
	assert(getCost(tribute) == 5);
	assert(getCost(ambassador) == 3);
	assert(getCost(cutpurse) == 4);
	assert(getCost(embargo) == 2);
	assert(getCost(outpost) == 5);
	assert(getCost(salvager) == 4);
	assert(getCost(sea_hag) == 4);
	assert(getCost(treasure_map) == 4);

	//Assert that -1 is returned for anything other than a card
	assert(getCost(34) == -1);
	assert(getCost(-1) == -1);	

    printf("All tests passed!\n");

    return 0;
}
