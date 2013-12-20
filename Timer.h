#pragma once
#include <iostream>

#include "Helpers.h"
#include "Models.h"

void Timer(int id)
{
	Player *person = Scene::GetInstance().GetPlayer();

	person->Update();

	for(int i = 0; i < PlatformsCount; i++)
	{
		Platform[i].Update();    

		if(Platform[i].Y < -50)
		{
			if (Platform[i].bonus)
			{
				HasBonus = false;
			}
			Platform[i].New();
		}
	}

	for(int i = 0; i < PlatformsCount; i++)
		if((person->X >= Platform[i].X) &&
			(person->X <= Platform[i].X + PlatformWidth) &&
			(person->Y + person->PlayerRadius >= Platform[i].Y) &&
			(person->Y <= Platform[i].Y + person->PlayerRadius + 20) &&
			person->dy <  0)
		{
			if (Platform[i].bonus)
			{
				person->dy = Bounce * 3;
				break;
			}
			person->dy = Bounce;
		}

	if(person->Y >= ScreenHeight)
		Score++; 

	if(person->Y == 0)
		Life = false;

	glutTimerFunc(1000 / 24, Timer, 0);
}