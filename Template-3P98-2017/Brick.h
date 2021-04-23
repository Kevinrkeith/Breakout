#pragma once
#include "Ball.h"
class Brick {
	typedef struct {
		float x, y, sizeX, sizeY;
	}Hitbox;
public:
	void Init(int x, int y, int sizeX, int sizeY);
	void Draw();
	void SetBallHitBox(Ball ball);
private:
	float posX, posY, width, height;
	Hitbox ballHitbox;
};