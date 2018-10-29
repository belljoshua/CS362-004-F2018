/*Tests kingdomCards()*/

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
	int testCards[10];
	int* resultCards;

    printf ("TESTING kingdomCards():\n");
    
	//Test with positive numbers including 0
	for(i = 0; i < 10; i++){
		testCards[i] = i;
	}
	resultCards = kingdomCards(testCards[0], testCards[1], testCards[2], testCards[3], testCards[4], testCards[5], testCards[6], testCards[7], testCards[8], testCards[9]);

	for(i = 0; i < 10; i++){
		asserttrue(resultCards[i], testCards[i]);		//Check that the cards have the correct value
	}

	//Test with negative numbers
	for(i = 0; i < 10; i++){
		testCards[i] = -10 + i;
	}
	resultCards = kingdomCards(testCards[0], testCards[1], testCards[2], testCards[3], testCards[4], testCards[5], testCards[6], testCards[7], testCards[8], testCards[9]);

	for(i = 0; i < 10; i++){
		asserttrue(resultCards[i], testCards[i]);		//Check that the cards have the correct value
	}

	//Test with extremely large numbers
	for(i = 0; i < 10; i++){
		testCards[i] = INT_MAX - i;
	}
	resultCards = kingdomCards(testCards[0], testCards[1], testCards[2], testCards[3], testCards[4], testCards[5], testCards[6], testCards[7], testCards[8], testCards[9]);
	
	for(i = 0; i < 10; i++){
		asserttrue(resultCards[i], testCards[i]);		//Check that the cards have the correct value
	}

	//Test with extremely small numbers
	for(i = 0; i < 10; i++){
		testCards[i] = INT_MIN + i;
	}
	resultCards = kingdomCards(testCards[0], testCards[1], testCards[2], testCards[3], testCards[4], testCards[5], testCards[6], testCards[7], testCards[8], testCards[9]);
	
	for(i = 0; i < 10; i++){
		asserttrue(resultCards[i], testCards[i]);		//Check that the cards have the correct value
	}


    if(passorfail == 1){
 		printf("All tests passed!\n");
	}

    return 0;
}
