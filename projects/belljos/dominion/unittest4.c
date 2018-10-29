/*Tests isGameOver()*/

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
    int r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf ("TESTING isGameOver():\n");

	 memset(&G, 23, sizeof(struct gameState));   // clear the game state
     r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

	//Out of Province cards
	for(i = 0; i < 25; i++){
		if(G.supplyCount[i] == 0)
			G.supplyCount[i]++;
	}
	G.supplyCount[province] = 0;

	asserttrue(isGameOver(&G), 1);

	//3 supply piles empty
	G.supplyCount[0] = G.supplyCount[1] = G.supplyCount[2] = 0;
	if(G.supplyCount[province] < 1)
		G.supplyCount[province]++;

	asserttrue(isGameOver(&G), 1);

	//Out of Province cards and 3 total supply piles empty
	G.supplyCount[0] = G.supplyCount[1] = G.supplyCount[province] = 0;

	asserttrue(isGameOver(&G), 1);

	//Not out of province cards or 3 total supply piles
	if(G.supplyCount[province] < 1)
		G.supplyCount[province]++;

	for(i = 0; i < 25; i++){
		if(G.supplyCount[i] == 0)
			G.supplyCount[i]++;
	}

	asserttrue(isGameOver(&G), 0);

    printf("All tests passed!\n");

    return 0;
}