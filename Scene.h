#pragma once

#include <vector>
#include <iostream>

using namespace std;

//#include "Platform.h"
#include "Player.h"

class Scene
{
public:
	Scene()
	{
		player = new Player();
	}

	static Scene GetInstance()
	{
		static Scene instance;
		return instance;
	}

	void Update()
	{
		/*for (int i = 0; i < platforms.size(); i++)
		{
			platforms[i]->Update();
		}*/
		player->Update();
	}

	void Draw()
	{

		/*for (int i = 0; i < platforms.size(); i++)
		{
			platforms[i]->Draw();
		}*/
		player->Draw();
	}

	Player* GetPlayer()
	{
		return player;
	}
protected:
	Player* player;
};