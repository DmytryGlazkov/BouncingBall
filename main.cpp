#include "libs/OpenGL/glut.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Display.h"
#include "Reshape.h"
#include "Keyboard.h"
#include "Timer.h"
#include "Helpers.h"
#include "Mouse.h"

int main(int argc, char** argv)
{
	srand(time(0));
	glutInit (&argc, argv);
	glutInitWindowSize (ScreenWidth, ScreenHeight);
	glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-ScreenWidth)/2,
		(glutGet(GLUT_SCREEN_HEIGHT)-ScreenHeight)/2);
	Window = glutCreateWindow ("Bouncing Ball");

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);

	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(KeyboardSpecialKeys);
	glutSpecialUpFunc(KeyboardSpecialKeysUp);
	glutMouseFunc(MouseFunc);
	glutTimerFunc(1000 / 24, Timer, 0);

	glEnable(GL_TEXTURE_2D);
	PlatformsTexture = LoadGLTextures("Textures/platform.jpg");

	StartTexture = LoadGLTextures("Textures/StartGame.tga");
	ExitTexture = LoadGLTextures("Textures/ExitGame.tga");
	GameOverTexture = LoadGLTextures("Textures/game_over.tga");
	BonusTexture = LoadGLTextures("Textures/bonus.tga");
	LogoTexture = LoadGLTextures("Textures/logo.tga");

	Scene::GetInstance().LoadGLTextures();

	glutMainLoop();
	return 0;
}