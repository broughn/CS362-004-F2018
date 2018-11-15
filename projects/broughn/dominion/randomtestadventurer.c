#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#define TESTCARD "adventurer"
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
	int cardState = 0;
	int i = 0,
		j = 0,
		h = 0;

	int newCards = 2;
	//int discarded = 1;

	initializeGame(numPlayer, k, seed, &G);

	for (i = 0; i < REPS; i++) {
		memcpy(&testG, &G, sizeof(struct gameState));

		choice1 = rand()%10;
		choice2 = rand()%10;
		choice3 = rand()%10;

		handPos = rand()%5;
		bonus = rand()%3;

		testG.whoseTurn = rand()%2;
		curPlayer = testG.whoseTurn;

		cardState = rand()%3;

		if (cardState == 1) {
			for (j = 0; j < testG.handCount[curPlayer]; j++) {
				discardCard(j, curPlayer, &testG, 0);
			}
		}
		else if (cardState == 2) {
			for (j = 0; j < testG.deckCount[curPlayer]; j++) {
				testG.deck[curPlayer][j] = estate;
			}
			int placement = rand()%testG.deckCount[curPlayer];
			if (placement == 0) {
				testG.deck[curPlayer][placement] = copper;
				testG.deck[curPlayer][placement+1] = gold;
			}
			switch (rand()%3) {
				case 0:
					testG.deck[curPlayer][placement-1] = copper;
				case 1:
					testG.deck[curPlayer][placement-1] = silver;
				case 2:
					testG.deck[curPlayer][placement-1] = gold;
			}
			switch (rand()%3) {
				case 0:
					testG.deck[curPlayer][placement] = copper;
				case 1:
					testG.deck[curPlayer][placement] = silver;
				case 2:
					testG.deck[curPlayer][placement] = gold;
			}
		}
		else {}

		
		cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);

		// if (cardState == 1) {
		// 	printf("%d\n", cardState);
		// 	printf("%d, %d\n", testG.handCount[curPlayer], testG.discardCount[curPlayer]);
		// }

		if (cardState == 0) {
			assert(testG.handCount[curPlayer] == G.handCount[curPlayer]+newCards);
			assert(testG.hand[curPlayer][G.handCount[curPlayer]] >= 4 && testG.hand[curPlayer][G.handCount[curPlayer]] <= 6);
			assert(testG.hand[curPlayer][G.handCount[curPlayer]+1] >= 4 && testG.hand[curPlayer][G.handCount[curPlayer]+1] <= 6);

			for (j = 0; j < testG.discardCount[curPlayer]; j++) {
				assert(testG.discard[curPlayer][j] < 4 || testG.discard[curPlayer][j] > 6);
			}
		}
		else {
			assert(testG.handCount[curPlayer] >= 2);
			assert(testG.discardCount[curPlayer] >= 1);
		}

		for (h = 0; h < numPlayer; h++) {
				if (h != curPlayer) {
					assert(testG.handCount[h] == G.handCount[h]);
					assert(testG.discardCount[h] == G.discardCount[h]);
				}
			}
	}

	printf(">>>All %d tests passed<<<<\n", REPS);

	return 0;
}