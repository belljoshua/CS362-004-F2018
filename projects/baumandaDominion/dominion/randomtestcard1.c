/*Random testing for Great Hall card (greatHallEffect())*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define TESTCARD "great hall"

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
	int handPos = 0;

	int i;
	for(i = 0; i < 10; i++){

		//Randomly assign values to parameters
		numPlayers = rand() % 3 + 2;
		int j, r;
		for(j = 0; j < 10; j++){
			r = rand() % 7 + 7;
			kingdomCards[j] = r;
		}
		randomSeed = rand() % 5000;

		initializeGame(numPlayers, kingdomCards, randomSeed, &state);
		memcpy(&testState, &state, sizeof(struct gameState));

		greatHallCard(currentPlayer, &state, handPos);

		//Check that there was no state change of kingdom or victory cards
		asserttrue(testState.supplyCount[village], state.supplyCount[village]);
		asserttrue(testState.supplyCount[smithy], state.supplyCount[smithy]);
		asserttrue(testState.supplyCount[remodel], state.supplyCount[remodel]);
		asserttrue(testState.supplyCount[mine], state.supplyCount[mine]);
		asserttrue(testState.supplyCount[council_room], state.supplyCount[council_room]);
		asserttrue(testState.supplyCount[feast], state.supplyCount[feast]);
		asserttrue(testState.supplyCount[gardens], state.supplyCount[gardens]);
		asserttrue(testState.supplyCount[duchy], state.supplyCount[duchy]);
		asserttrue(testState.supplyCount[estate], state.supplyCount[estate]);
		asserttrue(testState.supplyCount[province], state.supplyCount[province]);

	}

}