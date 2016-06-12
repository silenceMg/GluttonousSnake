#include "GluttonousSnake.h"


static Draw* draw = 0;
static Board* board = 0;
static keyEvent* key_event = 0;
static Snake* snake = 0;


void timerProc(int id)
{

	glClearColor(0.96, 0.96, 0.863, 1.0);//000黑色,111白色
	glClear(GL_COLOR_BUFFER_BIT);
	if (!snake->crashed)
	{	

		snake->move(board->board_XY, board);//蛇身的移动要更新board矩阵
		draw->DrawSnake(snake->body);//绘制过程要获得蛇身的信息
		draw->DrawFood(board->foodPos);//board创造食物，绘制过程要获得board类的信息
		draw->DrawGrid();
		draw->DrawWall();
	}
	else
	{
		//draw->DrawSnake(snake->body);//绘制过程要获得蛇身的信息
		//draw->DrawFood(board->foodPos);//board创造食物，绘制过程要获得board类的信息
		draw->DrawGrid();
		draw->DrawWall();
		draw->gameOver();
	}

	glutSwapBuffers();
	glutTimerFunc(500, timerProc, 1);//需要在函数中再调用一次，才能保证循环  
}

void myReshape(int x, int y)
{
	draw->myReshape(x, y);
}
void myDisplay()
{
	draw->myDisplay();
}
void KeyDown(unsigned char key, int x, int y)
{
	key_event->KeyDown(key, x, y);
}
int main(int argc, char ** argv) {
	/*初始化*/
	draw = new Draw;
	board = new Board;
	snake = new Snake;
	key_event = new keyEvent(snake);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);//双缓冲、RGB模式
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Gluttonous Snake");//窗口标题
	glShadeModel(GL_SMOOTH);//设置为光滑明暗模式
							/*绘制与显示*/
	glutReshapeFunc(myReshape);//窗口大小发生改变时采取的行为
	glutDisplayFunc(myDisplay);//显示绘制图形
	glutTimerFunc(500, timerProc, 1);
	glutKeyboardFunc(KeyDown);
	//glutMouseFunc(mouse);
	//glutIdleFunc(myDisplay);
	glutMainLoop();//循环

	delete draw;
	delete board;
	delete snake;
	delete key_event;
	return(0);
}

