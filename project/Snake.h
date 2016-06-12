#ifndef _Snake_H_
#define _Snake_H_ 
#include"Board.h"

using namespace std;
extern struct strucPos;
class Snake
{
public:
	vector<strucPos> body;
	enum { up, right, down, left };
	int direction = up;
	int direction_nallow = down;
	bool crashed;
public:
	Snake();
	void move(vector<vector<int>> & board_XY, Board  * const board);
	void dirCheck();
	bool checkCrash();
};
#endif