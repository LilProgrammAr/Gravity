#pragma once
#ifndef CLASS_SPACE_H
#define CLASS_SPACE_H

#include "Scene.h"
#include "Core\core.h"
#include "CelestialBody.h"
#include <vector>

class Space : public Scene
{
public:
	Space(const core::Config& cfg);
	void draw();
	void addObject();

	core::EventList checkEvent() override;

private:
	std::vector<CelestialBody> bodies;
	void computeScene();
	void add_object();
	gui::GuiButton main_menu, 
		add_body;
	bool addingObject;
	std::unique_ptr<CelestialBody> temp_object;
	
};

#endif //CLASS_SPACE_H