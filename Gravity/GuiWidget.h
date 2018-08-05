#pragma once
#ifndef CLASS_GUI_WIDGET_H
#define	CLASS_GUI_WIDGET_H	

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "vector2.h"

////////////////////////////////////////////////////////////////////////////////


class GuiWidget
{
public:
	GuiWidget(const Config& cfg);
	GuiWidget(const Config& cfg, char*& filepath);
	virtual ~GuiWidget() = default;

	bool loadFromFile(char*& path) noexcept;
	void loadConfig(const Config& obj) noexcept;

	virtual void draw() = 0;

	void setPosition(const vector2f& pos);
	sf::Vector2f getPosition() noexcept;



private:
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	Config cfg;
};

#endif //CLASS_GUI_WIDGET_H