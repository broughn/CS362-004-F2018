#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "smithy"

int main() {
	int seed = 1000;
	struct gameState G, testG;
	int numPlayer = 2;
	int curPlayer = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
		 remodel, smithy, village, baron, great_hall};
	int choice1 = 0, choice2 = 0, choice3 = 0;
	int handPos = 0;
	int bonus = 0;
	

	int newCards = 3;
	int discarded = 1;


	initializeGame(numPlayer, k, seed, &G);

	memcpy(&testG, &G, sizeof(struct gameState));


	cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);

	
	printf("----- Testing Card: %s -----\n", TESTCARD);
	printf("Test 1: Current player receives 3 cards\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[curPlayer], G.handCount[curPlayer]+newCards-discarded);
	printf("Test 2: Cards were drawn from player's own deck\n");
	printf("Deck count = %d, expected = %d\n", testG.deckCount[curPlayer], G.handCount[curPlayer]-newCards);

	//assert(testG.handCount[curPlayer] == G.handCount[curPlayer]+newCards-discarded);
	assert(testG.deckCount[curPlayer] == G.handCount[curPlayer]-newCards);

	printf("Test 3: No state change occurs for other player\n");
	printf("Deck count = %d, expected = %d\n", testG.deckCount[curPlayer+1], G.deckCount[curPlayer+1]);

	assert(testG.deckCount[curPlayer+1] == G.deckCount[curPlayer+1]);

	printf("Test 4: No state change to victory card piles and kingdom card piles\n");
	printf("Player 1 score: %d, expected: %d. Player 2 score: %d, expected %d\n", scoreFor(curPlayer, &testG), scoreFor(curPlayer, &G),
		scoreFor(curPlayer+1, &testG), scoreFor(curPlayer+1, &G));

	assert(scoreFor(curPlayer, &testG) == scoreFor(curPlayer, &G));
	assert(scoreFor(curPlayer+1, &testG) == scoreFor(curPlayer+1, &G));

	printf(">>> All tests passed <<<\n\n");

	return 0;
}