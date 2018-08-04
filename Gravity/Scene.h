#pragma once
#ifndef CLASS_SCENE_H
#define CLASS_SCENE_H

#include "Config.h"
#include "GameSettings.h"

////////////////////////////////////////////////////////////////////////////////

enum EventList {
	IDLE,
	EXIT,
	NEW_SIMULATION,
	SETTINGS,
	MAIN_MENU,
	ADD_PLANET,
	LOC_SETTINGS,
	APPLY_SETTINGS
};

class Scene
{
public:
	Scene(const Config& obj);
	virtual ~Scene() = default;

	virtual void draw() = 0;
	virtual EventList checkEvent() = 0;

private:
	Config cfg;
	GameSettings gs;

};

#endif //CLASS_SCENE_H