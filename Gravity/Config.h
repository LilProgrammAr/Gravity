#pragma once
#ifndef STRUCT_RENDER_SETTINGS_H
#define STRUCT_RENDER_SETTINGS_H

#include <SFML/Graphics.hpp>

////////////////////////////////////////////////////////////////////////////////
namespace core {
	struct Config {
		std::shared_ptr<sf::RenderWindow> window;
		std::shared_ptr<sf::Event> event;
		std::shared_ptr<sf::Clock> clock;
	};
}

#endif //STRUCT_RENDER_SETTINGS_H
