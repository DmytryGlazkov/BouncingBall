#pragma once


#include <vector>
#include <iostream>

using namespace std;

#include "libs/OpenGL/glut.h"

#include "Helpers.h"

#include "libs/SOIL/SOIL.h"

#pragma comment(lib, "./libs/SOIL/SOIL.lib")

class Player
{
public:
	float dx,dy;
	int X, Y;
	bool Right, Left;

	GLuint	texture;			// Storage For One Texture ( NEW )

	Player()
	{
		Right = Left = false;
		dx = 0;
		dy = 0;

		PlayerRadius = (ScreenHeight > ScreenWidth ? ScreenWidth : ScreenHeight) / 15;
		X = ScreenWidth / 2 - PlayerRadius / 2;
		Y = PlayerRadius;

		LoadGLTextures();
	}

	int LoadGLTextures()									// Load Bitmaps And Convert To Textures
	{
		/* load an image file directly as a new OpenGL texture */
		texture = SOIL_load_OGL_texture
			(
			"./Textures/Player.jpg",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

		if(texture == 0)
			return false;


		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

		return true;										// Return Success
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

		glColor3f(1, 1, 1);
		glTranslatef(X, Y, 0);

		float PI = 3.1415;

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_POLYGON);
		for(double i = 0; i < 2 * PI; i += PI / 50)
		{
			glTexCoord2d((cos(i) + 1) / 2, (sin(i) + 1) / 2);
			glVertex2f(cos(i) * PlayerRadius, sin(i) * PlayerRadius);
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);

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
		LoadGLTextures();
	}

	int LoadGLTextures()									// Load Bitmaps And Convert To Textures
	{
		/* load an image file directly as a new OpenGL texture */
		texture = SOIL_load_OGL_texture
			(
			"Textures/Background1.jpg",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

		if(texture == 0)
			return false;


		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

		return true;										// Return Success
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

	void DrawBackground()
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0); glVertex2f(0, 0);
			glTexCoord2d(1, 0); glVertex2f(ScreenWidth, 0);
			glTexCoord2d(1, 1); glVertex2f(ScreenWidth, ScreenHeight);
			glTexCoord2d(0, 1); glVertex2f(0, ScreenHeight);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}

	void Draw()
	{
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1, 1, 1);

		DrawBackground();

		glPopMatrix();
		if (Life)
			player->Draw();

		char buf[15] = "Score: ";
		itoa(Score / 10, buf + 7, 10);

		TextOut(0, ScreenHeight - 50, buf);
	}

	Player* GetPlayer()
	{
		return player;
	}
protected:
	Player* player;
	GLuint texture;
};

class Platforms
{
public:
	int X, Y, Width;

	Platforms()
	{
		X = rand()%(ScreenWidth - PlatformWidth) + PlatformWidth / 2;
		Y = rand()%ScreenHeight;
		Width = PlatformWidth;
	}

	void New()
	{
		X = rand()%(ScreenWidth - PlatformWidth) + PlatformWidth / 2;
		Y = ScreenHeight;
		Width = PlatformWidth;
	}

	void Update()
	{
		if(Scene::GetInstance().GetPlayer()->Y >= ScreenHeight / 3 * 2
			 && int(Scene::GetInstance().GetPlayer()->dy) > 0)
		{
			Y -= int(Scene::GetInstance().GetPlayer()->dy);
			Score  += int(Scene::GetInstance().GetPlayer()->dy);
		}
	}

	void Draw(){
		glPushMatrix();
		glLoadIdentity();

		glColor3f(1, 1, 1);
		glTranslatef(X, Y, 0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, PlatformsTexture);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex2f(0, 0);
		glTexCoord2d(1, 0); glVertex2f(PlatformWidth, 0);
		glTexCoord2d(1, 1); glVertex2f(PlatformWidth, PlatformHeight);
		glTexCoord2d(0, 1); glVertex2f(0, PlatformHeight);
		glEnd();
		glDisable(GL_TEXTURE_2D);

		glPopMatrix();
	}

} Platform[PlatformsCount];