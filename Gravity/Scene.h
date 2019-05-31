#pragma once
#ifndef CLASS_SCENE_H
#define CLASS_SCENE_H

#include "Core/core.h"
#include "gui.h"

////////////////////////////////////////////////////////////////////////////////

class Scene
{
public:
	Scene(const core::Config& obj);
	virtual ~Scene() = default;

	virtual void draw() = 0;
	virtual core::EventList checkEvent() = 0;
	virtual void pause() = 0;
	virtual void resume() = 0;;

protected:

	core::Config cfg;
	static core::GameSettings gs;
	bool paused;

};

#endif //CLASS_SCENE_H