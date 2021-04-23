#include "Bat.h"

void Bat::Draw()
{
	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x+width, y);
	glVertex2f(x+width, y+height);
	glVertex2f(x, y+height);
	glEnd();
	Update();
}

void Bat::Init(float posX, float posY, float sizeX, float sizeY, float speed)
{
	x = posX/2;
	y = posY*0.15;
	width = sizeX;
	height = sizeY;
	speedX = speed;
	
}

void Bat::Update()
{
	x += speedX;
}

void Bat::LoadTexture()
{
}
