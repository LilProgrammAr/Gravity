#pragma once
#ifndef CORE_H
#define CORE_H

#include "Config.h"
#include "functions.h"
#include "GameSettings.h"
#include "Vector2.h"

#include <SFML\Graphics.hpp>

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

	constexpr float MASS_RATIO = 0.6180387;
	constexpr float G = 1e-2;
	constexpr int START_COUNT = 6;
}

#endif //CORE_H