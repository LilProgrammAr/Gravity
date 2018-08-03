#include <SFML/Graphics.hpp>
#include "vector2.h"

////////////////////////////////////////////////////////////////////////////////

int main() {
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