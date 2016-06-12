#ifndef _keyEvent_H_
#define _keyEvent_H_ 
#include"Snake.h"
using namespace std;
 class Snake ;
class keyEvent
{
public:
	  Snake *snk;
public:
	keyEvent(Snake* snake) { snk = snake; };
	 void KeyDown(unsigned char key,int x,int y);
};
#endif
