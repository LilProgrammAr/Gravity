#include "functions.h"

////////////////////////////////////////////////////////////////////////////////

Config initialize() {
	Config buff{ std::make_shared<sf::RenderWindow>(),
				 std::make_shared<sf::Event>(),
				 std::make_shared<sf::Clock>() };
	return buff;
}