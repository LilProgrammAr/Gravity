#include <SFML/Graphics.hpp>
#include <iostream>
#include "vector2.h"

////////////////////////////////////////////////////////////////////////////////

int main() {

	auto a = vector2i(1, 2);
	
	std::cout << (a * 5).x << ' ' << (a * 5).y << std::endl;

	auto window = std::make_shared<sf::RenderWindow>();
	auto event = std::make_shared<sf::Event>();

	window->create(sf::VideoMode::getDesktopMode(), "Gravity");

	while (window->isOpen()) {
		while (window->pollEvent(*event)) {
			if (event->type == sf::Event::Closed) {
				window->close();
			}
		}

		window->clear(sf::Color::Black);

		window->display();
	}				
}