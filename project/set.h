#ifndef _SET_H_
#define _SET_H_ 
static float boardSize = 20;
extern struct strucPos {
	int x;
	int y;
	strucPos() {}
	strucPos(int _x, int _y) :x(_x),y(_y){ }
};
#endif