#include"keyEvent.h"


void keyEvent::KeyDown(unsigned char key, int x, int y)
{
	snk->dirCheck();//检测不能走的方向
	//根据按键值设定方向
	if (key == 'w')
	{
		if ( snk->up != snk->direction_nallow)
		snk->direction = snk->up;
	}
	if (key == 'a')
	{
		if (snk->left != snk->direction_nallow)
		snk->direction = snk->left;
	}
	if (key == 's')
	{
		if (snk->down != snk->direction_nallow)
		snk->direction = snk->down;
	}
	if (key == 'd')
	{
		if (snk->right != snk->direction_nallow)
		snk->direction = snk->right;
	}
}
