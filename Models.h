#pragma once


#include <vector>
#include <iostream>

using namespace std;

#include "libs/OpenGL/glut.h"

#include "Helpers.h"

class Player
{
public:
	float dx,dy;
	int X, Y;
	bool Right, Left;

	Player()
	{
		Right = Left = false;
		dx = 0;
		dy = 0;

		PlayerRadius = (ScreenHeight > ScreenWidth ? ScreenWidth : ScreenHeight) / 12;
		X = ScreenWidth / 2 - PlayerRadius / 2;
		Y = ScreenHeight - PlayerRadius;
	}

	void Update(){    
		if (Right) X += 25;
		if (Left) X -= 25;
		dy = dy - Gravity;
		Y += int(dy);
		if (Y >= ScreenHeight) Y = ScreenHeight;

		X += int(dx);

		if(Y < 0) {Y = 0; dy = 40; dx = dx;}    
		if(X < 0) {X = 0; dx = -dx;}
		if(X > ScreenWidth) {X = ScreenWidth; dx = -dx;}
	}

	void Draw(){
		glPushMatrix();

		glColor3f(1, 0, 0);
		glTranslatef(X, Y, 0);

		float PI = 3.1415;

		glBegin(GL_POLYGON);
			for(double i = 0; i < 2 * PI; i += PI / 50)
				glVertex2f(cos(i) * PlayerRadius, sin(i) * PlayerRadius);
		glEnd();

		glPopMatrix();
	}

	int PlayerRadius;
};

class Scene
{
public:
	Scene()
	{
		player = new Player();
	}

	static Scene GetInstance()
	{
		static Scene instance;
		return instance;
	}

	void Update()
	{
			
		player->Update();
	}

	void Draw()
	{
		player->Draw();
	}

	Player* GetPlayer()
	{
		return player;
	}
protected:
	Player* player;
};

class Platforms
{
public:
	int X, Y, Width;

	Platforms()
	{
		X = rand()%(ScreenWidth - 100) + 50;
		Y = rand()%ScreenHeight;
		Width = PlatformWidth;
	}

	void New()
	{
		X = rand()%(ScreenWidth - 100) + 50;
		Y = ScreenHeight;
		Width = PlatformWidth;
	}

	void Update()
	{
		if(Scene::GetInstance().GetPlayer()->Y >= 500){
			Y -= int(Scene::GetInstance().GetPlayer()->dy);
		}
	}

	void Draw(){
		glPushMatrix();

		glColor3f(0, 0, 0);
		glTranslatef(X, Y, 0);

		glBegin(GL_LINES);
			glVertex2f(X, Y);
			glVertex2f(X + PlatformWidth, Y);
		glEnd();

		glPopMatrix();
	}

} Platform[PlatformsCount];