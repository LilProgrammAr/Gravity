#include <SFML/Graphics.hpp>
#include <iostream>
#include "Core/core.h"
#include "MainMenu.h"
#include "SettingsMenu.h"
#include "Space.h"

////////////////////////////////////////////////////////////////////////////////

int main() {

	auto cfg = core::initialize();
	
	cfg.window->create(sf::VideoMode::getDesktopMode(),
					   "Gravity",
					   sf::Style::Fullscreen);
					 
	auto main_menu = new MainMenu(cfg);
	auto space = new Space(cfg);


	//auto settings_menu = std::make_unique<Scene>(SettingsMenu(cfg));
	

	Scene* current_scene = main_menu;

	while (cfg.window->isOpen()) {
		
		cfg.clock->restart();
		while (cfg.window->pollEvent(*(cfg.event))) {
			if (cfg.event->type == sf::Event::Closed) {
				cfg.window->close();
			}
			if (cfg.event->type == sf::Event::KeyPressed &&
				cfg.event->key.code == sf::Keyboard::Escape)
				cfg.window->close();
			switch (current_scene->checkEvent()) {
			case core::EventList::NEW_SIMULATION:
				current_scene = space;
				break;
			case core::EventList::ADD_PLANET:
				space->addObject();
				break;
			/*case core::EventList::SETTINGS:
				current_scene = settings_menu.get();
				break;*/
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

	//delete settings_menu;
	delete main_menu;
	delete space;

}