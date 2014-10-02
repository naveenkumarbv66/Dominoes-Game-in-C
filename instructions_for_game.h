#ifndef HINT_FOR_DOMINOES_GAME
#define HINT_FOR_DOMINOES_GAME



void Instructions()
{
	int i=0;

	printf("\n   ");
	while(i!=64)
	{
		printf("\4");
		if(i==30)
			printf(" \17 Hint \17  ");

		i++;
	}

	printf("\n\n\n    \20 To play the Game, select any one level in easy, medium and hard.");

	printf("\n\n\n\n    \20 EASY : To cancel the dominoes one by one by entering the");
	printf("\n\n\tposition of the dominoes which contains any adjacent pair is present.");
	

	printf("\n\n\n\n    \20 MEDIUM : then you need to match left bone of the first  dominoes or");
    printf("\n\n\tthe right bone of the last dominoes by entering the correct position.");

	printf("\n\n\n\n    \20 HARD : then you need to match the right bone of one  doninoe to the");
	printf("\n\n\tleft bone of another dominoe (from left to right) by  entering the two");
	printf("\n\n\tcorrect positions.");

	printf("\n\n\n\n    \20 If you are able to eleminte all the dominoes then you WIN the game.");

	printf("\n\n\n\n    \20 If you are not able to eleminate all the dominoes, then you LOOSE ");
	printf("\n\n       the game");

	printf("\n\n\n    \20 If any NO more adjacent pair of dominoes present, then we provided");
	printf("\n\n       three chances.");

	printf("\n\n\n    \20 If you want to Exit in middel of the game, press q latter to exit ");
	printf("\n\n       the game.");
	
	

	i=0;
	printf("\n\n\n   ");
    while(i!=74)
	{
		printf("\5");
		i++;
	}
}



#endif