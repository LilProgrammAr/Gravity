#include "GuiButton.h"

////////////////////////////////////////////////////////////////////////////////

gui::GuiButton::GuiButton() :
	was_pressed(false),
	was_larged(false)
{
	notify_if = []() {return false; };
}

gui::GuiButton::GuiButton(const core::Config & cfg) :
	was_pressed(false),
	was_larged(false),
	GuiWidget(cfg)
{
	notify_if = []() {return false; };
}


void gui::GuiButton::draw()
{
	cfg.window->draw(sprite);
}

bool gui::GuiButton::isClicked()
{
	if (notify_if()) return true;
	auto isHovered = handleHover();
	if (isHovered) {
		if (cfg.event->type == sf::Event::MouseButtonPressed &&
			cfg.event->key.code == sf::Mouse::Left) {
			sprite.setColor(sf::Color(133, 133, 133));
			was_pressed = true;
		}
		if (cfg.event->type == sf::Event::MouseButtonReleased &&
			cfg.event->key.code == sf::Mouse::Left) {
			sprite.setColor(sf::Color::White);
			if (was_pressed) {
				if (was_larged) {
					sprite.setScale(1.f, 1.f);
					sprite.setPosition(sprite.getPosition().x + image.getSize().x / 40,
									   sprite.getPosition().y + image.getSize().y / 40);
					was_larged = false;
				}
				was_pressed = false;
				return true;
			}
			else return false;
		}
	}

	if (cfg.event->type == sf::Event::MouseButtonReleased &&
		cfg.event->key.code == sf::Mouse::Left && was_pressed) {
		sprite.setColor(sf::Color::White);
		was_pressed = false;
	}

	return false;

}

void gui::GuiButton::notifyIf(std::function<bool()> notifyer)
{
	notify_if = notifyer;
}

bool gui::GuiButton::handleHover()
{
	auto mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*cfg.window));
	auto isHovered = sprite.getGlobalBounds().contains(mousePos);
	if (isHovered) {
		if (!was_larged) {
			sprite.setScale(1.05f, 1.05f);
			sprite.setPosition(sprite.getPosition().x - image.getSize().x / 40,
							   sprite.getPosition().y - image.getSize().y / 40);
			was_larged = true;
		}
	}
	else {
		if (was_larged) {
			sprite.setScale(1.f, 1.f);
			sprite.setPosition(sprite.getPosition().x + image.getSize().x / 40,
							   sprite.getPosition().y + image.getSize().y / 40);
			was_larged = false;
		}
	}
	return isHovered;
}
