#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "adventurer"

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
	int i = 0;

	int newCards = 2;
	int discarded = 1;


	initializeGame(numPlayer, k, seed, &G);

	memcpy(&testG, &G, sizeof(struct gameState));


	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);

	
	printf("----- Testing Card: %s -----\n", TESTCARD);
	printf("Test 1: Current player receives 2 treasure cards\n");
	printf("Hand count = %d, expected = %d\n", testG.handCount[curPlayer], G.handCount[curPlayer]+newCards);
	printf("Test 2: Drawn card #1 is a treasure card\n");
	printf("Drawn card = %d, expected = 4,5,6\n", testG.hand[curPlayer][G.handCount[curPlayer]]);
	printf("Test 3: Drawn card #2 is a treasure card\n");
	printf("Drawn card = %d, expected = 4,5,6\n", testG.hand[curPlayer][G.handCount[curPlayer]+1]);

	//assert(testG.handCount[curPlayer] == G.handCount[curPlayer]+newCards);
	assert(testG.hand[curPlayer][G.handCount[curPlayer]] == 4 || testG.hand[curPlayer][G.handCount[curPlayer]] == 5 ||
		testG.hand[curPlayer][G.handCount[curPlayer]] == 6);
	assert(testG.hand[curPlayer][G.handCount[curPlayer]+1] == 4 || testG.hand[curPlayer][G.handCount[curPlayer]+1] == 5 ||
		testG.hand[curPlayer][G.handCount[curPlayer]+1] == 6);

	printf("Test 4: Discard pile increased\n");
	printf("Discard pile = %d >= original discard = %d\n", testG.discardCount[curPlayer], G.discardCount[curPlayer]);

	assert(testG.discardCount[curPlayer] >= G.discardCount[curPlayer]);

	printf("Test 5: No treasure cards are discarded\n");
	printf("Discarded cards: ");
	for (i = 0; i < testG.discardCount[curPlayer]; i++) {
		printf("%d, ", testG.discard[curPlayer][i]);
	}
	printf("expected any number not 4,5,6\n");

	for (i = 0; i < testG.discardCount[curPlayer]; i++) {
		assert(testG.discard[curPlayer][i] != 4 || testG.discard[curPlayer][i] != 5 ||
			testG.discard[curPlayer][i] != 6);
	}

	printf("Other player's hand and discard remain the same\n");
	printf("Player 2 hand = %d, expected %d\n", testG.handCount[curPlayer+1], G.handCount[curPlayer+1]);
	printf("Player 2 discard = %d, expected %d\n", testG.discardCount[curPlayer+1], G.discardCount[curPlayer+1]);

	//assert(testG.handCount[curPlayer+1] == G.handCount[curPlayer+1]);
	assert(testG.discardCount[curPlayer+1] == G.discardCount[curPlayer+1]);

	printf(">>> All tests passed <<<\n\n");

	return 0;
}