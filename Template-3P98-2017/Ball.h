#pragma once
#include <freeglut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <FreeImage.h>
#include <math.h>
#include "Bat.h"

class Ball {
	typedef struct {
		float posX, posWidth, posY, posHeight;
	}BatHitbox;
public:
	void SetPosX(float a) { x = a; };
	void SetPosY(float a) { y = a; };
	void SetWidth(float a) { width = a; };
	void SetHeight(float inHeight) { height = inHeight; };
	void SetSpeedX(float speed) { movementX = speed; };
	void SetSpeedY(float speed) { movementY = speed; };
	void SetBatHitboxes(Bat bat);
	float GetPosX() { return x; };
	float GetPosY() { return y; };
	float GetWidth() { return width; };
	float GetHeight() { return height; };
	float GetSpeedX() { return movementX; };
	float GetSpeedY() { return movementY; };
	void LoadTexture(int texID);
	void Draw();
	void Init(float posX, float posY, float sizeX, float sizeY, float speedX, float speedY);
private:
	float x, y;
	float width, height;
	float radius;
	float movementX, movementY;
	int textureID;
	float screenWidth, screenHeight;
	BatHitbox hitBox;
	void Update();
	bool CollisionWithBat();
	bool CollisionWithBrick();
};