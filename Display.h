#pragma once

#include "Models.h"

void Display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	Scene::GetInstance().Draw();
	for(int i = 0;i < PlatformsCount; i++)
		Platform[i].Draw();


	glutSwapBuffers();
	glutPostRedisplay();
};