#include "Board.h"

#include <iostream>

using namespace std;

void initializeBoard(Board& boardGame) {
	
	boardGame.charArr = new char* [BOARDHEIGHT];
	boardGame.position = new Point* [BOARDHEIGHT];

	for (int i = 0; i < BOARDHEIGHT; i++) {
		boardGame.charArr[i] = new char[BOARDWIDTH];
        boardGame.position[i] = new Point [BOARDWIDTH];

		for (int j = 0; j < BOARDWIDTH; j++) {
			boardGame.position[i][j].x = i;
			boardGame.position[i][j].y = j;

            boardGame.charArr[i][j]= ' ';
	    }

	}

    srand(time(0));

    int flagNum = (BOARDHEIGHT * BOARDWIDTH) / 2;
    while (flagNum) {
        int time = 2;
        char c = 65 + rand() % 26;

        while (time) { 
            int index = rand() % 50;
            if (boardGame.charArr[index / 10][index % 10] == ' ') {
                boardGame.charArr[index / 10][index % 10] = c;
                time--;
            }
        }
        flagNum--;
    }

}

char Element[5][12] = {
            {" --------- "},
            {"|         |"},
            {"|         |"},
            {"|         |"},
            {" --------- "}
};



void drawElement(Board boardGame, int i, int j, int color) {

    int x = j + 1, y = i + 1;

    for (int i = 0; i < 5; i++) {
        GoToXY(x * 10, y * 4 + i);
        cout << Element[i];
    }

    if (boardGame.position[i][j].isSelected == 1 || boardGame.position[i][j].isHere == 1) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (boardGame.charArr[i][j] % 6 + 1)); // white background
        for (int i = 1; i < 4; i++) {
            GoToXY(x * 10 + 1, y * 4 + i);
            cout << "         ";
        }

        GoToXY(x * 10 + 5, y * 4 + 2);
        cout << boardGame.charArr[i][j];
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else {
        GoToXY(x * 10 + 5, y * 4 + 2);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), boardGame.charArr[i][j] % 6 + 1);
        cout << boardGame.charArr[i][j];
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }

}

void drawBoard(Board boardGame) {
    for (int i = 0; i < BOARDHEIGHT; i++) {
        for (int j = 0; j < BOARDWIDTH; j++) {
            if (boardGame.position[i][j].isValid == 1) {
                drawElement(boardGame, i, j, 112);
            }
        }
    }
}

void removeElement(Board boardGame, int i, int j) {
    int x = j + 1, y = i + 1;
    boardGame.charArr[i][j] = ' ';

    for (int i = 0; i < 5; i++) {
        GoToXY(x * 10, y * 4 + i);
        cout << "           ";

    }

}

void removeBoard(Board boardGame) {
    for (int i = 0; i < BOARDHEIGHT; i++) {
        for (int j = 0; j < BOARDWIDTH; j++) {
            removeElement(boardGame, i, j);
            Sleep(100);

        }
    }

    for (int i = 0; i < BOARDHEIGHT; i++) {
        delete[] boardGame.charArr[i];

    }

    delete[] boardGame.charArr;

}


