#include "Location.h"
#include <stack>
using namespace std;

const int MAZE_SIZE_WIDTH = 6;
const int MAZE_SIZE_HEIGHT = 7;
char map[MAZE_SIZE_WIDTH][MAZE_SIZE_HEIGHT] = {
	{'O', 'O', 'O', 'O', 'O', 'O'},
	{'e', 'X', 'O', 'O', 'O', 'X'},
	{'O', 'X', 'X', 'X', 'X', 'X'},
	{'O', 'X', 'O', 'X', 'O', 'O'},
	{'O', 'X', 'O', 'X', 'X', 'f'},
	{'O', 'O', 'O', 'O', 'O', 'O'},
};

bool isValidLoc(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE_HEIGHT || c >= MAZE_SIZE_WIDTH) return false;
	else return (map[r][c] == 'X' || map[r][c] == 'f');
}

void main() {
	stack<Location2D> locStack;
	Location2D entry(1, 0);
	locStack.push(entry);

	while (locStack.empty() == false) {
		Location2D here = locStack.top();
		locStack.pop();

		int r = here.row;
		int c = here.col;
		printf("(%d,%d) ", r, c);
		if (map[r][c] == 'f') {
			map[r][c] = 'X';
			printf("미로 탐색 성공\n\n");
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 7; j++)
					printf(" %c ", map[i][j]);
				printf("\n");
			}
			system("PAUSE");
			return;
		}
		else {
			map[r][c] = 'Y';
			if (isValidLoc(r - 1, c)) locStack.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c)) locStack.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1)) locStack.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1)) locStack.push(Location2D(r, c + 1));
		}
	}
	printf("미로 탐색 실패\n");

	system("PAUSE");
}