#pragma once

#include "Helpers.h"
#include "Scene.h"

class Platforms{
public:
	int X, Y;

	Platforms(){
		X = rand()%ScreenWidth-100;
		Y = rand()%ScreenHeight;
	}
	void New(){
		X = rand()%ScreenWidth-100;
		Y = ScreenHeight;
	}
	void move(){
		if(Scene::GetInstance().GetPlayer().Y >= 500){
			Y -= int(Scene::GetInstance().GetPlayer().dy);
		}
	}

	void Draw(){
		glColor3f(1, 0, 0);
		glTranslatef(X, Y, 0);
		float PI = 3.1415;
		glBegin(GL_POLYGON);
		for(double i = 0; i < 2 * PI; i += PI / 50)
			glVertex2f(cos(i) * 20, sin(i) * 20);
		glEnd();
	}

} Platform[PlatformsCount];