#pragma once
#include "libs/OpenGL/glut.h"


void MouseFunc(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		if (x > StartButtonLeft && x < StartButtonLeft + ButtonWidth &&
			y - StartButtonTop > 10 && y < StartButtonTop + ButtonHeight)
		{
			StartScreen = false;
			Life = true;
		}
		cout << StartButtonLeft << " " << StartButtonTop << endl;
		if (x > ExitButtonLeft && x < ExitButtonLeft + ButtonWidth &&
			y - ExitButtonTop > 10 && y < ExitButtonTop + ButtonHeight)
		{
			exit(0);
		}
	}
}