#include "Standard.h"

bool nextMatching(Board boardGame, int x1, int y1, int x2, int y2);
bool lineMatching(Board boardGame, int x1, int y1, int x2, int y2);

bool IMatching(Board boardGame, int x1, int y1, int x2, int y2);
bool LMatching(Board boardGame, int x1, int y1, int x2, int y2);
bool UMatching(Board boardGame, int x1, int y1, int x2, int y2);
bool ZMatching(Board boardGame, int x1, int y1, int x2, int y2);

bool CheckAll(Board boardGame, int x1, int y1, int x2, int y2);

void check(Board boardGame, Point selectedPos[], int& couple);

