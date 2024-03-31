#include "Board.h"

void Standard() {

	Board boardGame;



	initializeBoard(boardGame);
	drawBoard(boardGame);

	//cout  

	Point posCurr;
	posCurr.x = 0;
	posCurr.y = 0;

	Point selectedPos[] = { {-1,-1},{-1,-1} };
	int couple = 2;

	while (1) {
		boardGame.position[posCurr.y][posCurr.x].isHere = 1;
		drawBoard(boardGame);
		Sleep(50);

		boardGame.position[posCurr.y][posCurr.x].isHere = 0;
		move(boardGame, posCurr, selectedPos, couple);
		
		if (couple == 0) {
			check(boardGame, selectedPos, couple);
			drawBoard(boardGame);

		}

	}


}

