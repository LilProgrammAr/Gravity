#include "GuiButton.h"

////////////////////////////////////////////////////////////////////////////////

#define event cfg.event
#define window cfg.window
#define clock cfg.clock

gui::GuiButton::GuiButton(const core::Config & cfg) : GuiWidget(cfg) {}

void gui::GuiButton::draw()
{
	window->draw(sprite);
}

bool gui::GuiButton::isClicked()
{
	auto isHovered = handleHover();
	if (isHovered) {
		if (event->type == sf::Event::MouseButtonPressed && 
			event->key.code == sf::Mouse::Left) {
			sprite.setColor(sf::Color(133, 133, 133));
			wasPressed = true;
		}
		if (event->type == sf::Event::MouseButtonReleased &&
			event->key.code == sf::Mouse::Left) {
			sprite.setColor(sf::Color::White);
			if (wasPressed) {
				wasPressed = false;
				return true;
			}
			else return false;
		}
	}
	else return false;

}

bool gui::GuiButton::handleHover()
{
	auto mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window));
	auto isHovered = sprite.getGlobalBounds().contains(mousePos);
	if (isHovered) {
		if (!wasLarged) {
			sprite.setScale(1.05f, 1.05f);
			sprite.setPosition(sprite.getPosition().x - image.getSize().x / 40,
							   sprite.getPosition().y - image.getSize().y / 40);
			wasLarged = true;
		}
	}
	else {
		if (wasLarged) {
			sprite.setScale(1.f, 1.f);
			sprite.setPosition(sprite.getPosition().x + image.getSize().x / 40,
							   sprite.getPosition().y + image.getSize().y / 40);
			wasLarged = false;
		}
	}
	return isHovered;
}



