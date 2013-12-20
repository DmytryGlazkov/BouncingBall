#pragma once

#include "Models.h"

void Display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	glLoadIdentity();


	if (StartScreen)
	{
		Scene::GetInstance().DrawBackground();

		glColor3f(1, 1, 1);

		int startLeft = ScreenWidth / 6;
		int startTop = (ScreenHeight - ScreenWidth / 3) / 2;

		glEnable(GL_TEXTURE_2D);		
		glAlphaFunc(GL_GREATER, 0);
		glEnable(GL_ALPHA_TEST);
		glBindTexture(GL_TEXTURE_2D, StartTexture);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0); glVertex2f(startLeft, startTop);
			glTexCoord2d(1, 0); glVertex2f(startLeft + ScreenWidth / 3, startTop);
			glTexCoord2d(1, 1); glVertex2f(startLeft + ScreenWidth / 3, startTop + ScreenWidth / 3);
			glTexCoord2d(0, 1); glVertex2f(startLeft, startTop + ScreenWidth / 3);
		glEnd();


		glBindTexture(GL_TEXTURE_2D, ExitTexture);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 0); glVertex2f(ScreenWidth - startLeft - ScreenWidth / 3, startTop);
			glTexCoord2d(1, 0); glVertex2f(ScreenWidth - startLeft, startTop);
			glTexCoord2d(1, 1); glVertex2f(ScreenWidth - startLeft, startTop + ScreenWidth / 3);
			glTexCoord2d(0, 1); glVertex2f(ScreenWidth - startLeft - ScreenWidth / 3, startTop + ScreenWidth / 3);
		glEnd();
		glDisable(GL_ALPHA_TEST);
		glDisable(GL_TEXTURE_2D);
	}
	else
	{
		Scene::GetInstance().Draw();

		for(int i = 0; i < PlatformsCount; i++)
			Platform[i].Draw();
	}


	glutSwapBuffers();
	glutPostRedisplay();
};