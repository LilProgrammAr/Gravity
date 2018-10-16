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

private:
	std::vector<CelestialBody> bodies;
	void computeScene();
};

#endif //CLASS_SPACE_H