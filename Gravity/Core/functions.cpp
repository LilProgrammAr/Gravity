#include "functions.h"

////////////////////////////////////////////////////////////////////////////////

core::Config core::initialize() {
	return core::Config{ std::make_shared<sf::RenderWindow>(),
				 std::make_shared<sf::Event>(),
				 std::make_shared<sf::Clock>() };
}