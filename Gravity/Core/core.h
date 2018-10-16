#pragma once
#ifndef CORE_H
#define CORE_H

#include "Config.h"
#include "functions.h"
#include "GameSettings.h"
#include "Vector2.h"
 
constexpr float MASS_RATIO = 0.6180387;

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
}

#endif //CORE_H