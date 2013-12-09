#include "libs/OpenGL/glut.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Display.h"
#include "Reshape.h"
#include "Keyboard.h"
#include "Timer.h"
#include "Helpers.h"

int main(int argc, char** argv)
{
	srand(time(0));
	glutInit (&argc, argv);
	glutInitWindowSize (ScreenWidth, ScreenHeight);
	glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-ScreenWidth)/2,
		(glutGet(GLUT_SCREEN_HEIGHT)-ScreenHeight)/2);
	glutCreateWindow ("Bouncing Ball");

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);

	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(KeyboardSpecialKeys);
	glutSpecialUpFunc(KeyboardSpecialKeysUp);
	glutTimerFunc(1000 / 24, Timer, 0);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	glutMainLoop();
	return 0;
}