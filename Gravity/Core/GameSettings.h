#pragma once
#ifndef CLASS_GAME_SETTINGS_H
#define CLASS_GAME_SETTINGS_H

#include <SFML/Graphics.hpp>

////////////////////////////////////////////////////////////////////////////////
namespace core {
	struct GameSettings {
		sf::VideoMode vm;
		std::string title;
		sf::ContextSettings cs;
		sf::Uint32 style;
		float volume; // from 0 to 100
		int frameLimit;

	};
}

#endif //CLASS_GAME_SETTINGS_H