/*Tests numHandCards*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
	int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf ("TESTING numHandCards():\n");

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	for(p = 0; p < numPlayer; p++){		//Test for each player
		G.whoseTurn = p;
		//Test with positive numbers including 0
		for(i = 0; i < 10; i++){
			G.handCount[p] = i;
			assert(numHandCards(&G) == G.handCount[p]);
		}
		//Test with negative numbers
		for(i = -10; i < 0; i++){
			G.handCount[p] = i;
			assert(numHandCards(&G) == G.handCount[p]);
		}
		//Test with extremely large numbers
		for(i = 0; i < 10; i++){
			G.handCount[p] = INT_MAX - i;
			assert(numHandCards(&G) == G.handCount[p]);
		}
		//Test with extremely small numbers
		for(i = 0; i < 10; i++){
			G.handCount[p] = INT_MIN + i;
			assert(numHandCards(&G) == G.handCount[p]);
		}
	}

    printf("All tests passed!\n");

    return 0;
}
