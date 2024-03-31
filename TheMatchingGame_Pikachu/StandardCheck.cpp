#include "Standard.h"

bool nextMatching(Board boardGame, int x1, int y1, int x2, int y2) {

	if (boardGame.charArr[x1][y1] == boardGame.charArr[x2][y2]) {
		if(x1 == x2 && (y1 == y2 - 1) || y1 == y2 + 1) {
			return true;
		}
		if (y1 == y2 && (x1 == x2 - 1) || x1 == x2 + 1) {
			return true;
		}
	}

	return false;

}

bool lineMatching(Board boardGame, int x1, int y1, int x2, int y2) {
	int start, end, dem = 0;

	if (x1 == x2) {
		if (y1 > y2) {
			start = y2;
			end = y1;
		}
		else {
			start = y1;
			end = y2;

		}

		for (int i = start; i <= end; i++) {
			if (boardGame.position[x1][i].isValid == 1) {
				dem++;
				if (dem == 2) {
					return false;
				}
			}
		}

		if ((dem == 1) && ((!boardGame.position[x1][y1].isValid && boardGame.position[x2][y2].isValid) || (boardGame.position[x1][y1].isValid && !boardGame.position[y1][y2].isValid))) {
			return true;
		}
		else if (dem == 0) {
			return true;
		}
		return false;
	}

	dem = 0;


	if (y1 == y2) {
		if (x1 > x2) {
			start = x2;
			end = x1;
		}
		else {
			start = x1;
			end = x2;

		}

		for (int i = start; i <= end; i++) {
			if (boardGame.position[i][y1].isValid == 1) {
				dem++;
				if (dem == 2) {
					return false;
				}
			}
		}

		if ((dem == 1) && ((!boardGame.position[x1][y1].isValid && boardGame.position[x2][y2].isValid) || (boardGame.position[x1][y1].isValid && !boardGame.position[y1][y2].isValid))) {
			return true;
		}
		else if (dem == 0) {
			return true;
		}
		return false;
	}


}

bool IMatching(Board boardGame, int x1, int y1, int x2, int y2) {
	int dem = 0;
	int start, end;

	if (y1 == y2) {
		if (x1 < x2) {
			start = x1;
			end = x2;

		}
		else {
			start = x2;
			end = x1;

		}

		for (int i = 1; i < end - start; i++) {
			if (boardGame.position[start + i][y1].isValid == 1) {
				dem++;
				break;
			}
		}
		if (dem == 1) {
			return false;
		}

		return true;
	}

	dem = 0;

	if (x1 == x2) {
		if (y1 < y2) {
			start = y1;
			end = y2;

		}
		else {
			start = y2;
			end = y1;

		}

		for (int i = 1; i < end - start; i++) {
			if (boardGame.position[x1][start + i].isValid == 1) {
				dem++;
				break;
			}
		}
		if (dem == 1) {
			return false;
		}

		return true;

	}

	return false;

}


bool LMatching(Board boardGame, int x1, int y1, int x2, int y2) {
	if (x1 == x2 || y1 == y2) {
		return false; // I Matching not L Matching
	}

	bool Check1 = false, Check2 = false;

	if (boardGame.position[x1][y2].isValid == 0) {
		Check1 = lineMatching(boardGame, x1, y1, x1, y2);
		Check2 = lineMatching(boardGame, x1, y2, x2, y2);

		if (Check1 && Check2) {
			return true;
		}
	}

	if (boardGame.position[x2][y1].isValid == 0) {
		Check1 = lineMatching(boardGame, x1, y1, x2, y1);
		Check2 = lineMatching(boardGame, x2, y1, x2, y2);

		if (Check1 && Check2) {
			return true;
		}
	}

	return false;

}

