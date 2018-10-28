/* Tests Adventurer Card */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main(){
	int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;

    int i, j;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	int numTreasure1 = 0, numTreasure2 = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	for(i = 0; i < numPlayers; i++){
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);

		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

		numTreasure1 = 0;
		for(j = 0; j < G.handCount[i]; j++){
			if(G.hand[i][j] == copper || G.hand[i][j] == silver || G.hand[i][j] == gold)
				numTreasure1++;		//Number of treasures in hand before playing adventurer
		}
		numTreasure2 = 0;
		for(j = 0; j < testG.handCount[i]; j++){
			if(testG.hand[i][j] == copper || testG.hand[i][j] == silver || testG.hand[i][j] == gold)
				numTreasure2++;		//Number of treasures in hand after playing adventurer
		}

		newCards = numTreasure2 - numTreasure1;
		shuffledCards = G.discardCount[i] - testG.dicardCount[i];
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

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
}