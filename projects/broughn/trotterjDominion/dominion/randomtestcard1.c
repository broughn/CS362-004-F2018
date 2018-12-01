#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#define TESTCARD "estate"
#define REPS 10000


int main() {
	srand(time(NULL));

	int seed = 1001;
	struct gameState G, testG;
	int numPlayer = 2;
	int curPlayer = 0;
	int flag = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
		 remodel, smithy, village, baron, great_hall};
	int i = 0;

	initializeGame(numPlayer, k, seed, &G);


	for (i = 0; i < REPS; i++) {
		memcpy(&testG, &G, sizeof(struct gameState));

		flag = rand()%3;
		curPlayer = rand()%2;

		gainCard(estate, &testG, flag, curPlayer);

		//printf("%d, %d\n", flag, curPlayer);
		//printf("%d, %d\n\n", scoreFor(curPlayer, &testG), scoreFor(curPlayer, &G)+1);

		
		if (curPlayer == 1) {
			if (flag == 2 || flag == 0) {
				assert(scoreFor(curPlayer, &testG) == scoreFor(curPlayer, &G)+1);
			}
			else {
				assert(scoreFor(curPlayer, &testG) == scoreFor(curPlayer, &G));
			}
			if (curPlayer == 0) {
				assert(scoreFor(curPlayer+1, &testG) == scoreFor(curPlayer+1, &G));
			}
			else {
				assert(scoreFor(curPlayer-1, &testG) == scoreFor(curPlayer-1, &G));
			}
		}
		else {
			if (flag == 2) {
				assert(scoreFor(curPlayer, &testG) == scoreFor(curPlayer, &G)+1);
			}
			else if (flag == 0) {
				assert(scoreFor(curPlayer, &testG) == scoreFor(curPlayer, &G)+2);
			}
			else {
				assert(scoreFor(curPlayer, &testG) == scoreFor(curPlayer, &G));
			}
			if (curPlayer == 0) {
				assert(scoreFor(curPlayer+1, &testG) == scoreFor(curPlayer+1, &G));
			}
			else {
				assert(scoreFor(curPlayer-1, &testG) == scoreFor(curPlayer-1, &G));
			}
		}

	}

	printf(">>>All %d tests passed<<<<\n", REPS);

	return 0;
}
