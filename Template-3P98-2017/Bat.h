#pragma once
#include <freeglut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <FreeImage.h>
#include <math.h>
class Bat {
public:
	void SetPosX(float a) { x = a; };
	void SetPosY(float a) { y = a; };
	void SetWidth(float a) { width = a; };
	void SetHeight(float inHeight) { height = inHeight; };
	void SetSpeed(float speed) { speedX = speed; };
	float GetPosX() { return x; };
	float GetPosY() { return y; };
	float GetWidth() { return width; };
	float GetHeight() { return height; };
	float GetSpeed() { return speedX; };
	void Draw();
	void Init(float posX, float posY, float sizeX, float sizeY, float speed);
private:
	float x, y;
	float width, height;
	float speedX;
	void Update();
	void LoadTexture();
};