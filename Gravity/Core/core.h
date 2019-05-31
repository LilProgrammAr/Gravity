#pragma once
#ifndef CORE_H
#define CORE_H

#include "Config.h"
#include "functions.h"
#include "GameSettings.h"
#include "Vector2.h"

#include <SFML\Graphics.hpp>
#include <functional>

namespace core {
	enum class EventList : unsigned short{
		IDLE = 0,
		EXIT,
		NEW_SIMULATION,
		SETTINGS,
		MAIN_MENU,
		ADD_PLANET,
		LOC_SETTINGS,
		APPLY_SETTINGS
	};

	constexpr float MASS_RATIO = 0.6180387f;
	constexpr float G = 1e-4f;
	constexpr int START_COUNT = 50;
	constexpr float DEFAULT_MASS = 75;
	constexpr int MASS_STEP = 5;
	static float SPEED_MULT = 0.5;
	const static std::string RES_PATH = "Resources/";
}

#endif //CORE_H