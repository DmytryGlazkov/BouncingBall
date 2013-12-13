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
	//gluLookAt(0, 0, 0, 0, 0, 5, 0, 1, 0);
	gluOrtho2D(0, width, 0, height);
	glMatrixMode(GL_MODELVIEW);
};