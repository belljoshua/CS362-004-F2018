/*Random testing for Great Hall card (greatHallEffect())*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define TESTCARD "Adventurer"

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
	srand (time(NULL));

	int numPlayers = 4;
	int kingdomCards[10];
	struct gameState state, testState;
	int randomSeed = 1000;
	int currentPlayer = 0;
	int drawntreasure = 0;
	int cardDrawn = 4;
	int temphand[MAX_HAND];
	int thisPlayer = 0;
	int z = 0;
	int numTreasure1, numTreasure2;
	int discarded = 1, shuffledCards = 0;
	int i, j;
	
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	for(i = 0; i < 10; i++){
		//Randomly assign values to parameters
		numPlayers = rand() % 3 + 2;
		randomSeed = rand() % 5000;
		currentPlayer = rand() % numPlayers;
		drawntreasure = rand() % 4;
		cardDrawn = rand() % 33;
		z = rand() % MAX_HAND;
		initializeGame(numPlayers, kingdomCards, randomSeed, &state);
		memcpy(&testState, &state, sizeof(struct gameState));

		adventurerEffect(drawntreasure, &state, currentPlayer, cardDrawn, temphand, z);

		numTreasure1 = 0;
		for(j = 0; j < state.handCount[i]; j++){
			if(state.hand[i][j] == copper || state.hand[i][j] == silver || state.hand[i][j] == gold)
				numTreasure1++;		//Number of treasures in hand before playing adventurer
		}
		numTreasure2 = 0;
		for(j = 0; j < testState.handCount[i]; j++){
			if(testState.hand[i][j] == copper || testState.hand[i][j] == silver || testState.hand[i][j] == gold)
				numTreasure2++;		//Number of treasures in hand after playing adventurer
		}

		int newCards = numTreasure2 - numTreasure1;

		printf("hand count = %d, expected = %d\n", testState.handCount[thisPlayer], state.handCount[thisPlayer] + newCards - discarded);
		printf("deck count = %d, expected = %d\n", testState.deckCount[thisPlayer], state.deckCount[thisPlayer] - newCards + shuffledCards);
		asserttrue(testState.handCount[thisPlayer], state.handCount[thisPlayer] + newCards - discarded);
		asserttrue(testState.deckCount[thisPlayer], state.deckCount[thisPlayer] - newCards + shuffledCards);
	}
	

}