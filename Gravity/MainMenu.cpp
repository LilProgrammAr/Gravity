#include "MainMenu.h"

////////////////////////////////////////////////////////////////////////////////

MainMenu::MainMenu(const core::Config & cfg) :
	Scene(cfg) 
{
	gravity.loadFromFile("Resources/Main menu/GRAVITY_icon.png");
	newSimulation.loadFromFile("Resources/Main menu/New_simulation_icon.png");
	settings.loadFromFile("Resources/Main menu/Settings_icon.png");
	quit.loadFromFile("Resources/Main menu/Quit_icon.png");

	gravity.loadConfig(cfg);
	newSimulation.loadConfig(cfg);
	settings.loadConfig(cfg);
	quit.loadConfig(cfg);

	gravity.setPosition(core::Vector2f(cfg.window->getSize().x / 2, gravity.getSize().y * 2));
	newSimulation.setPosition(core::Vector2f(cfg.window->getSize().x / 2, gravity.getPosition().y + 200));
	settings.setPosition(core::Vector2f(cfg.window->getSize().x / 2, newSimulation.getPosition().y + 105));
	quit.setPosition(core::Vector2f(cfg.window->getSize().x / 2, settings.getPosition().y + 90));
}

void MainMenu::draw()
{	
	gravity.draw();
	newSimulation.draw();
	settings.draw();
	quit.draw();
}

core::EventList MainMenu::checkEvent()
{
	return core::EventList();
}
