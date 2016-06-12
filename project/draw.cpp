#include"draw.h"

void Draw::DrawString(void *font, const char s[], float x, float y)
{
	glColor3f(0, 0, 0);
	unsigned int i;
	glRasterPos2f(x, y);
	for (i = 0; i < strlen(s); i++)
	{
		glutBitmapCharacter(font, s[i]);
	}
}

void Draw::DrawGrid()
{
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);

	float row = boardSize * 10 + 10;
	float column = -boardSize * 10 - 10;
	for (int i = 0; i < boardSize * 2 + 1; i++)
	{
		row -= 10;              column += 10;

		glVertex2f(-boardSize * 10, row);			glVertex2f(boardSize * 10, row);

		glVertex2f(column, -boardSize * 10);			glVertex2f(column, boardSize * 10);
	}
	glEnd();
}

void Draw::DrawSnake(vector<strucPos>  &  body)
{

	for (auto it = body.begin(); it != body.end(); it++)
	{
		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);

		glVertex2f(it->x * 10 - 10, it->y * 10);     // 左上
		glVertex2f(it->x * 10, it->y * 10);     // 右上
		glVertex2f(it->x * 10, it->y * 10 - 10);     // 右下
		glVertex2f(it->x * 10 - 10, it->y * 10 - 10);     // 左下
		glEnd();
	}
}

void Draw::DrawFood(strucPos foodpos)
{


	glBegin(GL_QUADS);
	glColor3f(0.96, 0.6, 0.5);

	glVertex2f(foodpos.x * 10 - 10, foodpos.y * 10);     // 左上
	glVertex2f(foodpos.x * 10, foodpos.y * 10);     // 右上
	glVertex2f(foodpos.x * 10, foodpos.y * 10 - 10);     // 右下
	glVertex2f(foodpos.x * 10 - 10, foodpos.y * 10 - 10);     // 左下
	glEnd();
}

void Draw::DrawWall()
{


		for (int cnt = 0; cnt < boardSize * 2; cnt++)
		{
			glBegin(GL_QUADS);
			glColor3f(0.7, 0.6, 0.5);

			glVertex2f(-boardSize * 10+10*cnt, -boardSize * 10+10);     // 左上
			glVertex2f(-boardSize * 10 + 10 + 10 * cnt, -boardSize * 10 + 10 );     // 右上
			glVertex2f(-boardSize * 10 + 10 + 10 * cnt, -boardSize * 10   );     // 右下
			glVertex2f(-boardSize * 10 + 10 * cnt, - boardSize * 10 );     // 左下
			glEnd();
		}
		for (int cnt = 0; cnt < boardSize * 2; cnt++)
		{
			glBegin(GL_QUADS);
			glColor3f(0.7, 0.6, 0.5);

			glVertex2f(-boardSize * 10 + 10 * cnt, boardSize * 10 );     // 左上
			glVertex2f(-boardSize * 10 + 10 + 10 * cnt, boardSize * 10 );     // 右上
			glVertex2f(-boardSize * 10 + 10 + 10 * cnt, boardSize * 10-10);     // 右下
			glVertex2f(-boardSize * 10 + 10 * cnt, boardSize * 10-10);     // 左下
			glEnd();
		}

		for (int cnt = 0; cnt < boardSize * 2; cnt++)
		{
			glBegin(GL_QUADS);
			glColor3f(0.7, 0.6, 0.5);

			glVertex2f(-boardSize * 10 , -boardSize * 10 + 10 + 10 * cnt);     // 左上
			glVertex2f(-boardSize * 10 + 10 , -boardSize * 10 + 10 + 10 * cnt);     // 右上
			glVertex2f(-boardSize * 10 + 10 , -boardSize * 10 + 10 * cnt);     // 右下
			glVertex2f(-boardSize * 10 , -boardSize * 10 + 10 * cnt);     // 左下
			glEnd();
		}
	
		for (int cnt = 0; cnt < boardSize * 2; cnt++)
		{
			glBegin(GL_QUADS);
			glColor3f(0.7, 0.6, 0.5);

			glVertex2f(boardSize * 10-10, -boardSize * 10 + 10 + 10 * cnt);     // 左上
			glVertex2f(boardSize * 10 , -boardSize * 10 + 10 + 10 * cnt);     // 右上
			glVertex2f(boardSize * 10 , -boardSize * 10 + 10 * cnt);     // 右下
			glVertex2f(boardSize * 10-10, -boardSize * 10 + 10 * cnt);     // 左下
			glEnd();
		}

	

}

void Draw::gameOver()
{
	DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "Game Over!", -50, 0);
}

void  Draw::myReshape(GLsizei w, GLsizei h)
{
	GLfloat aspectRatio;
	// 防止被0所除
	if (0 == h)
	{
		h = 1;
	}
	glViewport(0, 0, w, h);// 设置视口为窗口的大小
	glMatrixMode(GL_PROJECTION);// 对投影矩阵应用随后的矩阵操作
	glLoadIdentity();//变换矩阵复位
	aspectRatio = (GLfloat)w / (GLfloat)h; // 计算窗口的纵横比（像素比）
	// 定义裁剪区域（根据窗口的纵横比，并使用正投影）
	if (w <= h) {// 宽 < 高
		glOrtho(-boardSize * 10, boardSize * 10, -boardSize * 10 / aspectRatio, boardSize * 10 / aspectRatio, 1.0, -1.0);
	}
	else {// 宽 > 高
		glOrtho(-boardSize * 10 * aspectRatio, boardSize * 10 * aspectRatio, -boardSize * 10, boardSize * 10, 1.0, -1.0);
	}
	glMatrixMode(GL_MODELVIEW);// 选择模型视图矩阵，并重置坐标系统
	glLoadIdentity();
}

void Draw::myDisplay(void) {

	glClearColor(0.96, 0.96, 0.863, 1.0);//000黑色,111白色
	glClear(GL_COLOR_BUFFER_BIT);
	//DrawGrid();
	//DrawSquare(0,0);
	glutSwapBuffers();
}