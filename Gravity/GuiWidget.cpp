#include "GuiWidget.h"

////////////////////////////////////////////////////////////////////////////////

gui::GuiWidget::GuiWidget(const core::Config& cfg) : cfg(cfg) {}



bool gui::GuiWidget::loadFromFile(std::string path) noexcept
{
	try {
		if (!image.loadFromFile(path)) return false;
		if (!texture.loadFromImage(image)) return false;
		sprite.setTexture(texture);
	}
	catch (...) {
		return false;
	}
	return true;
}

void gui::GuiWidget::loadConfig(const core::Config & obj) noexcept
{
	cfg = obj;
}

sf::Vector2u gui::GuiWidget::getSize()
{
	return sf::Vector2u(image.getSize().x * sprite.getScale().x,
						image.getSize().y * sprite.getScale().y);
}

void gui::GuiWidget::setPosition(const core::Vector2f & pos)
{
	sprite.setPosition(pos - core::Vector2f(image.getSize().x / 2.f,
									  image.getSize().y / 2.f));
}

sf::Vector2f gui::GuiWidget::getPosition() noexcept
{
	return sprite.getPosition();
}