void move(Board boardGame, Point& pos, Point selectedPos[], int& couple) {
    int key;
    
    switch (key = _getch())
    {
    case ESC_KEY:
        break;
    case ENTER_KEY:
        if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y) {
            drawElement(boardGame, selectedPos[0].y, selectedPos[0].x, 70);
            Sleep(500);

            boardGame.position[selectedPos[0].y][selectedPos[0].x].isSelected = 0;
            couple = 2;
            selectedPos[0] = { -1, -1 };
        } 
        else {
            selectedPos[2 - couple].x = pos.x;
            selectedPos[2 - couple].y = pos.y;
            boardGame.position[pos.y][pos.x].isSelected = 1;
            couple--;
        }
        break;

    case KEY_UP:
        for (int i = pos.x; i < BOARDWIDTH; i++) {
            for (int j = pos.y - 1; j >= 0; j--) {
                if (boardGame.position[j][i].isValid) {
                    pos.x = i;
                    pos.y = j;
                    return;
                }
            }
        }

        for (int i = pos.x - 1; i >= 0; i--) {
            for (int j = pos.y - 1; j >= 0; j--) {
                if (boardGame.position[j][i].isValid) {
                    pos.x = i;
                    pos.y = j;
                    return;
                }
            }
        }

        for (int i = pos.x; i < BOARDWIDTH; i++) {
            for (int j = BOARDHEIGHT - 1; j > pos.y; j--) {
                if (boardGame.position[j][i].isValid) {
                    pos.x = i;
                    pos.y = j;
                    return;
                }
            }
        }

        for (int i = pos.x; i >= 0; i--) {
            for (int j = BOARDHEIGHT - 1; j > pos.y; j--) {
                if (boardGame.position[j][i].isValid) {
                    pos.x = i;
                    pos.y = j;
                    return;
                }
            }
        }

        break;
    case KEY_DOWN:
        for (int i = pos.x; i < BOARDWIDTH; i++) {
            for (int j = pos.y + 1; j < BOARDHEIGHT; j++) {
                if (boardGame.position[j][i].isValid) {
                    pos.x = i;
                    pos.y = j;
                    return;
                }
            }
        }

        for (int i = pos.x - 1; i >= 0; i--) {
            for (int j = pos.y + 1; j < BOARDHEIGHT; j++) {
                if (boardGame.position[j][i].isValid) {
                    pos.x = i;
                    pos.y = j;
                    return;
                }
            }
        }

        for (int i = pos.x; i < BOARDWIDTH; i++) {
            for (int j = 0; j < pos.y; j++) {
                if (boardGame.position[j][i].isValid) {
                    pos.x = i;
                    pos.y = j;
                    return;
                }
            }
        }

        for (int i = pos.x - 1; i >= 0; i--) {
            for (int j = 0; j < pos.y; j++) {
                if (boardGame.position[j][i].isValid) {
                    pos.x = i;
                    pos.y = j;
                    return;
                }
            }
        }
        break;
    case KEY_LEFT:
        for (int i = pos.y; i >= 0; i--) {
            for (int j = pos.x - 1; j >= 0; j--) {
                if (boardGame.position[i][j].isValid) {
                    pos.x = j;
                    pos.y = i;
                    return;
                }
            }
        }

        for (int i = pos.y + 1; i < BOARDHEIGHT; i++) {
            for (int j = pos.x - 1; j >= 0; j--) {
                if (boardGame.position[i][j].isValid) {
                    pos.x = j;
                    pos.y = i;
                    return;
                }
            }
        }

        for (int i = pos.y; i >= 0; i--) {
            for (int j = BOARDWIDTH - 1; j > pos.x; j--) {
                if (boardGame.position[i][j].isValid) {
                    pos.x = j;
                    pos.y = i;
                    return;
                }
            }
        }

        for (int i = pos.y + 1; i < BOARDHEIGHT; i++) {
            for (int j = BOARDWIDTH - 1; j > pos.x; j--) {
                if (boardGame.position[i][j].isValid) {
                    pos.x = j;
                    pos.y = i;
                    return;
                }
            }
        }
        break;
    case KEY_RIGHT:
        for (int i = pos.y; i >= 0; i--) {
            for (int j = pos.x + 1; j < BOARDWIDTH; j++) {
                if (boardGame.position[i][j].isValid) {
                    pos.x = j;
                    pos.y = i;
                    return;
                }
            }
        }

        for (int i = pos.y + 1; i < BOARDHEIGHT; i++) {
            for (int j = pos.x + 1; j < BOARDWIDTH; j++) {
                if (boardGame.position[i][j].isValid) {
                    pos.x = j;
                    pos.y = i;
                    return;
                }
            }
        }

        for (int i = pos.y; i >= 0; i--) {
            for (int j = 0; j < pos.x; j++) {
                if (boardGame.position[i][j].isValid) {
                    pos.x = j;
                    pos.y = i;
                    return;
                }
            }
        }

        for (int i = pos.y + 1; i < BOARDHEIGHT; i++) {
            for (int j = 0; j < pos.x; j++) {
                if (boardGame.position[i][j].isValid) {
                    pos.x = j;
                    pos.y = i;
                    return;
                }
            }
        }
        break;
    }

}




    
