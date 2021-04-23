/* An example of how to read an image (img.tif) from file using freeimage and then
display that image using openGL's drawPixelCommand. Also allow the image to be saved
to backup.tif with freeimage and a simple thresholding filter to be applied to the image.
Conversion by Lee Rozema.
Added triangle draw routine, fixed memory leak and improved performance by Robert Flack (2008)
*/
using namespace std;
#define FILENAME "img.tif"

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <freeglut.h>
#include <FreeImage.h>
#include <Windows.h>
#include<vector>
#include "Brick.h"
#include "Bat.h"
#include "Ball.h"
Bat bat;
Ball ball;
vector<Brick> bricks;
int width = 1280, height = 720;
float speed = 0.5;
void InitializeBricks(){
	for (int i = 0; i < 30; i++) {
		Brick temp;
		temp.Init(, , 80, 40);
		bricks.push_back();
	}
}
void Display(void) {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	ball.SetBatHitboxes(bat);
	ball.Draw();
	bat.Draw();
	glutSwapBuffers();
	glutPostRedisplay();
}
void keyUp(unsigned char key, int x, int y) {
	switch (key) {
	case'a':
	case 'A':
		bat.SetSpeed(0);
		break;
	case'd':
	case 'D':
		bat.SetSpeed(0);
		break;
	}
}
void keyPressed(unsigned char key, int x, int y) {
	switch (key) {
	case'a':
	case 'A':
		bat.SetSpeed(-speed);
		break;
	case'd':
	case 'D':
		bat.SetSpeed(speed);
		break;
	}
}
int main(int argc, char** argv)
{
	bat.Init(width, height, 160, 40, 0);
	ball.Init(width, height, 13, 13, 0.25, 0.25);
	InitializeBricks();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(width, height);
	glutCreateWindow("Brick Breaker - Kevin Keith");
	glShadeModel(GL_SMOOTH);
	glutDisplayFunc(Display);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, width, 0, height, 0, 1);

	glutMainLoop();

	return 0;
}