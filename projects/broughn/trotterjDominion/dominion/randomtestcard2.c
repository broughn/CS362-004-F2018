#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#define TESTCARD "sea_hag"
#define REPS 500000

int main() {
	srand(time(NULL));

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

	initializeGame(numPlayer, k, seed, &G);

	for (i = 0; i < REPS; i++) {
		memcpy(&testG, &G, sizeof(struct gameState));

		choice1 = rand()%10;
		choice2 = rand()%10;
		choice3 = rand()%10;

		handPos = rand()%5;
		bonus = rand()%3;

		cardEffect(sea_hag, choice1, choice2, choice3, &testG, handPos, &bonus);


		if (curPlayer == 0) {
			assert(testG.discardCount[curPlayer+1] == G.discardCount[curPlayer+1]+1);
			assert(testG.discard[curPlayer+1][0] == 0);
			assert(scoreFor(curPlayer+1, &testG) == scoreFor(curPlayer+1, &G)-1);
		}
		else {
			assert(testG.discardCount[curPlayer-1] == G.discardCount[curPlayer-1]+1);
			assert(testG.discard[curPlayer-1][0] == 0);
			assert(scoreFor(curPlayer-1, &testG) == scoreFor(curPlayer-1, &G)-1);
		}
	}

	printf(">>>All %d tests passed<<<<\n", REPS);

	return 0;
}