/* Tests Great Hall Card */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "great hall"

int main(){
	int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;

    int j;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	for(thisPlayer = 0; thisPlayer < numPlayers; thisPlayer++){
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);

		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);

		newCards = 1;
		shuffledCards = G.discardCount[thisPlayer] - testG.discardCount[thisPlayer];
		if(shuffledCards < 0)
			shuffledCards = 0;
		printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
		printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
		assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
		assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
		for(j = 0; j < numPlayers; j++){
			if(j != thisPlayer){
				assert(testG.handCount[j] == G.handCount[j]);	//Check if other players' hands changed
				assert(testG.deckCount[j] == G.deckCount[j]);	//Check if other players' decks changed
				assert(testG.discardCount[j] == G.discardCount[j]);	//Check if other players' discard count changed
			}
		}

		printf("number of actions: %d, expected: %d\n", G.numActions+1, testG.numActions);
		assert(testG.numActions == G.numActions+1);

		//Check that there was no state change of kingdom or victory cards
		assert(testG.supplyCount[village] == G.supplyCount[village]);
		assert(testG.supplyCount[smithy] == G.supplyCount[smithy]);
		assert(testG.supplyCount[remodel] == G.supplyCount[remodel]);
		assert(testG.supplyCount[mine] == G.supplyCount[mine]);
		assert(testG.supplyCount[council_room] == G.supplyCount[council_room]);
		assert(testG.supplyCount[feast] == G.supplyCount[feast]);
		assert(testG.supplyCount[gardens] == G.supplyCount[gardens]);
		assert(testG.supplyCount[duchy] == G.supplyCount[duchy]);
		assert(testG.supplyCount[estate] == G.supplyCount[estate]);
		assert(testG.supplyCount[province] == G.supplyCount[province]);

		memset(&G, 23, sizeof(struct gameState));   // clear the game state
	}

}