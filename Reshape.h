#pragma once

#include <iostream>

void Reshape(int width, int height)
{
	ScreenHeight = height;
	ScreenWidth = width;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(45.0, (float)width / height, 0.1f, 100.0f);
	gluOrtho2D(0, width, height, 0);
	glMatrixMode(GL_MODELVIEW);
};