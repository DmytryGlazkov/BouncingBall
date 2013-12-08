#pragma once
#include <iostream>

using namespace std;

#include "Scene.h"

void Keyboard(unsigned char key, int x, int y)
{
	cout << key << " " << x << " " << y <<  "\r\n";
}

void KeyboardSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		Scene::GetInstance().GetPlayer()->Left = true;
		break;
	case GLUT_KEY_RIGHT:
		Scene::GetInstance().GetPlayer()->Right = true;
		break;
	case GLUT_KEY_DOWN:
		break;
	case GLUT_KEY_UP:
		break;
	}
}


void KeyboardSpecialKeysUp(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		Scene::GetInstance().GetPlayer()->Left = false;
		break;
	case GLUT_KEY_RIGHT:
		Scene::GetInstance().GetPlayer()->Right = false;
		break;
	case GLUT_KEY_DOWN:
		break;
	case GLUT_KEY_UP:
		break;
	}
}