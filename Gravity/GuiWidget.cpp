#include "GuiWidget.h"

////////////////////////////////////////////////////////////////////////////////

gui::GuiWidget::GuiWidget(const Config& cfg) : cfg(cfg) {}

gui::GuiWidget::GuiWidget(const Config & cfg, char *& filepath) : cfg(cfg)
{
	loadFromFile(filepath);
}

bool gui::GuiWidget::loadFromFile(char *& path) noexcept
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

void gui::GuiWidget::loadConfig(const Config & obj) noexcept
{
	cfg = obj;
}

void gui::GuiWidget::setPosition(const vector2f & pos)
{
	sprite.setPosition(pos - vector2f(image.getSize().x / 2.f,
									  image.getSize().y / 2.f));
}

sf::Vector2f gui::GuiWidget::getPosition() noexcept
{
	return sprite.getPosition();
}

