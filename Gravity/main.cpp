#include <SFML/Graphics.hpp>
#include <iostream>
#include "Core/core.h"
#include "MainMenu.h"
#include "SettingsMenu.h"

////////////////////////////////////////////////////////////////////////////////

int main() {

	auto cfg = core::initialize();
	
	cfg.window->create(sf::VideoMode::getDesktopMode(),
					   "Gravity",
					   sf::Style::Fullscreen);
	cfg.window->setFramerateLimit(120);
					 
	auto main_menu = new MainMenu(cfg);
	auto settings_menu = new SettingsMenu(cfg);
	

	Scene* current_scene = main_menu;

	while (cfg.window->isOpen()) {
		
		while (cfg.window->pollEvent(*(cfg.event))) {
			if (cfg.event->type == sf::Event::Closed) {
				cfg.window->close();
			}
			switch (current_scene->checkEvent()) {
			case core::EventList::NEW_SIMULATION:
				break;
			case core::EventList::SETTINGS:
				current_scene = settings_menu;
				break;
			case core::EventList::MAIN_MENU:
				current_scene = main_menu;
				break;
			case core::EventList::EXIT:
				cfg.window->close();
				break;
			}
		}

		cfg.window->clear(sf::Color::Black);

		//draw things
		current_scene->draw();

		cfg.window->display();	   
	}			

	delete main_menu;
	delete settings_menu;

}