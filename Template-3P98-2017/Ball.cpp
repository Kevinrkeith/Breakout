#include "Ball.h"
#include <vector>
#include <stdio.h>

void Ball::SetBatHitboxes(Bat bat)
{
	hitBox.posX = bat.GetPosX();
	hitBox.posY = bat.GetPosY();
	hitBox.posWidth = bat.GetWidth();
	hitBox.posHeight = bat.GetHeight();
}

void Ball::LoadTexture(int texID)
{
	textureID = texID;
}

void Ball::Draw()
{
	//glColor3f(0, 0, 1);
	//glBegin(GL_QUADS);
	//glVertex2f(x, y);
	//glVertex2f(x + width, y);
	//glVertex2f(x + width, y + height);
	//glVertex2f(x, y + height);
	//glEnd(); //Testing hit boxes
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		float theta = i * 3.14159265359 / 180;
		glVertex2f(width * cos(theta) + x, height * sin(theta) + y);
	}
	glEnd();

	Update();
}

void Ball::Init(float posX, float posY, float sizeX, float sizeY, float speedX, float speedY)
{
	screenWidth = posX;
	screenHeight = posY;
	x = posX / 2;
	y = posY / 2;
	width = sizeX;
	height = sizeY;
	movementX = speedX;
	movementY = speedY;
	/*hitBox.posX = bat.GetPosX();
	hitBox.posY = bat.GetPosY();
	hitBox.posHeight = bat.GetHeight();
	hitBox.posWidth = bat.GetWidth();*/
}

void Ball::Update()
{

	if (x > screenWidth || x < 0) {
		movementX *= -1;
	}
	if (y > screenHeight || y < 0) {
		movementY *= -1;
	}
	/*Bat Hitboxes*/
	if (CollisionWithBat()) {
		movementY *= -1;
	}
	x += movementX;
	y += movementY;
}

bool Ball::CollisionWithBat() //Creates hitboxes
{
	//Based on AABB collision
	if (x >= hitBox.posX && x < hitBox.posX + hitBox.posWidth) //Checks the x Pos of the ball
		if (y >= hitBox.posY && y < hitBox.posHeight + hitBox.posY) //Checks the Y pos of the ball
			return true;
	return false;
}
