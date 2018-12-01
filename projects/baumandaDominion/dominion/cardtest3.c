/* Tests Outpost Card */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Outpost"

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

int main(){
	int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;

    int i, j;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	for(thisPlayer = 0; thisPlayer < numPlayers; thisPlayer++){
		printf("Testing with player %d\n", i+1);
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);

		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		cardEffect(outpost, choice1, choice2, choice3, &testG, handpos, &bonus);

		asserttrue(testG.outpostPlayed, 1);

		newCards = 0;
		printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
		printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
		asserttrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
		asserttrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
		for(j = 0; j < numPlayers; j++){
			if(j != thisPlayer){
				asserttrue(testG.handCount[j], G.handCount[j]);	//Check if other players' hands changed
				asserttrue(testG.deckCount[j], G.deckCount[j]);	//Check if other players' decks changed
				asserttrue(testG.discardCount[j], G.discardCount[j]);	//Check if other players' discard count changed
			}
		}
		//Check that there was no state change of any cards
		for(j = curse; j <= treasure_map; j++){
			asserttrue(G.supplyCount[j], testG.supplyCount[j]);
		}

		memset(&G, 23, sizeof(struct gameState));   // clear the game state
	}

	if(passorfail == 1){
		printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
	}
}