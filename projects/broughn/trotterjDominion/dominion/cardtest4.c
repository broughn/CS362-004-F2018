#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "sea_hag"

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

	cardEffect(sea_hag, choice1, choice2, choice3, &testG, handPos, &bonus);

	


	printf("----- Testing Card: %s -----\n", TESTCARD);
	printf("Test 1: Other player discards one card\n");
	printf("Player 2 discard: %d, expected: %d\n", testG.discardCount[curPlayer+1], G.discardCount[curPlayer+1]+1);
	printf("Test 2: Other player's top card on deck is a curse\n");
	printf("Player 2 top deck: %d, expected: 0\n", testG.deck[curPlayer+1][testG.deckCount[curPlayer+1]-1]);
	printf("Player 2 discard count: %d\n", testG.discardCount[curPlayer+1]);
	for (i = 0; i < testG.discardCount[curPlayer+1]; i++) {
		printf("Player 2 card %d: %d\n", i, testG.discard[curPlayer+1][i]);
	}
	printf("Test 3: Player 2 score decrease by 1\n");
	printf("Player 2 score: %d, expected %d\n", scoreFor(curPlayer+1, &testG), scoreFor(curPlayer+1, &G)-1);

	assert(testG.discardCount[curPlayer+1] == G.discardCount[curPlayer+1]+1);
	assert(testG.discard[curPlayer+1][0] == 0);
	assert(scoreFor(curPlayer+1, &testG) == scoreFor(curPlayer+1, &G)-1);

	

	printf(">>> All tests passed <<<\n\n");

	return 0;
}