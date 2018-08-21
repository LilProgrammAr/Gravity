#include <SFML/Graphics.hpp>
#include <iostream>
#include "core.h"
#include "MainMenu.h"

////////////////////////////////////////////////////////////////////////////////

int main() {

	auto cfg = core::initialize();
	
	cfg.window->create(sf::VideoMode::getDesktopMode(), "Gravity");

	auto main_menu = new MainMenu(cfg);

	while (cfg.window->isOpen()) {
		while (cfg.window->pollEvent(*(cfg.event))) {
			if (cfg.event->type == sf::Event::Closed) {
				cfg.window->close();
			}
		}

		cfg.window->clear(sf::Color::Black);

		//draw things
		main_menu->draw();

		cfg.window->display();
	}			
}