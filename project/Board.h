#ifndef _Board_H_
#define _Board_H_ 
//#include"GluttonousSnake.h"
#include"set.h"
#include<vector>
#include <functional> 
#include<random>
#include<time.h>

#include<iostream>
#include<fstream>
using namespace std;

class Board
{
	
public:
	vector<vector<int>> board_XY;
	strucPos foodPos;
	//ofstream file;
public:
	Board();
	strucPos createFood();
	int myRandom(int begin, int end);


	
};
#endif