/*Tests numHandCards()*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
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
			asserttrue(numHandCards(&G), G.handCount[p]);
		}
		//Test with negative numbers
		for(i = -10; i < 0; i++){
			G.handCount[p] = i;
			asserttrue(numHandCards(&G), G.handCount[p]);
		}
		//Test with extremely large numbers
		for(i = 0; i < 10; i++){
			G.handCount[p] = INT_MAX - i;
			asserttrue(numHandCards(&G), G.handCount[p]);
		}
		//Test with extremely small numbers
		for(i = 0; i < 10; i++){
			G.handCount[p] = INT_MIN + i;
			asserttrue(numHandCards(&G), G.handCount[p]);
		}
	}

    if(passorfail == 1){
 		printf("All tests passed!\n");
	}

    return 0;
}
