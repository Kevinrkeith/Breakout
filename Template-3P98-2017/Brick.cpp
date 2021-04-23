#include "Brick.h"

void Brick::Init(int x, int y, int sizeX, int sizeY)
{
	posX = x/2;
	posY = y*0.75;
	width = sizeX;
	height = sizeY;
}

void Brick::Draw()
{
	glColor3f(0, 0, 1);
	glBegin(GL_QUADS);
	glVertex2f(posX, posY);
	glVertex2f(posX + width, posY);
	glVertex2f(posX + width, posY + height);
	glVertex2f(posX, posY + height);
	glEnd();
}

void Brick::SetBallHitBox(Ball ball)
{
	ballHitbox.sizeX = ball.GetHeight();
	ballHitbox.sizeY = ball.GetWidth();
	ballHitbox.x = ball.GetPosX();
	ballHitbox.y = ball.GetPosY();
}
