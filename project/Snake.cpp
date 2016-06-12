#include"Snake.h"
Snake::Snake()
{
	body.push_back(strucPos(0, 0));
	body.push_back(strucPos(0, -1));
	crashed = false;
}
void Snake::move(vector<vector<int>> & board_XY, Board  * const board)
{
	//根据前进方向更新蛇身位置
	auto it = body.begin();
	if (direction == up)
	{
		body.insert(body.begin(), *it);
		body.at(0).y += 1;

		board_XY[body.at(0).x + boardSize - 1][body.at(0).y + boardSize - 1] = 1;
	}
	if (direction == right)
	{
		body.insert(body.begin(), *it);
		body.at(0).x += 1;

		board_XY[body.at(0).x + boardSize - 1][body.at(0).y + boardSize - 1] = 1;
	}
	if (direction == down)
	{
		body.insert(body.begin(), *it);
		body.at(0).y -= 1;

		board_XY[body.at(0).x + boardSize - 1][body.at(0).y + boardSize - 1] = 1;
	}
	if (direction == left)
	{
		body.insert(body.begin(), *it);
		body.at(0).x -= 1;

		board_XY[body.at(0).x + boardSize - 1][body.at(0).y + boardSize - 1] = 1;
	}
    //检测是否吃到食物
	if (board->foodPos.x != body.at(0).x||board->foodPos.y != body.at(0).y)
	{
		board_XY[(body.end() - 1)->x + boardSize - 1][(body.end() - 1)->y + boardSize - 1] = 0;
		body.erase(body.end() - 1);
	}
	else
	{
		board->foodPos = board->createFood();
	}
    //检查碰撞
	if (checkCrash())
		crashed = true;


}

//检查不能走的方向
void Snake::dirCheck()
{
	int x = body.at(1).x - body.at(0).x;
	int y = body.at(1).y - body.at(0).y;

	if (x == 1) direction_nallow = right;
	if (x == -1) direction_nallow = left;
	if (y == 1) direction_nallow = up;
	if (y == -1) direction_nallow = down;
}

bool Snake::checkCrash()
{
	//检测是否撞到自己
	auto head = body.begin();
	for (auto it = body.begin() + 1; it != body.end(); it++)
	{
		if (head->x == it->x&&head->y==it->y)
			return true;
	}
	//检测是否撞墙
	if (body.at(0).x == boardSize
		|| body.at(0).x == -boardSize + 1
		|| body.at(0).y == boardSize
		|| body.at(0).y == -boardSize + 1)
	{
		return true;
	}

	return false;
}





