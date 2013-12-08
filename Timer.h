#pragma once
#include <iostream>

#include "Scene.h"

void Timer(int id)
{
	Scene::GetInstance().GetPlayer()->Update();
	glutTimerFunc(1000 / 24, Timer, 0);
}