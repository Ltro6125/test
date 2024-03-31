#include <string>
#include <time.h>
#include<conio.h>
#include <iostream>


#include "Account.h"
#include "Console.h"

using namespace std;

#define BOARDHEIGHT 5
#define	BOARDWIDTH 10

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC_KEY 27
#define ENTER_KEY 13


struct Point {
	int x;
	int y;
	int isValid = 1;
	int isSelected = 0;
	int isHere = 0;

};

struct Board {
	Account* player;

	Point** position;
	char** charArr = NULL;
};

void initializeBoard(Board& boardGame);

void drawElement(Board boardGame, int i, int j, int color);
void drawBoard(Board boardGame);

void removeElement(Board boardGame, int i, int j);
void removeBoard(Board boardGame);

void move(Board boardGame, Point& pos, Point selectedPos[], int& couple);
void check(Board boardGame, Point selectedPos[], int& couple);



