#pragma once

#include "libs/OpenGL/glut.h"

#include "Helpers.h"

class Player{
public:
	float dx,dy;
	int X, Y;
	bool Right, Left;

	Player()
	{
		Right = Left = false;
		dx = 0;
		dy = 0;

		playerRadius = (ScreenHeight > ScreenWidth ? ScreenWidth : ScreenHeight) / 12;
		X = ScreenWidth / 2 - playerRadius / 2;
		Y = ScreenHeight - playerRadius;
	}

	void Update(){    
		if (Right) X += 25;
		if (Left)  X -= 25;
		dy = dy - Gravity;
		Y -= int(dy);
		if (Y >= ScreenHeight - playerRadius / 2) {Y = ScreenHeight; dy = 40;} 
		if(Y < 0){Y = 0;}   

		X += int(dx);
 
		if(X < 0)  {X = ScreenWidth; dx =- dx;}
		if(X > ScreenWidth) { X = 0; dx = -dx;}
	}

	void Draw(){
		glColor3f(1, 0, 0);
		glTranslatef(X, Y, 0);
		float PI = 3.1415;
		glBegin(GL_POLYGON);
		for(double i = 0; i < 2 * PI; i += PI / 50)
			glVertex2f(cos(i) * playerRadius, sin(i) * playerRadius);
		glEnd();
	}
private:
	int playerRadius;
};