#pragma once
#include "libs/SOIL/SOIL.h"

int LoadGLTextures(char* filename);

static int Window = 0;

static int ScreenWidth	= 400;
static int ScreenHeight = 600;

static int Gravity = 3;
static int Bounce = 35;

const int PlatformsCount = 15;
static int PlatformWidth = ScreenWidth / 6;
static int PlatformHeight = PlatformWidth / 5;
static unsigned PlatformsTexture = 0;

static int Score = 0;
static bool HasBonus = false;
static bool Life = true;
static bool StartScreen = true;
static bool Exit = false;

static GLuint StartTexture = 0;
static GLuint ExitTexture = 0;
static GLuint GameOverTexture = 0;
static GLuint BonusTexture = 0;

static int StartButtonLeft = ScreenWidth / 6;
static int StartButtonTop = StartButtonLeft + ScreenWidth / 3;

static int ExitButtonLeft = ScreenWidth - StartButtonLeft - ScreenWidth / 3;
static int ExitButtonTop = StartButtonTop;

static int ButtonHeight = ScreenWidth / 3;
static int ButtonWidth = ScreenWidth / 3;

int LoadGLTextures(char* filename)									
{
	int texture = SOIL_load_OGL_texture
		(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if(texture == 0)
		return 0;

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	return texture;
}

void TextOut(int x, int y, char *string) {  
	char *c; glRasterPos2f(x, y);
	for (c=string; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}