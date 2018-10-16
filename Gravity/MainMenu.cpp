#include "MainMenu.h"

////////////////////////////////////////////////////////////////////////////////

MainMenu::MainMenu(const core::Config & cfg) :
	Scene(cfg) 
{
	Gravity.loadFromFile("Resources/Main menu/GRAVITY_icon.png");
	newSimulation.loadFromFile("Resources/Main menu/New_simulation_icon.png");
	//settings.loadFromFile("Resources/Main menu/Settings_icon.png");
	quit.loadFromFile("Resources/Main menu/Quit_icon.png");

	Gravity.loadConfig(cfg);
	newSimulation.loadConfig(cfg);
	//settings.loadConfig(cfg);
	quit.loadConfig(cfg);

	Gravity.setPosition(core::Vector2f(cfg.window->getSize().x / 2,
									   Gravity.getSize().y * 1.5f));

	newSimulation.setPosition(core::Vector2f(cfg.window->getSize().x / 2,
											 Gravity.getPosition().y +
											 Gravity.getSize().y * 2));

	/*settings.setPosition(core::Vector2f(cfg.window->getSize().x / 2,
										newSimulation.getPosition().y +
										newSimulation.getSize().y * 2));*/

	quit.setPosition(core::Vector2f(cfg.window->getSize().x / 2,
									//settings.getPosition().y +
									//settings.getSize().y * 1.8));
									newSimulation.getPosition().y +
									newSimulation.getSize().y * 2.8));
									
}

void MainMenu::draw()
{	
	Gravity.draw();
	newSimulation.draw();
	//settings.draw();
	quit.draw();
}

core::EventList MainMenu::checkEvent()
{
	if (newSimulation.isClicked())
		return core::EventList::NEW_SIMULATION;
	/*if (settings.isClicked())
		return core::EventList::SETTINGS;*/
	if (quit.isClicked())
		return core::EventList::EXIT;

	return core::EventList::IDLE;
}
