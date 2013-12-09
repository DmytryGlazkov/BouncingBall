#pragma once
#include <iostream>

#include "Helpers.h"
#include "Models.h"

void Timer(int id)
{
	for(int i = 0; i < PlatformsCount; i++)
	{
		Platform[i].Update();    

		if(Platform[i].Y < -50)
			Platform[i].New();
	}

	Player *person = Scene::GetInstance().GetPlayer();

	for(int i = 0; i < PlatformsCount; i++)
	{
		if((person->X + person->PlayerRadius >= Platform[i].X) &&
			(person->X - person->PlayerRadius <= Platform[i].X + PlatformWidth) &&
			(person->Y + person->PlayerRadius <= Platform[i].Y) &&
			(person->Y + person->PlayerRadius * 2 + 1 >= Platform[i].Y) &&
			person->dy < 0)
			person->dy=40;
	}
	if(person->Y == 500)
		Score++; 

	if(person->Y == 0)
	{
		Life = false;
	}

	person->Update();

	glutTimerFunc(1000 / 24, Timer, 0);
}