#include "GuiCheckbox.h"

////////////////////////////////////////////////////////////////////////////////

gui::GuiCheckbox::GuiCheckbox() :
	was_pressed(false),
	is_checked(false)
{
	image.loadFromFile("Resources/GUI/check_box_icon.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}


gui::GuiCheckbox::GuiCheckbox(const core::Config & cfg) :
	was_pressed(false),
	is_checked(false),
	GuiWidget(cfg) 
{
	image.loadFromFile("Resources/GUI/check_box_icon.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}

void gui::GuiCheckbox::draw()
{
	if (is_checked)
		cfg.window->draw(sprite);
}

bool gui::GuiCheckbox::isChecked()
{
	auto mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*cfg.window));

	if (sprite.getGlobalBounds().contains(mousePos)) {
		if (cfg.event->type == sf::Event::MouseButtonPressed)
			if (cfg.event->key.code == sf::Mouse::Left) {
				was_pressed = true;
			}
		if (cfg.event->type == sf::Event::MouseButtonReleased)
			if (cfg.event->key.code == sf::Mouse::Left)
			{
				is_checked = !is_checked;
				was_pressed = false;
			}
	}

	return is_checked;
}

void gui::GuiCheckbox::setCheched(bool checked)
{
	is_checked = checked;
}

gui::GuiCheckbox::operator bool()
{
	return is_checked;
}