bool UMatching(Board boardGame, int p1, int p2, int q1, int q2) {
	//if (x1 == x2 || x1 == x2 + 1 || x1 == x2 - 1 || y1 == y2 || y1 == y2 - 1 || y1 == y2 + 1) {
	//	return false; // I,L matching not U Matching
	//}

	//bool Check1 = false, Check2 = false, Check3 = false;
	//int start, end;

	//if (boardGame.charArr[x1][y1] == boardGame.charArr[x2][y2]) {
	//	start = x1;


	//	for (int i = start + 2; i <= BOARDWIDTH; i++) {
	//		if (i < BOARDWIDTH) {
	//			Check3 = IMatching(boardGame, i, y1, i, y2);

	//		}

	//		if (Check3) {
	//			if (i >= x1 && i >= x2) {
	//				Check1 = IMatching(boardGame, x1, y1, i, y1);
	//				Check1 = IMatching(boardGame, x2, y2, i, y2);
	//				if (Check1 && Check2) {
	//					return true;
	//				}
	//			}
	//		}

	//		if (i == BOARDWIDTH) {
	//			if (i >= x1 && i >= x2) {
	//				Check1 = IMatching(boardGame, x1, y1, i - 1, y1);
	//				Check1 = IMatching(boardGame, x2, y2, i - 1, y2);
	//				if (Check1 && Check2) {
	//					return true;
	//				}
	//			}
	//		}

	//	}

	//	Check1 = false, Check2 = false, Check3 = false;

	//	for (int i = start - 2; i >= -1; i--) {
	//		if (i >= -1) {
	//			Check3 = IMatching(boardGame, i, y1, i, y2);
	//		}

	//		if (Check3 || i == -1) {
	//			if (i <= x1 && i <= x2);

	//			Check1 = IMatching(boardGame, x1, y1, i, y1);
	//			Check1 = IMatching(boardGame, x2, y2, i, y2);
	//			if (Check1 && Check2) {
	//				return true;
	//			}
	//		}

	//		if (i == -1) {
	//			if (i <= x1 && i <= x2) {
	//				Check1 = IMatching(boardGame, x1, y1, i + 1, y1);
	//				Check1 = IMatching(boardGame, x2, y2, i + 1, y2);
	//				if (Check1 && Check2) {
	//					return true;
	//				}
	//			}
	//		}

	//	}


	//	Check1 = false, Check2 = false, Check3 = false;

	//	start = y1;

	//	for (int i = start + 2; i <= BOARDHEIGHT; i++) {
	//		if (i <= BOARDHEIGHT) {
	//			Check3 = IMatching(boardGame, x1, i, x2, i);

	//		}

	//		if (Check3 ) {
	//			if (y1 <= i && y2 <= i) {
	//				Check1 = IMatching(boardGame, x1, y1, x1, i);
	//				Check1 = IMatching(boardGame, x2, y2, x2, i);
	//				if (Check1 && Check2) {
	//					return true;
	//				}
	//			}
	//			
	//		}

	//		if (i == BOARDHEIGHT) {
	//			if (y1 <= i && y2 <= i) {
	//				Check1 = IMatching(boardGame, x1, y1, x1, i - 1);
	//				Check1 = IMatching(boardGame, x2, y2, x2, i - 1);
	//				if (Check1 && Check2) {
	//					return true;
	//				}
	//			}

	//		}

	//	}

	//	Check1 = false, Check2 = false, Check3 = false;

	//	for (int i = start - 2; i <= -1; i++) {
	//		if (i > - 1) {
	//			Check3 = IMatching(boardGame, x1, i, x2, i);

	//		}

	//		if (Check3) {
	//			if (i <= y1 && i <= y2) {
	//				Check1 = IMatching(boardGame, x1, y1, x1, i);
	//				Check1 = IMatching(boardGame, x2, y2, x2, i);
	//				if (Check1 && Check2) {
	//					return true;
	//				}
	//			}

	//			
	//		}

	//		if (i == -1) {
	//			if (i <= y1 && i <= y2) {
	//				Check1 = IMatching(boardGame, x1, y1, x1, i + 1);
	//				Check1 = IMatching(boardGame, x2, y2, x2, i + 1);
	//				if (Check1 && Check2) {
	//					return true;
	//				}
	//			}
	//		}

	//	}

	//	
	//}

	//return false;

	if (((p1 == q1) && (p1 == 0 || p1 == BOARDHEIGHT - 1) || ((p2 == q2) && (p2 == 0 || q2 == BOARDWIDTH - 1)))) {
		return true;
	}
	bool c1, c2, c3;
	int x, y;
	if (q2 < p2) {
		x = q2;
		y = p2;
	}
	else {
		x = p2;
		y = q2;
	}
	for (int i = 0; i < BOARDWIDTH; i++) {
		if (i <= x || i >= y) {
			c3 = lineMatching(boardGame, p1, i, q1, i);
			if (c3) {
				c1 = lineMatching(boardGame, p1, p2, p1, i);
				c2 = lineMatching(boardGame, q1, q2, q1, i);
				if (c1 && c2) {
					return true;
				}
			}
			else if (i == 0 || i == (BOARDWIDTH - 1)) {
				c1 = lineMatching(boardGame, p1, p2, p1, i);
				c2 = lineMatching(boardGame, q1, q2, q1, i);
				if ((c1 && c2) || (c1 && q2 == i) || (p2 == i && c2)) {
					return true;
				}
			}
		}
	}

	if (q1 < p1) {
		x = q1;
		y = p1;
	}
	else {
		x = p1;
		y = q1;
	}
	for (int i = 0; i < BOARDHEIGHT; i++) {
		if (i <= x || i >= y) {
			c3 = lineMatching(boardGame, i, p2, i, q2);
			if (c3) {
				c1 = lineMatching(boardGame, p1, p2, i, p2);
				c2 = lineMatching(boardGame, q1, q2, i, q2);
				if (c1 && c2) {
					return true;
				}
			}
			else if (i == 0 || i == (BOARDHEIGHT - 1)) {
				c1 = lineMatching(boardGame, p1, p2, i, p2);
				c2 = lineMatching(boardGame, q1, q2, i, q2);
				if ((c1 && c2) || (c1 && q1 == i) || (p1 == i && c2)) {
					return true;
				}
			}
		}
	}
	return false;
}

