#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTFUNC "isGameOver"

int main() {
	int seed = 1000;
	struct gameState G, testG;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
		 remodel, smithy, village, baron, great_hall};
	int result = 0;

	initializeGame(numPlayer, k, seed, &G);

	memcpy(&testG, &G, sizeof(struct gameState));

	result = isGameOver(&testG);

	assert(result == 0);

	memcpy(&testG, &G, sizeof(struct gameState));
	testG.supplyCount[province] = 0;

	result = isGameOver(&testG);

	assert(result == 1);

	memcpy(&testG, &G, sizeof(struct gameState));
	testG.supplyCount[copper] = 0;
	testG.supplyCount[silver] = 0;
	testG.supplyCount[gold] = 0;

	result = isGameOver(&testG);

	assert(result == 1);

	printf("----- Testing function: %s -----\n", TESTFUNC);
	printf(">>> All tests passed <<<\n\n");

	return 0;
}