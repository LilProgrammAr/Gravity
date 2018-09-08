////////////////////////////////////////////////////////////////////////////////

#include "SettingsMenu.h"

SettingsMenu::SettingsMenu(const core::Config & cfg) :
	Scene(cfg)
{
	Settings.loadConfig(cfg);
	Settings.loadFromFile("Resources/Settings scene/Settings.png");

	fullscreen.loadConfig(cfg);
	fullscreen.loadFromFile("Resources/Settings scene/Fullscreen_icon.png");

	resolution.loadConfig(cfg);
	resolution.loadFromFile("Resources/Settings scene/Resolution_icon.png");

	cancel.loadConfig(cfg);
	cancel.loadFromFile("Resources/Settings scene/Cancel_icon.png");

	accept.loadConfig(cfg);
	accept.loadFromFile("Resources/Settings scene/Accept_icon.png");

	apply.loadConfig(cfg);
	apply.loadFromFile("Resources/Settings scene/Apply_icon.png");

	fullsceen_checkbox.loadConfig(cfg);

	Settings.setPosition(core::Vector2f(cfg.window->getSize().x / 2,
									   Settings.getSize().y));

	fullscreen.setPosition(core::Vector2f(fullscreen.getSize().x * 1.2,
										  Settings.getPosition().y + 
										  Settings.getSize().y * 2));
	resolution.setPosition(core::Vector2f(resolution.getSize().x * 1.2,
										  fullscreen.getPosition().y +
										  fullscreen.getSize().y * 2));

	cancel.setPosition(core::Vector2f(cfg.window->getSize().x -
									  cancel.getSize().x,
									  cfg.window->getSize().y -
									  cancel.getSize().y * 1.5f));

	accept.setPosition(core::Vector2f(cancel.getPosition().x - 
									  cancel.getSize().x * 0.7f,
									  cfg.window->getSize().y -
									  cancel.getSize().y * 1.5f));

	apply.setPosition(core::Vector2f(accept.getPosition().x -
									 cancel.getSize().x * 0.7f,
									 cfg.window->getSize().y -
									 cancel.getSize().y * 1.5f));

	fullsceen_checkbox.setPosition(
		core::Vector2f(fullscreen.getSize().x * 2,
					   Settings.getPosition().y +
					   Settings.getSize().y * 2 ));

	fullsceen_checkbox.setCheched(Scene::gs.style == sf::Style::Fullscreen);

}

void SettingsMenu::draw()
{
	Settings.draw();
	fullscreen.draw();
	resolution.draw();
	cancel.draw();
	accept.draw();
	apply.draw();
	fullsceen_checkbox.draw();
}

core::EventList SettingsMenu::checkEvent()
{
	static core::GameSettings gs = Scene::gs;
	static bool is_changed = false;

	resolution.isClicked();

	if (fullscreen.isClicked() || fullsceen_checkbox.isChecked()) {
		if (gs.style != sf::Style::Fullscreen) {
			gs.style = sf::Style::Fullscreen;
		}
		else {
			gs.style = sf::Style::Close;
		}
		fullsceen_checkbox.setCheched(gs.style == sf::Style::Fullscreen);
		is_changed = true;
	}
	if (cancel.isClicked())
		return core::EventList::MAIN_MENU;
	if (apply.isClicked() && is_changed) {
		applySettings(gs);
		is_changed = false;
	}
	if (accept.isClicked()) {
		if (is_changed) {
			applySettings(gs);
			is_changed = false;
		}
		return core::EventList::MAIN_MENU;
	}

	return core::EventList();
}

void SettingsMenu::applySettings(const core::GameSettings& gs)
{
	cfg.window->create(gs.vm, gs.title, gs.style, gs.cs);
}
