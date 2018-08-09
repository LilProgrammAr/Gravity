#include <SFML/Graphics.hpp>
#include <iostream>
#include "vector2.h"
#include "Config.h"
#include "functions.h"

////////////////////////////////////////////////////////////////////////////////

int main() {

	Config cfg = initialize();
	

	cfg.window->create(sf::VideoMode::getDesktopMode(), "Gravity");

	while (cfg.window->isOpen()) {
		while (cfg.window->pollEvent(*(cfg.event))) {
			if (cfg.event->type == sf::Event::Closed) {
				cfg.window->close();
			}
		}

		cfg.window->clear(sf::Color::Black);

		cfg.window->display();
	}			
}