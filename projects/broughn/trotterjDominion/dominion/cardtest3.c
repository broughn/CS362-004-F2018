#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "estate"

int main() {
	int seed = 1001;
	struct gameState G, testG;
	int numPlayer = 2;
	int curPlayer = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
		 remodel, smithy, village, baron, great_hall};
	int choice1 = 0, choice2 = 0, choice3 = 0;
	int handPos = 0;
	int bonus = 0;
	int i = 0;

	int newCards = 2;
	int discarded = 1;


	initializeGame(numPlayer, k, seed, &G);

	memcpy(&testG, &G, sizeof(struct gameState));

	gainCard(estate, &testG, 2, curPlayer);//Gain an estate

	
	printf("----- Testing Card: %s -----\n", TESTCARD);
	printf("Test 1: Current player score goes up by 1\n");
	printf("Player 1 score: %d, expected: %d\n", scoreFor(curPlayer, &testG), scoreFor(curPlayer, &G)+1);
	printf("Test 2: other player score does not change\n");
	printf("Player 2 score: %d, expected: %d\n", scoreFor(curPlayer+1, &testG), scoreFor(curPlayer+1, &G));

	assert(scoreFor(curPlayer, &testG) == scoreFor(curPlayer, &G)+1);
	assert(scoreFor(curPlayer+1, &testG) == scoreFor(curPlayer+1, &G));
	

	printf(">>> All tests passed <<<\n\n");

	return 0;
}