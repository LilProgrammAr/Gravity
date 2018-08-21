#pragma once
#ifndef CLASS_GAME_SETTINGS_H
#define CLASS_GAME_SETTINGS_H

#include <SFML/Graphics.hpp>

////////////////////////////////////////////////////////////////////////////////
namespace core {
	struct GameSettings {
		bool isFulscreen;
		sf::ContextSettings windowSettings;
		float volume; // from 0 to 100

	};
}

#endif //CLASS_GAME_SETTINGS_H