bool ZMatching(Board boardGame, int x1, int y1, int x2, int y2) {

	if (x1 == x2 || y1 == y2) {
		return false;

	}

	bool Check1 = false, Check2 = false, Check3 = false;
	int start, end;

	if (x1 < x2) {
		start = x1;
		end = x2;

	}
	else {
		start = x2;
		end = x1;

	}

	for (int i = start + 1; i < end; i++) {
		Check3 = lineMatching(boardGame, i, y1, i, y2);
		if (Check3) {
			Check1 = lineMatching(boardGame, x1, y1, i, y1);
			Check2 = lineMatching(boardGame, x2, y2, i, y2);
			if (Check1 && Check2) {
				return true;
			}

		}
	}

	if (y1 < y2) {
		start = y1;
		end = y2;

	}
	else {
		start = y2;
		end = y1;

	}

	for (int i = start + 1; i < end; i++) {
		Check3 = lineMatching(boardGame, x1, i, x2, i);
		if (Check3) {
			Check1 = lineMatching(boardGame, x1, i, x1, x2);
			Check2 = lineMatching(boardGame, x2, i, x2, y2);
			if (Check1 && Check2) {
				return true;
			}

		}
	}


	return false;
}

bool CheckAll(Board boardGame, int x1, int y1, int x2, int y2) {
	if (nextMatching(boardGame, x1, y1, x2, y2)) {
		return true;
	}
	else if (IMatching(boardGame, x1, y1, x2, y2)) {
		return true;
	}
	else if (LMatching(boardGame, x1, y1, x2, y2)) {
		return true;
	}
	else if (ZMatching(boardGame, x1, y1, x2, y2)) {
		return true;
	}
	else if (UMatching(boardGame, x1, y1, x2, y2)) {
		return true;
	}

	return false;
}

void check(Board boardGame, Point selectedPos[], int& couple) {
	if (boardGame.charArr[selectedPos[0].y][selectedPos[0].x] == boardGame.charArr[selectedPos[1].y][selectedPos[1].x]) {
		if (CheckAll(boardGame, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x)) {
			drawElement(boardGame, selectedPos[0].y, selectedPos[0].x, 40);
			drawElement(boardGame, selectedPos[1].y, selectedPos[1].x, 40);


			Sleep(500);

			boardGame.position[selectedPos[0].y][selectedPos[0].x].isValid = 0;
			removeElement(boardGame, selectedPos[0].y, selectedPos[0].x);

			boardGame.position[selectedPos[1].y][selectedPos[1].x].isValid = 0;
			removeElement(boardGame, selectedPos[1].y, selectedPos[1].x);

		}

		else {
			drawElement(boardGame, selectedPos[0].y, selectedPos[0].x, 70);
			drawElement(boardGame, selectedPos[1].y, selectedPos[1].x, 70);

			Sleep(500);
		}
	}
	else {
		drawElement(boardGame, selectedPos[0].y, selectedPos[0].x, 70);
		drawElement(boardGame, selectedPos[1].y, selectedPos[1].x, 70);

		Sleep(500);
	}

	boardGame.position[selectedPos[0].y][selectedPos[0].x].isSelected = 0;
	boardGame.position[selectedPos[1].y][selectedPos[1].x].isSelected = 0;
	couple = 2;
	selectedPos[0] = { -1, -1 };
	selectedPos[1] = { -1, -1 };
}


